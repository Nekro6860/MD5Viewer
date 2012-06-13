#include "openglmd5viewer.h"

#include <QtGui>
#include <QApplication>
#include <iostream>

#include "src/rendering/Md5SolidRenderer.h"
#include "src/rendering/Md5WireframeRenderer.h"
#include "src/rendering/Renderer.h"

//#include "src/core/MD5/Md5Model.h"
#include "src/core/MD5/Md5Object.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLMD5Viewer::OpenGLMD5Viewer w;

    OpenGLMD5Viewer::Md5WireframeRenderer * initializationRenderer = new OpenGLMD5Viewer::Md5WireframeRenderer();
    w.getDisplayer()->setRenderer(initializationRenderer);

    w.show();


    return a.exec();
}
