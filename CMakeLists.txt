cmake_minimum_required(VERSION 3.22.0)

project ("CMakeProject3Тестирование")

add_subdirectory(./Catch2)
add_executable(run_test Test_main.cpp CMakeProject3.cpp CMakeProject3.h)
target_link_libraries(run_test Catch2::Catch2)
