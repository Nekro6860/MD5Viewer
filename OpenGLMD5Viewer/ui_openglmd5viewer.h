/********************************************************************************
** Form generated from reading UI file 'openglmd5viewer.ui'
**
** Created: Sun 11. Mar 01:25:03 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLMD5VIEWER_H
#define UI_OPENGLMD5VIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGLMD5ViewerClass
{
public:
    QWidget *centralwidget;
    QWidget *glCanvasWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OpenGLMD5ViewerClass)
    {
        if (OpenGLMD5ViewerClass->objectName().isEmpty())
            OpenGLMD5ViewerClass->setObjectName(QString::fromUtf8("OpenGLMD5ViewerClass"));
        OpenGLMD5ViewerClass->resize(800, 600);
        centralwidget = new QWidget(OpenGLMD5ViewerClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        glCanvasWidget = new QWidget(centralwidget);
        glCanvasWidget->setObjectName(QString::fromUtf8("glCanvasWidget"));
        glCanvasWidget->setGeometry(QRect(360, 10, 421, 551));
        OpenGLMD5ViewerClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OpenGLMD5ViewerClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        OpenGLMD5ViewerClass->setMenuBar(menubar);
        statusbar = new QStatusBar(OpenGLMD5ViewerClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OpenGLMD5ViewerClass->setStatusBar(statusbar);

        retranslateUi(OpenGLMD5ViewerClass);

        QMetaObject::connectSlotsByName(OpenGLMD5ViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLMD5ViewerClass)
    {
        OpenGLMD5ViewerClass->setWindowTitle(QApplication::translate("OpenGLMD5ViewerClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGLMD5ViewerClass: public Ui_OpenGLMD5ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLMD5VIEWER_H
