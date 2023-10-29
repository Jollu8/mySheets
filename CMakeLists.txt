CMAKE_MINIMUM_REQUIRED(VERSION 3.23)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project("project-4" VERSION ${PROJECT_VERSION})

option(WITH_GOOGLE_TEST "Whether to build Google tets" ON)


configure_file(versiondef.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/versiondef.h)
set(CMAKE_AUTOUIC ON)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 20)

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
include_directories(${PROJECT_SOURCE_DIR}/img)


#include_directories(${PROJECT_SOURCE_DIR}/antlr4_formula)


file(GLOB SOURCES "src/*.cpp" ${PROJECT_SOURCE_DIR}/"antlr4_formula/*.cpp" ${PROJECT_SOURCE_DIR}/"antlr4_formula/*.h")


find_package(Qt6 COMPONENTS Core Widgets Gui REQUIRED)


set(FORMS
        finddialog.ui
        gocell.ui
)

file(GLOB HEADERS
        header/ui_finddialog.h
        header/ui_gocell.h
        header/finddialog.h
        header/gocell.h
        header/spreadsheet.h

)
qt6_wrap_cpp(MOC ${HEADERS})
qt6_wrap_ui(UI ${FORMS})

add_executable(${PROJECT_NAME} main.cpp ${ANTLR_FormulaParser_CXX_OUTPUTS} ${SOURCES} ${MOC} ${UI})

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets antlr4_static)


#
#qt6_wrap_ui(PROJECT_SOURCES ${PROJECT_UI})
#set(PROJECT_UI spreadsheetwindow.ui)
#qt6_wrap_ui(PROJECT_SOURCES ${PROJECT_UI})
#file(GLOB S_QT "*./cpp" "./*.h" "*.ui")
## add generated grammar to synthtax binary target
#add_executable("project-4" main.cpp
#        ${ANTLR_FormulaParser_CXX_OUTPUTS}
#        ${S_QT}
#        ${SOURCES}
#        spreadsheetwindow.cpp
#        spreadsheettable.cpp
#)


#target_link_libraries("project-4" PRIVATE Qt6::Core Qt6::Widgets antlr4_static)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT zholu008@gmail.com)
include(CPack)



