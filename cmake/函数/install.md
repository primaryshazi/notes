# install

``` cmake
include(GNUInstallDirs)

cmake_minimum_required(VERSION 3.0.0)

project(MAIN LANGUAGES CXX)

# 指定编译类型
set(CMAKE_BUILD_TYPE Release)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(INSTLL_DIR debug)
else()
    set(INSTLL_DIR release)
endif()

add_executable(main main.cpp)

# 安装过程中打印信息
install(CODE "MESSAGE(STATUS \"Start Install\")")

# 指定安装路径前缀
set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/${INSTLL_DIR})

# 安装选项
install(TARGETS main
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE   # 设置权限
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}                      # 指定编译release版本
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}             # 可执行文件安装路径
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}             # 静态库安装路径
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}             # 动态库安装路径
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}   # public头文件安装路径
    PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}  # private头文件安装路径
)

#[[
TYPE            DESTINATION                         PATH

BIN             ${CMAKE_INSTALL_BINDIR}             bin
SBIN            ${CMAKE_INSTALL_SBINDIR}            sbin
LIB             ${CMAKE_INSTALL_SBINDIR}            sbin
INCLUDE         ${CMAKE_INSTALL_INCLUDEDIR}         include
SYSCONF         ${CMAKE_INSTALL_SYSCONFDIR}         etc
SHAREDSTATE     ${CMAKE_INSTALL_SHARESTATEDIR}      com
LOCALSTATE      ${CMAKE_INSTALL_LOCALSTATEDIR}      var
RUNSTATE        ${CMAKE_INSTALL_RUNSTATEDIR}        ${CMAKE_INSTALL_LOCALSTATEDIR}/run
DATA            ${CMAKE_INSTALL_DATADIR}            ${CMAKE_INSTALL_DATAROOTDIR}          # share
INFO            ${CMAKE_INSTALL_INFODIR}            ${CMAKE_INSTALL_DATAROOTDIR}/info
LOCALE          ${CMAKE_INSTALL_LOCALEDIR}          ${CMAKE_INSTALL_DATAROOTDIR}/locale
MAN             ${CMAKE_INSTALL_MANDIR}             ${CMAKE_INSTALL_DATAROOTDIR}/man
DOC             ${CMAKE_INSTALL_DOCDIR}             ${CMAKE_INSTALL_DATAROOTDIR}/doc
]]
# 以文件模式指定安装文件至默认var/run目录下
install(FILES CMakeLists.txt
    TYPE RUNSTATE
)

# 以安装路径指定安装文件至默认doc目录下
install(FILES Makefile
    DESTINATION ${CMAKE_INSTALL_DOCDIR}
)
```
