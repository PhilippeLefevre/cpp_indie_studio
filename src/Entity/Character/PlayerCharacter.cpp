//
// PlayerCharacter.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Sat Jun 17 05:03:29 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "PlayerCharacter.hpp"
#include "IEntity.hpp"
#include "IBlock.hpp"
#include "Normal.hpp"

indie::PlayerCharacter::PlayerCharacter(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver, MyEventReceiver *receiver, ITimer *timer) : _scnMngr(scnMngr), _pos(pos), _driver(driver), _receiver(receiver), _timer(timer)
{
        std::string txt = "media/texture_green.bmp";
        std::string obj = "media/BB8/bb8.obj";

        //_mesh = _scnMngr->addCubeSceneNode(10, 0, -1, _pos);
        _mesh = _scnMngr->addMeshSceneNode(_scnMngr->getMesh(obj.data()));
        if (_mesh)
        {
                //video::ITexture *texture = _driver->getTexture(txt.data());
                //if (texture != 0)
                //{
                //        _mesh->setMaterialTexture(0, texture);
                //}
                _mesh->setPosition(pos);
                _mesh->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                //_mesh->setScale(core::vector3df(3.0f, 3.0f, 2.6f));
                _mesh->setScale(core::vector3df(0.05f, 0.05f, 0.05f));

        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        _died = false;
        _speed = 1.0f * _PLAYER_SPEED;
        _bomb = 1;
}

indie::PlayerCharacter::~PlayerCharacter()
{
        if (_mesh)
        {
                _mesh->remove();
        }
}

indie::PlayerCharacter::PlayerCharacter(const PlayerCharacter &obj)
{
        _mesh = obj._mesh;
        _scnMngr = obj._scnMngr;
        _pos = obj._pos;
}

indie::PlayerCharacter &indie::PlayerCharacter::operator=(const PlayerCharacter &obj)
{
        // DO CANONICAL
}

void indie::PlayerCharacter::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value)
{
        _mesh->setMaterialFlag(flag, value);
}

void indie::PlayerCharacter::setPosition(core::vector3df const& pos)
{
        _mesh->setPosition(pos);
        _mesh->updateAbsolutePosition();
        _pos = getPosition();
}

core::vector3df const& indie::PlayerCharacter::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::PlayerCharacter::setRotation(core::vector3df const& rot)
{
        _mesh->setRotation(rot);
        _rot = getRotation();
}

core::vector3df const& indie::PlayerCharacter::getRotation(void) const
{
        return (_mesh->getRotation());
}

core::aabbox3df const indie::PlayerCharacter::getBoundingBox(void) const
{
        return (_mesh->getTransformedBoundingBox());
}

bool indie::PlayerCharacter::isColliding(core::aabbox3df const& box) const
{
        return (box.intersectsWithBox(getBoundingBox()));
}

bool indie::PlayerCharacter::isDied(void) const
{
        return (_died);
}

void indie::PlayerCharacter::Die(void)
{
        _died = true;
        _pos.Y -= 20;
        setPosition(_pos);
}

bool indie::PlayerCharacter::Move(const f32 fps, std::vector<indie::IEntity*> const& block, std::vector<indie::IEntity*>*bomb)
{
        core::vector3df oldPos;
        core::vector3df oldRot;

        oldRot = getRotation();
        oldPos = getPosition();
        if (_receiver->IsKeyDown(KEY_KEY_Z))
        {
                setRotation(core::vector3df(0.0f, 0.0f, 0.0f));
                _pos.Z += _speed * fps;
        }
        else if (_receiver->IsKeyDown(KEY_KEY_S))
        {
                setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
                _pos.Z -= _speed * fps;
        }
        else if (_receiver->IsKeyDown(KEY_KEY_Q))
        {
                setRotation(core::vector3df(0.0f, -90.0f, 0.0f));
                _pos.X -= _speed * fps;
        }
        else if (_receiver->IsKeyDown(KEY_KEY_D))
        {
                setRotation(core::vector3df(0.0f, 90.0f, 0.0f));
                _pos.X += _speed * fps;
        }
        setPosition(_pos);
        for (indie::IEntity *w : block)
        {
                if (isColliding(w->getBoundingBox()))
                {
                        setPosition(oldPos);
                        setRotation(oldRot);
                        break;
                }
        }
        if (_receiver->IsKeyDown(KEY_SPACE))
        {
                if (_bomb > 0)
                {
                        int z = ((((int)_pos.Z % 10) > 4) ? ((_pos.Z / 10) + 1) : (_pos.Z / 10));
                        int x = ((((int)_pos.X % 10) > 4) ? ((_pos.X / 10) + 1) : (_pos.X / 10));
                        bomb->push_back(new indie::Normal(_scnMngr, core::vector3df((x * 10), -70.0f, (z * 10)), _driver, this, _timer->getTime()));
                        _bomb--;
                        return (true);
                }
        }
        return (false);
}

void indie::PlayerCharacter::giveBomb(unsigned int bomb)
{
        _bomb += bomb;
}
