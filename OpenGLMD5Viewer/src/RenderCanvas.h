/*
 * RenderCanvas.h
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#ifndef RENDERCANVAS_H_
#define RENDERCANVAS_H_

#include <QGLWidget>

namespace OpenGLMD5Viewer {

class RenderCanvas : public QGLWidget{

public:
	RenderCanvas(int framesPerSecond, QWidget *parent = 0);
	virtual ~RenderCanvas();

	void setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ);

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

public slots:
    virtual void timeOutSlot();

private:
    QTimer *t_Timer;
};

} /* namespace OpenGLMD5Viewer */
#endif /* RENDERCANVAS_H_ */
