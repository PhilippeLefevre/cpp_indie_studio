#set(SRC_FILES
#        Main.cpp
#        MainMenu.cpp
#        Options.cpp
#)

set(SRC_FILES
        MainMenu.cpp
        Main.cpp
        Game/Game.cpp
        Entity/Block/DestructibleBlock.cpp
        Entity/Block/IndestructibleBlock.cpp
        Entity/Character/PlayerCharacter.cpp
        Entity/Character/NonPlayerCharacter.cpp
        Entity/Bomb/Normal.cpp
        Options.cpp
	Score.cpp
)

include_directories(.
        ../inc
        Game
        Entity
        Entity/Block
        Entity/Character
        Entity/Bomb
)

link_directories(../
lib/
)

add_executable(IndieStudio
        ${SRC_FILES}
)

target_link_libraries(
        IndieStudio
        Irrlicht
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
