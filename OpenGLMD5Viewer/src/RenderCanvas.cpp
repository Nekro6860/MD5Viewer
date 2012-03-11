/*
 * RenderCanvas.cpp
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <QtOpenGL>

#include "RenderCanvas.h"

namespace OpenGLMD5Viewer {

RenderCanvas::RenderCanvas(int framesPerSecond, QWidget *parent) : RenderCanvasAbs(60, parent)
{
	    leftMousePressed = false; // Au départ, l'utilisateur ne clique pas
	    rightMousePressed = false;
	    rotationSpeed = 0.005;
}

RenderCanvas::~RenderCanvas() {
	// TODO Auto-generated destructor stub
}

Renderer * RenderCanvas::getRenderer()
{
	return renderer;
}

void RenderCanvas::setRenderer(Renderer * r)
{
	renderer = r;
}

void RenderCanvas::initializeGL() {
	renderer->init();
}

void RenderCanvas::paintGL() {
	renderer->draw();
}

void RenderCanvas::resizeGL(int width, int height) {
	if (height == 0) height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderCanvas::timeOut()
{
	renderer->timeOut();
	updateGL();
}

void RenderCanvas::setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ) {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(camX, camY, camZ, targetX, targetY, targetZ, 0, 1, 0);
}

// Quand l'utilisateur clique
void RenderCanvas::mousePressEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton )
    {
    	leftMousePressed = TRUE;
    	leftMouseInitialPos = e->pos();
    }else if ( e->button() == Qt::RightButton )
    {
    	rightMousePressed = TRUE;
    	rightMouseInitialPos = e->pos();
    }else{
        return;
    }
}

void RenderCanvas::mouseMoveEvent( QMouseEvent *e )
{
    if ( leftMousePressed )
    {
    	QPoint pnt = e->pos();
    	int diffx = pnt.x() - leftMouseInitialPos.x();
    	float anglex = 3.14*rotationSpeed*diffx;

    	int diffy = pnt.y() - leftMouseInitialPos.y();
    	float angley = 3.14*rotationSpeed*diffy;

    	renderer->camera->updatePosition(anglex, angley);
    	leftMouseInitialPos = pnt;
    }else if ( rightMousePressed )
    {
    	QPoint pnt = e->pos();
		int diffx = pnt.x() - rightMouseInitialPos.x();
		float anglex = 3.14*rotationSpeed*diffx;

		renderer->light->updatePosition(anglex);
		rightMouseInitialPos = pnt;
    }else{
        return;
    }
}

void RenderCanvas::mouseReleaseEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton )
        leftMousePressed = FALSE;
    else if ( e->button() == Qt::RightButton )
    	rightMousePressed = FALSE;
}

void RenderCanvas::wheelEvent( QWheelEvent *e )
{
	if (e->delta() > 0)
		renderer->camera->zoomIn();
	else if (e->delta() < 0)
		renderer->camera->zoomOut();
}

} /* namespace OpenGLMD5Viewer */
