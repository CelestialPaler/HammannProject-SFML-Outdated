/***************************************************************************************************/
/*								        		 		  Hammann Project  														      */
/*								        		 	      Resource Manager     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Resource.h"

std::mutex mutexResource;
static Core::ResourceManager * instancePointer;

Core::ResourceManager * Core::ResourceManager::GetInstance(void)
{
	mutexResource.lock();
	if (instancePointer == nullptr)
		instancePointer = new ResourceManager();
	mutexResource.unlock();
	return instancePointer;
}

void Core::ResourceManager::Initialize(void)
{
	Util::Logger * logger = Util::Logger::GetInstance();
	LoadResources();
	if (LogResourceFileDetail)
		LogDetails();

	if (IntegrityCheck())
		logger->Write(Util::Logger::INFO, "Resource Integrity Check - OK!");
	else
		logger->Write(Util::Logger::WARNING, "Resource Integrity Check - Failed!");
}

void Core::ResourceManager::LoadResources(void)
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

bool Core::ResourceManager::IntegrityCheck(void) const
{
	return true;
}

void Core::ResourceManager::GetResourcesPaths(std::string path, std::vector<std::string>& files) const
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

void Core::ResourceManager::LogDetails(void) const
{
	Util::Logger * logger = Util::Logger::GetInstance();

	logger->Write(Util::Logger::INFO, "Loading textures.");
	for (auto name : textures)
		logger->Write(Util::Logger::DEBUG, name.second);
	logger->Write(Util::Logger::INFO, "Loading sounds.");
	for (auto name : sounds)
		logger->Write(Util::Logger::DEBUG, name.second);
	logger->Write(Util::Logger::INFO, "Loading texts.");
	for (auto name : texts)
		logger->Write(Util::Logger::DEBUG, name.second);
}
