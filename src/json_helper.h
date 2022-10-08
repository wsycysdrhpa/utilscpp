/*************************************************************************
 @Version: 1.0
 @CreatedBy: Aruan
 @UpdatedTime: '2021/6/21'
 @Copyright (c) 2021 ke Inc. All rights reserved.
 @Description:
 ************************************************************************/


#ifndef SRC_UTILSCPP_JSON_HELPER_H_
#define SRC_UTILSCPP_JSON_HELPER_H_


#include <string>

#include "json/json.h"


namespace utilscpp {

class JsonHelper {
 public:
    JsonHelper() {}
    ~JsonHelper() {}

    static bool StrToJson(const std::string& str, Json::Value* json);
    static bool JsonToStr(const Json::Value& json, std::string* str);
};

void TestJsonHelper();

}  // namespace utilscpp

#endif  // SRC_UTILSCPP_JSON_HELPER_H_
