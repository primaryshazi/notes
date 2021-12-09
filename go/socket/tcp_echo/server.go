package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
)

func DealConnect(connect net.Conn) {
	defer connect.Close()
	for {
		if message, err := bufio.NewReader(connect).ReadString('\n'); err != nil {
			log.Println(err)
			break
		} else {
			fmt.Printf("[%s] => %s", connect.RemoteAddr().String(), message)
			connect.Write([]byte(message))
		}
	}
}

func main() {
	if lsn, err := net.Listen("tcp", "localhost:8000"); err != nil {
		log.Fatal(err)
	} else {
		defer lsn.Close()
		for {
			if connect, err := lsn.Accept(); err != nil {
				log.Fatal(err)
			} else {
				go DealConnect(connect)
			}
		}
	}
}
