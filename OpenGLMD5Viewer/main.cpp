#include "openglmd5viewer.h"

#include <QtGui>
#include <QApplication>
#include <iostream>

#include "src/rendering/TestCubeRenderer.h"
#include "src/rendering/Md5SolidRenderer.h"
#include "src/rendering/Md5WireframeRenderer.h"
#include "src/rendering/Renderer.h"

//#include "src/core/MD5/Md5Model.h"
#include "src/core/MD5/Md5Object.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLMD5Viewer::OpenGLMD5Viewer w;

//    OpenGLMD5Viewer::TestCubeRenderer * testRenderer = new OpenGLMD5Viewer::TestCubeRenderer();
    OpenGLMD5Viewer::Md5WireframeRenderer * testRenderer = new OpenGLMD5Viewer::Md5WireframeRenderer();
//    OpenGLMD5Viewer::Md5SolidRenderer * testRenderer = new OpenGLMD5Viewer::Md5SolidRenderer();
    w.getDisplayer()->setRenderer(testRenderer);

    w.show();


    return a.exec();
}
