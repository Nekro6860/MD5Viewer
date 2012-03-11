/*
 * RenderCanvas.h
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#ifndef RENDERCANVAS_H_
#define RENDERCANVAS_H_

#include <QGLWidget>

#include "rendering/Renderer.h"
#include "RenderCanvasAbs.h"

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
	void timeOut();

private:
    Renderer * renderer;
    bool leftMousePressed;
    QPoint leftMouseInitialPos;
    double cameraRotationSpeed;
};

} /* namespace OpenGLMD5Viewer */
#endif /* RENDERCANVAS_H_ */
