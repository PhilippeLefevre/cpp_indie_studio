#  _____           _ _          _                  _ _
# (_____)         | (_)        | |   _            | (_)
#    _   ____   _ | |_  ____    \ \ | |_ _   _  _ | |_  ___
#   | | |  _ \ / || | |/ _  )    \ \|  _) | | |/ || | |/ _ \
#  _| |_| | | ( (_| | ( (/ / _____) ) |_| |_| ( (_| | | |_| |
# (_____)_| |_|\____|_|\____|______/ \___)____|\____|_|\___/
#
# « Les Indécis »
# Quentin ROUCHET - Alban VEGLEUR - Etienne ESCLAPEZ - PHILIPPE LEFEVRE - Tanguy LELIEVRE - Vladislav ZOBOV

# We require CMake >= 3.0
cmake_minimum_required(VERSION 3.0)

# Set projectname (must be done AFTER setting configurationtypes)
project(IndieStudio)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../ )

include_directories(inc)

# add dependencies
add_subdirectory(dep)

# add core sources
add_subdirectory(src)
