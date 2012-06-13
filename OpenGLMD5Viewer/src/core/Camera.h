/*
 * Camera.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "MD5/common.h"

namespace OpenGLMD5Viewer {

class Camera {
public:
	Camera();
	virtual ~Camera();
	vec3_t * getPosition();
	vec3_t * getTargetPosition();
	void updateAngles(int diffX, int diffY);
	void updateTargetPosition(float diffy);
	void zoomIn();
	void zoomOut();

private:
	vec3_t position;
	vec3_t targetPosition;
	float nearest;
	float furthest;
	float distance;
	float angleX;
	float angleY;
	void updatePosition();
};

} /* namespace OpenGLMD5Viewer */
#endif /* CAMERA_H_ */
