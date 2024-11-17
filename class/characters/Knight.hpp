/*
** PROJECT, 2024
** Assignement2
** File description:
** Player
*/

#pragma once
#include "ACharacter.hpp"

class Knight : public virtual ACharacter {
    public:
        Knight(const std::string &name = "Knight");
        ~Knight();
        void display() const override;
};
