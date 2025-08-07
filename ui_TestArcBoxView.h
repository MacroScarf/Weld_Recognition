/********************************************************************************
** Form generated from reading UI file 'TestArcBoxView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTARCBOXVIEW_H
#define UI_TESTARCBOXVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestArcBoxViewClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_3;
    QPushButton *btnStartLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *btnStartFace;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *TestArcBoxViewClass)
    {
        if (TestArcBoxViewClass->objectName().isEmpty())
            TestArcBoxViewClass->setObjectName(QString::fromUtf8("TestArcBoxViewClass"));
        TestArcBoxViewClass->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(TestArcBoxViewClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TestArcBoxViewClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(TestArcBoxViewClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        btnStartLine = new QPushButton(TestArcBoxViewClass);
        btnStartLine->setObjectName(QString::fromUtf8("btnStartLine"));

        horizontalLayout->addWidget(btnStartLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(TestArcBoxViewClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        label_4 = new QLabel(TestArcBoxViewClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        btnStartFace = new QPushButton(TestArcBoxViewClass);
        btnStartFace->setObjectName(QString::fromUtf8("btnStartFace"));

        horizontalLayout_2->addWidget(btnStartFace);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(TestArcBoxViewClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(TestArcBoxViewClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(TestArcBoxViewClass);

        QMetaObject::connectSlotsByName(TestArcBoxViewClass);
    } // setupUi

    void retranslateUi(QWidget *TestArcBoxViewClass)
    {
        TestArcBoxViewClass->setWindowTitle(QApplication::translate("TestArcBoxViewClass", "\350\275\250\350\277\271\347\224\237\346\210\220\346\265\213\350\257\225", nullptr));
        label->setText(QApplication::translate("TestArcBoxViewClass", "\347\272\277\357\274\232", nullptr));
        label_3->setText(QApplication::translate("TestArcBoxViewClass", "TextLabel", nullptr));
        btnStartLine->setText(QApplication::translate("TestArcBoxViewClass", "\345\274\200\345\247\213", nullptr));
        label_2->setText(QApplication::translate("TestArcBoxViewClass", "\351\235\242\357\274\232", nullptr));
        label_4->setText(QApplication::translate("TestArcBoxViewClass", "TextLabel", nullptr));
        btnStartFace->setText(QApplication::translate("TestArcBoxViewClass", "\345\274\200\345\247\213", nullptr));
        pushButton->setText(QApplication::translate("TestArcBoxViewClass", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("TestArcBoxViewClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestArcBoxViewClass: public Ui_TestArcBoxViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTARCBOXVIEW_H
