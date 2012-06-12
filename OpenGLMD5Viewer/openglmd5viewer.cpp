#include "openglmd5viewer.h"
#include <QtGui>
#include <iostream>
#include "src/rendering/Md5SolidRenderer.h"
#include "src/rendering/Md5WireframeRenderer.h"
#include "src/rendering/Md5TexturedRenderer.h"
#include "src/core/MD5/Md5iReader.h"


namespace OpenGLMD5Viewer{

OpenGLMD5Viewer::OpenGLMD5Viewer(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	displayer = new RenderCanvas(50, ui.glCanvasWidget);
	displayer->resize(ui.glCanvasWidget->width(), ui.glCanvasWidget->height());
	md5iFilePath = "";
	animationPath = "";
	showSqueleton = false;
	currentView = new QLabel("");
	connect(ui.browseMd5iFiles, SIGNAL(clicked()), this, SLOT(browseMd5iFiles()));
	connect(ui.browseAnimations, SIGNAL(clicked()), this, SLOT(browseAnimations()));
	connect(ui.showSqueleton, SIGNAL(clicked()), this, SLOT(showHideSqueleton()));
	connect(ui.view, SIGNAL(currentIndexChanged(int)), this, SLOT(appliquerVue(int)));
	connect(ui.loadedAnimations_comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeAnimation(QString)));
	connect(ui.useSpecMap_checkBox, SIGNAL(clicked()), this, SLOT(useSpecularMap()));
	connect(ui.useNormalMap_checkBox, SIGNAL(clicked()), this, SLOT(useNormalMap()));
	connect(ui.frameRate_horizontalSlider, SIGNAL(sliderReleased ()), this, SLOT(changeFrameRate()));

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

void OpenGLMD5Viewer::browseMd5iFiles()
{
	md5iFilePath = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.md5i)"));
	if(md5iFilePath != NULL)
	{
		Md5Model *model;
		Md5Object *object;

		// Load mesh model
		model = new Md5Model();
		model = Md5iReader::loadFromMd5i(md5iFilePath.toStdString());
//		model->loadModel(md5FilePath.toStdString());
		if(model) {
		object = new Md5Object();

		// Attach the model to object
		object->setMd5Model( model );
		object->setAnim( "NULL" );

		/////
		Md5WireframeRenderer * renderer = new Md5WireframeRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(object);

		_md5Object = object;

		ui.modelLocation->setText(md5iFilePath);
		ui.view->setCurrentIndex(0);
		}

	}
}

void OpenGLMD5Viewer::browseAnimations()
{
	animationPath = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.md5anim)"));
	ui.animationLocation->setText(animationPath);

	if(animationPath != NULL)
	{
		Md5Object * tempTarget = displayer->getRenderer()->getTarget();
		if(tempTarget)
		{
			if(tempTarget->getModelPtr()->addAnim(animationPath.toStdString()))
			{
				string addedAnimName = tempTarget->getModelPtr()->getLastAddedAnim()->getName();
				ui.loadedAnimations_comboBox->addItem(QString(addedAnimName.c_str()));
			}
		}
	}
}

QString OpenGLMD5Viewer::getMd5iFilePath(){
	return md5iFilePath;
}

QString OpenGLMD5Viewer::getAnimationPath(){
	return animationPath;
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

void OpenGLMD5Viewer::appliquerVue(int index){
	if(ui.view->currentIndex() == 0){
//	if(index == 0){
		Md5WireframeRenderer * renderer = new Md5WireframeRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(_md5Object);
		displayer->getRenderer()->displayType = 0;
	}
	else if(ui.view->currentIndex() == 1){
//		if(index == 1){
		Md5SolidRenderer * renderer = new Md5SolidRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(_md5Object);
		displayer->getRenderer()->displayType = 1;
	}
	else if(ui.view->currentIndex() == 2){
//		if(index == 2){
		Md5TexturedRenderer * renderer = new Md5TexturedRenderer();
		renderer->init();
		displayer->setRenderer(renderer);
		renderer->setTarget(_md5Object);
		displayer->getRenderer()->displayType = 2;
	}
	else if(ui.view->currentIndex() == 3){
//		if(index == 3){
		displayer->getRenderer()->displayType = 3;
	}
}

void OpenGLMD5Viewer::changeAnimation(QString name)
{
	displayer->getRenderer()->getTarget()->setAnim(name.toStdString());
}

void OpenGLMD5Viewer::useSpecularMap()
{
	this->displayer->getRenderer()->setUseSpecularMap(ui.useSpecMap_checkBox->isChecked());
}

void OpenGLMD5Viewer::useNormalMap()
{
	this->displayer->getRenderer()->setUseNormalMap(ui.useNormalMap_checkBox->isChecked());
}

void OpenGLMD5Viewer::changeFrameRate()
{
	int sliderValue = ui.frameRate_horizontalSlider->value();
	Md5Animation * currentAnim = displayer->getRenderer()->getTarget()->getCurrAnim();
	if(currentAnim)
	{
		currentAnim->setFrameRate(2*sliderValue);
		std::cout << "sliderValue : " << sliderValue << std::endl;
		std::cout << "frameRate : " << currentAnim->getFrameRate() << std::endl;
	}
}

//void OpenGLMD5Viewer::stop()
//{
//
//}

} // namespace OpenGLMD5Viewer{
