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
        // 여기서 타이핑; 이름과 전화번호 둘 다 중복이면 거부
        customer->push_back(id, name, true, 0);
    }
}

libsb::Node* Customer::findName(libsb::List* customer, std::string name) {
    if (customer != nullptr) {
        // 여기서 타이핑
        return customer->findName(name); // return을 바꿔야 하나
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
        // 인간일 경우만
        // 고객의 이름과 전화번호를 print
        std::cout << "[" << individual->mID << "] " << individual->mName << "\n" << std::endl;
        // 그리고 해당 고객이 빌린 모든 게임들을 게재
    }
}

void Customer::unsign(libsb::List* customer, libsb::Node* individual) {
    // customer을 찾았다는 걸 전제
    if (customer != nullptr && individual != nullptr) {
        // 인간일 경우만
        // 고객 정보 노드 삭제
        customer->remove(individual);
    }
}

