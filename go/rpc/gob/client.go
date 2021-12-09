package main

import (
	"fmt"
	"log"
	"net/rpc"
)

func main() {
	if client, err := rpc.DialHTTP("tcp", "localhost:8080"); err != nil {
		log.Fatal(err)
	} else {
		inputArray := []int{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}
		var ouputArray []int
		if err := client.Call("Algorithm.Sort", inputArray, &ouputArray); err != nil {
			log.Fatal(err)
		}
		fmt.Println(inputArray, ouputArray)
	}
}
