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

private Q_SLOTS:
    void updateConsole();

private:
    pyConsole* console;
    QLineEdit* lineEdit;
    QPlainTextEdit* textEdit;
};

#endif // CONSOLEWIDGET_H
