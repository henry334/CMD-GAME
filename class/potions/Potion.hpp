/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Potion
*/

#pragma once

#include "AItems.hpp"

class Potion : virtual public AItems {
    public:
        Potion(const std::string &name, float healthGen = 0, float defenseGen = 0, float stengthGen = 0, float ultiDamage = 0, float ultiCost = 0, float manaBar = 0, float maxManaBar = 0);
        ~Potion() = default;
        void use(ACharacter &character) override;
        void displayDescription() const override;
        void display() const = 0;
    protected:
        float healthGen;
        float defenseGen;
        float stengthGen;
        float ultiDamage;
        float ultiCost;
        float manaBar;
        float maxManaBar;
};
