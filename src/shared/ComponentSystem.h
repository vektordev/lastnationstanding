#ifndef COMPONENTSYSTEM_H
#define COMPONENTSYSTEM_H

#include <vector>

#include "RenderableComponent.h"

class ComponentSystem{
public:
	ComponentSystem();
	~ComponentSystem();

	RenderableComponent* createRenderable(Entity& up);

	std::vector<RenderableComponent> mRComps;
	//ID policy: 0 is invalid, 1 is initial. No reassigning after destruction.
	int mRCompID;
};
#endif // COMPONENTSYSTEM_H
