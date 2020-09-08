#include "consolewidget.h"

// #include <Python.h> 
//#include <python3.8/Python.h> can use this notation to chose specific versions of python if got wide imports.
// #include <QDebug>

/**
 * @brief Construct a new Console Widget:: Console Widget object
 * 
 * @param parent 
 */
ConsoleWidget::ConsoleWidget(QWidget *parent) : QWidget(parent), console(new pyConsole())
{
    QPushButton* button = new QPushButton(tr("Run"));
    
    lineEdit = new QLineEdit();
    lineEdit->setAcceptDrops(true);
    lineEdit->setPlaceholderText("Enter Python Commands in here.");
    
    textEdit = new QPlainTextEdit();
    textEdit->setPlaceholderText("Outputs Display Here.");
    textEdit->setReadOnly(true);
    textEdit->setMaximumBlockCount(100);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lineEdit);
    vbox->addWidget(button);
    vbox->addWidget(textEdit);
    
    //Connect Button Push to the Update Console function. 
    QObject::connect(button, &QPushButton::clicked, this, &ConsoleWidget::updateConsole , Qt::QueuedConnection);
    QObject::connect(lineEdit, &QLineEdit::returnPressed, this, &ConsoleWidget::updateConsole , Qt::QueuedConnection);
    this->setLayout(vbox);

}

/**
 * @brief Destroy the Console Widget:: Console Widget object
 * 
 */
ConsoleWidget::~ConsoleWidget()
{
    console->~pyConsole();
}

/**
 * @brief Called when Button Pressed contains logic that takes text passes to Python and displays output. 
 * 
 */
void ConsoleWidget::updateConsole(){
    bool debug = false;
    
    if (debug)
    {
        qInfo() << "Start of Update Console";    
    }

    //Test1
    //lineEdit->setText("Test");
    //Test2
    /* 
    QString linetext = lineEdit->text();
    QString text = textEdit->toPlainText();
    textEdit->setText(text +linetext); 
    */
        
    textEdit->appendPlainText(">>>" + lineEdit->text());
    QString output = console->pyRun(lineEdit->text());
    if (output!="")
    {
        textEdit->appendPlainText(output);
    }
    lineEdit->setText("");
    
    if (debug)
    {
        qInfo() << "End of Update Console";
    }
}