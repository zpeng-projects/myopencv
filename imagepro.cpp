#include "imagepro.h"
#include "ui_imagepro.h"

#include <QFileDialog>

ImagePro::ImagePro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImagePro)
{
    ui->setupUi(this);
}

ImagePro::~ImagePro()
{
    delete ui;
}

void ImagePro::on_btnLoadImg_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                    tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    _img= cv::imread(fileName.toUtf8().constData());
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", _img);

    Histogram1D HH;
    cv::Mat histIm = HH.getHistgramImage(_img);
    cv::namedWindow("Histogram");
    cv::imshow("Histogram", histIm);

    cv::Mat thresholded;
    cv::Mat imgG;
    cv::cvtColor(_img,imgG,CV_BGR2GRAY);
    cv::threshold(imgG,thresholded,60,255,cv::THRESH_BINARY);
    cv::namedWindow("binary");
    cv::imshow("binary", thresholded);

}

void ImagePro::on_btnProcess_clicked()
{
    cv::flip(_img,_img,1); // process the image
    // change color channel ordering
    cv::cvtColor(_img,_img,CV_BGR2RGB);
    // Qt image
    //QImage img= QImage((uchar*) _img.data, _img.cols, _img.rows, QImage::Format_RGB888);
    QImage img= QImage((const unsigned char*)(_img.data),
                       _img.cols,_img.rows,_img.step,QImage::Format_RGB888);
    // display on label
    ui->label->setPixmap(QPixmap::fromImage(img));
    // resize the label to fit the image
    ui->label->resize(ui->label->pixmap()->size());
}

void ImagePro::on_btnHistoStretch_clicked()
{
    cv::Mat tepImg;
    std::vector<cv::Mat> tmp;
    cv::split(_img,tmp);
    Histogram1D HH;
    for (int i=0;i<3;i++){
        tmp[i]=HH.stretch(tmp[i]);
    }
    cv::merge(tmp,tepImg);
    cv::namedWindow("stretch histogram");
    cv::imshow("stretch histogram",tepImg);
}

void ImagePro::on_btnEqualizer_clicked()
{
    cv::Mat tepImg;
    std::vector<cv::Mat> tmp;
    cv::split(_img,tmp);
    Histogram1D HH;
    for (int i=0;i<3;i++){
        tmp[i]=HH.equalize(tmp[i]);
    }
    cv::merge(tmp,tepImg);
    cv::namedWindow("histogram equalize");
    cv::imshow("histogram equalize",tepImg);
}

void ImagePro::on_btnDetectEdgeMorph_clicked()
{
    MorphoFeatures morpho;
    morpho.setThreshold(40);
    // Get the edges
    cv::Mat tmpImg;
    cv::cvtColor(_img, tmpImg, CV_RGB2GRAY);
    cv::Mat edges;
    edges= morpho.getEdges(tmpImg);
    cv::namedWindow("edge dection: Morphology");
    cv::imshow("edge dection: Morphology",edges);

    cv::Mat corners;
    corners= morpho.getCorners(tmpImg);
    cv::Mat tmp2;
    tmp2 = _img.clone();
    morpho.drawOnImage(corners,tmpImg);

    cv::namedWindow("corner dection: Morphology");
    cv::imshow("corner dection: Morphology",tmpImg);

}


void ImagePro::on_btnCanny_clicked()
{
    cv::Mat tmp2;
    cv::Canny(_img,tmp2,40,120);
    cv::threshold(tmp2,tmp2,128,255,cv::THRESH_BINARY_INV);
    cv::namedWindow("Canny contours");
    cv::imshow("Canny contours",tmp2);
}

void ImagePro::on_btnHoughLines_clicked()
{
    double PI = 3.14159;
    LineFinder finder;
    //    // Set probabilistic Hough parameters
    //finder.setLineLengthAndGap(100,20);
    //finder.setMinVote(40);
    //    // Detect lines and draw them
    cv::Mat tmp1, tmp2;
    cv::cvtColor(_img,tmp1,CV_BGR2GRAY);
    cv::Canny(tmp1,tmp2,40,100);
    //cv::Canny(tmp1,tmp2,40,150);
    //cv::threshold(tmp2,tmp2,128,255,cv::THRESH_BINARY_INV);
    std::vector<cv::Vec4i> lines= finder.findLines(tmp2);
    //finder.drawDetectedLines(_img);
    cv::namedWindow("Detected Lines with HoughP");
    cv::imshow("Detected Lines with HoughP",tmp2);
}

int ImagePro::on_btnVideoCap_clicked()
{
    cv::VideoCapture cap(2);
    if (!cap.isOpened())
        return -1;
}
