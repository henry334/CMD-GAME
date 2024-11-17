/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Goblin
*/

#include "Goblin.hpp"

Goblin::Goblin()
{
    this->health = 100;
    this->strength = 8;
    this->defense = 6;
    this->ultiDamage = 15;
    this->ultiCost = 30;
    this->manaBar = 100;
    this->maxManaBar = 100;
    this->name = "Goblin";
}

void Goblin::display() const
{
    std::cout << "         .:\\:/.:/\n";
    std::cout << "       .:\\:\\:/:/:.\n";
    std::cout << "     :.:\\:\\:\\:/:/:.: \n";
    std::cout << "     :=.' -   - '.=: \n";
    std::cout << "     '=(\\ 9   9 /)='\n";
    std::cout << "        (  (_)  )\n";
    std::cout << "        /`-vvv-'\\\n";
    std::cout << "       /         \\\n";
    std::cout << "      / /|,,,,,|\\ \\ \n";
    std::cout << "     /_//  /^\\  \\\\_\\\n";
    std::cout << "     WW(  (   )  )WW\n";
    std::cout << "     __\\,,\\ /,,/__\n";
    std::cout << "     (______Y______)\n";
}
