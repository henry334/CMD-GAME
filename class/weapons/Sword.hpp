/*
** PROJECT, 2024
** Assignement2
** File description:
** Sword
*/

#pragma once

#include "Weapon.hpp"

class Sword : public Weapon {
    public:
        Sword() : Weapon(39, "Sword") {};
        ~Sword() = default;
        void display() const override;
};
