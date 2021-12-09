package main

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

const (
	XmlContent string = `
<config>
    <anime kind="yuri">
        <tag>Citrus</tag>
        <tag>Bloom Into You</tag>
        <tag>Adachi And Shimamura</tag>
    </anime>
</config>
`
	XmlFilename string = "config.xml"
)

type XmlCfg struct {
	XMLName xml.Name `xml:"config"`
	Anime   AnimeSt  `xml:"anime"`
}

type AnimeSt struct {
	Kind string   `xml:"kind,attr"`
	Tag  []string `xml:"tag"`
}

func CreateFile() {
	if file, err := os.Create(XmlFilename); err != nil {
		log.Fatal(err)
	} else {
		defer file.Close()

		if _, err := file.WriteString(XmlContent); err != nil {
			log.Fatal(err)
		}
	}
}

func PrintXml(xCfg XmlCfg) {
	fmt.Println(xCfg)
	fmt.Println(xCfg.XMLName)
	for index, tag := range xCfg.Anime.Tag {
		fmt.Println(index, tag)
	}
}

func ReadXml(xCfg *XmlCfg) {
	file, err := os.Open(XmlFilename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	data, err := ioutil.ReadAll(file)
	if err != nil {
		log.Fatal(err)
	}

	*xCfg = XmlCfg{}
	err = xml.Unmarshal(data, xCfg)
	if err != nil {
		log.Fatal(err)
	}
}

func WriteXml(xCfg *XmlCfg) {
	data, err := xml.MarshalIndent(*xCfg, "", "  ")
	if err != nil {
		log.Fatal(err)
	}
	if file, err := os.Create(XmlFilename); err != nil {
		log.Fatal(err)
	} else {
		defer file.Close()
		file.Write(data)
	}
}

func main() {
	xCfg := XmlCfg{}

	CreateFile()
	ReadXml(&xCfg)
	/**
	 * => {{ config} {yuri [Citrus Bloom Into You Adachi And Shimamura]}}
	 * => { config}
	 * => 0 Citrus
	 * => 1 Bloom Into You
	 * => 2 Adachi And Shimamura
	 */
	PrintXml(xCfg)

	xCfg.Anime.Tag = append(xCfg.Anime.Tag, "A Kiss for the Petals")
	WriteXml(&xCfg)
	ReadXml(&xCfg)
	/**
	 * => {{ config} {yuri [Citrus Bloom Into You Adachi And Shimamura A Kiss for the Petals]}}
	 * => { config}
	 * => 0 Citrus
	 * => 1 Bloom Into You
	 * => 2 Adachi And Shimamura
	 * => 3 A Kiss for the Petals
	 */
	PrintXml(xCfg)
}
