//
// DestructibleBlock.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:07:30 2017 Philippe Lefevre
// Last update Wed Jun 14 10:00:58 2017 Philippe Lefevre
//

#ifndef DESTRUCTIBLEBLOCK_HPP_
# define DESTRUCTIBLEBLOCK_HPP_

# include "IBlock.hpp"

namespace indie
{
        class DestructibleBlock : public IBlock
        {
        private:
                scene::IMeshSceneNode *_mesh;
                scene::ISceneManager *_scnMngr;
                video::IVideoDriver* _driver;
                core::vector3df _pos;
                bool _explosed;
        public:
                DestructibleBlock(scene::ISceneManager*, core::vector3df, video::IVideoDriver*, bool);
                ~DestructibleBlock(void);
                DestructibleBlock(const DestructibleBlock &obj);
                DestructibleBlock &operator=(const DestructibleBlock &obj);
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

#endif /* !DESTRUCTIBLEBLOCK_HPP_ */
