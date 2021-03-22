//
//  App.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include "App.hpp"

App* App::instance = nullptr;

App* App::getInstance() {
    if (instance == nullptr) {
        instance = new App();
    }
    
    return instance;
}

void App::routine() {
    char control = NULL;
    unsigned int id = 0;
    std::string name;
    bool human = false;
    unsigned int rent = 0;
    
    loadCustomer(); // 고객 정보 로드
    loadGame(); // 게임 정보 로드
    
//    std::cout << "Initializing";
//    sleep(1);
//    std::cout << ".";
//    sleep(1);
//    std::cout << ".";
//    sleep(1);
//    std::cout << ".\n" << std::endl;
//    sleep(1);
    
    // 메인 루프
    while (true) {
        std::cout << "/===============\\" << std::endl;
        std::cout << "|GAME STORE RENT|" << std::endl;
        std::cout << "\\===============/\n" << std::endl;
        // sleep(1);
        
        std::cout << "Press C/c to handle Customer data." <<std::endl;
        std::cout << "Press G/g to handle   Game   data." <<std::endl;
        std::cout << "Press R/r to handle  Rental  data.\n" <<std::endl;
        std::cout << "Press Q/q to quit this session.\n" <<std::endl;
        
        std::cin >> control;
        if (control == 'C' || control == 'c') {
            control = NULL;
            std::cout << "\nCustomer Mode\n" <<std::endl;
        } else if (control == 'G' || control == 'g') {
            control = NULL;
            std::cout << "\nGame Mode\n" <<std::endl;
        } else if (control == 'R' || control == 'r') {
            control = NULL;
            std::cout << "\nRental Mode\n" <<std::endl;
        } else if (control == 'Q' || control == 'q') {
            control = NULL;
            break;
        }
        
        findCustomerName();
        addCustomer();
        addCustomer();
        findCustomerID();
        mCustomer->print(0);
        // sleep(1);
        
        // break;
    }
    
    saveCustomer(); // 고객 정보 저장
    saveGame(); // 게임 정보 저장
}


void App::loadCustomer() { // 고객 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    if (mCustomer == nullptr) {
        mCustomer = new libsb::List();
        // 여기서 로드
        rapidjson::Document document;
        char readBuffer[65536];
        
        FILE* fp = fopen("/Users/lvcrivca/repo/gameRent/grSave/customer.json", "r");
        
        rapidjson::FileReadStream is (fp, readBuffer, sizeof(readBuffer));
        
        document.ParseStream(is);
        
        for (rapidjson::SizeType i = 0; i < document.Size(); i++) {
            mCustomer->push_back(document[i]["ID"].GetUint(), document[i]["name"].GetString(), document[i]["isHuman"].GetBool(), document[i]["isOnRent"].GetUint());
            
        }
        
        fclose(fp);
        
        std::cout << "[DEBUG_M]: Customer data safely loaded.\n" << std::endl;
    }
}

void App::saveCustomer() { // 고객 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/customer.json)
    if (mCustomer != nullptr) {
        // 여기서 저장
        rapidjson::Document document;
        document.SetArray();
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        
        for (libsb::Node* iterator = mCustomer->getHead(); iterator != nullptr; iterator = iterator->next) {
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
        delete mCustomer;
    }
}

void App::addCustomer() {  // 고객 정보 입력 (신규)
    if (mCustomer != nullptr) {
        // 여기서 타이핑; 이름과 전화번호 둘 다 중복이면 거부
        // mCustomer->push_back(id, name, true, 0);
    }
}

void App::findCustomerName() {  // 고객 정보 검색 (이름)
    if (mCustomer != nullptr) {
        // 여기서 타이핑
        mCustomer->findName("Buddha"); // return을 바꿔야 하나
    }
}

void App::findCustomerID() {  // 고객 정보 검색 (전화번호)
    if (mCustomer != nullptr) {
        
        mCustomer->findID(108);
    }
}

void App::viewCustomer() { // 고객 정보 조회 ()
    if (mCustomer != nullptr) {
        // 인간일 경우만
        // 고객의 이름과 전화번호를 print
        // 그리고 해당 고객이 빌린 모든 게임들을 게재
    }
}

void App::offCustomer() { // 고객 정보 삭제 (탈퇴)
    if (mCustomer != nullptr) {
        // 인간일 경우만
        // 고객 정보 노드 삭제
        
    }
}


void App::loadGame() { // 게임 정보 로드 (from /Users/lvcrivca/repo/gameRent/grSave/game.json)
    if (mGame == nullptr) {
        mGame = new libsb::List();
        // 여기서 로드
        rapidjson::Document document;
        char readBuffer[65536];
        
        FILE* fp = fopen("/Users/lvcrivca/repo/gameRent/grSave/game.json", "r");
        
        rapidjson::FileReadStream is (fp, readBuffer, sizeof(readBuffer));
        
        document.ParseStream(is);
        
        for (rapidjson::SizeType i = 0; i < document.Size(); i++) {
            mGame->push_back(document[i]["ID"].GetUint(), document[i]["name"].GetString(), document[i]["isHuman"].GetBool(), document[i]["isOnRent"].GetUint());
            
        }
        
        fclose(fp);
        
        std::cout << "[DEBUG_M]: Game data safely loaded.\n" << std::endl;
    }
}

void App::saveGame() { // 게임 정보 저장 ( to  /Users/lvcrivca/repo/gameRent/grSave/game.json)
    if (mGame != nullptr) {
        rapidjson::Document document;
        document.SetArray();
        rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        
        for (libsb::Node* iterator = mGame->getHead(); iterator != nullptr; iterator = iterator->next) {
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
        delete mGame;
    }
}

void App::addGame() { // 게임 정보 입력 (신규)
    if (mGame != nullptr) {
        
    }
}

void App::findGameName() { // 게임 정보 검색 (이름)
    if (mGame != nullptr) {
        
    }
}

void App::findGameID() { // 게임 정보 검색 (일련번호)
    if (mGame != nullptr) {
        
    }
}

void App::viewGame() { // 게임 정보 조회 (대여 여부 등 확인)
    if (mGame != nullptr) {
        
    }
}

void App::offGame() { // 게임 정보 삭제 (매각)
    if (mGame != nullptr) {
        
    }
}

void App::rentGame() { // 게임 대여 처리
    if (mGame != nullptr) {
        
    }
}

void App::retrieveGame() { // 게임 반납 처리
    if (mGame != nullptr) {
        
    }
}

//----------------

App::App():
mCustomer(nullptr), mGame(nullptr) // , mRent(nullptr)
{
    std::cout << "[DEBUG_M]: Zoom\n" << std::endl;
}

App::~App() {
    std::cout << "[DEBUG_M]: pooF\n" << std::endl;
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
    
}
