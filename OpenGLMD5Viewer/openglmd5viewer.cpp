#include "openglmd5viewer.h"
#include <QtGui>
#include <iostream>
namespace OpenGLMD5Viewer{

OpenGLMD5Viewer::OpenGLMD5Viewer(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	displayer = new RenderCanvas(50, ui.glCanvasWidget);
	displayer->resize(ui.glCanvasWidget->width(), ui.glCanvasWidget->height());
	cheminModele = "";
	cheminAnimation = "";
	cheminBumpMap = "";
	cheminDiffuseMap = "";
	cheminSpecularMap = "";
	showSqueleton = false;
	currentView = new QLabel("");
	connect(ui.parcourirModele, SIGNAL(clicked()), this, SLOT(parcourirModele()));
	connect(ui.parcourirAnimation, SIGNAL(clicked()), this, SLOT(parcourirAnimation()));
	connect(ui.parcourirBumpMap, SIGNAL(clicked()), this, SLOT(parcourirBumpMap()));
	connect(ui.parcourirDiffuseMap, SIGNAL(clicked()), this, SLOT(parcourirDiffuseMap()));
	connect(ui.parcourirSpecularMap, SIGNAL(clicked()), this, SLOT(parcourirSpecularMap()));
	connect(ui.showSqueleton, SIGNAL(clicked()), this, SLOT(showHideSqueleton()));
	connect(ui.appliquerVue, SIGNAL(clicked()), this, SLOT(appliquerVue()));

	//	connect(ui.playPause, SIGNAL(clicked()), this, SLOT(playPause()));
	//	connect(ui.stop, SIGNAL(clicked()), this, SLOT(stop()));

}

OpenGLMD5Viewer::~OpenGLMD5Viewer()
{

}

void OpenGLMD5Viewer::setDiplayer(RenderCanvas *d)
{
	displayer = d;
}

RenderCanvas * OpenGLMD5Viewer::getDisplayer()
{
	return displayer;
}

void OpenGLMD5Viewer::parcourirModele()
{
	cheminModele = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
	ui.modelLocation->setText(cheminModele);
}

void OpenGLMD5Viewer::parcourirAnimation()
{
	cheminAnimation = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
	ui.animationLocation->setText(cheminAnimation);
}

void OpenGLMD5Viewer::parcourirBumpMap()
{
	cheminBumpMap = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
	ui.bumpMapLocation->setText(cheminBumpMap);
}

void OpenGLMD5Viewer::parcourirDiffuseMap()
{
	cheminDiffuseMap = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
	ui.diffuseMapLocation->setText(cheminDiffuseMap);
}

void OpenGLMD5Viewer::parcourirSpecularMap()
{
	cheminSpecularMap = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
	ui.specularMapLocation->setText(cheminSpecularMap);
}

QString OpenGLMD5Viewer::getCheminModele(){
	return cheminModele;
}

QString OpenGLMD5Viewer::getCheminDiffuseMap(){
	return cheminDiffuseMap;
}

QString OpenGLMD5Viewer::getCheminSpecularMap(){
	return cheminSpecularMap;
}

QString OpenGLMD5Viewer::getCheminAnimation(){
	return cheminAnimation;
}

QString OpenGLMD5Viewer::getCheminBumpMap(){
	return cheminBumpMap;
}

QString OpenGLMD5Viewer::getSelectedView(){
	return currentView->text();
}

void OpenGLMD5Viewer::showHideSqueleton(){
	showSqueleton = !showSqueleton;
	std::cout << ui.view->currentText().toStdString();
	if(showSqueleton){
		// TODO cas où on doit afficher le squelette
	}
	else{
		// TODO cas où on ne doit pas afficher le squelette
	}
}

void OpenGLMD5Viewer::appliquerVue(){
	if(ui.view->currentIndex() == 0){
		// TODO affichage fil de fer
	}
	else if(ui.view->currentIndex() == 1){
		// TODO affichage solide
	}
	else if(ui.view->currentIndex() == 2){
		// TODO affichage coloré
	}
	else if(ui.view->currentIndex() == 3){
		// TODO affichage coloré et détaillé
	}
}

//void OpenGLMD5Viewer::stop()
//{
//
//}

} // namespace OpenGLMD5Viewer{
