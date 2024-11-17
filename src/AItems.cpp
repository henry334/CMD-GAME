/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** AItems
*/

#include "AItems.hpp"

void AItems::drop() const
{
    std::cout << "You dropped " << this->name << std::endl;
}

void AItems::take() const
{
    std::cout << "You took " << this->name << std::endl;
}
