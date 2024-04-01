#include "Game.h"

Game::Game(){
	window = nullptr;
	initWindow();
	renderTexture.create(window->getSize().x, window->getSize().y);

	world.generateWorld();
	player.world = &this->world;
}

Game::~Game(){
	delete this->window;
}

void Game::run(){
	float lastTime = 0;

	sf::Clock clock;
	sf::Clock frameRateClock;
	sf::Time timeSincelastUpdate = sf::Time::Zero;

	while (isRunning()){
		pollEvents();

		timeSincelastUpdate += clock.restart();

		while (timeSincelastUpdate > timePerFrame) {

			timeSincelastUpdate -= timePerFrame;
			pollEvents();

			update(timePerFrame);
		}

		//fps shenanigans
		float currentTime = frameRateClock.restart().asSeconds();
		float fps = 1.f / currentTime;
		lastTime = currentTime;
		//std::cout << "FPS: " << fps << "\n";
		//end of fps shenanigans

		render();
	}
}

void Game::pollEvents(){
	while (window->pollEvent(ev)) {

		player.pollEvents();

		switch (ev.type) {
			case sf::Event::Closed:
				window->close();
				break;
		}
	}
}

void Game::update(sf::Time delta){
	player.update(delta);
	view.setCenter(player.position);
}

void Game::render(){
	//limpar jabela
	window->clear();
	renderTexture.clear();

	renderTexture.setView(view);

	//renderizar objetos
	world.render(renderTexture, player.getPosition());
	player.render(renderTexture);

	//exibir RenderTexture
	renderTexture.display();
	sf::Sprite renderSprite(renderTexture.getTexture());

	//desenhar RenderTexture na tela
	window->draw(renderSprite);

	//atualizar janela
	window->display();
}

void Game::initWindow(){
	window = new sf::RenderWindow(sf::VideoMode(768, 576), "Game");
	window->setFramerateLimit(60.f);
	view.reset(sf::FloatRect(0.f, 0.f, 768.f, 576.f));
}

const bool Game::isRunning() const{
	return window->isOpen();
}

const sf::Vector2f Game::getViewPosition()
{
	return viewPosition;
}
