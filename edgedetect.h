#ifndef EDGEDETECT_H
#define EDGEDETECT_H

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>

using namespace std;
using namespace cv;

class EdgeDetect
{
public:
    EdgeDetect();
    ~EdgeDetect();
    void camintr(Mat &thresh);
    double camtest(int &x, int &y, Mat threshold, Mat &cameraFeed);
    double runner();
private:
    int H_MIN =0;
    int H_MAX =0;
    int S_MIN =0;
    int S_MAX =0;
    int V_MIN =0;
    int V_MAX =0;
    int num;

    const int FRAME_WIDTH = 640;
    const int FRAME_HEIGHT = 480;
    const int MAX_NUM_OBJECTS = 50;
    const int MIN_OBJECT_AREA = 20 * 20;
    const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH / 1.5;

    bool calibrationMode;
    bool mouseIsDragging;
    bool mouseMove;
    bool rectangleSelected;
    cv::Point initialClickPoint, currentMousePoint;
    vector<int> H_ROI, S_ROI, V_ROI;




};

#endif // EDGEDETECT_H
