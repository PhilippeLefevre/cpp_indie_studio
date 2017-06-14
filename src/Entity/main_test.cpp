//
// main_test.cpp for  in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Entity/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed Jun 14 05:13:36 2017 Philippe Lefevre
// Last update Wed Jun 14 18:30:53 2017 Philippe Lefevre
//

#include "IndestructibleBlock.hpp"
#include "DestructibleBlock.hpp"
#include "PlayerCharacter.hpp"
#include "NonPlayerCharacter.hpp"
#include "Normal.hpp"
#include "EventReceiver.hpp"
#include <vector>

int	main(void)
{
        MyEventReceiver *_receiver = new MyEventReceiver;
        scene::ISceneManager *_sceneManager;
        IrrlichtDevice* _device;
        video::IVideoDriver* _driver;

        _device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 32, false, false, false, _receiver);
        _driver = _device->getVideoDriver();
        _sceneManager = _device->getSceneManager();
        _sceneManager->addCameraSceneNode(0, core::vector3df(80.0f, 40.0f, 40.0f), core::vector3df(80.0f, -80.0f, 60.0f), 0, true);
        _device->getCursorControl()->setVisible(false);

        int _map[15][15] = {
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::NPC_TWO, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::PC_ONE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::NPC_TWO, indie::EntityType::BLOCK_EMPTY, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_DESTRUCTIBLE, indie::EntityType::BLOCK_EMPTY, indie::EntityType::NPC_THREE, indie::EntityType::BLOCK_INDESTRUCTIBLE },
                { indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE, indie::EntityType::BLOCK_INDESTRUCTIBLE }
        };

        std::vector<indie::IEntity*> ground;
        std::vector<indie::IEntity*> block;
        std::vector<indie::IEntity*> character;
        std::vector<indie::IEntity*> bomb;
        for (size_t x = 0; x < 15; x++)
        {
                for (size_t y = 0; y < 15; y++)
                {
                        ground.push_back(new indie::IndestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -80.0f, (y * 10.0f)), _driver));
                        switch (_map[x][y])
                        {
                                case indie::EntityType::BLOCK_EMPTY: block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, true)); break;
                                case indie::EntityType::BLOCK_INDESTRUCTIBLE: block.push_back(new indie::IndestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver)); break;
                                case indie::EntityType::BLOCK_DESTRUCTIBLE: block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                                case indie::EntityType::PC_ONE: character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, _receiver)); break;
                                case indie::EntityType::PC_TWO: character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, _receiver)); break;
                                case indie::EntityType::PC_THREE: character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, _receiver)); break;
                                case indie::EntityType::PC_FOUR: character.push_back(new indie::PlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, _receiver)); break;
                                case indie::EntityType::NPC_ONE: character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver)); break;
                                case indie::EntityType::NPC_TWO: character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver)); break;
                                case indie::EntityType::NPC_THREE: character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver)); break;
                                case indie::EntityType::NPC_FOUR: character.push_back(new indie::NonPlayerCharacter(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver)); break;
                                case indie::EntityType::POWERUP_BOMBUP: block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                                case indie::EntityType::POWERUP_SPEED: block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                                case indie::EntityType::POWERUP_VEST: block.push_back(new indie::DestructibleBlock(_sceneManager, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f)), _driver, false)); break;
                        }
                }
        }



        u32 then = _device->getTimer()->getTime();

        while(_device->run())
        {
                if (_receiver->IsKeyDown(KEY_ESCAPE))
                {
                        std::cout << "escape event" << std::endl;
                        break;
                }

                const u32 now = _device->getTimer()->getTime();
                const f32 fps = (f32)(now - then) / 1000.0f;
                then = now;
                for (indie::IEntity *w : character)
                {
                        bool status = ((indie::ICharacter*)w)->Move(fps, block, &bomb);
                }
                for (indie::IEntity *w : bomb)
                {
                        ((indie::IBomb*)w)->Explose(block);
                }
                _driver->beginScene(true, true, video::SColor(255, 113, 113, 133));
                _sceneManager->drawAll();
                _device->getGUIEnvironment()->drawAll();
                _driver->endScene();
        }


        for (indie::IEntity *w : block)
        {
                delete w;
        }
        for (indie::IEntity *w : character)
        {
                delete w;
        }
        for (indie::IEntity *w : ground)
        {
                delete w;
        }
        delete _receiver;
        _device->drop ();
        return (0);
}
