//
// MapLoader.hpp for IndieStudio in /home/atraxys/Workspace/Epitech/Year_2/cpp_indie_studio/src/Map/
//
// Made by Philippe Lefevre
// Login   <philippe1.lefevre@epitech.eu>
//
// Started on  Sun Jun 18 16:05:30 2017 Philippe Lefevre
// Last update Sun Jun 18 21:23:00 2017 Philippe Lefevre
//

#ifndef MAPLOADER_HPP_
# define MAPLOADER_HPP_

# include "Game.hpp"

class MapLoader {
private:
        std::vector<indie::EntityType> _map;
public:
        MapLoader ();
        virtual ~MapLoader ();
        MapLoader(const MapLoader &obj);
        MapLoader &operator=(const MapLoader &obj);
        void init(core::stringc, s32, s32);
        std::vector<indie::EntityType> const&getMap(void);
};

#endif /* !MAPLOADER_HPP_ */
