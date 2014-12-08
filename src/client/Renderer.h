#ifndef RENDERER_H
#define RENDERER_H

#include <Ogre.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>

class GameState;

class Renderer
{
public:
	Renderer();
	~Renderer();


	bool setup();
	bool render(GameState* renderThis);//TODO: Missing the GameState param
	bool destroy();

    Ogre::LogManager *mLogMgr;
    Ogre::Log *mLog;
    Ogre::Root *mRoot;
    Ogre::Camera* mCamera;
    Ogre::SceneManager* mSceneMgr;
    Ogre::RenderWindow* mWindow;
    //Ogre::String mResourcesCfg;
    //Ogre::String mPluginsCfg;
	Ogre::OverlaySystem *mOverlaySystem;
	Ogre::Viewport *mViewport;

    OgreBites::SdkCameraMan* mCameraMan;       // basic camera controller

	void loadResources(Ogre::String resFile);

	//TODO:
	//- FrameListener (?)
	//- WindowEventListener for resized/closed calls(!)
    //- Unattach OIS before window shutdown (very important under Linux)

};

#endif

