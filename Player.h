#pragma once

#include "Entity.h"
#include "world.h"

class Player : public Entity{
	public:
		//construtor
		Player();

		//fun��es
		void pollEvents();
		void update(sf::Time delta);
		void render(sf::RenderTexture& t);

		sf::RectangleShape sprite;
		World* world;
	private:
		float speed = 160.f;
		bool getCollision(sf::Time delta);
		sf::Vector2f dir;

};

