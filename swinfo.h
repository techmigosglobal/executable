#ifndef SWINFO_H
#define SWINFO_H

#define STR_VALUE(val)#val
#define STR(name) STR_VALUE(name)
#define PATH_LEN 256
#define MD5_LEN 32
#include <QDialog>

namespace Ui {
class SwInfo;
}

class SwInfo : public QDialog
{
    Q_OBJECT

public:
    explicit SwInfo(QWidget *parent = nullptr);
    ~SwInfo();

private slots:
    void on_PBI_clicked();

private:
    Ui::SwInfo *ui;
};

#endif // SWINFO_H
