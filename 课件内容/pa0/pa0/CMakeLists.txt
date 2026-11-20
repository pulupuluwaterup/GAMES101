cmake_minimum_required(VERSION 3.10)
project(Transformation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

# 仅当本项目单独配置时设置启动项目（被主工程包含时由主工程统一决定）
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Transformation)
endif()

add_executable(Transformation main.cpp)

# Windows特定设置
if(WIN32)
    # 确保在Windows上正确处理控制台应用，F5 调试时工作目录为源码目录
    set_target_properties(Transformation PROPERTIES
        WIN32_EXECUTABLE OFF
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
endif()

target_link_libraries(Transformation PRIVATE Eigen3::Eigen)

# main.cpp 使用 #include <eigen3/Eigen/...>，而 Eigen3::Eigen 的
# 包含目录是 include/eigen3，故需追加上级 include 目录
get_target_property(_eigen3_include Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(Transformation PRIVATE ${_eigen3_include}/..)
