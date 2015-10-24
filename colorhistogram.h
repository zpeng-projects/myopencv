#ifndef COLORHISTOGRAM_H
#define COLORHISTOGRAM_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ColorHistogram {
private:
    int histSize[3]; //number of bins
    float hranges[2]; //min and max pixel value
    const float* ranges[3];
    int channels[3] ; //only 1 channel used here
public:
    ColorHistogram();
    cv::Mat getHistogram(const cv::Mat &image);
    // cv::Mat getHistgramImage(const cv::Mat &image);
    void colorReduce(const cv::Mat &image, cv::Mat& im,int div=32);


};

#endif // COLORHISTOGRAM_H
