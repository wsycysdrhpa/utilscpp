/*************************************************************************
 @Version: 1.0
 @CreatedBy: Aruan
 @UpdatedTime: '2021/6/21'
 @Copyright (c) 2021 ke Inc. All rights reserved.
 @Description:
 ************************************************************************/


#include "utilscpp/json_helper.h"

#include <iostream>
#include <memory>


namespace utilscpp {

bool JsonHelper::StrToJson(const std::string& str, Json::Value* json_ptr) {
    if (str.empty() || json_ptr == nullptr) return false;
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> parser(builder.newCharReader());
    std::string msg;
    return parser->parse(str.c_str(), str.c_str() + str.size(), json_ptr, &msg);
}

bool JsonHelper::JsonToStr(const Json::Value& json, std::string* str) {
    Json::StreamWriterBuilder builder;
    builder.settings_["indentation"] = "";
    std::unique_ptr<Json::StreamWriter> writer_ptr(builder.newStreamWriter());
    std::ostringstream oss;
    writer_ptr->write(json, &oss);
    *str = oss.str();
    return true;
}

void TestJsonHelper() {
    std::cout << "***Start Of Test Json Helper***" << std::endl;

    Json::Value json;
    Json::Value* json_ptr = &json;
    std::string str = "{\"field1\":1, \"field2\": \"abc\", \"field3\": false}";
    utilscpp::JsonHelper::StrToJson(str, json_ptr);
    std::cout << *json_ptr << std::endl;

    std::cout << std::endl;

    typedef Json::Value JsonDoc;
    JsonDoc jsonRoot;
    JsonDoc jsonItem;
    jsonItem["item1"] = "one";
    jsonItem["item2"] = 2;
    jsonRoot.append(jsonItem);
    JsonDoc dm_item;
    dm_item["title"] = "";
    dm_item["content"] = 123;
    jsonRoot.insert(0, dm_item);
    // std::cout << jsonRoot << std::endl;
    std::string str1;
    std::string* str1_ptr = &str1;
    utilscpp::JsonHelper::JsonToStr(jsonRoot, str1_ptr);
    std::cout << *str1_ptr << std::endl;

    std::cout << "***End Of Test Json Helper***" << std::endl;
}

}  // namespace utilscpp
