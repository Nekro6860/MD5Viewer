/*
 * MD5Skeleton.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef MD5SKELETON_H_
#define MD5SKELETON_H_

#include "common.h"

namespace OpenGLMD5Viewer {

class Md5Skeleton
{
 public:
  // Constructor/Destructor
  Md5Skeleton( void )
	: _numJoints(0) { }
  ~Md5Skeleton( void );

 public:
  // Public interface
  bool load( std::ifstream &file );
  void draw( const MathUtils::Matrix4x4f &modelView, bool labelJoints );

  Md5Joint_t *getJoint( unsigned int index ) {
	return _joints[ index ];
  }

  // Insert a joint at a given index from the beginning
  void insertJoint( unsigned int index, Md5Joint_t *thisJoint ) {
	_joints.insert( _joints.begin() + index, thisJoint );
  }

  // Set the number of joints and reserve memory to hold them all
  void setNumJoints( unsigned int numJoints ) {
	_numJoints = numJoints;
	_joints.reserve( _numJoints );
  }

  // Fill the joint vector with new joints
  void preAllocJoints( void ) {
	for( unsigned int i = 0; i < _numJoints; ++i ) {
	  _joints.push_back( new Md5Joint_t );
	}
  }

  unsigned int getNumJoints( void ) {
	return _numJoints;
  }

  Md5Skeleton *clone( void ) {
	Md5Skeleton *cpy = new Md5Skeleton;
	cpy->setNumJoints( _numJoints );

	for( unsigned int i = 0; i < _numJoints; ++i ) {
	  cpy->insertJoint( i, new Md5Joint_t( *_joints[i] ) );
	}

	return cpy;
  }

 private:
  // Member variables
  unsigned int _numJoints;
  vector<Md5Joint_t *> _joints;
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5SKELETON_H_ */
