/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** StrenghtPotion
*/

#pragma once

#include "Potion.hpp"

class StrengthPotion : public Potion {
    public:
        StrengthPotion(): Potion("Strenght Potion", -1, 0, 6, 0, 0, 0, 0) {};
        ~StrengthPotion() = default;
        void display() const override;
};
