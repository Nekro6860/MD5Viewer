#include "openglmd5viewer.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLMD5Viewer::OpenGLMD5Viewer w;
    w.show();
    return a.exec();
}
