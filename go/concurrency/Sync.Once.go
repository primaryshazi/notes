package main

import (
	"fmt"
	"sync"
)

const LoopSize int = 1000

func HelloWorld() {
	fmt.Println("Hello World!")
}

func main() {
	once := sync.Once{}

	/**
	 * => Hello World!
	 */
	for i := 0; i < LoopSize; i++ {
		once.Do(HelloWorld)
	}
}
