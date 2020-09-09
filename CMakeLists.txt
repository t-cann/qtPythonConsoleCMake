cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(embeddingPythonCmake LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Multiplatform Compatability issue (I have changed enviroment varible temperarly but could integrate into Python.) #list(APPEND ${PYTHONPATH} ${CMAKE_CURRENT_DIR}) #${CMAKE_CURRENT_DIR}/module/python_files SOURCE #message($ENV{PYTHONPATH})#set{ENV{PYTHONPATH} "$ENV{PYTHONPATH}:${CMAKE_CURRENT_DIR}")
# https://cmake.org/cmake/help/latest/module/FindPython.html  //Python3
find_package (Python3 COMPONENTS Interpreter Development NumPy)

# https://cmake.org/cmake/help/latest/manual/cmake-qt.7.html
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

#Prevents Keywords being overwritten between Qt and Python C++ API.
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

set(SOURCES main.cpp mainwindow.h mainwindow.cpp consolewidget.h consolewidget.cpp pyConsole.h pyConsole.cpp)

add_executable(embeddingPythonCmake
  ${SOURCES}
)

target_link_libraries(embeddingPythonCmake
  #Python::Python
  #Python::NumPy
  Python3::Python
  Python3::NumPy
  Qt5::Core
  Qt5::Widgets
)
