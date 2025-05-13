cmake_minimum_required(VERSION 3.30)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")


enable_testing()
include(CTest)

# 配置GoogleTest
# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     GIT_REPOSITORY https://github.com/google/googletest.git
#     GIT_TAG release-1.12.1
# )
# FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)

# 自动收集所有题目文件
file(GLOB PROBLEM_FILES "problems/*.cpp")

# 为每个题目创建测试可执行文件
foreach(problem_file ${PROBLEM_FILES})
    get_filename_component(problem_name ${problem_file} NAME_WE)
    
    add_executable(${problem_name}_test ${problem_file})
    target_link_libraries(${problem_name}_test 
        PRIVATE GTest::GTest GTest::Main)
        
    add_test(
        NAME ${problem_name}
        COMMAND ${problem_name}_test
    )
endforeach()

# 主程序（可选）
add_executable(leetcode main.cpp)