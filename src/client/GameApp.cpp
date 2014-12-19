#include "GameApp.h"
GameApp::GameApp() : mShutdown(false){}
GameApp::~GameApp(){}

void GameApp::run(){
	start();
	loop();
	destroy();
}

void GameApp::start(){
    mRnd.setup();
}

void GameApp::loop(){
    while(!mShutdown){
        mGs.tick();
        mRnd.render(&mGs);
    }
}

void GameApp::destroy(){
    mRnd.destroy();
}

