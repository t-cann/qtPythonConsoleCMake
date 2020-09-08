#include "mainwindow.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , consoleWidget(new ConsoleWidget())
{
    
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
}

/**
 * @brief Create all the Dock Windows
 * 
 */
void MainWindow::createDockWindows(){
    dock= new QDockWidget(tr("Python Console"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
    dock->setWidget(consoleWidget);
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);

}

