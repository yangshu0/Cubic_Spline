#include "cSpline.h"
#include "opencv2\opencv.hpp"

using namespace raven;

int main(int argc, char** argv) {

	std::vector<double> X(5), Y(5);
	X[0] = 0.1; X[1] = 0.4; X[2] = 1.2; X[3] = 1.8; X[4] = 2.0;
	Y[0] = 0.1; Y[1] = 0.7; Y[2] = 0.6; Y[3] = 1.1; Y[4] = 0.9;

	cSpline spline(X, Y);

	int w = 640;
	cv::Mat myImage = cv::Mat::zeros(w, w, CV_8UC3);
	
	double x1 = 0.1; 
	double y1 = 0.1;
	for (double x2 = 0; x2 < 2.2; x2 += 0.02) {
		double y2 = spline.getY(x2);
		std::cout << x2 << ":" << y2 << std::endl;
		cv::line(myImage, cv::Point(x1 * w / 3, y1 * w / 3), cv::Point(x2 * w / 3, y2 * w / 3), cv::Scalar(0, 255, 0), 2, 0);
		std::cout << x1 * w / 2 << ":" << y1 * w / 2 << std::endl;
		x1 = x2;
		y1 = y2;
	}

	for (int k = 0; k < X.size(); k++) {
		cv::circle(myImage, cv::Point(X[k] * w / 3, Y[k] * w / 3), 4, cv::Scalar(255, 0, 0), 3);
	}

	cv::imshow("image", myImage);
	cv::waitKey();
}