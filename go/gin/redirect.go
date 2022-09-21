package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	// 告知请求重定向
	router.GET("/ping", func(c *gin.Context) {
		c.Redirect(http.StatusMovedPermanently, "/ping2")
	})
	router.GET("/ping2", func(c *gin.Context) {
		c.String(http.StatusOK, "this is ping2")
	})

	// 告知请求直接转发
	router.GET("/ping3", func(c *gin.Context) {
		c.Request.URL.Path = "/ping4"
		router.HandleContext(c)
	})
	router.GET("/ping4", func(c *gin.Context) {
		c.String(http.StatusOK, "this is ping4")
	})
	router.Run()

	/**
	 * => curl http://localhost:8080/ping
	 * <= <a href="/ping2">Moved Permanently</a>.
	 *
	 * => curl http://localhost:8080/ping2
	 * <= this is ping2
	 *
	 * => curl http://localhost:8080/ping3
	 * <= this is ping4
	 *
	 * => curl http://localhost:8080/ping4
	 * <= this is ping4
	 */
}
