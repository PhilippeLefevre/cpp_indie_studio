//
// Game.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Wed May 31 09:47:49 2017 Philippe Lefevre
// Last update Fri Jun  9 01:27:22 2017 Philippe Lefevre
//

#include <irrlicht.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Game.hh"

Game::Game()
{
        _device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 32, false, false, false, &_receiver);
        _driver = _device->getVideoDriver();

        _sceneManager = _device->getSceneManager();

        std::string file = "media/map.bbm";
        std::ifstream afile(file.c_str(), std::ios::in);
        if (afile.is_open())
        {
                std::string line;
                int j = 0;
                while (std::getline(afile, line))
                {
                        if (line.size() != 15)
                        {
                                std::cerr << "Error: Invalid size map [" << file << ":" << (j + 1) << "]" << std::endl;
                                std::exit(0);
                        }
                        else if (j == 0 || j == 14)
                        {
                                for (size_t i = 0; i < 15; i++)
                                {
                                        if (line[i] != '1')
                                        {
                                                std::cerr << "Error: Invalid border [" << file << ":" << (j + 1) << "]" << std::endl;
                                                std::exit(0);
                                        }
                                }
                        }
                        else if (line[0] != '1' || line[14] != '1')
                        {
                                std::cerr << "Error: Invalid border [" << file << ":" << (j + 1) << "]" << std::endl;
                                std::exit(0);
                        }
                        for (size_t i = 0; i < 15; i++)
                        {
                                _map[j][i] = line[i] - '0';
                        }
                        j++;
                }
                afile.close();
                if (j != 15)
                {
                        std::cerr << "Error: Invalid size map [" << file << ":" << (j + 1) << "]" << std::endl;
                        std::exit(0);
                }
        }
        _device->getCursorControl()->setVisible(false);

        for (size_t x = 0; x < 15; x++)
        {
                for (size_t y = 0; y < 15; y++)
                {
                        _ground.push_back(_sceneManager->addCubeSceneNode(10.0f, 0, -1, core::vector3df((x * 10.0f), -80.0f, (y * 10.0f))));
                        _ground.back()->setMaterialTexture(0, _driver->getTexture("media/texture.bmp"));
                        _ground.back()->setMaterialFlag(video::EMF_LIGHTING, false);
                        if (x == 0 || x == 14 || y == 0 || y == 14)
                        {
                                _wall.push_back(_sceneManager->addCubeSceneNode(10.0f, 0, -1, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f))));
                                _wall.back()->setMaterialFlag(video::EMF_LIGHTING, false);
                                _wall.back()->setMaterialTexture(0, _driver->getTexture("media/texture.bmp"));
                        }
                        else if (_map[x][y] == 1)
                        {
                                _wall.push_back(_sceneManager->addCubeSceneNode(10.0f, 0, -1, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f))));
                                _ground.back()->setMaterialTexture(0, _driver->getTexture("media/texture.bmp"));
                                _wall.back()->setMaterialFlag(video::EMF_LIGHTING, true);
                        }
                        else if (_map[x][y] == 2)
                        {
                                _wall.push_back(_sceneManager->addCubeSceneNode(10.0f, 0, -1, core::vector3df((x * 10.0f), -70.0f, (y * 10.0f))));
                                _ground.back()->setMaterialTexture(0, _driver->getTexture("media/destructible.bmp"));
                                _wall.back()->setMaterialFlag(video::EMF_LIGHTING, false);
                        }
                }
        }
        _player.push_back(_sceneManager->addMeshSceneNode(_sceneManager->getMesh("media/Bomberman/Bomberman/Bomberman.obj")));
        _player.back()->setPosition(core::vector3df(10.0f, -70.0f, 130.0f));
        _player.back()->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
        _player.back()->setScale(core::vector3df(4.0f, 4.0f, 4.0f));
        _player.back()->setMaterialFlag(video::EMF_LIGHTING, false);
        _sceneManager->addCameraSceneNode(0, core::vector3df(80.0f, 40.0f, 0.0f), core::vector3df(80.0f, -80.0f, 60.0f), 0, true);
        _speed = 1.0f * _PLAYER_SPEED;
        _lfps = -1;
}

Game::~Game()
{
        _device->drop ();
}

Game::Game(const Game &obj)
{

}

Game &Game::operator=(const Game &obj)
{

}

void Game::move(core::vector3df *nodePosition, const f32 frameDeltaTime)
{
        if (_receiver.IsKeyDown(KEY_KEY_Z) && nodePosition->Z < 129.0f)
        {
                if (_map[(int)std::round((130 - std::round(nodePosition->Z + _speed * frameDeltaTime)) / 10 + 1 )][(int)std::round(nodePosition->X / 10)] == 0)
                {
                        nodePosition->Z += _speed * frameDeltaTime;
                        _player.back()->setRotation(core::vector3df(0.0f, 0.0f, 0.0f));
                }
        }
        else if (_receiver.IsKeyDown(KEY_KEY_S) && nodePosition->Z > 10.0f)
        {
                if (_map[(int)std::round((130 - std::round(nodePosition->Z - _speed * frameDeltaTime)) / 10 + 1 )][(int)std::round(nodePosition->X / 10)] == 0)
                {
                        nodePosition->Z -= _speed * frameDeltaTime;
                        _player.back()->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
                }

        }
        else if (_receiver.IsKeyDown(KEY_KEY_Q) && nodePosition->X > 10.0f)
        {
                if (_map[(int)std::round((130 - nodePosition->Z) / 10 + 1 )][(int)std::round(std::round(nodePosition->X - _speed * frameDeltaTime) / 10)] == 0)
                {
                        nodePosition->X -= _speed * frameDeltaTime;
                        _player.back()->setRotation(core::vector3df(0.0f, -90.0f, 0.0f));
                }
        }
        else if (_receiver.IsKeyDown(KEY_KEY_D) && nodePosition->X < 129.0f)
        {
                if (_map[(int)std::round((130 - nodePosition->Z) / 10 + 1 )][(int)std::round(std::round(nodePosition->X + _speed * frameDeltaTime) / 10)] == 0)
                {
                        nodePosition->X += _speed * frameDeltaTime;
                        _player.back()->setRotation(core::vector3df(0.0f, 90.0f, 0.0f));
                }
        }
}

void Game::dispFPS()
{
        _fps = _driver->getFPS();
        if (_fps != _lfps)
        {
                core::stringw tmp(L"IndieStudio - Bomberman [");
                tmp += _driver->getName();
                tmp += L"] fps: ";
                tmp += _lfps;
                _device->setWindowCaption(tmp.c_str());
                _lfps = _fps;
        }
}

void Game::launch()
{
        u32 then = _device->getTimer()->getTime();
        while(_device->run())
        {
                if (_receiver.IsKeyDown(KEY_ESCAPE))
                {
                        std::cout << "escape event" << std::endl;
                        break;
                }
                const u32 now = _device->getTimer()->getTime();
                const f32 frameDeltaTime = (f32)(now - then) / 1000.0f;
                then = now;

                core::vector3df nodePosition = _player.back()->getPosition();
                move(&nodePosition, frameDeltaTime);

                core::vector3df bombPosition = _player.back()->getPosition();
                if (_receiver.IsKeyDown(KEY_SPACE))
                {
                        int x, z;
                        x = (bombPosition.X / 10);
                        z = (bombPosition.Z / 10);
                        x *= 10;
                        z *= 10;
                        _bombe.push_back(_sceneManager->addMeshSceneNode(_sceneManager->getMesh("media/Bombs/MegaBomb/MegaBomb.obj")));
                        _bombe.back()->setPosition(core::vector3df(x, (int)std::round(bombPosition.Y), z));
                        _bombe.back()->setMaterialFlag(video::EMF_LIGHTING, false);
                }
                _player.back()->setPosition(nodePosition);

                _driver->beginScene(true, true, video::SColor(255, 113, 113, 133));
                _sceneManager->drawAll();
                _device->getGUIEnvironment()->drawAll();

                _driver->endScene();
                dispFPS();
        }
}
int	main(void)
{
        Game game;
        game.launch();
        return (0);
}