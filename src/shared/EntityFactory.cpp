#include "EntityFactory.h"

#include "Entity.h"
#include "ComponentSystem.h"

EntityFactory::EntityFactory(ComponentSystem& cs) : mCompSys(cs), nextID(0){}

EntityFactory::~EntityFactory(){}

Entity* EntityFactory::addOgreHead(){
	Entity* uuc = new Entity(nextID);
	nextID++;
	uuc->mRCmp = mCompSys.createRenderable(*uuc);
}
