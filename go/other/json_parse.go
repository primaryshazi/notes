package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

const (
	JsonContent string = `
{
  "config": {
    "anime": {
      "kind": "yuri",
      "tag": [
        "Citrus",
        "Bloom Into You",
        "Adachi And Shimamura"
      ]
    }
  }
}
`
	JsonFilename string = "config.json"
)

type JsonSt struct {
	Config ConfigSt `json:"config"`
}

type ConfigSt struct {
	Anime AnimeSt `json:"anime"`
}

type AnimeSt struct {
	Kind string   `json:"kind"`
	Tag  []string `json:"tag"`
}

func CreateJson() {
	if file, err := os.Create(JsonFilename); err != nil {
		log.Fatal(err)
	} else {
		defer file.Close()

		if _, err := file.WriteString(JsonContent); err != nil {
			log.Fatal(err)
		}
	}
}

func PrintJson(jCfg JsonSt) {
	fmt.Println(jCfg)
	fmt.Println(jCfg.Config)
	fmt.Println(jCfg.Config.Anime)
	for index, tag := range jCfg.Config.Anime.Tag {
		fmt.Println(index, tag)
	}
}

func ReadJson(jCfg *JsonSt) {
	file, err := os.Open(JsonFilename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	data, err := ioutil.ReadAll(file)
	if err != nil {
		log.Fatal(err)
	}

	*jCfg = JsonSt{}
	err = json.Unmarshal(data, jCfg)
	if err != nil {
		log.Fatal(err)
	}
}

func WriteJson(jCfg *JsonSt) {
	data, err := json.MarshalIndent(*jCfg, "", "  ")
	if err != nil {
		log.Fatal(err)
	}
	if file, err := os.Create(JsonFilename); err != nil {
		log.Fatal(err)
	} else {
		defer file.Close()
		file.Write(data)
	}
}

func main() {
	jCfg := JsonSt{}

	CreateJson()
	ReadJson(&jCfg)
	/**
	 * => {{{yuri [Citrus Bloom Into You Adachi And Shimamura]}}}
	 * => {{yuri [Citrus Bloom Into You Adachi And Shimamura]}}
	 * => {yuri [Citrus Bloom Into You Adachi And Shimamura]}
	 * => 0 Citrus
	 * => 1 Bloom Into You
	 * => 2 Adachi And Shimamura
	 */
	PrintJson(jCfg)

	jCfg.Config.Anime.Tag = append(jCfg.Config.Anime.Tag, "A Kiss for the Petals")
	WriteJson(&jCfg)
	ReadJson(&jCfg)
	/**
	 * => {{{yuri [Citrus Bloom Into You Adachi And Shimamura A Kiss for the Petals]}}}
	 * => {{yuri [Citrus Bloom Into You Adachi And Shimamura A Kiss for the Petals]}}
	 * => {yuri [Citrus Bloom Into You Adachi And Shimamura A Kiss for the Petals]}
	 * => 0 Citrus
	 * => 1 Bloom Into You
	 * => 2 Adachi And Shimamura
	 * => 3 A Kiss for the Petals
	 */
	PrintJson(jCfg)
}
