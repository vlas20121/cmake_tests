#include "opencv2/opencv_modules.hpp"
#include "opencv2/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    const int r = 100;
    Mat im = Mat::zeros(Size(4 * r, 4 * r), CV_8U);
    imwrite("im.jpg", im);

	cout << "Hello World!" << endl; 
	return 0; 
}

