/*
 * RenderCanvas.cpp
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <QtOpenGL>
#include <iostream>
using namespace std;

#include "RenderCanvas.h"

namespace OpenGLMD5Viewer {

RenderCanvas::RenderCanvas(int framesPerSecond, QWidget *parent) :
		QGLWidget(QGLFormat(QGL::SampleBuffers), parent) {

		int timerInterval = 0;
	    if(framesPerSecond == 0) {
	    	timerInterval = 1000 / 60;
	    }
	    else
	    {
	    	timerInterval = 1000 / framesPerSecond;
	    }
	    t_Timer = new QTimer(this);
	    connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
	    t_Timer->start(timerInterval);

	    leftMousePressed = false; // Au départ, l'utilisateur ne clique pas
	    cameraRotationSpeed = 0.005;
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

void RenderCanvas::timeOutSlot()
{
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
    }else{
        return;
    }
}

void RenderCanvas::mouseMoveEvent( QMouseEvent *e )
{
    if ( leftMousePressed )
    {
    	QPoint pnt = e->pos();
//    	cout << pnt.x() << " ; " << pnt.y() << "\n";
    	int diffx = pnt.x() - leftMouseInitialPos.x();
    	float anglex = 3.14*cameraRotationSpeed*diffx;

    	int diffy = pnt.y() - leftMouseInitialPos.y();
    	float angley = 3.14*cameraRotationSpeed*diffy;

    	renderer->camera->updatePosition(anglex, angley);
    }else{
        return;
    }
}

void RenderCanvas::mouseReleaseEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton )
        leftMousePressed = FALSE;
}

} /* namespace OpenGLMD5Viewer */
