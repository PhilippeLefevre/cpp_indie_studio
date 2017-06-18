//
// NonPlayerCharacter.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Sun Jun 18 22:33:23 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "NonPlayerCharacter.hpp"
#include <cstdlib>
#include <ctime>
#include "IEntity.hpp"
#include "IBlock.hpp"
#include "Normal.hpp"

indie::NonPlayerCharacter::NonPlayerCharacter(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver, ITimer *timer) : _scnMngr(scnMngr), _pos(pos), _driver(driver), _timer(timer)
{
        std::string txt = "media/texture_yellow.bmp";
        std::string obj = "media/BB8/bb8.obj";

        _mesh = _scnMngr->addMeshSceneNode(_scnMngr->getMesh(obj.data()));
        if (_mesh)
        {
                _mesh->setPosition(pos);
                _mesh->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                _mesh->setScale(core::vector3df(0.05f, 0.05f, 0.05f));

        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        _died = false;
        _collision = false;
        _speed = 1.0f * _PLAYER_SPEED;
        _bomb = 1;
        _goal.X = _pos.X;
        _goal.Y = _pos.Y;
        _goal.Z = _pos.Z;
        std::srand(std::time(0));
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
        _driver = obj._driver;
        _pos = obj._pos;
        _timer = obj._timer;
        _MaxXZ = obj._MaxXZ;
        _MinXZ = obj._MinXZ;
        _died = obj._died;
        _speed = obj._speed;
        _bomb = obj._bomb;
        _goal = obj._goal;
        _direction = obj._direction;
        _collision = obj._collision;
}

indie::NonPlayerCharacter &indie::NonPlayerCharacter::operator=(const NonPlayerCharacter &obj)
{
        NonPlayerCharacter *tmp = new NonPlayerCharacter(obj);
        return (*tmp);
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

    if ((_pos.X == _goal.X &&_pos.Y == _goal.Y && _pos.Z == _goal.Z) || _collision == true)
      {
        _collision = false;
        _direction = rand() % 4 + 1;
        if (_direction == 1 && _goal.Z <= 130.0f)
          {
            _goal.Z += 20.0f;
          }
        if (_direction == 2 && _goal.Z >= 10.0f)
          {
            _goal.Z -= 20.0f;
          }
        if (_direction == 3 && _goal.X <= 130.0f)
          {
            _goal.X += 20.0f;
          }
        if (_direction == 4 && _goal.X >= 10.0f)
          {
            _goal.X += 20.0f;
          }
      }
    if (_direction == 1)
      {
        _pos.Z += _speed * fps;
      }
    if (_direction == 2)
      {
        _pos.Z -= _speed * fps;
      }
    if (_direction == 3)
      {
        _pos.X -= _speed * fps;
      }
    if (_direction == 4)
      {
        _pos.X += _speed * fps;
      }
    setPosition(_pos);
    for (indie::IEntity *w : block)
      {
        if (isColliding(w->getBoundingBox()))
          {
            _collision = true;
            setPosition(oldPos);
          if (((indie::IBlock*)w)->isExplosible() == true)
          {
            int near;
            for (indie::IEntity *w : *bomb)
            {
                    near = w->getPosition().getDistanceFrom(getPosition());
            }
            if (_bomb > 0 && (near == 0 || near > 11))
            {
                    int z = ((((int)_pos.Z % 10) > 4) ? ((_pos.Z / 10) + 1) : (_pos.Z / 10));
                    int x = ((((int)_pos.X % 10) > 4) ? ((_pos.X / 10) + 1) : (_pos.X / 10));
                    bomb->push_back(new indie::Normal(_scnMngr, core::vector3df((x * 10), -70.0f, (z * 10)), _driver, this, _timer->getTime()));
                    _bomb--;
                    return (true);
            }
          }
        }
      }
}

void indie::NonPlayerCharacter::giveBomb(unsigned int bomb)
{
        _bomb += bomb;
}
