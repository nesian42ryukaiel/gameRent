//
//  Rental.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#include "RentalSystem.hpp"

RentalSystem::RentalSystem() {
    
}

RentalSystem::~RentalSystem() {
    
};

void RentalSystem::rent(libsb::List* customer, unsigned int phone, libsb::List* game, unsigned int serial) {
    if (customer->findID(phone) != nullptr && game->findID(serial) != nullptr && game->findID(serial)->mIsOnRent == 0) {
        game->findID(serial)->mIsOnRent = customer->findID(phone)->mID;
        // 연체 부분을 구현한다면 여기다 구현
    }
}

void RentalSystem::retrieve(libsb::List* game, unsigned int serial) {
    if (game->findID(serial) != nullptr && game->findID(serial)->mIsOnRent != 0) {
        game->findID(serial)->mIsOnRent = 0;
        // 연체 부분을 구현한다면 여기다 구현
    }
}
