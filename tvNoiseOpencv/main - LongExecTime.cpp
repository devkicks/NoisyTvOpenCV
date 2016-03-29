#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;

#define C_DIM_COLS 640
#define C_DIM_ROWS 480
#define C_STEP_LOOP 10
#define C_RANDOM_MOD 100

int main ()
{
	Mat outDisp;
	char ch = NULL;
	outDisp = Mat::zeros(C_DIM_ROWS, C_DIM_COLS, CV_8UC1);

	while(ch != 27)
	{
		for(int i = 0; i < outDisp.cols; i+=C_STEP_LOOP )
		{
			for(int j = 0; j < outDisp.rows; j+=C_STEP_LOOP)
			{
				int val = uchar(((rand()%C_RANDOM_MOD)*255)/C_RANDOM_MOD);
				for(int ii = i; ii < i + C_STEP_LOOP; ii++)
				{
					for(int jj = j; jj < j + C_STEP_LOOP; jj++)
					{
						outDisp.at<uchar>(jj,ii) = val;
					}
				}	
			}
		}
		imshow("outDisp Image", outDisp);
		ch = waitKey(10);
	}
	return 1;
}