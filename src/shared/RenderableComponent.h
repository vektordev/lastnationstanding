#ifndef RENDERABLECOMPONENT_H
#define RENDERABLECOMPONENT_H

#include "Component.h"

class RenderableComponent : Component{
public:
	RenderableComponent(Entity& eRef, int id);
	~RenderableComponent();
};
#endif // RENDERABLECOMPONENT_H
