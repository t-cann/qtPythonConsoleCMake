
add_executable(embeddingPythonCmake
    main.cpp
    mainwindow.h
    mainwindow.cpp 
    consolewidget.h 
    consolewidget.cpp 
    pyConsole.h 
    pyConsole.cpp 
    consoledialog.h 
    consoledialog.cpp
)

target_link_libraries(embeddingPythonCmake
  #Python::Python
  #Python::NumPy
  Python3::Python
  Python3::NumPy
  Qt5::Core
  Qt5::Widgets
)