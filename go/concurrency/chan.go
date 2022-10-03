package main

import (
	"fmt"
	"math/rand"
	"time"
)

const LoopSize int = 100

func PrintTime(normal, done chan int) {
	fmt.Println(&normal, &done)
	isDone := false
	for !isDone {
		select {
		case v := <-normal:
			fmt.Printf("[%s] %v\n", time.Now().Format("2006-01-02 15:04:05.000000"), v)
		case <-done:
			fmt.Println("done")
			isDone = true
		default:
			fmt.Println("empty")
			time.Sleep(time.Millisecond * 500)
		}
	}
}

func main() {
	normal := make(chan int, 1)
	done := make(chan int, 1)

	fmt.Println(&normal, &done)

	go func() {
		for {
			num := rand.Intn(100)
			if num == 0 {
				done <- num
				break
			} else {
				normal <- num
				time.Sleep(time.Millisecond * 100)
			}
		}
	}()

	PrintTime(normal, done)
}
