package main

import (
	"fmt"
	"log"
	"net/http"
	"time"
)

func Datetime(w http.ResponseWriter, r *http.Request) {
	strDatetime := fmt.Sprintf("[%s] %s\n", r.RemoteAddr, time.Now().Format("2006-01-02 15:04:05"))
	w.Write([]byte(strDatetime))
	fmt.Println(strDatetime)
}
func main() {
	mux := http.NewServeMux()
	serv := http.Server{
		Addr:    "localhost:8080",
		Handler: mux,
	}

	mux.HandleFunc("/datetime", Datetime)
	if err := serv.ListenAndServe(); err != nil {
		log.Println(err)
	}
}
