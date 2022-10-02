package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.New()
	router.GET("/ping", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"message": "pong",
		})
	})
	router.Run("0.0.0.0:8888")

	/**
	 * => curl http://localhost:8888/ping
	 * <= {"message", "pong"}
	 */
}
