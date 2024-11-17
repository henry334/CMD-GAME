/*
** PROJECT, 2024
** Assignement2
** File description:
** Room
*/

#pragma once
#include "random"
#include "My.h"
#include "ACharacter.hpp"
#include "Dragon.hpp"
#include "Troll.hpp"
#include "Goblin.hpp"
#include "Chest.hpp"

class Room {
    public:
        Room(const std::string &name, bool isTheEnd);
        ~Room() = default;
        const std::string &getName() const { return this->name; }
        void setIsTheEnd(bool isTheEnd) { this->isTheEnd = isTheEnd; }
        bool getIsTheEnd() const { return this->isTheEnd; }
        void addLinkedRoom(std::shared_ptr<Room> &linkedRoom);
        void displayConnectedRooms() const;
        void displayChests() const;
        void generateChests();
        void generateEnemies();
        void DisplayRoom() const;
        std::unique_ptr<ACharacter>& getLastEnemy() { return this->enemies.back(); };
        void removeLastEnemy() { this->enemies.pop_back(); };
        std::vector<std::unique_ptr<Chest>> &getChests() { return this->chests; };
        std::vector<std::unique_ptr<ACharacter>> &getEnemies() { return this->enemies; };
        std::vector<std::shared_ptr<Room>> &getLinkedRooms() { return this->linkedRooms; };
        void setPos(std::size_t x, std::size_t y) { this->x = x; this->y = y; };
        std::vector<std::size_t> getPos() const { return {this->x, this->y}; };
        void generateDisplayMap();
    private:
        std::size_t x;
        std::size_t y;
        std::string name;
        bool isTheEnd;
        std::vector<std::unique_ptr<Chest>> chests = {};
        std::vector<std::unique_ptr<ACharacter>> enemies = {};
        std::vector<std::shared_ptr<Room>> linkedRooms = {};
        std::vector<std::vector<char>> displayMap = {};
        const std::vector<std::function<std::unique_ptr<ACharacter>()>> enemys = {
            []() {return std::make_unique<Troll>();},
            []() {return std::make_unique<Dragon>();},
            []() {return std::make_unique<Goblin>();}
        };
};
