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

	// Init all the resources.
	void Init(void);
	// Query the path of required texture.
	const std::string & GetTexturePath(const std::string & name) const { return textures.find(name)->second; }

private:

	// Load all the resources.
	void LoadResources(void);
	// Check the integrality of the resources.
	bool IntegralityCheck(void);
	// Get paths of all the resources in the target folder.
	void GetResourcesPaths(std::string path, std::vector<std::string>& files) const;
	// Print all the resources for debugging.
	void PrintAllResources(void) const;

private:

	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> sounds;
	std::map<std::string, std::string> texts;
};



