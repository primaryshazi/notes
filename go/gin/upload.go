package main

import (
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()
	// 解析参数
	router.POST("/upload", func(c *gin.Context) {
		file, err := c.FormFile("file")
		if err != nil {
			c.String(http.StatusOK, "[%s]  upload fail: %v", time.Now().Format("2006-01-02 15:04:05.000"), err)
		} else {
			c.String(http.StatusOK, "[%s]  upload succ: %s:%d", time.Now().Format("2006-01-02 15:04:05.000"), file.Filename, file.Size)
		}
	})
	router.Run()

	/**
	 * => curl -X POST -F "file=@main.cpp" http://localhost:8080/upload
	 * <= [2022-10-02 17:14:35.159]  upload succ: main.cpp:91
	 */
}
