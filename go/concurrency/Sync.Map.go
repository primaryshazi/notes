package main

import (
	"fmt"
	"sync"
	"time"
)

const LoopSize int = 1000

type RepInterface interface {
	Increase()
	Reduce()
}

type Repository struct {
	_syncMap sync.Map
}

func (rep *Repository) Increase() {
	for {
		for i := 0; i < LoopSize; i++ {
			rep._syncMap.Store(i, i)
			fmt.Println("store", i)
		}
	}
}

func (rep *Repository) Reduce() {
	for {
		for i := 0; i < LoopSize; i++ {
			rep._syncMap.Delete(i)
			fmt.Println("delete", i)
		}
	}
}

func main() {
	var rep RepInterface = new(Repository)

	go rep.Increase()
	go rep.Reduce()
	time.Sleep(time.Second * 10)
}
