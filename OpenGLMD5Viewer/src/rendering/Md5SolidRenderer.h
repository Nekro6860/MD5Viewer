/*
 * Md5Renderer.h
 *
 *  Created on: 13 mars 2012
 *      Author: Administrator
 */

#ifndef MD5SOLIDRENDERER_H_
#define MD5SOLIDRENDERER_H_

#include "Renderer.h"
#include "../core/MD5/Md5Object.h"

namespace OpenGLMD5Viewer {

class Md5SolidRenderer : public Renderer {
public:
	Md5SolidRenderer();
	virtual ~Md5SolidRenderer();

	void init();
	void draw();
	void close();
	void timeOut();

	void setTarget(Md5Object *t);
	Md5Object * getTarget();

private :
	Md5Object *target;
	void renderMd5Object();
	void renderMeshVertexArrays(Md5Mesh * _mesh);
	void drawModel(Md5Model * _model);
	void drawSkeleton(Md5Skeleton * _animatedSkeleton, const MathUtils::Matrix4x4f &modelView, bool labelJoints );
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5SOLIDRENDERER_H_ */
