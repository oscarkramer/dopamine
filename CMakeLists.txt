cmake_minimum_required(VERSION 3.5)
project(dopamine)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES)

# Find the xstellar-commons installation (or repository) to bootstrap cmake:
if (EXISTS $ENV{KOMMONS_HOME})
   message("Accessing kommons in $ENV{KOMMONS_HOME}\n")
   set(KA_CMAKE_PATH $ENV{KOMMONS_HOME}/cmake)
elseif((EXISTS $ENV{KOMMONS_INSTALL_PREFIX}/share/kommons/cmake))
   message("Accessing kommons in $ENV{KOMMONS_INSTALL_PREFIX}\n")
   set(KA_CMAKE_PATH $ENV{KOMMONS_INSTALL_PREFIX}/share/kommons/cmake)
else()
   message(FATAL_ERROR "Could not locate xstellar-commons. Make sure one of the following is true:"
           "\nKOMMONS_INSTALL_PREFIX is set to the kommons install path, OR   "
           "KOMMONS_HOME is set to the local kommons repository directory.")
endif()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${KA_CMAKE_PATH})
find_package(Kommons)

include_directories(include ${KOMMONS_INCLUDE_DIR})

add_subdirectory (src)
add_subdirectory (app)

