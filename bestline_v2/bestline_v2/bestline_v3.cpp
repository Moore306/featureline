//#include<iostream>  
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>  
//#include <opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;
////#include  <direct.h>
//#include <fstream>
//#define FILENAME "scenel.bmp"
//int main()
//{
//	/*char   buffer[100]; 
//	getcwd(buffer, 100);
//	printf( "The   current   directory   is:   %s ",   buffer); */
//	//��ӡ��E:/C++/cppTest/cppPrimerTest
//	//#include <math.h>
//	
//	//fstream file;
//	//file.open(FILENAME,ios::in);
//	//if(file)
//	//{
//	//	cout<<FILENAME<<"û�б�����";
//	//	return -1;
//	//}
//	Mat imgl=imread("scenel.bmp");
//	Mat imgr=imread("scener5.bmp");
//	/*resize(imgl,imgl,Size(300,200));
//	resize(imgr,imgr,Size(300,200));*/
//	Mat timg_l;cvtColor(imgl, timg_l, CV_BGR2GRAY);
//	Mat timg_r;cvtColor(imgr, timg_r, CV_BGR2GRAY);
//	int H= imgl.rows;
//	int W= imgl.cols;
//
//	float tempE,minE;
//	
//	uchar *p1 = imgl.data;  // ����ָ��
//	uchar *p2 = imgr.data;  // ����ָ��
//	uchar *p3 = timg_l.data;
//	uchar *p4 = timg_r.data;
//	vector<vector<float> > imgr_l(H,vector<float>(W)); 
//	vector<vector<float> > imgg_l(H,vector<float>(W)); 
//	vector<vector<float> > imgb_l(H,vector<float>(W)); 
//	vector<vector<float> > imgr_r(H,vector<float>(W)); 
//	vector<vector<float> > imgg_r(H,vector<float>(W)); 
//	vector<vector<float> > imgb_r(H,vector<float>(W)); 
//	vector<vector<float> > img_l(H,vector<float>(W)); 
//	vector<vector<float> > img_r(H,vector<float>(W)); 
//	if(imgl.isContinuous())
//	{
//		
//		for (int i=0; i < H; i++) 
//			for (int j=0;j<W;j++){
//				imgb_l[i][j]=*p1++;
//				imgb_r[i][j]=*p2++;
//				imgg_l[i][j]=*p1++;
//				imgg_r[i][j]=*p2++;
//				imgr_l[i][j]=*p1++;
//				imgr_r[i][j]=*p2++;
//				img_l[i][j]=*p3++;
//				img_r[i][j]=*p4++;
//	       
//			} 
//	
//   
//	}
//	//imgl.release();
//	//imgr.release();
//	timg_r.release();
//	timg_l.release();
//	float Ecolor;
//	float Egeometry;
//	int a1,b1,c1,a2,b2,c2,y,color1,color2;
//	W=200;//�ص�������
//	float* Etotal=new float[W];
//	int **path=new int*[H];
//	for (int i=0;i<H;i++){
//		path[i]=new int[W];
//		
//	}
//	
//	for (int i=0;i<W;i++){
//		Etotal[i]=0;
//
//	}
//	
//	//ɫ��=������ɫ��Ӧͨ��ɫ�ײ�������ֵ-������ɫ��Ӧͨ��ɫ�ײ�ĸ���Сֵ��
//	//���û����ֵ��ֵ���������ֵ�����ֵ��0�ơ�ʵ����Ҳ����ĳ����ɫƫ��ȡ��ɫ�����Χ����������͸��򣩡�
//	//��һ�г�ʼ�� 
//	int first;//�����ж��Ƿ��ǵ�һ�θ�ֵ
//	for(int i=0;i<1;i++)
//	{
//		for (int j=0;j<W;j++)
//		{
//				
//			y=j;
//			a1=imgr_l[i][y];b1=imgg_l[i][y];c1=imgb_l[i][y];
//			a2=imgr_r[i][j];b2=imgg_r[i][j];c2=imgb_r[i][j];
//			color1=max(max(a1-a2,b1-b2),c1-c2)<0? 0:max(max(a1-a2,b1-b2),c1-c2);
//			color2=min(min(a1-a2,b1-b2),c1-c2)>0? 0:min(min(a1-a2,b1-b2),c1-c2);
//			Ecolor=(color1-color2)*(color1-color2);
//			if(j==0)
//			{
//				Egeometry=((img_l[0][y+1]+2*img_l[1][y+1])-(img_r[0][j+1]+2*img_r[1][j+1]))*
//				(-(img_l[1][y]+2*img_l[1][y+1])+(img_r[1][j]+2*img_r[1][j+1]));
//			}
//			else if(j==W-1){
//				Egeometry=(-(img_l[0][y-1]+2*img_l[1][y-1])+(img_r[0][j-1]+2*img_r[1][j-1]))*
//				(-(img_l[1][y]+2*img_l[1][y-1])+(img_r[1][j]+2*img_r[1][j-1]));
//			}
//			else{
//				Egeometry=((img_l[0][y+1]+2*img_l[1][y+1])-(img_l[0][y-1]+2*img_l[1][y-1])-(img_r[0][j+1]+2*img_r[1][j+1]-img_r[0][j-1]-2*img_r[1][j-1]))*
//				(-(img_l[1][y]+2*img_l[1][y-1]+2*img_l[1][y+1])+(img_r[1][j]+2*img_r[1][j-1]+2*img_r[1][j+1]));
//			}
//			Etotal[j]=Ecolor+abs(Egeometry);
//			path[0][j]=j;
//		}
//	}
//	for(int k=0;k<W;k++)
//		//��k��·��
//	{
//		for (int i=1;i<H;i++)
//			
//		{
//			first=0;
//			for (int j=path[i-1][k]-1;j<path[i-1][k]+2;j++)
//			{
//				
//				if(j<0||j>W-1)
//					continue;
//				y=W-W+j;
//				a1=imgr_l[i][y];b1=imgg_l[i][y];c1=imgb_l[i][y];
//				a2=imgr_r[i][j];b2=imgg_r[i][j];c2=imgb_r[i][j];
//				color1=max(max(a1-a2,b1-b2),c1-c2)<0? 0:max(max(a1-a2,b1-b2),c1-c2);
//				color2=min(min(a1-a2,b1-b2),c1-c2)>0? 0:min(min(a1-a2,b1-b2),c1-c2);
//				Ecolor=(color1-color2)*(color1-color2);
//				if(j==0&&i<=H-2){
//					 Egeometry=((2*img_l[i-1][y+1]+img_l[i][y+1]+2*img_l[i+1][y+1])-(2*img_r[i-1][j+1]+img_l[i][j+1]+2*img_l[i+1][j+1]))*
//						 ((img_l[i-1][y]+2*img_l[i-1][y+1]-img_l[i+1][y]-2*img_l[i+1][y+1])-(img_r[i-1][j]+2*img_r[i-1][j+1]-img_r[i+1][j]-2*img_r[i+1][j+1]));
//				}
//				else  if(j==W-1&&i<=H-2){
//					Egeometry=(-(2*img_l[i-1][y-1]+img_l[i][y-1]+2*img_l[i+1][y-1])+(2*img_r[i-1][j-1]+img_r[i][j-1]+2*img_r[i+1][j-1]))*
//						((2*img_l[i-1][y-1]+img_l[i-1][y]-2*img_l[i+1][y-1]-img_l[i+1][y])-(2*img_r[i-1][j-1]+img_r[i-1][j]-2*img_r[i+1][j-1]-img_r[i+1][j]));
//				}
//				else if(i<=H-2){
//					Egeometry=(2*img_l[i-1][y+1]+img_l[i][y+1]+2*img_l[i+1][y+1]-2*img_l[i-1][y-1]-img_l[i][y-1]-2*img_l[i+1][y-1]-
//						(2*img_r[i-1][j+1]+img_r[i][j+1]+2*img_r[i+1][j+1]-2*img_r[i-1][j-1]-img_r[i][j-1]-2*img_r[i+1][j-1]))*
//						(2*img_l[i-1][y-1]+img_l[i-1][y]+2*img_l[i-1][y+1]-2*img_l[i+1][y-1]-img_l[i+1][y]-2*img_l[i+1][y+1]-
//						(2*img_r[i-1][j-1]+img_r[i-1][j]+2*img_r[i-1][j+1]-2*img_r[i+1][j-1]-img_r[i+1][j]-2*img_r[i+1][j+1]));
//				}
//				else if(j==0){
//					Egeometry=(2*img_l[i-1][y+1]+img_l[i][y+1]-(2*img_r[i-1][j+1]+img_r[i][j+1]))*
//						(img_l[i-1][y]+2*img_l[i-1][y+1]-(img_r[i-1][j]+2*img_r[i-1][j+1]));
//				}
//				else if(j==W-1){
//					Egeometry=(-2*img_l[i-1][y-1]-img_l[i][y-1]+2*img_r[i-1][y-1]+img_r[i][y-1])*
//						(2*img_l[i-1][y-1]+img_l[i-1][y]-2*img_r[i-1][j-1]-img_r[i-1][j]);
//				}
//				else{
//					Egeometry=(2*img_l[i-1][y+1]+img_l[i][y+1]-2*img_l[i-1][y-1]-img_l[i][y-1]-(2*img_r[i-1][j+1]+img_r[i][j+1]-2*img_r[i-1][j-1]-img_r[i][j-1]))*
//						(img_l[i-1][y-1]*2+img_l[i-1][y]+img_l[i-1][y+1]*2-2*img_r[i-1][y-1]-img_r[i-1][y]-2*img_r[i-1][y+1]);
//				}
//				tempE=Ecolor+Egeometry;
//				if (first==0)
//					minE=tempE;
//				if(tempE<=minE){
//                  minE=tempE;
//				  path[i][k]=j;
//				  first=1;
//				}
//			    
//			}
//		    Etotal[k]=Etotal[k]+minE;
//		}
//
//		
//	}
//	minE=Etotal[0];
//	int num=0;
//	for(int k=1;k<W;k++)
//	{
//		tempE=Etotal[k];
//		if(tempE<minE)
//		{
//			minE=tempE;
//			num=k;
//		}
//
//	}
//	cout<<"minE= "<<minE<<"mum="<<num<<endl;
//	
//	Mat mask = Mat::zeros(cv::Size(2*W-W,H),CV_8UC3); //3ͨ��ÿ������Ԫ�ذ���3��ucharֵ
//	Mat stiching = mask.clone();
//	for(int i=0;i<H;i++)
//	{
//		cout<<path[i][num]<<endl;
//		for(int j=0;j<W*2-W;j++)
//		{
//			if(j<(W-W+path[i][num]))
//			{
//			 mask.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
//			 stiching.at<Vec3b>(i, j)=imgl.at<Vec3b>(i, j);
//			}
//			else
//			   stiching.at<Vec3b>(i,j)=imgr.at<Vec3b>(i, j-W+W);
//		}
//		/*for(int j=0;j<(W-W+path[i][num]);j++)
//		{
//
//			
//				mask.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
//				stiching.at<Vec3b>(i, j)=imgl.at<Vec3b>(i, j);
//
//		}*/
//	}
//	imshow("Lena Modified", mask);
//	imshow("stiching",stiching);
//	imwrite("mask.jpg",mask);
//	imwrite("stiching.jpg",stiching);
//	cvWaitKey();
//	system("pause");
//	return 0;
//}
