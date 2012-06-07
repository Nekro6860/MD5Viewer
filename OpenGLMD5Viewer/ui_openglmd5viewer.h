/********************************************************************************
** Form generated from reading UI file 'openglmd5viewer.ui'
**
** Created: Thu 7. Jun 21:45:16 2012
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
    QLabel *display_label;
    QComboBox *view;
    QCheckBox *showSqueleton;
    QLabel *model_label;
    QLabel *animation_label;
    QLineEdit *modelLocation;
    QLineEdit *animationLocation;
    QLineEdit *HspecularMapLocation;
    QPushButton *parcourirBumpMap;
    QPushButton *parcourirDiffuseMapH;
    QPushButton *parcourirAnimation;
    QPushButton *parcourirModele;
    QPushButton *parcourirSpecularMap;
    QPushButton *appliquerVue;
    QLabel *Options_label;
    QCheckBox *useSpecMap_checkBox;
    QCheckBox *useNormalMap_checkBox;
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
        glCanvasWidget->setGeometry(QRect(310, 10, 471, 571));
        QFont font1;
        font1.setPointSize(10);
        glCanvasWidget->setFont(font1);
        display_label = new QLabel(centralwidget);
        display_label->setObjectName(QString::fromUtf8("display_label"));
        display_label->setGeometry(QRect(10, 180, 71, 16));
        display_label->setFont(font1);
        display_label->setOpenExternalLinks(false);
        view = new QComboBox(centralwidget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(80, 180, 141, 21));
        view->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        showSqueleton = new QCheckBox(centralwidget);
        showSqueleton->setObjectName(QString::fromUtf8("showSqueleton"));
        showSqueleton->setGeometry(QRect(10, 340, 121, 23));
        showSqueleton->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        model_label = new QLabel(centralwidget);
        model_label->setObjectName(QString::fromUtf8("model_label"));
        model_label->setGeometry(QRect(10, 60, 61, 16));
        model_label->setFont(font1);
        model_label->setOpenExternalLinks(false);
        animation_label = new QLabel(centralwidget);
        animation_label->setObjectName(QString::fromUtf8("animation_label"));
        animation_label->setGeometry(QRect(10, 100, 71, 16));
        animation_label->setFont(font1);
        animation_label->setOpenExternalLinks(false);
        modelLocation = new QLineEdit(centralwidget);
        modelLocation->setObjectName(QString::fromUtf8("modelLocation"));
        modelLocation->setGeometry(QRect(80, 60, 181, 20));
        modelLocation->setFont(font1);
        modelLocation->setReadOnly(true);
        animationLocation = new QLineEdit(centralwidget);
        animationLocation->setObjectName(QString::fromUtf8("animationLocation"));
        animationLocation->setGeometry(QRect(80, 100, 181, 20));
        animationLocation->setFont(font1);
        animationLocation->setReadOnly(true);
        HspecularMapLocation = new QLineEdit(centralwidget);
        HspecularMapLocation->setObjectName(QString::fromUtf8("HspecularMapLocation"));
        HspecularMapLocation->setGeometry(QRect(10, 540, 201, 20));
        HspecularMapLocation->setFont(font1);
        HspecularMapLocation->setReadOnly(true);
        parcourirBumpMap = new QPushButton(centralwidget);
        parcourirBumpMap->setObjectName(QString::fromUtf8("parcourirBumpMap"));
        parcourirBumpMap->setGeometry(QRect(240, 520, 21, 21));
        parcourirDiffuseMapH = new QPushButton(centralwidget);
        parcourirDiffuseMapH->setObjectName(QString::fromUtf8("parcourirDiffuseMapH"));
        parcourirDiffuseMapH->setGeometry(QRect(240, 490, 21, 21));
        parcourirAnimation = new QPushButton(centralwidget);
        parcourirAnimation->setObjectName(QString::fromUtf8("parcourirAnimation"));
        parcourirAnimation->setGeometry(QRect(270, 100, 21, 21));
        parcourirModele = new QPushButton(centralwidget);
        parcourirModele->setObjectName(QString::fromUtf8("parcourirModele"));
        parcourirModele->setGeometry(QRect(270, 60, 21, 21));
        parcourirSpecularMap = new QPushButton(centralwidget);
        parcourirSpecularMap->setObjectName(QString::fromUtf8("parcourirSpecularMap"));
        parcourirSpecularMap->setGeometry(QRect(240, 550, 21, 21));
        appliquerVue = new QPushButton(centralwidget);
        appliquerVue->setObjectName(QString::fromUtf8("appliquerVue"));
        appliquerVue->setGeometry(QRect(230, 180, 71, 23));
        appliquerVue->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        Options_label = new QLabel(centralwidget);
        Options_label->setObjectName(QString::fromUtf8("Options_label"));
        Options_label->setGeometry(QRect(10, 320, 81, 16));
        useSpecMap_checkBox = new QCheckBox(centralwidget);
        useSpecMap_checkBox->setObjectName(QString::fromUtf8("useSpecMap_checkBox"));
        useSpecMap_checkBox->setGeometry(QRect(10, 380, 131, 17));
        useSpecMap_checkBox->setFont(font1);
        useNormalMap_checkBox = new QCheckBox(centralwidget);
        useNormalMap_checkBox->setObjectName(QString::fromUtf8("useNormalMap_checkBox"));
        useNormalMap_checkBox->setGeometry(QRect(10, 400, 161, 17));
        useNormalMap_checkBox->setFont(font1);
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
        display_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Display :", 0, QApplication::UnicodeUTF8));
        view->clear();
        view->insertItems(0, QStringList()
         << QApplication::translate("OpenGLMD5ViewerClass", "Fil de fer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Solide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Color\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Color\303\251 et d\303\251taill\303\251", 0, QApplication::UnicodeUTF8)
        );
        showSqueleton->setText(QApplication::translate("OpenGLMD5ViewerClass", "display skeleton", 0, QApplication::UnicodeUTF8));
        model_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Model :", 0, QApplication::UnicodeUTF8));
        animation_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Animation :", 0, QApplication::UnicodeUTF8));
        parcourirBumpMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirDiffuseMapH->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirAnimation->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirModele->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirSpecularMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        appliquerVue->setText(QApplication::translate("OpenGLMD5ViewerClass", "Appliquer", 0, QApplication::UnicodeUTF8));
        Options_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Options :", 0, QApplication::UnicodeUTF8));
        useSpecMap_checkBox->setText(QApplication::translate("OpenGLMD5ViewerClass", "use specular map", 0, QApplication::UnicodeUTF8));
        useNormalMap_checkBox->setText(QApplication::translate("OpenGLMD5ViewerClass", "use normal map", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGLMD5ViewerClass: public Ui_OpenGLMD5ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLMD5VIEWER_H
