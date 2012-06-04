/*
 * RenderCanvas.h
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#ifndef RENDERCANVAS_H_
#define RENDERCANVAS_H_


#include "RenderCanvasAbs.h"
#include "rendering/Renderer.h"


#include <GL/glew.h>
#include <QGLWidget>

namespace OpenGLMD5Viewer {

class RenderCanvas : public RenderCanvasAbs {
public:
	RenderCanvas(int framesPerSecond=60, QWidget *parent = 0);
	virtual ~RenderCanvas();

	void setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ);

	Renderer * getRenderer();
	void setRenderer(Renderer * r);

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mousePressEvent( QMouseEvent * );
	void mouseMoveEvent( QMouseEvent * );
	void mouseReleaseEvent( QMouseEvent * );
	void wheelEvent ( QWheelEvent * );
	void timeOut();

private:
    Renderer * renderer;
    bool leftMousePressed;
    QPoint leftMouseInitialPos;
    bool rightMousePressed;
	QPoint rightMouseInitialPos;
	bool middleMousePressed;
	QPoint middleMouseInitialPos;
    double rotationSpeed;

};

} /* namespace OpenGLMD5Viewer */
#endif /* RENDERCANVAS_H_ */
