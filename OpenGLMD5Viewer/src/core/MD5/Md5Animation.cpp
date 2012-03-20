/*
 * Md5Animation.cpp
 *
 *  Created on: 12 mars 2012
 *      Author: Administrator
 */

#include "Md5Animation.h"

namespace OpenGLMD5Viewer {

/////////////////////////////////////////////////////////////////////////////
//
// class Md5Animation implementation.
//
/////////////////////////////////////////////////////////////////////////////


// --------------------------------------------------------------------------
// Md5Animation::~Md5Animation
//
// Destructor.  Free all data allocated for the animation.
// --------------------------------------------------------------------------

Md5Animation::~Md5Animation( void )
{
  // Not exception-safe!
//  std::for_each( _skelframes.begin(), _skelframes.end(), DeleteObjectPtr() );
//  std::for_each( _bboxes.begin(), _bboxes.end(), DeleteObjectPtr() );
}


// --------------------------------------------------------------------------
// Md5Animation::load
//
// Load MD5 animation from <.md5anim> file.
// --------------------------------------------------------------------------

bool Md5Animation::load( const string &filename )
{
  vector<JointInfo_t> jointInfos;
  vector<BaseFrameJoint_t> baseFrame;
  vector<float> animFrameData;
  int numJoints = 0;
  int numAnimatedComponents = 0;

  // Open file
  std::ifstream file( filename.c_str(), std::ios::in );

  if( file.fail() ) {
	  std::cerr << "Couldn't load " << filename << std::endl;
	return false;
  }

  try {
	while( !file.eof() ) {
	  string token, buffer;
	  int version;
	  int i;

	  // Read next token
	  file >> token;

	  if( token == "//" ) {
		// This is the begining of a comment
		// Eat up rest of the line
		std::getline( file, buffer );
	  }
	  else if( token == "MD5Version" ) {
		file >> version;

		if( version != /*kMd5Version*/10 ) {
			std::cerr << "Error: MD5Version is " << version << std::endl;
			std::cerr << " Should be " << /*kMd5Version*/10 << std::endl;
		  file.close();
		  return false;
		}
	  }
	  else if( token == "numFrames" ) {
		file >> _numFrames;
		_skelframes.reserve( _numFrames );
		_bboxes.reserve( _numFrames );
	  }
	  else if( token == "numJoints" ) {
		file >> numJoints;
		jointInfos.reserve( numJoints );
		baseFrame.reserve( numJoints );
	  }
	  else if( token == "frameRate" ) {
		file >> _frameRate;
	  }
	  else if( token == "numAnimatedComponents" ) {
		file >> numAnimatedComponents;
		animFrameData.reserve( numAnimatedComponents );
	  }
	  else if( token == "hierarchy" ) {
		// Read all joint infos
		file >> token; // "{"

		// Read all joint infos
		for( i = 0; i < numJoints; ++i ) {
		  JointInfo_t jinfo;

		  file >> jinfo.name;
		  file >> jinfo.parent;
		  file >> jinfo.flags;
		  file >> jinfo.startIndex;

		  jointInfos.push_back( jinfo );

		  // Eat up rest of the line
		  std::getline( file, buffer );
		}

		file >> token; // "}"
	  }
	  else if( token == "bounds" ) {
		file >> token; // "{"

		// Read frame bounds
		for( unsigned int i = 0; i < _numFrames; ++i ) {
		  BoundingBox_t *bbox = new BoundingBox_t;

		  file >> token; // "("
		  file >> bbox->min._x;
		  file >> bbox->min._y;
		  file >> bbox->min._z;
		  file >> token; // ")"
		  file >> token; // "("
		  file >> bbox->max._x;
		  file >> bbox->max._y;
		  file >> bbox->max._z;
		  file >> token; // ")"

		  _bboxes.push_back( bbox );
		}

		file >> token; // "}"
	  }
	  else if( token == "baseframe" ) {
		// We should have an opening bracket for the baseframe joint list
		file >> token; // "{"

		// Read baseframe data
		for( i = 0; i < numJoints; ++i ) {
		  BaseFrameJoint_t bfj;

		  file >> token; // "("
		  file >> bfj.pos._x;
		  file >> bfj.pos._y;
		  file >> bfj.pos._z;
		  file >> token; // ")"
		  file >> token; // "("
		  file >> bfj.orient._x;
		  file >> bfj.orient._y;
		  file >> bfj.orient._z;
		  file >> token; // ")"

		  baseFrame.push_back( bfj );

		  // Eat up rest of the line
		  std::getline( file, buffer );
		}

		file >> token; // "}"
	  }
	  else if( token == "frame" ) {
		int frameIndex;
		file >> frameIndex;
		file >> token; // "{"

		animFrameData.clear();

		// Read all frame data
		float afvalue;
		for( i = 0; i < numAnimatedComponents; ++i ) {
		  // NOTE about coding style: beeuuarg *vomit*
		  file >> afvalue;
		  animFrameData.push_back( afvalue );
		}

		file >> token; // "}"

		// Build skeleton for this frame
		buildFrameSkeleton( jointInfos, baseFrame, animFrameData, frameIndex );
	  }
	}

	file.close();

	// Find animation's name
	string szfile = filename;
	string::size_type start = szfile.find_last_of( "/" );
	string::size_type end = szfile.find_last_of( ".md5anim" );
	_name = szfile.substr( start + 1, end - start - 8 );

	std::cout << "* ModelAnimation: " << filename << " loaded" << std::endl;
	return true;
  }
  catch( std::ios_base::failure &err ) {
	  std::cerr << "Couldn't load " << filename << std::endl;
	  std::cerr << " Reason: " << err.what() << std::endl;
	return false;
  }
  return false;
}


// --------------------------------------------------------------------------
// Md5Animation::buildFrameSkeleton
//
// Build a skeleton for a particular frame.  The skeleton is transformed
// by the given modelview matrix so that it is possible to obtain the
// skeleton in absolute coordinates.
//
// NOTE: You must delete yourself the skeleton returned!
// --------------------------------------------------------------------------

void Md5Animation::buildFrameSkeleton( vector<JointInfo_t> &jointInfos,
									   vector<BaseFrameJoint_t> &baseFrame,
									   vector<float> &animFrameData,
									   int iframe )
{
  // Allocate memory for this frame
  Md5Skeleton *skelframe = new Md5Skeleton;
  _skelframes.push_back( skelframe );

  skelframe->setNumJoints( jointInfos.size() );

  // Setup all joints for this frame
  for( unsigned int i = 0; i < jointInfos.size(); ++i ) {
	BaseFrameJoint_t *baseJoint = &baseFrame[i];
	MathUtils::Vector3f animatedPos = baseJoint->pos;
	MathUtils::Quaternionf animatedOrient = baseJoint->orient;
	int j = 0;

	if( jointInfos[i].flags & 1 ) { // Tx
	  animatedPos._x = animFrameData[ jointInfos[i].startIndex + j ];
	  ++j;
	}

	if( jointInfos[i].flags & 2 ) { // Ty
	  animatedPos._y = animFrameData[ jointInfos[i].startIndex + j ];
	  ++j;
	}

	if( jointInfos[i].flags & 4 ) { // Tz
	  animatedPos._z = animFrameData[ jointInfos[i].startIndex + j ];
	  ++j;
	}

	if( jointInfos[i].flags & 8 ) { // Qx
	  animatedOrient._x = animFrameData[ jointInfos[i].startIndex + j ];
	  ++j;
	}

	if( jointInfos[i].flags & 16 ) { // Qy
	  animatedOrient._y = animFrameData[ jointInfos[i].startIndex + j ];
	  ++j;
	}

	if( jointInfos[i].flags & 32 ) { // Qz
	  animatedOrient._z = animFrameData[ jointInfos[i].startIndex + j ];
	  ++j;
	}

	// Compute orient quaternion's w value
	animatedOrient.computeW();

	// NOTE: we assume that this joint's parent has
	// already been calculated, i.e. joint's ID should
	// never be smaller than its parent ID.
	Md5Joint_t *thisJoint = new Md5Joint_t;
	skelframe->insertJoint( i, thisJoint );

	int parent = jointInfos[i].parent;
	thisJoint->parent = parent;
	thisJoint->name = jointInfos[i].name;

	// has parent?
	if( thisJoint->parent < 0 ) {
	  thisJoint->pos = animatedPos;
	  thisJoint->orient = animatedOrient;
	}
	else {
	  Md5Joint_t *parentJoint = skelframe->getJoint( parent );

	  parentJoint->orient.rotate( animatedPos );
	  thisJoint->pos = animatedPos + parentJoint->pos;

	  thisJoint->orient = parentJoint->orient * animatedOrient;
	  thisJoint->orient.normalize();
	}
  }
}


// --------------------------------------------------------------------------
// Md5Animation::interpolate
//
// Build an interpolated skeleton given two frame indexes and an
// interpolation percentage.
// --------------------------------------------------------------------------

void Md5Animation::interpolate( unsigned int frameA, unsigned int frameB,
								float interp, Md5Skeleton *out )
{
  for( unsigned int i = 0; i < out->getNumJoints(); ++i ) {
	Md5Joint_t *pJointA = _skelframes[ frameA ]->getJoint(i);
	Md5Joint_t *pJointB = _skelframes[ frameB ]->getJoint(i);
	Md5Joint_t *pFinalJoint = out->getJoint(i);

	pFinalJoint->parent = pJointA->parent;
	pFinalJoint->pos = pJointA->pos + interp * (pJointB->pos - pJointA->pos);
	pFinalJoint->orient = Slerp( pJointA->orient, pJointB->orient, interp );
  }
}


} /* namespace OpenGLMD5Viewer */
