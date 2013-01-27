#ifndef INCLUDE_ENTITYMANAGER
#define INCLUDE_ENTITYMANAGER
#include <vector>
#include <memory>

	class Entity;

	class EntityManager
	{

	public:

	~EntityManager();

	EntityManager();

	void Update();
	void Draw();
	void Add(std::shared_ptr<Entity> ent);
	void AddPlayer(std::shared_ptr<Entity> ent);
	void AliveCheck();
	void Collision();
	void Updatedrops();

	private:

	std::shared_ptr<Entity> mPlayer;
	typedef std::vector <std::shared_ptr<Entity>> EntityVector;
	EntityVector mEntities;
	EntityVector mGraveYard;
	};

#endif
