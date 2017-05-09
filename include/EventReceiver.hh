//
// EventReceiver.hh for  in /home/zobov_v/rendu/cpp_indie_studio/include
// 
// Made by Vladisalv ZOBOV
// Login   <zobov_v@epitech.net>
// 
// Started on  Thu May  4 17:42:20 2017 Vladisalv ZOBOV
// Last update Tue May  9 16:52:13 2017 Vladisalv ZOBOV
//

#include <irrlicht.h>
#include <driverChoice.h>

struct SAppContext
{
  irr::IrrlichtDevice *device;
  irr::s32             counter;
  irr::gui::IGUIListBox*    listbox;
};

enum
{
  GUI_ID_QUIT_BUTTON = 101,
  GUI_NEW_GAME_BUTTON,
  GUI_LOAD_GAME_BUTTON,
  GUI_OPTION_GAME_BUTTON,
  GUI_ID_TRANSPARENCY_SCROLL_BAR,
  GUI_ID_DIALOG_ROOT_WINDOW,
  GUI_ID_X_SCALE,
  GUI_ID_Y_SCALE,
  GUI_ID_Z_SCALE,
  GUI_ID_TOGGLE_DEBUG_INFO
};

void setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin * skin)
{
  for (irr::s32 i=0; i < irr::gui::EGDC_COUNT ; ++i)
    {
      irr::video::SColor col = skin->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
      col.setAlpha(alpha);
      skin->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }
}

class MyEventReceiver : public irr::IEventReceiver
{
private:
  SAppContext & Context;
public:
  MyEventReceiver(SAppContext & context) : Context(context) {}

  virtual bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_GUI_EVENT)
      {
	irr::s32 id = event.GUIEvent.Caller->getID();
	irr::gui::IGUIEnvironment* env = Context.device->getGUIEnvironment();

	switch(event.GUIEvent.EventType)
	  {
	  case irr::gui::EGET_BUTTON_CLICKED:
	    switch(id)
	      {
	      case GUI_ID_QUIT_BUTTON:
		Context.device->closeDevice();
		return true;
		break;
	      case GUI_NEW_GAME_BUTTON:
		break;
	      case GUI_LOAD_GAME_BUTTON:
		break;
	      case GUI_OPTION_GAME_BUTTON:
		break;
	      }
	  default:
	    break;
	  }
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	  {
	    irr::s32 id = event.GUIEvent.Caller->getID();
	    irr::gui::IGUIEnvironment* env = Context.device->getGUIEnvironment();

	    switch(event.GUIEvent.EventType)
	      {
	      case irr::gui::EKEY_CODE:
		switch(id)
		  {
		  case GUI_ID_SELECT_BUTTON:
		    Context.device->closeDevice();
		    return true;
		    break;
		  }
	      default:
		break;
	      }
	  }
      }
    return false;
  }
};
