/***************************************************************************************************/
/*								        		 		  Hammann Project  														      */
/*								        		 	      Resource Manager     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Resource.h"

ResourceManager::ResourceManager(void)
{

}

void ResourceManager::Init(void)
{
	LoadResources();
	PrintAllResources();

	if (IntegralityCheck())
	{
		std::cout << "INFO: Integrality Check OK!" << std::endl;
	}
	else
	{
		std::cout << "ERROR: Integrality Check Failure!" << std::endl;
	}
}

void ResourceManager::LoadResources(void)
{
	// Find all the textures
	std::string texturePath = ResourcePathRoot + "//textures";
	std::vector<std::string> textureNames;
	GetResourcesPaths(texturePath, textureNames);

	// Find all the soundtracks
	std::string soundPath = ResourcePathRoot + "//sounds";
	std::vector<std::string> soundNames;
	GetResourcesPaths(soundPath, soundNames);

	// Find all the plaintexts
	std::string textPath = ResourcePathRoot + "//texts";
	std::vector<std::string> textNames;
	GetResourcesPaths(textPath, textNames);

	for (auto name : textureNames)
		this->textures.insert(std::pair<std::string, std::string>(name, texturePath + "//" + name));
	for (auto name : soundNames)
		this->sounds.insert(std::pair<std::string, std::string>(name, soundPath + "//" + name));
	for (auto name : textNames)
		this->texts.insert(std::pair<std::string, std::string>(name, textPath + "//" + name));
}

bool ResourceManager::IntegralityCheck(void)
{
	return true;
}

void ResourceManager::GetResourcesPaths(std::string path, std::vector<std::string>& files) const
{
	// Create a handle of file
	intptr_t  hFile;
	// Struct for save infomation of files
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if (!(fileinfo.attrib &  _A_SUBDIR))
				files.push_back(fileinfo.name);
		} while (!_findnext(hFile, &fileinfo));
		_findclose(hFile);
	}
}

void ResourceManager::PrintAllResources(void) const
{
	std::cout << "INFO: Loading textures" << std::endl;
	for (auto name : textures)
		std::cout << "	" << name.second << std::endl;
	std::cout << "INFO: Loading sounds" << std::endl;
	for (auto name : sounds)
		std::cout << "	" << name.second << std::endl;
	std::cout << "INFO: Loading texts" << std::endl;
	for (auto name : texts)
		std::cout << "	" << name.second << std::endl;
}
