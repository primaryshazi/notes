package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	router.POST("/ping", func(c *gin.Context) {
		username := c.PostForm("username")
		password := c.DefaultPostForm("password", "123456")
		c.JSON(http.StatusOK, gin.H{
			"username": username,
			"password": password,
		})
	})
	router.Run()

	/**
	 * => curl http://localhost:8080/ping -X POST -d 'username=root&password=asdf'
	 * <= {"password":"asdf","username":"root"}
	 */
}
