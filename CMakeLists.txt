cmake_minimum_required(VERSION 3.5)
project(dopamine)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES)

include_directories(include)

add_subdirectory (src)
add_subdirectory (app)

