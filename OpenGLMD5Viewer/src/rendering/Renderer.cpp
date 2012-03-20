/*
 * Renderer.cpp
 *
 *  Created on: 5 mars 2012
 *      Author: Administrator
 */

#include "Renderer.h"

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

void Renderer::setIdTexture(GLuint * id)
{
	idTexture = id;
}

GLuint * Renderer::getIdTexture(){
	return idTexture;
}

GLuint * Renderer::loadTexture(QString fileName)					// Creates Texture From A Bitmap File
{
	LPTSTR szFileName = (LPTSTR)fileName.utf16();
	GLuint* texid = new GLuint();
	HBITMAP hBMP;														// Handle Of The Bitmap
	BITMAP	BMP;														// Bitmap Structure

	glGenTextures(1, texid);											// Create The Texture
	hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE );

	if (!hBMP)															// Does The Bitmap Exist?
		return FALSE;													// If Not Return False

	GetObject(hBMP, sizeof(BMP), &BMP);									// Get The Object
																		// hBMP:        Handle To Graphics Object
																		// sizeof(BMP): Size Of Buffer For Object Information
																		// &BMP:        Buffer For Object Information

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);								// Pixel Storage Mode (Word Alignment / 4 Bytes)


	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, *texid);								// Bind To The Texture ID
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Min Filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Mag Filter
	glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); // ( NEW )
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, BMP.bmWidth, BMP.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	DeleteObject(hBMP);													// Delete The Object

	return texid;														// Loading Was Successful
}

} /* namespace OpenGLMD5Viewer */
