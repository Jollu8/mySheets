cmake_minimum_required(VERSION 3.23)
project("project-4")

set(CMAKE_CXX_STANDARD 20)



if (MSVC)
    message(STATUS "USE VISUAL STUDIO COMPILER")
    # All flags: https://docs.microsoft.com/ru-ru/cpp/build/reference/compiler-options-listed-by-category?view=msvc-160
    add_compile_options(/WX)
else ()
    message(STATUS "USE MINGW COMPILER")
    set(SYSTEM_LIBS -lstdc++)
    #    add_compile_options(-Wall -Wextra -ltbb -lpthread) #   +fs --enable-libstdcxx-filesystem-ts
endif ()

#add_subdirectory(tests)


set(SOURCE_DIR src)


set(sheet_DIR ${SOURCE_DIR})
set(sheet_FILES
        ${sheet_DIR}/header/common.h
        ${sheet_DIR}/structures.cpp
        ${sheet_DIR}/header/test_runner_p.h
        )

# SET UP BUILD TARGETS
add_executable("project-4" main.cpp ${sheet_FILES})
