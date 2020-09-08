#include <Python.h>
#include <QWidget>  //For this version of  QT need to explicitly import everything you use.
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
// #include <QVBoxLayout>
#include <pyConsole.h>
// #include <QSerialPort>
#include <QProcess>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Run Command"), &window);
    QLabel *label = new QLabel("Output", &window);
    QLineEdit *lineEdit = new QLineEdit(&window);


    QHBoxLayout *layout = new QHBoxLayout(&window);
    
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(label);
    window.setLayout(layout);
    window.setWindowTitle(
        QApplication::translate("windowlayout", "Basic Console App"));
    
    QString result = "Blah";
    QObject::connect(button, SIGNAL(clicked()), label, SLOT(clear()));
    
    //Does not work and don't know why?
    //QObject::connect(button, SIGNAL(clicked()), label, SLOT(setText(result)));
    window.show();

    pyConsole py = pyConsole(argv);
    char *command = (char *)"print('Test')"; 
    py.runCommand(command); 

    //How to convert chat * to wchar** -> If you know it is off the right format you can cast it directly. 
    //Py_Main(argc,(wchar_t**)argv);
    
    //QSerialPort Testing
    /* QSerialPort test;
    test.setPortName("testport");
    qDebug()<<"Hello Qt"; */

    //QProcess https://doc.qt.io/qt-5/qprocess.html#details

    /* QProcess test = new QProcess();
    start process to run program with parameter
    wait till finished.. */
    
    return app.exec();
}