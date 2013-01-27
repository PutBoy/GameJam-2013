#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "Player.h"
#include "MapManager.h"
#include "Camera.h"
#include <sstream>
#include "StartMenu.h"

#include "StateManager.h"

void loadTextures()
{
	ResourceManager* r = ResourceManager::getInstance();
	//Spinemace
	r->loadTexture("spinemace","bonemace_idle_png.png", sf::IntRect(0,0,256,256));	
	r->loadTexture("spinemaceIdle", "bonemace_idle_png.png", sf::IntRect(0,0,256,256));
	r->loadTexture("spinemaceAttackForward", "images/bonemace_forward_strike_sprite_png.png", sf::IntRect(0, 0, 2560, 256));
	r->loadTexture("spinemaceAttackLeft", "images/bonemace_left_strike_sprite_png.png", sf::IntRect(0, 0, 2560, 256));
	r->loadTexture("spinemaceAttackRight", "images/bonemace_right_strike_sprite_png.png", sf::IntRect(0, 0, 2560, 256));
	r->loadTexture("spinemaceAttackBack", "images/bonemace_back_strike_sprite_png.png", sf::IntRect(0, 0, 2560, 256));
	//Player
	r->loadTexture("down","priest_walk_forward_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("left","priest_walk_left_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("right","priest_walk_right_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("up","priest_walk_back_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("downIdle", "priest_stand_still_sprite.png", sf::IntRect(0,0,1280,128));
	r->loadTexture("leftIdle", "images/priest_idle_left_png.png", sf::IntRect(0,0,128,128));
	r->loadTexture("rigthIdle1", "images/priest_idle_right_png.png", sf::IntRect(0,0,127,127));
	r->loadTexture("BackIdle1", "images/priest_idle_back_png.png", sf::IntRect(0,0,127,127));

	//Megasuperhackerguy
	r->loadTexture("MegaSuperHackerGuyRigth", "images/machete_man_walk_right_sprite_png.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("MegaSuperHackerGuyLeft", "images/machete_man_walk_left_sprite_png.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("MegaSuperHackerGuyDown", "images/machete_man_walk_forward_sprite_png.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("MegaSuperHackerGuyUp", "images/machete_man_walk_back_sprite_png.png",sf::IntRect(0,0,1280,128));

	//knuckles
	//r->loadTexture("Knuckles", "sökväg", sf::IntRect(0,0,500,500));

	//Frog
	r->loadTexture("FrogRigth", "images/frog-right.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("FrogLeft", "images/frog-left.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("FrogDown", "images/frog-down.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("FrogUp", "images/frog-up.png",sf::IntRect(0,0,1280,128));

	//Bat
	r->loadTexture("BatLeft", "images/fladdemus-sida.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("BatRigth", "images/fladdermus-sida2.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("BatUp", "images/fladdermus-upp.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("BatDown", "images/fladdermus-sprite.png",sf::IntRect(0,0,1280,128));

	//AnimationEntities
	r->loadTexture("deathanimationenemy", "images/death_animation_enemy_png.png",sf::IntRect(0,0,2580,258));


}

int main()
{
	loadTextures();
	srand(time(NULL));
	WindowManager* window = WindowManager::getInstance();
	ResourceManager* resources = ResourceManager::getInstance();
	StateManager* StateManager = StateManager::getInstance();

	StateManager->add(new StartMenu());


	while(window->isOpen())
	{		
		window->pollEvents();
		StateManager->update();

		window->clear();
		StateManager->render();
		window->renderCanvas();
		window->flip();
	}
}