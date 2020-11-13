#include "Bullet.h"
#include <stdlib.h>
#include <time.h>

Bullet::Bullet(float rad, float x, float y, float width, float height)
	:sf::CircleShape(rad, 56) , width{width} , height{height}
{
	setOrigin(rad , rad);
	setPosition(x, y);
	renkVer();
}

void Bullet::hareket(float dt)
{
	move(dir_x * dt * 60 * 17, dir_y * dt * 60 * 17);
}

bool Bullet::control()
{
	if (getPosition().x <= 0 - getRadius())
		return true;


	else if (getPosition().x >= width + getRadius())
		return true;

	else if (getPosition().y <= 0 - getRadius())
		return true;

	else if (getPosition().y >= height + getRadius())
		return true;

	return false;
}

void Bullet::renkVer()
{
	srand(time(NULL));

	setFillColor(colors[rand() % 5]);
}
