#include "openglmd5viewer.h"

#include <QtGui>
#include <QApplication>
#include <iostream>

#include "src/rendering/TestCubeRenderer.h"
#include "src/rendering/Renderer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLMD5Viewer::OpenGLMD5Viewer w;

    OpenGLMD5Viewer::Renderer * testRenderer = new OpenGLMD5Viewer::TestCubeRenderer();
    w.getDisplayer()->setRenderer(testRenderer);

    w.show();


    return a.exec();
}
