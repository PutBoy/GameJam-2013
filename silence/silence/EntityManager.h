#ifndef INCLUDE_ENTITYMANAGER
#define INCLUDE_ENTITYMANAGER
#include <vector>

	

	class EntityManager
	{

	public:

	static EntityManager* EM();
	~EntityManager();

	void Update();
	void Draw();
	void Add(Entity* Ent);
	void AliveCheck();
	void Collision();

	protected:
	
		EntityManager();

	private:

		static EntityManager* mEM;
		typedef std::vector <Entity*> EntityVector;
		EntityVector mEntities;

	};

#endif
