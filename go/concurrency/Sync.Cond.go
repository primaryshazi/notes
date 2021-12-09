package main

import (
	"fmt"
	"sync"
	"time"
)

const (
	MaxValue int64 = 1000
	MinValue int64 = 0
)

type RepInterface interface {
	Init()
	Increase()
	Reduce()
}

type Repository struct {
	_cond  *sync.Cond
	_value int64
}

func (rep *Repository) Init() {
	rep._cond = sync.NewCond(new(sync.Mutex))
	rep._value = 0
}

func (rep *Repository) Increase() {
	for {
		rep._cond.L.Lock()
		for {
			rep._value++
			if MaxValue <= rep._value {
				break
			}
		}
		fmt.Println("this is max")
		time.Sleep(time.Millisecond * 100)
		rep._cond.L.Unlock()
		rep._cond.Signal()
	}
}

func (rep *Repository) Reduce() {
	for {
		rep._cond.L.Lock()
		rep._cond.Wait()
		for {
			rep._value--
			if MinValue >= rep._value {
				break
			}
		}
		fmt.Println("this is min")
		time.Sleep(time.Millisecond * 100)
		rep._cond.L.Unlock()
	}
}

func main() {
	var rep RepInterface = new(Repository)
	rep.Init()

	go rep.Increase()
	go rep.Reduce()
	time.Sleep(time.Second * 10)
}
