//
//  Game.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#include "Game.hpp"

Game::Game() {
    
}

Game::~Game() {
    
}

void Game::stash(libsb::List* game, unsigned int id, std::string name) {
    if (game != nullptr) {
        game->push_back(id, name, false, 0);
    }
}

libsb::Node* Game::findTitle(libsb::List* game, std::string title) {
    if (game != nullptr) {
        return game->findName(title);
    }
    
    return nullptr;
}

libsb::Node* Game::findSerial(libsb::List* game, unsigned int serial) {
    if (game != nullptr) {
        return game->findID(serial);
    }
    
    return nullptr;
}

void Game::viewGame(libsb::List* game, libsb::Node* soft) {
    if (game != nullptr && soft != nullptr) {
        std::cout << "[" << soft->mID << "] " << soft->mName << "\n" << std::endl;
    }
}

void Game::dispose(libsb::List* game, libsb::Node* soft) {
    if (game != nullptr && soft != nullptr) {
        game->remove(soft);
    }
}

