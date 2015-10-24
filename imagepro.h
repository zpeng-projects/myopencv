#ifndef IMAGEPRO_H
#define IMAGEPRO_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
//#include <opencv2/opencv.hpp>
#include "histogram1d.h"
#include "colorhistogram.h"
#include "morphofeatures.h"
#include "houghlinefinder.h"

namespace Ui {
class ImagePro;
}

class ImagePro : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImagePro(QWidget *parent = 0);
    ~ImagePro();

private slots:
    void on_btnLoadImg_clicked();

    void on_btnProcess_clicked();

    void on_btnHistoStretch_clicked();

    void on_btnEqualizer_clicked();

    void on_btnDetectEdgeMorph_clicked();

    void on_btnCanny_clicked();
    
    void on_btnHoughLines_clicked();

    int on_btnVideoCap_clicked();

private:
    Ui::ImagePro *ui;
    cv::Mat _img;
};

#endif // IMAGEPRO_H
