#include "match.h"
int min_path(Mat &img1,Point start,Point end)
{
	int height,width;
	height=img1.rows;
	width=img1.cols;
	Mat Img;
	/*circle(img1,start,5,Scalar(0,0,255));
	circle(img1,end,5,Scalar(0,0,255));
	line(img1,start,end,Scalar(0,0,255));*/
	cvtColor(img1, Img, CV_RGB2GRAY);
	namedWindow("Img", WINDOW_NORMAL );
	uchar *p1 = img1.data;  // Êý¾ÝÖ¸Õë
	int* temp_dis=new int[width];
	int* min_dis=new int[width];
	for*(int i=0;i<width;i++)
	for (int i=1;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			temp_dis*(temp_dis+i*width+j);
		}
	}
	
	imshow("Img",Img);
	//resizeWindow("Img",0.2*width,0.2*height);
	waitKey();
	return 0;
}