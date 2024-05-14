package main

import (
	"fmt"
	"os"
	"strconv"
	"sync"
	// "time"
)

type Philosopher struct {
	id           int
	leftCSMutex  *sync.Mutex
	rightCSMutex *sync.Mutex
	eaten        int //always at creation set to 0
}

func (p *Philosopher) eat(meals int, numPhilosophers int, wg *sync.WaitGroup) {
	defer wg.Done()
	for p.eaten < meals {
		if p.leftCSMutex.TryLock() {
			// fmt.Printf("Philosopher %d Picked Up %d TIME %d\n", p.id, p.id, time.Now().UnixNano()% 1000000000)
			if p.rightCSMutex.TryLock() {
				// fmt.Printf("Philosopher %d Picked Up %d TIME %d\n", p.id, (p.id + 1) % numPhilosophers, time.Now().UnixNano()% 1000000000)

				p.eaten++
				fmt.Printf("Philosopher %d is eating meal %d/%d\n", p.id, p.eaten, meals)

				p.leftCSMutex.Unlock()
				// fmt.Printf("Philosopher %d Put Down %d TIME %d\n", p.id, p.id, time.Now().UnixNano()% 1000000000)
				p.rightCSMutex.Unlock()
				// fmt.Printf("Philosopher %d Put Down %d TIME %d\n", p.id, (p.id + 1) % numPhilosophers, time.Now().UnixNano()% 1000000000)
			} else {
				p.leftCSMutex.Unlock()
				// fmt.Printf("Philosopher %d Put Down %d TIME %d\n", p.id, p.id, time.Now().UnixNano()% 1000000000)
			}
		}
	}
	fmt.Printf("Philosopher %d is Full\n", p.id)
}

func main() {
	numPhilosophers := 5 // Default value
	numMeals := 100      // Default value

	// Check if arguments are provided
	if len(os.Args) > 1 {
		numPhilosophers, _ = strconv.Atoi(os.Args[1])
	}
	if len(os.Args) > 2 {
		numMeals, _ = strconv.Atoi(os.Args[2])
	}
	fmt.Println("numPhilosophers ", numPhilosophers)
	fmt.Println("numMeals ", numMeals)

	// Create chopsticks mutexes
	chopstickMutexes := make([]*sync.Mutex, numPhilosophers)
	for i := 0; i < numPhilosophers; i++ {
		chopstickMutexes[i] = &sync.Mutex{}
	}

	// Create philosophers
	philosophers := make([]*Philosopher, numPhilosophers)
	for i := 0; i < numPhilosophers; i++ {
		leftCS := i
		rightCS := (i + 1) % numPhilosophers
		philosophers[i] = &Philosopher{
			id:           i,
			leftCSMutex:  chopstickMutexes[leftCS],
			rightCSMutex: chopstickMutexes[rightCS],
			eaten:        0,
		}
		fmt.Printf("Philosopher %d eats with %d %d\n", i, leftCS, rightCS)
	}

	// Start eating
	var wg sync.WaitGroup
	for _, p := range philosophers {
		wg.Add(1)
		go p.eat(numMeals, numPhilosophers, &wg)
	}
	wg.Wait()
}
