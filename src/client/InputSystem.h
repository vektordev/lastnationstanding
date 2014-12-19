#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISJoyStick.h>
#include <OISMouse.h>
#include <OgreWindowEventUtilities.h>
#include <vector>
namespace Ogre{
	class RenderWindow;
};

class InputSystem : public OIS::KeyListener, public OIS::MouseListener, public OIS::JoyStickListener, public Ogre::WindowEventListener
{
public:
	InputSystem();
	~InputSystem();

	void getInput();

	void init(Ogre::RenderWindow *renderWindow);

	void windowClosed();
	void windowResized(unsigned int width, unsigned int height);


	bool keyPressed( const OIS::KeyEvent &e );
	bool keyReleased( const OIS::KeyEvent &e );


	bool mouseMoved( const OIS::MouseEvent &e );
	bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
	bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );


	bool povMoved( const OIS::JoyStickEvent &e, int pov );
	bool axisMoved( const OIS::JoyStickEvent &e, int axis );
	bool sliderMoved( const OIS::JoyStickEvent &e, int sliderID );

	bool buttonPressed( const OIS::JoyStickEvent &e, int button );
	bool buttonReleased( const OIS::JoyStickEvent &e, int button );



	std::vector<OIS::JoyStick*> mJoysticks;
	OIS::Mouse*	mMouse;
	OIS::Keyboard*	mKeyboard;
	OIS::InputManager*	mInputMgr;
	Ogre::RenderWindow* mRenderWindow;
};

#endif

