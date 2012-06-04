/*
 * MD5Mesh.h
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#ifndef MD5MESH_H_
#define MD5MESH_H_

#include "Md5Skeleton.h"

#include "common.h"

namespace OpenGLMD5Viewer {

class Md5Mesh
{
 public:
  // Public internal types/enums
  enum {
	kHide = 1, // Skip mesh
	kNoDraw, // Don't draw but prepare vertices
	kShow // Draw mesh
  };

 public:
  // Constructor/Destructor
  Md5Mesh( void )
	: _renderState(kShow), _numVerts(0), _numTris(0), _numWeights(0),
	  _vertexArray(NULL), _normalArray(NULL), _tangentArray(NULL),
	  _texCoordArray(NULL), _vertIndices(NULL), _decal(0), _specMap(0),
	  _normalMap(0), _heightMap(0) { }
  ~Md5Mesh( void );

 public:
  // Public interface
  bool load( std::ifstream &file );
  void setupVertexArrays( Md5Skeleton *skel );
  void setupTexCoordArray( void );
  void computeWeightNormals( Md5Skeleton &skel );
  void computeWeightTangents( Md5Skeleton &skel );
  void computeBoundingBox( Md5Skeleton &skel );
//  void renderVertexArrays( void );
//  void drawNormals( void );

  const string &getName( void ) const {
	return _name;
  }

  const BoundingBox_t &getBoundingBox( void ) const {
	return _BoundingBox;
  }

  // Hide/NoDraw/Show state
  void setState( int state ) {
	_renderState = state;
  }

  // Texture setters
  void setDecalMap( GLuint id ) { _decal = id; }
  void setSpecularMap( GLuint id ) { _specMap = id; }
  void setNormalMap( GLuint id ) { _normalMap = id; }
  void setHeightMap( GLuint id ) { _heightMap = id; }

  GLuint getDecalMap() { return _decal; }
  GLuint getSpecularMap() { return _specMap; }
  GLuint getNormalMap() { return _normalMap; }
  GLuint getHeightMap() { return _heightMap; }

  // Mesh render state
  bool hiden( void ) const { return (_renderState == kHide);  }
  bool noDraw( void ) const { return (_renderState == kNoDraw); }
  bool show( void ) const { return (_renderState == kShow); }

vector<Md5Vertex_t *> getVertexArray()
{
	return _verts;
}

  vector<Md5Triangle_t *> getTriangleArray()
{
	  return _tris;
}

  vector<Md5Weight_t *> getWeightArray()
{
	  return _weights;
}

vec3_t * getFinalVertexArray()
{
	return _vertexArray;
}

GLuint * getFinalVertexIndice()
{
	return _vertIndices;
}

vec2_t * getFinalTexCoordArray()
{
	return _texCoordArray;
}

vec3_t * getFinalNormalArray()
{
	return _normalArray;
}

  void printTriangles();

 private:
  // Internal functions
  void allocVertexArrays( void );
  void freeVertexArrays( void );

  void loadTextures( void );

 private:
  // Member variables
  string _name;
  string _shader;
  int _renderState;

  BoundingBox_t _BoundingBox;

  unsigned int _numVerts;
  unsigned int _numTris;
  unsigned int _numWeights;

  // Original mesh data
  vector<Md5Vertex_t *> _verts;
  vector<Md5Triangle_t *> _tris;
  vector<Md5Weight_t *> _weights;

  // Final mesh data; vertex arrays for fast rendering
  vec3_t *_vertexArray;
  vec3_t *_normalArray;
  vec3_t *_tangentArray;
  vec2_t *_texCoordArray;
  GLuint *_vertIndices;

  // Textures
  GLuint _decal;
  GLuint _specMap;
  GLuint _normalMap;
  GLuint _heightMap;
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5MESH_H_ */
