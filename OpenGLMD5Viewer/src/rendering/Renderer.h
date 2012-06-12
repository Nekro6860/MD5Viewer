/*
 * Renderer.h
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "../core/MD5/common.h"
#include "../core/Camera.h"
#include "../core/Light.h"
#include "../core/MD5/Md5Object.h"

namespace OpenGLMD5Viewer {

class Renderer {

public:
	Renderer();
	virtual ~Renderer();

	virtual void init()=0;
	virtual void draw()=0;
	virtual void close()=0;
	virtual void timeOut()=0;
	void setTarget(Md5Object *t){target = t;}
	Md5Object * getTarget(){return target;}
	Camera * camera;
	Light * light;
	bool skeletonDisplay;
	int displayType;
	void setIdTexture(GLuint * id);
	GLuint * getIdTexture();
	static GLuint * loadTexture(string fileName);
	void setUseSpecularMap(bool v){useSpecularMap = v;}
	void setUseNormalMap(bool v){useNormalMap = v;}

protected:
	Md5Object *target;
	void setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ);
	QVector3D cameraPosition;
	QVector3D lightPosition;
	QVector3D targetPosition;

	bool useSpecularMap;
	bool useNormalMap;
};

} /* namespace OpenGLMD5Viewer */
#endif /* RENDERER_H_ */
