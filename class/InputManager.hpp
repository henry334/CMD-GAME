/*
** PROJECT, 2024
** Assignement2
** File description:
** InputManager
*/

#pragma once
#include "My.h"

class InputManager {
    public:
        InputManager() = default;
        ~InputManager() = default;
        void toLowerCase(std::string &str) const;
        std::string getUserInput(const std::string &prompt, const std::vector<std::string> &choices = {}) const;
};
