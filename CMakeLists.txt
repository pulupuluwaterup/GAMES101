cmake_minimum_required(VERSION 3.10)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源码含 UTF-8 中文注释，MSVC 默认按 GBK(936) 读取会误解析（吞行尾导致代码被注释掉），
# 统一按 UTF-8 编译
if(MSVC)
    add_compile_options(/utf-8)
endif()

# 查找依赖包
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 添加可执行文件
add_executable(Rasterizer
    main.cpp
    rasterizer.hpp
    rasterizer.cpp
    Triangle.hpp
    Triangle.cpp
)

# 链接库
target_link_libraries(Rasterizer PRIVATE
    ${OpenCV_LIBRARIES}
    Eigen3::Eigen
)

# 包含目录
target_include_directories(Rasterizer PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
)

# Windows特定设置
if(WIN32)
    # 确保在Windows上正确处理控制台应用
    set_target_properties(Rasterizer PROPERTIES
        WIN32_EXECUTABLE OFF
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
endif()

# ============ 各单元作业（同一个解决方案里各占一个可执行项目） ============
# pa0：Eigen 矩阵练习，纯控制台输出
add_subdirectory("课件内容/pa0/pa0")

# 第二课：三角形光栅化（z-buffer），弹图形窗口
add_subdirectory("课件内容/Assignment2/代码框架")

# 第三课：着色（纹理、Blinn-Phong、bump/displacement），弹图形窗口
add_subdirectory("课件内容/Assignment3/Code")

# 以后拿到新一课的作业代码后，放到对应目录再加一行 add_subdirectory 即可：
# add_subdirectory("课件内容/pa3/pa3")

# 解决方案默认启动项目（图形画面的那个）；做 pa0 作业时右键 Transformation → 设为启动项目
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Rasterizer)
