package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"time"
)

func main() {
	if connect, err := net.Dial("tcp", "localhost:8000"); err != nil {
		log.Fatal(err)
	} else {
		defer connect.Close()
		for {
			if _, err := connect.Write([]byte(fmt.Sprintf("%s\n", time.Now().Format("2006-01-02 15:04:05")))); err != nil {
				log.Println(err)
				break
			}

			if message, err := bufio.NewReader(connect).ReadString('\n'); err != nil {
				log.Println(err)
				break
			} else {
				fmt.Printf("[%s] => %s", connect.RemoteAddr().String(), message)
			}
			time.Sleep(time.Second * 1)
		}
	}
}
