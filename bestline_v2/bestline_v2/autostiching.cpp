//#include <iostream>
//#include <fstream>
//#include <opencv2/core/core.hpp>
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/stitching/stitcher.hpp"
//#include<Windows.h>
//
//using namespace std;
//using namespace cv;
//
//bool try_use_gpu = false;
//vector<Mat> imgs;
//string result_name = "result.jpg";
//vector<vector<Rect>> rects;
//vector<Rect> rect1,rect2;
//
//int main()
//{
//	Mat img;
//	/*Mat img1=imread("10.jpg");
//	Mat img2=imread("11.jpg");
//	imgs.push_back(img1);
//	imgs.push_back(img2);*/
//	
//	/*Rect rt(1400,0,520,1080);
//	img=imread("11.bmp");
//	img(rt).copyTo(roiimg);
//	imshow("idiosa",roiimg);
//	waitKey();*/
//	
//	//char filename[100]="11.bmp";
//	//for(int i=4;i<6;i++)
//	//{
//	//	filename[1]='0'+i;
//	//	img=imread(filename);
//	//	/*rect1.push_back(Rect(0,0,1920,1080));
//	//	rect2.push_back(Rect(0,0,1920,1080));*/
//	//	
//	//	resize(img,img,Size(600,400));
//	//	imgs.push_back(img);
//	//}
//	img=imread("imgl.jpg");
//	imgs.push_back(img);
//	img=imread("imgr.jpg");
//	imgs.push_back(img);
//
//	rects.push_back(rect1);
//	rects.push_back(rect2);
//	Mat pano;
//	Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
//	Stitcher::Status status = stitcher.stitch(imgs, pano);
//	//Sticher::stitch(InputArray images, const std::vector<std::vector<Rect>>& rois, OutputArray pano)
//	//Stitcher::Status status=stitcher.stitch(imgs,rects, pano);
//	if (status != Stitcher::OK)
//	{
//		cout << "Can't stitch images, error code = " << status << endl;
//		return -1;
//	}
//	namedWindow(result_name);
//	imshow(result_name,pano);
//	imwrite(result_name,pano);
//	waitKey();
//	return 0;
//
//}