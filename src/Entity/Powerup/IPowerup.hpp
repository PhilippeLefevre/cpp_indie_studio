//
//
// IPowerup.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Powerup/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 11 02:04:03 2017 Philippe Lefevre
// Last update Sun Jun 18 11:04:08 2017 Philippe Lefevre
//


#ifndef IPOWERUP_HPP_
# define IPOWERUP_HPP_

# include "IEntity.hpp"

namespace indie
{
        class IPowerup : public IEntity
        {
        public:
                virtual ~IPowerup(void) {}
                virtual void setPosition(core::vector3df const&) = 0;
                virtual core::vector3df const& getPosition(void) const = 0;
                virtual void setRotation(core::vector3df const&) = 0;
                virtual core::vector3df const& getRotation(void) const = 0;
                virtual core::aabbox3df const getBoundingBox(void) const = 0;
                virtual bool isColliding(core::aabbox3df const& box) const = 0;
                virtual void setPickup(const bool) = 0;
                virtual bool getPickup() const = 0;
        };
}

#endif /* !IPOWERUP_HPP_ */
