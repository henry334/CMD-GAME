/*
** PROJECT, 2024
** Assignement2
** File description:
** Knight
*/

#pragma once
#include "ACharacter.hpp"

class Dragon: virtual public ACharacter {
    public:
        Dragon();
        ~Dragon();
        void display() const override;
};
