cmake_minimum_required(VERSION 3.12)

project(karyapaddatih)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(AddGoogleTest)
include(AddGoogleBenchmark)

add_library(
  algos
  src/algos/bit_twidling.cpp
  include/algos/image_proc.hpp)
target_include_directories(algos PUBLIC include)
set_target_properties(algos PROPERTIES CXX_STANDARD 17)
target_compile_features(algos PUBLIC cxx_std_14)

enable_testing()

add_executable(bits_test test/bit_twiddling_test.cpp)
target_link_libraries(bits_test PUBLIC algos)
add_gtest(bits_test)
add_executable(image_proc_test test/image_proc_test.cpp)
target_link_libraries(image_proc_test PUBLIC algos)
add_gtest(image_proc_test)
