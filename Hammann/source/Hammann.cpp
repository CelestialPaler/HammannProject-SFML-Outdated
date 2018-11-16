/***************************************************************************************************/
/*								        		 		 Hammann Project  														      */
/*								        		 	           Hammann     															      */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Hammann.h"

Hammann::Hammann(void)
{
	
}

void Hammann::SetCharactor(const std::string & path)
{
	if (!texture.loadFromFile(path))
		std::cerr << "ERROR : Resource not found!" << std::endl;
	else
	{
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.3, 0.3));
		sprite.setPosition(windowWidth / 2, windowHight / 2);
	}
}

void Hammann::Update(void)
{
	static double angle;
	angle += 0.03;
	if (angle >= 1000000)	angle = 0;
	sprite.move(sf::Vector2f(0, 0.5 * cos(angle)));
}