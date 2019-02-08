cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(OUTPUT_DIR )

add_compile_options(-Wall)
add_executable(reference reference.cc)
add_executable(move_semantics move_semantics.cc)
add_executable(deducing_types deducing_types.cc)
add_executable(decltype decltype.cc)
