/*
 * Camera.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <QVector3D>

namespace OpenGLMD5Viewer {

class Camera {
public:
	Camera();
	virtual ~Camera();
	QVector3D getPosition();
	void updatePosition(float anglex, float angley);

private:
	QVector3D position;
};

} /* namespace OpenGLMD5Viewer */
#endif /* CAMERA_H_ */
