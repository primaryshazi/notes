package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"time"
)

func writeFile(filename string) {
	if file, err := os.OpenFile(filename, os.O_CREATE|os.O_WRONLY, 0755); err != nil {
		log.Fatal(err)
	} else {
		defer file.Close()

		buf := bufio.NewWriter(file)

		for i := 0; i < 10; i++ {
			buf.WriteString(fmt.Sprintf("%d %s\n", i, time.Now().Format("2006-01-02 15:04:05.000")))
			time.Sleep(time.Millisecond * 10)
		}
		buf.Flush()
	}
}

func readFile(filename string) {
	if file, err := os.OpenFile(filename, os.O_RDONLY, 0755); err != nil {
		log.Fatal(err)
	} else {
		defer file.Close()

		buf := bufio.NewReader(file)

		for {
			data, _, eof := buf.ReadLine()
			if eof == io.EOF {
				break
			}
			fmt.Println(string(data))
		}
	}
}

func main() {
	const filename = "temp.txt"
	writeFile(filename)
	readFile(filename)
}
