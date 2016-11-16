#ifndef OBJECTTRACKER_H
#define OBJECTTRACKER_H
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <sstream>
#include <string>

using namespace std;
using namespace cv;

class ObjectTracker
{
public:
    ObjectTracker();
    ~ObjectTracker();
    void morphOps(Mat &thresh);
    void trackFilteredObject(int &x, int &y, Mat threshold, Mat &cameraFeed);
    void runner();
    string intToString(int number);
    void drawObject(int x, int y,Mat &frame);
    void on_trackbar( int, void* );
    void createTrackbars();

private:

    Mat3b canvas;
    Mat image;

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

    //names that will appear at the top of each window
    const string windowName = "Original Image";
    const string windowName1 = "HSV Image";
    const string windowName2 = "Thresholded Image";
    const string windowName3 = "After Morphological Operations";
    const string trackbarWindowName = "Trackbars";

    bool calibrationMode;
    bool mouseIsDragging;
    bool mouseMove;
    bool rectangleSelected;
    cv::Point initialClickPoint, currentMousePoint;
    vector<int> H_ROI, S_ROI, V_ROI;

};

#endif // OBJECTTRACKER_H
