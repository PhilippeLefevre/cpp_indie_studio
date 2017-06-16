/*
** Options.hh for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Wed May 10 14:11:16 2017 Tanguy Lelievre
** Last update	Wed Jun 14 18:05:20 2017 Tanguy Lelievre
*/

#ifndef OPTIONS_HH_
# define OPTIONS_HH_

# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <vector>
# include <regex>
# include <irrlicht.h>
# include "Score.hh"

class Options
{
public:
  Options();
  ~Options();

  void	setFullscreen(bool);
  bool	getFullscreen() const;

  void	setWidth(irr::s16);
  irr::s16	getWidth() const;

  void	setHeight(irr::s16);
  irr::s16	getHeight() const;

  void	setVsync(bool);
  bool	getVsync() const;

  void	setAA(bool);
  bool	getAA() const;

  void	setSoundMute(bool);
  bool	getSoundMute() const;

  void	setSoundLevel(irr::s16);
  irr::s16	getSoundLevel() const;

  void	setMusicMute(bool);
  bool	getMusicMute() const;

  void	setMusicLevel(irr::s16);
  irr::s16	getMusicLevel() const;

  void	setEffectsMute(bool);
  bool	getEffectsMute() const;

  void	setEffectsLevel(irr::s16);
  irr::s16	getEffectsLevel() const;

  void	saveConf();
  void	loadConf();

private:

  irr::IrrlichtDevice *_NullDevice;

  // XML tool
  irr::io::IXMLReader*	_xmlReader;
  irr::io::IXMLWriter*	_xmlWriter;

  // Display
  bool	_fullscreen;
  irr::s16	_width;
  irr::s16	_height;
  bool	_vsync;
  bool	_aa;

  // Audio
  bool	_soundMute;
  irr::s16	_soundLevel;
  bool	_musicMute;
  irr::s16	_musicLevel;
  bool	_effectsMute;
  irr::s16	_effectsLevel;
};

#endif /* !OPTIONS_HH_ */
