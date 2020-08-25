#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QObject *parent =nullptr);
        ~MainWindow();
    
    private slots:



};

MainWindow::MainWindow(QObject *parent)
{
    this->setWindowTitle("Test");
    this->resize(300,200);
    //window.showFullScreen();
    this->show();
}

MainWindow::~MainWindow()
{
}

#endif
