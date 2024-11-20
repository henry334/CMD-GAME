/*
** PROJECT, 2024
** Assignement2
** File description:
** Chest
*/

#pragma once
#include "AItems.hpp"
#include "ManaPotion.hpp"
#include "DefensePotion.hpp"
#include "HpPotion.hpp"
#include "Sword.hpp"
#include "StrengthPotion.hpp"
#include "Axe.hpp"
#include "Map.hpp"
#include "My.h"

class Chest {
    public:
        Chest() = default;
        ~Chest() = default;
        std::unique_ptr<AItems> open();
        bool getIsOpen() const {return this->isOpen;};
    private:
        bool isOpen = false;
        const std::vector<std::function<std::unique_ptr<AItems>()>> items = {
            []() {return std::make_unique<HpPotion>();},
            []() {return std::make_unique<Axe>();},
            []() {return std::make_unique<ManaPotion>();},
            []() {return std::make_unique<DefensePotion>();},
            []() {return std::make_unique<StrengthPotion>();},
            []() {return std::make_unique<Sword>();},
            []() {return std::make_unique<Map>();}
        };
};
