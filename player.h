#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/objdetect.hpp>
#include <QLabel>

using namespace cv;

class Player : public QThread
{   Q_OBJECT
private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    VideoCapture capture;
    Mat RGBFrame;
    QImage img;
signals:
    void processedImage(const QImage &image);

protected:
    void run();
    void msleep(int ms);

public:
    Player(QObject *parent=0);
    ~Player();
    bool LoadVideo(QString filename);
    void Play();
    void Stop();
    bool IsStopped() const;
};
#endif

