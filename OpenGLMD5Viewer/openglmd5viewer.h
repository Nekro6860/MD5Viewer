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
    QString getCheminModele();
    QString getCheminAnimation();
    QString getCheminDiffuseMap();
    QString getCheminSpecularMap();
    QString getCheminBumpMap();
    QString getSelectedView();

protected slots:
//	virtual void stop();
	virtual void parcourirModele();
	virtual void parcourirAnimation();
	virtual void parcourirBumpMap();
	virtual void parcourirDiffuseMap();
	virtual void parcourirSpecularMap();
	virtual void showHideSqueleton();
	virtual void appliquerVue();

private:
    Ui::OpenGLMD5ViewerClass ui;
    RenderCanvas *displayer;
    QString cheminModele;
	QString cheminAnimation;
	QString cheminBumpMap;
	QString cheminDiffuseMap;
	QString cheminSpecularMap;
	QLabel * currentView;
	bool showSqueleton;
};

} // namespace OpenGLMD5Viewer

#endif // OPENGLMD5VIEWER_H
