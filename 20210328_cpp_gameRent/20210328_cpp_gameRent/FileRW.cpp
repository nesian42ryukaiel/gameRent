//
//  FileRW.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/24.
//

#include "FileRW.hpp"

FileRW::FileRW() {
    
}

FileRW::~FileRW() {
    
}

void FileRW::loadCustomer(libsb::List* customer) { // 고객 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    if (customer != nullptr) {
        customer = new libsb::List();
        // 여기서 로드
        rapidjson::Document document;
        char readBuffer[65536];
        
        FILE* fp = fopen("/Users/lvcrivca/repo/gameRent/grSave/customer.json", "r");
        
        rapidjson::FileReadStream is (fp, readBuffer, sizeof(readBuffer));
        
        document.ParseStream(is);
        
        for (rapidjson::SizeType i = 0; i < document.Size(); i++) {
            customer->push_back(document[i]["ID"].GetUint(), document[i]["name"].GetString(), document[i]["isHuman"].GetBool(), document[i]["isOnRent"].GetUint());
            
        }
        
        fclose(fp);
        
        std::cout << "[DEBUG_M]: Customer data safely loaded.\n" << std::endl;
    }
}

void FileRW::saveCustomer(libsb::List* customer) { // 고객 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    if (customer != nullptr) {
        // 여기서 저장
        rapidjson::Document document;
        document.SetArray();
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        
        for (libsb::Node* iterator = customer->getHead(); iterator != nullptr; iterator = iterator->next) {
            // 아마 여기서 역 파싱
            rapidjson::Value objValue;
            objValue.SetObject();
            
            unsigned int id = iterator->mID;
            const std::string& name = iterator->mName;
            bool human = iterator->mIsHuman;
            unsigned int rent = iterator->mIsOnRent;
            
            objValue.AddMember("ID", id, allocator);
            objValue.AddMember("name", rapidjson::Value(name.c_str(), allocator), allocator);
            objValue.AddMember("isHuman", human, allocator);
            objValue.AddMember("isOnRent", rent, allocator);
            
            document.PushBack(objValue, allocator);
            
        }
        
        FILE* fp = fopen("/Users/lvcrivca/repo/gameRent/grSave/customer.json", "w");
        
        char writeBuffer[65536];
        rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        
        rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
        document.Accept(writer);
        
        fclose(fp);
        
        std::cout << "[DEBUG_M]: Customer data safely stored.\n" << std::endl;
        delete customer;
    }
}

void FileRW::loadGame(libsb::List* game) { // 게임 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/game.json)
    if (game != nullptr) {
        game = new libsb::List();
        // 여기서 로드
        rapidjson::Document document;
        char readBuffer[65536];
        
        FILE* fp = fopen("/Users/lvcrivca/repo/gameRent/grSave/game.json", "r");
        
        rapidjson::FileReadStream is (fp, readBuffer, sizeof(readBuffer));
        
        document.ParseStream(is);
        
        for (rapidjson::SizeType i = 0; i < document.Size(); i++) {
            game->push_back(document[i]["ID"].GetUint(), document[i]["name"].GetString(), document[i]["isHuman"].GetBool(), document[i]["isOnRent"].GetUint());
            
        }
        
        fclose(fp);
        
        std::cout << "[DEBUG_M]: Game data safely loaded.\n" << std::endl;
    }
}

void FileRW::saveGame(libsb::List* game) { // 게임 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/game.json)
    if (game != nullptr) {
        rapidjson::Document document;
        document.SetArray();
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        
        for (libsb::Node* iterator = game->getHead(); iterator != nullptr; iterator = iterator->next) {
            // 아마 여기서 역 파싱
            rapidjson::Value objValue;
            objValue.SetObject();
            
            unsigned int id = iterator->mID;
            const std::string& name = iterator->mName;
            bool human = iterator->mIsHuman;
            unsigned int rent = iterator->mIsOnRent;
            
            objValue.AddMember("ID", id, allocator);
            objValue.AddMember("name", rapidjson::Value(name.c_str(), allocator), allocator);
            objValue.AddMember("isHuman", human, allocator);
            objValue.AddMember("isOnRent", rent, allocator);
            
            document.PushBack(objValue, allocator);
            
        }
        
        FILE* fp = fopen("/Users/lvcrivca/repo/gameRent/grSave/game.json", "w");
        
        char writeBuffer[65536];
        rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        
        rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
        document.Accept(writer);
        
        fclose(fp);
        
        std::cout << "[DEBUG_M]: Game data safely stored.\n" << std::endl;
        delete game;
    }
}
