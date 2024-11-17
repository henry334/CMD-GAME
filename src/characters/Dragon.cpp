/*
** PROJECT, 2024
** Assignement2
** File description:
** knight
*/

#include "Dragon.hpp"

Dragon::Dragon()
{
    this->health = 100;
    this->strength = 20;
    this->defense = 5;
    this->ultiDamage = 45;
    this->ultiCost = 80;
    this->manaBar = 100;
    this->maxManaBar = 100;
    this->name = "Dragon";
}

Dragon::~Dragon()
{
}

void Dragon::display() const
{
    std::cout << R"(
                __====-_  _-====__
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / `' \  //#################-
  -###################\\/  |   |\\/###################-
  )" << std::endl;
}