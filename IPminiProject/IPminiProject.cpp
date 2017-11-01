#include <iostream>
#include <string>
#include "stdafx.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

// declare function before main()
Mat resize(string path, int width, int height);

int main(int argc, char *argv[]) {
	
	for (int i = 1; i < argc; i += 3) { // process each image inputted through command line
		string fileName = argv[i];
		// stoi - string to int 
		int width = stoi(argv[i + 1]);
		int height = stoi(argv[i + 2]);

		Mat resizedImage = resize(fileName, width, height); // pass fileName into resize function to produce resized version of that image
		imshow(fileName, resizedImage);
		break;
	}
	
	// exit application when key pressed
	waitKey(0);
	return 0;
}

Mat resize(string path, int width, int height) {
	Mat image = imread(path); // load image with inputted file path
	Mat scaledImage(width, height, CV_8UC3); // CV_8U == 8-bit uchar

	imshow("original", image);

	cout << "----------" << endl;
	cout << "Processing: " << path << ", " << "[" << image.cols << ", " << image.rows << "]" << " " << image.type() << endl;
	cout << "New size: " << "[" << width  << ", " << height << "]" << endl;
	
	double xFactor, yFactor;

	xFactor = (double) width / (double) image.cols;
	yFactor = (double) height / (double) image.rows;

	cout << "Scale factors: " << "[" << xFactor << ", " << yFactor << "]" << endl;

	for (int i = 0; i < image.cols; i++) {
		for (int j = 0; j < image.rows; j++) {
			int x = i * xFactor;
			int y = j * yFactor;

			// cout << scaledImage.at<uchar>(x, y) << " ";// = image.at<uchar>(i, j);
			// cout << image.at<uchar>(i, j) << " ";
			// scaledImage.at<Vec3f>(x, y) = Vec3f(0, 0, 0);
			scaledImage.at<uchar>(x, y) = image.at<uchar>(i, j);
		}
	}

	return scaledImage;
}

