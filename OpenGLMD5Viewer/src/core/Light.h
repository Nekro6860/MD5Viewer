/*
 * Light.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "MD5/common.h"
namespace OpenGLMD5Viewer {

class Light {
public:
	Light();
	virtual ~Light();
	vec3_t * getPosition(){return &position;}
	vec3_t * getDiffuse(){return &diffuse;}
	vec3_t * getSpecular(){return &specular;}

	void updatePosition(float diffx, float diffy);

private:
	vec3_t position;
	vec3_t diffuse;
	vec3_t specular;
};

} /* namespace OpenGLMD5Viewer */
#endif /* LIGHT_H_ */
