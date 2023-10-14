cmake_minimum_required(VERSION 3.23 )
project(project4)

set(CMAKE_CXX_STANDARD 17)

    set(
            CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-implicit-fallthrough"
    )





add_subdirectory(antlr4_runtime)

#add_subdirectory(tests)
add_subdirectory(src)
#target_link_libraries(project-4 antlr4_static src)

add_executable(spreadsheet main.cpp antlr4_runtime src)


install(
        TARGETS spreadsheet
        DESTINATION bin
        EXPORT spreadsheet
)


#`set_directory_properties(PROPERTIES VS_STARTUP_PROJECT spreadsheet)
#`