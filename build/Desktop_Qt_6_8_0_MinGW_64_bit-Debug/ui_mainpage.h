/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_mainPage
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *mainPage)
    {
        if (mainPage->objectName().isEmpty())
            mainPage->setObjectName("mainPage");
        mainPage->resize(890, 501);
        buttonBox = new QDialogButtonBox(mainPage);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(mainPage);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, mainPage, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, mainPage, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(mainPage);
    } // setupUi

    void retranslateUi(QDialog *mainPage)
    {
        mainPage->setWindowTitle(QCoreApplication::translate("mainPage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainPage: public Ui_mainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
