//
//  FileRW.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/24.
//

#ifndef FileRW_hpp
#define FileRW_hpp

#include "gameRent.hpp"

class FileRW {
public:
    FileRW();
    ~FileRW();
    
    void loadCustomer(libsb::List* customer);// 고객 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    void saveCustomer(libsb::List* customer);// 고객 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    void loadGame(libsb::List* game); // 게임 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/game.json)
    void saveGame(libsb::List* game); // 게임 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/game.json)
    
};

#endif /* FileRW_hpp */
