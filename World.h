#pragma once

#include <iostream> //debug
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Tile.h"

class World {

	public:
		void generateWorld();
		void render(sf::RenderTexture& t, sf::Vector2f viewPos);
		Tile* getTile(sf::Vector2f pos);
		sf::Vector2i getSize();
	private:
		const sf::Vector2i tilesPerScreen = sf::Vector2i(26, 20); //tecnicamente 24x18, os 2 tiles extra são para a renderização de tiles nn ser visivel
		const sf::Vector2i size = sf::Vector2i(32, 32);
		Tile* tiles[32][32];

};