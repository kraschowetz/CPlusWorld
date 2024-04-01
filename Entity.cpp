#include "Entity.h"

Entity::Entity() {}

Entity::Entity(sf::Vector2f pos){
	this->position = pos;
}

sf::Vector2f Entity::getPosition(){
	return position;
}

void Entity::setPosition(sf::Vector2f pos){
	position = pos;
}

sf::Vector2f Entity::normalize(sf::Vector2f v){
	if(v == sf::Vector2f(0, 0))
		return v;
	float lenght = sqrt(v.x * v.x + v.y * v.y);
	sf::Vector2f result = sf::Vector2f(v.x / lenght, v.y / lenght);
	return result;
}
