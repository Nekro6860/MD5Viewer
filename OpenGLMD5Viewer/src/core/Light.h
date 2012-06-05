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
	QVector3D getPosition(){return position;}
	QVector3D getDiffuse(){return diffuse;}
	QVector3D getSpecular(){return specular;}

	void updatePosition(float diffx, float diffy);

private:
	QVector3D position;
	QVector3D diffuse;
	QVector3D specular;
};

} /* namespace OpenGLMD5Viewer */
#endif /* LIGHT_H_ */
