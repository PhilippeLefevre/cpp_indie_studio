//
// main1.cpp for  in /home/zobov_v/rendu/cpp_indie_studio/source
// 
// Made by Vladisalv ZOBOV
// Login   <zobov_v@epitech.net>
// 
// Started on  Tue May  9 22:55:09 2017 Vladisalv ZOBOV
// Last update Wed May 10 14:01:21 2017 Vladisalv ZOBOV
//

#include <irrlicht.h>
#include "MainMenu.hh"

int	main()
{
  bool fullscreen = true;
  bool music = true;
  bool shadows = false;
  bool additive = false;
  bool vsync = false;
  bool aa = false;
  irr::video::E_DRIVER_TYPE driverType = irr::video::EDT_OPENGL;

  MainMenu	menu(fullscreen, music, shadows, additive, vsync, aa, driverType);
  if (menu.run())
    {

    }
  fullscreen = false;
  return (0);
}
