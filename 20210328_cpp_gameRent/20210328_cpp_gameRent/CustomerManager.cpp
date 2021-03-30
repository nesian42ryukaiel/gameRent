//
//  Customer.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#include "CustomerManager.hpp"

CustomerManager::CustomerManager() {
    
}

CustomerManager::~CustomerManager() {
    
}

void CustomerManager::signup(libsb::List* customer, unsigned int id, std::string name) {
    if (customer != nullptr) {
        customer->push_back(id, name, true, 0);
        std::cout << "[DEBUG_M]: A new customer signed up.\n" << std::endl;
    } else {
        std::cout << "[DEBUG_M]: Signup failed.\n" << std::endl;
    }
}

libsb::Node* CustomerManager::findName(libsb::List* customer, std::string name) {
    if (customer != nullptr) {
        return customer->findName(name);
    }
    
    return nullptr;
}

libsb::Node* CustomerManager::findPhone(libsb::List* customer, unsigned int phone) {
    if (customer != nullptr) {
        
        return customer->findID(phone);
    }
    
    return nullptr;
}

void CustomerManager::viewIndividual(libsb::List* customer, libsb::Node* individual) {
    if (customer != nullptr && individual != nullptr) {
        std::cout << "[" << individual->mID << "] " << individual->mName << "\n" << std::endl;
    }
}

void CustomerManager::unsign(libsb::List* customer, libsb::Node* individual) {
    if (customer != nullptr && individual != nullptr) {
        customer->remove(individual);
    }
}

