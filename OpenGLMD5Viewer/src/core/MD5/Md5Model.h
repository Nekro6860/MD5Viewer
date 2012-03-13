#include <iostream>
//#include <vector>
//#include <string>

#include "common.h"
#include "Md5Skeleton.h"
#include "Md5Animation.h"
#include "Md5Mesh.h"

namespace OpenGLMD5Viewer {

class Md5Model
{
 public:
  // Constructor/Destructor
  Md5Model( void )
	: _numJoints(0), _numMeshes(0) { }
  ~Md5Model( void );

 public:
  // Internal type definitions
  typedef map<string, Md5Animation *> AnimMap;

 public:
  // Public interface
  bool loadModel( const string &filename );
  void prepare( Md5Skeleton &skel );

  bool addAnim( const string &filename );
  Md5Animation *getAnim( const string &name );

  unsigned int getNumJoints( void ) {
	return _numJoints;
  }

  Md5Skeleton *getBaseSkeleton( void ) {
	return &_baseSkeleton;
  }

  const AnimMap &getAnimList( void ) const {
	return _animList;
  }

  const BoundingBox_t &getBindPoseBoundingBox( void ) const {
	return _bindPoseBox;
  }

  void setMeshRenderState( const string &name, int state ) {
	if( Md5Mesh *mesh = getMeshByName( name ) ) {
	  mesh->setState( state );
	}
  }

  void setMeshDecalMap( const string &name, GLuint id ) {
	if( Md5Mesh *mesh = getMeshByName( name ) ) {
	  mesh->setDecalMap( id );
	}
  }

  void setMeshSpecularMap( const string &name, GLuint id ) {
	if( Md5Mesh *mesh = getMeshByName( name ) ) {
	  mesh->setSpecularMap( id );
	}
  }

  void setMeshNormalMap( const string &name, GLuint id ) {
	if( Md5Mesh *mesh = getMeshByName( name ) ) {
	  mesh->setNormalMap( id );
	}
  }

  void setMeshHeightMap( const string &name, GLuint id ) {
	if( Md5Mesh *mesh = getMeshByName( name ) ) {
	  mesh->setHeightMap( id );
	}
  }

 private:
  // Internal functions
  void computeBindPoseBoundingBox( void );

  // Check if an animation is valid for this model,
  // i.e. anim's skeleton matches with model's skeleton
  bool validityCheck( Md5Animation *anim );

  Md5Mesh *getMeshByName( const string &name );

 private:
  // Member variables
  unsigned int _numJoints;
  unsigned int _numMeshes;

  Md5Skeleton _baseSkeleton;

  vector<Md5Mesh *> _meshes;
  AnimMap _animList;

  BoundingBox_t _bindPoseBox;
};

} // namespace OpenGLMD5Viewer
