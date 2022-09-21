package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	router.POST("/ping", func(c *gin.Context) {
		id := c.Query("id")
		msg := c.DefaultQuery("msg", "")
		username := c.PostForm("username")
		password := c.DefaultPostForm("password", "123456")
		c.JSON(http.StatusOK, gin.H{
			"id":       id,
			"msg":      msg,
			"username": username,
			"password": password,
		})
	})
	router.Run()

	/**
	 * => curl "http://localhost:8080/ping?id=123&msg=hello" -X POST -d 'username=root&password=asdf'
	 * <= {"id":"123","msg":"hello","password":"asdf","username":"root"}
	 */
}
