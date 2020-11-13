#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "Bullet.h"


class Player : public sf::RectangleShape 
{
public:

	Player(float x, float y, float pos_x , float pos_y , const sf::Color& color , float width = 1600 , float height = 900);

	void hareket(const float dt);

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

	void sikma(const float dt, std::list<Bullet>& liste , const sf::RenderWindow& pencere , float& bul_time);

private:
	float width;
	float height;
};

