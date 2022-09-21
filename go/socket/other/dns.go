package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	dns := "baidu.com"

	addr, err := net.ResolveIPAddr("ip", dns)
	if err != nil {
		log.Fatalln(err)
	}

	fmt.Println(dns, " => ", addr.String())
}
