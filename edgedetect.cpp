#include "edgedetect.h"
#include "serialreadwrite.h"
#include "unistd.h"
#include "global.h"
#include <QDebug>
#include <QMessageBox>



Mat3b canvas;
Mat image;

//int H_MIN =0;
//int H_MAX =0;
//int S_MIN =0;
//int S_MAX =0;
//int V_MIN =0;
//int V_MAX =0;
//int num;

//const int FRAME_WIDTH = 640;
//const int FRAME_HEIGHT = 480;
//const int MAX_NUM_OBJECTS = 50;
//const int MIN_OBJECT_AREA = 20 * 20;
//const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH / 1.5;

//bool calibrationMode;
//bool mouseIsDragging;
//bool mouseMove;
//bool rectangleSelected;
//cv::Point initialClickPoint, currentMousePoint;
//vector<int> H_ROI, S_ROI, V_ROI;



EdgeDetect::EdgeDetect()
{
    H_MIN =0;
    H_MAX =0;
    S_MIN =0;
    S_MAX =0;
    V_MIN =0;
    V_MAX =0;
    num = 1;

}

EdgeDetect::~EdgeDetect(){

}

void EdgeDetect::camintr(Mat &thresh){
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));

    erode(thresh, thresh, erodeElement);
    erode(thresh, thresh, erodeElement);
    dilate(thresh, thresh, dilateElement);
    dilate(thresh, thresh, dilateElement);
}

double EdgeDetect::camtest(int &x, int &y, Mat threshold, Mat &cameraFeed){
    Mat temp;
    threshold.copyTo(temp);
    double foldWidth=0;

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


                 foldWidth =brect.width;


                }
            }
        }

    }

    return foldWidth;
}

double EdgeDetect::runner(){

    int foldWidth;

    bool testa= true;
    bool camint = true;
    calibrationMode = true;
    Mat cameraFeed;
    Mat HSV;
    Mat threshold;
    int x = 0, y = 0;
    Mat frame;

    VideoCapture cap(1);
    if(!cap.isOpened()) {
        cout << "Can't connect to camera" <<endl;

        QMessageBox messageBox;
        messageBox.critical(0,"Error","Camera unavailable");
        messageBox.setFixedSize(500,200);

    }
    //num = GlobalData::styleData.getRGB();
    num=1;

        if (num == 1)
        {

//            H_MIN = 0;
//            H_MAX = 179;
//            S_MIN = 141;
//            S_MAX = 241;
//            V_MIN = 148;
//            V_MAX = 255;
            H_MIN = 0;
            H_MAX = 130;
            S_MIN = 0;
            S_MAX = 255;
            V_MIN = 0;
            V_MAX = 24;
        }

        else if(num == 2){

//            H_MIN =113;
//            H_MAX =123;
//            S_MIN = 58;
//            S_MAX = 214;
//            V_MIN = 136;
//            V_MAX = 255;

            H_MIN =0;
            H_MAX =174;
            S_MIN = 0;
            S_MAX = 91;
            V_MIN = 126;
            V_MAX = 252;

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

    SerialReadWrite sRead;

    while (1){


        cap >> frame;
        cameraFeed =frame;

        namedWindow("Cam feed", WINDOW_NORMAL);
        cv::resizeWindow("Cam feed", 200, 200);


        cvtColor(cameraFeed, HSV, COLOR_BGR2HSV);

        inRange(HSV, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold);

        if (camint)
            camintr(threshold);

        if (testa){
            foldWidth = camtest(x, y, threshold, cameraFeed);
            imshow("Cam feed", cameraFeed);

            //foldWidth = foldWidth/2;
            cout<<"Fold width : "<< foldWidth<<endl;

            QString foldWidthSign = "f";
            QString foldWidthString = QString::number(foldWidth);
            QString seperator = "\n";

            QString s1Sign = "p";
            QString s2Sign = "q";
            QString s3Sign = "r";
            QString s4Sign = "s";
            QString t1Sign = "t";
            QString t2Sign = "u";
            QString t3Sign = "v";
            QString t4Sign = "w";
            QString setupFoldWidthSign = "x";

            //Differentiating between parameter values and dynamic values


            if(GlobalData::isDynamicValue){
                sRead.writeToSerial(foldWidthSign);
                sRead.writeToSerial(foldWidthString);
                sRead.writeToSerial(seperator);

                //Saving dynamic foldwidth to Global styledata variable
                GlobalData::styleData.setDynamicFoldwidth(foldWidth);

                //sRead.readSerial();

            }else{

                qDebug() << "Parameter values";
                QString speed1 = QString::number(GlobalData::styleData.getSpeed_1());
                QString speed2 = QString::number(GlobalData::styleData.getSpeed_2());
                QString speed3 = QString::number(GlobalData::styleData.getSpeed_3());
                QString speed4 = QString::number(GlobalData::styleData.getSpeed_4());
                QString tension1 = QString::number(GlobalData::styleData.getTension_1());
                QString tension2 = QString::number(GlobalData::styleData.getTension_2());
                QString tension3 = QString::number(GlobalData::styleData.getTension_3());
                QString tension4 = QString::number(GlobalData::styleData.getTension_4());
                QString setupFoldWidth = QString::number(GlobalData::styleData.getFoldWidth());

                qDebug() << speed1;

                //First time sending parameter values
                sRead.writeToSerial(s1Sign);
                sRead.writeToSerial(speed1);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(s2Sign);
                sRead.writeToSerial(speed2);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(s3Sign);
                sRead.writeToSerial(speed3);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(s4Sign);
                sRead.writeToSerial(speed4);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(t1Sign);
                sRead.writeToSerial(tension1);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(t2Sign);
                sRead.writeToSerial(tension2);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(t3Sign);
                sRead.writeToSerial(tension3);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(t4Sign);
                sRead.writeToSerial(tension4);
                sRead.writeToSerial(seperator);
                //sRead.writeToSerial(setupFoldWidthSign);
                sRead.writeToSerial(setupFoldWidth);
                sRead.writeToSerial(seperator);


                GlobalData::isDynamicValue = true;


            }

//            GlobalData::serialReadWrite.writeToSerial(foldWidthString);
//            GlobalData::serialReadWrite.writeToSerial(seperator);

//            GlobalData::serialReadWrite.readSerial();


        }

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break;
       }

       usleep(200000);

       cout<< "Is dynamic val "<<GlobalData::isDynamicValue<<endl;



       if(GlobalData::isEdge){
           break;
       }


    }

    return foldWidth;
}

