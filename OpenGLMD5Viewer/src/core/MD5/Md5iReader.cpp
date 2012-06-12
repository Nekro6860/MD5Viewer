/*
 * Md5iReader.cpp
 *
 *  Created on: 1 juin 2012
 *      Author: Administrator
 */

#include "Md5iReader.h"
#include "Md5Mesh.h"
#include "../../rendering/Renderer.h"

#include <iostream>
#include <fstream>

namespace OpenGLMD5Viewer {

Md5iReader::Md5iReader() {
	// TODO Auto-generated constructor stub

}

Md5iReader::~Md5iReader() {
	// TODO Auto-generated destructor stub
}

Md5Model * Md5iReader::loadFromMd5i(string md5iFilePath)
{
	Md5Model * model = new Md5Model;
	Md5Mesh * actualMesh;
	string md5ModelFilePath;
	string line;
	string tempMeshName;
	string tempMapName;
	string tempMapPath;
	std::ifstream fileContent(md5iFilePath.c_str());

	if(fileContent.is_open())
	{
		std::getline(fileContent, line);

		if(std::string::npos != line.find("model"))
		{

			line.erase(0, line.find_first_not_of(' ', 5)); // Extract the local path of the md5 model file
			string tempGlobalPath = md5iFilePath;
			tempGlobalPath.erase(tempGlobalPath.find_last_of('/') + 1, tempGlobalPath.size());// Suppress the name of the md5i file from the path to get the global folder path
			md5ModelFilePath = tempGlobalPath + line; // Adds the local file path to the global folder path
			std::cout << "md5ModelFilePath : " << md5ModelFilePath << std::endl;

			if(model->loadModel(md5ModelFilePath))
			{
				model->printfMeshNames();
				std::cout << std::endl << std::endl;
				while(fileContent.good())
				{
					std::getline(fileContent, line);
					if(std::string::npos != line.find("mesh"))
					{
//						std::cout << "mesh found !" << std::endl;
						line.erase(0, line.find_first_not_of(' ', 4));

						tempMeshName = line.substr(0, line.find_first_of(' ', 0)); // Extracting the name of the mesh with which the texture path will be associated
						std::cout << "tempMeshName : " << tempMeshName << std::endl;

						line.erase(0, line.find_first_not_of(' ', tempMeshName.size()));

						tempMapName = line.substr(0, line.find_first_of(' ', 0)); // Extracting the name of the map with which the texture path will be associated
						std::cout << "tempMapName : " << tempMapName << std::endl;

						line.erase(0, line.find_first_not_of(' ', tempMapName.size()));

						tempMapPath = line;
						std::cout << "tempMapPath : " << tempMapPath << std::endl;

						actualMesh = model->getMeshByName(tempMeshName); // Trying to find the corresponding mesh in the model
						if(actualMesh)
						{
							tempMapPath = tempGlobalPath + tempMapPath;
//							std::cout << "tempMapPath : " << tempMapPath << std::endl;

							if(std::string::npos != tempMapName.find("colorMap"))
							{
								actualMesh->setDecalMap(*Renderer::loadTexture(tempMapPath));
//								std::cout << "decal id : " << actualMesh->getDecalMap() << std::endl;
							}
							if(std::string::npos != tempMapName.find("specMap"))
							{
								actualMesh->setSpecularMap(*Renderer::loadTexture(tempMapPath));
//								std::cout << "specular id : " << actualMesh->getSpecularMap() << std::endl;
							}
							if(std::string::npos != tempMapName.find("normalMap"))
							{
								actualMesh->setNormalMap(*Renderer::loadTexture(tempMapPath));
//								std::cout << "normal id : " << actualMesh->getNormalMap() << std::endl;
							}
							if(std::string::npos != tempMapName.find("heightMap"))
							{
								actualMesh->setHeightMap(*Renderer::loadTexture(tempMapPath));
//								std::cout << "height id : " << actualMesh->getHeightMap() << std::endl;
							}

						}
						else
						{
							std::cerr << "the mesh " << tempMeshName << " does not exist in model " << md5ModelFilePath << std::endl;
						}
					}
				}
				return model;
			}
			else
			{
				std::cerr << "model failed to load" << std::endl;
				std::cerr << "	from md5i file : " << md5iFilePath << std::endl;
				std::cerr << "	extracted path : " << md5ModelFilePath << std::endl;
			}

		}
		else
		{
			std::cerr << "Model path not correctly indicated in " << md5iFilePath << std::endl;
		}
	}
	else std::cerr << "Unable to open file " << md5iFilePath << std::endl;


	return NULL;
}

} /* namespace OpenGLMD5Viewer */
