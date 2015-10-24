#include "imagepro.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImagePro w;
    w.show();

    return a.exec();
}
