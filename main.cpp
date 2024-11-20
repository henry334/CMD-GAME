/*
** PROJECT, 2024
** Assignement2
** File description:
** main
*/

#include "Knight.hpp"
#include "Dungeon.hpp"
#include "Map.hpp"

int main() {
    srand(time(0));
    Knight player("Your Hero");
    Dungeon dungeon(player);
    dungeon.startDungeon();

    return 0;
}
