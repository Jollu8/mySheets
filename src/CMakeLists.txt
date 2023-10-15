cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(spreadsheet)

set(CMAKE_CXX_STANDARD 20)
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(
            CMAKE_CXX_FLAGS_DEBUG
            "${CMAKE_CXX_FLAGS_DEBUG} /JMC"
    )
else()
    set(
            CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wno-implicit-fallthrough"
    )
endif()

set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/../tools/antlr-4.13.1-complete.jar)
include(${CMAKE_CURRENT_SOURCE_DIR}/FindANTLR.cmake)

# Добавляем поддиректорию antlr4_formula
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../antlr4_formula)

add_definitions(
        -DANTLR4CPP_STATIC
        -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
)

set(WITH_STATIC_CRT OFF CACHE BOOL "Visual C++ static CRT for ANTLR" FORCE)
add_subdirectory(antlr4_runtime)

antlr_target(FormulaParser Formula.g4 LEXER PARSER LISTENER)

include_directories(
        ${ANTLR4_INCLUDE_DIRS}
        ${ANTLR_FormulaParser_OUTPUT_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/antlr4_runtime/runtime/src

)

file(GLOB sources
        *.cpp
        header/*.h
        )

add_executable(
        spreadsheet
        ${ANTLR_FormulaParser_CXX_OUTPUTS}
        ${sources}
)

# Связываем исполняемый файл с библиотекой antlr4_formula
target_link_libraries(spreadsheet antlr4_static antlr4_formula)

install(
        TARGETS spreadsheet
        DESTINATION bin
        EXPORT spreadsheet
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT spreadsheet)
