#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H
class Entity;
class ComponentSystem;

class EntityFactory{
public:
    EntityFactory(ComponentSystem& cs);
    ~EntityFactory();

    Entity* addOgreHead();

private:
    ComponentSystem& mCompSys;
	int nextID;
};
#endif // ENTITYFACTORY_H
