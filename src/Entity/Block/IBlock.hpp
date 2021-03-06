//
// IBlock.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 11 02:04:03 2017 Philippe Lefevre
// Last update Wed Jun 14 18:04:58 2017 Philippe Lefevre
//


#ifndef IBLOCK_HPP_
# define IBLOCK_HPP_

# include "IEntity.hpp"

namespace indie
{
        class IBlock : public IEntity
        {
        public:
                virtual ~IBlock(void) {}
                virtual void setPosition(core::vector3df const&) = 0;
                virtual core::vector3df const& getPosition(void) const = 0;
                virtual void setRotation(core::vector3df const&) = 0;
                virtual core::vector3df const& getRotation(void) const = 0;
                virtual core::aabbox3df const getBoundingBox(void) const = 0;
                virtual bool isColliding(core::aabbox3df const& box) const = 0;
                virtual bool isExplosible(void) const = 0;
        };
}

#endif /* !IBLOCK_HPP_ */
