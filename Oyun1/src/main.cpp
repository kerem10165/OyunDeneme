#include <iostream>
#include <list>
#include "SFML\Graphics.hpp"
#include <SFML\Window.hpp>
#include "Player.h"
#include "Bullet.h"

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

	//pencere.setFramerateLimit(60);

	Player player(width / 15, width / 15, width / 2 , height - (10*height/ana) - width /30, sf::Color::Blue);

	std::list<Bullet> bullets;

	
	
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
		
		
		std::list<Bullet>::iterator it = bullets.begin();

		while (it != bullets.end())
		{
			it->hareket(dt);
			if (it->control())
			{
				std::list<Bullet>::iterator temp = ++it;
				bullets.erase(--it);
				it = temp;
				continue;
			}

			++it;
		}

		

		//draw
		pencere.clear();

		pencere.draw(player);
		for (Bullet& bul : bullets)
		{
			pencere.draw(bul);
		}


		pencere.display();
	}

	return 0;
}