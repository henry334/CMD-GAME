/*
** PROJECT, 2024
** Assignement2
** File description:
** ACharacter
*/

#pragma once
#include "My.h"

class AItems;

class ACharacter {
    protected:
        float health;
        float strength;
        float defense;
        float ultiDamage;
        float ultiCost;
        float manaBar;
        float maxManaBar;
        std::string name;
        bool isDead = false;
        std::size_t x = FIRST_ROOM_X;
        std::size_t y = FIRST_ROOM_Y;
    public:
        virtual void display() const = 0;
        void attack(ACharacter &target, bool isUlti = false);
        bool defend(float strength, const std::string &attackerName);
        void displayCharacterInfo() const;
        void setDefense(float defense);
        void setHealth(float health);
        void setStrength(float strength);
        void setNewPosition(std::size_t x, std::size_t y) {this->x = x; this->y = y;};
        std::string getName() const {return this->name;};
        void setUltiDamage(float ultiDamage) {this->ultiDamage = ultiDamage;};
        void setUltiCost(float ultiCost) {this->ultiCost = ultiCost;};
        void setMaxManaBar(float maxManaBar) {this->maxManaBar = maxManaBar;};
        void setManaBar(float manaBar);
        float getMaxManaBar() const {return this->maxManaBar;};
        float getUltiDamage() const {return this->ultiDamage;};
        float getUltiCost() const {return this->ultiCost;};
        float getManaBar() const {return this->manaBar;};
        float getHealth() const {return this->health;};
        float getDefense() const {return this->defense;};
        float getStrength() const {return this->strength;};
        std::vector<std::size_t> getPosition() const {return {this->x, this->y};};
        bool getIsDead() const {return this->isDead;};
        void useItem(AItems &item);
        virtual ~ACharacter() {};
};
