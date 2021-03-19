//
//  App.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#ifndef App_hpp
#define App_hpp

#include <stdio.h>
#include <filesystem>
#include <silverbeetle/DataStructure>
#include "unistd.h"

class App {
public:
    static App* getInstance();
    
    void routine();
    
    // 고객 정보 로드 (from customer.txt)
    // 고객 정보 저장 ( to  customer.txt)
    // 고객 정보 입력 (신규)
    // 고객 정보 검색 (이름)
    // 고객 정보 검색 (전화번호)
    // 고객 정보 조회 ()
    // 고객 정보 삭제 (탈퇴)
    
    // 게임 정보 로드 (from game.txt)
    // 게임 정보 저장 ( to  game.txt)
    // 게임 정보 입력 (신규)
    // 게임 정보 검색 (이름)
    // 게임 정보 검색 (일련번호)
    // 게임 정보 조회 (대여 여부 등 확인)
    // 게임 정보 삭제 (매각)
    // 게임 대여 처리
    // 게임 반납 처리
    
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
