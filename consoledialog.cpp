#include <QtWidgets>

#include "consoledialog.h"


ConsoleDialog::ConsoleDialog(QWidget *parent) : QDialog(parent)
{    
    label = new QLabel(tr("Enter &Name:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    copyButton = new QPushButton(tr("&Copy"));
    copyButton->setDefault(true);

    moveButton = new QPushButton(tr("&Move"));
    moveButton->setCheckable(true);
    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(copyButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(moveButton, QDialogButtonBox::ActionRole);

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topLeftLayout, 0, 0);
    mainLayout->addWidget(buttonBox, 0, 1);
    mainLayout->setRowStretch(2, 1);
    setLayout(mainLayout);
    setWindowTitle(tr("Send to Console Dialog"));
}
