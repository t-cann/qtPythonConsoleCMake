#include "mainwindow.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , consoleWidget(new ConsoleWidget())
{
    
    this->createCentralWidget();
    this->createDockWindows();
    this->setWindowTitle("Embedded Python Console Test Application");
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
 * @brief Creates the Central Widget
 * 
 */
void MainWindow::createCentralWidget()
{
    QGroupBox* formGroupBox = new QGroupBox(tr("Passing Varibles to Python Console Test:"));
    QFormLayout *layout = new QFormLayout;
    
    QPushButton* button1 = new QPushButton(tr("Int Arrary"));
    QPushButton* button2 = new QPushButton(tr("Double Arrary"));
    QPushButton* button3 = new QPushButton(tr("Char Arrary"));
    
    layout->addRow(new QLabel(tr("Add Numpy Arrary called x to python console:")), button1);
    layout->addRow(new QLabel(tr("Add Numpy Arrary called y to python console:")), button2);
    layout->addRow(new QLabel(tr("TODO Dialog Test")), button3);
    layout->addRow(new QTextEdit());
    formGroupBox->setLayout(layout);
    this->setCentralWidget(formGroupBox);

    //Dummy Data to Test - Sending to Python. 
    int myNum[3] = {10, 20, 30};
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    const char* cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};

    // QObject::connect(button1, &QPushButton::clicked, this, &MainWindow::button1 , Qt::QueuedConnection);
    // QObject::connect(button2, &QPushButton::clicked, this, &MainWindow::updateConsole , Qt::QueuedConnection);
    // QObject::connect(button3, &QPushButton::clicked, this, &MainWindow::updateConsole , Qt::QueuedConnection);
}

// /**
//  * @brief 
//  * 
//  */
// void MainWindow::button1(){

// }

/**
 * @brief Create all the Dock Windows
 * 
 */
void MainWindow::createDockWindows(){
    QDockWidget* dock = new QDockWidget(tr("Python Console"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
    dock->setWidget(consoleWidget);
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);

}

