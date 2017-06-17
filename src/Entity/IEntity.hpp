//
// IEntity.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 11 01:44:50 2017 Philippe Lefevre
// Last update Sat Jun 17 04:28:49 2017 Philippe Lefevre
//

#ifndef IENTITY_HPP_
# define IENTITY_HPP_

# include <irrlicht.h>
# include <iostream>
# include <vector>

using namespace irr;

namespace indie
{
        enum EntityType
        {
                BLOCK_EMPTY = 0,
                BLOCK_INDESTRUCTIBLE,
                BLOCK_DESTRUCTIBLE,
                PC_ONE,
                PC_TWO,
                PC_THREE,
                PC_FOUR,
                NPC_ONE,
                NPC_TWO,
                NPC_THREE,
                NPC_FOUR,
                BOMB_NORMAL,
                BOMB_NUKE,
                POWERUP_BOMBUP,
                POWERUP_SPEED,
                POWERUP_VEST
        };

        class IEntity
        {
        public:
                virtual ~IEntity(void) {}
                virtual void setPosition(core::vector3df const&) = 0;
                virtual core::vector3df const& getPosition(void) const = 0;
                virtual void setRotation(core::vector3df const&) = 0;
                virtual core::vector3df const& getRotation(void) const = 0;
                virtual core::aabbox3df const getBoundingBox(void) const = 0;
                virtual bool isColliding(core::aabbox3df const& box) const = 0;
        };
}

#endif /* !IENTITY_HPP_ */
