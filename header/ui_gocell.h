/********************************************************************************
** Form generated from reading UI file 'gocell.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOCELL_H
#define UI_GOCELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GoCell
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GoCell)
    {
        if (GoCell->objectName().isEmpty())
            GoCell->setObjectName("GoCell");
        GoCell->resize(290, 90);
        verticalLayout = new QVBoxLayout(GoCell);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(GoCell);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(GoCell);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(GoCell);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GoCell);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, GoCell, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, GoCell, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(GoCell);
    } // setupUi

    void retranslateUi(QDialog *GoCell)
    {
        GoCell->setWindowTitle(QCoreApplication::translate("GoCell", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("GoCell", "&Cell Location", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoCell: public Ui_GoCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOCELL_H
