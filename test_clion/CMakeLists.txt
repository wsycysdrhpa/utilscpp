cmake_minimum_required(VERSION 3.15)
project(test_clion)

set(CMAKE_CXX_STANDARD 14)

include_directories("src")
#include_directories("../../thirdparty/jsoncpp/include")

# file(GLOB UTILSCPP_FILES "src/utilscpp/*")
file(GLOB UTILSCPP_FILES
#        "src/utilscpp/string_helper.*"
#        "src/utilscpp/file_helper.*"
#        "src/utilscpp/json_helper.*"
)

# lib search dir
# link_directories("../../thirdparty/jsoncpp/cmake-build-debug/lib")

add_executable(test_clion
        src/main.cpp
#        ${UTILSCPP_FILES}
)

# 将第三方库链接在一起
target_link_libraries(test_clion
#        libjsoncpp.a
)
