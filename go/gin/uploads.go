package main

import (
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
)

type FileStat struct {
	Name string `json:"name"`
	Size int64  `json:"size"`
}

type FileStatArray struct {
	Files []FileStat `json:"files"`
}

func main() {
	router := gin.Default()
	// 解析参数
	router.POST("/uploads", func(c *gin.Context) {
		if from, err := c.MultipartForm(); err != nil {
			c.String(http.StatusOK, "[%s]  upload fail: %v", time.Now().Format("2006-01-02 15:04:05.000"), err)
		} else {
			files := from.File["files"]
			var fileStats FileStatArray
			for _, file := range files {
				stat := FileStat{
					Name: file.Filename,
					Size: file.Size,
				}
				fileStats.Files = append(fileStats.Files, stat)
			}

			c.JSON(http.StatusOK, fileStats)
		}
	})
	router.Run()

	/**
	 * => curl -X POST -F "files=@1" -F "files=@2" -F "files=@3"  http://localhost:8080/uploads
	 * <= {"files":[{"name":"1","size":0},{"name":"2","size":0},{"name":"3","size":0}]}
	 */
}
