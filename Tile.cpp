#include "Tile.h"

Tile::Tile() {
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setPosition(sf::Vector2f(0.f, 0.f));
	this->shape.setSize(sf::Vector2f(32.f, 32.f));
}

Tile::Tile(std::string path, sf::Vector2f pos, bool s){
	if (!t.loadFromFile(path)) {
		std::cout << "cant load " << path << "\n";
	}
	sprite.setTexture(t);
	sprite.setPosition(pos);
	this->solid = s;
}

void Tile::render(sf::RenderTexture& t){
	t.draw(sprite);
}

sf::RectangleShape Tile::getShape() {
	return shape;
}

sf::Sprite Tile::getSprite(){
	return sprite;
}
