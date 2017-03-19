cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)

add_library(fs STATIC src/fs/fs.cpp)
target_include_directories(fs
	PRIVATE src
	PUBLIC include)
