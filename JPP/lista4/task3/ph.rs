use std::thread;
use std::sync::{Mutex, Arc};
use std::env;
use std::process;

struct Table {
  forks: Vec<Mutex<()>>,
}

struct Philosopher {
  id: usize,
  left: usize,
  right: usize,
  eaten: usize,
  eaten_enough: usize,
}

impl Philosopher {
  fn new(id: usize, left: usize, right: usize, eaten: usize, eaten_enough: usize) -> Philosopher {
    Philosopher {
      id: id,
      left: left,
      right: right,
      eaten: eaten,
      eaten_enough: eaten_enough,
    }
  }

  fn eat(&mut self, table: &Table) {
    // let _left = table.forks[self.left].lock().unwrap();
    while self.eaten < self.eaten_enough {
    // let _right = table.forks[self.right].lock().unwrap();
      match table.forks[self.left].try_lock() {
        Ok(left_fork) => {
          match table.forks[self.right].try_lock() {
            Ok(right_fork) => {
              self.eaten += 1;
              println!("{} is eating: {}/{}", self.id, self.eaten, self.eaten_enough);
              drop(right_fork);
              drop(left_fork);
            }
            Err(_) => {
              // Failed to acquire the lock on the right fork
              // Release the left fork
              drop(left_fork);
              // println!("{} couldn't acquire the right fork.", self.id);
            }
          }
        }
        Err(_) => {
        }
      }
    }
    println!("{} is done eating.", self.id);
  }
}

fn main() {
  let args: Vec<String> = env::args().collect();
  if args.len() != 3 {
    println!("Usage: philosophers <NumPhilosophers> <EatenEnough>");
    process::exit(1);
  }
  let num_philosophers: usize = match args[1].parse() {
    Ok(n) => n,
    Err(_) => {
      eprintln!("Error: NumPhilosophers must be a positive integer");
      process::exit(1);
    }
  };
  let eaten_enough: usize = match args[2].parse() {
    Ok(n) => n,
    Err(_) => {
      eprintln!("Error: EatenEnough must be a positive integer");
      process::exit(1);
    }
  };
  println!("#Philosophers = {}", num_philosophers);
  println!("#Dininigs = {}", eaten_enough);

  // Create forks
  let forks: Vec<_> = (0..num_philosophers).map(|_| Mutex::new(())).collect();
  let table = Arc::new(Table{forks});

  // Create philosophers
  let philosophers: Vec<_> = (0..num_philosophers).map(|i| {
      Philosopher::new(i, i, (i + 1) % num_philosophers, 0, eaten_enough)
  }).collect();

  let handles: Vec<_> = philosophers.into_iter().map( |mut philosopher| {
    let table = table.clone();

    thread::spawn(move || {
      philosopher.eat(&table);
    })
  }).collect();

  for handle in handles {
    handle.join().unwrap();
  }
}