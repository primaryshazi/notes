package main

import (
	"fmt"
	"sync"
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
	wg := sync.WaitGroup{}
	var rep RepInterface = new(Repository)

	for i := 0; i < LoopSize; i++ {
		if i%3 == 0 {
			go func() {
				wg.Add(1)
				for j := 0; j < LoopSize; j++ {
					rep.Reduce()
				}
				wg.Done()
			}()
		} else {
			go func() {
				wg.Add(1)
				for j := 0; j < LoopSize; j++ {
					rep.Increase()
				}
				wg.Done()
			}()
		}
		fmt.Println(rep.Get())
	}
	wg.Wait()

	/**
	 * => 332000
	 */
	fmt.Println(rep.Get())
}
