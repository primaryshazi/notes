package main

import (
	"fmt"
	"log"
	"regexp"
)

func main() {
	strSource := "2006-01-02 15-04-05"
	strRegex := `([\d]+)-([\d]+)-([\d]+)`

	regex, err := regexp.Compile(strRegex)
	if err != nil {
		log.Fatal(err)
	}

	/**
	 * => true
	 * => 2006-01-02
	 * => [2006-01-02]
	 * => [2006-01-02 15-04-05]
	 * => [[2006-01-02 2006 01 02]]
	 * => [[2006-01-02 2006 01 02] [15-04-05 15 04 05]]
	 */
	fmt.Println(regex.MatchString(strSource))
	fmt.Println(regex.FindString(strSource))
	fmt.Println(regex.FindAllString(strSource, 1))
	fmt.Println(regex.FindAllString(strSource, -1))
	fmt.Println(regex.FindAllStringSubmatch(strSource, 1))
	fmt.Println(regex.FindAllStringSubmatch(strSource, -1))

	/**
	 * => [2006-01-02 15-04-05]
	 * => [   ]
	 */
	fmt.Println(regex.Split(strSource, 1))
	fmt.Println(regex.Split(strSource, -1))

	/**
	 * => 02+01+2006 05+04+15
	 */
	fmt.Println(regex.ReplaceAllString(strSource, "$3+$2+$1"))
}
