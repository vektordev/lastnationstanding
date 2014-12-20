#ifndef ENTITY_H
#define ENTITY_H

#include <LinearMath/btVector3.h>
#include <LinearMath/btQuaternion.h>


class RenderableComponent;

class Entity{
public:
	Entity(int id);
	~Entity();

	btVector3 getPosition();
	btQuaternion getOrientation();

	int mID;

	RenderableComponent* mRCmp;
};
#endif // ENTITY_H
