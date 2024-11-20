/*
** PROJECT, 2024
** Assignement2
** File description:
** Map
*/

#pragma once

#include "AItems.hpp"

class Map : public AItems {
    public:
        Map();
        ~Map() = default;
        void display() const override;
        void displayDescription() const override;
        void use(ACharacter &character, Dungeon *dungeon = nullptr) override;
};
