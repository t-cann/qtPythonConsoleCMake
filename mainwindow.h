#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets>
#include "pyConsole.h" 

//TODO- What causes the error below?  
//Qt: Session management error: None of the authentication protocols specified are supported
//QT and Python interface overlaping enviroment variable?  env -u SESSION_MANAGER

//https://stackoverflow.com/questions/23068700/embedding-python3-in-qt-5
//https://stackoverflow.com/questions/15078060/embedding-python-in-qt-5
//https://stackoverflow.com/questions/46571438/turning-the-no-keyword-qt-option-on-in-a-cmake-file-to-work-with-boostsignal/46573144


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void updateConsole();

private:
    void createDockWindows();
    bool debug = false;
    QLineEdit* lineEdit;
    QPlainTextEdit* textEdit;
    pyConsole* console;
    //QListWidget* console;
    void createConsoleWidget();
};

#endif // MAINWINDOW_H