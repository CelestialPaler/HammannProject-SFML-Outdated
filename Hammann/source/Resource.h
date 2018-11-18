/***************************************************************************************************/
/*								        		 		  Hammann Project  														      */
/*								        		 	      Resource Manager     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// Header file
#include <mutex>
#include "Config.hpp"
#include "Logger.h"

/***************************************************************************************************/
// Namespace : Core
// Core functionality of the program.
namespace Core
{
	/***************************************************************************************************/
	// Class : Resource Manager
	// Manage all the resources. Run integrity check at initializing state.
	class ResourceManager
	{
	public:
		// Get the pointer of the instance
		/// Singleton
		static ResourceManager * GetInstance(void);
		
	public:
		// Init all the resources.
		void Initialize(void);
		// Query the path of required texture.
		const std::string & GetTexturePath(const std::string & name) const { return textures.find(name)->second; }

	private:
		ResourceManager(void) {}
		// Refused
		ResourceManager(const ResourceManager & _rm) = delete;
		// Refused
		ResourceManager & operator = (const ResourceManager & _rm) = delete;

	private:
		// Load all the resources.
		void LoadResources(void);
		// Check the integrality of the resources.
		bool IntegrityCheck(void) const;
		// Get paths of all the resources in the target folder.
		void GetResourcesPaths(std::string path, std::vector<std::string>& files) const;
		// Log all the details of resources for debugging.
		void LogDetails(void) const;

	private:
		std::map<std::string, std::string> textures;
		std::map<std::string, std::string> sounds;
		std::map<std::string, std::string> texts;
	};
}