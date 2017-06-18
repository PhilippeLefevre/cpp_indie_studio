#==================================
#======INCLUSION D'IRRLICHT========
#==================================
#inclure le repertoire contenant les entetes de irrlicht
include_directories(${IRRLICHT_PATH_INCLUDE})
#inlude les bibliothèque compiles
link_directories(${IRRLICHT_PATH_LIB})

set(SRC_FILES
        ./Map/MapLoader.cpp
        ./Score.cpp
        ./MainMenu.cpp
        ./Main.cpp
        ./Game/Game.cpp
        ./Entity/Powerup/Bombup.cpp
        ./Entity/Block/DestructibleBlock.cpp
        ./Entity/Block/IndestructibleBlock.cpp
        ./Entity/Character/PlayerCharacter.cpp
        ./Entity/Character/NonPlayerCharacter.cpp
        ./Entity/Bomb/Normal.cpp
        ./Options.cpp
)

include_directories(.
        "/usr/include/irrlicht"
        "/usr/X11R6/include"
        Game
        Entity
        Entity/Block
        Entity/Character
        Entity/Bomb
        Entity/Powerup
        Map
)

add_executable(IndieStudio
        ${SRC_FILES}
)

target_link_libraries(
        IndieStudio
        Irrlicht
        GL
        Xxf86vm
        Xext
        X11
        Xcursor
)
