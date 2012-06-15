/*
 * MD5Mesh.cpp
 *
 *  Created on: 6 mars 2012
 *      Author: Administrator
 */

#include <iostream>

#include "Md5Mesh.h"
#include "Md5Skeleton.h"

namespace OpenGLMD5Viewer {

/////////////////////////////////////////////////////////////////////////////
//
// class Md5Mesh implementation.
//
/////////////////////////////////////////////////////////////////////////////


// --------------------------------------------------------------------------
// Md5Mesh::~Md5Mesh
//
// Destructor.  Free all data allocated for the mesh, i.e. vertices,
// triangles, weights and vertex arrays.
// --------------------------------------------------------------------------

Md5Mesh::~Md5Mesh( void )
{
  // Not exception-safe!
//  std::for_each( _verts.begin(), _verts.end(), DeleteObjectPtr() );
//  std::for_each( _tris.begin(), _tris.end(), DeleteObjectPtr() );
//  std::for_each( _weights.begin(), _weights.end(), DeleteObjectPtr() );

  // Free memory allocated for vertex arrays
  freeVertexArrays();
}


// --------------------------------------------------------------------------
// Md5Mesh::load
//
// Load mesh data from a <.md5mesh> file.
// --------------------------------------------------------------------------

bool Md5Mesh::load( std::ifstream &file )
{
  string token, buffer;

  if( !file.is_open() ) {
	return false;
  }


  Md5Triangle_t *fakeTri = new Md5Triangle_t;
  fakeTri->index[0] = 0;
  fakeTri->index[1] = 0;
  fakeTri->index[2] = 0;
  _tris.push_back(fakeTri);

  fakeTri = new Md5Triangle_t;
  fakeTri->index[0] = 0;
  fakeTri->index[1] = 0;
  fakeTri->index[2] = 0;
  _tris.push_back(fakeTri);

  do {
	// Read first token line from file
	file >> token;

	if( token == "shader" ) {
	  file >> _shader;

	  // Remove quote marks from the shader string
	  _shader = _shader.substr( _shader.find_first_of( "\"" ) + 1,
								_shader.find_last_of( "\"" ) - 1 );

	  // Get mesh name from shader string
	  _name = _shader.c_str() + _shader.find_last_of( "/" ) + 1;
	}
	else if( token == "numverts" ) {
	  file >> _numVerts;
	  _verts.reserve( _numVerts );
	}
	else if( token == "numtris" ) {
	  file >> _numTris;
	  _tris.reserve( _numTris );
	}
	else if( token == "numweights" ) {
	  file >> _numWeights;
	  _weights.reserve( _numWeights );
	}
	else if( token == "vert" ) {
	  Md5Vertex_t *v = new Md5Vertex_t;

	  // Read vertex data
	  file >> token; // index
	  file >> token; // "("
	  file >> v->st[0];
	  file >> v->st[1];
	  file >> token; // ")"
	  file >> v->startWeight;
	  file >> v->countWeight;

	  _verts.push_back( v );
	}
	else if( token == "tri" ) {
	  Md5Triangle_t *tri = new Md5Triangle_t;

	  // Read triangle data
	  file >> token; // index
	  file >> tri->index[0];
	  file >> tri->index[1];
	  file >> tri->index[2];

//	  std::cout << " mesh name : " << _name << std::endl;
//	  std::cout << "loading tri.index[0] = " << tri->index[0] << std::endl;
//	  std::cout << "loading tri.index[1] = " << tri->index[1] << std::endl;
//	  std::cout << "loading tri.index[2] = " << tri->index[2] << std::endl << std::endl;

	  _tris.push_back( tri );
	}
	else if( token == "weight" ) {
	  Md5Weight_t *w = new Md5Weight_t;

	  // Read weight data
	  file >> token; // index
	  file >> w->joint;
	  file >> w->bias;
	  file >> token; // "("
	  file >> w->pos._x;
	  file >> w->pos._y;
	  file >> w->pos._z;
	  file >> token; // ")"

	  _weights.push_back( w );
	}

	// Eat up rest of the line
	std::getline( file, buffer );

  } while( (token != "}") && !file.eof() );

  // Memory allocation for vertex arrays
  allocVertexArrays();

  // Setup texture coordinates array
  setupTexCoordArray();

  return true;
}


// --------------------------------------------------------------------------
// Md5Mesh::setupVertexArray
//
// Compute vertices' position, normal and tangent.
// --------------------------------------------------------------------------

void Md5Mesh::setupVertexArrays( Md5Skeleton *skel )
{
  for( unsigned int i = 0; i < _numVerts; ++i ) {
	  MathUtils::Vector3f finalVertex = MathUtils::kZeroVectorf;
	  MathUtils::Vector3f finalNormal = MathUtils::kZeroVectorf;
	  MathUtils::Vector3f finalTangent = MathUtils::kZeroVectorf;

	// Calculate final vertex to draw with weights
	for( int j = 0; j < _verts[i]->countWeight; ++j ) {
	  const Md5Weight_t *pWeight = _weights[ _verts[i]->startWeight + j ];
	  const Md5Joint_t *pJoint = skel->getJoint( pWeight->joint );

	  // Calculate transformed vertex for this weight
	  MathUtils::Vector3f wv = pWeight->pos;
	  pJoint->orient.rotate( wv );

	  // The sum of all pWeight->bias should be 1.0
	  finalVertex += (pJoint->pos + wv) * pWeight->bias;

	  // Calculate transformed normal for this weight
	  MathUtils::Vector3f wn = pWeight->norm;
	  pJoint->orient.rotate( wn );

	  finalNormal += wn * pWeight->bias;

	  // Calculate transformed tangent for this weight
	  MathUtils::Vector3f wt = pWeight->tan;
	  pJoint->orient.rotate( wt );

	  finalTangent += wt * pWeight->bias;
	}

	// We can omit to normalize normal and tangent,
	// because they should have been already normalized
	// when they were computed. We can gain some time
	// avoiding some heavy calculus.

	finalNormal.normalize();
	finalTangent.normalize();

	_vertexArray[i][0] = finalVertex._x;
	_vertexArray[i][1] = finalVertex._y;
	_vertexArray[i][2] = finalVertex._z;

	_normalArray[i][0] = finalNormal._x;
	_normalArray[i][1] = finalNormal._y;
	_normalArray[i][2] = finalNormal._z;

	_tangentArray[i][0] = finalTangent._x;
	_tangentArray[i][1] = finalTangent._y;
	_tangentArray[i][2] = finalTangent._z;
  }
}


// --------------------------------------------------------------------------
// Md5Mesh::setupTexCoordArray
//
// Compute vertices' texture coordinate.
// --------------------------------------------------------------------------

void Md5Mesh::setupTexCoordArray( void )
{
  for( unsigned int i = 0; i < _numVerts; ++i ) {
	_texCoordArray[i][0] = _verts[i]->st[0];
	_texCoordArray[i][1] = 1.0f - _verts[i]->st[1];
  }
}


// --------------------------------------------------------------------------
// Md5Mesh::computeWeightNormals
//
// der_ton said:
//
// * First you have to get the bind-pose model-space normals by calculating
//   them from the model geometry in bind-pose.
//
// * Then you calculate the weight's normal (which is in bone-space) by
//   invert-transforming the normal by the bone-space matrix.
//
// * So afterwards when animating, you'll transform the weight normal with
//   the animated bone-space matrix and add them all up and you'll get
//   back your animated vertex normal.
// --------------------------------------------------------------------------

void Md5Mesh::computeWeightNormals( Md5Skeleton &skel )
{
  vector<MathUtils::Vector3f> bindposeVerts( _numVerts );
  vector<MathUtils::Vector3f> bindposeNorms( _numVerts );

  for( unsigned int i = 0; i < _numVerts; ++i ) {
	// Zero out final vertex position and final vertex normal
	bindposeVerts[i] = MathUtils::kZeroVectorf;
	bindposeNorms[i] = MathUtils::kZeroVectorf;

	for( int j = 0; j < _verts[i]->countWeight; ++j ) {
	  const Md5Weight_t *pWeight = _weights[ _verts[i]->startWeight + j ];
	  const Md5Joint_t *pJoint = skel.getJoint( pWeight->joint );

	  // Calculate transformed vertex for this weight
	  MathUtils::Vector3f wv = pWeight->pos;
	  pJoint->orient.rotate( wv );

	  bindposeVerts[i] += (pJoint->pos + wv) * pWeight->bias;
	}
  }

  // Compute triangle normals
  for( unsigned int i = 0; i < _numTris; ++i ) {
	const Md5Triangle_t *pTri = _tris[i];

	MathUtils::Vector3f triNorm( -ComputeNormal( bindposeVerts[ pTri->index[0] ],
		bindposeVerts[ pTri->index[1] ], bindposeVerts[ pTri->index[2] ] ) );

	for( int j = 0; j < 3; ++j ) {
	  bindposeNorms[ pTri->index[j] ] += triNorm;
	}
  }

  // "Average" the surface normals, by normalizing them
  for( unsigned int i = 0; i < _numVerts; ++i ) {
	bindposeNorms[i].normalize();
  }

  //
  // At this stage we have all vertex normals computed
  // for the model geometry in bind-pos
  //

  // Zero out all weight normals
  for( unsigned int i = 0; i < _numWeights; ++i ) {
	_weights[i]->norm = MathUtils::kZeroVectorf;
  }

  // Compute weight normals by invert-transforming the normal
  // by the bone-space matrix
  for( unsigned int i = 0; i < _numVerts; ++i ) {
	for( int j = 0; j < _verts[i]->countWeight; ++j ) {
	  Md5Weight_t *pWeight = _weights[ _verts[i]->startWeight + j ];
	  const Md5Joint_t *pJoint = skel.getJoint( pWeight->joint );

	  MathUtils::Vector3f wn = bindposeNorms[i];

	  // Compute inverse quaternion rotation
	  MathUtils::Quaternionf invRot = Inverse( pJoint->orient );
	  invRot.rotate( wn );

	  pWeight->norm += wn;
	}
  }

  // Normalize all weight normals
  for( unsigned int i = 0; i < _numWeights; ++i ) {
	_weights[i]->norm.normalize();
  }
}


// --------------------------------------------------------------------------
// Md5Mesh::computeWeightTangents
//
// Compute per-vertex tangent vectors and then, calculate the weight
// tangent.
// --------------------------------------------------------------------------

void Md5Mesh::computeWeightTangents( Md5Skeleton &skel )
{
  vector<MathUtils::Vector3f> bindposeVerts( _numVerts );
  vector<MathUtils::Vector3f> bindposeNorms( _numVerts );
  vector<MathUtils::Vector3f> bindposeTans( _numVerts );

  vector<MathUtils::Vector3f> sTan( _numVerts );
  vector<MathUtils::Vector3f> tTan( _numVerts );

  // Zero out all weight tangents (thank you Valgrind :s)
  for( unsigned int i = 0; i < _numWeights; ++i ) {
	_weights[i]->tan = MathUtils::kZeroVectorf;
  }

  // Compute bind-pose vertices and normals
  for( unsigned int i = 0; i < _numVerts; ++i ) {
	// Zero out final vertex position, normal and tangent
	bindposeVerts[i] = MathUtils::kZeroVectorf;
	bindposeNorms[i] = MathUtils::kZeroVectorf;
	bindposeTans[i] = MathUtils::kZeroVectorf;

	// Zero s-tangents and t-tangents
	sTan[i] = MathUtils::kZeroVectorf;
	tTan[i] = MathUtils::kZeroVectorf;

	for( int j = 0; j < _verts[i]->countWeight; ++j ) {
	  const Md5Weight_t *pWeight = _weights[ _verts[i]->startWeight + j ];
	  const Md5Joint_t *pJoint = skel.getJoint( pWeight->joint );

	  // Calculate transformed vertex for this weight
	  MathUtils::Vector3f wv = pWeight->pos;
	  pJoint->orient.rotate( wv );

	  bindposeVerts[i] += (pJoint->pos + wv) * pWeight->bias;

	  // Calculate transformed normal for this weight
	  MathUtils::Vector3f wn = pWeight->norm;
	  pJoint->orient.rotate( wn );

	  bindposeNorms[i] += wn * pWeight->bias;
	}
  }

  // Calculate s-tangeants and t-tangeants at triangle level
  for( unsigned int i = 0; i < _numTris; ++i ) {
	const Md5Triangle_t *pTri = _tris[i];

	const MathUtils::Vector3f &v0 = bindposeVerts[ pTri->index[0] ];
	const MathUtils::Vector3f &v1 = bindposeVerts[ pTri->index[1] ];
	const MathUtils::Vector3f &v2 = bindposeVerts[ pTri->index[2] ];

	const vec2_t &w0 = _verts[ pTri->index[0] ]->st;
	const vec2_t &w1 = _verts[ pTri->index[1] ]->st;
	const vec2_t &w2 = _verts[ pTri->index[2] ]->st;

	float x1 = v1._x - v0._x;
	float x2 = v2._x - v0._x;
	float y1 = v1._y - v0._y;
	float y2 = v2._y - v0._y;
	float z1 = v1._z - v0._z;
	float z2 = v2._z - v0._z;

	float s1 = w1[0] - w0[0];
	float s2 = w2[0] - w0[0];
	float t1 = w1[1] - w0[1];
	float t2 = w2[1] - w0[1];

	float r = s1 * t2 - s2 * t1;

	if( r == 0.0f ) {
	  // Prevent division by zero
	  r = 1.0f;
	}

	float oneOverR = 1.0f / r;

	MathUtils::Vector3f sDir( (t2 * x1 - t1 * x2) * oneOverR,
				   (t2 * y1 - t1 * y2) * oneOverR,
				   (t2 * z1 - t1 * z2) * oneOverR );
	MathUtils::Vector3f tDir( (s1 * x2 - s2 * x1) * oneOverR,
				   (s1 * y2 - s2 * y1) * oneOverR,
				   (s1 * z2 - s2 * z1) * oneOverR );

	for( unsigned int j = 0; j < 3; ++j ) {
	  sTan[ pTri->index[j] ] += sDir;
	  tTan[ pTri->index[j] ] += tDir;
	}
  }

  // Calculate vertex tangent
  for( unsigned int i = 0; i < _numVerts; ++i ) {
	const MathUtils::Vector3f &n = bindposeNorms[i];
	const MathUtils::Vector3f &t = sTan[i];

	// Gram-Schmidt orthogonalize
	bindposeTans[i] = (t - n * DotProduct( n, t ));
	bindposeTans[i].normalize();

	// Calculate handedness
	if( DotProduct( CrossProduct( n, t ), tTan[i] ) < 0.0f ) {
	  bindposeTans[i] = -bindposeTans[i];
	}

	// Compute weight tangent
	for( int j = 0; j < _verts[i]->countWeight; ++j ) {
	  Md5Weight_t *pWeight = _weights[ _verts[i]->startWeight + j ];
	  const Md5Joint_t *pJoint = skel.getJoint( pWeight->joint );

	  MathUtils::Vector3f wt = bindposeTans[i];

	  // Compute inverse quaternion rotation
	  MathUtils::Quaternionf invRot = Inverse( pJoint->orient );
	  invRot.rotate( wt );

	  pWeight->tan += wt;
	}
  }

  // Normalize all weight tangents
  for( unsigned int i = 0; i < _numWeights; ++i ) {
	_weights[i]->tan.normalize();
  }
}


// --------------------------------------------------------------------------
// Md5Mesh::computeBoundingBox
//
// Compute mesh bounding box for a given skeleton.
// --------------------------------------------------------------------------

void Md5Mesh::computeBoundingBox( Md5Skeleton &skel )
{
	MathUtils::Vector3f max( -99999.0f, -99999.0f, -99999.0f );
	MathUtils::Vector3f min(  99999.0f,  99999.0f,  99999.0f );

  for( unsigned int i = 0; i < _numVerts; ++i ) {
	  MathUtils::Vector3f finalVertex = MathUtils::kZeroVectorf;

	// Calculate final vertex to draw with weights
	for( int j = 0; j < _verts[i]->countWeight; ++j ) {
	  const Md5Weight_t *pWeight = _weights[ _verts[i]->startWeight + j ];
	  const Md5Joint_t *pJoint = skel.getJoint( pWeight->joint );

	  // Calculate transformed vertex for this weight
	  MathUtils::Vector3f wv = pWeight->pos;
	  pJoint->orient.rotate( wv );

	  // The sum of all pWeight->bias should be 1.0
	  finalVertex += (pJoint->pos + wv) * pWeight->bias;
	}

	if( finalVertex._x > max._x ) {
	  max._x = finalVertex._x;
	}

	if( finalVertex._x < min._x ) {
	  min._x = finalVertex._x;
	}

	if( finalVertex._y > max._y ) {
	  max._y = finalVertex._y;
	}

	if( finalVertex._y < min._y ) {
	  min._y = finalVertex._y;
	}

	if( finalVertex._z > max._z ) {
	  max._z = finalVertex._z;
	}

	if( finalVertex._z < min._z ) {
	  min._z = finalVertex._z;
	}
  }

  _BoundingBox.min = min;
  _BoundingBox.max = max;
}


// --------------------------------------------------------------------------
// Md5Mesh::allocVertexArray
//
// Allocate memory for vertex array.
// --------------------------------------------------------------------------

void Md5Mesh::allocVertexArrays( void )
{
  _vertexArray = new vec3_t[ _numVerts ];
  _normalArray = new vec3_t[ _numVerts ];
  _tangentArray = new vec3_t[ _numVerts ];
  _texCoordArray = new vec2_t[ _numVerts ];
  _vertIndices = new GLuint[ _numTris * 3 ];

  // We can already initialize the vertex index array (we won't have
  // to do it each time we want to draw!)
  for( unsigned int k = 0, i = 0; i < _numTris; ++i ) {
	for( int j = 0; j < 3; ++j, ++k ) {
	  _vertIndices[k] = _tris[i]->index[j];
	}
  }
}


// --------------------------------------------------------------------------
// Md5Mesh::freeVertexArray
//
// Free allocated memory for vertex array.
// --------------------------------------------------------------------------

void Md5Mesh::freeVertexArrays( void )
{
  if( _vertexArray ) {
	delete [] _vertexArray;
	_vertexArray = NULL;
  }

  if( _normalArray ) {
	delete [] _normalArray;
	_normalArray = NULL;
  }

  if( _tangentArray ) {
	delete [] _tangentArray;
	_tangentArray = NULL;
  }

  if( _texCoordArray ) {
	delete [] _texCoordArray;
	_texCoordArray = NULL;
  }

  if( _vertIndices ) {
	delete [] _vertIndices;
	_vertIndices = NULL;
  }
}

void Md5Mesh::printTriangles()
{
	std::cout << "Mesh name : " << _name << std::endl;
//	for()
//	{
//
//	}
}

} /* namespace OpenGLMD5Viewer */
