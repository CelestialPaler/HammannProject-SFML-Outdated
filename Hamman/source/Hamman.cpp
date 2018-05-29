#include "Hamman.h"

Hamman::Hamman(void)
{
	if (!texture.loadFromFile(hammanTexturePath2))
		std::cerr << "ERROR : Resource not found!" << std::endl;
	else
	{
		sprite.setTexture(texture);
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
		sprite.setScale(sf::Vector2f(1, 1));
		sprite.setPosition(windowWidth / 2, windowHight / 2);
	}
}

void Hamman::ChangeCharactor(const std::string & path)
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

void Hamman::Update(void)
{
	static double angle;
	angle += 0.03;
	if (angle >= 1000000)	angle = 0;
	sprite.move(sf::Vector2f(0, 0.5 * cos(angle)));
}