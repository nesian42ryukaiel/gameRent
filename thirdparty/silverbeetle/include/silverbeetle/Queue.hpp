//
//  Queue.hpp
//  20210301_cpp_testbed
//
//  Created by 유기하 on 2021/03/16.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#include "Node.hpp"

namespace libsb {

class Queue {
public:
    Queue();
    ~Queue();
    
    void clear();
    void push(unsigned int id, std::string name);
    void pop();
    unsigned int frontID();
    std::string frontName();
    unsigned int backID();
    std::string backName();
    unsigned int size();
    bool empty();
    void print(bool inverse);
    
private:
    Node* front;
    Node* back;
    
};

}

#endif /* Queue_hpp */
