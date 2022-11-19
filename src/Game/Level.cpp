#include "Level.h"

#include "../Resources/ResourceManager.h"

#include "GameObjects/IGameObject.h"

#include "GameObjects/BrickWall.h"

#include <iostream>

const unsigned int BLOCK_SIZE = 16;

std::shared_ptr<IGameObject> createGameObjectFromDescription(const char description, const glm::vec2& position, const glm::vec2& size, const float rotation) {
	switch (description)
	{
	case '0' : 
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_right"), position, size, rotation);
		break;
	case '1':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_bottom"), position, size, rotation);
		break;
	case '2':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_left"), position, size, rotation);
		break;
	case '3':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_top"), position, size, rotation);
		break;
	case '4':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall"), position, size, rotation);
		break;
	case 'G':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_bottom_left"), position, size, rotation);
		break;
	case 'H':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_bottom_right"), position, size, rotation);
		break;
	case 'I':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_top_left"), position, size, rotation);
		break;
	case 'J':
		return std::make_shared<BrickWall>(ResourceManager::getSprite("brickWall_top_right"), position, size, rotation);
		break;
	case 'D':
		return nullptr;
		break;
	default:
		std::cerr << "Unknown GameObject description: " << description << std::endl;
		break;
	}
	return nullptr;
}

Level::Level(const std::vector<std::string>& levelDescription) {
	if (levelDescription.empty()) {
		std::cerr << "Empty level description" << std::endl;
	}

	m_width = levelDescription[0].length();
	m_height = levelDescription.size();

	m_mapObjects.reserve(m_width * m_height);
	unsigned int currentBottomOffset = static_cast<unsigned int>(BLOCK_SIZE * (m_height - 1));
	for (const std::string& currentRow : levelDescription) {
		unsigned int currentLeftOffset = 0;
		for (const char currentElement : currentRow) {
		m_mapObjects.emplace_back(createGameObjectFromDescription(currentElement, glm::vec2(currentLeftOffset, currentBottomOffset), glm::vec2(BLOCK_SIZE, BLOCK_SIZE), 0));
			currentLeftOffset += BLOCK_SIZE;
		}
		currentBottomOffset -= BLOCK_SIZE;
	}
}
void Level::render() const {
	for (const auto& currentMapObject : m_mapObjects) {
		if (currentMapObject) {
			currentMapObject->render();
		}
	}
}
void Level::update(const uint64_t delta) {
	for (const auto& currentMapObject : m_mapObjects) {
		if (currentMapObject) {
			currentMapObject->update(delta);
		}
	}
}