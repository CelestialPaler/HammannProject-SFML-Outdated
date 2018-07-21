#pragma once

#include "Config.hpp"
#include "Hammann.h"

class Window
{
public:

	Window(void) = default;

public:

	void Run(void);

private:

	void DefineWindowShape(sf::RenderWindow & _window);

private:

	void WindowConfig(sf::RenderWindow & _window);
	void ResourceConfig(void);

	void EventHandle(sf::RenderWindow & _window);

private:

	void Update(sf::RenderWindow & _window);
	void Clear(sf::RenderWindow & _window);
	void Draw(sf::RenderWindow & _window);
	void Display(sf::RenderWindow & _window);

private:

	std::string title = "Hammann Forever!";
	std::vector<std::string> resourcePath;
	size_t resourceIndex;
	float HammannScale;
	Hammann Hammann;
};
