cmake_minimum_required(VERSION 3.23)
project(project-4)
set(CMAKE_CXX_STANDARD 20)
include_directories(${PROJECT_SOURCE_DIR}../header)

set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/antlr-4.13.1-complete.jar)
include(${CMAKE_CURRENT_SOURCE_DIR}/FindANTLR.cmake)

add_definitions(
        -DANTLR4CPP_STATIC
        -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
)
#target_link_libraries(spreadsheet antlr4_static)



file(GLOB SOURCES "*.cpp")
add_library(project4 ${SOURCES})