/*
** MainMenu.cpp for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 18:40:29 2017 Tanguy Lelievre
** Last update	Tue May 09 18:48:39 2017 Tanguy Lelievre
*/

#include "MainMenu.hh"

MainMenu::MainMenu(bool f, bool m, bool s, bool a, bool v, bool fsaa, irr::video::E_DRIVER_TYPE d)
{
  int x = 1900;
  int y = 1080;

  _params.WindowSize = irr::core::dimension2d<irr::u32>(x, y);
  _params.Bits = 32;
  _params.Fullscreen = f;
  _params.Stencilbuffer = s;
  _params.DriverType = d;
  _params.Vsync = v;
  _params.AntiAlias = a?8:0;
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
  _logo_img = guienv->addImage(driver->getTexture("./media/blogo.png"), irr::core::position2d<int>(10, 10));

  irr::gui::IGUISkin* skin = guienv->getSkin();
  irr::gui::IGUIFont* font = guienv->getFont("./media/fonts/fonts.xml");

  if (font)
    {
      guienv->getSkin()->setFont(font);
      skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 255, 255, 0));
    }

  _NewGame = guienv->addButton(irr::core::rect<irr::s32>(200,190,590,190 + 60), 0, GUI_NEW_GAME_BUTTON, L"New Game");
  //_NewGame->setDrawBorder(0);
  _Load = guienv->addButton(irr::core::rect<irr::s32>(200,260,590,260 + 60), 0, GUI_LOAD_GAME_BUTTON, L"Load Game");
  //_Load->setDrawBorder(0);
  _Score = guienv->addButton(irr::core::rect<irr::s32>(200,330,590,330 + 60), 0, GUI_OPTION_GAME_BUTTON, L"Score");
  //_Score->setDrawBorder(0);
  _Options = guienv->addButton(irr::core::rect<irr::s32>(200,400,590,400 + 60), 0, GUI_OPTION_GAME_BUTTON, L"Options");
  //_Options->setDrawBorder(0);
  _Exit = guienv->addButton(irr::core::rect<irr::s32>(200,470,590,470 + 60), 0, GUI_ID_QUIT_BUTTON, L"Quit");
  //_Exit->setDrawBorder(0);

  irr::scene::IAnimatedMesh* mesh = smgr->getMesh("./media/Bomberman/Bomberman/Bomberman.obj");
  irr::scene::IAnimatedMeshSceneNode* modelNode = smgr->addAnimatedMeshSceneNode(mesh);
  irr::video::ITexture* irrlichtBack = driver->getTexture(".media/bck.jpg");

  if (modelNode)
    {
      modelNode->setPosition(irr::core::vector3df(0.f, 0.f, -6.f) );
      modelNode->setMaterialTexture(0, driver->getTexture("./media/Bomberman/Bomberman/Bomberman/Textures/Body.png"));
      modelNode->setMD2Animation(irr::scene::EMAT_STAND);
    }

  modelNode->setScale(modelNode->getScale() * 8.0f);
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
