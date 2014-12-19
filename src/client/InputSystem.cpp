#include "InputSystem.h"

#include <OgreRenderWindow.h>

InputSystem::InputSystem() :mMouse(0), mKeyboard(0), mInputMgr(0), mRenderWindow(0){

}
InputSystem::~InputSystem(){

}

void InputSystem::getInput(){
	if(mMouse) mMouse->capture();
	if(mKeyboard) mKeyboard->capture();
	for(OIS::JoyStick* i : mJoysticks)
		i->capture();
}

void InputSystem::init(Ogre::RenderWindow *renderWindow){
	if(mInputMgr) return;
	mRenderWindow = renderWindow;
	// Setup basic variables
	OIS::ParamList paramList;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;
	// Get window handle
	renderWindow->getCustomAttribute( "WINDOW", &windowHnd );
	// Fill parameter list
	windowHndStr << (unsigned int) windowHnd;
	paramList.insert( std::make_pair( std::string( "WINDOW" ), windowHndStr.str() ) );
	// Create inputsystem
	mInputMgr = OIS::InputManager::createInputSystem( paramList );
	// If possible create a buffered keyboard
	if (mInputMgr->getNumberOfDevices(OIS::OISKeyboard) > 0) {
		mKeyboard = static_cast<OIS::Keyboard*>( mInputMgr->createInputObject( OIS::OISKeyboard, true ) );
		mKeyboard->setEventCallback( this );
	}
	// If possible create a buffered mouse
	if (mInputMgr->getNumberOfDevices(OIS::OISMouse) > 0) {
		mMouse = static_cast<OIS::Mouse*>( mInputMgr->createInputObject( OIS::OISMouse, true ) );
		mMouse->setEventCallback( this );
		// Get window size
		unsigned int width, height, depth;
		int left, top;
		renderWindow->getMetrics( width, height, depth, left, top );
		// Set mouse region
		mMouse->getMouseState().width = width;
		mMouse->getMouseState().height = height;
		
	}
	// If possible create all joysticks in buffered mode
	if (mInputMgr->getNumberOfDevices(OIS::OISJoyStick) > 0) {
		mJoysticks.resize( mInputMgr->getNumberOfDevices(OIS::OISJoyStick) );
		for(std::vector<OIS::JoyStick*>::iterator itJoystick = mJoysticks.begin(); itJoystick != mJoysticks.end(); ++itJoystick ) {
			(*itJoystick) = static_cast<OIS::JoyStick*>( mInputMgr->createInputObject( OIS::OISJoyStick, true ) );
			(*itJoystick)->setEventCallback( this );
		}
	}
}

void InputSystem::windowClosed(){
	//TODO: assert it's the right one
	mRenderWindow = 0;
	if(mInputMgr){
		//destroy all input objects:
		mInputMgr->destroyInputObject(mMouse);
		mMouse = 0;
		mInputMgr->destroyInputObject(mKeyboard);
		mKeyboard = 0;
		for(OIS::JoyStick* i: mJoysticks)
			mInputMgr->destroyInputObject(i);
		mJoysticks = std::vector<OIS::JoyStick*>();

		//destroy the InputMgr
		OIS::InputManager::destroyInputSystem(mInputMgr);
		mInputMgr = 0;
	}
}
void InputSystem::windowResized(unsigned int width, unsigned int height){
	//register new window size with Input System.
	const OIS::MouseState &ms = mMouse->getMouseState();
	ms.width = width;
	ms.height = height;
}


bool InputSystem::keyPressed( const OIS::KeyEvent &e ){

}
bool InputSystem::keyReleased( const OIS::KeyEvent &e ){

}


bool InputSystem::mouseMoved( const OIS::MouseEvent &e ){

}
bool InputSystem::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ){

}
bool InputSystem::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ){

}


bool InputSystem::povMoved( const OIS::JoyStickEvent &e, int pov ){

}
bool InputSystem::axisMoved( const OIS::JoyStickEvent &e, int axis ){

}
bool InputSystem::sliderMoved( const OIS::JoyStickEvent &e, int sliderID ){

}

bool InputSystem::buttonPressed( const OIS::JoyStickEvent &e, int button ){

}
bool InputSystem::buttonReleased( const OIS::JoyStickEvent &e, int button ){

}
