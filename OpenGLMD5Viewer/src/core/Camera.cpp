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
	position = QVector3D(0, 0, 20);
	targetPosition = QVector3D(0, 0, 0);
	nearest = 5;
	furthest = 100;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

QVector3D Camera::getPosition()
{
	return position;
}

QVector3D Camera::getTargetPosition()
{
	return targetPosition;
}

void Camera::updatePositionx(float anglex)
{
	QVector3D position2 = position;
	position2.setX(position.x()*cos(anglex) - position.z()*sin(anglex));
	position2.setZ(position.x()*sin(anglex) + position.z()*cos(anglex));

	position = position2;
}

void Camera::updatePositiony(float diffy)
{
	float length = position.length();
	if (diffy > 0)
		position.setY(position.y() + 1);
	else if (diffy < 0)
		position.setY(position.y() - 1);
	else
		return;
	position.normalize();
	position = position*length;
}

void Camera::updateTargetPosition(float diffy)
{
	if (diffy > 0)
		targetPosition.setY(targetPosition.y() + 0.2);
	else if (diffy < 0)
		targetPosition.setY(targetPosition.y() - 0.2);
	else
		return;
}

void Camera::zoomIn()
{
	if (position.length() > nearest)
	{
		float newLength = position.length() - 1;
		position.normalize();
		position = position*newLength;
	}
}

void Camera::zoomOut()
{
	if (position.length() < furthest)
	{
		float newLength = position.length() + 1;
		position.normalize();
		position = position*newLength;
	}
}

} /* namespace OpenGLMD5Viewer */
