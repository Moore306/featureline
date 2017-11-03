#include <stdio.h>
#include <iostream>
#include <cv.h>
#include "opencv2/core/core.hpp"
#include <opencv2/opencv.hpp>  
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/nonfree.hpp>





using namespace cv;
using namespace std;

int match(Mat &img1,Mat& img2,vector<Point2f>& m_LeftInlier,vector<Point2f> &m_RightInlier);

int min_path(Mat &img1,Point start,Point end);