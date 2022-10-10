cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

message("test_vscode")
message(${CMAKE_CURRENT_SOURCE_DIR})
# get_filename_component(fc_base "fc_base" REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
# message(${fc_base})

file(GLOB UTILS_FILES "src/utilscpp/*")

# 更优雅的方式，使用FetchContent_Declare添加外部库
include_directories(
    # gflag
    src/fc_base/gflags/build/include
    # glog
    src/fc_base/glog/src
    src/fc_base/glog/build
    # gtest
    src/fc_base/googletest/googletest/include
    src/fc_base/googletest/googlemock/include
    # boost
    src/fc_base/boost
    # absl
    src/fc_base/abseil-cpp
    # jsoncpp
    src/fc_base/jsoncpp/include
    # rapidjson
    src/fc_base/rapidjson/include
    # utilscpp etc.
    src
)

link_directories(
    # gflag
    fc_base/gflags/build/libs
    # glog
    src/fc_base/glog/build
    # boost
    src/fc_base/boost/stage/lib
    # gtest
    src/fc_base/googletest/build/lib
    # absl
    src/fc_base/abseil-cpp/build/absl/strings
    # jsoncpp
    src/fc_base/jsoncpp/build/lib
)

add_executable(main 
    src/main.cpp
    ${UTILS_FILES}
)

target_link_libraries(main
    gflags_nothreads
    glog
    gtest
    gtest_main
    # note: gtest need pthread
    pthread
    absl_strings
    jsoncpp
)

# enable_testing()
# include(GoogleTest)
# gtest_discover_tests(main)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
