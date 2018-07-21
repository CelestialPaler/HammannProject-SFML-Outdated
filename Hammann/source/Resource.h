/***************************************************************************************************/
/*								        		 		  Hammann Project  														      */
/*								        		 	      Resource Manager     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// Header file
#include "Config.hpp"

/***************************************************************************************************/
// Class : Resource Manager
class ResourceManager
{
public:

	ResourceManager(void);

public:


private:

	void GetResourcesPath(std::string path, std::vector<std::string>& files) const
	{
		// Debug Info
		std::cout << "=> Loading resources" << std::endl;
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

private:

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sound> sounds;
	std::map<std::string, sf::Music> musics;
};



