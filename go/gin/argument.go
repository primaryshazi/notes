package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()
	// 解析参数
	router.GET("/ping/:argument", func(c *gin.Context) {
		name := c.Param("argument")
		c.String(http.StatusOK, "argument: %s", name)
	})
	router.Run()

	/**
	 * => curl http://localhost:8080/ping/hello
	 * <= argument: hello
	 */
}
