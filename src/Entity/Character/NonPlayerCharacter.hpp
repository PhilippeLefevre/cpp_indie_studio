//
// NonPlayerCharacter.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:07:30 2017 Philippe Lefevre
// Last update Sat Jun 17 03:15:46 2017 Philippe Lefevre
//

#ifndef NONPLAYERCHARACTER_HPP_
# define NONPLAYERCHARACTER_HPP_

# include "ICharacter.hpp"

namespace indie
{
        class NonPlayerCharacter : public ICharacter
        {
        private:
                scene::IMeshSceneNode *_mesh;
                scene::ISceneManager *_scnMngr;
                video::IVideoDriver* _driver;
                core::vector3df _pos;
                ITimer *_timer;
                float _MaxXZ;
                float _MinXZ;
                bool _died;
                f32 _speed;
                unsigned int _bomb;
                int _direction;
                bool _rotate;
        public:
                NonPlayerCharacter(scene::ISceneManager*, core::vector3df, video::IVideoDriver*, ITimer*);
                ~NonPlayerCharacter(void);
                NonPlayerCharacter(const NonPlayerCharacter &obj);
                NonPlayerCharacter &operator=(const NonPlayerCharacter &obj);
                void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool value);
                void setPosition(core::vector3df const&);
                core::vector3df const& getPosition(void) const;
                void setRotation(core::vector3df const&);
                core::vector3df const& getRotation(void) const;
                core::aabbox3df const getBoundingBox(void) const;
                bool isColliding(core::aabbox3df const& box) const;
                bool isDied(void) const;
                void Die(void);
                bool Move(const f32, std::vector<indie::IEntity*> const&, std::vector<indie::IEntity*>*);
                void giveBomb(unsigned int);
        };
}

#endif /* !NONPLAYERCHARACTER_HPP_ */
