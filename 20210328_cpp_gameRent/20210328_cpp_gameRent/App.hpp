//
//  App.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#ifndef App_hpp
#define App_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <silverbeetle/DataStructure>
#include "rapidjson/document.h" // JSON 파일 저장/로드용 유명 파싱 기능 라이브러리
#include "unistd.h"

class App {
public:
    static App* getInstance();
    
    void routine();
    
    void loadCustomer();// 고객 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/customer.txt)
    void saveCustomer();// 고객 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/customer.txt)
    void addCustomer(); // 고객 정보 입력 (신규)
    void findCustomerName(); // 고객 정보 검색 (이름)
    void findCustomerID(); // 고객 정보 검색 (전화번호)
    void viewCustomer(); // 고객 정보 조회 ()
    void offCustomer();// 고객 정보 삭제 (탈퇴)
    
    void loadGame(); // 게임 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/game.txt)
    void saveGame(); // 게임 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/game.txt)
    void addGame(); // 게임 정보 입력 (신규)
    void findGameName(); // 게임 정보 검색 (이름)
    void findGameID(); // 게임 정보 검색 (일련번호)
    void viewGame(); // 게임 정보 조회 (대여 여부 등 확인)
    void offGame(); // 게임 정보 삭제 (매각)
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
