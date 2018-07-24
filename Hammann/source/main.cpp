/***************************************************************************************************/
/*                                               Deep Learning Developing Kit                                                   */
/*								        		 	              Hammann    															   */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/

#include "Config.hpp"
#include "Window.h"
#include "Resource.h"

// Entry point for Debug mode.
int main()
{
	//Window window;
	//sf::Thread windowRender(&Window::Run, &window);
	//windowRender.launch();

	//sf::SoundBuffer buffer;
	//if (!buffer.loadFromFile(HammannAudioPath1))
	//	return -1;
	//sf::Sound test;
	//test.setBuffer(buffer);
	//test.play();
	ResourceManager testManager;
	testManager.Init();
	
	system("pause");
	return 0;
}

// Entry point for Release mode.
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	Window window;
	sf::Thread windowRender(&Window::Run, &window);
	windowRender.launch();
	return 0;
}
