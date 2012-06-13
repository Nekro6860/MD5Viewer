/*
 * Md5SolidRenderer.cpp
 *
 *  Created on: 13 mars 2012
 *      Author: Administrator
 */

#include <iostream>

#include "Md5SolidRenderer.h"

namespace OpenGLMD5Viewer {

Md5SolidRenderer::Md5SolidRenderer() {
	target = NULL;
}

Md5SolidRenderer::~Md5SolidRenderer() {
	// TODO Auto-generated destructor stub
}

void Md5SolidRenderer::init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90, (double) 200 / 200, 1, 650);

	/* init OpenGL */
	glClearColor(2.0f, 2.0f, 2.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* init OpenGL light */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// initialisations relatives aux textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->camera = new Camera();
	this->light = new Light();

	/* Do not use shaders */
	GLenum code;
	code = glewInit();
	if(code != GLEW_OK)
	{
		std::cout << "Cannot init glew" << std::endl;
		return;
	}
	glUseProgram(0);
}

void Md5SolidRenderer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	vec3_t * cameraPosition = this->camera->getPosition();
	vec3_t * targetPosition = this->camera->getTargetPosition();

	setCamera((*cameraPosition)[0], (*cameraPosition)[1], (*cameraPosition)[2],
	(*targetPosition)[0], (*targetPosition)[1], (*targetPosition)[2]);
	glMatrixMode(GL_MODELVIEW);

	renderMd5Object();

	GLfloat lightpos[] = { (*light->getPosition())[0], (*light->getPosition())[1], (*light->getPosition())[2], 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
}

void Md5SolidRenderer::timeOut()
{

}

void Md5SolidRenderer::close()
{

}

void Md5SolidRenderer::setTarget(Md5Object *t)
{
	target = t;
}

Md5Object * Md5SolidRenderer::getTarget()
{
	return target;
}

void Md5SolidRenderer::renderMeshVertexArrays(Md5Mesh * _mesh)
{
	vector<Md5Vertex_t *> vertexArray = _mesh->getVertexArray();
	vector<Md5Weight_t *> weightArray = _mesh->getWeightArray();
	vec3_t * finalVertexArray = _mesh->getFinalVertexArray();

	for(vector<Md5Triangle_t *>::iterator actualTriangle = _mesh->getTriangleArray().begin(); actualTriangle != _mesh->getTriangleArray().end(); actualTriangle++)
	{
		Md5Triangle_t * temp = *actualTriangle;
		if(temp != NULL)
		{
			if(temp->index[0]< weightArray.size() && temp->index[1]< weightArray.size() && temp->index[2]< weightArray.size())
					{
						glColor3f(0.4f, 0.4f, 0.4f);
						glBegin(GL_TRIANGLES);
						glVertex3f(finalVertexArray[temp->index[0]][0], finalVertexArray[temp->index[0]][1], finalVertexArray[temp->index[0]][2]);
						glVertex3f(finalVertexArray[temp->index[1]][0], finalVertexArray[temp->index[1]][1], finalVertexArray[temp->index[1]][2]);
						glVertex3f(finalVertexArray[temp->index[2]][0], finalVertexArray[temp->index[2]][1], finalVertexArray[temp->index[2]][2]);
						glEnd();
					}
		}
	}
}

void Md5SolidRenderer::drawModel(Md5Model * _model)
{
	for( unsigned int i = 0; i < _model->getNumMeshes(); ++i ) {
		if( _model->getMeshes()[i]->show() ) {
		  renderMeshVertexArrays(_model->getMeshes()[i]);
		}
	  }
}

void Md5SolidRenderer::drawSkeleton(Md5Skeleton * _animatedSkeleton, const MathUtils::Matrix4x4f &modelView, bool labelJoints )
{
	/* Do not use any shaders */
		glUseProgram(0);

	unsigned int i;

	  // Draw each joint
	  glPointSize( 5.0f );
	  glColor3f( 1.0f, 0.0f, 0.0f );
	  glBegin( GL_POINTS );
	    for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		  glVertex3fv( _animatedSkeleton->getJoint(i)->pos._v );
		}
	  glEnd();
	  glPointSize( 1.0f );

	  // Draw each bone
	  glColor3f( 0.0f, 1.0f, 0.0f );
	  glBegin( GL_LINES );
	    for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		  if( _animatedSkeleton->getJoint(i)->parent != -1 ) {
			glVertex3fv( _animatedSkeleton->getJoint(_animatedSkeleton->getJoint(i)->parent)->pos._v );
			glVertex3fv( _animatedSkeleton->getJoint(i)->pos._v );
		  }
		}
	  glEnd();

	  // Label each joint
	  if( labelJoints ) {
		vector<Md5Joint_t> jointlist( _animatedSkeleton->getNumJoints() );

		// Copy joint's position and name
		for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		  jointlist.push_back( *_animatedSkeleton->getJoint(i) );
		}

		// Sort joints about depth because of alpha blending
//		std::sort( jointlist.begin(), jointlist.end() );

		GLfloat mat[16];
		glGetFloatv( GL_MODELVIEW_MATRIX, mat );

		glPushMatrix();
	      // Setup billboard matrix
	      mat[0] = 1.0f; mat[1] = 0.0f; mat[2] = 0.0f;
		  mat[4] = 0.0f; mat[5] = 1.0f; mat[6] = 0.0f;
		  mat[8] = 0.0f; mat[9] = 0.0f; mat[10]= 1.0f;

		  glLoadMatrixf( mat );

		  glPushAttrib( GL_POLYGON_BIT );
		    glFrontFace( GL_CCW );
			glPolygonMode( GL_FRONT, GL_FILL );
			glColor3f( 1.0f, 1.0f, 1.0f );

			glLoadIdentity();
			glScalef( 0.1f, 0.1f, 0.1f );

			for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
			  glPushMatrix();
			    // Move to joint's position
		        glTranslatef( jointlist[i].pos._x * 10.0f,
							  jointlist[i].pos._y * 10.0f,
							  jointlist[i].pos._z * 10.0f );

//				font->printText( jointlist[i].name.c_str() );
			  glPopMatrix();
			}
		  glPopAttrib();
		glPopMatrix();
	  }
}

void Md5SolidRenderer::renderMd5Object()
{
	if(target != NULL)
	{

		int flags = Md5Object::kDrawModel;
		bool bAnimate = true;
		double dt = 0.001;
//		MathUtils::Matrix4x4f * final = new MathUtils::Matrix4x4();
//		target->setModelViewMatrix( *final );
		target->setRenderFlags( flags );
		target->animate( bAnimate ? dt : 0.0f );
		target->computeBoundingBox();
		target->prepare(false);
		glPushMatrix();
		float size = 0.1f;
		glScalef(size, size, size);
		  glRotatef( -90.0, 1.0, 0.0, 0.0 );

			glPushAttrib( GL_POLYGON_BIT | GL_ENABLE_BIT );
			  glFrontFace( GL_CW );

			  if( target->getRenderFlags() & target->kDrawModel ) {
				glEnable(GL_DEPTH_TEST);
				drawModel(target->getModelPtr());
			  }

			  if( skeletonDisplay ) {
				glDisable(GL_DEPTH_TEST);
				glDisable( GL_TEXTURE_2D );
				glDisable( GL_LIGHTING );

				drawSkeleton(target->getAnimatedSkeleton(), target->getModelViewMatrix(), target->getRenderFlags() & target->kDrawJointLabels );
			  }

			  glDisable(GL_LIGHTING);
			  glColor3f(1.0f, 0.5f, 0.0f);
			  glPointSize(4.0f);
			  glBegin(GL_POINT);
			  glVertex3f((*light->getPosition())[0], (*light->getPosition())[1], (*light->getPosition())[2]);
			  glEnd();
			  glEnable(GL_LIGHTING);

			glPopAttrib();
		  glPopMatrix();
	}
	else
	{
	}
}

} /* namespace OpenGLMD5Viewer */
