#ifndef LAPLACIANZC_H
#define LAPLACIANZC_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class LaplacianZC {
private:
    // original image
    cv::Mat img;
    // 32-bit float image containing the Laplacian
    cv::Mat laplace;
    // Aperture size of the laplacian kernel
    int aperture;
public:
    LaplacianZC() : aperture(3) {}
    // Set the aperture size of the kernel
    void setAperture(int a) {
        aperture= a;
    }
    // Compute the floating point Laplacian
    cv::Mat computeLaplacian(const cv::Mat& image) {
        // Compute Laplacian
        cv::Laplacian(image,laplace,CV_32F,aperture);
        // Keep local copy of the image
        // (used for zero-crossings)
        img= image.clone();
        return laplace;
    }

    cv::Mat getLaplacianImage(double scale=-1.0) {
        if (scale<0) {
            double lapmin, lapmax;
            cv::minMaxLoc(laplace,&lapmin,&lapmax);
            scale= 127/ std::max(-lapmin,lapmax);
        }
        cv::Mat laplaceImage;
        laplace.convertTo(laplaceImage,CV_8U,scale,128);
        return laplaceImage;
    }

    cv::Mat getZeroCrossings(float threshold=1.0) {
        // Create the iterators
        cv::Mat_<float>::const_iterator it=
                laplace.begin<float>()+laplace.step1();
        cv::Mat_<float>::const_iterator itend=
                laplace.end<float>();
        cv::Mat_<float>::const_iterator itup=
                laplace.begin<float>();
        // Binary image initialize to white
        cv::Mat binary(laplace.size(),CV_8U,cv::Scalar(255));
        cv::Mat_<uchar>::iterator itout=
                binary.begin<uchar>()+binary.step1();
        // negate the input threshold value
        threshold *= -1.0;
        for ( ; it!= itend; ++it, ++itup, ++itout) {
            // if the product of two adjascent pixel is
            // negative then there is a sign change
            if (*it * *(it-1) < threshold)
                *itout= 0; // horizontal zero-crossing
            else if (*it * *itup < threshold)
                *itout= 0; // vertical zero-crossing
        }
        return binary;
    }
};
#endif // LAPLACIANZC_H
