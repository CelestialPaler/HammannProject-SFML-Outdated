/***************************************************************************************************/
/*								        		 		   Hammann Project  														   */
/*								        		 	             Hammann     															   */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// Header file
#include "Config.hpp"
#include "Resource.h"

/***************************************************************************************************/
// Class : Hammann
class Hammann
{
	friend class Window;

public:

	Hammann(void);

public:

	void SetCharactor(const std::string & path);
	void Update(void);

private:

	sf::Texture texture;
	sf::Sprite sprite;
};



