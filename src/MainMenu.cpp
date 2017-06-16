/*
** MainMenu.cpp for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 18:40:29 2017 Tanguy Lelievre
** Last update	Fri Jun 16 16:28:06 2017 Tanguy Lelievre
*/

#include "MainMenu.hh"
#include "Game.hpp"

MainMenu::MainMenu() : _opts()
{
  _Mdevice = 0;
  createWindow();
}

irr::s32	**MainMenu::getMap() const
{
}

void     MainMenu::prepareGUI()
{
  _rootGUI     = _guienv->getRootGUIElement();
  _GOptionGUI  = new irr::gui::IGUIElement(irr::gui::EGUIET_TAB, _guienv, _rootGUI, GUI_OPTION_MENU_ELEMENT, irr::core::rect<irr::s32>(0, 0, _opts.getWidth(), _opts.getHeight()));
  _LoadGameGUI = new irr::gui::IGUIElement(irr::gui::EGUIET_TAB, _guienv, _rootGUI, GUI_LOAD_GAME_MENU_ELEMENT, irr::core::rect<irr::s32>(0, 0, _opts.getWidth(), _opts.getHeight()));
  _NewGameGUI  = new irr::gui::IGUIElement(irr::gui::EGUIET_TAB, _guienv, _rootGUI, GUI_NEW_GAME_MENU_ELEMENT, irr::core::rect<irr::s32>(0, 0, _opts.getWidth(), _opts.getHeight()));
  _MainMenuGUI = new irr::gui::IGUIElement(irr::gui::EGUIET_TAB, _guienv, _rootGUI, GUI_MAIN_MENU_ELEMENT, irr::core::rect<irr::s32>(0, 0, _opts.getWidth(), _opts.getHeight()));
  _ScoreGUI    = new irr::gui::IGUIElement(irr::gui::EGUIET_TAB, _guienv, _rootGUI, GUI_SCORE_MENU_ELEMENT, irr::core::rect<irr::s32>(0, 0, _opts.getWidth(), _opts.getHeight()));

  _rootGUI->addChild(_GOptionGUI);
  _rootGUI->addChild(_LoadGameGUI);
  _rootGUI->addChild(_NewGameGUI);
  _rootGUI->addChild(_MainMenuGUI);

  _MainMenuGUI->setVisible(true);
  _LoadGameGUI->setVisible(false);
  _NewGameGUI->setVisible(false);
  _GOptionGUI->setVisible(false);

  MainMenuGUI();
  GOptionsGUI();
  // LoadGameGUI();
  NewGameGUI();
  ScoreGUI();
}

void	MainMenu::ScoreGUI()
{
  Score	score;
  const irr::core::array<irr::s32>	points = score.getScores();
  const irr::core::array<irr::core::stringc>	pseudos = score.getPseudos();
  _image = _driver->createImageFromFile("./media/Backgrounds/OptionsBck.jpg");
  if (_image)
  {
    irr::video::IImage   *filter = _driver->createImage(irr::video::ECF_R8G8B8, irr::core::dimension2d<irr::u32>(_dim.Width, _dim.Height));
    _image->copyToScalingBoxFilter(filter, 0);
    _image->drop();
    _image = filter;
    _guienv->addImage(_driver->addTexture("./media/Backgrounds/OptionsBck.jpg", _image), irr::core::position2d<irr::s32>(0, 0), true, _ScoreGUI);
  }

  _guienv->addStaticText(L"Scores :", irr::core::rect<irr::s32>(_dim.Width / 2.25, _dim.Height / 7.2, _dim.Width / 1.75, _dim.Height / 3.5),	   false, true, _ScoreGUI);
  _listbox = _guienv->addListBox(irr::core::rect<irr::s32>(_dim.Width / 7, _dim.Height / 3.5, _dim.Width / 1.8, _dim.Height / 1.2), _ScoreGUI, GUI_SCORE_PSEUDO_LISTBOX, true);
  //_listbox->setDrawBackground(false);

  irr::s32	i;
  irr::core::stringw data;

  i = 0;
  while (i < pseudos.size() && i < 10)
  {
    data = pseudos[i];
    _listbox->addItem(data.c_str(), 0);
    i++;
  }

  _listbox = _guienv->addListBox(irr::core::rect<irr::s32>(_dim.Width / 1.8, _dim.Height / 3.5, _dim.Width, _dim.Height / 1.2), _ScoreGUI, GUI_SCORE_POINTS_LISTBOX, true);
  //_listbox->setDrawBackground(false);

  i = 0;
  while (i < points.size() && i < 10)
  {
    data = irr::core::stringw(points[i]);
    _listbox->addItem(data.c_str(), 0);
    i++;
  }


  _button = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width / 1.5, _dim.Height / 1.07, _dim.Width / 1.3, _dim.Height / 1.03), _ScoreGUI, GUI_BACK_SCORE_BUTTON, L"Back");
  _button->setDrawBorder(0);
}

void     MainMenu::NewGameGUI()
{
  _image = _driver->createImageFromFile("./media/Backgrounds/bck.jpg");
  if (_image)
  {
    irr::video::IImage   *filter = _driver->createImage(irr::video::ECF_R8G8B8, irr::core::dimension2d<irr::u32>(_dim.Width, _dim.Height));
    _image->copyToScalingBoxFilter(filter, 0);
    _image->drop();
    _image = filter;
    _guienv->addImage(_driver->addTexture("./media/Backgrounds/bck.jpg", _image), irr::core::position2d<irr::s32>(0, 0), true, _NewGameGUI);
  }

  _guienv->addStaticText(L"Players:", irr::core::rect<irr::s32>(_dim.Width / 4, _dim.Height / 7.2, _dim.Width / 2, _dim.Height / 3.5),	   false, true, _NewGameGUI);
  _guienv->addStaticText(L"IA:",      irr::core::rect<irr::s32>(_dim.Width / 4, _dim.Height / 3.5, _dim.Width / 2, _dim.Height / 2.5),	   false, true, _NewGameGUI);
  _guienv->addStaticText(L"Maps:",    irr::core::rect<irr::s32>(_dim.Width / 2.15, _dim.Height / 2.3, _dim.Width / 1.85, _dim.Height / 2), false, true, _NewGameGUI);

  _combobox = _guienv->addComboBox(irr::core::rect<irr::s32>(_dim.Width / 2, _dim.Height / 7.2, _dim.Width / 1.4, _dim.Height / 5.5), _NewGameGUI, GUI_NBPLAYER_COMBOBOX);
  _combobox->setMaxSelectionRows(2);

  _combobox->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _combobox->addItem(L"\t0", 0);
  _combobox->addItem(L"\t1", 1);
  _combobox->addItem(L"\t2", 2);

  _combobox = _guienv->addComboBox(irr::core::rect<irr::s32>(_dim.Width / 2, _dim.Height / 3.5, _dim.Width / 1.4, _dim.Height / 3), _NewGameGUI, GUI_NBIA_COMBOBOX);
  _combobox->setMaxSelectionRows(2);

  _combobox->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  _combobox->addItem(L"\t0", 0);
  _combobox->addItem(L"\t1", 1);
  _combobox->addItem(L"\t2", 2);
  _combobox->addItem(L"\t3", 3);
  _combobox->addItem(L"\t4", 4);

  _listbox = _guienv->addListBox(irr::core::rect<irr::s32>(_dim.Width / 6, _dim.Height / 2, _dim.Width / 1.2, _dim.Height / 1.2), _NewGameGUI, GUI_MAP_LISTBOX, true);
  irr::gui::IGUISpriteBank   *bank;
  if (0 == bank)
    bank = _Mdevice->getGUIEnvironment()->addEmptySpriteBank("");

  irr::gui::SGUISprite   sprite;
  irr::gui::SGUISpriteFrame   frame;
  irr::video::IImage   *image	     = 0;
  irr::video::ITexture   *tex	     = 0;
  irr::io::IFileSystem   *fileSystem = 0;
  irr::io::IFileList   *fileList;
  irr::core::rect<irr::s32>   r(0, 0, 160, 90);

  bank->getSprites().clear();
  bank->getPositions().clear();
  _listbox->setSpriteBank(bank);

  irr::u32   g = 0;
  irr::core::stringw   s;

  DIR   *dir;

  dir = opendir("./media/maps/");
  struct dirent   *f;
  fileSystem = _Mdevice->getFileSystem();

  if (dir)
  {
    while (f = readdir(dir))
    {
      if (f->d_type == DT_REG)
      {
	irr::io::path   filename(f->d_name);
	if (filename.find(".bbm"))
	{
	  cutFilenameExtension(filename, filename);
	  s = filename;
	  irr::io::path   scr("./media/maps/screenshots/");
	  scr += filename;
	  scr += ".jpg";

	  irr::core::dimension2du   dim(160, 90);

	  if (fileSystem->existFile(scr))
	    image = _driver->createImageFromFile(scr);
	  if (image)
	  {
	    irr::video::IImage   *filter = _driver->createImage(irr::video::ECF_R8G8B8, dim);
	    image->copyToScalingBoxFilter(filter, 0);
	    image->drop();
	    image = filter;
	  }
	  if (image)
	  {
	    tex = _driver->addTexture(filename, image);
	    image->drop();
	  }

	  bank->setTexture(g, tex);

	  r.LowerRightCorner.X = dim.Width;
	  r.LowerRightCorner.Y = dim.Height;
	  _listbox->setItemHeight(r.LowerRightCorner.Y + 4);
	  frame.rectNumber    = bank->getPositions().size();
	  frame.textureNumber = g;

	  bank->getPositions().push_back(r);

	  sprite.Frames.set_used(0);
	  sprite.Frames.push_back(frame);
	  sprite.frameTime = 0;
	  bank->getSprites().push_back(sprite);

	  _listbox->addItem(s.c_str(), g);
	  g += 1;
	}
      }
    }
    closedir(dir);
  }

  _button = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width / 1.5, _dim.Height / 1.07, _dim.Width / 1.3, _dim.Height / 1.03), _NewGameGUI, GUI_BACK_NEW_GAME_BUTTON, L"Back");
  _button->setDrawBorder(0);
  _button = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width / 1.3, _dim.Height / 1.07, _dim.Width / 1.1, _dim.Height / 1.03), _NewGameGUI, GUI_START_NEW_GAME_BUTTON, L"Start");
  _button->setDrawBorder(0);
}

void     MainMenu::createWindow()
{
  _params.WindowSize	= irr::core::dimension2d<irr::u32>(_opts.getWidth(), _opts.getHeight());
  _params.Bits		= 32;
  _params.Fullscreen	= _opts.getFullscreen();
  _params.Stencilbuffer = false;
  _params.DriverType	= irr::video::EDT_OPENGL;
  _params.Vsync		= _opts.getVsync();
  _params.AntiAlias	= _opts.getAA() ? 8 : 0;
  _params.EventReceiver = this;
  irr::core::stringw   str = "Bomberman - ";

  _Mdevice = createDeviceEx(_params);
  if (!_Mdevice)
    return;

  _Mdevice->setResizable(false);
  _driver = _Mdevice->getVideoDriver();
  _smgr	  = _Mdevice->getSceneManager();
  _guienv = _Mdevice->getGUIEnvironment();

  str += _Mdevice->getVersion();
  _Mdevice->setWindowCaption(str.c_str());

  _skin = _guienv->getSkin();
  _font = _guienv->getFont("./media/fonts/editundo.png");

  if (_font)
  {
    _guienv->getSkin()->setFont(_font);
    _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 255, 255, 0));
  }
  _dim	= _guienv->getVideoDriver()->getScreenSize();
  _quit = false;
  prepareGUI();
}

void     MainMenu::GOptionsGUI()
{
  _image = _driver->createImageFromFile("./media/Backgrounds/OptionsBck.jpg");
  if (_image)
  {
    irr::video::IImage   *filter = _driver->createImage(irr::video::ECF_R8G8B8, irr::core::dimension2d<irr::u32>(_dim.Width, _dim.Height));
    _image->copyToScalingBoxFilter(filter, 0);
    _image->drop();
    _image = filter;
    _guienv->addImage(_driver->addTexture("./media/Backgrounds/OptionsBck.jpg", _image), irr::core::position2d<irr::s32>(0, 0), true, _GOptionGUI);
  }

  _guienv->addStaticText(L"Display",	irr::core::rect<irr::s32>(_dim.Width / 5, _dim.Height / 6, _dim.Width / 2, _dim.Height / 4.7),	    false, true, _GOptionGUI);
  _guienv->addStaticText(L"Resolution", irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 4, _dim.Width / 2, _dim.Height / 3.3),    false, true, _GOptionGUI);
  _guienv->addStaticText(L"Fullscreen", irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 3.15, _dim.Width / 2, _dim.Height / 2.7), false, true, _GOptionGUI);
  _guienv->addStaticText(L"VSync",	irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 2.6, _dim.Width / 2, _dim.Height / 2.3),  false, true, _GOptionGUI);
  _guienv->addStaticText(L"AA",		irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 2.2, _dim.Width / 2, _dim.Height / 2),    false, true, _GOptionGUI);
  _guienv->addStaticText(L"Audio",	irr::core::rect<irr::s32>(_dim.Width / 5, _dim.Height / 1.8, _dim.Width / 2, _dim.Height / 1.6),    false, true, _GOptionGUI);
  _guienv->addStaticText(L"Sound",	irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 1.57, _dim.Width / 2, _dim.Height / 1.2), false, true, _GOptionGUI);
  _guienv->addStaticText(L"Music",	irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 1.43, _dim.Width / 2, _dim.Height / 1.2), false, true, _GOptionGUI);
  _guienv->addStaticText(L"Effects",	irr::core::rect<irr::s32>(_dim.Width / 4.5, _dim.Height / 1.3, _dim.Width / 2, _dim.Height / 1.2),  false, true, _GOptionGUI);

  _guienv->addCheckBox(_opts.getFullscreen(), irr::core::rect<irr::s32>(_dim.Width / 1.5, _dim.Height / 3.15, _dim.Width / 1.4, _dim.Height / 2.7), _GOptionGUI, GUI_FULLSCREEN_CHECKBOX);
  _guienv->addCheckBox(_opts.getAA(),	      irr::core::rect<irr::s32>(_dim.Width / 1.5, _dim.Height / 2.2, _dim.Width / 1.4, _dim.Height / 2),    _GOptionGUI, GUI_AA_CHECKBOX);
  _guienv->addCheckBox(_opts.getVsync(),      irr::core::rect<irr::s32>(_dim.Width / 1.5, _dim.Height / 2.6, _dim.Width / 1.4, _dim.Height / 2.3),  _GOptionGUI, GUI_VSYNC_CHECKBOX);

  _combobox = _guienv->addComboBox(irr::core::rect<irr::s32>(_dim.Width / 2, _dim.Height / 4, _dim.Width / 1.4, _dim.Height / 3.3), _GOptionGUI, GUI_RES_COMBOBOX);
  _combobox->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
  irr::f32   SoundValue = 1.f;

  _scrollbar = _guienv->addScrollBar(true, irr::core::rect<irr::s32>(_dim.Width / 2, _dim.Height / 1.57, _dim.Width / 1.4, _dim.Height / 1.5), _GOptionGUI, GUI_SOUND_LEVEL_SCROLLBAR);
  _guienv->addCheckBox(_opts.getSoundMute(), irr::core::rect<irr::s32>(_dim.Width / 1.37, _dim.Height / 1.57, _dim.Width / 1.3, _dim.Height / 1.5), _GOptionGUI, GUI_SOUND_MUTE_CHECKBOX);
  _scrollbar->setMin(0);
  _scrollbar->setMax(100);
  _scrollbar->setSmallStep(1);
  _scrollbar->setLargeStep(10);
  _scrollbar->setPos(irr::core::floor32(SoundValue * 50.f));
  _scrollbar = _guienv->addScrollBar(true, irr::core::rect<irr::s32>(_dim.Width / 2, _dim.Height / 1.43, _dim.Width / 1.4, _dim.Height / 1.37), _GOptionGUI, GUI_MUSIC_LEVEL_SCROLLBAR);
  _guienv->addCheckBox(_opts.getMusicMute(), irr::core::rect<irr::s32>(_dim.Width / 1.37, _dim.Height / 1.43, _dim.Width / 1.3, _dim.Height / 1.37), _GOptionGUI, GUI_MUSIC_MUTE_CHECKBOX);
  _scrollbar->setMin(0);
  _scrollbar->setMax(100);
  _scrollbar->setSmallStep(1);
  _scrollbar->setLargeStep(10);
  _scrollbar->setPos(irr::core::floor32(SoundValue * 50.f));
  _scrollbar = _guienv->addScrollBar(true, irr::core::rect<irr::s32>(_dim.Width / 2, _dim.Height / 1.3, _dim.Width / 1.4, _dim.Height / 1.25), _GOptionGUI, GUI_EFFECTS_LEVEL_SCROLLBAR);
  _guienv->addCheckBox(_opts.getEffectsMute(), irr::core::rect<irr::s32>(_dim.Width / 1.37, _dim.Height / 1.3, _dim.Width / 1.3, _dim.Height / 1.25), _GOptionGUI, GUI_EFFECTS_MUTE_CHECKBOX);
  _scrollbar->setMin(0);
  _scrollbar->setMax(100);
  _scrollbar->setSmallStep(1);
  _scrollbar->setLargeStep(10);
  _scrollbar->setPos(irr::core::floor32(SoundValue * 50.f));

  irr::u16   w	  = 1920;
  irr::u16   h	  = 1080;
  irr::u32   data = w << 16 | h;
  _combobox->addItem(L"1920 x 1080", data);
  w    = 1600;
  h    = 900;
  data = w << 16 | h;
  _combobox->addItem(L"1600 x 900", data);
  w    = 1280;
  h    = 720;
  data = w << 16 | h;
  _combobox->addItem(L"1280 x 720", data);
  w    = _opts.getWidth();
  h    = _opts.getHeight();
  data = w << 16 | h;
  _combobox->setSelected(_combobox->getIndexForItemData(data));
  _button = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width / 1.5, _dim.Height / 1.07, _dim.Width / 1.3, _dim.Height / 1.03), _GOptionGUI, GUI_BACK_OPTIONS_BUTTON, L"Back");
  _button->setDrawBorder(0);
  _button = _guienv->addButton(irr::core::rect<irr::s32>(_dim.Width / 1.3, _dim.Height / 1.07, _dim.Width / 1.1, _dim.Height / 1.03), _GOptionGUI, GUI_APPLY_BUTTON, L"Apply");
  _button->setDrawBorder(0);
}

void     MainMenu::MainMenuGUI()
{
  _image = _driver->createImageFromFile("./media/Backgrounds/bck.jpg");
  if (_image)
  {
    irr::video::IImage   *filter = _driver->createImage(irr::video::ECF_R8G8B8, irr::core::dimension2d<irr::u32>(_dim.Width, _dim.Height));
    _image->copyToScalingBoxFilter(filter, 0);
    _image->drop();
    _image = filter;
    _guienv->addImage(_driver->addTexture("./media/Backgrounds/bck.jpg", _image), irr::core::position2d<irr::s32>(0, 0), true, _MainMenuGUI);
  }

  _button = _guienv->addButton(irr::core::rect<irr::s32>((_dim.Width / 2) - 200, (_dim.Height / 2) - 50, (_dim.Width / 2) + 200, (_dim.Height / 2) + 10), _MainMenuGUI, GUI_NEW_GAME_BUTTON, L"New Game");
  _button->setDrawBorder(0);
  _button = _guienv->addButton(irr::core::rect<irr::s32>((_dim.Width / 2) - 200, (_dim.Height / 2) + 20, (_dim.Width / 2) + 200, (_dim.Height / 2) + 80), _MainMenuGUI, GUI_LOAD_GAME_BUTTON, L"Load Game");
  _button->setDrawBorder(0);
  _button = _guienv->addButton(irr::core::rect<irr::s32>((_dim.Width / 2) - 200, (_dim.Height / 2) + 90, (_dim.Width / 2) + 200, (_dim.Height / 2) + 150), _MainMenuGUI, GUI_SCORE_BUTTON, L"Score");
  _button->setDrawBorder(0);
  _button = _guienv->addButton(irr::core::rect<irr::s32>((_dim.Width / 2) - 200, (_dim.Height / 2) + 160, (_dim.Width / 2) + 200, (_dim.Height / 2) + 220), _MainMenuGUI, GUI_OPTION_BUTTON, L"Options");
  _button->setDrawBorder(0);
  _button = _guienv->addButton(irr::core::rect<irr::s32>((_dim.Width / 2) - 200, (_dim.Height / 2) + 230, (_dim.Width / 2) + 200, (_dim.Height / 2) + 290), _MainMenuGUI, GUI_QUIT_BUTTON, L"Quit");
  _button->setDrawBorder(0);
}

MainMenu::~MainMenu() {}

void     MainMenu::Menu()
{
  _mesh	     = _smgr->getMesh("./media/knight/source/knight.b3d");
  _modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);

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

  _smgr->addCameraSceneNode(0, irr::core::vector3df(45, 0, 0), irr::core::vector3df(0, 0, 10));
}

void     MainMenu::optsChange()
{
  _combobox = (irr::gui::IGUIComboBox*)_GOptionGUI->getElementFromId(GUI_RES_COMBOBOX, true);
  irr::u32   val = _combobox->getItemData(_combobox->getSelected());
  std::cout << val << std::endl;
  irr::s16   h = val & 0xFFFF;
  irr::s16   w = val >> 16;

  if ((((irr::gui::IGUICheckBox*)_GOptionGUI->getElementFromId(GUI_FULLSCREEN_CHECKBOX, true))->isChecked() != _opts.getFullscreen()) ||
      (((irr::gui::IGUICheckBox*)_GOptionGUI->getElementFromId(GUI_VSYNC_CHECKBOX, true))->isChecked() != _opts.getVsync()) ||
      (((irr::gui::IGUICheckBox*)_GOptionGUI->getElementFromId(GUI_AA_CHECKBOX, true))->isChecked() != _opts.getAA()) ||
      (h != _opts.getHeight()) || (w != _opts.getWidth()))
  {
    _opts.setFullscreen(((irr::gui::IGUICheckBox*)_GOptionGUI->getElementFromId(GUI_FULLSCREEN_CHECKBOX, true))->isChecked());
    _opts.setVsync(((irr::gui::IGUICheckBox*)_GOptionGUI->getElementFromId(GUI_VSYNC_CHECKBOX, true))->isChecked());
    _opts.setAA(((irr::gui::IGUICheckBox*)_GOptionGUI->getElementFromId(GUI_AA_CHECKBOX, true))->isChecked());
    _opts.setHeight(h);
    _opts.setWidth(w);
    _opts.saveConf();
    _quit = 1;
    _Mdevice->closeDevice();
  }
}

irr::s32     MainMenu::run()
{
  while (_Mdevice->run() && _driver)
  {
    if (_Mdevice->isWindowActive())
    {
      _driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
      _guienv->drawAll();
      _smgr->drawAll();
      _driver->endScene();
    }
    else
      _Mdevice->yield();
  }
  _Mdevice->drop();
  return (_quit);
}

void	 MainMenu::OptionMenu()
{
  _MainMenuGUI->setVisible(false);
  _GOptionGUI->setVisible(true);
}

bool	 MainMenu::OnEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32   id		     = event.GUIEvent.Caller->getID();
    irr::gui::IGUIEnvironment   *env = _Mdevice->getGUIEnvironment();

    switch (event.GUIEvent.EventType)
    {
    case irr::gui::EGBS_BUTTON_MOUSE_OVER:

      switch (id)
      {
      case GUI_NEW_GAME_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo_green.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_NEW_GAME_BUTTON, true);
	_button->setOverrideFont(_font);

	_mesh	   = _smgr->getMesh("./media/Bombs/FireBomb/Bomb.obj");
	_modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_ani	   = _smgr->createRotationAnimator(irr::core::vector3df(0, 1, 0));
	_modelNode->addAnimator(_ani);
	if (_modelNode)
	{
	  _modelNode->setPosition(irr::core::vector3df(-30.f, -6.5f, 36.f));
	  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  _modelNode->setScale(_modelNode->getScale() * 0.50f);
	}
	return (true);
	break;

      case GUI_LOAD_GAME_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo_green.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_LOAD_GAME_BUTTON, true);
	_button->setOverrideFont(_font);

	_mesh	   = _smgr->getMesh("./media/Bombs/AquaBomb/AquaBomb.obj");
	_modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_ani	   = _smgr->createRotationAnimator(irr::core::vector3df(0, 1, 0));
	_modelNode->addAnimator(_ani);
	if (_modelNode)
	{
	  _modelNode->setPosition(irr::core::vector3df(-30.f, -14.5f, 36.f));
	  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  _modelNode->setScale(_modelNode->getScale() * 0.50f);
	}
	return (true);
	break;

      case GUI_SCORE_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo_green.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_SCORE_BUTTON, true);
	_button->setOverrideFont(_font);

	_mesh	   = _smgr->getMesh("./media/Bombs/IceBomb/IceBomb.obj");
	_modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_ani	   = _smgr->createRotationAnimator(irr::core::vector3df(0, 1, 0));
	_modelNode->addAnimator(_ani);
	if (_modelNode)
	{
	  _modelNode->setPosition(irr::core::vector3df(-30.f, -22.5f, 36.f));
	  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  _modelNode->setScale(_modelNode->getScale() * 0.50f);
	}
	return (true);
	break;

      case GUI_OPTION_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo_green.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_OPTION_BUTTON, true);
	_button->setOverrideFont(_font);

	_mesh	   = _smgr->getMesh("./media/Bombs/PowerBomb/PowerBomb.obj");
	_modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_ani	   = _smgr->createRotationAnimator(irr::core::vector3df(0, 1, 0));
	_modelNode->addAnimator(_ani);
	if (_modelNode)
	{
	  _modelNode->setPosition(irr::core::vector3df(-30.f, -30.5f, 36.f));
	  _modelNode->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  _modelNode->setScale(_modelNode->getScale() * 0.50f);
	}
	return (true);
	break;

      case GUI_QUIT_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo_green.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_QUIT_BUTTON, true);
	_button->setOverrideFont(_font);

	_mesh	   = _smgr->getMesh("./media/Bombs/MegaBomb/MegaBomb.obj");
	_modelNode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_ani	   = _smgr->createRotationAnimator(irr::core::vector3df(0, 1, 0));
	_modelNode->addAnimator(_ani);
	if (_modelNode)
	{
	  _modelNode->setPosition(irr::core::vector3df(-30.f, -38.5f, 36.f));
	  _modelNode->setRotation(irr::core::vector3df(0.f, -10.f, 30.f));
	  _modelNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  _modelNode->setScale(_modelNode->getScale() * 0.50f);
	}
	return (true);
	break;

  case GUI_START_NEW_GAME_BUTTON:
    break;
      }
      break;

    case irr::gui::EGBS_BUTTON_MOUSE_OFF:

      switch (id)
      {
      case GUI_NEW_GAME_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_NEW_GAME_BUTTON, true);
	_button->setOverrideFont(_font);
	_ani->drop();
	_smgr->addToDeletionQueue(_modelNode);
	return (true);
	break;

      case GUI_LOAD_GAME_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_LOAD_GAME_BUTTON, true);
	_button->setOverrideFont(_font);
	_ani->drop();
	_smgr->addToDeletionQueue(_modelNode);
	return (true);
	break;

      case GUI_SCORE_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_SCORE_BUTTON, true);
	_button->setOverrideFont(_font);
	_ani->drop();
	_smgr->addToDeletionQueue(_modelNode);
	return (true);
	break;

      case GUI_OPTION_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_OPTION_BUTTON, true);
	_button->setOverrideFont(_font);
	_ani->drop();
	_smgr->addToDeletionQueue(_modelNode);
	return (true);
	break;

      case GUI_QUIT_BUTTON:
	_font	= _guienv->getFont("./media/fonts/editundo.png");
	_button = (irr::gui::IGUIButton*)_MainMenuGUI->getElementFromId(GUI_QUIT_BUTTON, true);
	_button->setOverrideFont(_font);
	_ani->drop();
	_smgr->addToDeletionQueue(_modelNode);
	return (true);
	break;
      }
      break;

    case irr::gui::EGET_BUTTON_CLICKED:

      switch (id)
      {
      case GUI_QUIT_BUTTON:
      {
	_Mdevice->closeDevice();
	_quit = 0;
	return (true);
	break;
      }

      case GUI_START_NEW_GAME_BUTTON:
      {
        _Mdevice->closeDevice();
        _quit = 2;
      }

      case GUI_NEW_GAME_BUTTON:
      {
	_MainMenuGUI->setVisible(false);
	_NewGameGUI->setVisible(true);
	return (true);
	break;
      }

      case GUI_LOAD_GAME_BUTTON:
      {
	break;
      }

      case GUI_OPTION_BUTTON:
      {
	_MainMenuGUI->setVisible(false);
	_GOptionGUI->setVisible(true);
	break;
      }

      case GUI_SCORE_BUTTON:
      {
        _MainMenuGUI->setVisible(false);
        _ScoreGUI->setVisible(true);
        break;
      }

      case GUI_BACK_OPTIONS_BUTTON:
      {
	_GOptionGUI->setVisible(false);
	_MainMenuGUI->setVisible(true);
      }

      case GUI_BACK_NEW_GAME_BUTTON:
      {
	_NewGameGUI->setVisible(false);
	_MainMenuGUI->setVisible(true);
	break;
      }

      case GUI_BACK_SCORE_BUTTON:
      {
        _ScoreGUI->setVisible(false);
        _MainMenuGUI->setVisible(true);
      }

      case GUI_APPLY_BUTTON:
      {
	optsChange();
	break;
      }
      }
      break;

    case irr::gui::EGET_COMBO_BOX_CHANGED:

      switch (id)
      {
      case GUI_NBPLAYER_COMBOBOX:
      {
	irr::s32   i;

	_combobox = (irr::gui::IGUIComboBox*)_NewGameGUI->getElementFromId(GUI_NBPLAYER_COMBOBOX, true);
	i	  = _combobox->getItemData(_combobox->getSelected());
	_combobox = (irr::gui::IGUIComboBox*)_NewGameGUI->getElementFromId(GUI_NBIA_COMBOBOX, true);
  if (i == 0)
  {
    if (_combobox->getItemCount() == 3)
      _combobox->addItem(L"\t3", 3);
    if (_combobox->getItemCount() == 4)
      _combobox->addItem(L"\t4", 4);
  }
	else if (i == 1)
  {
    if (_combobox->getItemCount() == 3)
      _combobox->addItem(L"\t3", 3);
    _combobox->removeItem(4);
  }
	else if (i == 2)
	{
    std::cout << _combobox->getItemCount() << std::endl;
	  _combobox->removeItem(4);
    _combobox->removeItem(3);
	}
	break;
      }

      case GUI_NBIA_COMBOBOX:
      {
	irr::s32   i;

  _combobox = (irr::gui::IGUIComboBox*)_NewGameGUI->getElementFromId(GUI_NBIA_COMBOBOX, true);
	i	  = _combobox->getItemData(_combobox->getSelected());
  _combobox = (irr::gui::IGUIComboBox*)_NewGameGUI->getElementFromId(GUI_NBPLAYER_COMBOBOX, true);
	if (i == 0 || i == 1 || i == 2)
	{
    if (_combobox->getItemCount() == 1)
      _combobox->addItem(L"\t1", 1);
    if (_combobox->getItemCount() == 2)
      _combobox->addItem(L"\t2", 2);
	}
	else if (i == 3)
	{
    if (_combobox->getItemCount() == 1)
      _combobox->addItem(L"\t1", 1);
    _combobox->removeItem(2);
	}
	else if (i == 4)
	{
	  _combobox->removeItem(2);
    _combobox->removeItem(1);
	}
	break;
      }
      }

    default:
      break;
    }
  }
  return (false);
}
