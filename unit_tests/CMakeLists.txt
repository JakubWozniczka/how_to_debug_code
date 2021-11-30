cmake_minimum_required(VERSION 3.16)

find_package(Boost 1.65 COMPONENTS program_options log unit_test_framework REQUIRED)

add_executable(main
   	main.cpp
	CameraMoveController.cpp)

target_link_libraries(main Boost::program_options Boost::log)


add_executable(tests 
	CameraMoveController.cpp
	CameraMoveControllerTests.cpp)
target_link_libraries(tests Boost::unit_test_framework Boost::log)
target_compile_definitions(tests PUBLIC BOOST_TEST_DYN_LINK)
enable_testing()
add_test(test_unit tests)
