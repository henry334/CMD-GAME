/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Weapon
*/

#include "Weapon.hpp"

Weapon::Weapon(std::size_t damage, const std::string &name)
{
    this->name = name;
    this->damage = damage;
}

void Weapon::use(ACharacter &character)
{
    character.setStrength(this->damage);
    std::cout << "You used a " << this->name << std::endl;
}

void Weapon::displayDescription() const
{
    std::cout << this->name << " is a weapon that deals " << this->damage << " damage" << std::endl;
}
