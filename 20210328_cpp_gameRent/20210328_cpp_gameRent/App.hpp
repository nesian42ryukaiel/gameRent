//
//  App.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#ifndef App_hpp
#define App_hpp

//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <silverbeetle/DataStructure>
//#include <rapidjson/RapidJsonUsing>
//#include "unistd.h"
#include "gameRent.hpp"

class App {
public:
    static App* getInstance();
    
    void routine();
    
    void loadCustomer();// 고객 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    void loadGame(); // 게임 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/game.json)
    void saveCustomer();// 고객 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    void saveGame(); // 게임 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/game.json)
    
    void addCustomer(unsigned int id, std::string name); // 고객 정보 입력 (신규)
    libsb::Node* findCustomerName(std::string name); // 고객 정보 검색 (이름)
    libsb::Node* findCustomerID(unsigned int id); // 고객 정보 검색 (전화번호)
    void viewCustomer(libsb::Node* customer); // 고객 정보 조회 ()
    void offCustomer(libsb::Node* customer);// 고객 정보 삭제 (탈퇴)
    
    void addGame(unsigned int id, std::string name); // 게임 정보 입력 (신규)
    libsb::Node* findGameName(std::string name); // 게임 정보 검색 (이름)
    libsb::Node* findGameID(unsigned int id); // 게임 정보 검색 (일련번호)
    void viewGame(libsb::Node* game); // 게임 정보 조회 (대여 여부 등 확인)
    void offGame(libsb::Node* game); // 게임 정보 삭제 (매각)
    
    void rentGame(); // 게임 대여 처리
    void retrieveGame();// 게임 반납 처리
    
protected:
    
    
private:
    App();
    ~App();
    
    libsb::List* mCustomer;
    libsb::List* mGame;
    // libsb::List* mRent;
    
    static App* instance;
    
};

#endif /* App_hpp */
