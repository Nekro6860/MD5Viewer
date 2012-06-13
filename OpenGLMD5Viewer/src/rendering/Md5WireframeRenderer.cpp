/*
 * Md5WireframeRenderer.cpp
 *
 *  Created on: 14 mars 2012
 *      Author: Administrator
 */

#include <iostream>
#include "Md5WireframeRenderer.h"


namespace OpenGLMD5Viewer {

Md5WireframeRenderer::Md5WireframeRenderer() {
	target = NULL;

}

Md5WireframeRenderer::~Md5WireframeRenderer() {
	// TODO Auto-generated destructor stub
}

void Md5WireframeRenderer::init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90, (double) 200 / 200, 1, 650);

	/* init OpenGL */
	glClearColor(2.0f, 2.0f, 2.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* init OpenGL light */
//	lightPosition = this->light->getPosition();
//	GLfloat lightpos[] = { lightPosition.x(), lightPosition.y(), lightPosition.z(), 1.0f };
	//GLfloat ambiant_color[] = { 1.0, 0.8, 0.0, 1.0 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
//	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	// initialisations relatives aux textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->camera = new Camera();
	this->light = new Light();
//	cameraPosition = this->camera->getPosition();
//	lightPosition = this->light->getPosition();
//	targetPosition = this->camera->getTargetPosition();

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

void Md5WireframeRenderer::draw()
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

void Md5WireframeRenderer::timeOut()
{
//	lightPosition = this->light->getPosition();
//	cameraPosition = this->camera->getPosition();
//	targetPosition = this->camera->getTargetPosition();
}

void Md5WireframeRenderer::close()
{

}

void Md5WireframeRenderer::renderMeshVertexArrays(Md5Mesh * _mesh)
{
//	GLint tangentLoc = -1;
//	  bool useShader = bShaders && glslSupported && lightProg && _normalMap;

//	  if( useShader ) {
//		if( GLEW_VERSION_2_0 ) {
//		  // Enable shader
//		  glUseProgram( lightProg );
//		  GLint texLoc, parallaxLoc;
//
//		  // Set uniform parameters
//		  texLoc = glGetUniformLocation( lightProg, "decalMap" );
//		  glUniform1i( texLoc, 0 );
//
//		  texLoc = glGetUniformLocation( lightProg, "glossMap" );
//		  glUniform1i( texLoc, 1 );
//
//		  texLoc = glGetUniformLocation( lightProg, "normalMap" );
//		  glUniform1i( texLoc, 2 );
//
//		  texLoc = glGetUniformLocation( lightProg, "heightMap" );
//		  glUniform1i( texLoc, 3 );
//
//		  parallaxLoc = glGetUniformLocation( lightProg, "parallaxMapping" );
//		  glUniform1i( parallaxLoc, bParallax );
//
//		  // Get attribute location
//		  tangentLoc = glGetAttribLocation( lightProg, "tangent" );
//
//		  if( tangentLoc != -1 ) {
//			glEnableVertexAttribArray( tangentLoc );
//
//			// Upload tangents
//			glVertexAttribPointer( tangentLoc, 3, GL_FLOAT, GL_FALSE, 0, _tangentArray );
//		  }
//		}
//		else if( GLEW_VERSION_1_5 ) {
//		  // Enable shader
//		  glUseProgramObjectARB( lightProg );
//		  GLint texLoc, parallaxLoc;
//
//		  // Set uniform parameters
//		  texLoc = glGetUniformLocationARB( lightProg, "decalMap" );
//		  glUniform1iARB( texLoc, 0 );
//
//		  texLoc = glGetUniformLocationARB( lightProg, "glossMap" );
//		  glUniform1iARB( texLoc, 1 );
//
//		  texLoc = glGetUniformLocationARB( lightProg, "normalMap" );
//		  glUniform1iARB( texLoc, 2 );
//
//		  texLoc = glGetUniformLocationARB( lightProg, "heightMap" );
//		  glUniform1iARB( texLoc, 3 );
//
//		  parallaxLoc = glGetUniformLocationARB( lightProg, "parallaxMapping" );
//		  glUniform1iARB( parallaxLoc, bParallax );
//
//		  // Get attribute location
//		  tangentLoc = glGetAttribLocationARB( lightProg, "tangent" );
//
//		  if( tangentLoc != -1 ) {
//			glEnableVertexAttribArrayARB( tangentLoc );
//
//			// Upload tangents
//			glVertexAttribPointerARB( tangentLoc, 3, GL_FLOAT, GL_FALSE, 0, _tangentArray );
//		  }
//		}
//	  }

//	std::cout << "début de renderVertexArray" << std::endl;
//	std::cout << "mesh name " << _mesh->getName() << std::endl;
	vector<Md5Vertex_t *> vertexArray = _mesh->getVertexArray();
	vector<Md5Weight_t *> weightArray = _mesh->getWeightArray();

//	std::cout << "avant premier parcours des triangles" << std::endl;

//	std::cout << "après premier parcours des triangles" << std::endl;

//	std::cout << "_mesh->getTriangleArray().size() = " << _mesh->getTriangleArray().size() << std::endl;

	vec3_t * finalVertexArray = _mesh->getFinalVertexArray();

	for (int i = 0; i<vertexArray.size(); i++)
	{
//		std::cout << "i = " << i << std::endl;
//		std::cout << "finalVertexArray[i][0] = " << finalVertexArray[i][0] << std::endl;
//		std::cout << "finalVertexArray[i][1] = " << finalVertexArray[i][1] << std::endl;
//		std::cout << "finalVertexArray[i][2] = " << finalVertexArray[i][2] << std::endl << std::endl;
	}

//	std::cout << std::endl << std::endl << "sortie !" << std::endl << std::endl << std::endl << std::endl;

	for(vector<Md5Triangle_t *>::iterator actualTriangle = _mesh->getTriangleArray().begin(); actualTriangle != _mesh->getTriangleArray().end(); actualTriangle++)
	{
		Md5Triangle_t * temp = *actualTriangle;
//		std::cout << "temp = " << temp << std::endl;
		if(temp != NULL)
		{
			if(temp->index[0]< weightArray.size() && temp->index[1]< weightArray.size() && temp->index[2]< weightArray.size())
					{
//						std::cout << "actualTriangle.index[0] = " << temp->index[0] << std::endl;
//						std::cout << "actualTriangle.index[1] = " << temp->index[1] << std::endl;
//						std::cout << "actualTriangle.index[2] = " << temp->index[2] << std::endl << std::endl;
//
//						std::cout << "weightArray[temp->index[0]]->pos._x" << weightArray[temp->index[0]]->pos._x << std::endl;
//						std::cout << "weightArray[temp->index[0]]->pos._y" << weightArray[temp->index[0]]->pos._y << std::endl;
//						std::cout << "weightArray[temp->index[0]]->pos._z" << weightArray[temp->index[0]]->pos._z << std::endl << std::endl;
//
//						std::cout << "weightArray[temp->index[1]]->pos._x" << weightArray[temp->index[1]]->pos._x << std::endl;
//						std::cout << "weightArray[temp->index[1]]->pos._y" << weightArray[temp->index[1]]->pos._y << std::endl;
//						std::cout << "weightArray[temp->index[1]]->pos._z" << weightArray[temp->index[1]]->pos._z << std::endl << std::endl;
//
//						std::cout << "weightArray[temp->index[2]]->pos._x" << weightArray[temp->index[2]]->pos._x << std::endl;
//						std::cout << "weightArray[temp->index[2]]->pos._y" << weightArray[temp->index[2]]->pos._y << std::endl;
//						std::cout << "weightArray[temp->index[2]]->pos._z" << weightArray[temp->index[2]]->pos._z << std::endl;
//						std::cout << "--------------------------------------------------" << std::endl << std::endl;

//						glBegin(GL_TRIANGLES);
//						glVertex3f(finalVertexArray[temp->index[0]][0], finalVertexArray[temp->index[0]][1], finalVertexArray[temp->index[0]][2]);
//						glVertex3f(finalVertexArray[temp->index[1]][0], finalVertexArray[temp->index[1]][1], finalVertexArray[temp->index[1]][2]);
//						glVertex3f(finalVertexArray[temp->index[2]][0], finalVertexArray[temp->index[2]][1], finalVertexArray[temp->index[2]][2]);
//						glEnd();


						glDisable(GL_LIGHTING);
						glColor3f(0.4f, 0.4f, 0.4f);
						glBegin(GL_LINES);
						glVertex3f(finalVertexArray[temp->index[0]][0], finalVertexArray[temp->index[0]][1], finalVertexArray[temp->index[0]][2]);
						glVertex3f(finalVertexArray[temp->index[1]][0], finalVertexArray[temp->index[1]][1], finalVertexArray[temp->index[1]][2]);

						glVertex3f(finalVertexArray[temp->index[0]][0], finalVertexArray[temp->index[0]][1], finalVertexArray[temp->index[0]][2]);
						glVertex3f(finalVertexArray[temp->index[2]][0], finalVertexArray[temp->index[2]][1], finalVertexArray[temp->index[2]][2]);

						glVertex3f(finalVertexArray[temp->index[1]][0], finalVertexArray[temp->index[1]][1], finalVertexArray[temp->index[1]][2]);
						glVertex3f(finalVertexArray[temp->index[2]][0], finalVertexArray[temp->index[2]][1], finalVertexArray[temp->index[2]][2]);
						glEnd();

						glEnable(GL_LIGHTING);
					}
		}


	}
//	std::cout << "fin de renderMeshVertexArray" << std::endl;
}

void Md5WireframeRenderer::drawModel(Md5Model * _model)
{
	for( unsigned int i = 0; i < _model->getNumMeshes(); ++i ) {
		if( _model->getMeshes()[i]->show() ) {
		  renderMeshVertexArrays(_model->getMeshes()[i]);
		}
	  }
}

void Md5WireframeRenderer::drawSkeleton(Md5Skeleton * _animatedSkeleton, const MathUtils::Matrix4x4f &modelView, bool labelJoints )
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

void Md5WireframeRenderer::renderMd5Object()
{
//	std::cout << "début renderMD5Object" << std::endl;
	if(target && target->getModelPtr())
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
			glPopAttrib();
		  glPopMatrix();
	}
	else
	{
	}

}

} /* namespace OpenGLMD5Viewer */
