/*
** PROJECT, 2024
** Assignement2
** File description:
** Knight
*/

#pragma once
#include "ACharacter.hpp"

class Troll: virtual public ACharacter {
    public:
        Troll();
        ~Troll();
        void display() const override;
};
