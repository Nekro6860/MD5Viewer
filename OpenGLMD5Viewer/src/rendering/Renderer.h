/*
 * Renderer.h
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "../core/Camera.h"

namespace OpenGLMD5Viewer {

class Renderer {
public:
	Renderer();
	virtual ~Renderer();

	virtual void init()=0;
	virtual void draw()=0;
	virtual void close()=0;
	Camera * camera;
};

} /* namespace OpenGLMD5Viewer */
#endif /* RENDERER_H_ */
