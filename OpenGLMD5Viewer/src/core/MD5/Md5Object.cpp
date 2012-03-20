/*
 * Md5Object.cpp
 *
 *  Created on: 13 mars 2012
 *      Author: Administrator
 */

#include "Md5Object.h"

namespace OpenGLMD5Viewer {

/////////////////////////////////////////////////////////////////////////////
//
// class Md5Object implementation.
//
/////////////////////////////////////////////////////////////////////////////


// --------------------------------------------------------------------------
// Md5Object::~Md5Object
//
// Destructor.  Free all data allocated for the objct.
// --------------------------------------------------------------------------

Md5Object::~Md5Object( void )
{
  if( _animatedSkeleton ) {
	delete _animatedSkeleton;
  }
}


// --------------------------------------------------------------------------
// Md5Object::setMd5Model
//
// Attach MD5 Model to Object.
// --------------------------------------------------------------------------

void Md5Object::setMd5Model( Md5Model *pModel ) {
  if( _model != pModel ) {
	_model = pModel; // Link to the model

	// Delete previous skeletons because the new
	// model is different and its skeleton can hold
	// more joints.
	if( _animatedSkeleton ) {
	  delete _animatedSkeleton;
	}

	// Copy skeleton joints name
	_animatedSkeleton = _model->getBaseSkeleton()->clone();
  }
}


// --------------------------------------------------------------------------
// Md5Object::setAnim
//
// Set animation to play.
// --------------------------------------------------------------------------

void Md5Object::setAnim( const string &name )
{
  if( _model ) {
	// Retrieve animation from model's animation list
	if( (_currAnim = _model->getAnim( name )) ) {

	  // Compute max frame time and reset _last_time
	  _max_time =  1.0 / static_cast<double>(_currAnim->getFrameRate());
	  _last_time = 0.0;
	}
	else {
	  if( _animatedSkeleton ) {
		delete _animatedSkeleton;
	  }

	  // Rebuild animated skeleton with model's base skeleton
	  _animatedSkeleton = _model->getBaseSkeleton()->clone();
	}
  }

  // Reset current and next frames
  _currFrame = 0;
  _nextFrame = _currFrame + 1;
}


// --------------------------------------------------------------------------
// Md5Object::animate
//
// Compute current and next frames for model's animation.
// --------------------------------------------------------------------------

void Md5Object::animate( double dt )
{
  // Animate only if there is an animation...
  if( _currAnim ) {
	_last_time += dt;

	// Move to next frame
	if( _last_time >= _max_time ) {
	  _currFrame++;
	  _nextFrame++;
	  _last_time = 0.0f;

	  unsigned int maxFrames = _currAnim->getMaxFrames();

	  if( _currFrame > maxFrames ) {
		_currFrame = 0;
	  }

	  if( _nextFrame > maxFrames ) {
		_nextFrame = 0;
	  }
	}
  }
}


// --------------------------------------------------------------------------
// Md5Object::computeBoundingBox
//
// Compute object's oriented bounding box.
// --------------------------------------------------------------------------

void Md5Object::computeBoundingBox( void )
{
  BoundingBox_t bbox;

  if( _currAnim ) {
	// Interpolate frames' bounding box in order
	// to get animated AABB in object space
	BoundingBox_t *boxA, *boxB;
	boxA = _currAnim->getFrameBounds( _currFrame );
	boxB = _currAnim->getFrameBounds( _nextFrame );

	float interp = _last_time * _currAnim->getFrameRate();

	bbox.min = boxA->min + (boxB->min - boxA->min) * interp;
	bbox.max = boxA->max + (boxB->max - boxA->max) * interp;
  }
  else {
	// Get bind-pose model's bouding box
	bbox = _model->getBindPoseBoundingBox();
  }

  // Compute oriented bounding box
  _bbox.world = _modelView;
  _bbox.center = MathUtils::Vector3f( (bbox.max._x + bbox.min._x) * 0.5f,
						   (bbox.max._y + bbox.min._y) * 0.5f,
						   (bbox.max._z + bbox.min._z) * 0.5f );
  _bbox.extent = MathUtils::Vector3f( bbox.max._x - _bbox.center._x,
						   bbox.max._y - _bbox.center._y,
						   bbox.max._z - _bbox.center._z );
}


// --------------------------------------------------------------------------
// Md5Object::prepare
//
// Prepare object to be drawn.
// --------------------------------------------------------------------------

void Md5Object::prepare( bool softwareTransformation )
{
  _softwareTransformation = softwareTransformation;

  if( _renderFlags & kDrawModel ) {
	if( _currAnim ) {
	  // Interpolate current and next frame skeletons
	  float interp = _last_time * _currAnim->getFrameRate();
	  _currAnim->interpolate( _currFrame, _nextFrame, interp,
							  _animatedSkeleton );
	}
	else {
	  // If there is no animated skeleton, fall to
	  // model's base skeleton
	  if( _animatedSkeleton ) {
		delete _animatedSkeleton;
	  }

	  _animatedSkeleton = _model->getBaseSkeleton()->clone();
	}

	if( _softwareTransformation || _renderFlags & kDrawJointLabels ) {
	  // Force software transformation if joint labels have
	  // to be drawn
	  _softwareTransformation = true;

	  MathUtils::Quaternionf rot;
	  rot.fromMatrix( _modelView );

	  // Applly Model-View transformation for each joint
	  for( unsigned int i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		Md5Joint_t *thisJoint = _animatedSkeleton->getJoint(i);

		thisJoint->pos = _modelView * thisJoint->pos;
		thisJoint->orient = rot * thisJoint->orient;
	  }
	}

	// Setup vertex arrays
	_model->prepare( *_animatedSkeleton );
  }
}


} /* namespace OpenGLMD5Viewer */
