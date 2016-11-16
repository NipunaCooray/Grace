#ifndef EDGEDETECTOR_H
#define EDGEDETECTOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "global.h"
#include <vector>

using namespace cv;


class EdgeDetector
{
public:
    EdgeDetector();
    int returnFoldWidth(int &x,int &y, Mat threshold, Mat &cameraFeed);
    void foldWidthController();
    void setHSV();
    void erodeFunc(Mat &threshold);

private:
    int H_MIN;
    int H_MAX;
    int S_MIN;
    int S_MAX;
    int V_MIN;
    int V_MAX;

    int FRAME_WIDTH;
    int FRAME_HEIGHT;
    int MAX_NUM_OBJECTS;
    int MIN_OBJECT_AREA;
    int MAX_OBJECT_AREA;

    Mat cameraFeed;
    Mat HSV;
    Mat threshold;
    int x;
    int y;

};



#endif // EDGEDETECTOR_H
