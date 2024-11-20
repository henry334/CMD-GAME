#include "InputManager.hpp"

void InputManager::toLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

std::string InputManager::getUserInput(const std::string &prompt, const std::vector<std::string> &choices)
{
    std::string action;
    std::cout << prompt;
    if (!(std::cin >> action)) { // Handle crt+d
        std::cout << "\nExiting program." << std::endl;
        exit(0);
    }
    InputManager::toLowerCase(action);
    if (choices.size() > 0) {
        if (std::find(choices.begin(), choices.end(), action) != choices.end())
            return action;
        else {
            std::cout << "Invalid action" << std::endl;
            return getUserInput(prompt, choices);
        }
    }
    return action;
}