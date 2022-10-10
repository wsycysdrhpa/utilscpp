/*************************************************************************
 @Version: 
 @CreatedBy: 
 @UpdatedTime: 
 @Copyright (c) 
 @Description:
 ************************************************************************/


#ifndef SRC_UTILSCPP_STRING_HELPER_H_
#define SRC_UTILSCPP_STRING_HELPER_H_


#include <iostream>
#include <string>
#include <vector>


namespace utilscpp {

class StringHelper {
 public:
    StringHelper() {}
    ~StringHelper() {}

    /*!
     * 输入字符串，去除两边空格
     * @param str :
     * @return :
     */
    static bool Trim(std::string* str_ptr);
    static bool Split(const std::string& str, const std::string& delimiter, std::vector<std::string>* tokens_ptr);
};

void TestStringHelper();

}  // namespace utilscpp

#endif  // SRC_UTILSCPP_STRING_HELPER_H_
