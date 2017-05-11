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

class	MainMenu : public irr::IEventReceiver
{
public:
  MainMenu();
  ~MainMenu();

  bool	run();

  virtual bool	OnEvent(const irr::SEvent &event);

private:
  Options	_opts;
  irr::SIrrlichtCreationParameters _params;
  irr::IrrlichtDevice *_Mdevice;

  irr::video::E_DRIVER_TYPE _driverType;

  irr::gui::IGUIButton* _NewGame;
  irr::gui::IGUIButton* _Load;
  irr::gui::IGUIButton* _Score;
  irr::gui::IGUIButton* _Options;
  irr::gui::IGUIButton* _Exit;
  irr::gui::IGUIImage* _logo_img;
};

#endif /* !MAINMENU_HH_ */
