cmake_minimum_required(VERSION 3.0.0)
project(RDS VERSION 0.1.0)

include_directories(inc/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(src/CMakeLists.txt)

include(cmake/compiler_warnings.cmake)
include(cmake/doxygen.cmake)

add_executable(RDS main.cpp ${SOURCES})

set_project_warnings(${PROJECT_NAME})