file(GLOB SOURCE_FILES "*.cpp" )
message("SOURCE_FILES = ${SOURCE_FILES}")

add_library (libdopamine ${SOURCE_FILES})
