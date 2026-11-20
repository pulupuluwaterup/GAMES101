cmake_minimum_required(VERSION 3.10)
project(Assignment3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 仅当本项目单独配置时设置启动项目（被主工程包含时由主工程统一决定）
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Assignment3)
endif()

# 原框架的可执行项目名 Rasterizer 与主工程重名，合并后统一叫 Assignment3
add_executable(Assignment3
    main.cpp
    rasterizer.hpp
    rasterizer.cpp
    global.hpp
    Triangle.hpp
    Triangle.cpp
    Texture.hpp
    Texture.cpp
    Shader.hpp
    OBJ_Loader.h
)

target_link_libraries(Assignment3 PRIVATE
    ${OpenCV_LIBRARIES}
    Eigen3::Eigen
)

# 源码使用 #include <eigen3/Eigen/...>，而 Eigen3::Eigen 的包含目录是 include/eigen3，
# 故需追加上级 include 目录
get_target_property(_eigen3_include Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(Assignment3 PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${_eigen3_include}/..
)

# Windows特定设置
if(WIN32)
    # 模型/贴图路径是相对路径 ../models/spot/...（官方框架约定从构建目录运行），
    # 调试工作目录需为 Code 下的子目录，才能解析到 Code/models/；
    # output.png 也会输出到这里，不污染源码目录
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
    set_target_properties(Assignment3 PROPERTIES
        WIN32_EXECUTABLE OFF
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    )
endif()
