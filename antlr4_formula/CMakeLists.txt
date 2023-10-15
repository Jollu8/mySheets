cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

# Подключаем ANTLR
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/../tools/antlr-4.13.1-complete.jar)
include(${CMAKE_CURRENT_SOURCE_DIR}/FindANTLR.cmake)

# Добавляем определения
add_definitions(
        -DANTLR4CPP_STATIC
        -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
)

# Устанавливаем свойства для ANTLR
set(WITH_STATIC_CRT OFF CACHE BOOL "Visual C++ static CRT for ANTLR" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../antlr4_runtime)

# Создаем цель для ANTLR
antlr_target(FormulaParser Formula.g4 LEXER PARSER LISTENER)

# Добавляем директории включения
include_directories(
        ${ANTLR4_INCLUDE_DIRS}
        ${ANTLR_FormulaParser_OUTPUT_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../antlr4_runtime/runtime/src
)

# Собираем исходные файлы
file(GLOB sources *.cpp *.h)

# Создаем библиотеку
add_library(
        antlr4_formula
        ${ANTLR_FormulaParser_CXX_OUTPUTS}
        ${sources}
)

# Связываем библиотеку с antlr4_static
target_link_libraries(antlr4_formula antlr4_static)
