package main

import (
	"fmt"
	"time"
)

func printNowTime(t time.Time) {
	fmt.Println(t)                      // 输出当前时间
	fmt.Println(t.Unix())               // 数据当前时间戳
	fmt.Println(t.UnixNano())           // 输出当前纳秒时间戳
	fmt.Println(time.Unix(t.Unix(), 0)) // 时间戳和时间转换
	fmt.Printf("%04d-%02d-%02d %02d:%02d:%02d\n", t.Year(), t.Month(), t.Day(), t.Hour(), t.Minute(), t.Second())
	fmt.Println("")
}

func printOperatorTime(t time.Time) {
	fmt.Println(t)

	fmt.Println(t.Add(time.Hour))        // 时间增加一时
	fmt.Println(t.Sub(t.Add(time.Hour))) // t - (t + Hour)

	fmt.Println(t.Equal(t.Add(time.Hour)))  // t是否与t+Hour想等
	fmt.Println(t.Before(t.Add(time.Hour))) // t是否在t+Hour之前
	fmt.Println(t.After(t.Add(time.Hour)))  // t是否在t+Hour之后

	fmt.Println("")
}

func printFormat(t time.Time) {
	fmt.Println(t.Format("2006-01-02 15:04:05"))
	fmt.Println(t.Format(time.ANSIC)) // 以ANSIC格式输出

	tp, _ := time.Parse("2006-01-02 15:04:05", t.Format("2006-01-02 15:04:05")) // 指定格式解析时间
	fmt.Println(tp.Unix())
	fmt.Println("")
}

func printDuration(t time.Time) {
	tp, _ := time.ParseDuration("1.5s")
	fmt.Println(tp.Truncate(time.Second)) // 向下取整
	fmt.Println(tp.Round(time.Second))    // 四舍五入
	fmt.Println(tp.Seconds())             // 秒数
	fmt.Println(time.Since(t))            // 从t开始花费了多少时间
	fmt.Println("")
}

func printTickTime(t time.Time) {
	ticker := time.Tick(time.Second) // 创建定时1秒的定时器
	for item := range ticker {
		fmt.Println(item)
		if item.After(t.Add(time.Second * 3)) {
			break
		}
	}

	for i := 0; i < 3; i++ {
		fmt.Println(time.Now())
		time.Sleep(time.Second)
	}
	fmt.Println("")
}

func main() {
	t := time.Now()
	printNowTime(t)
	printOperatorTime(t)
	printFormat(t)
	printDuration(t)
	printTickTime(t)
}
