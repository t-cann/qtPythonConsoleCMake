cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(embeddingPythonCmake LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# https://cmake.org/cmake/help/latest/module/FindPython.html
find_package (Python COMPONENTS Interpreter Development)
# https://cmake.org/cmake/help/latest/manual/cmake-qt.7.html
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
#find_package(Qt5Core)

set(SOURCES main.cpp)

add_executable(embeddingPythonCmake
  ${SOURCES}
)

#Research function/macro and workout how to import SerialPort?
#qt5_use_modules(embeddingPythonCmake Core SerialPort)

#Do I need to add Python Modules in Here? 
target_link_libraries(embeddingPythonCmake
  # Why target_link_libraries ?
  Python::Python
  Qt5::Core
  Qt5::Widgets
)
