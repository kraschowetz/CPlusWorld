#include "World.h"

void World::generateWorld() {
	//etapa 0: seed do rng
	std::srand(std::time(nullptr));

	//etapa 1: mundo plano
	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			tiles[x][y] = new Tile("Sprites/Water.png", sf::Vector2f(x * 32, y * 32), true);
		}
	}
	//etapa 2: Random walk algorithm
	std::vector<sf::Vector2f> lastWalkPosition;
	sf::Vector2f currentWalkPosition;
	sf::Vector2f nextpos;

	//loop do algoritimo
	tiles[0][0] = new Tile("Sprites/Grass.png", sf::Vector2f(0.f, 0.f), false);
	for (int i = 0; i < 256; i++) {
		//determinar a próxima posição
		int d = std::rand() % 4;
		switch (d) {
			case 1:
				nextpos = sf::Vector2f(0.f, -1.f);
				break;
			case 2:
				nextpos = sf::Vector2f(1.f, 0.f);
				break;
			case 3:
				nextpos = sf::Vector2f(0.f, 1.f);
				break;
			default:
				nextpos = sf::Vector2f(-1.f, 0.f);
				break;
		}

		//validar posição
		if (currentWalkPosition.x + nextpos.x< 0 || currentWalkPosition.y + nextpos.y < 0) { i--; continue; }
		if (currentWalkPosition.x + nextpos.x >= size.x || currentWalkPosition.y + nextpos.y >= size.y) { i--; continue; }

		for (sf::Vector2f n : lastWalkPosition) {
			if (currentWalkPosition + nextpos == n) { i--; break; }
		}

		currentWalkPosition += nextpos;
		lastWalkPosition.push_back(currentWalkPosition);

		std::cout << i << ": " << currentWalkPosition.x <<", " << currentWalkPosition.y <<"\n";

		tiles[(int)currentWalkPosition.x][(int)currentWalkPosition.y] = new Tile("Sprites/Grass.png", sf::Vector2f(currentWalkPosition.x * 32, currentWalkPosition.y * 32.f), false);

	}

}

void World::render(sf::RenderTexture& t, sf::Vector2f viewPos){
	viewPos = sf::Vector2f(viewPos.x / 32.f, viewPos.y / 32.f); //convert worldspace into tilemapSpace position

	for (int x = (int)(viewPos.x - tilesPerScreen.x / 2); x < (int)(viewPos.x + tilesPerScreen.x / 2); x++) {
		for (int y = (int)(viewPos.y - tilesPerScreen.y / 2); y < (int)(viewPos.y + tilesPerScreen.y / 2); y++) {
			if (x < 0 || y < 0) { continue; }
			if (x >= size.x || y >= size.y) { continue; }
			t.draw(tiles[x][y]->getSprite());
		}
	}

}

Tile* World::getTile(sf::Vector2f pos){
	int x = pos.x / 32.f;
	int y = pos.y / 32.f;
	return tiles[x][y];
}

sf::Vector2i World::getSize(){
	return size;
}
