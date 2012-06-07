#ifndef OPENGLMD5VIEWER_H
#define OPENGLMD5VIEWER_H

#include <QtGui/QMainWindow>
#include "ui_openglmd5viewer.h"

#include "src/RenderCanvas.h"
#include "src/core/MD5/Md5Object.h"

namespace OpenGLMD5Viewer{

class OpenGLMD5Viewer : public QMainWindow
{
    Q_OBJECT

public:
    OpenGLMD5Viewer(QWidget *parent = 0);
    ~OpenGLMD5Viewer();

    RenderCanvas * getDisplayer();
    void setDiplayer(RenderCanvas * d);
    QString getCheminModele();
    QString getCheminAnimation();
    QString getSelectedView();

    Md5Object * _md5Object;

protected slots:
//	virtual void stop();
	virtual void parcourirModele();
	virtual void parcourirAnimation();
	virtual void showHideSqueleton();
	virtual void appliquerVue();
	virtual void useSpecularMap();
	virtual void useNormalMap();

private:
    Ui::OpenGLMD5ViewerClass ui;
    RenderCanvas *displayer;
    QString md5iFilePath;
	QString cheminAnimation;
	QLabel * currentView;
	bool showSqueleton;
};

} // namespace OpenGLMD5Viewer

#endif // OPENGLMD5VIEWER_H
