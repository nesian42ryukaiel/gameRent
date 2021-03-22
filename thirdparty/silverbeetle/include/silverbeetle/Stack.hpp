//
//  Stack.hpp
//  20210301_cpp_testbed
//
//  Created by 유기하 on 2021/03/17.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#include "Node.hpp"

namespace libsb {

class Stack {
public:
    Stack();
    ~Stack();
    
    void clear();
    void push(unsigned int id, std::string name, bool human, unsigned int rent);
    void pop();
    unsigned int topID();
    std::string topName();
    unsigned int size();
    bool empty();
    void print();
    Node* getTop();
    
private:
    Node* top;
    
};

}

#endif /* Stack_hpp */
