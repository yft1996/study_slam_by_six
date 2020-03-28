/**
 * @author 空想
 * @date 2020-3-28
 * @descp  已知相机的位姿用四元数表示为q=[0.35,0.2,0.3,0.1],顺序为x,y,z,w，请编程实现：
 *         输出四元数对应的旋转矩阵，
 *         旋转矩阵的转置，
 *         旋转矩阵的逆矩阵，
 *         旋转矩阵乘以自身的转置，验证旋转矩阵的正交性。
 */

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;
int main(int argc,char ** argv)
{
    Eigen::Quaterniond quat;

    //Eigen 中四元数  qw,qx,qy,qz
    //三维旋转用单位四元数来描述
    quat = Eigen::Quaterniond(0.1,0.35,0.2,0.3).normalized();
    cout << quat.coeffs() << endl;

    cout << "四元数对应的旋转矩阵：" << endl;
    Eigen::Matrix3d rotation = Eigen::Matrix3d(quat);
    cout << rotation << endl;

    cout << "旋转矩阵的转置：" << endl;
    cout << rotation.transpose() << endl;

    cout << "旋转矩阵的逆矩阵：" << endl;
    cout << rotation.inverse() << endl;

    cout << "旋转矩阵乘以自身的转置：" << endl;
    cout << rotation * rotation.transpose() << endl;

    return 0;
}