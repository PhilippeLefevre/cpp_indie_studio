/*
** MainMenu.hh for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 18:37:17 2017 Tanguy Lelievre
** Last update	Thu May 11 17:55:15 2017 Tanguy Lelievre
*/

#ifndef MAINMENU_HH_
# define MAINMENU_HH_

# include <driverChoice.h>
# include "irrlicht.h"
# include "Options.hh"
# include <ctime>

class	MainMenu : public irr::IEventReceiver
{
public:
  MainMenu();
  ~MainMenu();

  bool	run();

  bool	OnEvent(const irr::SEvent &event);
  void	GOptions();
  void	LoadGame();
  void	NewGame();
  void	Menu();
  void	Display();
private:
  Options	_opts;

  irr::SIrrlichtCreationParameters _params;
  irr::IrrlichtDevice *_Mdevice;
  irr::core::dimension2d<irr::u32> _dim;

  irr::video::E_DRIVER_TYPE _driverType;
  irr::gui::IGUISkin* _skin;
  irr::gui::IGUIFont* _font;

  irr::video::IVideoDriver* _driver;
  irr::gui::IGUIEnvironment* _guienv;
  irr::gui::IGUIElement* _elem;
  irr::scene::ISceneManager* _smgr;
  irr::scene::IAnimatedMesh* _mesh;
  irr::scene::IAnimatedMeshSceneNode* _modelNode;
  irr::scene::ISceneNodeAnimator* _ani;

  irr::video::ITexture* _irrlichtBack;
  irr::gui::IGUIButton* _NewGame;
  irr::gui::IGUIButton* _Load;
  irr::gui::IGUIButton* _Score;
  irr::gui::IGUIButton* _Options;
  irr::gui::IGUIButton* _Exit;
  irr::gui::IGUIImage* _logo_img;
  irr::gui::IGUIButton* _Tatata;
  irr::gui::IGUIButton* _display;
  irr::gui::IGUIButton* _sound;
  irr::gui::IGUIButton* _shortc;
  irr::gui::IGUIButton* _back;

  irr::gui::IGUIComboBox* _Resolution;
  irr::gui::IGUICheckBox* _Fullscreen;
  irr::gui::IGUICheckBox* _Sound;
  irr::gui::IGUICheckBox* _Effects;
  irr::gui::IGUICheckBox* _Vsync;
  irr::gui::IGUICheckBox* _aa;
};

#endif /* !MAINMENU_HH_ */
