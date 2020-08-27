#include "consolewidget.h"
#include <QtWidgets>

ConsoleWidget::ConsoleWidget(QWidget *parent) : QWidget(parent)
{

    QPushButton *button = new QPushButton(tr("Run"));
    QLineEdit *lineEdit = new QLineEdit();
    QTextEdit *textEdit = new QTextEdit();
    QVBoxLayout *layout  = new QVBoxLayout(this);

    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(textEdit);

    this->setLayout(layout);
    this->show();
}
