/*
** PROJECT, 2024
** Assignement2
** File description:
** Goblin
*/

#pragma once

#include "ACharacter.hpp"

class Goblin : virtual public ACharacter {
    public:
        Goblin();
        ~Goblin() = default;
        void display() const override;
};
