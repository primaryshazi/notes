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
	Get() int64
}

type Repository struct {
	_mtx   sync.Mutex
	_value int64
}

func (rep *Repository) Increase() {
	rep._mtx.Lock()
	defer rep._mtx.Unlock()
	rep._value++
}

func (rep *Repository) Reduce() {
	rep._mtx.Lock()
	defer rep._mtx.Unlock()
	rep._value--
}

func (rep *Repository) Get() int64 {
	rep._mtx.Lock()
	defer rep._mtx.Unlock()
	return rep._value
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
