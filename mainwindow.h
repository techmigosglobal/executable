#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Include/stdemace.h"
#include "mythread.h"
#include "workthread.h"
#include<QLineEdit>
#include<QMessageBox>

/*MC HEADERS */
#include <stdemace.h>
#include "rtthread.h"
#include "bcthread.h"
#include"sgeneration.h"
#include<QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /***RC_TIMERS****/
    QTimer *timer_t;
    QTimer *timer;
    int lineCount,recievecount;
    unsigned int time_tag;

    /***RC_TIMERS****/

    MyThread *mThread;
    workthread *updateclass;
    QThread *upThread;
    QMessageBox *errorPopup;
    int ui_Count;
    void rc_initialize();
    bool stn1,stn2,stn3,stn4,Maneuverb,mNrQ;
    bool cb1,cb2,cb3,cb4;
    double pITCH;
    unsigned short MnurCnt;

    /* MC CLASS and Thread*/

    bcthread *mc_Bc;
    rtthread *mc_Rt;
    QThread *mc_bcthread;
    QThread *mc_rtthread;
    QTimer *mc_timer;
    sgeneration *sg1,*sg2,*sg3,*sg4;
    int icount,mcCount;
    FILE *fpIn10msData;
    FILE *file_RC;
    FILE *file_rcw1,*file_mcw1,*file_rcw2,*file_mcw2,*file_rcw3,*file_mcw3,*file_rcw4,*file_mcw4,*file_man;
    static QString mcFilePath,rcFilePath;
    FILE *Autolaunch_file;
    FILE *DLZ_file;
    void mc_BcConfig(); // new functin
    void mc_rtConfig();  // new functin
    void startRc();
    void stopRc();
    void startMc();
    void stopMc();
    void openMCfile();
    //FILE *HMDS_file;

private slots:
    void message();
    void acestop();
    void Ondisplay();
    void updategui();
    //void filewriting();
    void Onmesgcount();
    //void on_start_sim_Pbt_clicked();
    void on_stop_sim_Pbt_clicked();
    //  void on_pb_freq_enter_clicked();

    /********MC SLOTS ***/
    void Onrtconfig();
    void Onbcconfig();
    void mc_acestop();
    void mc_Timer_Message();
    void updateinu01(unsigned short dataBuff[32]);
    void updateinu03(unsigned short dataBuff[32]);
    void updateinu02(unsigned short dataBuff[32]);
    void modifyguinu01(unsigned short dataBuff[32]);
    void modifyguinu02(unsigned short dataBuff[32]);
    void modifyguinu03(unsigned short dataBuff[32]);
    void on_mc_File_Brwse_Pbt_clicked();
    void on_mc_file_Chk_clicked(bool checked);
    void on_rc_file_Pbt_clicked();
    void on_rc_select_Chk_clicked(bool checked);
  //  void on_cB_simulation_clicked(bool checked);
    void on_cB_simulation_3_clicked(bool checked);
    void on_cB_simulation_4_clicked(bool checked);
    void on_cB_simulation_2_clicked(bool checked);
    void on_cB_mANEUVER_clicked(bool checked);

signals:
    void sendupdate();

public slots:
    void UpdateGUIData();
    void on_start_sim_Pbt_clicked();
    void filewriting();
    void onSIM();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
