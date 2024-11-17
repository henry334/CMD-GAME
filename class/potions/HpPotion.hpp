/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** potions
*/

#pragma once

#include "Potion.hpp"

class HpPotion : public Potion {
    public:
        HpPotion() : Potion("Heal Potion", 35) {};
        ~HpPotion() = default;
        void display() const override;
};