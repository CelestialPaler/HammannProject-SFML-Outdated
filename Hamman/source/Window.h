#pragma once

#include "Config.hpp"
#include "Hamman.h"

class Window
{
public:
	Window(void) = default;
public:
	void WindowConfig(sf::RenderWindow & _window);
	void Run(void);
	void Update(sf::RenderWindow & _window);
	void Clear(sf::RenderWindow & _window);
	void Draw(sf::RenderWindow & _window);
	void Display(sf::RenderWindow & _window);

public:
	void EventHandle(sf::RenderWindow & _window);

private:
	void DefineWindowShape(sf::RenderWindow & _window);
private:
	std::string title = "Hamman Forever!";
	Hamman hamman;
};

