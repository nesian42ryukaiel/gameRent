//
//  main.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include <iostream>
#include <silverbeetle/DataStructure>
#include "App.hpp"

int main(int argc, const char * argv[]) {
    App* session = App::getInstance(); // singleton을 써봄
    
    libsb::List* testList = new libsb::List();
    
    libsb::Node testNode;
    testNode.mIsHuman = true;
    
    delete testList;
    
    // delete session;
    return 0;
}
