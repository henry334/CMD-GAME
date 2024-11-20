/*
** PROJECT, 2024
** Assignement2
** File description:
** DefensePotion
*/

#pragma once

#include "Potion.hpp"

class DefensePotion : public Potion {
    public:
        DefensePotion() : Potion("Defense Potion", 0, 4, -1, 0, 0, 0, 0) {};
        ~DefensePotion() = default;
        void display() const override;
};
