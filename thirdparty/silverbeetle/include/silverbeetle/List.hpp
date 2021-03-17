//
//  List.hpp
//  20210301_cpp_testbed
//
//  Created by 유기하 on 2021/03/15.
//

#ifndef List_hpp
#define List_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#include "Node.hpp"

namespace libsb {

class List {
public:
    List();
    ~List();
    
    void clear();
    void insert(Node* position, unsigned int id, std::string name);
    void push_front(unsigned int id, std::string name);
    void push_back(unsigned int id, std::string name);
    void pop_front();
    void pop_back();
    void remove(Node* position);
    Node* findName(std::string name);
    Node* findID(unsigned int id);
    unsigned int size();
    bool empty();
    void print(bool inverse);
    
private:
    Node* head;
    Node* tail;
    
};

}

#endif /* List_hpp */
