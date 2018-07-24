/***************************************************************************************************/
/*								        		 		 Hammann Project  														   */
/*								        		 	           Hammann     															   */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Hammann.h"

Hammann::Hammann(void)
{
	ResourceManager testManager;

	sf::Texture tempTexture;
	std::cout << testManager.GetTexturePath("hammann_g.png") << std::endl;
	if (!tempTexture.loadFromFile(HammannTexturePath1))
		std::cerr << "ERROR : Resource not found!" << std::endl;

	sprite.setTexture(tempTexture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(sf::Vector2f(1, 1));
	sprite.setPosition(windowWidth / 2, windowHight / 2);
}

void Hammann::ChangeCharactor(const std::string & path)
{
	if (!texture.loadFromFile(path))
		std::cerr << "ERROR : Resource not found!" << std::endl;
	else
	{
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(1, 1));
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