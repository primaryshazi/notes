package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	defaultHandler := func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"path": c.FullPath(),
		})
	}

	// 分组
	group := router.Group("/group")
	{
		group.GET("/ping", defaultHandler)
		group.GET("/ping2", defaultHandler)
		group.GET("/ping3", defaultHandler)
	}

	router.Run()

	/**
	 * => curl http://localhost:8080/group/ping
	 * <= {"path":"/group/ping"}
	 *
	 * => curl http://localhost:8080/group/ping2
	 * <= {"path":"/group/ping2"}
	 *
	 * => curl http://localhost:8080/group/ping3
	 * <= {"path":"/group/ping3"}
	 */
}
