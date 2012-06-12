/*
 * Md5Animation.h
 *
 *  Created on: 12 mars 2012
 *      Author: Administrator
 */

#ifndef MD5ANIMATION_H_
#define MD5ANIMATION_H_

#include <iostream>

#include "common.h"
#include "Md5Skeleton.h"

namespace OpenGLMD5Viewer {

class Md5Animation
{
 public:
  // Constructor/Destructor
  Md5Animation( void )
	: _numFrames(0), _frameRate(0) { }
  ~Md5Animation( void );

 public:
  // Public interface
  bool load( const string &filename );

  void interpolate( unsigned int frameA, unsigned int frameB,
					float interp, Md5Skeleton *out );

  // Accessors
  unsigned int getMaxFrames( void ) const {
	return _numFrames - 1;
  }

  const string &getName( void ) const {
	return _name;
  }

  unsigned int getFrameRate( void ) const {
	return _frameRate;
  }

  void setFrameRate( unsigned int f) {
  	_frameRate = f;
    }

  Md5Skeleton *getFrame( unsigned int frame ) {
//	assert( frame < _numFrames );
	  if(frame < _numFrames)
	  {
		  return _skelframes[ frame ];
	  }
	  else
	  {
		  std::cout << "assert( frame < _numFrames ) failed !" << std::endl;
	  }
	  return _skelframes[ 0 ];
  }

  BoundingBox_t *getFrameBounds( unsigned int frame ) {
	return _bboxes[ frame ];
  }

 private:
  // Internal type
  struct JointInfo_t {
	string name;
	int parent;
	int flags;
	int startIndex;
  };

  struct BaseFrameJoint_t {
	MathUtils::Vector3f pos;
	MathUtils::Quaternionf orient;
  };

 private:
  // Internal functions
  void buildFrameSkeleton( vector<JointInfo_t> &jointInfos,
	vector<BaseFrameJoint_t> &baseFrame, vector<float> &animFrameData, int iframe );

 private:
  // Member variables
  unsigned int _numFrames;
  unsigned int _frameRate;

  string _name;

  // Store each frame as a skeleton
  vector<Md5Skeleton *> _skelframes;

  // Bounding boxes for each frame
  vector<BoundingBox_t *> _bboxes;
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5ANIMATION_H_ */
