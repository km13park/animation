#include <SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(512, 512), "SFML Tutorial", Style::Close | Style::Resize);
	RectangleShape player(Vector2f(100.0f, 150.0f));
	player.setPosition(206.0f, 206.0f);
	Texture playerTexture;
	playerTexture.loadFromFile("tux_from_linux.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, Vector2u(3, 9), 0.3f);

	float deltaTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);
		window.clear(Color(150, 150, 150));
		window.draw(player);
		window.display();
	}

}