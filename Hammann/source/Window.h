/*
	Project Name : Hammann Project

	Copyright © 2015-2018 Celestial Tech Inc.     
*/                                     

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
	void RefreshShape(sf::RenderWindow & _window);

private:

	void WindowConfig(sf::RenderWindow & _window);
	void ResourceConfig(void);

private:

	void Update(sf::RenderWindow & _window);
	void Clear(sf::RenderWindow & _window);
	void Draw(sf::RenderWindow & _window);
	void Display(sf::RenderWindow & _window);
	void EventHandle(sf::RenderWindow & _window);

private:

	std::string title = "Hammann Forever!";
	std::vector<std::string> resourcePath;
	Hammann Hammann;
	ResourceManager ResourceManager;
};
