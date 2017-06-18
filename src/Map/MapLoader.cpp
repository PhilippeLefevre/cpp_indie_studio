//
// MapLoader.cpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Map/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 18 16:16:39 2017 Philippe Lefevre
// Last update Sun Jun 18 22:24:22 2017 Philippe Lefevre
//

#include <fstream>
#include "MapLoader.hpp"

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{

}

MapLoader::MapLoader(const MapLoader &obj)
{
        _map = obj._map;
}

MapLoader &MapLoader::operator=(const MapLoader &obj)
{
        MapLoader *tmp = new MapLoader(obj);
        return (*tmp);
}

void MapLoader::init(core::stringc path, s32 nb_player, s32 nb_ia)
{
        std::ifstream afile("media/maps/map.bbm", std::ios::in);
        if (afile.is_open())
        {
                std::string line;
                int i = 0;
                int pl = 3;
                int ia = 7;
                while (std::getline(afile, line))
                {
                        if (line.size() != 15)
                        {
                                std::cerr << "Error: map [" << "media/maps/map.bbm" << ":" << i << "]" << std::endl;
                                std::exit(1);
                        }
                        int j = 0;
                        for (size_t j = 0; j < 15; j++)
                        {
                                if ((line[j] - 48) >= 3)
                                {
                                        if (nb_player > 0)
                                        {
                                                _map.push_back((indie::EntityType)(pl));
                                                nb_player--;
                                                pl++;
                                        }
                                        else if (nb_ia > 0)
                                        {
                                                _map.push_back((indie::EntityType)(ia));
                                                nb_ia--;
                                                ia++;
                                        }
                                        else
                                        {
                                                _map.push_back((indie::EntityType)(2));
                                        }
                                }
                                else
                                {
                                        _map.push_back((indie::EntityType)(line[j] - 48));
                                }
                        }
                        i++;
                }
                afile.close();
        }
        else
        {
                std::cerr << "Unable to open file" << std::endl;
        }
}
std::vector<indie::EntityType> const&MapLoader::getMap(void)
{
        return (_map);
}
