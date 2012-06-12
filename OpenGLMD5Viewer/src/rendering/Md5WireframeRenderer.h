/*
 * Md5WireframeRenderer.h
 *
 *  Created on: 14 mars 2012
 *      Author: Administrator
 */

#ifndef MD5WIREFRAMERENDERER_H_
#define MD5WIREFRAMERENDERER_H_

#include "Renderer.h"
#include "../core/MD5/Md5Object.h"

namespace OpenGLMD5Viewer {

class Md5WireframeRenderer : public Renderer {
public:
	Md5WireframeRenderer();
	virtual ~Md5WireframeRenderer();

	void init();
	void draw();
	void close();
	void timeOut();

private :
	void renderMd5Object();
	void renderMeshVertexArrays(Md5Mesh * _mesh);
	void drawModel(Md5Model * _model);
	void drawSkeleton(Md5Skeleton * _animatedSkeleton, const MathUtils::Matrix4x4f &modelView, bool labelJoints );
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5WIREFRAMERENDERER_H_ */
