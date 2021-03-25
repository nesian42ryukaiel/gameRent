//
//  Game.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#include "GameManager.hpp"

GameManager::GameManager() {
    
}

GameManager::~GameManager() {
    
}

void GameManager::stash(libsb::List* game, unsigned int id, std::string name) {
    if (game != nullptr) {
        game->push_back(id, name, false, 0);
    }
}

libsb::Node* GameManager::findTitle(libsb::List* game, std::string title) {
    if (game != nullptr) {
        return game->findName(title);
    }
    
    return nullptr;
}

libsb::Node* GameManager::findSerial(libsb::List* game, unsigned int serial) {
    if (game != nullptr) {
        return game->findID(serial);
    }
    
    return nullptr;
}

void GameManager::viewGame(libsb::List* game, libsb::Node* soft) {
    if (game != nullptr && soft != nullptr) {
        std::cout << "[" << soft->mID << "] " << soft->mName << "\n" << std::endl;
    }
}

void GameManager::dispose(libsb::List* game, libsb::Node* soft) {
    if (game != nullptr && soft != nullptr) {
        game->remove(soft);
    }
}

