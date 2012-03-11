/*
 * TestCubeRenderer.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include "TestCubeRenderer.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <QtOpenGL>

namespace OpenGLMD5Viewer {

//float angle = 45;
QVector3D cameraPosition = QVector3D(0, 0, 10);

void setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ) {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(camX, camY, camZ, targetX, targetY, targetZ, 0, 1, 0);
}

TestCubeRenderer::TestCubeRenderer() {
	// TODO Auto-generated constructor stub
	this->camera = new Camera();
}

TestCubeRenderer::~TestCubeRenderer() {
	// TODO Auto-generated destructor stub
}

void TestCubeRenderer::init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90, (double) 200 / 200, 1, 650);

	/* init OpenGL */
	glClearColor(2.0f, 2.0f, 2.0f, 0.2f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* init OpenGL light */
	GLfloat lightpos[] = { -5.0f, -5.0f, 5.0f, 1.0f };
	//GLfloat ambiant_color[] = { 1.0, 0.8, 0.0, 1.0 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	// initialisations relatives aux textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void TestCubeRenderer::draw()
{
	// TODO Transformer cette fonction compl�tement pour qu'elle affiche un cube situ� sur l'origine, elle servira � tester les mouvements de la cam�ra etc...
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	setCamera(cameraPosition.x(), cameraPosition.y(), cameraPosition.z(), 0, 0, 0);

//	setCamera(0, 0, 10, 0, 0, 0);

	glMatrixMode(GL_MODELVIEW);

//	glRotatef(angle, 1.0f, 1.0f, 0.0f);

//	cube();
	pyramide();
}

void TestCubeRenderer::cube()
{
	glBegin(GL_QUADS);
			glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);
			glVertex3f(1.0f, -1.0f, 1.0f);
			glVertex3f(1.0f, 1.0f, 1.0f);

			glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(1.0f, -1.0f, -1.0f);
			glVertex3f(1.0f, 1.0f, -1.0f);

			glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);

			glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
			glVertex3f(1.0f, 1.0f, 1.0f);
			glVertex3f(1.0f, 1.0f, -1.0f);
			glVertex3f(1.0f, -1.0f, -1.0f);
			glVertex3f(1.0f, -1.0f, 1.0f);

			glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, -1.0f);
			glVertex3f(1.0f, 1.0f, -1.0f);
			glVertex3f(1.0f, 1.0f, 1.0f);

			glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(1.0f, -1.0f, -1.0f);
			glVertex3f(1.0f, -1.0f, 1.0f);

		glEnd();
}

void TestCubeRenderer::pyramide()
{
	glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-1.0f, -0.5f, 1.0f);
		glVertex3f(1.0f, -0.5f, 1.0f);

		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(1.0f, -0.5f, 1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);

		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);

		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f, 1.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -0.5f, 1.0f);
		glVertex3f(1.0f, -0.5f, 1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
	glEnd();
}

void TestCubeRenderer::timeOut()
{
	cameraPosition = this->camera->getPosition();
//	angle += 1;
}

void TestCubeRenderer::close()
{

}

} /* namespace OpenGLMD5Viewer */
