/*
** PROJECT, 2024
** Assignement2
** File description:
** knight
*/

#include "Troll.hpp"

Troll::Troll()
{
    this->health = 100;
    this->strength = 10;
    this->defense = 10;
    this->ultiDamage = 25;
    this->ultiCost = 50;
    this->manaBar = 100;
    this->maxManaBar = 100;
    this->name = "Troll";
}

Troll::~Troll()
{
}

void Troll::display() const
{
    std::cout << "         ,      ,\n";
    std::cout << "       /(.-\"\"-.)\\\n";
    std::cout << "   |\\  \\/      \\/  /|\n";
    std::cout << "   | \\ / =.  .= \\ / |\n";
    std::cout << "    \\( \\   o\\/o   / )/\n";
    std::cout << "     \\_, '-/  \\-' ,_/\n";
    std::cout << "       /   \\__/   \\\n";
    std::cout << "       \\ \\__/\\__/ /\n";
    std::cout << "     ___\\ \\|--|/ /___\n";
    std::cout << " /`    `\\      /`    `\\\n";
    std::cout << "|       |      |       |\n";
    std::cout << "|       |      |       |\n";
}