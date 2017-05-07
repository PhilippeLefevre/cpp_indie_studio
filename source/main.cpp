//
// main.cpp for  in /home/zobov_v/rendu/cpp_indie_studio
// 
// Made by Vladisalv ZOBOV
// Login   <zobov_v@epitech.net>
// 
// Started on  Thu May  4 17:12:57 2017 Vladisalv ZOBOV
// Last update Sat May  6 21:49:39 2017 Vladisalv ZOBOV
//

#include "EventReceiver.hh"

irr::IrrlichtDevice * device = 0;
irr::scene::ISceneNode* Model = 0;
irr::core::stringc StartUpModelFile;
irr::core::stringw MessageText;
irr::core::stringw Caption;
bool Octree=false;
bool UseLight=false;

void setActiveCamera(irr::scene::ICameraSceneNode* newActive)
{
  if (0 == device)
    return;

  irr::scene::ICameraSceneNode * active = device->getSceneManager()->getActiveCamera();
  active->setInputReceiverEnabled(false);

  newActive->setInputReceiverEnabled(true);
  device->getSceneManager()->setActiveCamera(newActive);
}

void updateScaleInfo(irr::scene::ISceneNode* model)
{
  irr::gui::IGUIElement* toolboxWnd = device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(GUI_ID_DIALOG_ROOT_WINDOW, true);
  if (!toolboxWnd)
    return;
  if (!model)
    {
      toolboxWnd->getElementFromId(GUI_ID_X_SCALE, true)->setText( L"-" );
      toolboxWnd->getElementFromId(GUI_ID_Y_SCALE, true)->setText( L"-" );
      toolboxWnd->getElementFromId(GUI_ID_Z_SCALE, true)->setText( L"-" );
    }
  else
    {
      irr::core::vector3df scale = model->getScale();
      toolboxWnd->getElementFromId(GUI_ID_X_SCALE, true)->setText( irr::core::stringw(scale.X).c_str() );
      toolboxWnd->getElementFromId(GUI_ID_Y_SCALE, true)->setText( irr::core::stringw(scale.Y).c_str() );
      toolboxWnd->getElementFromId(GUI_ID_Z_SCALE, true)->setText( irr::core::stringw(scale.Z).c_str() );
    }
}

void loadModel(const irr::c8* fn)
{
  // modify the name if it a .pk3 file

  irr::io::path filename(fn);

  irr::io::path extension;
  irr::core::getFileNameExtension(extension, filename);
  extension.make_lower();

  // if a texture is loaded apply it to the current model..
  if (extension == ".jpg" || extension == ".pcx" ||
      extension == ".png" || extension == ".ppm" ||
      extension == ".pgm" || extension == ".pbm" ||
      extension == ".psd" || extension == ".tga" ||
      extension == ".bmp" || extension == ".wal" ||
      extension == ".rgb" || extension == ".rgba")
    {
      irr::video::ITexture * texture =
	device->getVideoDriver()->getTexture( filename );
      if ( texture && Model )
	{
	  // always reload texture
	  device->getVideoDriver()->removeTexture(texture);
	  texture = device->getVideoDriver()->getTexture( filename );

	  Model->setMaterialTexture(0, texture);
	}
      return;
    }
  // if a archive is loaded add it to the FileArchive..
  else if (extension == ".pk3" || extension == ".zip" || extension == ".pak" || extension == ".npk")
    {
      device->getFileSystem()->addFileArchive(filename.c_str());
      return;
    }

  // load a model into the engine

  if (Model)
    Model->remove();

  Model = 0;
  if (extension==".irr")
    {
      irr::core::array<irr::scene::ISceneNode*> outNodes;
      device->getSceneManager()->loadScene(filename);
      device->getSceneManager()->getSceneNodesFromType(irr::scene::ESNT_ANIMATED_MESH, outNodes);
      if (outNodes.size())
	Model = outNodes[0];
      return;
    }

  irr::scene::IAnimatedMesh* m = device->getSceneManager()->getMesh( filename.c_str() );

  if (!m)
    {
      // model could not be loaded

      if (StartUpModelFile != filename)
	device->getGUIEnvironment()->addMessageBox(
						   Caption.c_str(), L"The model could not be loaded. " \
						   L"Maybe it is not a supported file format.");
      return;
    }

  // set default material properties

  if (Octree)
    Model = device->getSceneManager()->addOctreeSceneNode(m->getMesh(0));
  else
    {
      irr::scene::IAnimatedMeshSceneNode* animModel = device->getSceneManager()->addAnimatedMeshSceneNode(m);
      animModel->setAnimationSpeed(30);
      Model = animModel;
    }
  Model->setMaterialFlag(irr::video::EMF_LIGHTING, UseLight);
  Model->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, UseLight);
  //      Model->setMaterialFlag(video::EMF_BACK_FACE_CULLING, false);
  Model->setDebugDataVisible(irr::scene::EDS_OFF);

  // we need to uncheck the menu entries. would be cool to fake a menu event, but
  // that's not so simple. so we do it brute force
  irr::gui::IGUIContextMenu* menu = (irr::gui::IGUIContextMenu*)device->getGUIEnvironment()->getRootGUIElement()->getElementFromId(GUI_ID_TOGGLE_DEBUG_INFO, true);
  if (menu)
    for(int item = 1; item < 6; ++item)
      menu->setItemChecked(item, false);
  updateScaleInfo(Model);
}


int	main(int argc, char **argv)
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

  device->getFileSystem()->addFileArchive("./media/");

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

  irr::io::IXMLReader* xml = device->getFileSystem()->createXMLReader( L"config.xml");

  while(xml && xml->read())
    {
      switch(xml->getNodeType())
	{
	case irr::io::EXN_TEXT:
	  // in this xml file, the only text which occurs is the
	  // messageText
	  MessageText = xml->getNodeData();
	  break;
	case irr::io::EXN_ELEMENT:
	  {
	    if (irr::core::stringw("startUpModel") == xml->getNodeName())
	      StartUpModelFile = xml->getAttributeValue(L"file");
	    else
	      if (irr::core::stringw("messageText") == xml->getNodeName())
		Caption = xml->getAttributeValue(L"caption");
	  }
	  break;
	default:
	  break;
	}
    }

  if (xml)
    xml->drop(); // don't forget to delete the xml reader

  if (argc > 1)
    StartUpModelFile = argv[1];

  loadModel(StartUpModelFile.c_str());
  
  irr::scene::ISceneNode* SkyBox = smgr->addSkyBoxSceneNode(
							    driver->getTexture("media/mp_drakeq/drakeq_up.tga"),
							    driver->getTexture("media/mp_drakeq/drakeq_dn2.jpeg"),
							    driver->getTexture("media/mp_drakeq/drakeq_lf.tga"),
							    driver->getTexture("media/mp_drakeq/drakeq_rt.tga"),
							    driver->getTexture("media/mp_drakeq/drakeq_bk.tga"),
							    driver->getTexture("media/mp_drakeq/drakeq_ft.tga"));

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
