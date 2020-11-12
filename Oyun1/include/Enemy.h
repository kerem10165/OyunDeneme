#pragma once

#include "SFML/Graphics.hpp"
#include <random>
#include "Bullet.h"

class Enemy : public sf::RectangleShape
{
public:
	Enemy(float x, float y, float width, float height);

	void hareket(float dt);

	float getWidth() const
	{
		return width;
	}

	float getHeight() const
	{
		return height;
	}

	void setWidth(float w)
	{
		width = w;
	}

	void setHeight(float h)
	{
		height = h;
	}

	bool control(Bullet& bul);
	bool control();


private:
	void setPos();
	sf::Color colors[5] = { sf::Color::Yellow, sf::Color::Red , sf::Color::White , sf::Color::Green , sf::Color::Magenta };
	void renkVer();
	float height;
	float width;
};

