#include "openglmd5viewer.h"

namespace OpenGLMD5Viewer{

OpenGLMD5Viewer::OpenGLMD5Viewer(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
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

} // namespace OpenGLMD5Viewer{
