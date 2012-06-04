/*
 * Light.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include "Light.h"
#include <cmath>
#include <iostream>

using namespace std;

namespace OpenGLMD5Viewer {

Light::Light() {
	// TODO Auto-generated constructor stub
	position = QVector3D(2, 5, 0);
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

QVector3D Light::getPosition()
{
	return position;
}

void Light::updatePosition(float diffx, float diffy)
{
	QVector3D position2 = position;
	position2.setX(position.x()*cos(diffx) - position.z()*sin(diffx));
	position2.setZ(position.x()*sin(diffx) + position.z()*cos(diffx));
	position2.setY(position.y() + diffy);

	position = position2;
}

} /* namespace OpenGLMD5Viewer */
