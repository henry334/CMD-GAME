/*
** PROJECT, 2024
** Assignement2
** File description:
** Chest
*/

#include "Chest.hpp"

std::unique_ptr<AItems> Chest::open()
{
    if (this->isOpen) {
        std::cout << "The chest is already open" << std::endl;
        return nullptr;
    }
    const std::size_t randomIndex = rand() % this->items.size();
    std::unique_ptr<AItems> item = this->items[randomIndex]();
    std::cout << "You found a " << item->getName() << std::endl;
    this->isOpen = true;
    return std::move(item);
}
