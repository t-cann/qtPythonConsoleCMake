#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets>
//#include "pyConsole.h" 

//https://stackoverflow.com/questions/23068700/embedding-python3-in-qt-5
//https://stackoverflow.com/questions/15078060/embedding-python-in-qt-5
//https://stackoverflow.com/questions/46571438/turning-the-no-keyword-qt-option-on-in-a-cmake-file-to-work-with-boostsignal/46573144


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