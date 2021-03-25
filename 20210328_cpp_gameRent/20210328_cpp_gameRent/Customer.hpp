//
//  Customer.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/25.
//

#ifndef Customer_hpp
#define Customer_hpp

#include "gameRent.hpp"

class Customer {
public:
    Customer();
    ~Customer();
    
    void signup(libsb::List* customer, unsigned int id, std::string name); // 고객 정보 입력 (신규)
    libsb::Node* findName(libsb::List* customer, std::string name); // 고객 정보 검색 (이름)
    libsb::Node* findPhone(libsb::List* customer, unsigned int phone); // 고객 정보 검색 (전화번호)
    void viewIndividual(libsb::List* customer, libsb::Node* individual); // 고객 정보 조회 ()
    void unsign(libsb::List* customer, libsb::Node* individual);// 고객 정보 삭제 (탈퇴)
    
private:
    
};

#endif /* Customer_hpp */
