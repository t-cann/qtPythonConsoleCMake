#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLineEdit;
class QTextEdit;
class QVBoxLayout;
QT_END_NAMESPACE

class Console : public QWidget
{
    Q_OBJECT

public:
    Console();
};


#endif
