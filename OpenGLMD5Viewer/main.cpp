#include "openglmd5viewer.h"

#include <QtGui>
#include <QApplication>
#include <iostream>

#include "src/rendering/TestCubeRenderer.h"
#include "src/rendering/Renderer.h"

//#include "src/core/MD5/Md5Model.h"
#include "src/core/MD5/Md5Object.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLMD5Viewer::OpenGLMD5Viewer w;

    OpenGLMD5Viewer::Renderer * testRenderer = new OpenGLMD5Viewer::TestCubeRenderer();
    w.getDisplayer()->setRenderer(testRenderer);


    // Zone de test du core

    string meshFile = "player.md5mesh";
    OpenGLMD5Viewer::Md5Model *model = new OpenGLMD5Viewer::Md5Model;
    OpenGLMD5Viewer::Md5Object *object;

	// Load mesh model
	if( model->loadModel( meshFile ) ) {
		object = new OpenGLMD5Viewer::Md5Object;

	  // Attach the model to object
	  object->setMd5Model( model );
	  object->setAnim( "NULL" );
	}

	model->printfMeshNames();
//	model->getMeshByName("origin")->printTriangles();

    // Fin de zone de test du core

    w.show();


    return a.exec();
}
