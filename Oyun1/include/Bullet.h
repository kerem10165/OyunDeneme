#pragma once

#include <SFML/Graphics.hpp>


class Bullet : public sf::CircleShape
{
public:
	Bullet(float rad, float x, float y, float width = 1600, float height = 900);

	void hareket(float dt);

	bool control();

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

	float getDirectionX() const
	{
		return dir_x;
	}

	float getDirectionY() const
	{
		return dir_y;
	}


	void setDirX(float dir)
	{
		dir_x = dir;
	}

	void setDirY(float dir)
	{
		dir_y = dir;
	}

private:
	void renkVer();
	sf::Color colors[5] = { sf::Color::Yellow, sf::Color::Red , sf::Color::White , sf::Color::Green , sf::Color::Magenta};
	float width;
	float height;
	float dir_x;
	float dir_y;
};

