#include <python3.8/Python.h> 

#include <QtWidgets>
#include <QDebug>

#include "mainwindow.h"
#include "pyConsole.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ////Adding a Central Widget for effect ( as Demonstration ). Probably Better ways of doing this. 
    //QTextEdit* textEdit = new QTextEdit(this);
    //setCentralWidget(textEdit);

    createDockWindows();
    setWindowTitle("Test");
    resize(300,200);
}

/**
 * @brief Destroy the Main Window:: Main Window object
 * 
 */
MainWindow::~MainWindow()
{

}

/**
 * @brief Creates all docking widget for the MainWindow.
 * 
 */
void MainWindow::createDockWindows(){

    QDockWidget* dock= new QDockWidget(tr("Python Console Test"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QGroupBox* box = new QGroupBox(dock);
    QPushButton* button = new QPushButton(tr("Run"));

    lineEdit = new QLineEdit();
    textEdit = new QPlainTextEdit();

    //textEdit->setReadOnly(true);
    //textEdit->setMaximumBlockCount(); // More like a log than textbox
    //textEdit->appendPlainText();      // Better that resetting everytime
    //textEdit - potential feature could be Syntax Highlighting //https://doc.qt.io/qt-5/qsyntaxhighlighter.html

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lineEdit);
    vbox->addWidget(button);
    vbox->addWidget(textEdit);
    //vbox->addStretch(1);
    box->setContentsMargins(0,0,0,0);
    box->setLayout(vbox);

    dock->setWidget(box);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    QObject::connect(button, &QPushButton::clicked, this, &MainWindow::updateConsole , Qt::QueuedConnection);

}

/**
 * @brief Logic when button pressed. 
 * 
 *  Step 1 Append Command to textEdit e.g. >>> 3+4 
 *  Step 2 Pass Command to Python Interpreter get QString back.
 *  Step 3 Append Returned Value to textEdit
 *  Step 4 Clear lineEdit (potential feature around suggested commands or up arrow for past commands) 
 */
void MainWindow::updateConsole(){
    QString linetext = lineEdit->text();
    QString text = textEdit->toPlainText();

    if(debug)
    {
        //Debug1
        qInfo() << "Test";
        //Debug2
        lineEdit->setText("Test");
        //Debug3    
        textEdit->setPlainText(text +linetext);
    }else
    {
        //Debug4 
        pyConsole* console = new pyConsole(); 
        QString linetext = lineEdit->text();
        textEdit->appendPlainText(console->pyRun(linetext));
        //console->~pyConsole();
    }
}

void MainWindow::createConsoleWidget(){
        //ConsoleWidget *console = new ConsoleWidget(this);
        //console->show();
}
