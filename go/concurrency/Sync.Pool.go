package main

import (
	"fmt"
	"sync"
)

type User struct {
	Name string
}

func main() {
	objectPool := sync.Pool{New: func() interface{} {
		return new(User)
	}}

	/**
	 * => 0 0xc0000d8018
	 * => 1 0xc0000d8028
	 * => 2 0xc0000d8030
	 * => 3 0xc0000d8038
	 * => 4 0xc0000d8040
	 * => 5 0xc0000d8048
	 * => 6 0xc0000d8050
	 * => 7 0xc0000d8058
	 * => 8 0xc0000d8060
	 * => 9 0xc0000d8068
	 */
	for i := 0; i < 10; i++ {
		obj := objectPool.Get().(*User)
		obj.Name = fmt.Sprint(i)
		fmt.Println(obj.Name, &obj)
		objectPool.Put(obj)
	}
}
