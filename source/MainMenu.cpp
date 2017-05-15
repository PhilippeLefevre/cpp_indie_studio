/*
** MainMenu.cpp for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 18:40:29 2017 Tanguy Lelievre
** Last update	Thu May 11 18:00:35 2017 Tanguy Lelievre
*/

#include "MainMenu.hh"

MainMenu::MainMenu() : _opts()
{
  _params.WindowSize = irr::core::dimension2d<irr::u32>(_opts.getWidth(), _opts.getHeight());
  _params.Bits = 32;
  _params.Fullscreen = _opts.getFullscreen();
  _params.Stencilbuffer = false;
  _params.DriverType = irr::video::EDT_OPENGL;
  _params.Vsync = _opts.getVsync();
  _params.AntiAlias = _opts.getAA() ? 8 : 0;
  _params.EventReceiver = this;

  _Mdevice = createDeviceEx(_params);
  if (!_Mdevice)
    return;

  _driver = _Mdevice->getVideoDriver();
  _smgr = _Mdevice->getSceneManager();

  _guienv = _Mdevice->getGUIEnvironment();
}

MainMenu::~MainMenu() {}

enum
{
  GUI_ID_QUIT_BUTTON = 101,
  GUI_NEW_GAME_BUTTON,
  GUI_LOAD_GAME_BUTTON,
  GUI_SCORE_GAME_BUTTON,
  GUI_OPTION_GAME_BUTTON,
  GUI_TATATA_GAME_BUTTON,
  GUI_DISPLAY_GAME_BUTTON,
  GUI_SOUND_GAME_BUTTON,
  GUI_SHORTCUTS_GAME_BUTTON,
  GUI_BACK_GAME_BUTTON
};

void	MainMenu::Menu()
{
  _irrlichtBack = _driver->getTexture("./media/Backgrounds/bck.jpg");
  _logo_img = _guienv->addImage(_driver->getTexture("./media/Logos/blogo.png"), irr::core::position2d<int>(300, 80));

  _mesh = _smgr->getMesh("./media/Bomberman/Bomberman/Bomberman.obj");
  _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);

  if (_modelNode)
    {
      _modelNode->setPosition(irr::core::vector3df(0.f, -20.f, -20.f));
      _modelNode->setRotation(irr::core::vector3df(0.10f, 50.f, 0.f));
      _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _modelNode->setDebugDataVisible(irr::scene::EDS_OFF);
      _modelNode->getMaterial(0).NormalizeNormals = true;
      _modelNode->setFrameLoop(0, 14);
      _modelNode->setAnimationSpeed(15);
      _modelNode->setScale(_modelNode->getScale() * 8.0f);
    }

  _smgr->addCameraSceneNode(0, irr::core::vector3df(45,0,0), irr::core::vector3df(0,0,10));
  _dim = _guienv->getVideoDriver()->getScreenSize();
  _NewGame = _guienv->addButton(irr::core::rect<irr::s32>(750, 540, 1150, 540 + 60), 0, GUI_NEW_GAME_BUTTON, L"New Game");
  _NewGame->setDrawBorder(0);
  _Load = _guienv->addButton(irr::core::rect<irr::s32>(750,610,1150,610 + 60), 0, GUI_LOAD_GAME_BUTTON, L"Load Game");
  _Load->setDrawBorder(0);
  _Score = _guienv->addButton(irr::core::rect<irr::s32>(750,680,1150, 680 + 60), 0, GUI_SCORE_GAME_BUTTON, L"Score");
  _Score->setDrawBorder(0);
  _Options = _guienv->addButton(irr::core::rect<irr::s32>(750,750, 1150,750 + 60), 0, GUI_OPTION_GAME_BUTTON, L"Options");
  _Options->setDrawBorder(0);
  _Exit = _guienv->addButton(irr::core::rect<irr::s32>(750, 820, 1150, 820 + 60), 0, GUI_ID_QUIT_BUTTON, L"Quit");
  _Exit->setDrawBorder(0); 
}

bool	MainMenu::run()
{
  Menu();
  irr::core::stringw str = "Bomberman - Main Menu ";
  str += _Mdevice->getVersion();
  _Mdevice->setWindowCaption(str.c_str());

  _logo_img = _guienv->addImage(_driver->getTexture("./media/Logos/blogo.png"), irr::core::position2d<int>(300, 80));

  _skin = _guienv->getSkin();
  _font = _guienv->getFont("./media/fonts/editundo.png");
  _irrlichtBack = _driver->getTexture("./media/Backgrounds/bck.jpg");

  if (_font)
    {
      _guienv->getSkin()->setFont(_font);
      _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 255, 255, 0));
    }

  _smgr->addCameraSceneNode(0, irr::core::vector3df(45,0,0), irr::core::vector3df(0,0,10));
  while(_Mdevice->run() && _driver)
    {
      if (_Mdevice->isWindowActive())
	{
	  _driver->beginScene(true, true, irr::video::SColor(255,255,255,255));
	  if (_irrlichtBack)
	    _driver->draw2DImage(_irrlichtBack, irr::core::position2d<int>(0,0));
	  _smgr->drawAll();
	  _guienv->drawAll();
	  _driver->endScene();
	}
      else
	_Mdevice->yield();
    }
  _Mdevice->drop();
}

void	MainMenu::GOptions()
{
  _Mdevice->sleep(300);
  _guienv->clear();
  _smgr->clear();

  _irrlichtBack = _driver->getTexture("./media/Backgrounds/OptionsBck.jpg");
  _dim = _guienv->getVideoDriver()->getScreenSize();
  _Tatata = _guienv->addButton(irr::core::rect<irr::s32>(750,540,1150,540 + 60), 0, GUI_TATATA_GAME_BUTTON, L"Tatata");
  _Tatata->setDrawBorder(0);
  _display = _guienv->addButton(irr::core::rect<irr::s32>(750,610,1150,610 + 60), 0, GUI_DISPLAY_GAME_BUTTON, L"Display");
  _display->setDrawBorder(0);
  _sound = _guienv->addButton(irr::core::rect<irr::s32>(750,680,1150, 680 + 60), 0, GUI_SOUND_GAME_BUTTON, L"Sound");
  _sound->setDrawBorder(0);
  _shortc = _guienv->addButton(irr::core::rect<irr::s32>(750,750, 1150,750 + 60), 0, GUI_SHORTCUTS_GAME_BUTTON, L"Shortcuts");
  _shortc->setDrawBorder(0);
  _back = _guienv->addButton(irr::core::rect<irr::s32>(750, 820, 1150, 820 + 60), 0, GUI_BACK_GAME_BUTTON, L"Back");
  _back->setDrawBorder(0);
}

void	MainMenu::Display()
{
  _guienv->clear();

  _dim = _guienv->getVideoDriver()->getScreenSize();
  _Resolution = _guienv->addComboBox(irr::core::rect<irr::s32>( _dim.Width - 300, 24, _dim.Width - 10, 40 ));
}

bool	MainMenu::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      irr::s32 id = event.GUIEvent.Caller->getID();
      irr::gui::IGUIEnvironment* env = _Mdevice->getGUIEnvironment();

      switch(event.GUIEvent.EventType)
	{
	case irr::gui::EGBS_BUTTON_MOUSE_OVER:
	  switch(id)
	    {
	    case GUI_NEW_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _NewGame->setOverrideFont(_font);
	      _mesh = _smgr->getMesh("./media/Bombs/FireBomb/Bomb.obj");
	      _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	      _ani = _smgr->createRotationAnimator(irr::core::vector3df(0,1,0));
	      _modelNode->addAnimator(_ani);
	      if (_modelNode)
		{
		  _modelNode->setPosition(irr::core::vector3df(-30.f, -6.5f, 36.f));
		  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
		  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		  _modelNode->setScale(_modelNode->getScale() * 0.50f);
		}
	      return true;
	      break;

	    case GUI_LOAD_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _Load->setOverrideFont(_font);
	      _mesh = _smgr->getMesh("./media/Bombs/AquaBomb/AquaBomb.obj");
	      _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	      _ani = _smgr->createRotationAnimator(irr::core::vector3df(0,1,0));
	      _modelNode->addAnimator(_ani);
	      if (_modelNode)
		{
		  _modelNode->setPosition(irr::core::vector3df(-30.f, -14.5f, 36.f));
		  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
		  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		  _modelNode->setScale(_modelNode->getScale() * 0.50f);
		}
	      return true;
	      break;

	    case GUI_SCORE_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _Score->setOverrideFont(_font);
	      _mesh = _smgr->getMesh("./media/Bombs/IceBomb/IceBomb.obj");
	      _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	      _ani = _smgr->createRotationAnimator(irr::core::vector3df(0,1,0));
	      _modelNode->addAnimator(_ani);
	      if (_modelNode)
		{
		  _modelNode->setPosition(irr::core::vector3df(-30.f, -22.5f, 36.f));
		  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
		  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		  _modelNode->setScale(_modelNode->getScale() * 0.50f);
		}
	      return true;
	      break;

	    case GUI_OPTION_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _Options->setOverrideFont(_font);
	      _mesh = _smgr->getMesh("./media/Bombs/PowerBomb/PowerBomb.obj");
	      _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	      _ani = _smgr->createRotationAnimator(irr::core::vector3df(0,1,0));
	      _modelNode->addAnimator(_ani);
	      if (_modelNode)
		{
		  _modelNode->setPosition(irr::core::vector3df(-30.f, -30.5f, 36.f));
		  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
		  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		  _modelNode->setScale(_modelNode->getScale() * 0.50f);
		}
	      return true;
	      break;

	    case GUI_ID_QUIT_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _Exit->setOverrideFont(_font);
	      _mesh = _smgr->getMesh("./media/Bombs/MegaBomb/MegaBomb.obj");
	      _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	      _ani = _smgr->createRotationAnimator(irr::core::vector3df(0,1,0));
	      _modelNode->addAnimator(_ani);
	      if (_modelNode)
		{
		  _modelNode->setPosition(irr::core::vector3df(-30.f, -38.5f, 36.f));
		  _modelNode->setRotation(irr::core::vector3df(0.f, -10.f, 30.f));
		  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		  _modelNode->setScale(_modelNode->getScale() * 0.50f);
		}
	      return true;
	      break;
	    }
	  break;

	case irr::gui::EGBS_BUTTON_MOUSE_OFF:
	  switch(id)
	    {
	    case GUI_NEW_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo.png");
	      _NewGame->setOverrideFont(_font);
	      _ani->drop();
	      _smgr->addToDeletionQueue(_modelNode);
	      return true;
	      break;

	    case GUI_LOAD_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo.png");
	      _Load->setOverrideFont(_font);
	      _ani->drop();
	      _smgr->addToDeletionQueue(_modelNode);
	      return true;
	      break;

	    case GUI_SCORE_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo.png");
	      _Score->setOverrideFont(_font);
	      _ani->drop();
	      _smgr->addToDeletionQueue(_modelNode);
	      return true;
	      break;

	    case GUI_OPTION_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo.png");
	      _Options->setOverrideFont(_font);
	      _ani->drop();
	      _smgr->addToDeletionQueue(_modelNode);
	      return true;
	      break;

	    case GUI_ID_QUIT_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo.png");
	      _Exit->setOverrideFont(_font);
	      _ani->drop();
	      _smgr->addToDeletionQueue(_modelNode);
	      return true;
	      break;
	    }
	  break;

	case irr::gui::EGET_BUTTON_CLICKED:
	  switch(id)
	    {
	    case GUI_ID_QUIT_BUTTON:
	      _Mdevice->closeDevice();
	      return true;
	      break;
	    case GUI_NEW_GAME_BUTTON:
	      return true;
	      break;
	    case GUI_LOAD_GAME_BUTTON:
	      break;
	    case GUI_OPTION_GAME_BUTTON:
	      GOptions();
	      break;
	    case GUI_TATATA_GAME_BUTTON:
	      break;
	    case GUI_DISPLAY_GAME_BUTTON:
	      Display();
	      break;
	    case GUI_SOUND_GAME_BUTTON:
	      break;
	    case GUI_SHORTCUTS_GAME_BUTTON:
	      break;
	    case GUI_BACK_GAME_BUTTON:
	      _guienv->clear();
	      Menu();
	    }
	default:
	  break;
	}
    }
  return false;
}
