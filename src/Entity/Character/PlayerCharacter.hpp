//
// PlayerCharacter.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/Block/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:07:30 2017 Philippe Lefevre
// Last update Sat Jun 17 04:30:53 2017 Philippe Lefevre
//

#ifndef PLAYERCHARACTER_HPP_
# define PLAYERCHARACTER_HPP_

# include "ICharacter.hpp"
# include "EventReceiver.hpp"

# define	_PLAYER_SPEED	40

namespace indie
{
        class PlayerCharacter : public ICharacter
        {
        private:
                scene::IMeshSceneNode *_mesh;
                scene::ISceneManager *_scnMngr;
                video::IVideoDriver* _driver;
                core::vector3df _pos;
                core::vector3df _rot;
                MyEventReceiver *_receiver;
                ITimer *_timer;
                bool _died;
                f32 _speed;
		int _id;
                unsigned int _bomb;
        public:
		PlayerCharacter(scene::ISceneManager*, core::vector3df, video::IVideoDriver*, MyEventReceiver*, ITimer*, int);
                ~PlayerCharacter(void);
                PlayerCharacter(const PlayerCharacter &obj);
                PlayerCharacter &operator=(const PlayerCharacter &obj);
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

#endif /* !PLAYERCHARACTER_HPP_ */
