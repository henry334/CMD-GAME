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

// Method for attacking another character
void ACharacter::attack(ACharacter &target, bool isUlti)
{
    std::size_t damage = this->strength;
    if (isUlti) {
        damage = this->ultiDamage; // Use ultimate damage if it's an ultimate attack
        this->manaBar -= this->ultiCost; // Decrease mana after ulti use
        std::cout << "\033[32m" << this->name << " uses ulti attack against " << target.getName() << "!\033[0m" << std::endl;
    }
    // Check if the target is defeated after the attack
    bool isEnemyDead = target.defend(damage, this->name);
    if (isEnemyDead)
        this->setManaBar(this->manaBar + (target.getUltiDamage() * 0.95)); // Regain some mana on kill
}

bool ACharacter::defend(float strength, const std::string &attackerName)
{
    int damage = strength - this->defense; // Reduce damage by defense
    if (damage < 0)
        damage = 0; // Prevent negative damage
    this->health -= damage; // Deduct health by the damage
    if (this->health <= 0) {
        this->isDead = true; // Character dies if health goes below or equal to 0
        std::cout << "\033[31m" << this->name << " has been defeated by " << attackerName << "!\033[0m" << std::endl;
        return true;
    } else
        std::cout << "\033[31m" << this->name << " takes " << damage << " damage from " << attackerName << ", remaining health: " << this->health << "\033[0m" << std::endl;
    return false; // Character is still alive
}

void ACharacter::useItem(AItems &item)
{
    item.use(*this);
}