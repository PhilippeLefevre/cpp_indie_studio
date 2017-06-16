//
// DestructibleBlock.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Wed Jun 14 18:06:45 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "DestructibleBlock.hpp"

indie::DestructibleBlock::DestructibleBlock(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver, bool explosed) : _scnMngr(scnMngr), _pos(pos), _driver(driver), _explosed(explosed)
{
        std::string txt = "media/texture_red.bmp";
        _mesh = _scnMngr->addCubeSceneNode(10.0f, 0, -1, _pos);
        if (_mesh)
        {
                video::ITexture *texture = _driver->getTexture(txt.data());
                if (texture != 0)
                {
                        _mesh->setMaterialTexture(0, texture);
                }
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        }
        else
        {
                std::cerr << "Error: cannot add block" << std::endl;
        }
        if (_explosed)
        {
                Explose();
        }
}

indie::DestructibleBlock::~DestructibleBlock()
{
        if (_mesh)
        {
                _mesh->remove();
        }
}

indie::DestructibleBlock::DestructibleBlock(const DestructibleBlock &obj)
{
        _mesh = obj._mesh;
        _scnMngr = obj._scnMngr;
        _pos = obj._pos;
}

indie::DestructibleBlock &indie::DestructibleBlock::operator=(const DestructibleBlock &obj)
{
        // DO CANONICAL
}

void indie::DestructibleBlock::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value)
{
        _mesh->setMaterialFlag(flag, value);
}

void indie::DestructibleBlock::setPosition(core::vector3df const& pos)
{
        _mesh->setPosition(pos);
        _mesh->updateAbsolutePosition();
}

core::vector3df const& indie::DestructibleBlock::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::DestructibleBlock::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
        _pos = pos;
}

core::vector3df const& indie::DestructibleBlock::getRotation(void) const
{
        return (_mesh->getRotation());
}

core::aabbox3df const indie::DestructibleBlock::getBoundingBox(void) const
{
        return (_mesh->getTransformedBoundingBox());
}

bool indie::DestructibleBlock::isColliding(core::aabbox3df const& box) const
{
        return (box.intersectsWithBox(getBoundingBox()));
}

bool indie::DestructibleBlock::isExplosed(void) const
{
        return (_explosed);
}

void indie::DestructibleBlock::Explose(void)
{
        _explosed = true;
        _pos.Y -= 20;
        setPosition(_pos);
}

bool indie::DestructibleBlock::isExplosible(void) const
{
        return (!isExplosed());
}
