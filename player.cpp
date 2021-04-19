#include "player.h"

Player::Player(QObject *parent)
        :QThread(parent)
{
    stop = true;
}

bool Player::LoadVideo(QString filename)
{
    capture.open(filename.toStdString().data());
    if (capture.isOpened())
    {
        frameRate = (int) capture.get(CAP_PROP_FPS);
        return true;
    } else{
        return false;
    }
}

void Player::Play(){
    if(!isRunning()){
        if(IsStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

void Player::run() {
    int delay = (1000/frameRate);
    while(!stop)
    {
        if (!capture.read(frame))
        {
            stop = true;
        }
        if(frame.channels() == 3)
        {
            cv::cvtColor(frame, RGBFrame, COLOR_BGR2RGB);
            img = QImage((uchar*)RGBFrame.data, RGBFrame.cols, RGBFrame.rows, QImage::Format_RGB888);
        }
        else
        {
            img = QImage((uchar*) frame.data, frame.cols, frame.rows, QImage::Format_Indexed8);
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
void Player::Stop()
{
    stop = true;
}
void Player::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}
bool Player::IsStopped() const {
    return stop;
}

