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
	position = {0.0f, 5.0f, 20.0f};
	diffuse = {1.0f, 1.0f, 1.0f};
	specular = {1.0f, 1.0f, 1.0f};
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

void Light::updatePosition(float diffx, float diffy)
{
	vec3_t position2 = {position[0], position[1], position[2]};
	position2[0] = position[0]*cos(diffx) - position[2]*sin(diffx);
	position2[2] = position[0]*sin(diffx) + position[2]*cos(diffx);
	position2[1] = position[1] + diffy;

	position = {position2[0], position2[1], position2[2]};
}

} /* namespace OpenGLMD5Viewer */
