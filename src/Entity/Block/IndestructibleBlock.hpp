//
// IndestructibleBlock.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:07:30 2017 Philippe Lefevre
// Last update Wed Jun 14 10:01:09 2017 Philippe Lefevre
//

#ifndef INDESTRUCTIBLEBLOCK_HPP_
# define INDESTRUCTIBLEBLOCK_HPP_

# include "IBlock.hpp"

namespace indie
{
        class IndestructibleBlock : public IBlock
        {
        private:
                scene::IMeshSceneNode *_mesh;
                scene::ISceneManager *_scnMngr;
                video::IVideoDriver* _driver;
                core::vector3df _pos;
        public:
                IndestructibleBlock(scene::ISceneManager*, core::vector3df, video::IVideoDriver*);
                ~IndestructibleBlock(void);
                IndestructibleBlock(const IndestructibleBlock &obj);
                IndestructibleBlock &operator=(const IndestructibleBlock &obj);
                void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value);
                void setPosition(core::vector3df const&);
                core::vector3df const& getPosition(void) const;
                void setRotation(core::vector3df const&);
                core::vector3df const& getRotation(void) const;
                core::aabbox3df const getBoundingBox(void) const;
                bool isColliding(core::aabbox3df const& box) const;
        };
}

#endif /* !INDESTRUCTIBLEBLOCK_HPP_ */
