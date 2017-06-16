/*
** Score.cpp for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Wed Jun 14 17:50:59 2017 Tanguy Lelievre
** Last update	Thu Jun 15 11:01:26 2017 Tanguy Lelievre
*/

#include "Score.hh"

Score::Score() : _points(), _pseudos()
{
  irr::IrrlichtDevice   *NullDevice = irr::createDevice(irr::video::EDT_NULL);

  if (!NullDevice)
    return;
  irr::io::IXMLReader   *xmlReader = NullDevice->getFileSystem()->createXMLReader("./score.xml");
  if (!xmlReader)
    return;
  irr::core::stringw   node;

  node = "score";
  while (xmlReader && xmlReader->read())
  {
    switch (xmlReader->getNodeType())
    {
    case irr::io::EXN_ELEMENT:
    {
      if (node.equalsn(xmlReader->getNodeName(), node.size()))
      {
	_points.push_back(xmlReader->getAttributeValueAsInt(L"points"));
	_pseudos.push_back(xmlReader->getAttributeValue(L"player"));
      }
      break;
    }
    }
  }
  xmlReader->drop();
  sort();
  if (NullDevice)
  {
    NullDevice->closeDevice();
    NullDevice->drop();
  }
}

void	Score::sort()
{
  irr::s32	i;
  irr::s32	save;
  irr::core::stringc	pseudo;

  i = 0;
  while (i < _points.size())
  {
    if (_points[i] < _points[i + 1] && (i + 1) < _points.size())
      {
        pseudo = _pseudos[i];
        _pseudos[i] = _pseudos[i + 1];
        _pseudos[i + 1] = pseudo;
        save = _points[i];
        _points[i] = _points[i + 1];
        _points[i + 1] = save;
        save = 0;
        i = 0;
      }
    else
      i++;
  }
}

void	Score::addScore(irr::core::stringc pseudo, irr::s32 points)
{
  _points.push_back(points);
  _pseudos.push_back(pseudo);
  sort();
}

irr::core::array<irr::s32>	Score::getScores() const
{
  return (_points);
}

irr::core::array<irr::core::stringc>	Score::getPseudos() const
{
  return (_pseudos);
}
