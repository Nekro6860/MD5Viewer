/*
 * RenderCanvasAbs.h
 *
 *  Created on: 11 mars 2012
 *      Author: Ikspay
 */

#ifndef RENDERCANVASABS_H_
#define RENDERCANVASABS_H_

#include <GL/glew.h>
#include <QGLWidget>

class QTimer;

class RenderCanvasAbs : public QGLWidget
{
	Q_OBJECT

public:
	RenderCanvasAbs(int framesPerSecond=60, QWidget *parent = 0);

protected:
	virtual void initializeGL() = 0;
	virtual void resizeGL( int width, int height ) = 0;
	virtual void paintGL() = 0;
	virtual void timeOut();

protected slots:
	virtual void timeOutSlot();

private:
	QTimer *t_Timer;
};

#endif /* RENDERCANVASABS_H_ */
