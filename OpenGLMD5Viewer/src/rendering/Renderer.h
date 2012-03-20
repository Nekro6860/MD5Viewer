/*
 * Renderer.h
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <QtOpenGL>
#include <GL/glext.h>


#include "../core/MD5/common.h"
#include "../core/Camera.h"
#include "../core/Light.h"

namespace OpenGLMD5Viewer {

class Renderer {

public:
	Renderer();
	virtual ~Renderer();

	virtual void init()=0;
	virtual void draw()=0;
	virtual void close()=0;
	virtual void timeOut()=0;
	Camera * camera;
	Light * light;
	bool skeletonDisplay;
	int displayType;
	void setIdTexture(GLuint * id);
	GLuint * getIdTexture();
	GLuint * loadTexture(QString fileName);

protected:
	void setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ);
	QVector3D cameraPosition;
	QVector3D lightPosition;
	QVector3D targetPosition;
	GLuint * idTexture;
};

} /* namespace OpenGLMD5Viewer */
#endif /* RENDERER_H_ */
