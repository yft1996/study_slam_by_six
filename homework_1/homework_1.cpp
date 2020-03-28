/**
 * @author 空想
 * @date 2020-3-28
 * @descp   修改指定文件夹中的指定格式的文件的文件名为0000~9999并另存为到另一个文件夹中
 */

#include <iostream>
#include <boost/format.hpp>  
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc,char** argv)
{
    if(argc != 4)
    {
        cout << "Usage: ./homework_1 指定文件夹路径 另存为文件夹路径 待修改文件的文件格式后缀" << endl;
        exit(-1);
    }

    cv::String input_path = argv[1];
    cv::String output_path =  argv[2];
    cv::String image_format = argv[3];

    //设置输出文件名
    boost::format output_image_name("%s/%04d%s");

    //读取文件夹内文件名
    vector<cv::String> v_image_name;
    glob(input_path,v_image_name,false);

    int image_idx = 0;
    for(auto image_name : v_image_name)
    {
        //判断当前文件名是否含有指定图像格式后缀
        if(image_name.find(image_format) != cv::String::npos)
        {
            cout << "## 修改第" << image_idx << "幅图像的文件名 ##" << endl;
            //读取图片
            cv::Mat image = cv::imread( image_name );
            if(image.empty())
            {
                cerr << "## 读取第" << image_idx << "幅图像失败！ ##" << endl;
                image_idx ++ ;
                continue;
            }
            //写入图片
            cv::imwrite( (output_image_name%output_path%image_idx%image_format).str() , image );
            image_idx ++ ;
        }
    }
}
