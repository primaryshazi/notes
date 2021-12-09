package main

import (
	"database/sql"
	"fmt"
	"log"

	_ "github.com/go-sql-driver/mysql"
)

const (
	MysqlAddress  = "192.168.100.100:3306"
	MysqlUsername = "root"
	MysqlPassword = "asdf"
	MysqlDatabase = "test"
)

type MysqlHandle struct {
	_handle *sql.DB
}

func (mysql *MysqlHandle) Init() {
	mysql._handle = nil
}

func (mysql *MysqlHandle) Connect(address, username, password, database string) bool {
	dataSourceName := fmt.Sprintf("%s:%s@tcp(%s)/%s", username, password, address, database)

	if handle, err := sql.Open("mysql", dataSourceName); err != nil {
		log.Println(err)
		return false
	} else {
		mysql._handle = handle
	}

	if err := mysql._handle.Ping(); err != nil {
		log.Println(err)
		mysql._handle.Close()
		mysql._handle = nil
		return false
	}

	return true
}

func (mysql *MysqlHandle) DisConnect() {
	if mysql._handle != nil {
		mysql._handle.Close()
		mysql._handle = nil
	}
}

func (mysql *MysqlHandle) Handle() *sql.DB {
	return mysql._handle
}

func main() {
	mysql := new(MysqlHandle)

	mysql.Init()
	if mysql.Connect(MysqlAddress, MysqlUsername, MysqlPassword, MysqlDatabase) {
		defer mysql.DisConnect()

		fmt.Println("SELECT => ")
		// 查询当前时间
		var current string
		if err := mysql.Handle().QueryRow("SELECT NOW()").Scan(&current); err != nil {
			log.Fatal(err)
		} else {
			fmt.Println(current)
		}

		fmt.Println("DROP TABLE => ")
		// 删除表
		if stm, err := mysql.Handle().Prepare("DROP TABLE IF EXISTS temptable"); err != nil {
			log.Fatal(err)
		} else {
			defer stm.Close()
			stm.Exec()
		}

		fmt.Println("CREATE TABLE => ")
		// 创建表
		if _, err := mysql.Handle().Exec("CREATE TABLE temptable (id INT NOT NULL AUTO_INCREMENT, val INT, PRIMARY KEY(id))"); err != nil {
			log.Fatal(err)
		}

		fmt.Println("INSERT INTO => ")
		// 执行事务
		if tx, err := mysql.Handle().Begin(); err != nil {
			log.Fatal(err)
		} else {

			if _, err := tx.Exec("INSERT INTO temptable (val) VALUES (?), (?), (?)", 1, 2, 3); err != nil {
				log.Fatal(err)
			}
			if _, err := tx.Exec("INSERT INTO temptable (val) VALUES (?), (?), (?)", 4, 5, 6); err != nil {
				log.Fatal(err)
			}
			if err := tx.Commit(); err != nil {
				log.Fatal(err)
			}
		}

		fmt.Println("SELECT => ")
		// 查询所有数据
		if rows, err := mysql.Handle().Query("SELECT id, val FROM temptable"); err != nil {
			log.Println(err)
			return
		} else {
			defer rows.Close()
			for rows.Next() {
				var id string
				var val string
				rows.Scan(&id, &val)
				fmt.Println(id, val)
			}
		}

		fmt.Print("DROP TABLE => ")
		// 删除表
		if stm, err := mysql.Handle().Prepare("DROP TABLE IF EXISTS temptable"); err != nil {
			log.Fatal(err)
		} else {
			defer stm.Close()
			stm.Exec()
		}
	}
}
