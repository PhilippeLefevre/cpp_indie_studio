//
// Game.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Game/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 11 01:42:46 2017 Philippe Lefevre
// Last update Sun Jun 18 17:08:18 2017 Philippe Lefevre
//

#ifndef GAME_HPP_
# define GAME_HPP_

# include <vector>
# include <ITimer.h>
# include "IndestructibleBlock.hpp"
# include "DestructibleBlock.hpp"
# include "PlayerCharacter.hpp"
# include "NonPlayerCharacter.hpp"
# include "Normal.hpp"
# include "Bombup.hpp"
# include "EventReceiver.hpp"

class Game
{
private:

        IrrlichtDevice *_device;
        MyEventReceiver *_receiver;
        scene::ISceneManager *_sceneManager;
        video::IVideoDriver *_driver;
        ITimer *_timer;

        std::vector<indie::IEntity*> _ground;
        std::vector<indie::IEntity*> _block;
        std::vector<indie::IEntity*> _character;
        std::vector<indie::IEntity*> _bomb;
        std::vector<indie::IEntity*> _powerup;

public:

        Game();
        virtual ~Game();
        Game(const Game& obj);
        Game &operator=(const Game& obj);
        void Play();
        void init(std::vector<indie::EntityType> const);
};

#endif /* !GAME_HPP_ */
