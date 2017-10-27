#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src=imread("img.jpg",CV_LOAD_IMAGE_COLOR);
	int size=src.rows*src.cols;

	namedWindow("Source Image",CV_WINDOW_AUTOSIZE);
	namedWindow("Gray Scale Conversion",CV_WINDOW_AUTOSIZE);
	namedWindow("Normal Histogram",CV_WINDOW_AUTOSIZE);
	namedWindow("Eq-Histogram WITHOUT CV",CV_WINDOW_AUTOSIZE);
	namedWindow("Eq-Histogram WITH CV",CV_WINDOW_AUTOSIZE);
	namedWindow("Equalized Image",CV_WINDOW_AUTOSIZE);

	imshow("Source Image",src);
	cvtColor(src,src,CV_BGR2GRAY);
	imshow("Gray Scale Conversion",src);

	Mat hist=Mat::zeros(1,256,CV_32SC1); //32 bit SC=signed integer 1=No of channels

	for(int i=0;i<src.rows;i++)
	{
		for(int j=0;j<src.cols;j++)
		{
			hist.at<int>((int)src.at<uchar>(i,j))+=1;
		}
	}

	//Histogram Equalization using manual process //
	float sum=0.0;
	float temp[256];
	Mat eq_hist=Mat::zeros(1,256,CV_32SC1);
	for(int i=0;i<256;i++)
	{
		temp[i]=(float)(hist.at<int>(i))/(float)size;
		sum+=temp[i];
		temp[i]=sum*(float)255;
		temp[i]=(floor)(temp[i]+0.5);
		eq_hist.at<int>(int(temp[i]))+=hist.at<int>(i);
	}
	//Histogram Equalization using manual process //

	//Histogram Equalization using OpenCV functions//
	Mat eq_img;
	equalizeHist(src,eq_img);
	Mat eq_hist_cv=Mat::zeros(1,256,CV_32SC1);
	for(int i=0;i<eq_img.rows;i++)
	{
		for(int j=0;j<eq_img.cols;j++)
		{
			eq_hist_cv.at<int>((int)eq_img.at<uchar>(i,j))+=1;
		}
	}
	//Histogram Equalization using OpenCV functions//
	imshow("Equalized Image",eq_img);
	
	normalize(hist,hist,0,256,NORM_MINMAX,-1,Mat());
	normalize(eq_hist,eq_hist,0,256,NORM_MINMAX,-1,Mat());
	normalize(eq_hist_cv,eq_hist_cv,0,256,NORM_MINMAX,-1,Mat());
	
	Mat canvas1(300,256,CV_8UC1);
	for(int i=0;i<256;i++)
	{
		line(canvas1,Point(i,299),Point(i,300-hist.at<int>(i)),Scalar(128,128,128));
	}
	imshow("Normal Histogram",canvas1);

	Mat canvas2(300,256,CV_8UC1);
	for(int i=0;i<256;i++)
	{
		line(canvas2,Point(i,299),Point(i,300-eq_hist.at<int>(i)),Scalar(128,128,128));
	}
	imshow("Eq-Histogram WITHOUT CV",canvas2);

	Mat canvas3(300,256,CV_8UC1);
	for(int i=0;i<256;i++)
	{
		line(canvas3,Point(i,299),Point(i,300-eq_hist_cv.at<int>(i)),Scalar(128,128,128));
	}
	imshow("Eq-Histogram WITH CV",canvas3);

	waitKey(0);
	return 0;
}
