/*
 * Renderer.cpp
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#include "Renderer.h"
#include <il.h>
#include <iostream>

namespace OpenGLMD5Viewer {

void Renderer::setCamera(float camX, float camY, float camZ, float targetX, float targetY, float targetZ) {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(camX, camY, camZ, targetX, targetY, targetZ, 0, 1, 0);
}

Renderer::Renderer() {
	// TODO Auto-generated constructor stub

}

Renderer::~Renderer() {
	// TODO Auto-generated destructor stub
}

//GLuint * Renderer::loadTexture(QString fileName)					// Creates Texture From A Bitmap File
//{
//	// TODO find a new texture loader, one that does the job...
//	LPTSTR szFileName = (LPTSTR)fileName.utf16();
//	GLuint* texid = new GLuint();
//	HBITMAP hBMP;														// Handle Of The Bitmap
//	BITMAP	BMP;														// Bitmap Structure
//
//	glGenTextures(1, texid);											// Create The Texture
//	hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE );
//
//	if (!hBMP)															// Does The Bitmap Exist?
//		return FALSE;													// If Not Return False
//
//	GetObject(hBMP, sizeof(BMP), &BMP);									// Get The Object
//																		// hBMP:        Handle To Graphics Object
//																		// sizeof(BMP): Size Of Buffer For Object Information
//																		// &BMP:        Buffer For Object Information
//
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);								// Pixel Storage Mode (Word Alignment / 4 Bytes)
//
//
//	// Typical Texture Generation Using Data From The Bitmap
//	glBindTexture(GL_TEXTURE_2D, *texid);								// Bind To The Texture ID
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Min Filter
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Mag Filter
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
//
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); // ( NEW )
//	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, BMP.bmWidth, BMP.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
//
//	DeleteObject(hBMP);													// Delete The Object
//
//	return texid;														// Loading Was Successful
//}




GLuint * Renderer::loadTexture(string fileName)
{


	 ILuint texid; /* ILuint is a 32bit unsigned integer.
	   Variable texid will be used to store image name. */
	 ILboolean success; /* ILboolean is type similar to GLboolean and can equal GL_FALSE (0) or GL_TRUE (1)
	   it can have different value (because it's just typedef of unsigned char), but this sould be
	   avoided.
	   Variable success will be used to determine if some function returned success or failure. */
	 GLuint * image = new GLuint;

	 if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
	  {
	    /* wrong DevIL version */
		 std::cerr << "wrong DevIL version" << std::endl;
		 return NULL;
	  }

	 ilInit(); /* Initialization of DevIL */
	  ilGenImages(1, &texid); /* Generation of one image name */
	  ilBindImage(texid); /* Binding of image name */
	  success = ilLoadImage((const ILstring)fileName.c_str()); /* Loading of image "image.jpg" */
	  if (success) /* If no error occured: */
	  {
	    success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE); /* Convert every colour component into
	      unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA */
	    if (!success)
	    {
	      /* Error occured */
	    	std::cerr << "error while converting image " << fileName << std::endl;
	      return NULL;
	    }
	    glGenTextures(1, image); /* Texture name generation */
	    glBindTexture(GL_TEXTURE_2D, *image); /* Binding of texture name */
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear
	      interpolation for magnification filter */
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear
	      interpolation for minifying filter */
	    glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
	      ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
	      ilGetData()); /* Texture specification */
	  }
	  else
	  {
	    /* Error occured */
		  std::cerr << "image " << fileName << " did not load" << std::endl;
	    return NULL;
	  }
	  ilDeleteImages(1, &texid); /* Because we have already copied image data into texture data
	    we can release memory used by image. */

	std::cout << "_________________________________________" << std::endl;
	std::cout << "Image loaded" << std::endl;
	std::cout << "	path : " << fileName << std::endl;
	std::cout << "	opengl id : " << *image << std::endl;
	std::cout << "_________________________________________" << std::endl << std::endl;

//	idTexture = new GLuint;
//	*idTexture = *image;
	return image;
}

} /* namespace OpenGLMD5Viewer */
