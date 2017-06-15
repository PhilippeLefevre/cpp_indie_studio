//
// IndestructibleBlock.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Wed Jun 14 18:05:43 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "IndestructibleBlock.hpp"

indie::IndestructibleBlock::IndestructibleBlock(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver) : _scnMngr(scnMngr), _pos(pos), _driver(driver)
{
        std::string txt = "texture_blue.bmp";
        _mesh = _scnMngr->addCubeSceneNode(10.0f, 0, -1, _pos);
        if (_mesh)
        {
                video::ITexture *texture = _driver->getTexture(txt.data());
                if (texture != 0)
                {
                        _mesh->setMaterialTexture(0, texture);
                }
                if (_pos.Y < -70)
                {
                        _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, true);
                }
                else
                {
                        _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                }
        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
}

indie::IndestructibleBlock::~IndestructibleBlock()
{
        if (_mesh)
        {
                _mesh->remove();
        }
}

indie::IndestructibleBlock::IndestructibleBlock(const IndestructibleBlock &obj)
{
        _mesh = obj._mesh;
        _scnMngr = obj._scnMngr;
        _pos = obj._pos;
}

indie::IndestructibleBlock &indie::IndestructibleBlock::operator=(const IndestructibleBlock &obj)
{
        // DO CANONICAL
}

void indie::IndestructibleBlock::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value)
{
        _mesh->setMaterialFlag(flag, value);
}

void indie::IndestructibleBlock::setPosition(core::vector3df const& pos)
{
        _mesh->setPosition(pos);
        _mesh->updateAbsolutePosition();
}

core::vector3df const& indie::IndestructibleBlock::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::IndestructibleBlock::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
}

core::vector3df const& indie::IndestructibleBlock::getRotation(void) const
{
        return (_mesh->getRotation());
}

core::aabbox3df const indie::IndestructibleBlock::getBoundingBox(void) const
{
        return (_mesh->getTransformedBoundingBox());
}

bool indie::IndestructibleBlock::isColliding(core::aabbox3df const& box) const
{
        return (box.intersectsWithBox(getBoundingBox()));
}

bool indie::IndestructibleBlock::isExplosible(void) const
{
        return (false);
}