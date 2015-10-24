#ifndef HISTOGRAM1D_H
#define HISTOGRAM1D_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Histogram1D {
private:
    int histSize[1]; //number of bins
    float hranges[2]; //min and max pixel value
    const float* ranges[1];
    int channels[1] ; //only 1 channel used here
public:
    Histogram1D();
    cv::MatND getHistogram(const cv::Mat &image);
    cv::Mat getHistgramImage(const cv::Mat &image);
    cv::Mat applyLookUp(const cv::Mat& image, // input image
    const cv::Mat& lookup); // 1x256 uchar matrix
    cv::Mat stretch(const cv::Mat &image, int minValue=100);
    cv::Mat equalize(const cv::Mat &image); //1D

};



#endif // HISTOGRAM1D_H
