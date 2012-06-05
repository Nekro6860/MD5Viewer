/*
 * Md5iReader.h
 *
 *  Created on: 1 juin 2012
 *      Author: Administrator
 */

#ifndef MD5IREADER_H_
#define MD5IREADER_H_

#include "Md5Model.h"
#include <string>

namespace OpenGLMD5Viewer {

class Md5iReader {
public:
	Md5iReader();
	virtual ~Md5iReader();

	static Md5Model * loadFromMd5i(string md5iFilePath);
	static void printMeshesNamesFromMd5(string md5FilePath);
};

} /* namespace OpenGLMD5Viewer */
#endif /* MD5IREADER_H_ */
