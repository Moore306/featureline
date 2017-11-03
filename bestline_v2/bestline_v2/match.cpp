#include "match.h"



int match(Mat &img1,Mat &img2,vector<Point2f>& m_LeftInlier,vector<Point2f> &m_RightInlier)
{
	initModule_nonfree();//��ʼ��ģ�飬ʹ��SIFT��SURFʱ�õ� 
	Ptr<FeatureDetector> detector = FeatureDetector::create( "SURF" );//����SIFT������������ɸĳ�SURF/ORB
	/*int minHessian = 400;
	Ptr<SURF> detector = SURF::create()*/
	Ptr<DescriptorExtractor> descriptor_extractor = DescriptorExtractor::create( "SURF" );//���������������������ɸĳ�SURF/ORB
	Ptr<DescriptorMatcher> descriptor_matcher = DescriptorMatcher::create( "BruteForce" );//��������ƥ����  
	if( detector.empty() || descriptor_extractor.empty() )  
		cout<<"fail to create detector!";  

	
	
	//��������  
	double t = getTickCount();//��ǰ�δ���  
	vector<KeyPoint> m_LeftKey,m_RightKey;  
	detector->detect( img1, m_LeftKey );//���img1�е�sift�����㣬�洢��m_leftkey��  
	detector->detect( img2, m_RightKey );  

	//#################################################

	cout<<"ͼ��1���������:"<<m_LeftKey.size()<<endl;  
	cout<<"ͼ��2���������:"<<m_RightKey.size()<<endl;  

	//����������������������Ӿ��󣬼�������������  
	Mat descriptors1,descriptors2;  
	descriptor_extractor->compute( img1, m_LeftKey, descriptors1 );  
	descriptor_extractor->compute( img2, m_RightKey, descriptors2 );  
	t = ((double)getTickCount() - t)/getTickFrequency();  
	cout<<"SIFT�㷨��ʱ��"<<t<<"��"<<endl;  

	cout<<"ͼ��1�������������С��"<<descriptors1.size()  
		<<"����������������"<<descriptors1.rows<<"��ά����"<<descriptors1.cols<<endl;  
	cout<<"ͼ��2�������������С��"<<descriptors2.size()  
		<<"����������������"<<descriptors2.rows<<"��ά����"<<descriptors2.cols<<endl;  

	//����������  
	Mat img_m_LeftKey,img_m_RightKey;  
	drawKeypoints(img1,m_LeftKey,img_m_LeftKey,Scalar::all(-1),0);  
	drawKeypoints(img2,m_RightKey,img_m_RightKey,Scalar::all(-1),0);  
	//imshow("Src1",img_m_LeftKey);  
	//imshow("Src2",img_m_RightKey);  

	//����ƥ��  
	vector<DMatch> matches;//ƥ����  
	descriptor_matcher->match( descriptors1, descriptors2, matches );//ƥ������ͼ�����������  
	cout<<"Match������"<<matches.size()<<endl;  

	//����ƥ�����о����������Сֵ  
	//������ָ���������������ŷʽ���룬�������������Ĳ��죬ֵԽС��������������Խ�ӽ�  
	double max_dist = 0;  
	double min_dist = 100;  
	for(int i=0; i<matches.size(); i++)  
	{  
		double dist = matches[i].distance;  
		if(dist < min_dist) min_dist = dist;  
		if(dist > max_dist) max_dist = dist;  
	}  
	cout<<"�����룺"<<max_dist<<endl;  
	cout<<"��С���룺"<<min_dist<<endl;  

	//ɸѡ���Ϻõ�ƥ���  
	vector<DMatch> goodMatches;  
	for(int i=0; i<matches.size(); i++)  
	{  
		if(matches[i].distance < 0.2 * max_dist)  
		{  
			goodMatches.push_back(matches[i]);  
		}  
	}  
	cout<<"goodMatch������"<<goodMatches.size()<<endl;  

	//����ƥ����  
	//Mat img_matches;  
	////��ɫ���ӵ���ƥ���������ԣ���ɫ��δƥ���������  
	//drawMatches(img1,m_LeftKey,img2,m_RightKey,goodMatches,img_matches,  
	//	Scalar::all(-1)/*CV_RGB(255,0,0)*/,CV_RGB(0,255,0),Mat(),2);  

	////imshow("MatchSIFT",img_matches);
	////imwrite("MatchSIFT.jpg",img_matches);
	//IplImage result=img_matches;

	///*waitKey(0);*/


	//RANSACƥ�����
	vector<DMatch> m_Matches=goodMatches;
	// ����ռ�
	int ptCount = (int)m_Matches.size();
	Mat p1(ptCount, 2, CV_32F);
	Mat p2(ptCount, 2, CV_32F);

	// ��Keypointת��ΪMat
	Point2f pt;
	for (int i=0; i<ptCount; i++)
	{
		pt = m_LeftKey[m_Matches[i].queryIdx].pt;
		p1.at<float>(i, 0) = pt.x;
		p1.at<float>(i, 1) = pt.y;

		pt = m_RightKey[m_Matches[i].trainIdx].pt;
		p2.at<float>(i, 0) = pt.x;
		p2.at<float>(i, 1) = pt.y;
	}

	// ��RANSAC��������F
	Mat m_Fundamental;
	vector<uchar> m_RANSACStatus;       // ����������ڴ洢RANSAC��ÿ�����״̬
	findFundamentalMat(p1, p2, m_RANSACStatus, FM_RANSAC,1,0.9);

	// ����Ұ�����

	int OutlinerCount = 0;
	for (int i=0; i<ptCount; i++)
	{
		if (m_RANSACStatus[i] == 0)    // ״̬Ϊ0��ʾҰ��
		{
			OutlinerCount++;
		}
	}
	int InlinerCount = ptCount - OutlinerCount;   // �����ڵ�
	cout<<"�ڵ���Ϊ��"<<InlinerCount<<endl;


	// �������������ڱ����ڵ��ƥ���ϵ
	
	

	m_LeftInlier.resize(InlinerCount);
	m_RightInlier.resize(InlinerCount);
	InlinerCount=0;
	float inlier_minRx=img1.cols;        //���ڴ洢�ڵ�����ͼ��С�����꣬�Ա�����ں�

	for (int i=0; i<ptCount; i++)
	{
		if (m_RANSACStatus[i] != 0)
		{
			m_LeftInlier[InlinerCount].x = p1.at<float>(i, 0);
			m_LeftInlier[InlinerCount].y = p1.at<float>(i, 1);
			m_RightInlier[InlinerCount].x = p2.at<float>(i, 0);
			m_RightInlier[InlinerCount].y = p2.at<float>(i, 1);

			InlinerCount++;
		}
	}
	return InlinerCount;
	}