# mingw64环境

## 下载glfw

[glfw](https://www.glfw.org/download.html "glfw.org/download.html")

1. 下载 “64-bit Windows binaries”

## 下载glad

[glad](https://glad.dav1d.de/ "glad.dav1d.de")

1. Language:  C/C++
2. Specification: OpenGL
3. API->gl: Version 4.6
4. Profile: Core

## 编译glad

将生成的libglad.a文件拷贝到lib目录下
``` bash
# cd glad
gcc ./src/glad.c -c -I ./include
ar -rc libglad.a glad.o
```
