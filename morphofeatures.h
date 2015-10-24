#ifndef MORPHOFEATURES_H
#define MORPHOFEATURES_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class MorphoFeatures {
private:
// threshold to produce binary image
int threshold;
// structuring elements used in corner detection
cv::Mat cross;
cv::Mat diamond;
cv::Mat square;
cv::Mat x;

public:
MorphoFeatures();

cv::Mat getEdges(const cv::Mat &image) {
// Get the gradient image
cv::Mat result;
cv::morphologyEx(image,result,cv::MORPH_GRADIENT,cv::Mat());
// Apply threshold to obtain a binary image
applyThreshold(result);
return result;
}

void setThreshold(int t){
    threshold = t;
}

void applyThreshold(cv::Mat& result) {
// Apply threshold on result
if (threshold>0)
cv::threshold(result, result,
threshold, 255, cv::THRESH_BINARY);
}

cv::Mat getCorners(const cv::Mat &image);
void drawOnImage(const cv::Mat& binary,cv::Mat& image);

};

#endif // MORPHOFEATURES_H
