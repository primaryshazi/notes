package main

import (
	"fmt"
	"math/rand"
	"time"
)

const LoopSize int = 100

func PrintTime(normal, done *chan int) {
	isDone := false
	for !isDone {
		select {
		case <-*normal:
			fmt.Println(time.Now().Format("2006-01-02 15:04:05.000000"))
		case <-*done:
			fmt.Println("done")
			isDone = true
		default:
			fmt.Println("default")
		}
		time.Sleep(time.Millisecond * 500)
	}
}

func main() {
	normal := make(chan int, 1)
	done := make(chan int, 1)

	go func() {
		for {
			num := rand.Intn(100)
			if num == 0 {
				done <- num
				time.Sleep(time.Millisecond * 100)
			} else {
				normal <- num
				time.Sleep(time.Millisecond * 1000)
			}
		}
	}()
	PrintTime(&normal, &done)
}
