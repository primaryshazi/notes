package main

import (
	"errors"
	"fmt"
	"log"
	"net"
	"net/rpc"
	"net/rpc/jsonrpc"
	"sort"
)

type Algorithm struct {
}

type ArrayInt struct {
	Array []int
}

func (algo *Algorithm) Sort(inputArray ArrayInt, outputArray *ArrayInt) error {
	if outputArray == nil {
		return errors.New("output is nil")
	}
	if len(inputArray.Array) == 0 {
		return errors.New("input is empty")
	}
	(*outputArray).Array = append((*outputArray).Array, inputArray.Array...)
	sort.Ints((*outputArray).Array)
	fmt.Println(inputArray, *outputArray)

	return nil
}

func main() {
	algo := new(Algorithm)
	rpc.Register(algo)
	lsn, err := net.ListenTCP("tcp", &net.TCPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 8080})
	if err != nil {
		log.Fatal(err)
	}
	for {
		if connect, err := lsn.Accept(); err != nil {
			log.Println(err)
		} else {
			jsonrpc.ServeConn(connect)
		}
	}
}
