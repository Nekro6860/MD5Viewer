/*
 * common.h
 *
 *  Created on: 12 mars 2012
 *      Author: Administrator
 */

#ifndef COMMON_H_
#define COMMON_H_

#ifdef _WIN32
#define	WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif // _WIN32

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <GL/glew.h>

#include "../utils/Mathlib.h"

using std::string;
using std::vector;
using std::map;



namespace OpenGLMD5Viewer {

// Forward declarations
//class Md5Skeleton;
//class Md5Mesh;
//class Md5Model;
//class Md5Animation;
//class Md5Object;


//extern const int kMd5Version;

// OpenGL vector types
typedef GLfloat vec2_t[2];
typedef GLfloat vec3_t[3];
typedef GLfloat vec4_t[4];

struct Md5Joint_t
{
  string name;
  int parent;

  MathUtils::Vector3f pos;
  MathUtils::Quaternionf orient;

  // Provide operator < for depth sorting
  bool operator<( const Md5Joint_t &j ) const {
	return (pos._z < j.pos._z);
  }
};


struct Md5Vertex_t
{
  float st[2]; // Texture coordinates

  int startWeight; // Start index weights
  int countWeight; // Number of weights
};


struct Md5Triangle_t
{
  int index[3]; // Vertex indices
};


struct Md5Weight_t
{
  int joint; // Joint index
  float bias;

  MathUtils::Vector3f pos;
  MathUtils::Vector3f norm;
  MathUtils::Vector3f tan;
};


struct BoundingBox_t {
	MathUtils::Vector3f min;
	MathUtils::Vector3f max;
};


struct OBBox_t {
	MathUtils::Matrix4x4f world;

	MathUtils::Vector3f center;
	MathUtils::Vector3f extent;
};


// Object deletion for containers... We should use a smart
// pointer instead to be exception-safe.
struct DeleteObjectPtr {
  template<typename T>
  void operator()( const T *ptr ) const {
	delete ptr;
  }
};


//const int kMd5Version = 10;

// Shader related global variables
extern GLuint lightProg;
extern bool bShaders;
extern bool bParallax;

} // namespace OpenGLMD5Viewer

#endif /* COMMON_H_ */
