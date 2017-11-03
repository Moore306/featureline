#include"match.h"

int main()
{
	Mat imgl = imread("imgl.jpg");  
	//	Mat imgr = imread("imgr.jpg");  
	resize(imgl,imgl,Size(600,400));
	//	resize(imgr,imgr,Size(600,400));
	Point startpoint(imgl.cols/2,0);

	Point endpoint(imgl.cols/2,imgl.rows-1);
	min_path(imgl,startpoint,endpoint);

}