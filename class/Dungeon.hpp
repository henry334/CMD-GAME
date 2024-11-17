/*
** PROJECT, 2024
** Assignement2
** File description:
** Dungeon
*/

#pragma once
#include "ACharacter.hpp"
#include "GameMap.hpp"
#include "InputManager.hpp"
#include "My.h"

class Dungeon {
    public:
        Dungeon(ACharacter &player);
        ~Dungeon() = default;
        void startDungeon();
        void display() const;
        void checkFight(std::shared_ptr<Room> &room);
        void displayBattleMode(const ACharacter &player, const ACharacter& enemy) const;
        bool battelMode(ACharacter &enemy);
        void coreGameLoop();
        void handleExit(std::shared_ptr<Room> &room);
        void handleChestOpening(std::shared_ptr<Room> &room, const std::string &action);
        void handleRoomChange(std::shared_ptr<Room> &room, const std::string &action);
        void actionHandler(std::shared_ptr<Room> &room, const std::string &action);
        void displayGameInfo(std::shared_ptr<Room> &room) const;
    private:
        bool haveExit = false;
        ACharacter &player;
        GameMap map;
        InputManager inputManager;
};
