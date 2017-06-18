//
// Bombup.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Sun Jun 18 14:02:42 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "Bombup.hpp"

indie::Bombup::Bombup(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver) : _scnMngr(scnMngr), _pos(pos), _driver(driver)
{
        std::string txt = "media/texture_red.bmp";
        _mesh = _scnMngr->addCubeSceneNode(10, 0, -1, _pos);
        if (_mesh)
        {
                video::ITexture *texture = _driver->getTexture(txt.data());
                if (texture != 0)
                {
                        _mesh->setMaterialTexture(0, texture);
                }
                _mesh->setScale(core::vector3df(0.5f, 0.5f, 0.5f));
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        _pickup = false;
}

indie::Bombup::~Bombup()
{
        if (_mesh)
        {
                _mesh->remove();
        }
}

indie::Bombup::Bombup(const Bombup &obj)
{
        _mesh = obj._mesh;
        _scnMngr = obj._scnMngr;
        _pos = obj._pos;
}

indie::Bombup &indie::Bombup::operator=(const Bombup &obj)
{
        // DO CANONICAL
}

void indie::Bombup::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value)
{
        _mesh->setMaterialFlag(flag, value);
}

void indie::Bombup::setPosition(core::vector3df const& pos)
{
        _mesh->setPosition(pos);
        _mesh->updateAbsolutePosition();
}

core::vector3df const& indie::Bombup::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::Bombup::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
        _pos = pos;
}

core::vector3df const& indie::Bombup::getRotation(void) const
{
        return (_mesh->getRotation());
}

core::aabbox3df const indie::Bombup::getBoundingBox(void) const
{
        return (_mesh->getTransformedBoundingBox());
}

bool indie::Bombup::isColliding(core::aabbox3df const& box) const
{
        return (box.intersectsWithBox(getBoundingBox()));
}

void indie::Bombup::setPickup(const bool pickup)
{
        _pickup = pickup;
        if (_pickup == true)
        {
                setPosition(core::vector3df(getPosition().X, -100.0f, getPosition().Z));
        }
}

bool indie::Bombup::getPickup() const
{
        return (_pickup);
}
