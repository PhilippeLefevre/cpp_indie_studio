/*
** Options.hh for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Wed May 10 14:11:16 2017 Tanguy Lelievre
** Last update	Thu May 11 15:38:13 2017 Tanguy Lelievre
*/

#ifndef OPTIONS_HH_
# define OPTIONS_HH_

# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <vector>
# include <regex>

class Options
{
public:
  Options();
  ~Options();

  void	setFullscreen(bool);
  bool	getFullscreen() const;

  void	setWidth(int);
  int	getWidth() const;

  void	setHeight(int);
  int	getHeight() const;

  void	setSound(bool);
  bool	getSound() const;

  void	setMusic(bool);
  bool	getMusic() const;

  void	setEffects(bool);
  bool	getEffects() const;

  void	setVsync(bool);
  bool	getVsync() const;

  void	setAA(bool);
  bool	getAA() const;

private:
  bool	_fullscreen;
  int	_width;
  int	_height;
  bool	_sound;
  bool	_music;
  bool	_effects;
  bool	_vsync;
  bool	_aa;
};

#endif /* !OPTIONS_HH_ */
