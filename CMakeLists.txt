cmake_minimum_required(VERSION 3.17)
project(triangle)

#set(CMAKE_CXX_STANDARD 11)

add_executable(triangle main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(triangle ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

set_target_properties(
    triangle PROPERTIES
        CXX_STANDART 11
        CXX_STANDART_REQUIRED ON
)