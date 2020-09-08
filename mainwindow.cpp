#include <Python.h> 
#include <QtWidgets>
#include <QDebug>
#include "mainwindow.h"
//#include <python3.8/Python.h> can use this notation to chose specific versions of python if got wide imports.
//#include "consolewidget.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    console = new pyConsole(); 
    QTextEdit* textEdit = new QTextEdit(this);
    this->setCentralWidget(textEdit);
    this->createDockWindows();
    this->setWindowTitle("Test");
    this->resize(500,600);    
}

/**
 * @brief Destroy the Main Window:: Main Window object
 * 
 */
MainWindow::~MainWindow()
{
    console->~pyConsole();
}

/**
 * @brief Create all the Dock Windows
 * 
 */
void MainWindow::createDockWindows(){

    dock= new QDockWidget(tr("Python Console Test"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
    
    box = new QGroupBox(dock);
    
    button = new QPushButton(tr("Run"));
    
    lineEdit = new QLineEdit();
    lineEdit->setAcceptDrops(true);
    lineEdit->setPlaceholderText("Enter Python Commands in here.");
    
    textEdit = new QPlainTextEdit();
    textEdit->setPlaceholderText("Outputs Display Here.");
    textEdit->setReadOnly(true);
    textEdit->setMaximumBlockCount(100);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lineEdit);
    vbox->addWidget(button);
    vbox->addWidget(textEdit);
    //vbox->addStretch(1);
    
    box->setContentsMargins(0,0,0,0);
    box->setLayout(vbox);

    dock->setWidget(box);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    //Connect Button Push to the Update Console function. 
    QObject::connect(button, &QPushButton::clicked, this, &MainWindow::updateConsole , Qt::QueuedConnection);
}

/**
 * @brief Called when Button Pressed contains logic that takes text passes to Python and displays output. 
 * 
 */
void MainWindow::updateConsole(){
    bool debug = false;
    
    if (debug)
    {
        qInfo() << "Start of Update Console";    
    }

    //Test1
    //lineEdit->setText("Test");
    //Test2
    /* 
    QString linetext = lineEdit->text();
    QString text = textEdit->toPlainText();
    textEdit->setText(text +linetext); 
    */
        
    textEdit->appendPlainText(">>>" + lineEdit->text());
    QString output = console->pyRun(lineEdit->text());
    if (output!="")
    {
        textEdit->appendPlainText(output);
    }
    lineEdit->setText("");
    
    if (debug)
    {
        qInfo() << "End of Update Console";
    }
}