#include <iostream>
#include "../shared/GameState.h"

int main(){
	std::cout<<"Server Hello World"<<std::endl;
	GameState g;
	g.sayHello();
	g.bulletTest();
}

