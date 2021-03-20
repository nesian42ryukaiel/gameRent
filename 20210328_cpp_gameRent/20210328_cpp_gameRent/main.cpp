//
//  main.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include <iostream>
#include "App.hpp"
// 이하 RapidJSON 테스트용 헤더들 명시
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace libsb;

int main(int argc, const char * argv[]) {
    App* session = App::getInstance(); // singleton을 써봄
    
    session->routine();
    
    // delete session; 싱글턴 사용 시 이건 사용 안 함
    
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    rapidjson::Document d;
    d.Parse(json);
 
    // 2. Modify it by DOM.
    rapidjson::Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
 
    // 3. Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);
 
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl << std::endl;
    return 0;
    
    return 0;
}
