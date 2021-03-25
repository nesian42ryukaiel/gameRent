//
//  Game.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#ifndef Game_hpp
#define Game_hpp

#include "gameRent.hpp"

class GameManager {
public:
    GameManager();
    ~GameManager();
    
    void stash(libsb::List* game, unsigned int id, std::string name); // 게임 정보 입력 (신규)
    libsb::Node* findTitle(libsb::List* game, std::string title); // 게임 정보 검색 (이름)
    libsb::Node* findSerial(libsb::List* game, unsigned int serial); // 게임 정보 검색 (일련번호)
    void viewGame(libsb::List* game, libsb::Node* soft); // 게임 정보 조회 (대여 여부 등 확인)
    void dispose(libsb::List* game, libsb::Node* soft); // 게임 정보 삭제 (매각)
    
private:
    
};

#endif /* Game_hpp */
