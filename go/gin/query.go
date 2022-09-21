package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()
	// 获取Query参数
	router.GET("/ping", func(c *gin.Context) {
		id := c.Query("id")
		msg := c.DefaultQuery("msg", "")
		c.String(http.StatusOK, "%s:%s", id, msg)
	})
	router.Run()

	/**
	 * => curl "http://localhost:8080/ping?id=123&msg=hello"
	 * <= 123:hello
	 */
}
