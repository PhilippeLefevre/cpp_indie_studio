//
// Normal.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:11:44 2017 Philippe Lefevre
// Last update Sat Jun 17 05:03:04 2017 Philippe Lefevre
//

#include <IVideoDriver.h>
#include "IBlock.hpp"
#include "DestructibleBlock.hpp"
#include "Normal.hpp"

indie::Normal::Normal(scene::ISceneManager *scnMngr, core::vector3df pos, video::IVideoDriver *driver, indie::ICharacter *owner, u32 time) : _scnMngr(scnMngr), _pos(pos), _driver(driver), _owner(owner), _time(time)
{
        std::string txt = "media/Bombs/MegaBomb/MegaBomb.obj";
        _mesh = _scnMngr->addMeshSceneNode(_scnMngr->getMesh(txt.data()));
        if (_mesh)
        {
                _mesh->setScale(core::vector3df(0.7f, 0.7f, 0.7f));
                _mesh->setPosition(pos);
                _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        }
        else
        {
                std::cerr << "Error: cannot add bomb" << std::endl;
        }
        _explosed = false;
        _level = 2;
}

indie::Normal::~Normal()
{
        if (_mesh)
        {
                _mesh->remove();
        }
}

indie::Normal::Normal(const Normal &obj)
{
        _mesh = obj._mesh;
        _scnMngr = obj._scnMngr;
        _pos = obj._pos;
}

indie::Normal &indie::Normal::operator=(const Normal &obj)
{
        // DO CANONICAL
}

void indie::Normal::setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value)
{
        _mesh->setMaterialFlag(flag, value);
}

void indie::Normal::setPosition(core::vector3df const& pos)
{
        _mesh->setPosition(pos);
        _mesh->updateAbsolutePosition();
        _pos = getPosition();
}

core::vector3df const& indie::Normal::getPosition(void) const
{
        return (_mesh->getPosition());
}

void indie::Normal::setRotation(core::vector3df const& pos)
{
        _mesh->setRotation(pos);
}

core::vector3df const& indie::Normal::getRotation(void) const
{
        return (_mesh->getRotation());
}

core::aabbox3df const indie::Normal::getBoundingBox(void) const
{
        return (_mesh->getTransformedBoundingBox());
}

bool indie::Normal::isColliding(core::aabbox3df const& box) const
{
        return (box.intersectsWithBox(getBoundingBox()));
}

bool indie::Normal::isExplosed(void) const
{
        return (_explosed);
}

void indie::Normal::Explose(std::vector<indie::IEntity*> const& block, const u32 time)
{
        if (time > (_time + TIME_TO_EXPLOSE))
        {
                _pos = getPosition();
                int x, z;
                x = _pos.X / 10;
                z = _pos.Z / 10;
                for (size_t i = 0; i < _level; i++)
                {
                        if (((x * 14 + z + x) + (i * 15)) > 0 && ((x * 14 + z + x) + (i * 15)) < 225 && ((indie::IBlock*)block.at((x * 14 + z + x) + (i * 15)))->isExplosible())
                        {
                                (((indie::DestructibleBlock*)block.at((x * 14 + z + x) + (i * 15)))->Explose());
                        }
                        if (((x * 14 + z + x) - (i * 15)) > 0 && ((x * 14 + z + x) - (i * 15)) < 225 && ((indie::IBlock*)block.at((x * 14 + z + x) - (i * 15)))->isExplosible())
                        {
                                (((indie::DestructibleBlock*)block.at((x * 14 + z + x) - (i * 15)))->Explose());
                        }
                        if (((x * 14 + z + x) + (i * 1)) > 0 && ((x * 14 + z + x) + (i * 1)) < 225 && ((indie::IBlock*)block.at((x * 14 + z + x) + (i * 1)))->isExplosible())
                        {
                                (((indie::DestructibleBlock*)block.at((x * 14 + z + x) + (i * 1)))->Explose());
                        }
                        if (((x * 14 + z + x) - (i * 1)) > 0 && ((x * 14 + z + x) - (i * 1)) < 225 && ((indie::IBlock*)block.at((x * 14 + z + x) - (i * 1)))->isExplosible())
                        {
                                (((indie::DestructibleBlock*)block.at((x * 14 + z + x) - (i * 1)))->Explose());
                        }
                }
                _explosed = true;
                _owner->giveBomb(1);
                setPosition(_pos);
        }
}
