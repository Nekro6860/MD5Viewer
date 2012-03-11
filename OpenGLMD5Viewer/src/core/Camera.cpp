/*
 * Camera.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include "Camera.h"
#include <cmath>
using namespace std;

namespace OpenGLMD5Viewer {

Camera::Camera() {
	// TODO Auto-generated constructor stub
	position = QVector3D(0, 0, 10);
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

QVector3D Camera::getPosition()
{
	return position;
}

void Camera::updatePosition(float anglex, float angley)
{
	QVector3D position2 = position;
	position2.setX(position.x()*cos(anglex) - position.z()*sin(anglex));
	position2.setZ(position.x()*sin(anglex) + position.z()*cos(anglex));

	QVector3D position3 = position2;
	position3.setY(position2.y()*cos(angley) - position2.z()*sin(angley));
	position3.setZ(position2.y()*sin(angley) + position2.z()*cos(angley));

	position = position3;


}

} /* namespace OpenGLMD5Viewer */
