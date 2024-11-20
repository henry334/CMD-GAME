/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Map
*/

#include "GameMap.hpp"

GameMap::GameMap()
{
    this->generateMap();
    this->connectRoomsDfs();
}

void GameMap::generateMap()
{
    std::size_t x = rand() % MAP_SIZE + 2;
    std::size_t y = rand() % MAP_SIZE + 2;

    for (std::size_t i = 0; i < x; i++) {
        std::vector<std::shared_ptr<Room>> row;
        for (std::size_t j = 0; j < y; j++) {
            std::shared_ptr<Room> room = std::make_shared<Room>("Room " + std::to_string(i) + std::to_string(j), false);
            room->setPos(i, j);
            row.push_back(room);
        }
        this->map.push_back(row);
    }

    std::size_t endRoomX = (std::rand() % (x - 1)) + 1;
    std::size_t endRoomY = (std::rand() % (y - 1)) + 1;
    this->map[endRoomX][endRoomY]->setIsTheEnd(true);
}

void GameMap::connectRoomsDfs()
{
    std::size_t xStart = FIRST_ROOM_X;
    std::size_t yStart = FIRST_ROOM_Y;

    std:size_t x = xStart;
    std::size_t y = yStart;

    std::size_t xMapSize = this->map.size();
    std::size_t yMapSize = this->map[0].size();

    std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::map<std::pair<std::size_t, std::size_t>, bool> visited = {{std::make_pair(xStart, yStart), true}};

    std::vector<std::pair<int, int>> path = {{xStart, yStart}};
    std::vector<std::pair<int, int>> directionsToTry = directions;

    while (path.size() > 0) {
        if (directionsToTry.size() == 0) {
            x = path.back().first;
            y = path.back().second;
            path.pop_back();
            directionsToTry = directions;
            continue;
        }
        std::size_t randomIndex = rand() % directionsToTry.size();
        std::pair<int, int> direction = directionsToTry[randomIndex];

        if ((x + direction.first < 0 || x + direction.first >= xMapSize) 
            || (y + direction.second < 0 || y + direction.second >= yMapSize)
            || visited[std::make_pair(x + direction.first, y + direction.second)]
            ) {
            directionsToTry.erase(directionsToTry.begin() + randomIndex);
            continue;
        }

        std::size_t xOld = x;
        std::size_t yOld = y;
        
        x += direction.first;
        y += direction.second;
        visited[std::make_pair(x, y)] = true;
        path.push_back(std::make_pair(x, y));
        this->map[xOld][yOld]->addLinkedRoom(this->map[x][y]);
        this->map[x][y]->addLinkedRoom(this->map[xOld][yOld]);

        directionsToTry = directions;
    }
}


std::vector<std::vector<std::shared_ptr<Room>>> &GameMap::getMap()
{
    return this->map;
}

void GameMap::enterRoom(std::size_t x, std::size_t y, ACharacter &player)
{
    if ((x >= this->map.size() || y >= this->map[0].size()) || (x < 0 || y < 0)) {
        std::cout << "Invalid room" << std::endl;
        return;
    }

    std::shared_ptr<Room> room = this->map[x][y];
    std::cout << "You entered the room: " << room->getName() << std::endl;
    player.setNewPosition(x, y);
}

void GameMap::displayMap() const
{
    std::shared_ptr<Room> starterRoom = this->map[FIRST_ROOM_X][FIRST_ROOM_Y];
    std::vector<std::string> visited;
    std::cout << "Game Map:" << std::endl;
    this->displayLinkedRooms(starterRoom, visited, "", true, 0);
    InputManager::getUserInput("Continue press any key: ");
}

void GameMap::displayLinkedRooms(std::shared_ptr<Room> room, std::vector<std::string>& visited, const std::string& prefix = "", bool recursive, int level) const
{
    // Mark the current room as visited
    visited.push_back(room->getName());

    // Display the current room with prefix
    std::cout << prefix << (level > 0 ? "|-- " : "") << room->getName();
    if (room->getIsTheEnd())
        std::cout << " (End)";
    std::cout << std::endl;

    const std::vector<std::shared_ptr<Room>>& linkedRooms = room->getLinkedRooms();
    size_t numLinkedRooms = linkedRooms.size();
    size_t count = 0;

    for (std::shared_ptr<Room> linkedRoom : linkedRooms) {
        std::string roomName = linkedRoom->getName();

        // Skip already visited rooms
        if (std::find(visited.begin(), visited.end(), roomName) != visited.end())
            continue;

        // Increment the count of processed linked rooms
        count++;

        // Create the prefix for the next level
        std::string nextPrefix = prefix + (level > 0 ? "|   " : "    ");
        if (count == numLinkedRooms) {
            nextPrefix = prefix + (level > 0 ? "    " : "    "); // No continuation for the last room
        }

        // Recursively display linked rooms
        if (recursive) {
            this->displayLinkedRooms(linkedRoom, visited, nextPrefix, true, level + 1);
        }
    }
}
