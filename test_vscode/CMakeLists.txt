cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)

message("test_vscode")
message(${CMAKE_CURRENT_SOURCE_DIR})
get_filename_component(fc_base "fc_base" REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
message(${fc_base})

include(CTest)
enable_testing()

# 更优雅的方式，使用FetchContent_Declare添加外部库
include_directories(
    # rapidjson
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/rapidjson/include
    # gflag
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/gflags/build/include
    # glog
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/glog/src
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/glog/build
    # boost
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/boost_1_80_0
)

link_directories(
    # gflag
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/gflags/build/lib/
    # glog
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/glog/build/
    # boost
    /nfsdata/sai_team/ruanhaipeng/tmp/test_cpp/3rd/boost_1_80_0/stage/lib
)

add_executable(main main.cpp)

target_link_libraries(main
    gflags_nothreads
    glog
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
