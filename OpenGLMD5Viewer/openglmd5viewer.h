#ifndef OPENGLMD5VIEWER_H
#define OPENGLMD5VIEWER_H

#include <QtGui/QMainWindow>
#include "ui_openglmd5viewer.h"

#include "src/RenderCanvas.h"
#include "src/core/MD5/Md5Object.h"

namespace OpenGLMD5Viewer{

class OpenGLMD5Viewer : public QWidget
{
    Q_OBJECT

public:
    OpenGLMD5Viewer(QWidget *parent = 0);
    ~OpenGLMD5Viewer();

    RenderCanvas * getDisplayer();
    void setDiplayer(RenderCanvas * d);
    QString getMd5iFilePath();
    QString getAnimationPath();
    QString getSelectedView();

    Md5Object * _md5Object;

protected slots:
//	virtual void stop();
	virtual void browseMd5iFiles();
	virtual void browseAnimations();
	virtual void showHideSqueleton();
	virtual void appliquerVue(int);
	virtual void changeAnimation(QString);
	virtual void useSpecularMap();
	virtual void useNormalMap();
	virtual void changeFrameRate();

private:
    Ui::OpenGLMD5ViewerClass ui;
    RenderCanvas *displayer;
    QString md5iFilePath;
	QString animationPath;
	QLabel * currentView;
	bool showSqueleton;
};

} // namespace OpenGLMD5Viewer

#endif // OPENGLMD5VIEWER_H
