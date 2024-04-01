#include "Player.h"

Player::Player(){
	sprite.setSize(sf::Vector2f(30.f, 30.f));
	sprite.setFillColor(sf::Color::White);
}

void Player::pollEvents(){
	dir = sf::Vector2f(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir.x += -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir.x += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir.y += -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir.y += 1;
	}
}

void Player::update(sf::Time delta){
	if(!getCollision(delta))
		position += normalize(dir) * speed * delta.asSeconds();

	sprite.setPosition(position);
}

void Player::render(sf::RenderTexture& t){
	t.draw(sprite);
}

bool Player::getCollision(sf::Time delta){
	if ((position + dir).x< 1 || (position + dir).y < 1) {
		return true;
	}
	if ((position + dir).x == world->getSize().x * 32 || (position + dir).y == world->getSize().y * 32) {
		return true;
	}
	for (int x = -1; x < 2; x++) {
		for (int y = -1; y < 2; y++) {
			//tile validations
			if ((position + sf::Vector2f(x * 32.f, y * 32.f)).x < 0) { continue; }
			if ((position + sf::Vector2f(x * 32.f, y * 32.f)).y < 0) { continue; }
			if ((position + sf::Vector2f(x * 32.f, y * 32.f)).x >= world->getSize().x * 32) { continue; }
			if ((position + sf::Vector2f(x * 32.f, y * 32.f)).y >= world->getSize().y * 32) { continue; }

			if (sprite.getGlobalBounds().intersects(
				world->getTile(position + sf::Vector2f(x * 32.f, y * 32.f))->getSprite().getGlobalBounds())
				&& world->getTile(position + sf::Vector2f(x * 32.f, y * 32.f))->solid)
			{
				sf::Vector2f pushDir = position - world->getTile(position + sf::Vector2f(x * 32.f, y * 32.f))->getSprite().getPosition();
				position += normalize(pushDir) * 16.f * delta.asSeconds();
				return true;
			}
		}
	}
	return false;
}
