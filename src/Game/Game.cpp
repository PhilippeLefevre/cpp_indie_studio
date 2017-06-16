//

// Game.cpp for IndieStudio in
// /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Game/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Thu Jun 15 17:25:23 2017 Philippe Lefevre
// Last update Fri Jun 16 02:19:58 2017 John Doe
//

#include "Game.hpp"

Game::Game()
{
        _receiver = nullptr;
        _device	= nullptr;
        _timer	= nullptr;
        _driver	= nullptr;
        _sceneManager = nullptr;
}

Game::~Game()
{
        for (indie::IEntity *w : _block)
        {
                delete w;
        }
        for (indie::IEntity *w : _character)
        {
                delete w;
        }
        for (indie::IEntity *w : _ground)
        {
                delete w;
        }
        if (_receiver)
        delete _receiver;
}

Game::Game(const Game& obj)
{

}

Game	 & Game::operator=(const Game& obj)
{

}

void     Game::init(const int _map[15][15])
{
        _receiver = new MyEventReceiver;
        _device   = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 32, false, false, false, _receiver);
        _device->getCursorControl()->setVisible(false);
        _timer = _device->getTimer();

        _driver	= _device->getVideoDriver();
        _sceneManager = _device->getSceneManager();
        _sceneManager->addCameraSceneNode(0, core::vector3df(80.0f, 40.0f, 40.0f), core::vector3df(80.0f, -80.0f, 60.0f), 0, true);


        for (size_t x = 0; x < 15; x++)
        {
                for (size_t y = 0; y < 15; y++)
                {
                        _ground.push_back(new indie::IndestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -80.0f, (y * 10.0f)), _driver));

                        switch (_map[x][y])
                        {
                                case indie::EntityType::BLOCK_EMPTY: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::BLOCK_INDESTRUCTIBLE: _block.push_back(new indie::IndestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver)); break;
                                case indie::EntityType::BLOCK_DESTRUCTIBLE: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                                case indie::EntityType::PC_ONE: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _receiver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::PC_TWO: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _receiver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::PC_THREE: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _receiver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::PC_FOUR: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _receiver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::NPC_ONE: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::NPC_TWO: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::NPC_THREE: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::NPC_FOUR: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f + 0.5f), -70.0f, (y * 10.0f + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::POWERUP_BOMBUP: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                                case indie::EntityType::POWERUP_SPEED: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                                case indie::EntityType::POWERUP_VEST: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                        }
                }
        }
}

void	 Game::Play()
{
        u32   then = _device->getTimer()->getTime();

        while (_device->run())
        {
                if (_receiver->IsKeyDown(KEY_ESCAPE))
                {
                        std::cout << "escape event" << std::endl;
                        _device->closeDevice();
                        break;
                }

                const u32   now = _device->getTimer()->getTime();
                const f32   fps = (f32)(now - then) / 1000.0f;
                then = now;
                for (indie::IEntity *w : _character)
                {
                        bool   status = ((indie::ICharacter*)w)->Move(fps, _block, &_bomb);
                }
                for (indie::IEntity *w : _bomb)
                {
                        if (w && ((indie::IBomb*)w)->isExplosed() == false)
                        {
                                ((indie::IBomb*)w)->Explose(_block, _timer->getTime());
                        }
                }

                // for (indie::IEntity *w : _bomb)
                // {
                //        if (((indie::IBomb*)w)->isExplosed())
                //        {
                //                delete w;
                //                break;
                //        }
                // }
                _driver->beginScene(true, true, video::SColor(255, 113, 113, 133));
                _sceneManager->drawAll();
                _device->getGUIEnvironment()->drawAll();
                _driver->endScene();
        }
        if (_device)
        _device->drop();
}
