/***************************************************************************************************/
/*                                               Deep Learning Developing Kit                                                   */
/*								        		 	              Hamman    															   */
/*								        		 	             Config File    															   */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// Header file
#include "Config.hpp"

class Hamman
{
	friend class Window;
public:
	Hamman(void);

public:

	void ChangeCharactor(const std::string & path);
	void Update(void);

private:
	sf::Texture texture;
	sf::Sprite sprite;
};



