//
//  main.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include <iostream>
#include "App.hpp"

int main(int argc, const char * argv[]) {
    App* session = App::getInstance(); // singleton을 써봄
    
    session->routine();
    
    // libsb::Node testNode;
    // testNode.mIsHuman = true;
    // std::cout << testNode.mIsHuman << std::endl;
    
    // libsb::List* testList = new libsb::List();
    // delete testList;
    
    // delete session; 싱글턴 사용 시 이건 사용 안 함
    return 0;
}
