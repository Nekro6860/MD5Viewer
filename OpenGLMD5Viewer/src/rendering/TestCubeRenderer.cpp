/*
 * TestCubeRenderer.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include "TestCubeRenderer.h"

namespace OpenGLMD5Viewer {

//float angle = 45;
QVector3D cameraPosition;
QVector3D targetPosition;
QVector3D lightPosition;

TestCubeRenderer::TestCubeRenderer() {
	// TODO Auto-generated constructor stub
	this->camera = new Camera();
	this->light = new Light();
}

TestCubeRenderer::~TestCubeRenderer() {
	// TODO Auto-generated destructor stub
}

void TestCubeRenderer::init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90, (double) 200 / 200, 1, 650);

	/* init OpenGL */
	glClearColor(2.0f, 2.0f, 2.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* init OpenGL light */
//	lightPosition = this->light->getPosition();
//	GLfloat lightpos[] = { lightPosition.x(), lightPosition.y(), lightPosition.z(), 1.0f };
	//GLfloat ambiant_color[] = { 1.0, 0.8, 0.0, 1.0 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
//	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	// initialisations relatives aux textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	cameraPosition = this->camera->getPosition();
	targetPosition = this->camera->getTargetPosition();
}

void TestCubeRenderer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	setCamera(cameraPosition.x(), cameraPosition.y(), cameraPosition.z(),
				targetPosition.x(), targetPosition.y(), targetPosition.z());

	glMatrixMode(GL_MODELVIEW);

//	glRotatef(angle, 1.0f, 1.0f, 0.0f);

//	cube();
	pyramide();

	GLfloat lightpos[] = { lightPosition.x(), lightPosition.y(), lightPosition.z(), 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
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
	lightPosition = this->light->getPosition();
	cameraPosition = this->camera->getPosition();
	targetPosition = this->camera->getTargetPosition();
//	angle += 1;
}

void TestCubeRenderer::close()
{

}

} /* namespace OpenGLMD5Viewer */
