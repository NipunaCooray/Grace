#include "player.h"

Player::Player(QObject *parent)
 : QThread(parent)
{
    stop = true;

}

//    VideoCapture stream1(0);
//    if(!stream1.isOpened()){
//        cout<<"Cannot open camera/n";
//    } else{
//        while(true){
//            Mat cameraFrame;
//            stream1.read(cameraFrame);
//            imshow("cam",cameraFrame);
//            if(waitKey(30)>=0){
//                break;
//            }

//        }
//    }

bool Player::loadVideo() {

    Mat cameraFrame;
    VideoCapture stream1(1);
    stream1.read(cameraFrame);
    capture = stream1;

    if (stream1.isOpened())
    {
        frameRate = (int) stream1.get(CAP_PROP_FPS);

        //Play code
        start(LowPriority);

        return true;
    }
    else
        return false;
}



void Player::run()
{
    int delay = (1000/frameRate);
    while(!stop){
        if (!capture.read(frame))
        {
            stop = true;
        }
        if (frame.channels()== 3){
            cv::cvtColor(frame, RGBframe,COLOR_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_Indexed8);
        }
        emit processedImage(img);
        this->msleep(delay);
    }
}

Player::~Player()
{
    mutex.lock();
    stop = true;
    capture.release();
    condition.wakeOne();
    mutex.unlock();
    wait();
}

void Player::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

