cmake_minimum_required(VERSION 3.5)
project(dopamine)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES)

set(KOMMONS_LIBRARY "$ENV{KOMMONS_HOME}/build/lib/libkommons.so")
include_directories(include $ENV{KOMMONS_HOME}/include)

add_subdirectory (src)
add_subdirectory (app)

