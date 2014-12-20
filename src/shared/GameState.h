#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "ComponentSystem.h"
#include "EntityFactory.h"

class GameState{
public:
	GameState();
	~GameState();

	void sayHello();
	void bulletTest();

	bool init();
	void tick();
	void destroy();

private:
	EntityFactory mEntityFactory;
	ComponentSystem mComponentSystem;
};

#endif

