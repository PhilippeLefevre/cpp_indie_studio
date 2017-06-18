//
// Bombup.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Powerup/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:07:30 2017 Philippe Lefevre
// Last update Sun Jun 18 11:04:36 2017 Philippe Lefevre
//

#ifndef POWERUP_HPP_
# define POWERUP_HPP_

# include "IPowerup.hpp"

namespace indie
{
        class Bombup : public IPowerup
        {
        private:
                scene::IMeshSceneNode *_mesh;
                scene::ISceneManager *_scnMngr;
                video::IVideoDriver* _driver;
                core::vector3df _pos;
                bool _pickup;
        public:
                Bombup(scene::ISceneManager*, core::vector3df, video::IVideoDriver*);
                ~Bombup(void);
                Bombup(const Bombup &obj);
                Bombup &operator=(const Bombup &obj);
                void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value);
                void setPosition(core::vector3df const&);
                core::vector3df const& getPosition(void) const;
                void setRotation(core::vector3df const&);
                core::vector3df const& getRotation(void) const;
                core::aabbox3df const getBoundingBox(void) const;
                bool isColliding(core::aabbox3df const& box) const;
                void setPickup(const bool);
                bool getPickup() const;
        };
}

#endif /* !POWERUP_HPP_ */
