#include "Player.h"
#include <math.h>
#include <iostream>

Player::Player(float x, float y, float pos_x, float pos_y, const sf::Color& color , float width , float height)
	: RectangleShape(sf::Vector2f(x, y))
{
	setOrigin(x/2, y/2);
	setFillColor(color);
	setPosition(pos_x, pos_y);
	this->width = width;
	this->height = height;
}

void Player::hareket(const float dt)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && RectangleShape::getPosition().x >= 0 + RectangleShape::getSize().x / 2)
	{
		move(-9 * dt * 60.0, 0);
	}

	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && RectangleShape::getPosition().x <= width - RectangleShape::getSize().x / 2)
	{
		move(+9 * dt * 60.0, 0);
	}
}



void Player::sikma(const float dt, std::list<Bullet>& liste , const sf::RenderWindow& pencere , float& bul_time)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && bul_time >= 14)
	{
		Bullet bul(getSize().x / 8, getPosition().x, getPosition().y, width, height);
		int mouseX{ sf::Mouse::getPosition(pencere).x };
		int mouseY{ sf::Mouse::getPosition(pencere).y };
		int dist = sqrt(pow(getPosition().x - mouseX, 2) + pow(getPosition().y - mouseY, 2));
		bul.setDirX((mouseX - getPosition().x ) / dist);
		bul.setDirY((mouseY - getPosition().y) / dist);
		liste.push_back(std::move(bul));
		bul_time = 0;
	}
}
