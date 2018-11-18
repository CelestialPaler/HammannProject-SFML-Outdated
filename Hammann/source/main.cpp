/***************************************************************************************************/
/*                                               Deep Learning Developing Kit                                                   */
/*								        		 	              Hammann    															   */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/

#include "Config.hpp"
#include "Resource.h"
#include "Logger.h"

// Entry point for Debug mode.
int main()
{
	Util::Logger * logger = Util::Logger::GetInstance();
	logger->Start(Util::Logger::DEBUG);
	logger->Write(Util::Logger::INFO,"Logger initialize OK.");

	Core::ResourceManager * resourceManager = Core::ResourceManager::GetInstance();
	resourceManager->Initialize();

	//Window window;
	//sf::Thread windowRender(&Window::Run, &window);
	//windowRender.launch();

	//sf::SoundBuffer buffer;
	//if (!buffer.loadFromFile(HammannAudioPath1))
	//	return -1;
	//sf::Sound test;
	//test.setBuffer(buffer);
	//test.play();

	return 0;
}

// Entry point for Release mode.
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	//Window window;
	//sf::Thread windowRender(&Window::Run, &window);
	//windowRender.launch();
	return 0;
}
