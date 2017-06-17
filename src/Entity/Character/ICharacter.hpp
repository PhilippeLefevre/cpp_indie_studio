//
// ICharacter.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Character/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 11 02:04:03 2017 Philippe Lefevre
// Last update Sat Jun 17 03:13:55 2017 Philippe Lefevre
//


#ifndef ICHARACTER_HPP_
# define ICHARACTER_HPP_

# include <vector>
# include "IEntity.hpp"

namespace indie
{
        class ICharacter : public IEntity
        {
        public:
                virtual ~ICharacter(void) {}
                virtual void setPosition(core::vector3df const&) = 0;
                virtual core::vector3df const& getPosition(void) const = 0;
                virtual void setRotation(core::vector3df const&) = 0;
                virtual core::vector3df const& getRotation(void) const = 0;
                virtual core::aabbox3df const getBoundingBox(void) const = 0;
                virtual bool isColliding(core::aabbox3df const& box) const = 0;
                virtual bool Move(const f32, std::vector<indie::IEntity*> const&, std::vector<indie::IEntity*>*) = 0;
                virtual bool isDied(void) const = 0;
                virtual void Die(void) = 0;
                virtual void giveBomb(unsigned int) = 0;
        };
}

#endif /* !ICHARACTER_HPP_ */
