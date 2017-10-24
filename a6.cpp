/*
How to run
Just fire g++ filename `pkg-config --cflags --libs opencv`



*/
#include <iostream>
#include "opencv2/opencv.hpp"
#include <algorithm>

using namespace cv;
using namespace std;

int main(){

Mat gimage,cimage;
//image = imread("/home/cl-1/4101/as6/tiff.tiff", CV_LOAD_COLOR);
gimage = imread("/home/hp/Desktop/final/B12/Lenna.png", CV_LOAD_IMAGE_GRAYSCALE);   // or use 0
cimage = imread("tiff.tiff",CV_LOAD_IMAGE_COLOR);		//or use >0
/*
if(! gimage.data )                              // Check for invalid input
*/
namedWindow( "GDisplay window",WINDOW_NORMAL);// Create a window for display.
imshow( "GDisplay window", gimage );                   // Show our image inside it.
/*
resizeWindow("GDisplay window",400,400);		//Resize a window
*/

float count[256];
for(int i=0;i<256;i++)
	count[i]=0;

for(int y=0;y<gimage.rows;y++)
	for(int x=0;x<gimage.cols;x++)
		count[(int)gimage.at<uchar>(y,x)]++;

float maxi=0;
for(int i=0;i<256;i++){
	maxi=max(maxi,count[i]);
}

float factor=400/maxi;
Scalar col;
col=Scalar(255,255,255);


Mat hist = Mat::zeros( 500,400, gimage.type());
for(int i=0;i<256;i++){
	int length=factor*count[i];
	int yfirst=450;
	int ysecond=450-length;
	int xshift=50;
	line(hist,Point(xshift+i,yfirst),Point(xshift+i,ysecond),col);
}

namedWindow("Histogram",WINDOW_NORMAL);
imshow("Histogram",hist);


waitKey(0);                                          // Wait for a keystroke in the window
return 0;

}
