CMAKE_MINIMUM_REQUIRED(VERSION 3.23 )

project("project-4")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

# Use clang++ compiler
set(CMAKE_CXX_COMPILER "clang++")

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)

# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${CMAKE_SOURCE_DIR}/tools/antlr-4.13.1-complete.jar)



# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(FormulaParser Formula.g4 LEXER PARSER LISTENER)


# include generated files in project environment
include_directories(${ANTLR_FormulaParser_OUTPUT_DIR})
include_directories(${PROJECT_SOURCE_DIR}/header)


#include_directories(${PROJECT_SOURCE_DIR}/antlr4_formula)


file(GLOB SOURCES "src/*.cpp" ${PROJECT_SOURCE_DIR}/"antlr4_formula/*.cpp" ${PROJECT_SOURCE_DIR}/"antlr4_formula/*.h")

# add generated grammar to synthtax binary target
add_executable("project-4" main.cpp
        ${ANTLR_FormulaParser_CXX_OUTPUTS}
        ${SOURCES}
        )



target_link_libraries("project-4" PRIVATE antlr4_static  )
