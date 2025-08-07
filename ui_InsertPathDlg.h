/********************************************************************************
** Form generated from reading UI file 'InsertPathDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTPATHDLG_H
#define UI_INSERTPATHDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_InsertPathDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditPtX;
    QLabel *label_2;
    QLineEdit *lineEditPtY;
    QLabel *label_3;
    QLineEdit *lineEditPtZ;
    QLabel *label_4;
    QLineEdit *lineEditPtA;
    QLabel *label_5;
    QLineEdit *lineEditPtB;
    QLabel *label_6;
    QLineEdit *lineEditPtC;
    QLabel *label_7;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InsertPathDlg)
    {
        if (InsertPathDlg->objectName().isEmpty())
            InsertPathDlg->setObjectName(QString::fromUtf8("InsertPathDlg"));
        InsertPathDlg->resize(300, 125);
        gridLayout = new QGridLayout(InsertPathDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(InsertPathDlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditPtX = new QLineEdit(InsertPathDlg);
        lineEditPtX->setObjectName(QString::fromUtf8("lineEditPtX"));
        lineEditPtX->setMinimumSize(QSize(68, 22));
        lineEditPtX->setMaximumSize(QSize(68, 22));

        gridLayout->addWidget(lineEditPtX, 0, 1, 1, 2);

        label_2 = new QLabel(InsertPathDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        lineEditPtY = new QLineEdit(InsertPathDlg);
        lineEditPtY->setObjectName(QString::fromUtf8("lineEditPtY"));
        lineEditPtY->setMinimumSize(QSize(68, 22));
        lineEditPtY->setMaximumSize(QSize(68, 22));

        gridLayout->addWidget(lineEditPtY, 0, 4, 1, 1);

        label_3 = new QLabel(InsertPathDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 5, 1, 1);

        lineEditPtZ = new QLineEdit(InsertPathDlg);
        lineEditPtZ->setObjectName(QString::fromUtf8("lineEditPtZ"));
        lineEditPtZ->setMinimumSize(QSize(68, 22));
        lineEditPtZ->setMaximumSize(QSize(68, 22));

        gridLayout->addWidget(lineEditPtZ, 0, 6, 1, 1);

        label_4 = new QLabel(InsertPathDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEditPtA = new QLineEdit(InsertPathDlg);
        lineEditPtA->setObjectName(QString::fromUtf8("lineEditPtA"));
        lineEditPtA->setMinimumSize(QSize(68, 22));
        lineEditPtA->setMaximumSize(QSize(68, 22));

        gridLayout->addWidget(lineEditPtA, 1, 1, 1, 2);

        label_5 = new QLabel(InsertPathDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 1);

        lineEditPtB = new QLineEdit(InsertPathDlg);
        lineEditPtB->setObjectName(QString::fromUtf8("lineEditPtB"));
        lineEditPtB->setMinimumSize(QSize(68, 22));
        lineEditPtB->setMaximumSize(QSize(68, 22));

        gridLayout->addWidget(lineEditPtB, 1, 4, 1, 1);

        label_6 = new QLabel(InsertPathDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 5, 1, 1);

        lineEditPtC = new QLineEdit(InsertPathDlg);
        lineEditPtC->setObjectName(QString::fromUtf8("lineEditPtC"));
        lineEditPtC->setMinimumSize(QSize(68, 22));
        lineEditPtC->setMaximumSize(QSize(68, 22));

        gridLayout->addWidget(lineEditPtC, 1, 6, 1, 1);

        label_7 = new QLabel(InsertPathDlg);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 2);

        comboBox = new QComboBox(InsertPathDlg);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(220, 22));
        comboBox->setMaximumSize(QSize(220, 22));

        gridLayout->addWidget(comboBox, 2, 2, 1, 5);

        buttonBox = new QDialogButtonBox(InsertPathDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setMinimumSize(QSize(160, 22));
        buttonBox->setMaximumSize(QSize(160, 22));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 2, 1, 4);

        QWidget::setTabOrder(lineEditPtX, lineEditPtY);
        QWidget::setTabOrder(lineEditPtY, lineEditPtZ);
        QWidget::setTabOrder(lineEditPtZ, lineEditPtA);
        QWidget::setTabOrder(lineEditPtA, lineEditPtB);
        QWidget::setTabOrder(lineEditPtB, lineEditPtC);
        QWidget::setTabOrder(lineEditPtC, comboBox);

        retranslateUi(InsertPathDlg);

        QMetaObject::connectSlotsByName(InsertPathDlg);
    } // setupUi

    void retranslateUi(QDialog *InsertPathDlg)
    {
        InsertPathDlg->setWindowTitle(QApplication::translate("InsertPathDlg", "InsertPathDlg", nullptr));
        label->setText(QApplication::translate("InsertPathDlg", "X:", nullptr));
        label_2->setText(QApplication::translate("InsertPathDlg", "Y:", nullptr));
        label_3->setText(QApplication::translate("InsertPathDlg", "Z:", nullptr));
        label_4->setText(QApplication::translate("InsertPathDlg", "A:", nullptr));
        label_5->setText(QApplication::translate("InsertPathDlg", "B:", nullptr));
        label_6->setText(QApplication::translate("InsertPathDlg", "C:", nullptr));
        label_7->setText(QApplication::translate("InsertPathDlg", "\345\247\277\346\200\201\347\261\273\345\236\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertPathDlg: public Ui_InsertPathDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTPATHDLG_H
