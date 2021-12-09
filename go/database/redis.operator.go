package main

import (
	"fmt"
	"log"
	"time"

	"github.com/gomodule/redigo/redis"
)

func main() {
	if rds, err := redis.Dial("tcp", "192.168.100.100:6379"); err != nil {
		log.Fatal(err)
	} else {
		defer rds.Close()

		fmt.Print("AUTH => ")
		if result, err := redis.String(rds.Do("AUTH", "asdf")); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println(result)
		}

		fmt.Print("CONFIG GET => ")
		if result, err := redis.Strings(rds.Do("CONFIG", "GET", "bind")); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println(result)
		}

		fmt.Print("SET => ")
		if _, err := rds.Do("SET", "name", "shazi", "EX", 3); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println()
		}

		fmt.Print("GET => ")
		if result, err := redis.String(rds.Do("GET", "name")); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println(result)
		}

		time.Sleep(time.Second * 3)

		fmt.Print("GET => ")
		if result, err := rds.Do("GET", "name"); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println(result)
		}

		fmt.Print("MULTI => ")
		rds.Send("MULTI")
		rds.Send("INCR", "number")
		rds.Send("INCR", "number")
		rds.Send("INCR", "number")
		rds.Send("EXPIRE", "number", 10)
		if result, err := rds.Do("EXEC"); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println(result)
		}
	}
}
