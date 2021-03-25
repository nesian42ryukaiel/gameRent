//
//  Rental.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#ifndef Rental_hpp
#define Rental_hpp

#include "gameRent.hpp"

class Rental {
public:
    Rental();
    ~Rental();
    
    void rent(libsb::List* customer, unsigned int phone, libsb::List* game, unsigned int serial); // 게임 대여 처리; 빌리려는 고객과 게임의 id를 받아 연결한다.
    void retrieve(libsb::List* game, unsigned int serial);// 게임 반납 처리; 빌린 상태인 게임의 id를 받아 해제한다.
    
private:
    
};

#endif /* Rental_hpp */
