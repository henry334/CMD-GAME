/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Weapon
*/

#pragma once
#include "AItems.hpp"

class Weapon : virtual public AItems {
    public:
        Weapon(std::size_t damage, const std::string& name);
        ~Weapon() = default;
        void use(ACharacter &character) override;
        void displayDescription() const override;
        void display() const = 0;
    protected:
        std::size_t damage;
};
