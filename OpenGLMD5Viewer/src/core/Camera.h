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
	QVector3D getTargetPosition();
	void updatePositionx(float anglex);
	void updatePositiony(float angley);
	void updateTargetPosition(float diffy);
	void zoomIn();
	void zoomOut();

private:
	QVector3D position;
	QVector3D targetPosition;
	float nearest;
	float furthest;
};

} /* namespace OpenGLMD5Viewer */
#endif /* CAMERA_H_ */
