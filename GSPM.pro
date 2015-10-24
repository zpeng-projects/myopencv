#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T12:45:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GSPM
TEMPLATE = app


SOURCES += main.cpp\
        imagepro.cpp \
    histogram1d.cpp \
    colorhistogram.cpp \
    imagecomparator.cpp \
    morphofeatures.cpp \
    laplacianzc.cpp \
    houghlinefinder.cpp

HEADERS  += imagepro.h \
    histogram1d.h \
    colorhistogram.h \
    imagecomparator.h \
    morphofeatures.h \
    laplacianzc.h \
    houghlinefinder.h

FORMS    += imagepro.ui

INCLUDEPATH += -L/usr/local/include/
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_videoio \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_imgcodecs \
-lopencv_flann
