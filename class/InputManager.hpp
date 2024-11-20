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
        static void toLowerCase(std::string &str);
        static std::string getUserInput(const std::string &prompt, const std::vector<std::string> &choices = {});
    private:
        InputManager() = delete;
        ~InputManager() = delete;
};
