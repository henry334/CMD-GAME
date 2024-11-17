/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name)
{
    this->health = HEALTH_START;
    this->strength = 25;
    this->defense = 5;
    this->ultiDamage = 50;
    this->ultiCost = 50;
    this->manaBar = MAX_MANA_START;
    this->maxManaBar = MAX_MANA_START;
    this->name = name;
}

Knight::~Knight()
{
}

void Knight::display() const
{
    std::cout << "  ,^.\n";
    std::cout << "  |||\n";
    std::cout << "  |||       _T_\n";
    std::cout << "  |||   .-.[:|:].-.\n";
    std::cout << "  ===_ /\\|  \"'\"'  |/\n";
    std::cout << "   E]_|\\/ \\--|-|''''|\n";
    std::cout << "   O  `'  '=[:]| A  |\n";
    std::cout << "          /\"\"\"\"|  P |\n";
    std::cout << "         /\"\"\"\"\"`.__.'\n";
    std::cout << "        []\"/\"\"\"\\\"[]\n";
    std::cout << "        | \\     / |\n";
    std::cout << "        | |     | |\n";
    std::cout << "      <\\\\\\)    (///>\n";
}
