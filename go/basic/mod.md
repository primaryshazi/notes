# mod

## 基本命令

### 启用mod

go env -w GO111MODULE=on

### 初始化

go mod init Directory

### 下载

go mod download

### 精简

go mod tidy

### 校验

go mod verify

### 依赖

go mod why

### 依赖图

go mod graph

### 编辑

go mod edit

## 格式

``` mod
module test

go 1.19

require (
    github.com/go-sql-driver/mysql v1.6.0
)

replace (
    github.com/go-sql-driver/mysql => github.com/go-sql-driver/mysql v1.6.0
)

exclude (
    github.com/go-sql-driver/mysql v1.5.0
)
```