#include<iostream>
#include<opencv2/opencv.hpp>
#include<algorithm>
using namespace cv;
using namespace std;

int main()
{
	Mat src;
	src=imread("image.tiff",CV_LOAD_IMAGE_GRAYSCALE);
	
	namedWindow("Original Grayscale",WINDOW_NORMAL);
	imshow("Original Grayscale",src);
	
	float count[256];
	for(int i=0;i<256;i++)
	{
		count[i]=0;
	}
	for(int y=0;y<src.cols;y++)
	{
		for(int x=0;x<src.rows;x++)
		{
			count[(int)src.at<uchar>(y,x)]++;
		}
	}
	float maxi=0;
	for(int i=0;i<256;i++)
	{
		maxi=max(maxi,count[i]);
	}
	float factor=400/maxi;
	Scalar col;
	col =Scalar(128,128,128);
	Mat hist=Mat::zeros(500,400,src.type());
	for(int i=0;i<256;i++)
	{
		int length=factor*count[i];
		int yfirst=450;
		int ysecond=450-length;
		int xshift=50;
		line(hist,Point(xshift+i,yfirst),Point(xshift+i,ysecond),col);
	}
	
	namedWindow("Histogram",WINDOW_NORMAL);
	imshow("Histogram",hist);
	
	waitKey(0);
	return 0;
}
