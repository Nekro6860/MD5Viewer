/********************************************************************************
** Form generated from reading UI file 'openglmd5viewer.ui'
**
** Created: Wed 14. Mar 06:59:33 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGLMD5ViewerClass
{
public:
    QAction *actionCharger_modele;
    QAction *actionCharger_animation;
    QAction *actionCharger_diffuse_map;
    QAction *actionCharger_bump_map;
    QAction *actionCharger_specular_map;
    QAction *actionQuitter;
    QAction *actionPlay_pause;
    QAction *actionStop;
    QWidget *centralwidget;
    QWidget *glCanvasWidget;
    QLabel *label;
    QComboBox *view;
    QCheckBox *showSqueleton;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *modelLocation;
    QLineEdit *animationLocation;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *diffuseMapLocation;
    QLineEdit *bumpMapLocation;
    QLineEdit *specularMapLocation;
    QPushButton *parcourirBumpMap;
    QPushButton *parcourirDiffuseMap;
    QPushButton *parcourirAnimation;
    QPushButton *parcourirModele;
    QPushButton *parcourirSpecularMap;
    QPushButton *appliquerVue;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OpenGLMD5ViewerClass)
    {
        if (OpenGLMD5ViewerClass->objectName().isEmpty())
            OpenGLMD5ViewerClass->setObjectName(QString::fromUtf8("OpenGLMD5ViewerClass"));
        OpenGLMD5ViewerClass->resize(800, 600);
        QFont font;
        font.setPointSize(12);
        OpenGLMD5ViewerClass->setFont(font);
        actionCharger_modele = new QAction(OpenGLMD5ViewerClass);
        actionCharger_modele->setObjectName(QString::fromUtf8("actionCharger_modele"));
        actionCharger_animation = new QAction(OpenGLMD5ViewerClass);
        actionCharger_animation->setObjectName(QString::fromUtf8("actionCharger_animation"));
        actionCharger_diffuse_map = new QAction(OpenGLMD5ViewerClass);
        actionCharger_diffuse_map->setObjectName(QString::fromUtf8("actionCharger_diffuse_map"));
        actionCharger_bump_map = new QAction(OpenGLMD5ViewerClass);
        actionCharger_bump_map->setObjectName(QString::fromUtf8("actionCharger_bump_map"));
        actionCharger_specular_map = new QAction(OpenGLMD5ViewerClass);
        actionCharger_specular_map->setObjectName(QString::fromUtf8("actionCharger_specular_map"));
        actionQuitter = new QAction(OpenGLMD5ViewerClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionPlay_pause = new QAction(OpenGLMD5ViewerClass);
        actionPlay_pause->setObjectName(QString::fromUtf8("actionPlay_pause"));
        actionStop = new QAction(OpenGLMD5ViewerClass);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        centralwidget = new QWidget(OpenGLMD5ViewerClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        glCanvasWidget = new QWidget(centralwidget);
        glCanvasWidget->setObjectName(QString::fromUtf8("glCanvasWidget"));
        glCanvasWidget->setGeometry(QRect(360, 50, 421, 501));
        QFont font1;
        font1.setPointSize(10);
        glCanvasWidget->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 20, 71, 16));
        label->setFont(font1);
        label->setOpenExternalLinks(false);
        view = new QComboBox(centralwidget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(430, 20, 141, 21));
        view->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        showSqueleton = new QCheckBox(centralwidget);
        showSqueleton->setObjectName(QString::fromUtf8("showSqueleton"));
        showSqueleton->setGeometry(QRect(660, 18, 121, 23));
        showSqueleton->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(58, 210, 61, 16));
        label_2->setFont(font1);
        label_2->setOpenExternalLinks(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(42, 240, 71, 16));
        label_3->setFont(font1);
        label_3->setOpenExternalLinks(false);
        modelLocation = new QLineEdit(centralwidget);
        modelLocation->setObjectName(QString::fromUtf8("modelLocation"));
        modelLocation->setGeometry(QRect(120, 210, 201, 20));
        modelLocation->setFont(font1);
        modelLocation->setReadOnly(true);
        animationLocation = new QLineEdit(centralwidget);
        animationLocation->setObjectName(QString::fromUtf8("animationLocation"));
        animationLocation->setGeometry(QRect(120, 240, 201, 20));
        animationLocation->setFont(font1);
        animationLocation->setReadOnly(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(31, 270, 81, 16));
        label_4->setFont(font1);
        label_4->setOpenExternalLinks(false);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(38, 300, 71, 16));
        label_5->setFont(font1);
        label_5->setOpenExternalLinks(false);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 330, 91, 16));
        label_6->setFont(font1);
        label_6->setOpenExternalLinks(false);
        diffuseMapLocation = new QLineEdit(centralwidget);
        diffuseMapLocation->setObjectName(QString::fromUtf8("diffuseMapLocation"));
        diffuseMapLocation->setGeometry(QRect(120, 270, 201, 20));
        diffuseMapLocation->setFont(font1);
        diffuseMapLocation->setReadOnly(true);
        bumpMapLocation = new QLineEdit(centralwidget);
        bumpMapLocation->setObjectName(QString::fromUtf8("bumpMapLocation"));
        bumpMapLocation->setGeometry(QRect(120, 300, 201, 20));
        bumpMapLocation->setFont(font1);
        bumpMapLocation->setReadOnly(true);
        specularMapLocation = new QLineEdit(centralwidget);
        specularMapLocation->setObjectName(QString::fromUtf8("specularMapLocation"));
        specularMapLocation->setGeometry(QRect(120, 330, 201, 20));
        specularMapLocation->setFont(font1);
        specularMapLocation->setReadOnly(true);
        parcourirBumpMap = new QPushButton(centralwidget);
        parcourirBumpMap->setObjectName(QString::fromUtf8("parcourirBumpMap"));
        parcourirBumpMap->setGeometry(QRect(330, 300, 21, 21));
        parcourirDiffuseMap = new QPushButton(centralwidget);
        parcourirDiffuseMap->setObjectName(QString::fromUtf8("parcourirDiffuseMap"));
        parcourirDiffuseMap->setGeometry(QRect(330, 270, 21, 21));
        parcourirAnimation = new QPushButton(centralwidget);
        parcourirAnimation->setObjectName(QString::fromUtf8("parcourirAnimation"));
        parcourirAnimation->setGeometry(QRect(330, 240, 21, 21));
        parcourirModele = new QPushButton(centralwidget);
        parcourirModele->setObjectName(QString::fromUtf8("parcourirModele"));
        parcourirModele->setGeometry(QRect(330, 210, 21, 21));
        parcourirSpecularMap = new QPushButton(centralwidget);
        parcourirSpecularMap->setObjectName(QString::fromUtf8("parcourirSpecularMap"));
        parcourirSpecularMap->setGeometry(QRect(330, 330, 21, 21));
        appliquerVue = new QPushButton(centralwidget);
        appliquerVue->setObjectName(QString::fromUtf8("appliquerVue"));
        appliquerVue->setGeometry(QRect(580, 19, 71, 23));
        appliquerVue->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        OpenGLMD5ViewerClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(OpenGLMD5ViewerClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        OpenGLMD5ViewerClass->setStatusBar(statusbar);

        retranslateUi(OpenGLMD5ViewerClass);

        QMetaObject::connectSlotsByName(OpenGLMD5ViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLMD5ViewerClass)
    {
        OpenGLMD5ViewerClass->setWindowTitle(QApplication::translate("OpenGLMD5ViewerClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCharger_modele->setText(QApplication::translate("OpenGLMD5ViewerClass", "charger modele", 0, QApplication::UnicodeUTF8));
        actionCharger_animation->setText(QApplication::translate("OpenGLMD5ViewerClass", "charger animation", 0, QApplication::UnicodeUTF8));
        actionCharger_diffuse_map->setText(QApplication::translate("OpenGLMD5ViewerClass", "charger diffuse map", 0, QApplication::UnicodeUTF8));
        actionCharger_bump_map->setText(QApplication::translate("OpenGLMD5ViewerClass", "charger bump map", 0, QApplication::UnicodeUTF8));
        actionCharger_specular_map->setText(QApplication::translate("OpenGLMD5ViewerClass", "charger specular map", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("OpenGLMD5ViewerClass", "quitter", 0, QApplication::UnicodeUTF8));
        actionPlay_pause->setText(QApplication::translate("OpenGLMD5ViewerClass", "play/pause", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("OpenGLMD5ViewerClass", "stop", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Affichage :", 0, QApplication::UnicodeUTF8));
        view->clear();
        view->insertItems(0, QStringList()
         << QApplication::translate("OpenGLMD5ViewerClass", "Fil de fer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Solide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Color\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Color\303\251 et d\303\251taill\303\251", 0, QApplication::UnicodeUTF8)
        );
        showSqueleton->setText(QApplication::translate("OpenGLMD5ViewerClass", "Afficher squelette", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OpenGLMD5ViewerClass", "Mod\303\250le :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OpenGLMD5ViewerClass", "Animation :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OpenGLMD5ViewerClass", "Diffuse map :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OpenGLMD5ViewerClass", "Bump map :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("OpenGLMD5ViewerClass", "Specular map :", 0, QApplication::UnicodeUTF8));
        parcourirBumpMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirDiffuseMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirAnimation->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirModele->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirSpecularMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        appliquerVue->setText(QApplication::translate("OpenGLMD5ViewerClass", "Appliquer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGLMD5ViewerClass: public Ui_OpenGLMD5ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLMD5VIEWER_H
