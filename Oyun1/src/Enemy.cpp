#include "Enemy.h"

Enemy::Enemy(float x, float y, float width, float height)
	:width{width} , height{height}
{
	setOrigin(x / 2, y / 2);
	setSize(sf::Vector2f(x, y));
	renkVer();
	setPos();
}

void Enemy::hareket(float dt)
{
	move(0, 5 * dt * 60);
}

bool Enemy::control(Bullet& bul)
{
	if (getGlobalBounds().intersects(bul.getGlobalBounds()))
		return true;
	
	return false;
}

bool Enemy::control()
{
	if (getPosition().y >= height + getSize().y / 2)
		return true;

	return false;
}

void Enemy::setPos()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(0 + getSize().x / 2, width - getSize().x / 2);
	std::uniform_real_distribution<float> dist1(0 + getSize().y / 2, height/3 - getSize().y / 2);

	setPosition(dist(mt), dist1(mt));
}

void Enemy::renkVer()
{
	srand(time(NULL));

	setFillColor(colors[rand() % 5]);
}
