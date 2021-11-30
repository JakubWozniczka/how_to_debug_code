cmake_minimum_required(VERSION 3.16)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread") 
#SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=thread")
#-DCMAKE_BUILD_TYPE=Debug ..
find_package(Boost 1.65 COMPONENTS program_options log unit_test_framework REQUIRED)

add_executable(main
   	main.cpp
	CameraMoveController.cpp)

target_link_libraries(main Boost::program_options Boost::log)

