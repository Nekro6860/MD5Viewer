#include "Md5Model.h"

namespace OpenGLMD5Viewer {

/////////////////////////////////////////////////////////////////////////////
//
// class Md5Model implementation.
//
/////////////////////////////////////////////////////////////////////////////


// --------------------------------------------------------------------------
// Md5Model::~Md5Model
//
// Destructor.  Free all data allocated for the model.
// --------------------------------------------------------------------------

Md5Model::~Md5Model( void )
{
  // Not exception-safe!
//  std::for_each( _meshes.begin(), _meshes.end(), DeleteObjectPtr() );

  // Simply awful
  for( AnimMap::iterator itor = _animList.begin();
	   itor != _animList.end(); ++itor ) {

	delete itor->second;
  }

  _animList.clear();
}


// --------------------------------------------------------------------------
// Md5Model::loadMd5Mesh
//
// Load MD5 mesh from file.
// --------------------------------------------------------------------------

bool Md5Model::loadModel( const string &filename )
{
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
	  else if( token == "numJoints" ) {
		file >> _numJoints;
		_baseSkeleton.setNumJoints( _numJoints );
	  }
	  else if( token == "numMeshes" ) {
		file >> _numMeshes;
		_meshes.reserve( _numMeshes );
	  }
	  else if( token == "joints" ) {
		// Base skeleton data
		file >> token; // "{"

		if( !_baseSkeleton.load( file ) ) {
		  // An error has occured when loading skeleton data
		  file.close();
		  return false;
		}

		file >> token; // "}"
	  }
	  else if( token == "mesh" ) {
		file >> token; // "{"

		// Create a new model mesh
		Md5Mesh *mesh = new Md5Mesh;

		// Load it
		if( !mesh->load( file ) ) {
		  // An error has occured when loading mesh data
		  delete mesh;
		  file.close();
		  return false;
		}
		else {
		  // Compute bounding box in bind-pose
		  mesh->computeBoundingBox( _baseSkeleton );

		  // Compute weight normals
		  mesh->computeWeightNormals( _baseSkeleton );

		  // Compute weight tangents
		  mesh->computeWeightTangents( _baseSkeleton );
		}

		_meshes.push_back( mesh );
	  }
	}

	file.close();

	// Compute the bounding box in bind-pose
	computeBindPoseBoundingBox();

	std::cout << "_________________________________________" << std::endl;
	std::cout << "Model loaded" << std::endl;
	std::cout << "	path: " << filename << std::endl;
	std::cout << "_________________________________________" << std::endl << std::endl;
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
// Md5Model::prepare
//
// Prepare each mesh of the model for drawing, i.e. compute final vertex
// positions, normals and other vertex's related data.
// --------------------------------------------------------------------------

void Md5Model::prepare( Md5Skeleton &skel )
{
  for( unsigned int i = 0; i < _numMeshes; ++i ) {
	if( !_meshes[i]->hiden() ) {
	  // Prepare for drawing with interpolated skeleton
	  _meshes[i]->setupVertexArrays( &skel );
	}
  }
}


// --------------------------------------------------------------------------
// Md5Model::addAnim
//
// Load a MD5 animation and add it to the animation list.  Return true if
// the animation has been loaded successfully.
// --------------------------------------------------------------------------

bool Md5Model::addAnim( const string &filename )
{
  Md5Animation *pAnim = new Md5Animation;

  if( pAnim->load( filename ) ) {
	// Check for compatibility
	if( !validityCheck( pAnim ) ) {
		std::cerr << filename << " isn't a valid animation"
		   << " for this model!" << std::endl;
	  delete pAnim;
	  return false;
	}

	string name = pAnim->getName();

	// If there is already an animation with same name,
	// delete it
	AnimMap::iterator itor = _animList.find( name );
	if( itor != _animList.end() ) {
	  delete itor->second;
	  _animList.erase( itor );
	}

	// Insert the new animation
	_animList.insert( AnimMap::value_type( name, pAnim ) );
  }
  else {
	// Failled to load the animation file, free memory
	// and exit.
	delete pAnim;
	return false;
  }

  return true;
}


// --------------------------------------------------------------------------
// Md5Model::getAnim
//
// Return animation from list.
// --------------------------------------------------------------------------

Md5Animation *Md5Model::getAnim( const string &name )
{
  AnimMap::iterator itor = _animList.find( name );
  if( itor != _animList.end() ) {
	return itor->second;
  }

  return NULL;
}


// --------------------------------------------------------------------------
// Md5Model::computeBindPoseBoundingBox
//
// Compute model's bounding box in bind-pose.
// --------------------------------------------------------------------------

void Md5Model::computeBindPoseBoundingBox( void )
{
  MathUtils::Vector3f max( -99999.0f, -99999.0f, -99999.0f );
  MathUtils::Vector3f min(  99999.0f,  99999.0f,  99999.0f );

  // Get the min and the max from all mesh bounding boxes
  for( unsigned int i = 0; i < _numMeshes; ++i ) {
	BoundingBox_t meshBox = _meshes[i]->getBoundingBox();

  	if( meshBox.max._x > max._x ) {
	  max._x = meshBox.max._x;
	}

	if( meshBox.min._x < min._x ) {
	  min._x = meshBox.min._x;
	}

	if( meshBox.max._y > max._y ) {
	  max._y = meshBox.max._y;
	}

	if( meshBox.min._y < min._y ) {
	  min._y = meshBox.min._y;
	}

	if( meshBox.max._z > max._z ) {
	  max._z = meshBox.max._z;
	}

	if( meshBox.min._z < min._z ) {
	  min._z = meshBox.min._z;
	}
  }

  _bindPoseBox.min = min;
  _bindPoseBox.max = max;
}


// --------------------------------------------------------------------------
// Md5Model::validityCheck
//
// Check if an animation is valid for this model or not.  A valid
// animation must have a skeleton with the same number of joints with
// model's skeleton and for each skeleton joint, name and parent Id must
// match.
// --------------------------------------------------------------------------

bool Md5Model::validityCheck( Md5Animation *anim )
{
  if( anim && (_numJoints == anim->getFrame(0)->getNumJoints()) ) {
	for( unsigned int i = 0; i < _numJoints; ++i ) {
	  Md5Joint_t *modelJoint = _baseSkeleton.getJoint(i);
	  Md5Joint_t *animJoint = anim->getFrame(0)->getJoint(i);

	  if( modelJoint->name != animJoint->name ) {
		return false;
	  }

	  if( modelJoint->parent != animJoint->parent ) {
		return false;
	  }
	}
  }
  else {
	return false;
  }

  return true;
}


// --------------------------------------------------------------------------
// Md5Model::getMeshByName
//
// Get pointer to a mesh given its name.  Return NULL if there is no mesh
// with such a name.
// --------------------------------------------------------------------------

Md5Mesh *Md5Model::getMeshByName( const string &name )
{
  for( unsigned int i = 0; i < _numMeshes; ++i ) {
	if( _meshes[i]->getName() == name ) {
	  return _meshes[i];
	}
  }

  return NULL;
}

void Md5Model::printfMeshNames()
{
	std::cout << "Mesh names :" << std::endl;
	for(std::vector<Md5Mesh *>::iterator actualMesh = _meshes.begin(); actualMesh != _meshes.end(); actualMesh++)
	{
		Md5Mesh * temp = *actualMesh;
		std::cout << temp->getName() << std::endl;
	}

}

} // namespace OpenGLMD5Viewer
