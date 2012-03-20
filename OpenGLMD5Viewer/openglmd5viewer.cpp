#include "openglmd5viewer.h"
#include <QtGui>
#include <iostream>
#include "src/rendering/Md5SolidRenderer.h"
#include "src/rendering/Md5WireframeRenderer.h"
#include "src/rendering/Md5TexturedRenderer.h"


namespace OpenGLMD5Viewer{

OpenGLMD5Viewer::OpenGLMD5Viewer(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	displayer = new RenderCanvas(50, ui.glCanvasWidget);
//	displayer->getRenderer()->skeletonDisplay = false;
//	displayer->getRenderer()->displayType = 0;
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
	if(cheminModele != NULL)
	{
		Md5Model *model = new Md5Model();
		Md5Object *object;

		// Load mesh model
		if( model->loadModel( cheminModele.toStdString() ) ) {
			object = new Md5Object();

		  // Attach the model to object
		  object->setMd5Model( model );
		  object->setAnim( "NULL" );
		}

		Md5WireframeRenderer * renderer = new Md5WireframeRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(object);

		_md5Object = object;

		ui.modelLocation->setText(cheminModele);
	}
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

	Md5Model *model = new Md5Model();

	Md5WireframeRenderer * renderer = new Md5WireframeRenderer();
	renderer->init();
	renderer->setIdTexture(renderer->loadTexture(cheminDiffuseMap));
//	renderer->setIdTexture(renderer->loadTexture(L"\models\fatGuy\textures\fatty_d.tga"));
	displayer->setRenderer(renderer);
	renderer->setTarget(_md5Object);

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
	if(showSqueleton){
		displayer->getRenderer()->skeletonDisplay = true;
	}
	else{
		displayer->getRenderer()->skeletonDisplay = false;
	}
}

void OpenGLMD5Viewer::appliquerVue(){
	if(ui.view->currentIndex() == 0){
		Md5WireframeRenderer * renderer = new Md5WireframeRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(_md5Object);
		displayer->getRenderer()->displayType = 0;
	}
	else if(ui.view->currentIndex() == 1){
		Md5SolidRenderer * renderer = new Md5SolidRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(_md5Object);
		displayer->getRenderer()->displayType = 1;
	}
	else if(ui.view->currentIndex() == 2){
		Md5TexturedRenderer * renderer = new Md5TexturedRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(_md5Object);
		displayer->getRenderer()->displayType = 2;
	}
	else if(ui.view->currentIndex() == 3){
		displayer->getRenderer()->displayType = 3;
	}
}

//void OpenGLMD5Viewer::stop()
//{
//
//}

} // namespace OpenGLMD5Viewer{
