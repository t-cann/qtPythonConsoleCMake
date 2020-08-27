#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets>
//#include "pyConsole.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateConsole();

private:
    void createDockWindows();
    QDockWidget* dock;
    //QListWidget* console;
    QGroupBox* box;
    QPushButton* button;
    QLineEdit* lineEdit;
    QTextEdit* textEdit;
    //pyConsole console;
};




#endif // MAINWINDOW_H