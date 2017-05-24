set(SRC_FILES
        Main.cpp
        MainMenu.cpp
        Options.cpp
)

add_executable(IndieStudio
        ${SRC_FILES}
)

target_link_libraries(
        IndieStudio
        Irrlicht
)
