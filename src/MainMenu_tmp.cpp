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
  GUI_BACK_GAME_BUTTON,
  GUI_APPLY_GAME_BUTTON,
  GUI_YES_GAME_BUTTON,
  GUI_NO_GAME_BUTTON,
  GUI_SCROLL_BAR,
  GUI_RES_BUTTON
};

void	MainMenu::Menu()
{
  _irrlichtBack = _driver->getTexture("./media/Backgrounds/bck.jpg");
  //_logo_img = _guienv->addImage(_driver->getTexture("./media/Logos/blogo.png"), irr::core::position2d<int>(300, 80));

  _mesh = _smgr->getMesh("./media/knight/source/knight.b3d");
  _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);

  _dim = _guienv->getVideoDriver()->getScreenSize();

  if (_modelNode)
    {
      _modelNode->setPosition(irr::core::vector3df(0.f, -20.f, -20.f));
      _modelNode->setRotation(irr::core::vector3df(0.10f, -130.f, 0.f));
      _modelNode->setMaterialTexture(0, _driver->getTexture("media/knight/textures/Diffuse1024.jpg"));
      _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _modelNode->setScale(_modelNode->getScale() * 150.0f);
      _modelNode->setFrameLoop(1, 50);
      _modelNode->setAnimationSpeed(30);
    }

  _smgr->addCameraSceneNode(0, irr::core::vector3df(45,0,0), irr::core::vector3df(0,0,10));

  irr::scene::IBillboardTextSceneNode* textNode;

  _size = _guienv->addStaticText(L"", irr::core::rect<irr::s32>(10, 10,300,300));
  _size2 = _guienv->addStaticText(L"", irr::core::rect<irr::s32>(10, 50,300,300));

  _size->setText(irr::core::stringw(_dim.Width).c_str());
  _size2->setText(irr::core::stringw(_dim.Height).c_str());

  _elem = _guienv->addGUIElement("Button", 0);
  _NewGame = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 1080, 520, _dim.Height - 10, 560), _elem, GUI_NEW_GAME_BUTTON, L"New Game");
  _NewGame->setDrawBorder(0);
  _Load = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 1090, 590, _dim.Height, 630), _elem, GUI_LOAD_GAME_BUTTON, L"Load Game");
  _Load->setDrawBorder(0);
  _Score = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 1080, 660, _dim.Height - 10, 700), _elem, GUI_SCORE_GAME_BUTTON, L"Score");
  _Score->setDrawBorder(0);
  _Options = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 1080, 730, _dim.Height - 10, 770), _elem, GUI_OPTION_GAME_BUTTON, L"Options");
  _Options->setDrawBorder(0);
  _Exit = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 1080, 800, _dim.Height - 10, 840), _elem, GUI_ID_QUIT_BUTTON, L"Quit");
  _Exit->setDrawBorder(0);
  _NewGame->setAlignment( irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _Load->setAlignment( irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _Score->setAlignment( irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _Options->setAlignment( irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _Exit->setAlignment( irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
}

 bool	MainMenu::run()
{
  Menu();
  irr::core::stringw str = "Bomberman - Main Menu ";
  str += _Mdevice->getVersion();
  _Mdevice->setWindowCaption(str.c_str());

  //_logo_img = _guienv->addImage(_driver->getTexture("./media/Logos/blogo.png"), irr::core::position2d<int>(300, 80));
  irr::video::ITexture* images = _driver->getTexture("./media/Backgrounds/ships.jpg");
  _driver->makeColorKeyTexture(images, irr::core::position2d<irr::s32>(0,0));
  
  irr::core::rect<irr::s32> imp1(25,0,570,220);
  irr::core::rect<irr::s32> imp2(580,0,1128,220);

  _driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
  _driver->getMaterial2D().AntiAliasing=irr::video::EAAM_FULL_BASIC;

  _skin = _guienv->getSkin();
  _font = _guienv->getFont("./media/fonts/editundo.png");
  _irrlichtBack = _driver->getTexture("./media/Backgrounds/bck1.jpg");

  if (_font)
    {
      _guienv->getSkin()->setFont(_font);
      _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 255, 255, 0));
    }

  _smgr->addCameraSceneNode(0, irr::core::vector3df(45,0,0), irr::core::vector3df(0,0,10));
  irr::u32 x = 1890;
  irr::u32 y = 230;

  while(_Mdevice->run() && _driver)
    {
      if (_Mdevice->isWindowActive())
	{
	  irr::u32 time = _Mdevice->getTimer()->getTime();

	  _driver->beginScene(true, true, irr::video::SColor(255,255,255,255));
	  if (_irrlichtBack)
	    _driver->draw2DImage(_irrlichtBack, irr::core::position2d<int>(0,0));
	  _driver->draw2DImage(images, irr::core::position2d<irr::s32>(--x,y),
			       (time/400 % 2) ? imp1 : imp2, 0,
			       irr::video::SColor(255,255,255,255), true);
	  if (x == -550)
	    x = 1890;
	  _smgr->drawAll();
	  _guienv->drawAll();
	  _driver->endScene();
	}
      else
	_Mdevice->yield();
    }
  _Mdevice->drop();
}

void	MainMenu::NGame()
{
  _guienv->clear();
  _smgr->clear();
  _guienv->addStaticText(L"Players:", irr::core::rect<irr::s32>(_dim.Width - 1690, 130, _dim.Height - 550, 200));
  _guienv->addStaticText(L"IA:", irr::core::rect<irr::s32>(_dim.Width - 760, 130, _dim.Height + 380, 200));
  _guienv->addStaticText(L"Maps:", irr::core::rect<irr::s32>(_dim.Width - 1190, 410, _dim.Height - 130, 480));
  _Players = _guienv->addComboBox(irr::core::rect<irr::s32>( _dim.Width - 1330, 130, _dim.Height - 390, 200));
  _Players->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _IA = _guienv->addComboBox(irr::core::rect<irr::s32>( _dim.Width - 400, 130, _dim.Height + 540, 200));
  _IA->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);

  _Maps = _guienv->addListBox(irr::core::rect<irr::s32>(_dim.Width - 1580, 540, _dim.Height + 240, 830));

  if (_Maps)
    {
      _Maps->clear();

      irr::gui::IGUISpriteBank *bank;
      if ( 0 == bank )
	bank = _Mdevice->getGUIEnvironment()->addEmptySpriteBank("");

      irr::gui::SGUISprite sprite;
      irr::gui::SGUISpriteFrame frame;
      irr::video::IImage* image = 0;
      irr::video::ITexture *tex = 0;
      irr::core::rect<irr::s32> r;
      irr::core::dimension2du dim ( 128, 128 );

      bank->getSprites().clear();
      bank->getPositions().clear ();
      _Maps->setSpriteBank ( bank );

      irr::u32 g = 0;
      irr::core::stringw s;

      s = " ./media/map.jpg";
      image = _driver->createImageFromFile("./media/map.jpg");
      if (image)
	{
	  irr::video::IImage* filter = _driver->createImage ( irr::video::ECF_R8G8B8, dim );
	  image->copyToScalingBoxFilter ( filter, 0 );
	  image->drop ();
	  image = filter;
	}
      if ( image )
	{
	  tex = _driver->addTexture ("./media/map.jpg", image );
	  image->drop ();
	}
      bank->setTexture ( g, tex );
      r.LowerRightCorner.X = dim.Width;
      r.LowerRightCorner.Y = dim.Height;
      _Maps->setItemHeight ( r.LowerRightCorner.Y + 4 );
      frame.rectNumber = bank->getPositions().size();
      frame.textureNumber = g;

      bank->getPositions().push_back(r);

      sprite.Frames.set_used ( 0 );
      sprite.Frames.push_back(frame);
      sprite.frameTime = 0;
      bank->getSprites().push_back(sprite);

      _Maps->addItem ( s.c_str (), g );
      g += 1;
    }
  _back = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 640, 920, _dim.Height + 400, 970), 0, GUI_BACK_GAME_BUTTON, L"Back");
  _back->setDrawBorder(0);
}

void	MainMenu::LGame()
{
  _guienv->clear();
  _smgr->clear();
  _guienv->addStaticText(L"Load", irr::core::rect<irr::s32>(_dim.Width - 1510, 250, _dim.Height - 370, 300));
  _Maps = _guienv->addListBox(irr::core::rect<irr::s32>(_dim.Width - 1510, 360, _dim.Height + 250, 900));
  if (_Maps)
    {
      _Maps->clear();

      irr::gui::IGUISpriteBank *bank;
      if ( 0 == bank )
	bank = _Mdevice->getGUIEnvironment()->addEmptySpriteBank("");

      irr::gui::SGUISprite sprite;
      irr::gui::SGUISpriteFrame frame;
      irr::video::IImage* image = 0;
      irr::video::ITexture *tex = 0;
      irr::core::rect<irr::s32> r;
      irr::core::dimension2du dim ( 128, 128 );

      bank->getSprites().clear();
      bank->getPositions().clear ();
      _Maps->setSpriteBank ( bank );

      irr::u32 g = 0;
      irr::core::stringw s;

      s = " Save : Tatata t'est qui toi ?";
      image = _driver->createImageFromFile("./media/map.jpg");
      if (image)
	{
	  irr::video::IImage* filter = _driver->createImage ( irr::video::ECF_R8G8B8, dim );
	  image->copyToScalingBoxFilter ( filter, 0 );
	  image->drop ();
	  image = filter;
	}
      if ( image )
	{
	  tex = _driver->addTexture ("./media/map.jpg", image );
	  image->drop ();
	}
      bank->setTexture ( g, tex );
      r.LowerRightCorner.X = dim.Width;
      r.LowerRightCorner.Y = dim.Height;
      _Maps->setItemHeight ( r.LowerRightCorner.Y + 4 );
      frame.rectNumber = bank->getPositions().size();
      frame.textureNumber = g;

      bank->getPositions().push_back(r);

      sprite.Frames.set_used ( 0 );
      sprite.Frames.push_back(frame);
      sprite.frameTime = 0;
      bank->getSprites().push_back(sprite);

      _Maps->addItem ( s.c_str (), g );
      g += 1;
    }
  _back = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 640, 920, _dim.Height + 400, 970), 0, GUI_BACK_GAME_BUTTON, L"Back");
  _back->setDrawBorder(0);
}

void	MainMenu::Score()
{
  _guienv->clear();
  _smgr->clear();
  _guienv->addStaticText(L"Score", irr::core::rect<irr::s32>(_dim.Width - 1510, 250, _dim.Height - 370, 300));
  _ScoreB = _guienv->addListBox(irr::core::rect<irr::s32>(_dim.Width - 1510, 360, _dim.Height + 250, 900));
  if (_ScoreB)
    {
      irr::core::stringw s;
      
      s = "\n\n\n\n\n\nMao Zedong - 78000000\n";
      s += "Hitler - 17000000\n";
      s += "Stalin - 23000000\n";
      s += "Tatata - :)\n";
      s += "1 - 1\n";
      s += "2 - 2\n";
      s += "3 - 3";

      _ScoreB->addItem ( s.c_str ());
    }
  _back = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 640, 920, _dim.Height + 400, 970), 0, GUI_BACK_GAME_BUTTON, L"Back");
  _back->setDrawBorder(0);
}

void	MainMenu::GOptions()
{
  _guienv->clear();
  _smgr->clear();

  _irrlichtBack = _driver->getTexture("./media/Backgrounds/OptionsBck.jpg");
  _dim = _guienv->getVideoDriver()->getScreenSize();

  _guienv->addStaticText(L"Display", irr::core::rect<irr::s32>(_dim.Width - 1400, 280, _dim.Height - 380, 320));
  _guienv->addStaticText(L"Resolution", irr::core::rect<irr::s32>(_dim.Width - 1320, 350, _dim.Height - 240, 390));
  _guienv->addStaticText(L"Fullscreen", irr::core::rect<irr::s32>(_dim.Width - 1320, 410, _dim.Height - 220, 450));
  _guienv->addStaticText(L"VSync", irr::core::rect<irr::s32>(_dim.Width - 1320, 470, _dim.Height - 290, 510));
  _guienv->addStaticText(L"AA", irr::core::rect<irr::s32>(_dim.Width - 1320, 530, _dim.Height - 350, 570));
  _guienv->addStaticText(L"Audio", irr::core::rect<irr::s32>(_dim.Width - 1400, 600, _dim.Height - 380, 640));
  _guienv->addStaticText(L"Sound", irr::core::rect<irr::s32>(_dim.Width - 1340, 670, _dim.Height - 270, 710));
  _guienv->addStaticText(L"Music", irr::core::rect<irr::s32>(_dim.Width - 1340, 730, _dim.Height - 270, 770));
  _guienv->addStaticText(L"Effects", irr::core::rect<irr::s32>(_dim.Width - 1340, 790, _dim.Height - 270, 830));

  _guienv->addCheckBox(false, irr::core::rect<irr::s32>(_dim.Width - 870, 400, _dim.Height - 10, 470));
  _guienv->addCheckBox(false, irr::core::rect<irr::s32>(_dim.Width - 870, 460, _dim.Height - 10, 530));
  _guienv->addCheckBox(false, irr::core::rect<irr::s32>(_dim.Width - 870, 520, _dim.Height - 10, 590));
  // _Yes = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 960, 430, _dim.Height - 20 , 470), 0, GUI_YES_GAME_BUTTON, L"Yes");
  // _Yes->setDrawBorder(0);
  // _No = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 830, 430, _dim.Height + 110 , 470), 0, GUI_NO_GAME_BUTTON, L"No");
  // _No->setDrawBorder(0);

  _Resolution = _guienv->addComboBox(irr::core::rect<irr::s32>( _dim.Width - 980, 360, _dim.Height + 150, 400 ), 0, GUI_RES_BUTTON);
  _Resolution->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  //_SSound = _guienv->addScrollBar(true, irr::core::rect<irr::s32>( _dim.Width - 880, 510, _dim.Height - 10, 540 ), 0, GUI_SCROLL_BAR);
  irr::f32	SoundValue = 1.f;

  // _SSound->setMin ( 0 );
  // _SSound->setMax ( 100 );
  // _SSound->setSmallStep ( 1 );
  // _SSound->setLargeStep ( 10 );
  // _SSound->setPos ( irr::core::floor32 ( SoundValue * 100.f ) );
  // _Mdevice->setGammaRamp ( SoundValue, SoundValue, SoundValue, 0.f, 0.f );
  irr::video::IVideoModeList* vml = _Mdevice->getVideoModeList();
  for (irr::u32 i = 0; i < vml->getVideoModeCount(); i++)
    {
      irr::core::dimension2du r = vml->getVideoModeResolution(i);
      irr::s32 d = vml->getVideoModeDepth(i);

      if (r.Width >= 800 && r.Height >= 600 && d >= 16)
	{
	  irr::core::stringw s = "";

	  s += r.Width;
	  s += " x ";
	  s += r.Height;
	  _Resolution->addItem(s.c_str(), i);
	}
    }
  _back = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 640, 920, _dim.Height + 400, 970), 0, GUI_BACK_GAME_BUTTON, L"Back");
  _back->setDrawBorder(0);
  _Apply = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width - 380, 920, _dim.Height + 660 , 970), 0, GUI_APPLY_GAME_BUTTON, L"Apply");
  _Apply->setDrawBorder(0);
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
	      NGame();
	      break;
	    case GUI_LOAD_GAME_BUTTON:
	      LGame();
	      break;
	    case GUI_OPTION_GAME_BUTTON:
	      GOptions();
	      break;
	    case GUI_SCORE_GAME_BUTTON:
	      Score();
	      break;
	    case GUI_BACK_GAME_BUTTON:
	      _guienv->clear();
	      Menu();
	    case GUI_APPLY_GAME_BUTTON:
	      return true;
	      break;
	    case GUI_YES_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _Yes->setOverrideFont(_font);
	      return true;
	      break;
	    case GUI_NO_GAME_BUTTON:
	      _font = _guienv->getFont("./media/fonts/editundo_green.png");
	      _No->setOverrideFont(_font);
	      return true;
	      break;
	    }

	case irr::gui::EGET_SCROLL_BAR_CHANGED:
	  switch(id)
	    {
	    case GUI_SCROLL_BAR:
	      // Game->GammaValue = gui.Gamma->getPos () * 0.01f;
	      // Game->Device->setGammaRamp ( Game->GammaValue, Game->GammaValue, Game->GammaValue, 0.f, 0.f );
	      return true;
	      break;
	    }
	case irr::gui::EGET_COMBO_BOX_CHANGED:
	  switch(id)
	    {
	    case GUI_RES_BUTTON:
	      irr::u32 val = _Resolution->getItemData (_Resolution->getSelected());
	      _opts.setWidth(val >> 16);
	      _opts.setHeight(val & 0xFFFF);
	      _params.WindowSize = irr::core::dimension2d<irr::u32>(_opts.getWidth(), _opts.getHeight());
	      return true;
	      break;
	    }
	default:
	  break;
	}
    }
  return false;
}
