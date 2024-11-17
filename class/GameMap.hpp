/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Map
*/

#pragma once

#include "Room.hpp"
#include "My.h"

class GameMap {
    public:
        GameMap();
        ~GameMap() = default;
        std::vector<std::vector<std::shared_ptr<Room>>> &getMap();
        std::shared_ptr<Room> &getRoom(std::size_t x, std::size_t y) {return this->map[x][y];};
        void enterRoom(std::size_t x, std::size_t y, ACharacter &player);
    private:
        void generateMap();
        void connectRoomsDfs();
        std::vector<std::vector<std::shared_ptr<Room>>> map = {};
};
