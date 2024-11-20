/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** AItems
*/

#pragma once
#include <iostream>
#include "ACharacter.hpp"

class Dungeon;

class AItems {
    public:
        AItems() = default;
        virtual ~AItems() = default;
        virtual void take() const;
        void drop() const;
        std::string getName() const {return this->name;};
        virtual void display() const = 0;
        virtual void displayDescription() const = 0;
        virtual void use(ACharacter &character, Dungeon *dungeon = nullptr) = 0;
    protected:
        std::string name;
};
