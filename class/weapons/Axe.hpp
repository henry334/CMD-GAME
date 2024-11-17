/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Axe
*/

#pragma once
#include "Weapon.hpp"

class Axe : public Weapon {
    public:
        Axe(): Weapon(30, "Axe") {};
        ~Axe() = default;
        void display() const override;
};
