add_library(fs STATIC src/fs/fs.cpp)
target_include_directories(fs
	PRIVATE src
	PUBLIC include)
