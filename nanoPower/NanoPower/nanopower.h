#ifndef NANOPOWER_H
#define NANOPOWER_H

#include <QMainWindow>

namespace Ui {
class NanoPower;
}

class NanoPower : public QMainWindow
{
    Q_OBJECT

public:
    explicit NanoPower(QWidget *parent = 0);
    ~NanoPower();

private:
    Ui::NanoPower *ui;
};

#endif // NANOPOWER_H
