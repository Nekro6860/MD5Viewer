/*
 * Light.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include <QVector3D>

namespace OpenGLMD5Viewer {

class Light {
public:
	Light();
	virtual ~Light();
	QVector3D getPosition();
	void updatePosition(float diffx, float diffy);

private:
	QVector3D position;
};

} /* namespace OpenGLMD5Viewer */
#endif /* LIGHT_H_ */
