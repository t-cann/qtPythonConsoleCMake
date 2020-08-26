#include <QWidgets>
#include <console.h>

Console::Console() 
{
    
    QPushButton *button = new QPushButton(tr("Run"),this);
    QLineEdit *lineEdit = new QLineEdit(this);
    QTextEdit *textEdit = new QTextEdit(this);
    QVBoxLayout *layout  = new QVBoxLayout(this);

    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(textEdit);

    setLayout(layout);
    setWindowTitle("Python Console Example");
    
    //void someFunction();
    //QObject::connect(button, &QPushButton::clicked, this, someFunction, Qt::QueuedConnection);

    //QApplication::translate("windowlayout", "Window layout"));
    //this->setWindowTitle("Test");
    //this->resize(300,200);
    //window.showFullScreen();
    //this->show();
}
