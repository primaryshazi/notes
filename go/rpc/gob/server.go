package main

import (
	"errors"
	"fmt"
	"log"
	"net/http"
	"net/rpc"
	"sort"
)

type Algorithm struct {
}

func (algo *Algorithm) Sort(inputArray []int, outputArray *[]int) error {
	if len(inputArray) == 0 {
		return errors.New("input is empty")
	}
	*outputArray = append(*outputArray, inputArray...)
	sort.Ints(*outputArray)
	fmt.Println(inputArray, *outputArray)

	return nil
}

func main() {
	algo := new(Algorithm)
	rpc.Register(algo)
	rpc.HandleHTTP()
	if err := http.ListenAndServe("localhost:8080", nil); err != nil {
		log.Fatal(err)
	}
}
