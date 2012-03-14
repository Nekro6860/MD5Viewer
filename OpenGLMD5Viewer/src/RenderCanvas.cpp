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
}

RenderCanvas::~RenderCanvas() {
	// TODO Auto-generated destructor stub
}

void RenderCanvas::initializeGL() {
	glMatrixMode(GL_PROJECTION);
		gluPerspective(90, (double) 200 / 200, 1, 650);

		/* init OpenGL */
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);

		/* init OpenGL light */
		GLfloat lightpos[] = { -10.0f, 2.0f, -40.0f, 0.0f };
		GLfloat diffuse_color[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat specular_color[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat ambiant_color[] = { 0.3, 0.3, 0.3, 1.0 };
		//GLfloat ambiant_color[] = { 1.0, 0.8, 0.0, 1.0 };
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambiant_color);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color);

		// initialisations relatives aux textures
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RenderCanvas::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		setCamera(1, 1, -10, 0, 0, 0);

		glMatrixMode(GL_MODELVIEW);

		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();

		glTranslatef(4.0f, 0.0f, -1.0f);

		glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3d(1.0f, 1.0f, 0.0f);
		glEnd();
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

} /* namespace OpenGLMD5Viewer */
