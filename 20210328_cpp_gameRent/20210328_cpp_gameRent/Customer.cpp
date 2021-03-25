//
//  Customer.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#include "Customer.hpp"

Customer::Customer() {
    
}

Customer::~Customer() {
    
}

void Customer::signup(libsb::List* customer, unsigned int id, std::string name) {
    if (customer != nullptr) {
        customer->push_back(id, name, true, 0);
    }
}

libsb::Node* Customer::findName(libsb::List* customer, std::string name) {
    if (customer != nullptr) {
        return customer->findName(name);
    }
    
    return nullptr;
}

libsb::Node* Customer::findPhone(libsb::List* customer, unsigned int phone) {
    if (customer != nullptr) {
        
        return customer->findID(phone);
    }
    
    return nullptr;
}

void Customer::viewIndividual(libsb::List* customer, libsb::Node* individual) {
    if (customer != nullptr && individual != nullptr) {
        std::cout << "[" << individual->mID << "] " << individual->mName << "\n" << std::endl;
    }
}

void Customer::unsign(libsb::List* customer, libsb::Node* individual) {
    if (customer != nullptr && individual != nullptr) {
        customer->remove(individual);
    }
}

