cmake_minimum_required(VERSION 3.10)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
