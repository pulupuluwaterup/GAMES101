# GAMES101 - 光栅化器

这是GAMES101课程的光栅化器作业实现。

## 项目结构

```
GAMES101/
├── CMakeLists.txt      # CMake配置文件
├── main.cpp            # 主程序
├── rasterizer.cpp      # 光栅化器实现
├── rasterizer.hpp      # 光栅化器头文件
├── Triangle.cpp        # 三角形实现
├── Triangle.hpp        # 三角形头文件
└── 课件内容/            # 课程资料
```

## 依赖项

- **Eigen3**: 线性代数库
- **OpenCV**: 图像处理库

## Windows 构建指南

### 方法1: 使用 vcpkg (推荐)

1. 安装 vcpkg:
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

2. 安装依赖:
```bash
.\vcpkg install eigen3 opencv4
```

3. 配置项目:
```bash
cd GAMES101
cmake -B build -DCMAKE_TOOLCHAIN_FILE=[vcpkg根目录]/scripts/buildsystems/vcpkg.cmake
cmake --build build
```

### 方法2: 手动安装

1. 安装 Eigen3:
   - 下载: https://eigen.tuxfamily.org/
   - 解压到 `C:/eigen3`

2. 安装 OpenCV:
   - 下载: https://opencv.org/releases/
   - 解压到 `C:/opencv`

3. 配置项目:
```bash
cd GAMES101
cmake -B build -DEigen3_DIR=C:/eigen3 -DOpenCV_DIR=C:/opencv/build
cmake --build build
```

## 运行

```bash
# 交互模式
./build/Debug/Rasterizer.exe

# 命令行模式
./build/Debug/Rasterizer.exe -r 45 output.png
```

## 功能说明

- **W/A/S/D**: 旋转三角形
- **ESC**: 退出程序
- 支持模型、视图、投影矩阵变换

## 学习笔记

本项目实现了:
- [ ] 旋转变换 (绕Z轴)
- [ ] 投影变换 (透视投影)
- [ ] 光栅化算法

## 许可证

本项目仅用于学习目的，基于GAMES101课程作业。
