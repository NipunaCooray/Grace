#include <QCoreApplication>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>

using namespace cv;
using namespace std;

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

bool calibrationMode;
bool mouseIsDragging;
bool mouseMove;
bool rectangleSelected;
cv::Point initialClickPoint, currentMousePoint;
vector<int> H_ROI, S_ROI, V_ROI;

string intToString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}


void camintr(Mat &thresh){
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));

    erode(thresh, thresh, erodeElement);
    erode(thresh, thresh, erodeElement);
    dilate(thresh, thresh, dilateElement);
    dilate(thresh, thresh, dilateElement);
}

void camtest(int &x, int &y, Mat threshold, Mat &cameraFeed){
    Mat temp;
    threshold.copyTo(temp);

    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(temp, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    double refArea = 0;
    int largestIndex = 0;
    bool objectFound = false;
    if (hierarchy.size() > 0) {
        int numObjects = hierarchy.size();
        if (numObjects<MAX_NUM_OBJECTS){
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                Moments moment = moments((cv::Mat)contours[index]);
                double area = moment.m00;

                if (area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea){
                    x = moment.m10 / area;
                    y = moment.m01 / area;
                    objectFound = true;
                    refArea = area;

                    largestIndex = index;
                }
                else objectFound = false;
            }

            if (objectFound == true){

                drawContours(cameraFeed, contours, largestIndex, Scalar(0, 100, 255), 3);

                vector<Point> points;
                for (size_t i=0; i < contours.size(); i++) {
                    for (size_t j = 0; j < contours[i].size(); j++) {
                        Point p = contours[i][j];
                        points.push_back(p);
                    }
                }

                if(points.size() > 0){
                Rect brect = boundingRect(Mat(points).reshape(2));
                rectangle(cameraFeed, brect.tl(), brect.br(), Scalar(0, 255, 0), 2);

                 double pt1, pt2;
                 pt1 =brect.width;
                 cout<<pt1<<endl;



                }
            }
        }

    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

        bool testa= true;
        bool camint = true;
        calibrationMode = true;
        Mat cameraFeed;
        Mat HSV;
        Mat threshold;
        int x = 0, y = 0;
        Mat frame;

        VideoCapture cap(1);
        if(!cap.isOpened())
            return -1;


        cout << "Enter a number: " << endl;
            cin >> num;
            if (num == 1)
            {

                H_MIN = 0;
                H_MAX = 179;
                S_MIN = 141;
                S_MAX = 241;
                V_MIN = 148;
                V_MAX = 255;
            }

            else if(num == 2){

                H_MIN =113;
                H_MAX =123;
                S_MIN = 58;
                S_MAX = 214;
                V_MIN = 136;
                V_MAX = 255;

            }

            else
                {

                H_MIN = 81;
                H_MAX = 100;
                S_MIN = 48;
                S_MAX = 172;
                V_MIN = 80;
                V_MAX = 132;
            }

        while (1){


            cap >> frame;
            cameraFeed =frame;
            cvtColor(cameraFeed, HSV, COLOR_BGR2HSV);

            inRange(HSV, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold);

            if (camint)
                camintr(threshold);

            if (testa)

                camtest(x, y, threshold, cameraFeed);

            if (calibrationMode == true){


            }

            if (waitKey(30) == 99) calibrationMode = !calibrationMode;

            if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
           {
                cout << "esc key is pressed by user" << endl;
                break;
           }

        }


    return a.exec();
}
