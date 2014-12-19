#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "Renderer.h"
#include <GameState.h>

class GameApp{
public:
	GameApp();
	~GameApp();

	void run();

private:
	void start();
	void loop();
	void destroy();

	Renderer mRnd;
	GameState mGs;

	bool mShutdown;
};

#endif

