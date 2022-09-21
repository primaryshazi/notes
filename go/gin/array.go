package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	// array参数
	router.POST("/ping", func(c *gin.Context) {
		ids := c.QueryArray("ids")
		usernames := c.PostFormArray("usernames")

		c.JSON(http.StatusOK, gin.H{
			"ids":       ids,
			"usernames": usernames,
		})
	})
	router.Run()

	/**
	 * => curl -g "http://localhost:8080/ping?ids=1,2" -X POST -d 'usernames=ua,ub'
	 * <= {"ids":["1,2"],"usernames":["aaa,bbb"]}
	 */
}
