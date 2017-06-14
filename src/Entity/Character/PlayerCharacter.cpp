//
// PlayerCharacter.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Wed Jun 14 19:29:23 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "PlayerCharacter.hpp"
#include "IEntity.hpp"
#include "IBlock.hpp"
#include "Normal.hpp"

indie::PlayerCharacter::PlayerCharacter(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver, MyEventReceiver *receiver) : _scnMngr(scnMngr), _pos(pos), _driver(driver), _receiver(receiver)
{
        std::string txt = "texture_green.bmp";
        _mesh = _scnMngr->addCubeSceneNode(10.0f, 0, -1, _pos);
        if (_mesh)
        {
                //video::ITexture *texture = _driver->getTexture(txt.data());
                //if (texture != 0)
                //{
                //        _mesh->setMaterialTexture(0, texture);
                //}
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                _mesh->setScale(core::vector3df(0.5f, 2.5f, 0.5f));

        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        _explosed = false;
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

void indie::PlayerCharacter::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
        _pos = getRotation();
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

bool indie::PlayerCharacter::isExplosed(void) const
{
        return (_explosed);
}

void indie::PlayerCharacter::Explose(void)
{
        _explosed = true;
        _pos.Y -= 20;
        setPosition(_pos);
}

bool indie::PlayerCharacter::Move(const f32 fps, std::vector<indie::IEntity*> const& block, std::vector<indie::IEntity*>*bomb)
{
        core::vector3df oldPos;

        oldPos.X = _pos.X;
        oldPos.Y = _pos.Y;
        oldPos.Z = _pos.Z;
        if (_receiver->IsKeyDown(KEY_KEY_Z) && _pos.Z < 130.0f)
        {
                _pos.Z += _speed * fps;
        }
        else if (_receiver->IsKeyDown(KEY_KEY_S) && _pos.Z > 10.0f)
        {
                _pos.Z -= _speed * fps;
        }
        else if (_receiver->IsKeyDown(KEY_KEY_Q) && _pos.X > 10.0f)
        {
                _pos.X -= _speed * fps;
        }
        else if (_receiver->IsKeyDown(KEY_KEY_D) && _pos.X < 130.0f)
        {
                _pos.X += _speed * fps;
        }
        setPosition(_pos);
        for (indie::IEntity *w : block)
        {
                if (isColliding(w->getBoundingBox()))
                {
                        setPosition(oldPos);
                        break;
                }
        }
        if (_receiver->IsKeyDown(KEY_SPACE))
        {
                if (_bomb > 0)
                {
                        int x, z;
                        x = (_pos.X / 10);
                        z = (_pos.Z / 10);
                        bomb->push_back(new indie::Normal(_scnMngr, core::vector3df((x * 10.0f), -70.0f, (z * 10.0f)), _driver, this));
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
