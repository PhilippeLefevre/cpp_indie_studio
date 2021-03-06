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

#include <ctime>
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
        for (indie::IEntity *w : _bomb)
        {
                delete w;
        }
        for (indie::IEntity *w : _powerup)
        {
                delete w;
        }
        if (_receiver)
        {
                delete _receiver;
        }
        if (_device)
        {
                _device->drop();
        }
}

Game::Game(const Game& obj)
{
        _device = obj._device;
        _receiver = obj._receiver;
        _sceneManager = obj._sceneManager;
        _driver = obj._driver;
        _timer = obj._timer;
        _ground = obj._ground;
        _block = obj._block;
        _character = obj._character;
        _bomb = obj._bomb;
        _powerup = obj._powerup;
}

Game &Game::operator=(const Game& obj)
{
        Game *tmp = new Game(obj);
        return (*tmp);
}

void Game::init(std::vector<indie::EntityType> const _map)
{
        _receiver = new MyEventReceiver;
        _device   = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 32, false, false, false, _receiver);
        _device->getCursorControl()->setVisible(false);
        _timer = _device->getTimer();

        _driver	= _device->getVideoDriver();
        _sceneManager = _device->getSceneManager();
        _sceneManager->addCameraSceneNode(0, core::vector3df(80.0f, 40.0f, 40.0f), core::vector3df(80.0f, -80.0f, 60.0f), 0, true);

        std::srand(std::time(0));

        for (size_t x = 0; x < 15; x++)
        {
                for (size_t y = 0; y < 15; y++)
                {
                        _ground.push_back(new indie::IndestructibleBlock(_sceneManager, core::vector3df((x * 10), -80.0f, (y * 10)), _driver));
                        int nb = std::rand() % 10;
                        switch (_map.at(x * 15 + y))
                        {
                                case indie::EntityType::BLOCK_EMPTY: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::BLOCK_INDESTRUCTIBLE: _block.push_back(new indie::IndestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver)); break;
                                case indie::EntityType::BLOCK_DESTRUCTIBLE: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, false)); ((nb == 4 || nb == 5) ? (_powerup.push_back(new indie::Bombup(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver))) : (((nb == 6 || nb == 7) ? (_powerup.push_back(new indie::Bombup(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver))) : (((nb == 8 || nb == 9) ? (_powerup.push_back(new indie::Bombup(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver))) : ((void)nb)))))); break;
                                case indie::EntityType::PC_ONE: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _receiver, _timer, _character.size())); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::PC_TWO: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _receiver, _timer, _character.size())); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::PC_THREE: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _receiver, _timer, _character.size())); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::PC_FOUR: _character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _receiver, _timer, _character.size())); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::NPC_ONE: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::NPC_TWO: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::NPC_THREE: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::NPC_FOUR: _character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10 + 0.5f), -70.0f, (y * 10 + 0.5f)), _driver, _timer)); _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, true)); break;
                                case indie::EntityType::POWERUP_BOMBUP: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, false)); break;
                                case indie::EntityType::POWERUP_SPEED: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, false)); break;
                                case indie::EntityType::POWERUP_VEST: _block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10), -70.0f, (y * 10)), _driver, false)); break;
                        }
                }
                std::cout << std::endl;
        }
}

void Game::Play()
{
        u32   then = _device->getTimer()->getTime();

        while (_device->run())
        {
                if (_receiver->IsKeyDown(KEY_ESCAPE))
                {
                        break;
                }

                const u32   now = _device->getTimer()->getTime();
                const f32   fps = (f32)(now - then) / 1000.0f;
                then = now;
                int i = 0;
                for (indie::IEntity *w : _character)
                {
                        if (((indie::ICharacter*)w)->isDied() == false)
                        {
                                i++;
                                ((indie::ICharacter*)w)->Move(fps, _block, &_bomb);
                        }
                }
                if (i <= 1)
                {
                        std::cout << "Won Game" << std::endl;
                        break;
                }
                for (indie::IEntity *w : _bomb)
                {
                        if (w && ((indie::IBomb*)w)->isExplosed() == false)
                        {
                                ((indie::IBomb*)w)->Explose(_block, _timer->getTime());
                                if (((indie::IBomb*)w)->isExplosed() == true)
                                {
                                        core::vector3df pos_bomb = ((indie::IBomb*)w)->getPosition();
                                        int i = 0;
                                        for (indie::IEntity *v : _character)
                                        {
                                                if (((indie::IBomb*)w)->getPosition().getDistanceFrom(((indie::ICharacter*)v)->getPosition()) < 13)
                                                {

                                                        ((indie::ICharacter*)v)->setPosition(core::vector3df(((indie::ICharacter*)v)->getPosition().X, -100.0f, ((indie::ICharacter*)v)->getPosition().Z));
                                                        ((indie::ICharacter*)v)->Die();
                                                        _character.erase(_character.begin() + i);
                                                }
                                                i++;
                                        }
                                        ((indie::IBomb*)w)->setPosition(core::vector3df(((indie::IBomb*)w)->getPosition().X, -100.0f, ((indie::IBomb*)w)->getPosition().Z));
                                }
                        }
                }
                //int j = 0;
                //for (indie::IEntity *w : _bomb)
                //{
                //        if (((indie::IBomb*)w)->isExplosed())
                //        {
                //                _bomb.erase(_bomb.begin() + j);
                //        }
                //        j++;
                //}
                int k = 0;
                for (indie::IEntity *w : _powerup)
                {
                        for (indie::IEntity *v : _character)
                        {
                                if (((indie::IPowerup*)w)->isColliding(((indie::IPowerup*)v)->getBoundingBox()))
                                {
                                        if (((indie::IPowerup*)w)->getPickup() == false)
                                        {
                                                ((indie::ICharacter*)v)->giveBomb(1);
                                                ((indie::IPowerup*)w)->setPickup(true);
                                                _powerup.erase(_powerup.begin() + k);
                                        }
                                }
                        }
                        k++;
                }
                _driver->beginScene(true, true, video::SColor(255, 113, 113, 133));
                _sceneManager->drawAll();
                _device->getGUIEnvironment()->drawAll();
                _driver->endScene();
        }
}
