/*
 * Light.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include "Light.h"
#include <cmath>
#include <iostream>

namespace OpenGLMD5Viewer {

Light::Light() {
	// TODO Auto-generated constructor stub
	position = QVector3D(0, 0, -2);
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

QVector3D Light::getPosition()
{
	return position;
}

void Light::updatePosition(float anglex)
{
	QVector3D position2 = position;
	position2.setX(position.x()*cos(anglex) - position.z()*sin(anglex));
	position2.setZ(position.x()*sin(anglex) + position.z()*cos(anglex));

	position = position2;
}

} /* namespace OpenGLMD5Viewer */
