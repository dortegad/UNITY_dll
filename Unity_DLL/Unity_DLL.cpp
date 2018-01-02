#include "opencv2\core\core.hpp",
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\objdetect.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace cv;

extern "C" int __declspec(dllexport) __stdcall  Init(char *name, int& outCameraWidth, int& outCameraHeight, char* data)
{
	//cv::Mat img = cv::imread("c:\\imagen.jpg");
	//cv::imshow("prueba", img);

	cv::Size size(outCameraWidth, outCameraHeight);
	//cv::Mat importImage = cv::Mat(size, CV_8UC3, cv::Scalar(0, 0, 255));// data).clone();
	cv::Mat importImage = cv::Mat(size, CV_8UC3, data);// .clone();
	cv::cvtColor(importImage, importImage, cv::COLOR_RGB2BGR);
	//cv::resize(importImage, importImage, cv::Size(outCameraWidth / 4, outCameraHeight / 4));
	cv::flip(importImage, importImage, 0);
	cv::imshow(name, importImage);

	return 0;
}