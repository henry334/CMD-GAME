/*
** PROJECT, 2024
** Assignement2
** File description:
** ACharacter
*/

#include "ACharacter.hpp"
#include "AItems.hpp"

void ACharacter::displayCharacterInfo() const
{
    std::cout << "Name: " << this->name;
    std::cout << "  Health: " << this->health;
    std::cout << "  Defense: " << this->defense;
    std::cout << "  Strength: " << this->strength;
    std::cout << "  Ulti Damage: " << this->ultiDamage;
    std::cout << "  Ulti Cost: " << this->ultiCost;
    std::cout << "  Mana: " << this->manaBar << "/" << this->maxManaBar << std::endl;
}

void ACharacter::setDefense(float defense)
{
    this->defense = defense;
}

void ACharacter::setHealth(float health)
{
    this->health = health;
}

void ACharacter::setStrength(float strength)
{
    this->strength = strength;
}

void ACharacter::setManaBar(float manaBar)
{
    if (manaBar > this->maxManaBar)
        this->manaBar = this->maxManaBar;
    else
        this->manaBar = manaBar;
}

void ACharacter::attack(ACharacter &target, bool isUlti)
{
    std::size_t damage = this->strength;
    if (isUlti) {
        damage = this->ultiDamage;
        this->manaBar -= this->ultiCost;
        std::cout << this->name << " uses ulti attack against " << target.getName() << "!" << std::endl;
    }
    bool isEnemyDead = target.defend(damage, this->name);
    if (isEnemyDead)
        this->setManaBar(this->manaBar + (target.getUltiDamage() * 0.95));
}

bool ACharacter::defend(float strength, const std::string &attackerName)
{
    int damage = strength - this->defense;
    if (damage < 0)
        damage = 0;
    this->health -= damage;
    if (this->health <= 0) {
        this->isDead = true;
        std::cout << this->name << " has been defeated by " << attackerName << "!" << std::endl;
        return true;
    } else
        std::cout << this->name << " takes " << damage << " damage from " << attackerName << ", remaining health: " << this->health << std::endl;
    return false;
}

void ACharacter::useItem(AItems &item)
{
    item.use(*this);
}