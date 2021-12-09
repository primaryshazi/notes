# CMake

## 一般编译方法

    cmake .
    make

## 命令行

    # 指定生成Unix环境下的Makefile文件
    cmake . -G "Unix Makefiles"

    # 等同于make
    cmake --build .

    # 指定CMakeLists.txt中变量value的类型为string值为"Hello World!"
    cmake . -D value:string=HelloWorld!

    # 删除CMakeLists.txt中变量value
    cmake . -U value

    # 指定项目根路径以及构建目录根路径
    cmake -S . -B .

    # 加载当前路径下的CMakeLists.txt构建缓存信息
    cmake . -C

    # 查看模式加载CMakeLists.txt
    cmake . -N

    # 生成依赖关系图至file中
    cmake . --graphviz=file

    # 启用开发人员告警
    cmake . -Wdev

    # 禁止开发人员告警
    cmake . -Wno-dev

    # 告警视为错误
    cmake . -Werror=dev

    # 错误视为告警
    cmake . -Wno-error=dev

    # 不推荐功能告警
    cmake . -Wdeprecated

    # 禁止不推荐功能告警
    cmake . -Wno-deprecated

    # 不推荐函数和宏错误
    cmake . -Werror=deprecated

    # 不推荐函数或宏告警
    cmak . -Wno-error=deprecated
