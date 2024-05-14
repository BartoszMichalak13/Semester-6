package main

import (
    "fmt"
    "sync"
    "time"
)

type Philosopher struct {
    name string
    leftChopstick, rightChopstick *Chopstick
}

type Chopstick struct {
    sync.Mutex
}

func (p *Philosopher) eat(wg *sync.WaitGroup) {
    defer wg.Done()
    for i := 0; i < 3; i++ {
        p.leftChopstick.Lock()
        p.rightChopstick.Lock()
        fmt.Printf("%s is eating\n", p.name)
        time.Sleep(100 * time.Millisecond) // Simulating eating
        p.leftChopstick.Unlock()
        p.rightChopstick.Unlock()
        fmt.Printf("%s is thinking\n", p.name)
    }
}

func main() {
    chopsticks := make([]*Chopstick, 5)
    for i := 0; i < 5; i++ {
        chopsticks[i] = new(Chopstick)
    }

    philosophers := make([]*Philosopher, 5)
    names := []string{"Plato", "Socrates", "Aristotle", "Descartes", "Kant"}
    for i := 0; i < 5; i++ {
        philosophers[i] = &Philosopher{
            name:           names[i],
            leftChopstick:  chopsticks[i],
            rightChopstick: chopsticks[(i+1)%5],
        }
    }

    var wg sync.WaitGroup
    for i := 0; i < 5; i++ {
        wg.Add(1)
        go philosophers[i].eat(&wg)
    }
    wg.Wait()
}