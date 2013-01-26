#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "Player.h"
#include "MapManager.h"
#include "Camera.h"
#include <sstream>

#include "StateManager.h"
#include "Game.h"

int main()
{
	WindowManager* window = WindowManager::getInstance();
	ResourceManager* resources = ResourceManager::getInstance();
	StateManager* StateManager = StateManager::getInstance();

	StateManager->add(new Game());


	while(window->isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{		
		window->pollEvents();
		StateManager->update();

		window->clear();
		StateManager->render();
		window->renderCanvas();
		window->flip();
	}
}