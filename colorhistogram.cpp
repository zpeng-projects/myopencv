#include "colorhistogram.h"

ColorHistogram::ColorHistogram(){
    histSize[0]=histSize[1]=histSize[2]=256;
    hranges[0] = 0.0;
    hranges[1] = 255.0;
    ranges[0]=ranges[1]=ranges[2]=hranges;
    channels[0]=channels[1]=channels[2]=0;
}


cv::Mat ColorHistogram::getHistogram(const cv::Mat &image) {
    cv::Mat hist;
    cv::calcHist(&image,
                 1, //1 image
                 channels,
                 cv::Mat(),
                 hist,
                 3, //1d histogram
                 histSize,
                 ranges
                 );
    return hist;
}

void ColorHistogram::colorReduce(const cv::Mat &image, cv::Mat& result, int div) {
    result.create(image.rows,image.cols,image.type());
int nl= image.rows; // number of lines
// total number of elements per line
int nc= image.cols * image.channels();
for (int j=0; j<nl; j++) {
// get the address of row j
const uchar* data_in= image.ptr<uchar>(j);
uchar* data_out= result.ptr<uchar>(j);
for (int i=0; i<nc; i++) {
// process each pixel ---------------------
data_out[i]= data_in[i]/div*div + div/2;
// end of pixel processing ----------------
} // end of line
}
}
