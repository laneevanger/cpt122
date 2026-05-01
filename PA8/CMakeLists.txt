cmake_minimum_required(VERSION 4.2)
project(PA8)

set(CMAKE_CXX_STANDARD 14)

include_directories(project/tree)

add_executable(PA8
        project/bin/main.cpp
        project/tree/nodes.cpp
        project/tree/tree.cpp
        project/tree/tree.hpp)

add_custom_command(TARGET PA8 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/project/files/datacopy.csv
        $<TARGET_FILE_DIR:PA8>/datacopy.csv
)