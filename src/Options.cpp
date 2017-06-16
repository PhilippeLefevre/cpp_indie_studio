/*
** Options.cpp for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Wed May 10 14:42:18 2017 Tanguy Lelievre
** Last update	Sat Jun 03 12:11:48 2017 Tanguy Lelievre
*/

#include "Options.hh"

Options::Options() : _fullscreen(false), _width(1920), _height(1080),
  _vsync(true), _aa(true), _soundMute(false), _soundLevel(50),
  _musicMute(false), _musicLevel(50), _effectsMute(false), _effectsLevel(50)
{
  _NullDevice = irr::createDevice(irr::video::EDT_NULL);
  loadConf();
}

void     Options::loadConf()
{
  if (!_NullDevice)
    return;
  _xmlReader = _NullDevice->getFileSystem()->createXMLReader("./conf.xml");
  if (!_xmlReader)
    return;
  irr::core::stringw   disp;
  irr::core::stringw   aud;

  disp = "display";
  aud  = "audio";
  while (_xmlReader && _xmlReader->read())
  {
    switch (_xmlReader->getNodeType())
    {
    case irr::io::EXN_ELEMENT:
    {
      if (disp.equalsn(_xmlReader->getNodeName(), disp.size()))
      {
	_width	= _xmlReader->getAttributeValueAsInt(L"width");
	_height = _xmlReader->getAttributeValueAsInt(L"height");
	if (((_width != 1280) && (_width != 1600) && (_width != 1920)) ||
	    ((_height != 720) && (_height != 900) && (_height != 1080)))
	{
	  _width  = 1920;
	  _height = 1080;
	}
	_fullscreen = _xmlReader->getAttributeValueAsInt(L"fullscreen");
	_vsync	    = _xmlReader->getAttributeValueAsInt(L"vsync");
	_aa	    = _xmlReader->getAttributeValueAsInt(L"antialias");
      }
      else if (aud.equalsn(_xmlReader->getNodeName(), aud.size()))
      {
	_soundMute  = _xmlReader->getAttributeValueAsInt(L"soundMute");
	_soundLevel = _xmlReader->getAttributeValueAsInt(L"soundLevel");
	if ((_soundLevel > 100) || (_soundLevel < 0))
	  _soundLevel = 50;
	_musicMute  = _xmlReader->getAttributeValueAsInt(L"musicMute");
	_musicLevel = _xmlReader->getAttributeValueAsInt(L"musicLevel");
	if ((_musicLevel > 100) || (_musicLevel < 0))
	  _musicLevel = 50;
	_effectsMute  = _xmlReader->getAttributeValueAsInt(L"effectsMute");
	_effectsLevel = _xmlReader->getAttributeValueAsInt(L"effectsLevel");
	if ((_effectsLevel > 100) || (_effectsLevel < 0))
	  _effectsLevel = 50;
      }
      break;
    }
    }
  }
  _xmlReader->drop();
  saveConf();
}

void     Options::saveConf()
{
  if (!_NullDevice)
    return;
  _xmlWriter = _NullDevice->getFileSystem()->createXMLWriter("./conf.xml");
  if (!_xmlWriter)
    return;

  _xmlWriter->writeXMLHeader();

  irr::core::array<irr::core::stringw>   names;
  names.push_back(L"soundLevel");
  names.push_back(L"soundMute");
  names.push_back(L"musicLevel");
  names.push_back(L"musicMute");
  names.push_back(L"effectsLevel");
  names.push_back(L"effectsMute");

  irr::core::array<irr::core::stringw>   values;
  values.push_back(irr::core::stringw(_soundLevel).c_str());
  values.push_back(irr::core::stringw(_soundMute).c_str());
  values.push_back(irr::core::stringw(_musicLevel).c_str());
  values.push_back(irr::core::stringw(_musicMute).c_str());
  values.push_back(irr::core::stringw(_effectsLevel).c_str());
  values.push_back(irr::core::stringw(_effectsMute).c_str());

  _xmlWriter->writeElement(L"config");
  _xmlWriter->writeLineBreak();

  _xmlWriter->writeElement(L"display", true,
    L"width", irr::core::stringw(_width).c_str(),
    L"height", irr::core::stringw(_height).c_str(),
    L"antialias", irr::core::stringw(_aa).c_str(),
    L"fullscreen", irr::core::stringw(_fullscreen).c_str(),
    L"vsync", irr::core::stringw(_vsync).c_str());
  _xmlWriter->writeLineBreak();

  _xmlWriter->writeElement(L"audio", true, names, values);
  _xmlWriter->writeLineBreak();

  _xmlWriter->writeClosingTag(L"config");
  _xmlWriter->writeLineBreak();

  _xmlWriter->drop();
}

void	     Options::setFullscreen(bool fullscreen)
{
  _fullscreen = fullscreen;
}

bool	     Options::getFullscreen() const
{
  return (_fullscreen);
}

void	     Options::setWidth(irr::s16 width)
{
  _width = width;
}

irr::s16     Options::getWidth() const
{
  return (_width);
}

void	     Options::setHeight(irr::s16 height)
{
  _height = height;
}

irr::s16     Options::getHeight() const
{
  return (_height);
}

void	     Options::setVsync(bool vsync)
{
  _vsync = vsync;
}

bool	     Options::getVsync() const
{
  return (_vsync);
}

void	     Options::setAA(bool aa)
{
  _aa = aa;
}

bool	     Options::getAA() const
{
  return (_aa);
}

void	     Options::setSoundMute(bool sound)
{
  _soundMute = sound;
}

void	     Options::setSoundLevel(irr::s16 sound)
{
  _soundMute = sound;
}

bool	     Options::getSoundMute() const
{
  return (_soundMute);
}

irr::s16     Options::getSoundLevel() const
{
  return (_soundMute);
}

void	     Options::setMusicMute(bool music)
{
  _musicMute = music;
}

void	     Options::setMusicLevel(irr::s16 music)
{
  _musicLevel = music;
}

bool	     Options::getMusicMute() const
{
  return (_musicMute);
}

irr::s16     Options::getMusicLevel() const
{
  return (_musicLevel);
}

void	     Options::setEffectsMute(bool effects)
{
  _effectsMute = effects;
}

void	     Options::setEffectsLevel(irr::s16 effects)
{
  _effectsLevel = effects;
}

bool	     Options::getEffectsMute() const
{
  return (_effectsMute);
}

irr::s16     Options::getEffectsLevel() const
{
  return (_effectsLevel);
}

Options::~Options()
{
  if (_NullDevice)
  {
    _NullDevice->closeDevice();
    _NullDevice->drop();
  }
}
