/*
 * Camera.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#define M_PI 3.14159265358979323846
#define EPS 0.00001

#include "Camera.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace OpenGLMD5Viewer {

Camera::Camera() {
	// TODO Auto-generated constructor stub
	position = QVector3D(0, 0, 20);
	targetPosition = QVector3D(0, 0, 0);
	nearest = 0;
	furthest = 100;
	distance = 20;
	angleX = 0;
	angleY = 0;
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

//void Camera::updatePositionx(float anglex)
//{
//	QVector3D position2 = position;
//	position2.setX(position.x()*cos(anglex) - position.z()*sin(anglex));
//	position2.setZ(position.x()*sin(anglex) + position.z()*cos(anglex));
//
//	position = position2;
//}
//
//void Camera::updatePositiony(float diffy)
//{
//	float length = position.length();
//	if (diffy > 0)
//		position.setY(position.y() + 1);
//	else if (diffy < 0)
//		position.setY(position.y() - 1);
//	else
//		return;
//	position.normalize();
//	position = position*length;
//}

void Camera::updateAngles(int diffX, int diffY)
{
	float rotationSpeed = 0.005;
	angleX += diffX*rotationSpeed;
	if(angleX<0) angleX = 2*M_PI - EPS;
	if(angleX> 2*M_PI) angleX = EPS;

	angleY += diffY*rotationSpeed;

	updatePosition();
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
	if(distance>nearest && distance<furthest)
		{
			distance -= 0.5;
			updatePosition();
		}
}

void Camera::zoomOut()
{
	if(distance>nearest && distance<furthest)
		{
			distance += 0.5;
			updatePosition();
		}
}

void Camera::updatePosition()
{
	position.setZ(cos(angleX) * cos(angleY) * distance);
	position.setY(sin(angleY) * distance);
//	position.setX(-sqrt(float(distance*distance - position.z()*position.z() - position.y()*position.y())));
	if(angleX>M_PI)
	{
		position.setX(sqrt(float(distance*distance - position.z()*position.z() - position.y()*position.y())));
	}
	else
	{
		position.setX(-sqrt(float(distance*distance - position.z()*position.z() - position.y()*position.y())));
	}

}

} /* namespace OpenGLMD5Viewer */
