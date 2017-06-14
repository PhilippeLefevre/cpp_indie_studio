//
// Normal.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:07:30 2017 Philippe Lefevre
// Last update Wed Jun 14 12:22:25 2017 Philippe Lefevre
//

#ifndef NORMAL_HPP_
# define NORMAL_HPP_

# include "IBomb.hpp"

namespace indie
{
        class Normal : public IBomb
        {
        private:
                scene::IMeshSceneNode *_mesh;
                scene::ISceneManager *_scnMngr;
                video::IVideoDriver* _driver;
                core::vector3df _pos;
                bool _explosed;
        public:
                Normal(scene::ISceneManager*, core::vector3df, video::IVideoDriver*);
                ~Normal(void);
                Normal(const Normal &obj);
                Normal &operator=(const Normal &obj);
                void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value);
                void setPosition(core::vector3df const&);
                core::vector3df const& getPosition(void) const;
                void setRotation(core::vector3df const&);
                core::vector3df const& getRotation(void) const;
                core::aabbox3df const getBoundingBox(void) const;
                bool isColliding(core::aabbox3df const& box) const;
                bool isExplosed(void) const;
                void Explose(void);
        };
}

#endif /* !NORMAL_HPP_ */
