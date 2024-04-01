#pragma once

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Tile.h"
#include "World.h"

class Game {
	public:
		//construtores e destrutores
		Game();
		virtual ~Game();

		//funções
		void run();
		void pollEvents();
		void update(sf::Time delta);
		void render();

		//assessores
		const bool isRunning() const;
		const sf::Vector2f getViewPosition();

		//delta
		sf::Time timePerFrame = sf::seconds(1.f / 60.f);

		//objetos
		Player player;
		World world;
	private:
		//janela
		sf::RenderWindow* window;
		sf::RenderTexture renderTexture;
		sf::Event ev;
		sf::View view; //implementar depois
		sf::Vector2f viewPosition;

		//funções
		void initWindow();
};