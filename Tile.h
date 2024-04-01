#pragma once

#include <iostream> //debug
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Tile {

	public:
		Tile();
		Tile(std::string path, sf::Vector2f pos, bool s);
		void render(sf::RenderTexture& t);

		bool solid = false;

		sf::RectangleShape getShape();
		sf::Sprite getSprite();
	private:
		sf::RectangleShape shape;
		sf::Sprite sprite;
		sf::Texture t;
}; 