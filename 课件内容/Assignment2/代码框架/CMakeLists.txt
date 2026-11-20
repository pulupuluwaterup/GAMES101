cmake_minimum_required(VERSION 3.10)
project(Assignment2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 仅当本项目单独配置时设置启动项目（被主工程包含时由主工程统一决定）
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Assignment2)
endif()

# 原框架的可执行项目名 Rasterizer 与主工程重名，合并后统一叫 Assignment2
add_executable(Assignment2
    main.cpp
    rasterizer.hpp
    rasterizer.cpp
    global.hpp
    Triangle.hpp
    Triangle.cpp
)

target_link_libraries(Assignment2 PRIVATE
    ${OpenCV_LIBRARIES}
    Eigen3::Eigen
)

# 源码使用 #include <eigen3/Eigen/...>，而 Eigen3::Eigen 的包含目录是 include/eigen3，
# 故需追加上级 include 目录
get_target_property(_eigen3_include Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(Assignment2 PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${_eigen3_include}/..
)

# Windows特定设置
if(WIN32)
    set_target_properties(Assignment2 PROPERTIES
        WIN32_EXECUTABLE OFF
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
endif()
