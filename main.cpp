#include <python3.8/Python.h>   // Code will not compile if include Python.h is after QtCore  -- Order should not matter.
#include <QtWidgets>            //

#include "pyConsole.h"


void test(QApplication *a){
    //Basic Example
    qInfo() << "Hello World !!";

    //qInfo() << argv[0]; // ./embeddingPythonCmake
    qInfo() << a->allWidgets();
    qInfo() << a->allWindows();

    //Python Console Code
    pyConsole date; 
    
    date.test(); 

}



int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QMainWindow window;
    QMainWindow window2;
    //testWidget.setText("Blah Blah");
    window.show();
    window2.show();

    test(&a); 

    return a.exec(); 
}