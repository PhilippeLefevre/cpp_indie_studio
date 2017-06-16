set(SRC_FILES
        Main.cpp
        MainMenu.cpp
        Options.cpp
)

#set(SRC_FILES
#        MainMenu_tmp.cpp
#        MainMenu.cpp
#        Main.cpp
#        main_test.cpp
#        Game/Game.cpp
#        Entity/Block/DestructibleBlock.cpp
#        Entity/Block/IndestructibleBlock.cpp
#        Entity/Character/PlayerCharacter.cpp
#        Entity/Character/NonPlayerCharacter.cpp
#        Entity/Bomb/Normal.cpp
#        Options.cpp
#)

add_executable(IndieStudio
        ${SRC_FILES}
)

target_link_libraries(
        IndieStudio
        Irrlicht
)

include_directories(.
        Game
        Entity
        Entity/Block
        Entity/Character
        Entity/Bomb
)

set(GAME_FILES
        main_test.cpp
        Game/Game.cpp
        Entity/Block/DestructibleBlock.cpp
        Entity/Block/IndestructibleBlock.cpp
        Entity/Character/PlayerCharacter.cpp
        Entity/Character/NonPlayerCharacter.cpp
        Entity/Bomb/Normal.cpp
)

add_executable(game
        ${GAME_FILES}
)

target_link_libraries(
        game
        Irrlicht
)
