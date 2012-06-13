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
	position = {0.0f, 0.0f, 20.0f};
	targetPosition = {0.0f, 0.0f, 0.0f};
	nearest = 0;
	furthest = 100;
	distance = 20;
	angleX = 0;
	angleY = 0;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

vec3_t * Camera::getPosition()
{
	return &position;
}

vec3_t * Camera::getTargetPosition()
{
	return &targetPosition;
}

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
		targetPosition[1] = targetPosition[1] + 0.2;
	else if (diffy < 0)
		targetPosition[1] = targetPosition[1] - 0.2;
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
	position[2] = cos(angleX) * cos(angleY) * distance;
	position[1] = sin(angleY) * distance;
	if(angleX>M_PI)
	{
		position[0] = sqrt(float(distance*distance - position[2]*position[2] - position[1]*position[1]));
	}
	else
	{
		position[0] = -sqrt(float(distance*distance - position[2]*position[2] - position[1]*position[1]));
	}

}

} /* namespace OpenGLMD5Viewer */
