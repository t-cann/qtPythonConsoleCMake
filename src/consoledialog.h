#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H

#include <QDialog>

// QT_BEGIN_NAMESPACE
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QDialogButtonBox;
// QT_END_NAMESPACE

class ConsoleDialog : public QDialog
{
    Q_OBJECT

public:
    ConsoleDialog(QWidget *parent = nullptr);

private:
    QLabel *label; 
    QLineEdit *lineEdit;
    QPushButton *copyButton;
    QPushButton *moveButton;
    QDialogButtonBox *buttonBox;

};


#endif