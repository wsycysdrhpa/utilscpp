/*************************************************************************
 @Version: 1.0
 @CreatedBy: Aruan
 @UpdatedTime: '2021/5/26'
 @Copyright (c) 2021 ke Inc. All rights reserved.
 @Description:
 ************************************************************************/


#include "utilscpp/file_helper.h"

#include <stdlib.h>

#include <utility>

#include "utilscpp/string_helper.h"


namespace utilscpp {

bool FileHelper::FileToVector(const std::string& path, std::vector<std::string>* vec_ptr) {
    if (path.empty() || vec_ptr == nullptr) return false;
    std::ifstream fin(path.c_str());
    std::string line;
    while (getline(fin, line)) {
        utilscpp::StringHelper().Trim(&line);
        if (line.empty()) continue;
        vec_ptr->emplace_back(line);
    }
    fin.close();
    return true;
}

bool FileHelper::FileToUmap(const std::string& path, std::unordered_map<std::string, float>* umap_ptr) {
    if (path.empty() || umap_ptr == nullptr) return false;
    std::ifstream fin(path.c_str());
    std::string line;
    while (getline(fin, line)) {
        utilscpp::StringHelper().Trim(&line);
        if (line.empty()) continue;
        std::string d = "\t";
        std::vector<std::string> vec;
        std::vector<std::string>* vec_ptr = &vec;
        if (utilscpp::StringHelper().Split(line, d, vec_ptr)) {
            const char* val_c_str = (*vec_ptr)[1].c_str();
            float val = atof(val_c_str);
            (*umap_ptr).insert(std::make_pair((*vec_ptr)[0], val));
        }
    }
    fin.close();
    return true;
}

void TestFileHelper() {
    std::string path = "D:\\Code\\CPP\\test\\test_clion\\src\\utilscpp\\data\\in_file.txt";
    std::vector<std::string> vec;
    std::vector<std::string>* vec_ptr = &vec;
    utilscpp::FileHelper().FileToVector(path, vec_ptr);
    for (int i = 0; i < vec_ptr->size(); ++i) {
        std::cout << (*vec_ptr)[i] << std::endl;
    }

    std::cout << std::endl;

    std::string path_2 = "D:\\Code\\CPP\\test\\test_clion\\src\\utilscpp\\data\\in_file_2.txt";
    std::unordered_map<std::string, float> umap;
    std::unordered_map<std::string, float>* umap_ptr = &umap;
    utilscpp::FileHelper().FileToUmap(path_2, umap_ptr);
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        std::cout << iter->first << "\t"<< iter->second << std::endl;
    }

    std::cout << std::endl;
}

}  // namespace utilscpp
