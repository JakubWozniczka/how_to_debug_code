cmake_minimum_required(VERSION 3.16)
#option(BUILD_ADDRESS_SANITIZER "Build with address sanitizier" OFF)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address") 
message("Added address sanitizer")
endif()


find_package(Boost 1.65 COMPONENTS program_options log unit_test_framework REQUIRED)

add_executable(main
   	main.cpp
	CameraMoveController.cpp)

target_link_libraries(main Boost::program_options Boost::log)
