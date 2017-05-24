/*
** Options.cpp for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Wed May 10 14:42:18 2017 Tanguy Lelievre
** Last update	Thu May 11 18:30:21 2017 Tanguy Lelievre
*/

#include "Options.hh"

Options::Options() : _fullscreen(false), _width(1600), _height(900),
  _sound(true), _music(true), _effects(true), _vsync(true), _aa(0)
{
  std::ifstream   ifs("display.conf");
  std::string   line;
  std::string   fp;
  std::string   sp;
  int   pos;
  unsigned int   i;
  std::vector<std::string>   opts;
  std::regex   is_num;

  is_num = "[0-9]+";
  opts.push_back("FULLSCREEN");
  opts.push_back("WIDTH");
  opts.push_back("HEIGHT");
  opts.push_back("SOUND");
  opts.push_back("MUSIC");
  opts.push_back("EFFECTS");
  opts.push_back("VSYNC");
  opts.push_back("AA");
  if (ifs.is_open())
  {
    while (std::getline(ifs, line))
    {
      i	  = 0;
      pos = line.find('=', 0);
      fp  = line.substr(0, pos);
      sp  = line.substr(pos + 1);
      while (i < opts.size())
      {
	if (fp.compare(opts[i]) == 0)
	  switch (i) {
	  case 0:
	    if (sp.compare("true") == 0)
	      _fullscreen = true;
	    else if (sp.compare("false") == 0)
	      _fullscreen = false;
	    break;

	  case 1:
	    if (std::regex_match(sp, is_num) == true)
	    {
	      _width = std::stoi(sp);
	    }
	    break;

	  case 2:
	    if (std::regex_match(sp, is_num) == true)
	    {
	      _height = std::stoi(sp);
	    }
	    break;

	  case 3:
	    if (sp.compare("true") == 0)
	      _sound = true;
	    else if (sp.compare("false") == 0)
	      _sound = false;
	    break;

	  case 4:
	    if (sp.compare("true") == 0)
	      _music = true;
	    else if (sp.compare("false") == 0)
	      _music = false;
	    break;

	  case 5:
	    if (sp.compare("true") == 0)
	      _effects = true;
	    else if (sp.compare("false") == 0)
	      _effects = false;
	    break;

	  case 6:
	    if (sp.compare("true") == 0)
	      _vsync = true;
	    else if (sp.compare("false") == 0)
	      _vsync = false;
	    break;

	  case 7:
	    if (sp.compare("true") == 0)
	      _aa = true;
	    else if (sp.compare("false") == 0)
	      _aa = false;
	    break;
	  }
	i++;
      }
    }
  }
}

void	Options::setFullscreen(bool fullscreen)
{
  _fullscreen = fullscreen;
}

bool	Options::getFullscreen() const
{
  return (_fullscreen);
}

void	Options::setWidth(int width)
{
  _width = width;
}

int	Options::getWidth() const
{
  return (_width);
}

void	Options::setHeight(int height)
{
  _height = height;
}
int	Options::getHeight() const
{
  return (_height);
}

void	Options::setSound(bool sound)
{
  _sound = sound;
}
bool	Options::getSound() const
{
  return (_sound);
}

void	Options::setMusic(bool music)
{
  _music = music;
}
bool	Options::getMusic() const
{
  return (_music);
}

void	Options::setEffects(bool effects)
{
  _effects = effects;
}
bool	Options::getEffects() const
{
  return (_effects);
}


void	Options::setVsync(bool vsync)
{
  _vsync = vsync;
}
bool	Options::getVsync() const
{
  return (_vsync);
}

void	Options::setAA(bool aa)
{
  _aa = aa;
}
bool	Options::getAA() const
{
  return (_aa);
}

Options::~Options() {}
