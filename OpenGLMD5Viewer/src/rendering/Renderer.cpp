/*
 * Renderer.cpp
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#include "Renderer.h"

namespace OpenGLMD5Viewer {

void Renderer::setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ) {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(camX, camY, camZ, targetX, targetY, targetZ, 0, 1, 0);
}

Renderer::Renderer() {
	// TODO Auto-generated constructor stub

}

Renderer::~Renderer() {
	// TODO Auto-generated destructor stub
}

} /* namespace OpenGLMD5Viewer */
