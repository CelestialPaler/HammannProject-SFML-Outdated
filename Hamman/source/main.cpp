/***************************************************************************************************/
/*                                               Deep Learning Developing Kit                                                   */
/*								        		 	              Hamman    															   */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/

#include "Config.hpp"
#include "Window.h"

int main()
{
	Window window;
	sf::Thread windowRender(&Window::Run, &window);
	windowRender.launch();
	return 0;
}
