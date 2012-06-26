/********************************************************************************
** Form generated from reading UI file 'openglmd5viewer.ui'
**
** Created: Tue 26. Jun 14:04:32 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
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
    QLineEdit *HspecularMapLocation;
    QPushButton *parcourirBumpMap;
    QPushButton *parcourirDiffuseMapH;
    QPushButton *parcourirSpecularMap;
    QGroupBox *Animtion_groupBox;
    QLabel *loadedAnimations_label;
    QComboBox *loadedAnimations_comboBox;
    QLabel *animationSpeed_label;
    QSlider *frameRate_horizontalSlider;
    QGroupBox *browseFiles_groupBox;
    QLabel *model_label;
    QLineEdit *modelLocation;
    QPushButton *browseMd5iFiles;
    QLabel *animation_label;
    QLineEdit *animationLocation;
    QPushButton *browseAnimations;
    QGroupBox *display_groupBox;
    QComboBox *view;
    QLabel *Options_label;
    QCheckBox *showSqueleton;
    QCheckBox *useSpecMap_checkBox;
    QCheckBox *useNormalMap_checkBox;
    QStatusBar *statusbar;

    void setupUi(QWidget *OpenGLMD5ViewerClass)
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
        centralwidget->setGeometry(QRect(0, 0, 791, 591));
        glCanvasWidget = new QWidget(centralwidget);
        glCanvasWidget->setObjectName(QString::fromUtf8("glCanvasWidget"));
        glCanvasWidget->setGeometry(QRect(310, 10, 471, 571));
        QFont font1;
        font1.setPointSize(10);
        glCanvasWidget->setFont(font1);
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
        parcourirSpecularMap = new QPushButton(centralwidget);
        parcourirSpecularMap->setObjectName(QString::fromUtf8("parcourirSpecularMap"));
        parcourirSpecularMap->setGeometry(QRect(240, 550, 21, 21));
        Animtion_groupBox = new QGroupBox(centralwidget);
        Animtion_groupBox->setObjectName(QString::fromUtf8("Animtion_groupBox"));
        Animtion_groupBox->setGeometry(QRect(10, 150, 291, 91));
        loadedAnimations_label = new QLabel(Animtion_groupBox);
        loadedAnimations_label->setObjectName(QString::fromUtf8("loadedAnimations_label"));
        loadedAnimations_label->setGeometry(QRect(10, 30, 61, 16));
        loadedAnimations_comboBox = new QComboBox(Animtion_groupBox);
        loadedAnimations_comboBox->setObjectName(QString::fromUtf8("loadedAnimations_comboBox"));
        loadedAnimations_comboBox->setGeometry(QRect(70, 30, 141, 21));
        loadedAnimations_comboBox->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        animationSpeed_label = new QLabel(Animtion_groupBox);
        animationSpeed_label->setObjectName(QString::fromUtf8("animationSpeed_label"));
        animationSpeed_label->setGeometry(QRect(10, 60, 51, 16));
        frameRate_horizontalSlider = new QSlider(Animtion_groupBox);
        frameRate_horizontalSlider->setObjectName(QString::fromUtf8("frameRate_horizontalSlider"));
        frameRate_horizontalSlider->setGeometry(QRect(60, 60, 221, 21));
        frameRate_horizontalSlider->setSliderPosition(49);
        frameRate_horizontalSlider->setOrientation(Qt::Horizontal);
        browseFiles_groupBox = new QGroupBox(centralwidget);
        browseFiles_groupBox->setObjectName(QString::fromUtf8("browseFiles_groupBox"));
        browseFiles_groupBox->setGeometry(QRect(10, 10, 291, 131));
        model_label = new QLabel(browseFiles_groupBox);
        model_label->setObjectName(QString::fromUtf8("model_label"));
        model_label->setGeometry(QRect(10, 30, 61, 16));
        model_label->setFont(font1);
        model_label->setOpenExternalLinks(false);
        modelLocation = new QLineEdit(browseFiles_groupBox);
        modelLocation->setObjectName(QString::fromUtf8("modelLocation"));
        modelLocation->setGeometry(QRect(60, 30, 191, 20));
        modelLocation->setFont(font1);
        modelLocation->setReadOnly(true);
        browseMd5iFiles = new QPushButton(browseFiles_groupBox);
        browseMd5iFiles->setObjectName(QString::fromUtf8("browseMd5iFiles"));
        browseMd5iFiles->setGeometry(QRect(260, 30, 21, 21));
        animation_label = new QLabel(browseFiles_groupBox);
        animation_label->setObjectName(QString::fromUtf8("animation_label"));
        animation_label->setGeometry(QRect(10, 60, 71, 16));
        animation_label->setFont(font1);
        animation_label->setOpenExternalLinks(false);
        animationLocation = new QLineEdit(browseFiles_groupBox);
        animationLocation->setObjectName(QString::fromUtf8("animationLocation"));
        animationLocation->setGeometry(QRect(80, 60, 171, 20));
        animationLocation->setFont(font1);
        animationLocation->setReadOnly(true);
        browseAnimations = new QPushButton(browseFiles_groupBox);
        browseAnimations->setObjectName(QString::fromUtf8("browseAnimations"));
        browseAnimations->setGeometry(QRect(260, 60, 21, 21));
        display_groupBox = new QGroupBox(centralwidget);
        display_groupBox->setObjectName(QString::fromUtf8("display_groupBox"));
        display_groupBox->setGeometry(QRect(10, 250, 201, 161));
        view = new QComboBox(display_groupBox);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(10, 30, 87, 22));
        view->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        view->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        Options_label = new QLabel(display_groupBox);
        Options_label->setObjectName(QString::fromUtf8("Options_label"));
        Options_label->setGeometry(QRect(10, 60, 81, 16));
        showSqueleton = new QCheckBox(display_groupBox);
        showSqueleton->setObjectName(QString::fromUtf8("showSqueleton"));
        showSqueleton->setGeometry(QRect(10, 80, 121, 23));
        showSqueleton->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        useSpecMap_checkBox = new QCheckBox(display_groupBox);
        useSpecMap_checkBox->setObjectName(QString::fromUtf8("useSpecMap_checkBox"));
        useSpecMap_checkBox->setGeometry(QRect(10, 120, 131, 17));
        useSpecMap_checkBox->setFont(font1);
        useNormalMap_checkBox = new QCheckBox(display_groupBox);
        useNormalMap_checkBox->setObjectName(QString::fromUtf8("useNormalMap_checkBox"));
        useNormalMap_checkBox->setGeometry(QRect(10, 140, 161, 17));
        useNormalMap_checkBox->setFont(font1);
        statusbar = new QStatusBar(OpenGLMD5ViewerClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 24));

        retranslateUi(OpenGLMD5ViewerClass);

        QMetaObject::connectSlotsByName(OpenGLMD5ViewerClass);
    } // setupUi

    void retranslateUi(QWidget *OpenGLMD5ViewerClass)
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
        parcourirBumpMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirDiffuseMapH->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        parcourirSpecularMap->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        Animtion_groupBox->setTitle(QApplication::translate("OpenGLMD5ViewerClass", "Animation", 0, QApplication::UnicodeUTF8));
        loadedAnimations_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Selected :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        loadedAnimations_comboBox->clear();
        loadedAnimations_comboBox->insertItems(0, QStringList()
         << QApplication::translate("OpenGLMD5ViewerClass", "None", 0, QApplication::UnicodeUTF8)
        );
        animationSpeed_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Speed :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        browseFiles_groupBox->setTitle(QApplication::translate("OpenGLMD5ViewerClass", "Browse files", 0, QApplication::UnicodeUTF8));
        model_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Model :", 0, QApplication::UnicodeUTF8));
        browseMd5iFiles->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        animation_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Animation :", 0, QApplication::UnicodeUTF8));
        browseAnimations->setText(QApplication::translate("OpenGLMD5ViewerClass", "...", 0, QApplication::UnicodeUTF8));
        display_groupBox->setTitle(QApplication::translate("OpenGLMD5ViewerClass", "Display", 0, QApplication::UnicodeUTF8));
        view->clear();
        view->insertItems(0, QStringList()
         << QApplication::translate("OpenGLMD5ViewerClass", "Wireframe", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Solid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Textured", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenGLMD5ViewerClass", "Lighted", 0, QApplication::UnicodeUTF8)
        );
        Options_label->setText(QApplication::translate("OpenGLMD5ViewerClass", "Options :", 0, QApplication::UnicodeUTF8));
        showSqueleton->setText(QApplication::translate("OpenGLMD5ViewerClass", "display skeleton", 0, QApplication::UnicodeUTF8));
        useSpecMap_checkBox->setText(QApplication::translate("OpenGLMD5ViewerClass", "use specular map", 0, QApplication::UnicodeUTF8));
        useNormalMap_checkBox->setText(QApplication::translate("OpenGLMD5ViewerClass", "use normal map", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGLMD5ViewerClass: public Ui_OpenGLMD5ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLMD5VIEWER_H
