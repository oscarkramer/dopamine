add_executable (dopamine dopamine.cpp ${SOURCE_FILES})
target_link_libraries(dopamine ${requiredLibs} ${KOMMONS_LIBRARY} )
