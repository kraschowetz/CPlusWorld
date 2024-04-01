#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics.hpp>

class Entity {
	public:
		Entity();
		Entity(sf::Vector2f pos);
		sf::Vector2f position;
		//sf::Rect<Entity> collision;

		//get e set
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f pos);

		//normalização de vetores
		sf::Vector2f normalize(sf::Vector2f v);
};