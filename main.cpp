//#include <python3.8/Python.h>   
//#include <QtWidgets>            
// Code will not compile if include Python.h is after QtCore  -- Order should not matter.
// In my Build this includes all submodules with older version of Qt this may not. 
// Difference between QtWidgets adn QWidget Classes

#include <QApplication>
//#include "pyConsole.h"
#include"mainwindow.h"


void MainWindowtest(QApplication *a){


    //Basic Example
    qInfo() << "Hello World !!";

    //qInfo() << argv[0]; // ./embeddingPythonCmake
    qInfo() << a->allWidgets();
    qInfo() << a->allWindows();

}



int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    //Python Console Code
    //pyConsole date = pyConsole() ;  // Another method of calling test method. date.test(); 


    MainWindow w;
    w.show();

    // Why does this command not work in Test function? 
    //Answer : You are instanciating the window objects on the stack inside a a tight scope, and as you know those objects will be destructed as soon as they go out of that scope. What you are doing is letting them go out of scope before the application is ever started.
    //QMainWindow window;
    //QMainWindow window2;
    //testWidget.setText("Blah Blah");
    //window.show();
    //window2.show();

    //Method to test MainWindow Class functionality.
    //MainWindowtest(&a); 
    

  


    return a.exec(); 
}



