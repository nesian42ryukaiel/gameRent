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
    static App* getInstance();
    
protected:
    
    
private:
    App();
    ~App();
    
    libsb::List* mCustomer;
    libsb::List* mGame;
    // libsb::List* mRent;
    
    static App* instance;
    
};

#endif /* App_hpp */
