package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	// map参数
	router.POST("/ping", func(c *gin.Context) {
		ids := c.QueryMap("ids")
		usernames := c.PostFormMap("usernames")

		c.JSON(http.StatusOK, gin.H{
			"ids":       ids,
			"usernames": usernames,
		})
	})
	router.Run()

	/**
	 * => curl -g  "http://localhost:8080/ping?ids[a]=1&ids[b]=2" -X POST -d 'usernames[a]=ua&usernames[b]=ub'
	 * <= {"ids":{"a":"1","b":"2"},"usernames":{"a":"ua","b":"ub"}}
	 */
}
