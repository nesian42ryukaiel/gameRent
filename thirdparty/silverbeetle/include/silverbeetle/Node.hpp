//
//  Node.hpp
//  20210301_cpp_testbed
//
//  Created by 유기하 on 2021/03/15.
//

#ifndef Node_hpp
#define Node_hpp

#include <iostream>
#include <string>
#include <stdio.h>

namespace libsb {

struct Node {
public:
    Node();
    Node(unsigned int id, std::string name, bool human, unsigned int rent);
    ~Node();
    
    unsigned int mID; // 전화번호
    std::string mName; // 이름
    bool mIsHuman;
    unsigned int mIsOnRent;
    struct Node* prev;
    struct Node* next;
    
protected:
    
    
private:
    
    
};

}

#endif /* Node_hpp */
