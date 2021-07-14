/*************************************************************************
 @Version: 1.0
 @CreatedBy: Aruan
 @UpdatedTime: '2021/5/26'
 @Copyright (c) 2021 ke Inc. All rights reserved.
 @Description:
 ************************************************************************/


#include "utilscpp/string_helper.h"


namespace utilscpp {

bool StringHelper::Trim(std::string* str_ptr) {
    if (str_ptr == nullptr || str_ptr->empty()) return false;
    str_ptr->erase(0, str_ptr->find_first_not_of(" "));
    str_ptr->erase(str_ptr->find_last_not_of(" ")+1);
    return true;
}

bool StringHelper::Split(const std::string& str, const std::string& delimiter, std::vector<std::string>* tokens_ptr) {
    if (str.empty() || delimiter.empty() || tokens_ptr == nullptr) return false;
    tokens_ptr->clear();
    std::string::size_type pos1, pos2;
    pos2 = str.find(delimiter);
    pos1 = 0;
    while (std::string::npos != pos2) {
        tokens_ptr->push_back(str.substr(pos1, pos2-pos1));

        pos1 = pos2 + delimiter.size();
        pos2 = str.find(delimiter, pos1);
    }
    if (pos1 != str.length()) {
        tokens_ptr->push_back(str.substr(pos1));
    }
    return true;
}

void TestStringHelper() {
    std::string a = " 123  ";
    std::string* a_ptr = &a;
    utilscpp::StringHelper().Trim(a_ptr);
    std::cout << *a_ptr << std::endl;

    std::cout << std::endl;

    std::string b = "123^456^789";
    std::string d = "^";
    std::vector<std::string> vec;
    std::vector<std::string>* vec_ptr = &vec;
    utilscpp::StringHelper().Split(b, d, vec_ptr);
    for (int i = 0; i < vec_ptr->size(); ++i) {
        std::cout << (*vec_ptr)[i] << std::endl;
    }
}

}  // namespace utilscpp
