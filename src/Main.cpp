/*
** main.c for  in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed May 24 14:43:24 2017 Philippe Lefevre
** Last update	Sun Jun 18 21:24:02 2017 Philippe Lefevre
*/

#include <irrlicht.h>
#include "MainMenu.hh"
#include "Game.hpp"
#include "MapLoader.hpp"

int     main(void)
{
  MainMenu   menu;
  Game game;
  MapLoader loader;
  irr::s32   state;

  while (state = menu.run())
  {
    if (state == 0)
      return (0);
    else if (state == 1)
    {
      menu.createWindow();
      menu.OptionMenu();
    }
    else if (state == 2)
    {
            loader.init(menu.getMap(), menu.getNbPlayer(), menu.getNbIA());
      game.init(loader.getMap());
      game.Play();
      menu.createWindow();
    }
  }
  return (0);
}
