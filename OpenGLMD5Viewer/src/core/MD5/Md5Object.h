/*
 * Md5Object.h
 *
 *  Created on: 13 mars 2012
 *      Author: Administrator
 */

#ifndef MD5OBJECT_H_
#define MD5OBJECT_H_

#include "common.h"
#include "Md5Model.h"
#include "Md5Skeleton.h"
#include "Md5Animation.h"

namespace OpenGLMD5Viewer {

/////////////////////////////////////////////////////////////////////////////
//
// class Md5Object - MD5 object class.
//
/////////////////////////////////////////////////////////////////////////////

class Md5Object
{
 public:
  // Public internal types/enums
  enum {
	kDrawModel = 1,
	kDrawSkeleton = 2,
	kDrawJointLabels = 4
  };

 public:
  // Contructor/Destructor
  Md5Object( void )
	: _model(NULL), _animatedSkeleton(NULL), _softwareTransformation(false),
	  _currAnim(NULL), _currFrame(0), _nextFrame(1), _last_time(0.0),
	  _max_time(0.0), _renderFlags(kDrawModel) { }
  virtual ~Md5Object( void );

 public:
  // Public interface
  void setMd5Model( Md5Model *pModel );
  void setAnim( const string &name );
  void setModelViewMatrix( const MathUtils::Matrix4x4f &modelView ) {
	_modelView = modelView;
  }
  MathUtils::Matrix4x4f getModelViewMatrix() {
  	return _modelView;
  }

  Md5Skeleton * getAnimatedSkeleton() {
	  return _animatedSkeleton;
  }

  void setRenderFlags( int flags ) {
	_renderFlags = flags;
  }

  int getRenderFlags( void ) {
	return _renderFlags;
  }

  Md5Model *getModelPtr( void ) {
	return _model;
  }

  const string getCurrAnimName( void ) const {
	if( _currAnim ) {
	  return _currAnim->getName();
	}
	else {
	  return "NULL";
	}
  }

  Md5Animation * getCurrAnim( void ) const {
  	  return _currAnim;
  }

  const OBBox_t &getBoundingBox( void ) const {
	return _bbox;
  }

  void animate( double dt );
  void computeBoundingBox( void );
  void prepare( bool softwareTransformation );

 protected:
  // Member variables;
  Md5Model *_model;
  Md5Skeleton *_animatedSkeleton;

  MathUtils::Matrix4x4f _modelView;
  bool _softwareTransformation;

  Md5Animation *_currAnim;
  unsigned int _currFrame;
  unsigned int _nextFrame;

  double _last_time;
  double _max_time;

  int _renderFlags;

  //BoundingBox_t _bbox;
  OBBox_t _bbox;
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5OBJECT_H_ */
