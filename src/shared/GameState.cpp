#include <iostream>
#include "GameState.h"
#include <btBulletDynamicsCommon.h>

void GameState::sayHello(){
	std::cout<<"GS says hello!"<<std::endl;
}

void GameState::bulletTest(){
	btBroadphaseInterface* broadphase = new btDbvtBroadphase();
	std::cout<<"Physics!"<<std::endl;
	delete broadphase;
}

