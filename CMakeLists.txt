cmake_minimum_required(VERSION 3.14)
project(crowServer)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)


# 1. Using Fetch Crow

FetchContent_Declare(
	Crow
	GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
	GIT_TAG master #or specify a particular version like "v1.2.0"
	)
FetchContent_MakeAvailable(Crow)
	
add_executable(randomServer randomServer.cpp)
target_compile_options(randomServer PRIVATE -mrdrnd)
target_link_libraries(randomServer Crow::Crow)

add_executable(trueRandomServer trueRandomServer.cpp)
target_compile_options(trueRandomServer PRIVATE -mrdrnd)
target_link_libraries(trueRandomServer Crow::Crow)

