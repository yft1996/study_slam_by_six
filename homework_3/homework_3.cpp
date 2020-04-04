/**
 * @author 空想
 * @date 2020-4-4
 * @descp  c++ 新特性
 *              auto关键字
 *              lambda表达式等
 */
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

bool cmp(Point2i pt1, Point2i pt2)
{
    if(pt1.x != pt2.x)return pt1.x < pt2.x;
    if(pt1.y != pt2.y)return pt1.y < pt2.y;
}

int main()
{
    vector<Point2i> vec;
    vec.push_back(Point2i(2, 1));
    vec.push_back(Point2i(3, 3));
    vec.push_back(Point2i(2, 3));
    vec.push_back(Point2i(3, 2));
    vec.push_back(Point2i(3, 1));
    vec.push_back(Point2i(1, 3));
    vec.push_back(Point2i(1, 1));
    vec.push_back(Point2i(2, 2));
    vec.push_back(Point2i(1, 2));

    cout << "Before sort: " << endl;
    for(auto i:vec)
    {
        cout << i << endl;
    }

    sort(vec.begin(), vec.end(), cmp);

    cout << "After sort: " << endl;
    for(auto i:vec)
    {
        cout << i << endl;
    }

    return 0;
}
