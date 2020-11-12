#include <iostream>
#include <list>
#include "SFML\Graphics.hpp"
#include <SFML\Window.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

using std::cout;
using std::endl;

float width = 1600;
float height = 900;
float ana = 150;

float bul_time = 0.f;
extern "C" __declspec(dllexport) unsigned long NvOptimusEnablement = 1;

int main()
{
	sf::RenderWindow pencere(sf::VideoMode(width, height), "oyun");

	pencere.setFramerateLimit(1000);

	Player player(width / 15, width / 15, width / 2 , height - (10*height/ana) - width /30, sf::Color::Blue);

	std::list<Bullet> bullets;

	cout << sizeof(sf::RectangleShape);

	std::list<Enemy> enemys;

	float enemy_time = 0;

	sf::Clock clock;
	float dt;

		
	while (pencere.isOpen())
	{
		sf::Event event;

		while (pencere.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				pencere.close();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				pencere.close();
			}
		}


		//update
		dt = clock.restart().asSeconds();
		player.hareket(dt);
		
		if (bul_time < 5)
			bul_time += 1 * dt * 60;
		else
		{
			player.sikma(dt, bullets, pencere);
			bul_time = 0;
		}

		if (enemy_time < 135)
		
			enemy_time += 1 * 60 * dt;
		else
		{
			enemy_time = 0;
			enemys.emplace_back(60, 60, width, height);
		}
		
		
		std::list<Bullet>::iterator it = bullets.begin();
		std::list<Enemy>::iterator it1 = enemys.begin();

		while (it1 != enemys.end())
		{
			it1->hareket(dt);
			if (it1->control())
			{
				std::list<Enemy>::iterator temp = ++it1;
				enemys.erase(--it1);
				it1 = temp;
				continue;
			}

			++it1;
		}

		while (it != bullets.end())
		{
			it1 = enemys.begin();
			it->hareket(dt);
			if (it->control())
			{
				std::list<Bullet>::iterator temp = ++it;
				bullets.erase(--it);
				it = temp;
				continue;
			}

			while (it1 != enemys.end() && it != bullets.end())
			{
				if (it1->control(*it))
				{
					std::list<Bullet>::iterator temp1 = ++it;
					bullets.erase(--it);
					it = temp1;

					std::list<Enemy>::iterator tempp = ++it1;
					enemys.erase(--it1);
					it1 = tempp;
					continue;
				}

				it1++;
			}

			if (it != bullets.end())
			{
				it++;
			}
		}

		//draw
		pencere.clear();

		pencere.draw(player);
		for (Bullet& bul : bullets)
		{
			pencere.draw(bul);
		}
		for (Enemy& enemy : enemys)
		{
			pencere.draw(enemy);
		}


		pencere.display();
	}

	return 0;
}