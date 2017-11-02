#include "match.h"
int main()
{
	//读入图像  
	Mat imgl = imread("imgl.jpg");  
	Mat imgr = imread("imgr.jpg");  
	resize(imgl,imgl,Size(600,400));
	resize(imgr,imgr,Size(600,400));
	Mat img1=imgl.clone();
	Mat img2=imgr.clone();
	vector<Point2f> m_LeftInlier;
	vector<Point2f> m_RightInlier;
	//	Mat img2 = imread("imgr.jpg");  
	//	resize(img1,img1,Size(600,400));
	//	resize(img2,img2,Size(600,400));
	int num;
	num=match(img1,img2,m_LeftInlier,m_RightInlier);
	// 显示计算F过后的内点匹配
	Mat OutImage;
	/*drawMatches(img1, key1, img2, key2, m_InlierMatches, OutImage);
	cvNamedWindow( "Match features", 1);
	cvShowImage("Match features", &IplImage(OutImage));
	waitKey(0);
	
	cvDestroyAllWindows();*/
	
	//##################################################
	int leftmost1,rightmost1,leftmost2,rightmost2;
	leftmost1=rightmost1=m_LeftInlier[0].y;
	leftmost2=rightmost2=m_RightInlier[0].y;
	int leftmost_index,rightmost_index;
	leftmost_index=rightmost_index=0;
	for(int i=0;i<num;i++)
	{
		circle(img1,m_LeftInlier[i],5,Scalar(255,0,255));
		circle(img2,m_RightInlier[i],5,Scalar(255,0,255));
		if(leftmost1>m_LeftInlier[i].x)
		{
			leftmost1=m_LeftInlier[i].x;
			leftmost_index=i;
		}
		  
		if(rightmost1<m_LeftInlier[i].x)
		{
			rightmost1=m_LeftInlier[i].x;
			rightmost_index=i;
		}
	
		if(leftmost2>m_RightInlier[i].x)
			leftmost2=m_RightInlier[i].x;
		if(rightmost2<m_RightInlier[i].x)
			rightmost2=m_RightInlier[i].x;
	}
	line( img1, Point(leftmost1,0), Point(leftmost1,img1.rows), Scalar( 0, 255, 0), 1 );
	line( img1, Point(rightmost1,0), Point(rightmost1,img1.rows), Scalar( 0, 255, 0), 1 );
	line( img2, Point(rightmost2,0), Point(rightmost2,img2.rows), Scalar( 0, 255, 0), 1 );
	line( img2, Point(leftmost2,0), Point(leftmost2,img2.rows), Scalar( 0, 255, 0), 1 );
	
	//选取一个AB line 区域
	int move_N=158;
	int region_leftedge=leftmost1+move_N-10;
	int region_rightedge=region_leftedge+30;
	int first=0;
	line( img1, Point(region_leftedge,0), Point(region_leftedge,img1.rows), Scalar( 0, 0, 0), 1 );
	line( img1, Point(region_rightedge,0), Point(region_rightedge,img1.rows), Scalar( 0, 0, 0), 1 );

	//找到右图对应的特征点区域
	for(int i=0;i<num;i++)
	{
		
		if((m_LeftInlier[i].x>region_leftedge) && (m_LeftInlier[i].x<region_rightedge))
		{
			if(first==0){
				rightmost1=leftmost1=m_LeftInlier[i].x;
				rightmost_index=leftmost_index=i;
				first=1;
			}

			else {
					if(m_LeftInlier[i].x<leftmost1)
					{
						leftmost_index=i;
						leftmost1=m_LeftInlier[i].x;
	
					}
					if(m_LeftInlier[i].x>rightmost1)
					{
						rightmost_index=i;
						rightmost1=m_LeftInlier[i].x;
				
					}


			}
			
		}

	}
	leftmost2=m_RightInlier[leftmost_index].x;
	rightmost2=m_RightInlier[rightmost_index].x;
	line( img1, Point(leftmost1,0), Point(leftmost1,img1.rows), Scalar( 0, 255, 255), 1 );
	line( img1, Point(rightmost1,0), Point(rightmost1,img1.rows), Scalar( 0, 255, 255), 1 );
	line( img2, Point(rightmost2,0), Point(rightmost2,img2.rows), Scalar( 0, 255, 255), 1 );
	line( img2, Point(leftmost2,0), Point(leftmost2,img2.rows), Scalar( 0, 255, 255), 1 );
	
	
	
	Mat img(img1.rows,img1.cols+img2.cols,img1.type());
	img1.copyTo(img.colRange(0,img1.cols));
	img2.copyTo(img.colRange(img1.cols,img1.cols+img2.cols));
	
	
	imshow("dojjdoi",img);
	/*waitKey(0);*/

	/*Mat img11=imgl.colRange(leftmost1-10,rightmost1+10);
	Mat img22=imgr.colRange(leftmost2-10,rightmost2+10);


	imshow("jijio",img11);*/
	/*m_LeftInlier.clear();
	m_RightInlier.clear();
	num=match(img11,img22,m_LeftInlier,m_RightInlier);*/
	waitKey();
	return 0;
}