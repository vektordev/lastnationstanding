#include <iostream>
#include <GameState.h>

#include "Renderer.h"

int main(){
	std::cout<<"Client Hello World"<<std::endl;
	GameState g;
	g.sayHello();
	g.bulletTest();
	Renderer r;
	r.setup();
    for(int i = 0; i < 600; i++)
        r.render(0);
	r.destroy();
}

