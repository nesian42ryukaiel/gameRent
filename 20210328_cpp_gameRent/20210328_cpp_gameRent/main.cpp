//
//  main.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include <iostream>
#include "gameRent.hpp"

using namespace libsb;

int main(int argc, const char * argv[]) {
    App* session = App::getInstance(); // singleton을 써봄
    
    session->routine();
    
    return 0;
}
