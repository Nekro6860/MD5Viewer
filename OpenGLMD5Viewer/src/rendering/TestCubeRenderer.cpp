/*
 * TestCubeRenderer.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include "TestCubeRenderer.h"

namespace OpenGLMD5Viewer {

void setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ) {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(camX, camY, camZ, targetX, targetY, targetZ, 0, 1, 0);
}

TestCubeRenderer::TestCubeRenderer() {
	// TODO Auto-generated constructor stub

}

TestCubeRenderer::~TestCubeRenderer() {
	// TODO Auto-generated destructor stub
}

void TestCubeRenderer::init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90, (double) 200 / 200, 1, 650);

	/* init OpenGL */
	glClearColor(8.0f, 8.0f, 8.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* init OpenGL light */
	GLfloat lightpos[] = { -10.0f, 2.0f, 40.0f, 0.0f };
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

void TestCubeRenderer::draw()
{
	// TODO Transformer cette fonction complètement pour qu'elle affiche un cube situé sur l'origine, elle servira à tester les mouvements de la caméra etc...
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	setCamera(1, 1, -10, 0, 0, 0);

	glMatrixMode(GL_MODELVIEW);

//	glRotatef(45.0f, 1.0f, 1.0f, 0.0f);
	cube();
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

			glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
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

void TestCubeRenderer::close()
{

}

} /* namespace OpenGLMD5Viewer */
