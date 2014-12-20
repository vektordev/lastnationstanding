#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"

class Component{
public:
	Component(Entity& ePtr, int idIn);

	//reference to the Entity this component belongs to
	const Entity& upPtr;

	//unique amongst all components of the implementing class.
	const int id;
};
#endif // COMPONENT_H
