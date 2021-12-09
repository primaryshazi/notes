package main

import (
	"fmt"
	"log"
	"net/rpc/jsonrpc"
)

type ArrayInt struct {
	Array []int
}

func main() {
	if client, err := jsonrpc.Dial("tcp", "127.0.0.1:8080"); err != nil {
		log.Fatal(err)
	} else {
		inputArray := ArrayInt{Array: []int{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}}
		var ouputArray ArrayInt
		if err := client.Call("Algorithm.Sort", inputArray, &ouputArray); err != nil {
			log.Fatal(err)
		}
		fmt.Println(inputArray, ouputArray)
	}
}
