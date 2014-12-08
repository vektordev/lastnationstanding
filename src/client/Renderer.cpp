#include "Renderer.h"

#include <GameState.h>

Renderer::Renderer(){}
Renderer::~Renderer(){}

bool Renderer::setup(){
    Ogre::String cfgFile = "resources.cfg";
    Ogre::String pluginsFile = "plugins.cfg";

    Ogre::String windowName = "Last Nation Standing";
    Ogre::String logFileName = "LNS_Client.log";

    mLogMgr = new Ogre::LogManager();

    mLog = Ogre::LogManager::getSingleton().createLog(logFileName, true, true, false);
    mLog->setDebugOutputEnabled(true);

    mRoot = new Ogre::Root();

    loadResources(cfgFile);

    mLog->logMessage("Getting graphics options from user");
    if(!mRoot->showConfigDialog())return false;
    mLog->logMessage("Options received.");

    mWindow = mRoot->initialise(true, windowName);

    // Get the SceneManager, in this case a generic one. Add some settings.
	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.3f, 0.3f, 0.3f));

	//no use for an overlay system.
	//mOverlaySystem = new Ogre::OverlaySystem();
	//mSceneMgr->addRenderQueueListener(mOverlaySystem);

	// Create the camera - we need to attach this guy to a sceneNode in the Render loop.
	//This one will be in oblivion until we find a entity that accepts a camera.
	mCamera = mSceneMgr->createCamera("MainCamera");
	mCamera->setPosition(Ogre::Vector3(0,0,80));
	mCamera->lookAt(Ogre::Vector3(0,0,-300));
	mCamera->setNearClipDistance(5);

	// Create a Viewport that matches our camera and put it on the window.
	mViewport = mWindow->addViewport(mCamera);
	mViewport->setBackgroundColour(Ogre::ColourValue(0.8f,0.7f,0.6f,1.0f));
	mCamera->setAspectRatio(
		Ogre::Real(mViewport->getActualWidth()) / Ogre::Real(mViewport->getActualHeight()));

    mViewport->setCamera(mCamera);

	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

	// TODO: What are resource listeners? Do we need one?

	// Load resources
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

bool Renderer::render(GameState* renderThis){
    mLog->logMessage("Starting rendering call");
    mRoot->renderOneFrame();
    mLog->logMessage("Ending rendering call");
}

bool Renderer::destroy(){
    mLog->logMessage("Cleaning up renderer");
}

void Renderer::loadResources(Ogre::String resFile){
    // Load resource paths from config file
	Ogre::ConfigFile cf;
	cf.load(resFile);

	// Go through all sections & settings in the file
	// This will likely need some more dynamic loading with growing memory usage...
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

	Ogre::String secName, typeName, archName;
	while (seci.hasMoreElements())
	{
		secName = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i)
		{
			typeName = i->first;
			archName = i->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
				archName, typeName, secName);
		}
	}
}
