#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "pyConsole.h" 



class mainwindow
{
private:
    
public:
    mainwindow(int argc, char *argv[]);
    ~mainwindow();
};

mainwindow::mainwindow(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;


    w.show();
    app.exec(); 
}

mainwindow::~mainwindow()
{
}



//https://stackoverflow.com/questions/34245235/qt-how-to-redirect-qprocess-stdout-to-textedit

/* class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private Q_SLOTS:
    void updateConsole();

private:
    void createDockWindows();
    QDockWidget* dock;
    //QListWidget* console;
    QGroupBox* box;
    QPushButton* button;
    QLineEdit* lineEdit;
    QPlainTextEdit* textEdit;
    pyConsole* console;
};

public slots:
    void runCommand();
    void readCommand();
    void stopCommand(int exitCode, QProcess::ExitStatus exitStatus);

//private or public?
private slots:
    void error(QProcess::ProcessError error);
    void stateChanged(QProcess::ProcessState state);

private:
    QProcess *cmd;
}; */

#endif