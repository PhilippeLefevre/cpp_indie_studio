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
}

MainMenu::~MainMenu() {}

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


bool	MainMenu::run()
{
  irr::video::IVideoDriver* driver = _Mdevice->getVideoDriver();
  irr::scene::ISceneManager* smgr = _Mdevice->getSceneManager();
  irr::gui::IGUIEnvironment* guienv = _Mdevice->getGUIEnvironment();

  irr::core::stringw str = "Bomberman - Main Menu ";
  str += _Mdevice->getVersion();
  _Mdevice->setWindowCaption(str.c_str());

  _Mdevice->getFileSystem()->addFileArchive("./media/");
  _logo_img = guienv->addImage(driver->getTexture("./media/blogo.png"), irr::core::position2d<int>(300, 80));

  irr::gui::IGUISkin* skin = guienv->getSkin();
  irr::gui::IGUIFont* font = guienv->getFont("./media/fonts/fonts.xml");

  if (font)
    {
      guienv->getSkin()->setFont(font);
      skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 255, 255, 0));
    }
  _NewGame = guienv->addButton(irr::core::rect<irr::s32>(750,540,1150,540 + 60), 0, GUI_NEW_GAME_BUTTON, L"New Game");
  _NewGame->setDrawBorder(0);
  _Load = guienv->addButton(irr::core::rect<irr::s32>(750,610,1150,610 + 60), 0, GUI_LOAD_GAME_BUTTON, L"Load Game");
  _Load->setDrawBorder(0);
  _Score = guienv->addButton(irr::core::rect<irr::s32>(750,680,1150, 680 + 60), 0, GUI_OPTION_GAME_BUTTON, L"Score");
  _Score->setDrawBorder(0);
  _Options = guienv->addButton(irr::core::rect<irr::s32>(750,750, 1150,750 + 60), 0, GUI_OPTION_GAME_BUTTON, L"Options");
  _Options->setDrawBorder(0);
  _Exit = guienv->addButton(irr::core::rect<irr::s32>(750, 820, 1150, 820 + 60), 0, GUI_ID_QUIT_BUTTON, L"Quit");
  _Exit->setDrawBorder(0);

  irr::scene::IAnimatedMesh* mesh = smgr->getMesh("./media/Bomberman/Bomberman/Bomberman.obj");
  irr::scene::IAnimatedMeshSceneNode* modelNode = smgr->addAnimatedMeshSceneNode(mesh);

  if (modelNode)
    {
      modelNode->setPosition(irr::core::vector3df(0.f, -20.f, -20.f));
      modelNode->setRotation(irr::core::vector3df(0.10f, 50.f, 0.f));
      modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      modelNode->setDebugDataVisible(irr::scene::EDS_OFF);
      modelNode->getMaterial(0).NormalizeNormals = true;
      modelNode->setFrameLoop(0, 14);
      modelNode->setAnimationSpeed(15);
      modelNode->setScale(modelNode->getScale() * 8.0f);
    }
  irr::video::ITexture* irrlichtBack = driver->getTexture(".media/bck.jpg");
  // irr::SKeyMap keyMap[5];                             // re-assigne les commandes

  // keyMap[0].Action = irr::EKA_MOVE_FORWARD;           // avancer
  // keyMap[0].KeyCode = irr::KEY_KEY_W;                 // w
  // keyMap[1].Action = irr::EKA_MOVE_BACKWARD;          // reculer
  // keyMap[1].KeyCode = irr::KEY_KEY_S;                 // s
  // keyMap[2].Action = irr::EKA_STRAFE_LEFT;            // a gauche
  // keyMap[2].KeyCode = irr::KEY_KEY_A;                 // a
  // keyMap[3].Action = irr::EKA_STRAFE_RIGHT;           // a droite
  // keyMap[3].KeyCode = irr::KEY_KEY_D;                 // d
  // keyMap[4].Action = irr::EKA_JUMP_UP;                // saut
  // keyMap[4].KeyCode = irr::KEY_SPACE;                 // barre espace

  // smgr->addCameraSceneNodeFPS(0, 0.0f, 0.1f, -1, keyMap, 5);

  smgr->addCameraSceneNode(0, irr::core::vector3df(45,0,0), irr::core::vector3df(0,0,10));
  while(_Mdevice->run() && driver)
    {
      if (_Mdevice->isWindowActive())
	{
	  driver->beginScene(true, true, irr::video::SColor(255,255,255,255));
	  if (irrlichtBack)
	    driver->draw2DImage(irrlichtBack, irr::core::position2d<int>(0,0));
	  smgr->drawAll();
	  guienv->drawAll();
	  driver->endScene();
	}
      else
	_Mdevice->yield();
    }
  _Mdevice->drop();
}

bool	MainMenu::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      irr::s32 id = event.GUIEvent.Caller->getID();
      irr::gui::IGUIEnvironment* env = _Mdevice->getGUIEnvironment();

      switch(event.GUIEvent.EventType)
	{
	case irr::gui::EGET_BUTTON_CLICKED:
	  switch(id)
	    {
	    case GUI_ID_QUIT_BUTTON:
	      _Mdevice->closeDevice();
	      return true;
	      break;
	    case GUI_NEW_GAME_BUTTON:
	      _Mdevice->closeDevice();
	      return true;
	      break;
	    case GUI_LOAD_GAME_BUTTON:
	      break;
	    case GUI_OPTION_GAME_BUTTON:
	      break;
	    }
	default:
	  break;
	}
    }
  return false;
}
