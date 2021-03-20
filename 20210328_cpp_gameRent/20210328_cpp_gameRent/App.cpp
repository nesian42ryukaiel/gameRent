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
    loadCustomer(); // 고객 정보 로드
    // 게임 정보 로드
    
    std::cout << "Initializing";
    sleep(1);
    std::cout << ".";
    sleep(1);
    std::cout << ".";
    sleep(1);
    std::cout << ".\n" << std::endl;
    sleep(1);
    
    // 메인 루프
    while (true) {
        std::cout << "/===============\\" << std::endl;
        std::cout << "|GAME STORE RENT|" << std::endl;
        std::cout << "\\===============/\n" << std::endl;
        sleep(1);
        
        findCustomerName();
        addCustomer();
        addCustomer();
        findCustomerID();
        mCustomer->print(0);
        sleep(1);
        
        break;
    }
    
    saveCustomer(); // 고객 정보 저장
    // 게임 정보 저장
}


void App::loadCustomer() { // 고객 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/customer.txt)
    if (mCustomer == nullptr) {
        mCustomer = new libsb::List();
        // 여기서 로드
        std::cout << "[DEBUG_M]: Customer data safely loaded.\n" << std::endl;
    }
}

void App::saveCustomer() { // 고객 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/customer.txt)
    if (mCustomer != nullptr) {
        // 여기서 저장
        std::cout << "[DEBUG_M]: Customer data safely stored.\n" << std::endl;
        delete mCustomer;
    }
}

void App::addCustomer() {  // 고객 정보 입력 (신규)
    if (mCustomer != nullptr) {
        // 여기서 타이핑; 이름과 전화번호 둘 다 중복이면 거부
        mCustomer->push_back(108, "Buddha");
    }
}

void App::findCustomerName() {  // 고객 정보 검색 (이름)
    if (mCustomer != nullptr) {
        // 여기서 타이핑
        mCustomer->findName("Buddha"); // return을 바꿔야 하나
    }
}

void App::findCustomerID() {  // 고객 정보 검색 (전화번호)
    if (mCustomer != nullptr) {
        
        mCustomer->findID(108);
    }
}

void App::viewCustomer() { // 고객 정보 조회 ()
    if (mCustomer != nullptr) {
        
    }
}

void App::offCustomer() { // 고객 정보 삭제 (탈퇴)
    if (mCustomer != nullptr) {
        
    }
}


void App::loadGame() { // 게임 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/game.txt)
    if (mGame == nullptr) {
        
    }
}

void App::saveGame() { // 게임 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/game.txt)
    if (mGame != nullptr) {
        
    }
}

void App::addGame() { // 게임 정보 입력 (신규)
    if (mGame != nullptr) {
        
    }
}

void App::findGameName() { // 게임 정보 검색 (이름)
    if (mGame != nullptr) {
        
    }
}

void App::findGameID() { // 게임 정보 검색 (일련번호)
    if (mGame != nullptr) {
        
    }
}

void App::viewGame() { // 게임 정보 조회 (대여 여부 등 확인)
    if (mGame != nullptr) {
        
    }
}

void App::offGame() { // 게임 정보 삭제 (매각)
    if (mGame != nullptr) {
        
    }
}

void App::rentGame() { // 게임 대여 처리
    if (mGame != nullptr) {
        
    }
}

void App::retrieveGame() { // 게임 반납 처리
    if (mGame != nullptr) {
        
    }
}

//----------------

App::App():
mCustomer(nullptr), mGame(nullptr) // , mRent(nullptr)
{
    std::cout << "[DEBUG_M]: Zoom\n" << std::endl;
}

App::~App() {
    std::cout << "[DEBUG_M]: pooF\n" << std::endl;
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
    
}
