package main

import (
	"fmt"
	"net/http"
	"time"
)

func Datetime(w http.ResponseWriter, r *http.Request) {
	strDatetime := fmt.Sprintf("[%s] %s\n", r.RemoteAddr, time.Now().Format("2006-01-02 15:04:05"))
	w.Write([]byte(strDatetime))
	fmt.Println(strDatetime)
}

func main() {
	http.HandleFunc("/datetime", Datetime)
	http.ListenAndServe("localhost:8080", nil)
}
