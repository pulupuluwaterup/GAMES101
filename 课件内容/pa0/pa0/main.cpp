#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main(){

    // Basic Example of cpp
	Eigen::Vector3f PointP(2.0f, 1.0f, 1.0f);
    std::cout << "点P坐标: (" << PointP(0) << ", " << PointP(1) << ", " << PointP(2) << ")" << std::endl;

    // Example of vector
    std::cout << "旋转矩阵 \n";
    const float angle_deg = 45.0f;  // 旋转角度，可修改为任意角度
    const float angle_rad = angle_deg * std::acos(-1.0f) / 180.0f;

    const float cos_angle = std::cos(angle_rad);
    const float sin_angle = std::sin(angle_rad);
	Eigen::Matrix3f RotationMatrix;
    RotationMatrix << cos_angle, -sin_angle, 1.0f,
        sin_angle, cos_angle, 2.0f,
        0.0f, 0.0f, 1.0f;
    // vector output
    Eigen::Vector3f VextorA(1, 2, 0);
	std::cout << "平移向量:(" << VextorA[0] << ", " << VextorA[1] << ", " << VextorA[2] << ")" << std::endl;
    Eigen::Vector3f TransformedPoint = RotationMatrix * PointP;
    std::cout << "Transformed point: ("
        << TransformedPoint.x() << ", "
        << TransformedPoint.y() << ", "
        << TransformedPoint.z() << ")" << std::endl;
    // matrix add i + j
    // matrix scalar multiply i * 2.0
    // matrix multiply i * j
    // matrix multiply vector i * v

    return 0;
}