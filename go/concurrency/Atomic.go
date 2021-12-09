package main

import (
	"fmt"
	"sync/atomic"
	"time"
)

const LoopSize int = 1000

type RepInterface interface {
	Increase()
	Reduce()
	Get() int64
}

type Repository struct {
	_value int64
}

func (rep *Repository) Increase() {
	atomic.AddInt64(&rep._value, 1)
}

func (rep *Repository) Reduce() {
	atomic.AddInt64(&rep._value, -1)
}

func (rep *Repository) Get() int64 {

	return atomic.LoadInt64(&rep._value)
}

func main() {
	var rep RepInterface = new(Repository)

	for i := 0; i < LoopSize; i++ {
		if i%3 == 0 {
			go func() {
				for j := 0; j < LoopSize; j++ {
					rep.Reduce()
				}
			}()
		} else {
			go func() {
				for j := 0; j < LoopSize; j++ {
					rep.Increase()
				}
			}()
		}
		fmt.Println(rep.Get())
	}
	time.Sleep(time.Second * 3)

	/**
	 * => 332000
	 */
	fmt.Println(rep.Get())
}
