#include <Python.h> //#include <python3.8/Python.h> 

#include <QtWidgets>
#include <QDebug>

#include "mainwindow.h"
//#include "consolewidget.h"

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

MainWindow::~MainWindow()
{
    console->~pyConsole();
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

    QObject::connect(button, &QPushButton::clicked, this, &MainWindow::updateConsole , Qt::QueuedConnection);

}

void MainWindow::updateConsole(){
    //Debug1
    //qInfo() << "Start of Update Console";
    //Debug2
    //lineEdit->setText("Test");
    //Debug3
    /* 
    QString linetext = lineEdit->text();
    QString text = textEdit->toPlainText();
    textEdit->setText(text +linetext); 
     */
    //QString* linetext = lineEdit->text();
    textEdit->appendPlainText(">>>" + lineEdit->text());
    QString output = console->pyRun(lineEdit->text());
    if (output!="")
    {
        textEdit->appendPlainText(output);
    }
    
    
    lineEdit->setText("");
    //qInfo() << "End of Update Console";

}



//void someFunction();
//QObject::connect(button, &QPushButton::clicked, this, someFunction, Qt::QueuedConnection);
//ConsoleWidget *console = new ConsoleWidget(this);
//console->show();