package main

import (
    "encoding/csv"
    "fmt"
    "log"
    "os"
)

func writeToCsv(filename string) {
    if file, err := os.OpenFile(filename, os.O_RDWR|os.O_CREATE, 0666); err != nil {
        log.Fatal(err)
    } else {
        defer file.Close()

        writer := csv.NewWriter(file)
        writer.Comma = ','                      // 指定逗号分隔符
        writer.UseCRLF = false                  // 不适用CRLF作为换行符
        writer.Write([]string{"name", "score"}) // 写入一行
        writer.Flush()

        //一次写入多行
        var bufs [][]string
        bufs = append(bufs, []string{"citrus", "8,0"})
        bufs = append(bufs, []string{"yuru yuri", "9.5"})
        writer.WriteAll(bufs)
        writer.Flush()
    }
}

func readFromCsv(filename string) {
    if file, err := os.Open(filename); err != nil {
        log.Fatal(err)
    } else {
        defer file.Close()

        reader := csv.NewReader(file)
        reader.Comma = ','
        reader.FieldsPerRecord = 2     // 2个字段
        reader.TrimLeadingSpace = true // 去除前导空格
        if content, err := reader.ReadAll(); err != nil {
            log.Fatal(err)
        } else {
            for _, row := range content {
                fmt.Println(row)
            }
        }
    }
}

func main() {
    const FILE_NAME string = "temp.csv"
    writeToCsv(FILE_NAME)
    readFromCsv(FILE_NAME)
}
