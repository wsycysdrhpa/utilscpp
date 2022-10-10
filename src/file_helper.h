/*************************************************************************
 @Version: 
 @CreatedBy: 
 @UpdatedTime: 
 @Copyright (c) 
 @Description:
 ************************************************************************/


#ifndef SRC_UTILSCPP_FILE_HELPER_H_
#define SRC_UTILSCPP_FILE_HELPER_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>


namespace utilscpp {

class FileHelper {
 public:
    FileHelper() {}
    ~FileHelper() {}

    /*!
     *
     * @param path : In file path
     * @param vector : The container
     * @return
     */
    static bool FileToVector(const std::string& path, std::vector<std::string>* vec_ptr);

    /*!
     *
     * @param path : In file path
     * @param umap : The container
     * @return
     */
    static bool FileToUmap(const std::string& path, std::unordered_map<std::string, float>* umap_ptr);
};

void TestFileHelper();

}  // namespace utilscpp

#endif  // SRC_UTILSCPP_FILE_HELPER_H_
