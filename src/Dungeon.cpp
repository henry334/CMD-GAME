/*
** EPITECH PROJECT, 2024
** Assignement2
** File description:
** Dungeon
*/

#include "Dungeon.hpp"

Dungeon::Dungeon(ACharacter &player) : player(player)
{
}

void Dungeon::startDungeon() {
    this->display();
    this->player.displayCharacterInfo();
    InputManager::getUserInput("Press any key to start the game: ");
    this->map.enterRoom(FIRST_ROOM_X, FIRST_ROOM_Y, this->player);
    this->coreGameLoop();
}

void Dungeon::display() const {
    std::cout << "\t You are entering the dungeon! You must find the EXIT" << std::endl;
    std::cout << "                                   ]=I==II==I=[\n";
    std::cout << "                                    \\\\__||__//                 ]=I==II==I=[\n";
    std::cout << "               ]=I==II==I=[          |.. ` *|                   \\\\__||__//\n";
    std::cout << "                \\\\__||__//           |. /\\ #|                    |-_ []#|\n";
    std::cout << "                 | []   |            |  ## *|                    |      |\n";
    std::cout << "                 |    ..|            | . , #|                  ]=I==II==I=[\n";
    std::cout << "  ___   ____  ___|   .. |         __ |..__.*| __                \\\\__||__//\n";
    std::cout << " ] I---I  I--I [ |..    |        |  ||_|  |_|| |                 |    _*|\n";
    std::cout << " ]_____________[ | .. []|         \\--\\|-|--/-//                  |   _ #|\n";
    std::cout << "  \\_\\| |_| |/_/  |_   _ | _   _   _|      ' *|                   |`    *|\n";
    std::cout << "   |  .     |'-'-` '-` '-` '-` '-` | []     #|-|--|-_-_-_-_ _ _ _|_'   #|\n";
    std::cout << "   |     '  |=-=-=-=-=-=-=-=-=-=-=-|      []*|-----________` ` `   ]   *|\n";
    std::cout << "   |  ` ` []|      _-_-_-_-_  '    |-       #|      ,    ' ```````['  _#|\n";
    std::cout << "   | '  `  '|   [] | | | | |  []`  |  []    *|   `          . `   |'  I*|\n";
    std::cout << "   |      - |    ` | | | | | `     | ;  '   #|     .  |        '  |    #|\n";
    std::cout << "  /_'_-_-___-\\__,__|_|_|_|_|_______|   `  , *|    _______+___,__,-/._.._.\\\n";
    std::cout << "              _,--'    __,-'      /,_,_v_Y_,_v\\\\-'\n";
}

void Dungeon::checkFight(std::shared_ptr<Room> &room)
{

    while (room->getEnemies().size() > 0) {
        std::unique_ptr<ACharacter> &enemy = room->getLastEnemy();
        if (this->battelMode(*enemy))
            break;
        room->removeLastEnemy();
    }
}

void Dungeon::displayBattleMode(const ACharacter &player, const ACharacter &enemy) const
{
    std::cout << "--------------------FIGHT!--------------------" << std::endl;
    enemy.displayCharacterInfo();
    enemy.display();
    std::cout << "---------------------VS--------------------" << std::endl;
    player.displayCharacterInfo();
    player.display();
}

bool Dungeon::battelMode(ACharacter &enemy)
{
    while (!this->player.getIsDead() && !enemy.getIsDead()) {
        this->displayBattleMode(this->player, enemy);
        std::string action = InputManager::getUserInput("Choose your action: (1) Attack | (2) Ultimate: ", {"1", "2"});
        std::system("clear");
        if (action == "1") {
            this->player.attack(enemy);
        } else if (action == "2" && this->player.getManaBar() >= this->player.getUltiCost()) {
            this->player.attack(enemy, true);
        } else {
            std::cout << "Invalid action" << std::endl;
            continue;
        }
        if (enemy.getHealth() > 0) {
            bool ulti = 0 == rand() % ENEMY_ULTI_CHANCE ? true : false;
            enemy.attack(this->player, ulti);
        }
    }
    std::system("clear");
    if (this->player.getIsDead()) {
        std::cout << "You have been defeated by " << enemy.getName() << "!" << std::endl;
        return true;
    }
    return false;
}

void Dungeon::coreGameLoop()
{
    while (!this->player.getIsDead() && !this->haveExit) {
        std::system("clear");
        std::shared_ptr<Room> &room = this->map.getRoom(this->player.getPosition()[0], this->player.getPosition()[1]);
        this->checkFight(room);
        if (this->player.getIsDead()) break;
        this->displayGameInfo(room);
        std::string actionStr = "Choose your action: ";
        if (room->getLinkedRooms().size() > 0)
            actionStr += "(R[x]) Move ";
        if (room->getChests().size() > 0)
            actionStr += "(C[x]) Open Chest ";
        if (room->getIsTheEnd())
            actionStr += "(E) Exit ";
        actionStr += ": ";
        std::string action = InputManager::getUserInput(actionStr);
        this->actionHandler(room, action);
    }
}

void Dungeon::handleExit(std::shared_ptr<Room> &room)
{
    if (room->getIsTheEnd()) {
        std::cout << "You have found the exit! Congratulations!" << std::endl;
        this->haveExit = true;
    } else {
        std::cout << "No exit in this room" << std::endl;
    }
}

void Dungeon::handleChestOpening(std::shared_ptr<Room> &room, const std::string &action)
{
    std::string modifiedAction = action;
    modifiedAction.erase(0, 1);
    std::size_t chestIndex = std::stoi(modifiedAction);
    if (chestIndex >= room->getChests().size()) {
        std::cout << "Invalid chest index" << std::endl;
        return;
    }
    if (room->getChests()[chestIndex]->getIsOpen()) {
        std::cout << "Chest already opened" << std::endl;
        return;
    }
    std::unique_ptr<AItems> item = room->getChests()[chestIndex]->open();
    if (item == nullptr) return;
    item->display();
    item->displayDescription();
    const std::string resp = InputManager::getUserInput("Do you want to use? (Y/N): ", {"y", "n"});
    if (resp == "y") {
        item->use(this->player, &(*this));
    } else
        item->drop();
}

void Dungeon::handleRoomChange(std::shared_ptr<Room> &room, const std::string &action)
{
    std::string modifiedAction = action;
    modifiedAction.erase(0, 1);
    std::size_t roomIndex = std::stoi(modifiedAction);
    if (roomIndex >= room->getLinkedRooms().size()) {
        std::cout << "Invalid room index" << std::endl;
        return;
    }
    std::shared_ptr<Room> &linkedRoom = room->getLinkedRooms()[roomIndex];
    if (linkedRoom->getEnemies().size() > 0) {
        const std::string action = InputManager::getUserInput("You are about to enter a room with " + std::to_string(linkedRoom->getEnemies().size()) + " enemies, are you sure? (Y/N): ", {"y", "n"});
        if (action == "n") {
            std::cout << "You decided to not enter the room" << std::endl;
            return;
        }
    }
    this->map.enterRoom(linkedRoom->getPos()[0], linkedRoom->getPos()[1], this->player);
}

void Dungeon::actionHandler(std::shared_ptr<Room> &room, const std::string &action)
{
    if (action.size() < 2) {
        std::cout << "Invalid action" << std::endl;
        return;
    };
    char c = action[0];
    const std::map<char, std::function<void()>> actions = {
        {'r', [&]() {this->handleRoomChange(room, action);}},
        {'c', [&]() {this->handleChestOpening(room, action);}},
        {'e', [&]() {this->handleExit(room);}}


    };
    if (actions.find(c) != actions.end())
        actions.at(c)();
    else
        std::cout << "Invalid action" << std::endl;
}

void Dungeon::displayGameInfo(std::shared_ptr<Room> &room) const
{
    room->DisplayRoom();
    this->player.displayCharacterInfo();
    std::cout << "Your position in the map: " << this->player.getPosition()[0] << " " << this->player.getPosition()[1] << std::endl;
    std::cout << "You are in room: " << room->getName() << std::endl;
    std::cout << "Description of the room: " << std::endl;
    room->displayConnectedRooms();
    room->displayChests();
}