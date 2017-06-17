//
// NonPlayerCharacter.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Sat Jun 17 03:14:19 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "NonPlayerCharacter.hpp"
#include "IEntity.hpp"
#include "IBlock.hpp"
#include "Normal.hpp"

indie::NonPlayerCharacter::NonPlayerCharacter(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver, ITimer *timer) : _scnMngr(scnMngr), _pos(pos), _driver(driver), _timer(timer)
{
        std::string txt = "media/texture_yellow.bmp";
        _mesh = _scnMngr->addCubeSceneNode(10.0f, 0, -1, _pos);
        if (_mesh)
        {
                video::ITexture *texture = _driver->getTexture(txt.data());
                if (texture != 0)
                {
                        _mesh->setMaterialTexture(0, texture);
                }
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                _mesh->setScale(core::vector3df(0.5f, 2.5f, 0.5f));

        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        _died = false;
        _speed = 1.0f * _PLAYER_SPEED;
        _bomb = 1;
        _MaxXZ = 130.0f;
        _MinXZ = 10.0f;

        if (_pos.X == 10.5f && _pos.Z == 10.5f)
          _direction = 1;
        if (_pos.X == 130.5f && _pos.Z == 10.5f)
          _direction = 2;
        if (_pos.X == 130.5f && _pos.Z == 130.5f)
          _direction = 3;
        if (_pos.X == 10.5f && _pos.Z == 130.5f)
          _direction = 4;
}

indie::NonPlayerCharacter::~NonPlayerCharacter()
{
        if (_mesh)
        {
                _mesh->remove();
        }
}

indie::NonPlayerCharacter::NonPlayerCharacter(const NonPlayerCharacter &obj)
{
        _mesh = obj._mesh;
        _scnMngr = obj._scnMngr;
        _pos = obj._pos;
}

indie::NonPlayerCharacter &indie::NonPlayerCharacter::operator=(const NonPlayerCharacter &obj)
{
        // DO CANONICAL
}

void indie::NonPlayerCharacter::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value)
{
        _mesh->setMaterialFlag(flag, value);
}

void indie::NonPlayerCharacter::setPosition(core::vector3df const& pos)
{
        _mesh->setPosition(pos);
        _mesh->updateAbsolutePosition();
        _pos = getPosition();
}

core::vector3df const& indie::NonPlayerCharacter::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::NonPlayerCharacter::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
        _pos = getRotation();
}

core::vector3df const& indie::NonPlayerCharacter::getRotation(void) const
{
        return (_mesh->getRotation());
}

core::aabbox3df const indie::NonPlayerCharacter::getBoundingBox(void) const
{
        return (_mesh->getTransformedBoundingBox());
}

bool indie::NonPlayerCharacter::isColliding(core::aabbox3df const& box) const
{
        return (box.intersectsWithBox(getBoundingBox()));
}

bool indie::NonPlayerCharacter::isDied(void) const
{
        return (_died);
}

void indie::NonPlayerCharacter::Die(void)
{
        _died = true;
        _pos.Y -= 20;
        setPosition(_pos);
}

bool indie::NonPlayerCharacter::Move(const f32 fps, std::vector<indie::IEntity*> const& block, std::vector<indie::IEntity*>*bomb)
{
    core::vector3df oldPos;

    oldPos.X = _pos.X;
    oldPos.Y = _pos.Y;
    oldPos.Z = _pos.Z;

        if (_direction == 1 && _pos.Z < _MaxXZ)
        {
          _pos.Z += _speed * fps;
          if (_pos.Z >= _MaxXZ)
          {
            _MaxXZ -= 20.5f;
            _direction = 2;
          }
        }
        if (_direction == 2 && _pos.X < _MaxXZ)
        {
          _pos.X += _speed * fps;
          if (_pos.X >= _MaxXZ)
          {
            _MaxXZ -= 20.5f;
            _direction = 3;
          }
        }
        if (_direction == 3 && _pos.Z > _MinXZ)
        {
          _pos.Z -= _speed * fps;
          if (_pos.Z <= _MinXZ)
            {
              _MinXZ += 20.5f;
              _direction = 4;
            }
        }
        if (_direction == 4 &&  _pos.X > _MinXZ)
        {
          _pos.X -= _speed * fps;
          if (_pos.X <= _MinXZ)
            {
              _MinXZ += 20.5f;
              _direction = 1;
            }
        }
        setPosition(_pos);
        for (indie::IEntity *w : block)
        {
          if (isColliding(w->getBoundingBox()))
            {
              setPosition(oldPos);
              if (_bomb > 0)
              {
                      int z = ((((int)_pos.Z % 10) > 4) ? ((_pos.Z / 10) + 1) : (_pos.Z / 10));
                      int x = ((((int)_pos.X % 10) > 4) ? ((_pos.X / 10) + 1) : (_pos.X / 10));
                      bomb->push_back(new indie::Normal(_scnMngr, core::vector3df((x * 10.0f), -70.0f, (z * 10.0f)), _driver, this, _timer->getTime()));
                      _bomb--;
                      return (true);
              }
              break;
            }
        }
}

void indie::NonPlayerCharacter::giveBomb(unsigned int bomb)
{
        _bomb += bomb;
}
