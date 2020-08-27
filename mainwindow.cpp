#include <python3.8/Python.h> 

#include <QtWidgets>
#include <QDebug>

#include "mainwindow.h"
//#include "consolewidget.h"

#include "pyConsole.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    
    //QTextEdit* textEdit = new QTextEdit(this);
    //setCentralWidget(textEdit);
    createDockWindows();
    setWindowTitle("Test");
    resize(300,200);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createDockWindows(){

    // QDockWidget *dock = new QDockWidget(tr("Customers"), this);
    // dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // console = new QListWidget(dock);
    // console->addItems(QStringList()
    //         << "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
    //         << "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
    //         << "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
    //         << "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
    //         << "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
    //         << "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
    // dock->setWidget(console);
    // addDockWidget(Qt::RightDockWidgetArea, dock);
    // //viewMenu->addAction(dock->toggleViewAction());

    dock= new QDockWidget(tr("Python Console Test"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    box = new QGroupBox(dock);
    button = new QPushButton(tr("Run"));
    lineEdit = new QLineEdit();
    textEdit = new QTextEdit();

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

void MainWindow::updateConsole(){
    //Debug1
    //qInfo() << "Test";
    //Debug2
    //lineEdit->setText("Test");
    //Debug3
    /* 
    QString linetext = lineEdit->text();
    QString text = textEdit->toPlainText();
    textEdit->setText(text +linetext); 
    */
    pyConsole console = pyConsole(); 
    //QString linetext = lineEdit->text();
    //textEdit->setText(console.runString(linetext));
    //console->~pyConsole();


}

//void someFunction();
//QObject::connect(button, &QPushButton::clicked, this, someFunction, Qt::QueuedConnection);
//ConsoleWidget *console = new ConsoleWidget(this);
//console->show();