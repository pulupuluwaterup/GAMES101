# GAMES101 - 光栅化器

这是 GAMES101 课程的光栅化器作业实现，所有单元作业整合在一个 VS 解决方案中。

## 项目结构

```
GAMES101/
├── CMakeLists.txt              # 顶层 CMake 配置（汇总所有作业）
├── main.cpp                    # pa1 主程序（光栅化器，图形窗口）
├── rasterizer.cpp/.hpp         # 光栅化器实现
├── Triangle.cpp/.hpp           # 三角形实现
├── build_sln/                  # VS 解决方案构建目录（唯一）
│   └── Rasterizer.sln          # 含全部作业项目的解决方案
└── 课件内容/
    ├── pa0/pa0/                # Transformation：Eigen 矩阵练习（纯控制台）
    ├── Assignment2/代码框架/    # 第二课：三角形光栅化（z-buffer）
    └── Assignment3/Code/        # 第三课：着色（纹理、Blinn-Phong、bump/displacement）
```

## 解决方案项目一览

| 项目 | 对应作业 | 输出 |
|---|---|---|
| Rasterizer | pa1 光栅化器 | `build_sln/Debug/Rasterizer.exe` |
| Transformation | pa0 Eigen 练习 | `build_sln/课件内容/pa0/pa0/Debug/Transformation.exe` |
| Assignment2 | 第二课三角形光栅化 | `build_sln/课件内容/Assignment2/代码框架/Debug/Assignment2.exe` |
| Assignment3 | 第三课着色 | `build_sln/课件内容/Assignment3/Code/Debug/Assignment3.exe` |

## 依赖项

- **Eigen3**: 线性代数库
- **OpenCV**: 图像处理库

（均由 vcpkg 安装，本机位于 `C:/Users/wuyi7/scoop/apps/vcpkg/2026.06.24/installed/x64-windows`）

## Windows 构建指南

### 方法1: VS2022 打开解决方案（推荐）

直接打开 `build_sln/Rasterizer.sln`，选好启动项目（做哪个作业就右键哪个项目 → 设为启动项目）按 F5 运行。

### 方法2: 命令行

```bash
cd GAMES101
cmake -B build_sln ^
  -DCMAKE_TOOLCHAIN_FILE=[vcpkg根目录]/scripts/buildsystems/vcpkg.cmake ^
  -DVCPKG_TARGET_TRIPLET=x64-windows ^
  -DCMAKE_PREFIX_PATH=[vcpkg根目录]/installed/x64-windows
cmake --build build_sln --config Debug
```

> 注意：三个参数缺一不可。只传 toolchain 时 vcpkg 的包查找可能不生效（找不到 OpenCV/Protobuf）。
> MSVC 需 `/utf-8` 编译选项（已在 CMakeLists 统一配置），所有源码文件请保存为 UTF-8 编码。

### 运行

```bash
# pa1 光栅化器：交互模式
./build_sln/Debug/Rasterizer.exe

# 命令行模式
./build_sln/Debug/Rasterizer.exe -r 45 output.png
```

## 功能说明

- **W/A/S/D**: 旋转三角形
- **ESC**: 退出程序
- 支持模型、视图、投影矩阵变换

## 学习笔记

见 [P0作业笔记.md](P0作业笔记.md)。

- [x] 旋转变换 (绕Z轴)
- [x] 投影变换 (透视投影)
- [ ] 光栅化算法

## 许可证

本项目仅用于学习目的，基于 GAMES101 课程作业。
