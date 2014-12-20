#include "ComponentSystem.h"

ComponentSystem::ComponentSystem(){
	mRCompID = 1;
}

ComponentSystem::~ComponentSystem(){

}

RenderableComponent* ComponentSystem::createRenderable(Entity& up){
	RenderableComponent uuc = RenderableComponent(up, mRCompID);
	mRCompID++;
	mRComps.push_back(uuc);
	return &mRComps.back();
}
