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
		int i = 0;

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
		player.sikma(dt, bullets , pencere);
		
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
			++i;
		}

		

		//draw
		pencere.clear();

		pencere.draw(player);
		for (Bullet& bul : bullets)
		{
			pencere.draw(bul);
		}

		pencere.display();
		cout << i << endl;
	}

	

	return 0;
}