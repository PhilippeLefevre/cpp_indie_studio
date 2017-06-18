set(SRC_FILES
        Main.cpp
        MainMenu.cpp
        Options.cpp
        Score.cpp
        Game/Game.cpp
        Entity/Block/IndestructibleBlock.cpp
        Entity/Block/DestructibleBlock.cpp
        Entity/Bomb/Normal.cpp
        Entity/Character/NonPlayerCharacter.cpp
        Entity/Character/PlayerCharacter.cpp
        Entity/Powerup/Bombup.cpp
)

include_directories(.
        "/usr/include/irrlicht"
        Game
        Entity
        Entity/Block
        Entity/Character
        Entity/Bomb
        Entity/Powerup
)

#link_directories(../
#lib/
#)

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

set(GAME_FILES
        main_test.cpp
        Game/Game.cpp
        Entity/Block/DestructibleBlock.cpp
        Entity/Block/IndestructibleBlock.cpp
        Entity/Character/PlayerCharacter.cpp
        Entity/Character/NonPlayerCharacter.cpp
        Entity/Bomb/Normal.cpp
        Entity/Powerup/Bombup.cpp
)

add_executable(game
        ${GAME_FILES}
)

target_link_libraries(
        game
        Irrlicht
        GL
        Xxf86vm
        Xext
        X11
        Xcursor
)
