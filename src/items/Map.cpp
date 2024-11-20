/*
** PROJECT, 2024
** Assignement2
** File description:
** Map
*/

#include "Map.hpp"
#include "Dungeon.hpp"

Map::Map()
{
    this->name = "Map";
}

void Map::display() const
{
    std::cout << "  ___________________________\n";
    std::cout << " /                           \\\n";
    std::cout << "/       ____                 |\n";
    std::cout << "|      /    \\     *          |\n";
    std::cout << "|     |      |          ~    |\n";
    std::cout << "|     |      |   ~      ~    |\n";
    std::cout << "|      \\____/      *         |\n";
    std::cout << "|         \\         ~  ~     |\n";
    std::cout << "|     *    \\   ~        X    |\n";
    std::cout << "|  ~       /\\       ~        |\n";
    std::cout << "|  ~      /  \\        ~      |\n";
    std::cout << "|       *      \\             |\n";
    std::cout << " \\___________________________/\n";
}

void Map::displayDescription() const
{
    std::cout << "This map will help you to find your way out of the dungeon (One time use)" << std::endl;
}

void Map::use(ACharacter &character, Dungeon *dungeon)
{
    dungeon->getMap().displayMap();
}

