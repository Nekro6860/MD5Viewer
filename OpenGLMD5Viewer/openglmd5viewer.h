#ifndef OPENGLMD5VIEWER_H
#define OPENGLMD5VIEWER_H

#include <QtGui/QMainWindow>
#include "ui_openglmd5viewer.h"

#include "src/RenderCanvas.h"

namespace OpenGLMD5Viewer{

class OpenGLMD5Viewer : public QMainWindow
{
    Q_OBJECT

public:
    OpenGLMD5Viewer(QWidget *parent = 0);
    ~OpenGLMD5Viewer();

    RenderCanvas * getDisplayer();
    void setDiplayer(RenderCanvas * d);

private:
    Ui::OpenGLMD5ViewerClass ui;
    RenderCanvas *displayer;
};

} // namespace OpenGLMD5Viewer

#endif // OPENGLMD5VIEWER_H
