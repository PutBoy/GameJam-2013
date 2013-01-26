#ifndef INCLUDE_ENTITYMANAGER
#define INCLUDE_ENTITYMANAGER
#include <vector>

	class Entity;

	class EntityManager
	{

	public:

	static EntityManager* getInstance();

	//static EntityManager* EM();
	~EntityManager();

	void Update();
	void Draw();
	void Add(Entity* Ent);
	void AddPlayer(Entity* ent);
	void AliveCheck();
	void Collision();
	void Updatedrops();

	private:
		EntityManager();

		Entity* mPlayer;
		typedef std::vector <Entity*> EntityVector;
		EntityVector mEntities;

	};

#endif
