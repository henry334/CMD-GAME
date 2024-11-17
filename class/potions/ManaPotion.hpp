/*
** PROJECT, 2024
** Assignement2
** File description:
** ManaPotion
*/

#pragma once

#include "Potion.hpp"

class ManaPotion : public Potion {
    public:
        ManaPotion() : Potion("Mana Potion", 0, -6, -4, 0, 0, 38, 18) {};
        ~ManaPotion() = default;
        void display() const override;
};
