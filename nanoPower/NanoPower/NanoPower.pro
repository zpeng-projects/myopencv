#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T16:19:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NanoPower
TEMPLATE = app


SOURCES += main.cpp\
        nanopower.cpp

HEADERS  += nanopower.h

FORMS    += nanopower.ui


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
