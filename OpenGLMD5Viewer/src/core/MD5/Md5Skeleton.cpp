/*
 * MD5Skeleton.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include <list>

#include "Md5Skeleton.h"

namespace OpenGLMD5Viewer {

/////////////////////////////////////////////////////////////////////////////
//
// class Md5Skeleton implementation.
//
/////////////////////////////////////////////////////////////////////////////


// --------------------------------------------------------------------------
// Md5Skeleton::~Md5Skeleton
//
// Destructor.  Free all data allocated for skeleton's joints.
// --------------------------------------------------------------------------

Md5Skeleton::~Md5Skeleton( void )
{
  // Not exception-safe!
//  std::for_each( _joints.begin(), _joints.end(), DeleteObjectPtr() );
}


// --------------------------------------------------------------------------
// Md5Skeleton::load
//
// Load skeleton data from a <.md5mesh> file.
// --------------------------------------------------------------------------

bool Md5Skeleton::load( std::ifstream &file )
{
  string token, buffer;

  if( !file.is_open() ) {
	return false;
  }

  // Read all joints
  for( unsigned int i = 0; i < _numJoints; ++i ) {
	// NOTE: hope there isn't any comment between
	// two lines of joints data...
	Md5Joint_t *j = new Md5Joint_t;

	file >> j->name;
	file >> j->parent;
	file >> token; // "("
	file >> j->pos._x;
	file >> j->pos._y;
	file >> j->pos._z;
	file >> token; // ")"
	file >> token; // "("
	file >> j->orient._x;
	file >> j->orient._y;
	file >> j->orient._z;
	file >> token; // ")"

	// Eat up rest of the line
	std::getline( file, buffer );

	// Compute orient quaternion's w value
	j->orient.computeW();

	// Add joint to joints vector
	_joints.push_back( j );
  }

  return true;
}



// --------------------------------------------------------------------------
// Md5Skeleton::draw
//
// Draw skeleton's bones and joints.
// --------------------------------------------------------------------------

void Md5Skeleton::draw( const MathUtils::Matrix4x4f &modelView, bool labelJoints )
{
  unsigned int i;

  // Draw each joint
  glPointSize( 5.0f );
  glColor3f( 1.0f, 0.0f, 0.0f );
  glBegin( GL_POINTS );
    for( i = 0; i < _numJoints; ++i ) {
	  glVertex3fv( _joints[i]->pos._v );
	}
  glEnd();
  glPointSize( 1.0f );

  // Draw each bone
  glColor3f( 0.0f, 1.0f, 0.0f );
  glBegin( GL_LINES );
    for( i = 0; i < _numJoints; ++i ) {
	  if( _joints[i]->parent != -1 ) {
		glVertex3fv( _joints[ _joints[i]->parent ]->pos._v );
		glVertex3fv( _joints[i]->pos._v );
	  }
	}
  glEnd();

  // Label each joint
  if( labelJoints ) {
	vector<Md5Joint_t> jointlist( _numJoints );

	// Copy joint's position and name
	for( i = 0; i < _numJoints; ++i ) {
	  jointlist.push_back( *_joints[i] );
	}

	// Sort joints about depth because of alpha blending
//	std::list::sort( jointlist.begin(), jointlist.end() );

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

		for( i = 0; i < _numJoints; ++i ) {
		  glPushMatrix();
		    // Move to joint's position
	        glTranslatef( jointlist[i].pos._x * 10.0f,
						  jointlist[i].pos._y * 10.0f,
						  jointlist[i].pos._z * 10.0f );

//			font->printText( jointlist[i].name.c_str() );
		  glPopMatrix();
		}
	  glPopAttrib();
	glPopMatrix();
  }
}

} /* namespace OpenGLMD5Viewer */
