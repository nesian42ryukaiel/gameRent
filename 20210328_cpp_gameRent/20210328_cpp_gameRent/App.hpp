//
//  App.hpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#ifndef App_hpp
#define App_hpp

#include <stdio.h>
#include <filesystem>
#include <silverbeetle/DataStructure>

class App {
public:
    App();
    ~App();
    
protected:
    
    
private:
    libsb::List* mCustomer;
    libsb::List* mGame;
    libsb::List* mRent;
    
};

#endif /* App_hpp */
