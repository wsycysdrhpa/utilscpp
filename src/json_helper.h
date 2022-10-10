/*************************************************************************
 @Version: 
 @CreatedBy: 
 @UpdatedTime: 
 @Copyright (c) 
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
