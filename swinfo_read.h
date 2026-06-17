#ifndef SWINFO_READ_H
#define SWINFO_READ_H

#include <QDialog>

namespace Ui {
class SwInfo_read;
}

class SwInfo_read : public QDialog
{
    Q_OBJECT

public:
    explicit SwInfo_read(QWidget *parent = nullptr);
    ~SwInfo_read();

private:
    Ui::SwInfo_read *ui;
};

#endif // SWINFO_READ_H
