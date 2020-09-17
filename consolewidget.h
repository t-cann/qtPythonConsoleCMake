#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "pyConsole.h" 

class ConsoleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleWidget(QWidget *parent = nullptr);
    ~ConsoleWidget();

Q_SIGNALS:


public Q_SLOTS:
    void updateConsole();
//  void clearConsole();
//  void toConsole(int *x);
//  void toConsole(QString *x);
//  void toConsole(int[3] *x);
//  void toConsole(DataArray *x);

private:
    pyConsole* console;     //Need Better Name - can't have multiple Consoles does not make sense. Interpreter/Run
    QLineEdit* lineEdit;
    QPlainTextEdit* textEdit;
    int arraytoPython();
};

#endif // CONSOLEWIDGET_H
