/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Potion
*/

#include "Potion.hpp"
#include "Dungeon.hpp"

Potion::Potion(const std::string &name, float healthGen, float defenseGen, float stengthGen, float ultiDamage, float ultiCost, float manaBar, float maxManaBar)
{
    this->name = name;
    this->healthGen = healthGen;
    this->defenseGen = defenseGen;
    this->stengthGen = stengthGen;
    this->ultiDamage = ultiDamage;
    this->ultiCost = ultiCost;
    this->manaBar = manaBar;
    this->maxManaBar = maxManaBar;
}

void Potion::use(ACharacter &character, Dungeon *dungeon)
{
    character.setHealth(character.getHealth() + this->healthGen);
    character.setDefense(character.getDefense() + this->defenseGen);
    character.setStrength(character.getStrength() + this->stengthGen);
    character.setUltiDamage(character.getUltiDamage() + this->ultiDamage);
    character.setUltiCost(character.getUltiCost() + this->ultiCost);
    character.setManaBar(character.getManaBar() + this->manaBar);
    character.setMaxManaBar(character.getMaxManaBar() + this->maxManaBar);
    std::cout << "You used a " << this->name << std::endl;
}

void Potion::displayDescription() const
{
    std::cout << this->name << " is a potion that gives ";
    if (this->healthGen != 0)
        std::cout << this->healthGen << " health points ";
    if (this->defenseGen != 0)
        std::cout << this->defenseGen << " defense points ";
    if (this->stengthGen != 0)
        std::cout << this->stengthGen << " strength points ";
    if (this->ultiDamage != 0)
        std::cout << this->ultiDamage << " ulti damage points ";
    if (this->ultiCost != 0)
        std::cout << this->ultiCost << " ulti cost points ";
    if (this->manaBar != 0)
        std::cout << this->manaBar << " mana points ";
    if (this->maxManaBar != 0)
        std::cout << this->maxManaBar << " max mana points ";
    std::cout << std::endl;
}
