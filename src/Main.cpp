/*
** main.c for  in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed May 24 14:43:24 2017 Philippe Lefevre
** Last update	Fri Jun 16 16:38:12 2017 Tanguy Lelievre
*/

#include <irrlicht.h>
#include "MainMenu.hh"
#include "Game.hpp"

int     main(void)
{
  MainMenu   menu;
  Game	game;
  irr::s32   state;
  irr::s32 map[15][15] = {
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::NPC_TWO, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::PC_ONE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::NPC_TWO, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::NPC_THREE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
          { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE }
  };

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
      game.init(map);
      game.Play();
      menu.createWindow();
    }
  }
  return (0);
}
