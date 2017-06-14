//
// NonPlayerCharacter.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Wed Jun 14 18:34:14 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "NonPlayerCharacter.hpp"

indie::NonPlayerCharacter::NonPlayerCharacter(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver) : _scnMngr(scnMngr), _pos(pos), _driver(driver)
{
        std::string txt = "texture_yellow.bmp";
        _mesh = _scnMngr->addCubeSceneNode(10.0f, 0, -1, _pos);
        if (_mesh)
        {
                video::ITexture *texture = _driver->getTexture(txt.data());
                if (texture != 0)
                {
                        _mesh->setMaterialTexture(0, texture);
                }
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                _mesh->setScale(core::vector3df(0.5f, 0.5f, 0.5f));

        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        _explosed = false;
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
}

core::vector3df const& indie::NonPlayerCharacter::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::NonPlayerCharacter::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
        _pos = pos;
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

bool indie::NonPlayerCharacter::isExplosed(void) const
{
        return (_explosed);
}

void indie::NonPlayerCharacter::Explose(void)
{
        _explosed = true;
        _pos.Y -= 20;
        setPosition(_pos);
}

bool indie::NonPlayerCharacter::Move(const f32 fps, std::vector<indie::IEntity*> const& block, std::vector<indie::IEntity*>*bomb)
{
}

void indie::NonPlayerCharacter::giveBomb(unsigned int bomb)
{
        _bomb += bomb;
}
