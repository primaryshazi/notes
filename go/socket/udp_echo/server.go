package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	if connect, err := net.ListenUDP("udp", &net.UDPAddr{IP: net.IPv4(127, 0, 0, 1), Port: 8000}); err != nil {
		log.Fatal(err)
	} else {
		defer connect.Close()
		for {
			var message [1024]byte
			if length, remoteAddr, err := connect.ReadFromUDP(message[:]); err != nil {
				log.Println(err)
				break
			} else {
				fmt.Printf("[%s] => %s\n", remoteAddr.String(), string(message[:length]))
				connect.WriteToUDP(message[:length], remoteAddr)
			}
		}
	}
}
