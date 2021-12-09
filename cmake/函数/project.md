# project

``` cmake
cmake_minimum_required(VERSION 3.0.0)

# project(MAIN)
# project(MAIN LANGUAGES CXX)
project(MAIN
    VERSION         0.1.0.0
    DESCRIPTION     "main program"
    HOMEPAGE_URL    "www.baidu.com"
    LANGUAGES        CXX
)

message(${PROJECT_NAME})
message(${PROJECT_VERSION})
message(${PROJECT_DESCRIPTION})
message(${PROJECT_HOMEPAGE_URL})

message(${CMAKE_PROJECT_NAME})
message(${CMAKE_PROJECT_VERSION})
message(${CMAKE_PROJECT_DESCRIPTION})
message(${CMAKE_PROJECT_HOMEPAGE_URL})

message(${MAIN_VERSION})
message(${MAIN_DESCRIPTION})
message(${MAIN_HOMEPAGE_URL})
```
