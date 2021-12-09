package main

import (
	"fmt"
	"log"
	"net"
	"time"
)

func main() {
	if connect, err := net.DialUDP("udp", nil, &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 8000}); err != nil {
		log.Fatal(err)
	} else {
		defer connect.Close()
		for {
			if _, err := connect.Write([]byte(fmt.Sprintf("%s", time.Now().Format("2006-01-02 15:04:05")))); err != nil {
				log.Println(err)
				break
			}

			var message [1024]byte
			if length, remoteAddr, err := connect.ReadFromUDP(message[0:]); err != nil {
				log.Println(err)
				break
			} else {
				fmt.Printf("[%s] => %s\n", remoteAddr.String(), string(message[:length]))
			}
			time.Sleep(time.Second * 1)
		}
	}
}
