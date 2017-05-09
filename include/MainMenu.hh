/*
** MainMenu.hh for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 18:37:17 2017 Tanguy Lelievre
** Last update	Tue May 09 18:43:27 2017 Tanguy Lelievre
*/

#ifndef MAINMENU_HH_
# define MAINMENU_HH_

# include "IMenu.hh"

class	MainMenu : public IMenu
{
public:
  MainMenu();
  ~MainMenu();

  virtual bool	run();

  virtual bool	OnEvent(const irr::SEvent &event);

private:
  irr::SIrrlichtCreationParameters params;
};

#endif /* !MAINMENU_HH_ */
