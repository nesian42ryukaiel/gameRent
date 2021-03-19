//
//  App.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include "App.hpp"

App* App::instance = nullptr;

App* App::getInstance() {
    if (instance == nullptr) {
        instance = new App();
    }
    
    return instance;
}

void App::routine() {
    std::cout << "Initializing";
    sleep(1);
    std::cout << ".";
    sleep(1);
    std::cout << ".";
    sleep(1);
    std::cout << "." << std::endl;
    sleep(1);
    
}

App::App():
mCustomer(nullptr), mGame(nullptr) // , mRent(nullptr)
{
    std::cout << "Zoom\n" << std::endl;
}

App::~App() {
    std::cout << "pooF\n" << std::endl;
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
    
}
