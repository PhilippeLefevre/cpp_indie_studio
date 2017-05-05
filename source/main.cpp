//
// main.cpp for  in /home/zobov_v/rendu/cpp_indie_studio
// 
// Made by Vladisalv ZOBOV
// Login   <zobov_v@epitech.net>
// 
// Started on  Thu May  4 17:12:57 2017 Vladisalv ZOBOV
// Last update Fri May  5 18:48:50 2017 Vladisalv ZOBOV
//

#include "EventReceiver.hh"

irr::IrrlichtDevice * device;

void setActiveCamera(irr::scene::ICameraSceneNode* newActive)
{
  if (0 == device)
    return;

  irr::scene::ICameraSceneNode * active = device->getSceneManager()->getActiveCamera();
  active->setInputReceiverEnabled(false);

  newActive->setInputReceiverEnabled(true);
  device->getSceneManager()->setActiveCamera(newActive);
}

int	main()
{
  irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
  if (driverType == irr::video::EDT_COUNT)
    return 1;

  device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(640, 480));
  if (device == 0)
    return 1;
  
  device->setWindowCaption(L"Bomberman - Menu");
  device->setResizable(false);

  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  irr::scene::ISceneManager* smgr = device->getSceneManager();
  
  irr::gui::IGUISkin* skin = env->getSkin();
  irr::gui::IGUIFont* font = env->getFont("media/Gamegirl.ttf");

  if (font)
    skin->setFont(font);

  skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
  env->addButton(irr::core::rect<irr::s32>(290,280,390,280 + 32), 0, GUI_NEW_GAME_BUTTON, L"New Game", L"Start New Game");
  env->addButton(irr::core::rect<irr::s32>(290,320,390,320 + 32), 0, GUI_LOAD_GAME_BUTTON, L"Load Game", L"Load Save");
  env->addButton(irr::core::rect<irr::s32>(290,360,390,360 + 32), 0, GUI_OPTION_GAME_BUTTON, L"Options", L"Game Options");
  env->addButton(irr::core::rect<irr::s32>(290,400,390,400 + 32), 0, GUI_ID_QUIT_BUTTON, L"Quit", L"Exits Program");

  SAppContext context;
  context.device = device;
  context.counter = 0;

  MyEventReceiver receiver(context);
  device->setEventReceiver(&receiver);
  env->addImage(driver->getTexture("media/logo1.png"), irr::core::position2d<int>(10,10));

  irr::scene::ISceneNode* SkyBox = smgr->addSkyBoxSceneNode(
							    driver->getTexture("media/mckg.jpg"),
							    driver->getTexture("media/mckg.jpg"),
							    driver->getTexture("media/mckg.jpg"),
							    driver->getTexture("media/mckg.jpg"),
							    driver->getTexture("media/mckg.jpg"),
							    driver->getTexture("media/mckg.jpg"));

  irr::scene::ICameraSceneNode* Camera[2] = {0, 0};
  Camera[0] = smgr->addCameraSceneNodeMaya();
  Camera[0]->setFarValue(20000.f);
  Camera[0]->setTarget(irr::core::vector3df(0,30,0));
  Camera[1] = smgr->addCameraSceneNodeFPS();
  Camera[1]->setFarValue(20000.f);
  Camera[1]->setPosition(irr::core::vector3df(0,0,-70));
  Camera[1]->setTarget(irr::core::vector3df(0,30,0));

  setActiveCamera(Camera[0]);

  while(device->run() && driver)
    {
      if (device->isWindowActive())
	{
	  driver->beginScene(true, true, irr::video::SColor(0,200,255,200));
	  smgr->drawAll();
	  env->drawAll();
	  driver->endScene();
	}
      else
	device->yield();
    }
  device->drop();
  return 0;
}
