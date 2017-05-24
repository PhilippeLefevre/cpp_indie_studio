/*
** Menu.hh for indie studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 15:10:18 2017 Tanguy Lelievre
** Last update	Tue May 09 18:36:23 2017 Tanguy Lelievre
*/


#ifndef IMENU_HH_
# define IMENU_HH_

# include <driverChoice.h>
# include "irrlicht.h"

class	IMenu : public irr::IEventReceiver
{
public:
  virtual bool	run() = 0;

  virtual bool	OnEvent(const irr::SEvent &event) = 0;
};

#endif /* !IMENU_HH_ */
