/*
 * TestCubeRenderer.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef TESTCUBERENDERER_H_
#define TESTCUBERENDERER_H_

#include <QtOpenGL>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Renderer.h"

namespace OpenGLMD5Viewer {

class TestCubeRenderer : public Renderer {
public:
	TestCubeRenderer();
	virtual ~TestCubeRenderer();

	void init();
	void draw();
	void close();
	void cube();
};

} /* namespace OpenGLMD5Viewer */
#endif /* TESTCUBERENDERER_H_ */
