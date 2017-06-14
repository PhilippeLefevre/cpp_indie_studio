//
// Game.hh for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed May 31 09:47:34 2017 Philippe Lefevre
// Last update Sun Jun 11 02:11:11 2017 Philippe Lefevre
//

#ifndef GAME_HH_
# define GAME_HH_

# include "EventReceiver.hpp"

# define	_PLAYER_SPEED	80

typedef struct	s_tile
{
        bool isDestructible;
        irr::scene::IMeshSceneNode *block;
}               t_tile;

class Game {
private:
        MyEventReceiver _receiver;
        irr::IrrlichtDevice* _device;
        irr::video::IVideoDriver* _driver;
        irr::scene::ISceneManager* _sceneManager;
        std::vector<irr::scene::IMeshSceneNode*> _ground;
        std::vector<irr::scene::IMeshSceneNode*> _wall;
        std::vector<irr::scene::IMeshSceneNode*> _player;
        std::vector<irr::scene::IMeshSceneNode*> _bombe;

        std::vector<t_tile*> _myMap;

        irr::f32 _speed;
        int _lfps;
        int _fps;

        int _map[15][15] = {
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1 },
                { 1, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 1 },
                { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
                { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
                { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
                { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
                { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
                { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
                { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
                { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
                { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
                { 1, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 1 },
                { 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1 },
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
        };
public:
        Game ();
        virtual ~Game ();
        Game(const Game &);
        Game        &operator=(const Game &);

public:
        void launch();
        void dispFPS();
        void move(core::vector3df *, const f32);
};

#endif /* !GAME_HH_ */
