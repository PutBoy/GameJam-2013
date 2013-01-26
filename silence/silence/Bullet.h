#ifndef BULLET_INCLUDE
#define BULLET_INCLUDE
#include "Entity.h"

class Bullet: public Entity
{

public:

	Bullet();
	~Bullet(void);
	void update();
	void render();
	std::string isID(std::string ID);
	sf::FloatRect getColBox();
	void closeToEnemy(Entity* en);




private:

};


#endif
