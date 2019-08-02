#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;

int main(void)
{

	Mat image = imread("../../../samples/data/lena.jpg");
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);
	imshow("Linear Blend", gray);
	waitKey(0);
	//![display]

	return 0;
}