#ifndef WEAPON_H
#define WEAPON_H

class Player;
class Entity;

class Weapon
{
public:
	Weapon(void);
	~Weapon(void);
	Entity* shoot();
private:
	Player* mPlayer;
};

#endif