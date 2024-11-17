/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Room
*/

#include "Room.hpp"

Room::Room(const std::string &name, bool isTheEnd) : isTheEnd(isTheEnd)
{
    this->name = name;
    this->generateChests();
    this->generateEnemies();
    this->generateDisplayMap();
}

std::pair<std::size_t, std::size_t> getRCoord(std::size_t maxX, std::size_t maxY, bool nonZero) {
    std::random_device rd;
    std::mt19937 gen(rd());

    if (nonZero) {
        std::uniform_int_distribution<std::size_t> distX(0, maxX - 1);
        std::uniform_int_distribution<std::size_t> distY(0, maxY - 1);
        std::size_t x = distX(gen);
        std::size_t y = distY(gen);
        if (x != 0 && y != 0) (std::uniform_int_distribution<>(0, 1)(gen) == 0 ? x : y) = 0;
        return {x, y};
    } 

    std::uniform_int_distribution<std::size_t> distX(1, maxX - 1);
    std::uniform_int_distribution<std::size_t> distY(1, maxY - 1);
    return {distX(gen), distY(gen)};
}

void Room::addLinkedRoom(std::shared_ptr<Room> &linkedRoom)
{
    auto coord = getRCoord(DISPLAY_MAP_X - 1, DISPLAY_MAP_Y - 1, true);
    if (coord.first < DISPLAY_MAP_X && coord.second < DISPLAY_MAP_Y) {
        this->displayMap[coord.first][coord.second] = 'R';
    }
    this->linkedRooms.push_back(linkedRoom);
}

void Room::displayConnectedRooms() const
{
    std::cout << "Door rooms: ";
    for (auto room : this->linkedRooms) {
        std::cout << room->name << " ";
    }
    if (this->isTheEnd)
        std::cout << "Exit";
    std::cout << std::endl;
}

void Room::displayChests() const
{
    if (this->chests.size() == 0) {
        std::cout << "No chests in this room" << std::endl;
        return;
    }
    std::cout << "Chests in this room: ";
    std::size_t i = 0;
    for (auto &chest : this->chests) {
        if (i != 0)
            std::cout << " | ";
        std::cout << "Chest " << i;
        if (chest->getIsOpen())
            std::cout << " (Opened)";
        i++;
    }
    std::cout << std::endl;
}

void Room::generateChests()
{
    std::size_t chestsToGenerate = rand() % MAX_CHESTS;
    for (std::size_t i = 0; i < chestsToGenerate; i++) {
        this->chests.push_back(std::make_unique<Chest>());
    }
}

void Room::generateEnemies()
{
    std::size_t enemiesToGenerate = (rand() % MAX_ENEMIES);
    for (std::size_t i = 0; i < enemiesToGenerate; i++) {
        const std::size_t randomIndex = rand() % this->enemys.size();
        this->enemies.push_back(this->enemys[randomIndex]());
    }
}

void Room::DisplayRoom() const
{
    std::size_t x = DISPLAY_MAP_X;
    std::size_t y = DISPLAY_MAP_Y;

    for (std::size_t i = 0; i < x; i++) {
        for (std::size_t j = 0; j < y; j++)
            std::cout << this->displayMap[i][j];
        std::cout << std::endl;
    }
}

void Room::generateDisplayMap()
{
    std::size_t x = DISPLAY_MAP_X;
    std::size_t y = DISPLAY_MAP_Y;
    std:size_t numberOfDoor = this->linkedRooms.size();
    std::size_t numberOfChest = this->chests.size();
    std::vector<std::vector<char>> map(x, std::vector<char>(y, '.'));
    for (std::size_t i = 0; i < x; i++) {
        for (std::size_t j = 0; j < y; j++) {
            if ((i == 0 || i == x - 1) || (j == 0 || j == y - 1)) {
                map[i][j] = '#';
            }
        }
    }

    for (std::size_t i = 0; i < numberOfChest; i++) {
        auto coord = getRCoord(x - 1, y - 1, false);
        if (coord.first < x && coord.second < y) { 
            map[coord.first][coord.second] = 'C';
        }
    }
    this->displayMap = map;
}
