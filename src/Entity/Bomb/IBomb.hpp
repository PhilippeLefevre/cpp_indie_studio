//
// IBomb.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Bomb/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 11 02:04:03 2017 Philippe Lefevre
// Last update Wed Jun 14 18:20:55 2017 Philippe Lefevre
//


#ifndef IBOMB_HPP_
# define IBOMB_HPP_

# include "IEntity.hpp"

namespace indie
{
        class IBomb : public IEntity
        {
        public:
                virtual ~IBomb(void) {}
                virtual void setPosition(core::vector3df const&) = 0;
                virtual core::vector3df const& getPosition(void) const = 0;
                virtual void setRotation(core::vector3df const&) = 0;
                virtual core::vector3df const& getRotation(void) const = 0;
                virtual core::aabbox3df const getBoundingBox(void) const = 0;
                virtual bool isColliding(core::aabbox3df const& box) const = 0;
                virtual bool isExplosed(void) const = 0;
                virtual void Explose(std::vector<indie::IEntity*> const&) = 0;
        };
}

#endif /* !IBOMB_HPP_ */
