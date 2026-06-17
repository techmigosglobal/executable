#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "ta_bias.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include "QFileDialog"
#include "mythread.h"
#include "mcvariables.h"
#include "variables.h"
#include "windows.h"
#include <QDebug>
#include <QCheckBox>
#include <QDesktopWidget>
#include <QRect>
#include <time.h>
#include <string>
#include <QDate>
#include <QTime>
#include <QDir>
#include <QLabel>
#include <QPushButton>
#include <QtGui>
#include <QAction>
#include <qmessagebox.h>
#include <qcolor.h>
#include <QProcess>
#include <QFile>
#include <QCryptographicHash>
#include <iostream>
#include <fcntl.h>
#include <io.h>

#define DBLK1   1
#define DBLK2   2
#define DBLK3   3
#define DBLK4   4
#define DBLK5   5
#define DBLK6   6
#define DBLK7   7
#define DBLK8   8
#define DBLK9   9
#define DBLK10   10
#define DBLK11   11
#define DBLK12   12
#define DBLK13   13
#define DBLK14   14
#define DBLK15   15
#define DBLK16   16
#define DBLK17   17
#define DBLK18   18
#define DBLK19   19
#define DBLK20   20
#define DBLK21   21
#define DBLK22   22
#define DBLK23   23
#define DBLK24   24
#define DBLK25   25
#define DBLK26   26
#define DBLK23   23
#define DBLK24   24
#define DBLK25   25
#define DBLK50  50



#define MSG1    1
#define MSG2    2
#define MSG3    3
#define MSG4    4
#define MSG5    5
#define MSG6    6
#define MSG7    7
#define MSG8    8
#define MSG9    9
#define MSG10   10
#define MSG11    11
#define MSG12    12
#define MSG13    13
#define MSG14    14
#define MSG15    15
#define MSG16    16
#define MSG17    17
#define MSG18    18
#define MSG19    19
#define MSG20    20
#define MSG21    21
#define MSG22    22
#define MSG23    23
#define MSG24    24
#define MSG25    25
#define MSG26    26
#define MSG27   27

//#define MSG23    23
//#define MSG24    24
//#define MSG25    25

#define OP1     1
#define OP2     2
#define OP3     3
#define OP4     4
#define OP5     5
#define OP6     6
#define OP7     7
#define OP8     8
#define OP9     9
#define OP10    10
#define OP11    11
#define OP12    12
#define OP13    13
#define OP14    14
#define OP15    15
#define OP16    16
#define OP17    17
#define OP18    18
#define OP19    19
#define OP20    20
#define OP21    21
#define OP22    22
#define OP23    23
#define OP24    24
#define OP25    25
#define OP26    26
#define OP27    27
#define OP28    28
#define OP29    29
//#define OP27    27
//#define OP28    28

#define MNR1    1
#define MNR2    2
#define MJR     3
#define END_OF_MSG 0x8000

/***********QT_MC VALUES**************/

#include <QTimer>
#include "math.h"
#include "variables.h"

#define DBLK1   1	// define data blocks for BC
#define DBLK2   2
#define DBLK3   3
#define DBLK4   4
#define DBLK5   5
#define DBLK6   6

#define MSG1    1	// define message constants
#define MSG2    2
#define MSG3    3

#define OP_MSG1     1
#define OP_MSG2     2
#define OP_MSG3     3

#define OP_MNR1     5
#define OP_MNR2     6
#define OP_MNR3     7
#define OP_MNR4     8
#define OP_MNR5     9
#define OP_MNR6     10
#define OP_MNR7     11
#define OP_MNR8     12

#define MNR1    1	// define frame constants
#define MNR2    2
#define MNR3    3
#define MNR4    4
#define MNR5    5	// define frame constants
#define MNR6    6
#define MNR7    7
#define MNR8    8

#define MJR     10

//#define DevNumBC 0
//#define DevNumRT 1
#define wRTAddress 5
//U16BIT wTTvalue;
using namespace std;
extern int ta_bias;
QString mc_str;
int fileclosecount;
char szDummy[512];
 int togglingcount=0;
QString MainWindow::mcFilePath;
QString MainWindow::rcFilePath;
 FILE *Autolaunch_file;
// FILE *pFile;
// FILE *rFile; FILE *sFile; FILE *tFile; FILE *uFile;
// FILE *HMDSFile;
// FILE *Surv7File;FILE *Surv8File;FILE *Surv9File;FILE *Surv10File;
// FILE *Tgt7File;FILE *Tgt8File;FILE *Tgt9File;FILE *Tgt10File;
int gb_umbilical_sts7=0, gb_umbilical_sts8=0, gb_umbilical_sts9=0, gb_umbilical_sts10=0;
int stn_flag=0;int nogoflag=0;
int filament_flag=0;int DLTxflag=0;int Obcflag=0;int modeflag=0; int ltypeflag=0; int lflag=0;int finflag=0; int actflag=0;//int dlrflag=0;
int eleflag=0;int L1flag=0;int L2flag=0;int HP_flag=0;int LP_flag=0;
int insflag=0;int rpfflag=0;int samflag=0;int seekrflag=0;int obcflag=0;int DLRflag=0;int umblicalflag=0;int Maneverflag=0;int Readyflag=0; int seekhtflag=0,Apsuflag = 0,Readyrelay=0;
int sgnflag=0;int lotdflag=0; int stnflag=0; int seekrdl_flag=0; int TAflag=0; int Boosterflag=0; int seekeleflag=0;int seekTxflag=0; int Ltbflag=0;
float IRT_range; int Pbitflag=0;int Pbitcmpflag=0;int msl_type_flag=0; int reinit_flag=0; int mlpflag=0; int mis_avail_flag=0;

/***********QT_MC VALUE ENDS**************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    errorPopup = new QMessageBox();
   // ui->EL_Launch->setCurrentIndex(0);

    // Default file names..
    MnurCnt=0;
    lineCount =0;
    recievecount=0;
    time_tag=15;
    ui->devnum_rt->setCurrentIndex(3);
    ui->devnum_bc->setCurrentIndex(2);
    ui->rc_file_Ldt->setReadOnly(true);
    ui->mc_file_Ldt->setReadOnly(true);
    ui->rc_file_Ldt->setText("MIL_RC_LOT_RAW1.txt");
    ui->mc_file_Ldt->setText("MIL_MC_HYBRID_RAW1.txt");
    //  ui->rc_file_Ldt->setText("MIL_RC_LOT_RAW_1.txt");
    //  ui->mc_file_Ldt->setText("MIL_MC_HYBRID_RAW_1.txt");
    this->setWindowTitle("RC-MC SIMULATOR ( ASTRA )");

    ui->lB_aSTRA10->setHidden(true);
    ui->lB_aSTRA9->setHidden(true);
    ui->lB_aSTRA8->setHidden(true);
    ui->lB_aSTRA7->setHidden(true);
    ui->lE_cI7->setHidden(true);
    ui->lE_cO7->setHidden(true);
    ui->lE_cI8->setHidden(true);
    ui->lE_cO8->setHidden(true);
    ui->lE_cI9->setHidden(true);
    ui->lE_cO9->setHidden(true);
    ui->lE_cI10->setHidden(true);
    ui->lE_cO10->setHidden(true);
    ui->lb_launch_stn7->setHidden(true);
    ui->lb_launch_stn8->setHidden(true);
    ui->lb_launch_stn9->setHidden(true);
    ui->lb_launch_stn10->setHidden(true);




    cb1=cb4=cb3=cb2= true;
    Maneuverb= false;
    mNrQ=false;
    ui_Count = 0;

    //     setting geometry to GUI window
    QDesktopWidget *dwed = QApplication::desktop();
    QRect rect = dwed->availableGeometry();
    //    qDebug()<<"b rect"<<rect;
    rect.setWidth(rect.width()-100);

    rect.setX(100);
    rect.setY(100);
    rect.setHeight(rect.height());

    //    qDebug()<<"a rect"<<rect;
    //    this->setGeometry(rect);
    this->showMaximized();
    /*================== QT_MC Connections==================*/

    mc_bcthread = new QThread();
    mc_Bc = new bcthread();
    connect(mc_Bc,SIGNAL(bcconfig()),this,SLOT(Onbcconfig())); // mc_bc_thread connection
    mc_Bc->moveToThread(mc_bcthread);

    mc_rtthread = new QThread();
    mc_Rt = new rtthread();
    connect(mc_Rt,SIGNAL(rtconfig()),this,SLOT(Onrtconfig())); // mc_rt_thread connection

    mc_Rt->moveToThread(mc_rtthread);

    mc_timer= new QTimer(this);
    connect(mc_timer,SIGNAL(timeout()),this,SLOT (mc_Timer_Message())); // mc_timer connection

    /*=========== QT_MC_CONNECTION ENDS =========================*/

    /*=========== QT_RC-Connections =============================*/

    mThread = new MyThread(this);
    connect(mThread,SIGNAL(display()),this,SLOT(Ondisplay())); //BC start

    timer_t= new QTimer(this);
    connect(timer_t,SIGNAL(timeout()),this,SLOT(message()));   //RT-BC reception and display // timer_t 20 msecs

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Onmesgcount()));  // timer 18 msec for updation of 1553b buffer before sending

    upThread = new QThread();
    updateclass = new workthread();

    //        connect(this,SIGNAL(sendupdate()),updateclass,SLOT(recieveUpdate()));//send update is emitted from message function every 2sec
    connect(updateclass,SIGNAL(sendMessge()),this,SLOT(UpdateGUIData())); //Update GUI after receiving RT data


    updateclass->moveToThread(upThread);
    upThread->start();

    upThread->setPriority(QThread::LowPriority);

    stn1=stn2=stn3=stn4=false;

    ui->new_2->removeTab(3);
    ui->new_2->removeTab(4);
    ui->new_2->removeTab(3);
    ui->new_2->removeTab(4);
    ui->new_2->removeTab(3);


time_t timeval;
(void) time (&timeval);

/*
pFile = fopen("MSLP data.txt","a");
fprintf(pFile,"\n**********************MSLP DATA************************** \n");
fprintf(pFile,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(pFile,"\n********************************************************* \n");

rFile=fopen("MSLP Stn7_data.txt","a");
fprintf(rFile,"\n**********************MSLP Stn7 DATA************************** \n");
fprintf(rFile,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(rFile,"\n************************************************************** \n");

sFile=fopen("MSLP Stn8_data.txt","a");
fprintf(sFile,"\n**********************MSLP Stn8 DATA************************** \n");
fprintf(sFile,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(sFile,"\n************************************************************** \n");

tFile=fopen("MSLP Stn9_data.txt","a");
fprintf(tFile,"\n**********************MSLP Stn9 DATA************************** \n");
fprintf(tFile,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(tFile,"\n************************************************************** \n");

uFile=fopen("MSLP Stn10_data.txt","a");
fprintf(uFile,"\n**********************MSLP Stn10 DATA************************** \n");
fprintf(uFile,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(uFile,"\n************************************************************** \n");
*/
//HMDSFile=fopen("HMDS.txt","a");
//fprintf(HMDSFile,"\n**********************HMDS DATA************************** \n");
//fprintf(HMDSFile,"\n\t Conducted on : %s",ctime(&timeval));
//fprintf(HMDSFile,"\n************************************************************** \n");
/*
Surv7File=fopen("Stn7_Surveillance","a");
fprintf(Surv7File,"\n**********************Surveillance Stn7 DATA************************** \n");
fprintf(Surv7File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Surv7File,"\n************************************************************** \n");

Surv8File=fopen("Stn8_Surveillance","a");
fprintf(Surv8File,"\n**********************Surveillance Stn8 DATA************************** \n");
fprintf(Surv8File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Surv8File,"\n************************************************************** \n");

Surv9File=fopen("Stn9_Surveillance","a");
fprintf(Surv9File,"\n**********************Surveillance Stn9 DATA************************** \n");
fprintf(Surv9File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Surv9File,"\n************************************************************** \n");

Surv10File=fopen("Stn10_Surveillance","a");
fprintf(Surv10File,"\n**********************Surveillance Stn10 DATA************************** \n");
fprintf(Surv10File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Surv10File,"\n************************************************************** \n");


Tgt7File=fopen("Stn7_tgt_data","a");
fprintf(Tgt7File,"\n**********************Stn7 Tgt DATA************************** \n");
fprintf(Tgt7File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Tgt7File,"\n************************************************************** \n");

Tgt8File=fopen("Stn8_tgt_data","a");
fprintf(Tgt8File,"\n**********************Stn8 Tgt DATA************************** \n");
fprintf(Tgt8File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Tgt8File,"\n************************************************************** \n");

Tgt9File=fopen("Stn9_tgt_data","a");
fprintf(Tgt9File,"\n**********************Stn9 Tgt DATA************************** \n");
fprintf(Tgt9File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Tgt9File,"\n************************************************************** \n");

Tgt10File=fopen("Stn10_tgt_data","a");
fprintf(Tgt10File,"\n**********************Stn10 Tgt DATA************************** \n");
fprintf(Tgt10File,"\n\t Conducted on : %s",ctime(&timeval));
fprintf(Tgt10File,"\n************************************************************** \n");*/
    /*===================QT_RC-Connections ends================**/

QFile file("D:/BDL/RCMC_Executable/RC-MCSimulator.exe");
 if(file.open(QIODevice::ReadOnly))
 {
     QByteArray fileData = file.readAll();
     QByteArray hashData = QCryptographicHash::hash(fileData,QCryptographicHash::Md5);
     qDebug()<<hashData.toHex();
     QString digest = hashData.toHex();
     ui->Checksum_Read->setText(digest);
     ui->Version_read->setText("ASTRAMKI_v1.0");
     qDebug()<<"In Checksum";

 }

}

MainWindow::~MainWindow()
{
    delete ui;

    acestop();
    mc_acestop();

    if(mThread->isRunning())
    {
        mThread->terminate();
        return;
    }
    if(timer->isActive())
    {
        timer->stop();
        return;
    }
    if(timer_t->isActive())
    {
        timer_t->stop();
        return;
    }
    if(upThread->isRunning())
    {
        upThread->terminate();
        return;
    }
    if(mc_timer->isActive())
    {
        mc_timer->stop();
        return;
    }
    if(mc_rtthread->isRunning())
    {
        mc_rtthread->terminate();
        return;
    }
    //    fclose(file_mcw1);
    //    fclose(file_rcw1);
    //    fclose(file_mcw2);
    //    fclose(file_rcw2);
    //    fclose(file_mcw3);
    //    fclose(file_rcw3);
    //    fclose(file_mcw4);
    //    fclose(file_rcw4);
     //   fclose(file_man); //22082023

}

void MainWindow::mc_rtConfig()  //new function...
{

    printf("RT Thread started\n");
    //   qDebug()<<" inside rt threads";
    nResult = aceInitialize(DevNumRT,ACE_ACCESS_CARD,ACE_MODE_RT,0,0,0);
    if(nResult)
    {
        printf("Initialize ");
        PrintOutError(nResult);
    }
    // Legalize msgs received by the RT own address and mode code 17 (Synchronize with Data)
    aceRTMsgLegalityEnable(0,ACE_RT_MODIFY_ALL,ACE_RT_MODIFY_ALL,ACE_RT_MODIFY_ALL, ACE_RT_SA5);
    // Create DBLK3 for RT
    aceRTDataBlkCreate(DevNumRT, DBLK4, ACE_RT_DBLK_SINGLE, wBuffer, 27);
    aceRTDataBlkCreate(DevNumRT, DBLK5, ACE_RT_DBLK_SINGLE, wBuffer, 20);
    aceRTDataBlkCreate(DevNumRT, DBLK6, ACE_RT_DBLK_SINGLE, wBuffer, 18);

    aceRTSetAddress(DevNumRT,wRTAddress); //Set RT [or latch (BU-65565 only)] address

    aceRTDataBlkMapToSA(DevNumRT, DBLK4, 1, ACE_RT_MSGTYPE_TX, 0, TRUE);	// Map data block to given sub-address
    aceRTDataBlkMapToSA(DevNumRT, DBLK5, 2, ACE_RT_MSGTYPE_TX, 0, TRUE);
    aceRTDataBlkMapToSA(DevNumRT, DBLK6, 3, ACE_RT_MSGTYPE_TX, 0, TRUE);

    aceSetTimeTagRes(DevNumRT,ACE_TT_64US);  // sets time tag res
    if(nResult < 0)
    {
        printf("Error in aceSet-TimeTagRes() function \n");
        PrintOutError(nResult);
        return;
    }
    aceRTInstallHBuf(DevNumRT,(512*ACE_MSGSIZE_BC)*4 *3); // Create Host Buffer

    // Poll for messages
    aceRTStart(DevNumRT);   // Start RT Device

}
void MainWindow::mc_BcConfig()   // new function
{

   qDebug()<<"BC Thread started";

    wResult = aceInitialize(DevNumBC,ACE_ACCESS_CARD,ACE_MODE_BC,0,0,0);
    if(wResult)
    {
        printf("Initialize ");
        PrintOutError(wResult);
    }
    wResult = aceBCConfigure(DevNumBC,ACE_BC_ASYNC_HMODE);
    if(wResult)
    {
        PrintOutError(wResult);
    }
    // Create 4 data blocks
    aceBCDataBlkCreate(DevNumBC,DBLK1,32,wBuffer,27);
    aceBCDataBlkCreate(DevNumBC,DBLK2,32,wBuffer,20);
    aceBCDataBlkCreate(DevNumBC,DBLK3,32,wBuffer,18);
    // Create message block
    aceBCMsgCreateRTtoBC(
                DevNumBC,              	// Device number
                MSG1,                	// Message ID to create
                DBLK1,               	// Message will use this data block
                wRTAddress,                 // RT address
                1,                   	// RT subaddress
                27,            		// Word count
                0,                   	// Default message timer
                ACE_BCCTRL_CHL_A);   	// use chl A options

    aceBCMsgCreateRTtoBC(DevNumBC,MSG2,DBLK2,wRTAddress,2,20,0,ACE_BCCTRL_CHL_A);
    aceBCMsgCreateRTtoBC(DevNumBC,MSG3,DBLK3,wRTAddress,3,18,0,ACE_BCCTRL_CHL_A);

    // Create XEQ opcode that will use msg block
    aceBCOpCodeCreate(DevNumBC,OP_MSG1,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG1,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MSG2,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG2,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MSG3,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG3,0,0);

    // Create CAL opcode that will call mnr frame from major
    aceBCOpCodeCreate(DevNumBC,OP_MNR1,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR1,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR2,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR2,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR3,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR3,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR4,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR4,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR5,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR5,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR6,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR6,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR7,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR7,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR8,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR8,0,0);

    // Create Minor Frame
    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG3;
    aceBCFrameCreate(DevNumBC,MNR1,ACE_FRAME_MINOR,aOpCodes,2,0,0); // mnr frm 1 = msg1, msg3

    // Create Minor Frame
    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR2,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 2 = msg1, msg4

    // Create Minor Frame
    aOpCodes[0] = OP_MSG1;
    aceBCFrameCreate(DevNumBC,MNR3,ACE_FRAME_MINOR,aOpCodes,1,0,0); //mnr frm 3 = msg1,

    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR4,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 3 = msg1,msg4

    aOpCodes[0] = OP_MSG1;
    aceBCFrameCreate(DevNumBC,MNR5,ACE_FRAME_MINOR,aOpCodes,1,0,0); //mnr frm 3 = msg1

    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR6,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 3 = msg1,msg4

    aOpCodes[0] = OP_MSG1;
    aceBCFrameCreate(DevNumBC,MNR7,ACE_FRAME_MINOR,aOpCodes,1,0,0); //mnr frm 3 = msg1

    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR8,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 3 = msg1,msg4

    // Create Major Frame
    aOpCodes[0] = OP_MNR1;		//msg 1,3
    aOpCodes[1] = OP_MNR2;		//msg 1,4
    aOpCodes[2] = OP_MNR3;		//msg 1
    aOpCodes[3] = OP_MNR4;		//msg 1,4
    aOpCodes[4] = OP_MNR5;		//msg 1
    aOpCodes[5] = OP_MNR6;		//msg 1,4
    aOpCodes[6] = OP_MNR7;		//msg 1
    aOpCodes[7] = OP_MNR8;                //msg 1,4
    aceBCFrameCreate(DevNumBC,MJR,ACE_FRAME_MAJOR,aOpCodes,8,100 ,0);

    aceBCInstallHBuf(DevNumBC,(512*ACE_MSGSIZE_BC)*4 *3);   // Create Host Buffer
    //  nResult = aceSetTimeTagRes (DevNumBC,ACE_TT_64US);
    aceBCStart(DevNumBC,MJR,-1);	// Start BC

}

void MainWindow::rc_initialize() //rcintialization
{
    printf("\n new version\n");
    // card initialization and message creation

    wResult=aceInitialize(DevNum,ACE_ACCESS_CARD,ACE_MODE_BC,0,0,0);

    if(wResult)
    {
        printf("Initialize ");
        PrintOutError(wResult);
    }

    aceSetIrqConditions(DevNum,true,ACE_IMR2_BC_UIRQ3, funcExternalISR);
    /*create data  block*/
    aceBCDataBlkCreate(DevNum,DBLK1,32,dstd1,32);
    aceBCDataBlkCreate(DevNum,DBLK2,32,dstd2,32);
    aceBCDataBlkCreate(DevNum,DBLK3,32,dstd3,32);
    aceBCDataBlkCreate(DevNum,DBLK4,32,dstd4,32);
    aceBCDataBlkCreate(DevNum,DBLK5,32,lotd,32);

    // for MSLP message
    aceBCDataBlkCreate(DevNum,DBLK6,32,wBuffer,32); //rt7
    aceBCDataBlkCreate(DevNum,DBLK7,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK8,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK9,32,wBuffer,32); //rt10

    // change made target data
    aceBCDataBlkCreate(DevNum,DBLK10,32,wBuffer,32); //rt7
    aceBCDataBlkCreate(DevNum,DBLK11,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK12,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK13,32,wBuffer,32); //rt10

    // DATA BLOCK FOR HMDS MESSAGES 3RD Dec 2015

    // change made target data
    aceBCDataBlkCreate(DevNum,DBLK14,32,wBuffer,32); //rt7
    //   aceBCDataBlkCreate(DevNum,DBLK15,32,wBuffer,32);
    //   aceBCDataBlkCreate(DevNum,DBLK16,32,wBuffer,32);
    //   aceBCDataBlkCreate(DevNum,DBLK17,32,wBuffer,32); //rt10

    // change made Dl_seeker freq data
    aceBCDataBlkCreate(DevNum,DBLK15,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK16,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK17,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK18,32,wBuffer,32);

    // change made Dl_seeker freq data_ack
    aceBCDataBlkCreate(DevNum,DBLK19,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK20,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK21,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK22,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK23,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK24,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK25,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK26,32,wBuffer,32);//ADDED DBLK23-26 FOR SURVEILLANCE MESSAGE
    aceBCDataBlkCreate(DevNum,DBLK23,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK24,32,wBuffer,32);
    aceBCDataBlkCreate(DevNum,DBLK25,32,wBuffer,32);
   // aceBCDataBlkCreate(DevNum,DBLK25,32,wBuffer,32);


    //BroAD CAST MESSAGE FOR RC TARGET DATA

    aceBCMsgCreateBcst(DevNum,MSG1,DBLK1,1,32,0,ACE_BCCTRL_CHL_A);
    aceBCMsgCreateBcst(DevNum,MSG2,DBLK2,2,32,0,ACE_BCCTRL_CHL_A);
    aceBCMsgCreateBcst(DevNum,MSG3,DBLK3,3,32,0,ACE_BCCTRL_CHL_A);
    aceBCMsgCreateBcst(DevNum,MSG4,DBLK4,4,32,0,ACE_BCCTRL_CHL_A);
    aceBCMsgCreateBcst(DevNum,MSG5,DBLK5,5,32,0,ACE_BCCTRL_CHL_A);

    /* Create message block *///------------
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG6,                /* Message ID to create             */
                DBLK6,               /* Message will use this data block */
                7,                   /* RT address                       */
                1,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG7,                /* Message ID to create             */
                DBLK7,               /* Message will use this data block */
                8,                   /* RT address                       */
                1,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG8,                /* Message ID to create             */
                DBLK8,               /* Message will use this data block */
                9,                   /* RT address                       */
                1,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG9,                /* Message ID to create             */
                DBLK9,               /* Message will use this data block */
                10,                   /* RT address                       */
                1,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    // Target Data change made----------------------RT2BC-------------------------------------
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG10,                /* Message ID to create             */
                DBLK10,               /* Message will use this data block */
                7,                   /* RT address                       */
                2,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG11,                /* Message ID to create             */
                DBLK11,               /* Message will use this data block */
                8,                   /* RT address                       */
                2,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG12,                /* Message ID to create             */
                DBLK12,               /* Message will use this data block */
                9,                   /* RT address                       */
                2,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG13,                /* Message ID to create             */
                DBLK13,               /* Message will use this data block */
                10,                   /* RT address                       */
                2,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options  */

    /////////////////////////////HMDS BROADCAST///////////////////////////

    aceBCMsgCreateBcst(DevNum,MSG14,DBLK14,6,32,0,ACE_BCCTRL_CHL_A);

    ///////////////////////////DL_seeker_freq RT7-10///////////////////////////

    aceBCMsgCreateBCtoRT(
                DevNum,              /* Device number                    */
                MSG15,                /* Message ID to create             */
                DBLK15,               /* Message will use this data block */
                7,                   /* RT address                       */
                7,                   /* RT subaddress                    */
                5,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    /* Create message block */
    aceBCMsgCreateBCtoRT(
                DevNum,              /* Device number                    */
                MSG16,                /* Message ID to create             */
                DBLK16,               /* Message will use this data block */
                8,                   /* RT address                       */
                7,                   /* RT subaddress                    */
                5,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    /* Create message block */
    aceBCMsgCreateBCtoRT(
                DevNum,              /* Device number                    */
                MSG17,                /* Message ID to create             */
                DBLK17,               /* Message will use this data block */
                9,                   /* RT address                       */
                7,                   /* RT subaddress                    */
                5,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    /* Create message block */
    aceBCMsgCreateBCtoRT(
                DevNum,              /* Device number                    */
                MSG18,                /* Message ID to create             */
                DBLK18,               /* Message will use this data block */
                10,                   /* RT address                       */
                7,                   /* RT subaddress                    */
                5,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options  */


    ///////////////////////////DL_seeker_freq_Ack RT7-10///////////////////////////

    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG19,                /* Message ID to create             */
                DBLK19,               /* Message will use this data block */
                7,                   /* RT address                       */
                3,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    // Target Data change made
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG20,                /* Message ID to create             */
                DBLK20,               /* Message will use this data block */
                8,                   /* RT address                       */
                3,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG21,                /* Message ID to create             */
                DBLK21,               /* Message will use this data block */
                9,                   /* RT address                       */
                3,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG22,                /* Message ID to create             */
                DBLK22,               /* Message will use this data block */
                10,                   /* RT address                       */
                3,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    ///////////////////////////SURVEILLANCE MESSAGE RT7-10///////////////////////////

    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG23,                /* Message ID to create             */
                DBLK23,               /* Message will use this data block */
                7,                   /* RT address                       */
                4,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    // Target Data change made
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG24,                /* Message ID to create             */
                DBLK24,               /* Message will use this data block */
                8,                   /* RT address                       */
                4,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG25,                /* Message ID to create             */
                DBLK25,               /* Message will use this data block */
                9,                   /* RT address                       */
                4,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */
    /* Create message block */
    aceBCMsgCreateRTtoBC(
                DevNum,              /* Device number                    */
                MSG26,                /* Message ID to create             */
                DBLK26,               /* Message will use this data block */
                10,                   /* RT address                       */
                4,                   /* RT subaddress                    */
                32,                  /* Word count                       */
                0,                   /* Default message timer            */
                ACE_BCCTRL_CHL_A);   /* use chl A options                */

    aceBCOpCodeCreate(DevNum,OP1,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG1,0,0);
    aceBCOpCodeCreate(DevNum,OP2,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG2,0,0);
    aceBCOpCodeCreate(DevNum,OP3,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG3,0,0);
    aceBCOpCodeCreate(DevNum,OP4,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG4,0,0);
    aceBCOpCodeCreate(DevNum,OP5,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG5,0,0);
    aceBCOpCodeCreate(DevNum,OP6,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG6,0,0);
    aceBCOpCodeCreate(DevNum,OP7,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG7,0,0);
    aceBCOpCodeCreate(DevNum,OP8,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG8,0,0);
    aceBCOpCodeCreate(DevNum,OP9,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG9,0,0);

    //Target Data change
    aceBCOpCodeCreate(DevNum,OP10,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG10,0,0);
    aceBCOpCodeCreate(DevNum,OP11,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG11,0,0);
    aceBCOpCodeCreate(DevNum,OP12,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG12,0,0);
    aceBCOpCodeCreate(DevNum,OP13,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG13,0,0);

    //HMDS Data change
    aceBCOpCodeCreate(DevNum,OP14,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG14,0,0);
    //   aceBCOpCodeCreate(DevNum,OP15,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG15,0,0);
    //   aceBCOpCodeCreate(DevNum,OP16,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG16,0,0);
    //   aceBCOpCodeCreate(DevNum,OP17,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG17,0,0);

    //DL_seeker_freq_change
    aceBCOpCodeCreate(DevNum,OP15,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG15,0,0);
    aceBCOpCodeCreate(DevNum,OP16,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG16,0,0);
    aceBCOpCodeCreate(DevNum,OP17,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG17,0,0);
    aceBCOpCodeCreate(DevNum,OP18,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG18,0,0);


    //DL_seeker_freq_Ack_change
    aceBCOpCodeCreate(DevNum,OP19,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG19,0,0);
    aceBCOpCodeCreate(DevNum,OP20,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG20,0,0);
    aceBCOpCodeCreate(DevNum,OP21,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG21,0,0);
    aceBCOpCodeCreate(DevNum,OP22,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG22,0,0);

    //SURVEILLANCE MESSAGES
    aceBCOpCodeCreate(DevNum,OP23,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG23,0,0);
    aceBCOpCodeCreate(DevNum,OP24,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG24,0,0);
    aceBCOpCodeCreate(DevNum,OP25,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG25,0,0);
    aceBCOpCodeCreate(DevNum,OP26,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG26,0,0);


    /* Create WFT opcode for the timer to wait untill the end of frame */
    aceBCOpCodeCreate(DevNum,OP27,ACE_OPCODE_WFT,ACE_CNDTST_ALWAYS,0,0,0);

    /* Create IRQ opcode for generating interrupt at the end of frame */
    aceBCOpCodeCreate(DevNum,OP28,ACE_OPCODE_IRQ,ACE_CNDTST_ALWAYS,0x0008,0,0);

    aceBCOpCodeCreate(DevNum,OP29,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR1,0,0);

    aOpCodes[0] = OP1;
    aOpCodes[1] = OP2;
    aOpCodes[2] = OP3;
    aOpCodes[3] = OP4;
    aOpCodes[4] = OP5;
    aOpCodes[5] = OP6;
    aOpCodes[6] = OP7;
    aOpCodes[7] = OP8;
    aOpCodes[8] = OP9;
    aOpCodes[9] = OP10;
    aOpCodes[10] = OP11;
    aOpCodes[11] = OP12;
    aOpCodes[12] = OP13;
    aOpCodes[13] = OP14;
    aOpCodes[14] = OP15;
    aOpCodes[15] = OP16;
    aOpCodes[16] = OP17;
    aOpCodes[17] = OP18;
    aOpCodes[18] = OP19;
    aOpCodes[19] = OP20;
    aOpCodes[20] = OP21;
    aOpCodes[21] = OP22;
    aOpCodes[22] = OP23;
    aOpCodes[23] = OP24;
    aOpCodes[24] = OP25;
    aOpCodes[25] = OP26;
    aOpCodes[26] = OP27;
    aOpCodes[27] = OP28;
    //   aOpCodes[24] = OP25;
    //   aOpCodes[25] = OP26;
    //   aOpCodes[26] = OP27;

    aceBCFrameCreate(DevNum,MNR1,ACE_FRAME_MINOR,aOpCodes,28,0,0);

    aOpCodes[0] = OP29;
    aceBCFrameCreate(DevNum,MJR,ACE_FRAME_MAJOR,aOpCodes,1,200,0);

    /* Create Host Buffer */
    aceBCInstallHBuf(DevNum,32*1024);

}

void MainWindow::UpdateGUIData() // mslp update gui...
{
    time_t timeval;
    (void) time (&timeval);
        if((ui->station_select1->currentText()== "Station 7") & (stn_flag==0))
       {
            stn_flag=1;
            fprintf(Autolaunch_file,"\t RT  Stn:7\n");
            fprintf(Autolaunch_file,"\n\t  --------PBIT--------- ");


        }

        if((ui->station_select1->currentText()== "Station 8") & (stn_flag==0))
        {
            stn_flag=2;
            fprintf(Autolaunch_file,"\t RT Stn:8\n");
            fprintf(Autolaunch_file,"\n\t  --------PBIT--------- ");



        }
        if((ui->station_select1->currentText()== "Station 9") & (stn_flag==0))
        {
            stn_flag=3;
            fprintf(Autolaunch_file,"\t RT  Stn:9\n");
            fprintf(Autolaunch_file,"\n\t  --------PBIT--------- ");


        }
        if((ui->station_select1->currentText()== "Station 10") & (stn_flag==0))
        {
            stn_flag=4;
            fprintf(Autolaunch_file,"\t RT  Stn:10\n");
            fprintf(Autolaunch_file,"\n\t  --------PBIT--------- ");


        }

    QPalette palettered,palettegreen,paletteyellow;
    palettered.setColor(QPalette::Text,Qt::red);
    palettegreen.setColor(QPalette::Text,Qt::green);
    paletteyellow.setColor(QPalette::Text,Qt::yellow);
    /**********MHW-WORD0**************/




    Maneuver=((mslp_res_data[0]) >>1) & 0x0100; //Maneuver Required
    if(Maneuver==0x0100)
    {
        ui->manever->clear();
        ui->manever->setText("Required");
     //   ui->manever->setStyleSheet("color: rgb(235, 120, 255);");
        ui->manever->setPalette(palettegreen);

        mNrQ=true;
      //  printf ("\n ever Received \n");
    }
    else
    {
        ui->manever->setPalette(palettered);
        ui->manever->clear();
        ui->manever->setText("Not Required");
        mNrQ=false;
    }
    Transfer_align= ((mslp_res_data[0]) ) & 0x01C0;   // Transfer Alignment Sts
    if(Transfer_align==0x0000)
    {
        ui->ta_sts->setPalette(palettered);
        ui->ta_sts->clear();
        ui->ta_sts->setText("Not Started");
//        ui->ta_sts->setStyleSheet("background-color:#FF0000;color: #0000FF;");
        ui->tasts_GrpBox->setStyleSheet("background-color: rgb(255, 0, 0);"); //red


    }
    if(Transfer_align==0x0040)
    {
        ui->ta_sts->clear();
        ui->ta_sts->setText("Progress");
        //  ui->tasts_GrpBox->setStyleSheet("background-color: rgb(255, 85, 0);"); //orange
        ui->tasts_GrpBox->setStyleSheet("background-color: rgb(255, 250, 0);"); //yellow
    }
    if(Transfer_align==0x0080)
    {
        ui->ta_sts->clear();
        ui->ta_sts->setText("Single Shot TA");
    }
    if(Transfer_align==0x00C0)
    {
        ui->ta_sts->clear();
        ui->ta_sts->setText("Converged");
        ui->tasts_GrpBox->setStyleSheet("background-color: rgb(0, 170, 127);"); //green

    }
    if(Transfer_align==0x0100)
    {
        ui->ta_sts->clear();
        ui->ta_sts->setText("Fine TA");
    }
    if(Transfer_align==0x0140)
    {
        ui->ta_sts->clear();
        ui->ta_sts->setText("Nav Mode");
    }
    if(Transfer_align==0x01C0)
    {
        ui->ta_sts->setPalette(palettered);
        ui->ta_sts->clear();
        ui->ta_sts->setText("NO MINS Data");
    }
    Mis_Avail = ((mslp_res_data[0])>>5) & 0x0001; // missile availability on station
    if(Mis_Avail==0x0001)
    {
        ui->mis_avail->setPalette(palettegreen);
        ui->mis_avail->clear();
        ui->mis_avail->setText("Available");
    }
    else
    {
        ui->mis_avail->setPalette(palettered);
        ui->mis_avail->clear();
        ui->mis_avail->setText("Not Available");
    }
    msl_val = mslp_res_data[0] &0x8000;
  //  if(msl_val==0x8000)  // If valid
 //   {
        mis_rdy= mslp_res_data[0] & 0x0008;
        if(mis_rdy==0x0008)
        {
            ui->mis_rdy->setPalette(palettegreen);
            ui->mis_rdy->clear();
            ui->mis_rdy->setText("OK");
        }
        else
        {
            ui->mis_rdy->setPalette(palettered);
            ui->mis_rdy->clear();
            ui->mis_rdy->setText("NOT OK");
        }


        Astra_state= mslp_res_data[0] & 0x3C00;
        if(Astra_state == 0x0000)
        {
            ui->AstraState->setPalette(palettegreen);
            ui->AstraState->setText("INIT");
        }
        if(Astra_state == 0x0400)
        {
            ui->AstraState->setPalette(palettegreen);
            ui->AstraState->setText("STANDBY");
        }
         if(Astra_state == 0x0800)
        {
             ui->AstraState->setPalette(palettegreen);
            ui->AstraState->setText("PBIT");
        }
        if(Astra_state == 0x0C00)
       {
            ui->AstraState->setPalette(palettegreen);
            ui->AstraState->setText("PRELAUNCH");
        }
        if(Astra_state == 0x1000)
        {
            ui->AstraState->setPalette(palettegreen);
            ui->AstraState->setText("AUTOLAUNCH ");
        }

        if(Astra_state == 0x1400)
        {
            ui->AstraState->setPalette(palettegreen);
              ui->AstraState->setText("FLIGHT ");
        }
        if(Astra_state == 0x1800)
        {
            ui->AstraState->setPalette(palettegreen);
            ui->AstraState->setText("ONLY_LAUNCHER");
        }
        if(Astra_state == 0x3400)
        {
            ui->AstraState->setPalette(palettegreen);
           ui->AstraState->setText("NOGO ");
        }
         if(Astra_state == 0x0008)
         {
             ui->AstraState->setPalette(palettegreen);
             ui->AstraState->setText("IBIT");

         }
          if(Astra_state == 0x0020)
          {
              ui->AstraState->setPalette(palettegreen);
              ui->AstraState->setText("EMERGENCY LAUNCH");
          }



        apole_valid=mslp_res_data[0]&0x0004;
        if(apole_valid==0x0004)
        {
            ui->apole_valid->setPalette(palettegreen);
            ui->apole_valid->clear();
            ui->apole_valid->setText("VALID");
        }
        else
        {
            ui->apole_valid->setPalette(palettered);
            ui->apole_valid->clear();
            ui->apole_valid->setText("InVALID");
        }
        mis_rel=((mslp_res_data[0]) >>1) & 0x0001; //Missile Released
        if(mis_rel==0x0001)
        {
            ui->mis_rel->setPalette(palettegreen);
            ui->mis_rel->setText("Released");
        }
        else
        {
            ui->mis_rel->setPalette(palettered);
            ui->mis_rel->setText("Not Released");
        }
        mis_hlth=((mslp_res_data[0])) & 0x0001;
        if(mis_hlth==0x0001)
        {
            ui->mis_hlth->setPalette(palettegreen);
            ui->mis_hlth->setText("OK");
        }
        else
        {
            ui->mis_hlth->setPalette(palettered);
            ui->mis_hlth->setText("Not OK");
        }


    /*****LHW-WORD1******/
    mis_state=mslp_res_data[1] & 0x3000;
    if(mis_state==0x0000)
    {
        ui->mis_state->setPalette(palettered);
        ui->mis_state->setText("NO-GO");
    }
    if(mis_state==0x1000)
    {
        ui->mis_state->setText("PBIT in Progress"); // pchange..
        // ui->pbit_GrpBox->setStyleSheet("background-color: rgb(255, 100, 0);");
        ui->pbit_GrpBox->setStyleSheet("background-color: rgb(255, 250, 0);");//yellow
    }

    if(mis_state==0x2000)
    {
        ui->mis_state->setPalette(palettegreen);
        ui->mis_state->setText("Ready after PBIT");
        ui->pbit_GrpBox->setStyleSheet("background-color: rgb(0, 170, 127);");
    }

    amlp_hlth=mslp_res_data[1] & 0x0001;
    if(amlp_hlth == 0x0001)
    {
        ui->amlp_hlth->setPalette(palettegreen);
        ui->amlp_hlth->setText("OK");
    }
    else
    {
        ui->amlp_hlth->setPalette(palettered);
        ui->amlp_hlth->setText("NOT OK");
    }

    apsu_sts=mslp_res_data[1] & 0x0080;
    if(apsu_sts == 0x0080)
    {
        ui->apsu_sts->setPalette(palettegreen);
        ui->apsu_sts->setText("OK");
    }
    else
    {
        ui->apsu_sts->setPalette(palettered);
        ui->apsu_sts->setText("NOT OK");
    }
    DLTx_init= mslp_res_data[1] & 0x0040;
    if(DLTx_init == 0x0040)
    {
        ui->DLTx_init->setPalette(palettegreen);
        ui->DLTx_init->setText("OK");
    }
    else
    {
        ui->DLTx_init->setPalette(palettered);
        ui->DLTx_init->setText("NOT OK");
    }
    DLTx_sts= mslp_res_data[1] & 0x0020;
    if(DLTx_sts == 0x0020)
    {
        ui->DLTx_sts->setPalette(palettegreen);
        ui->DLTx_sts->setText("OK");
    }
    else
    {
        ui->DLTx_sts->setPalette(palettered);
        ui->DLTx_sts->setText("NOT OK");
    }

    mins_data= mslp_res_data[1] & 0x0008;
    if(mins_data == 0x0008)
    {
        ui->mins_data->setPalette(palettegreen);
        ui->mins_data->setText("Available");
    }
    else
    {
        ui->mins_data->setPalette(palettered);
        ui->mins_data->setText("No MINS Data");
    }
    lau_val=mslp_res_data[1]  & 0x8000;  // check for validity for BIT13
    if(lau_val==0x8000)
    {
        launch_hlth= mslp_res_data[1] & 0x0004;
        if(launch_hlth == 0x0004)
        {
            ui->launch_hlth->setPalette(palettegreen);
            ui->launch_hlth->setText("OK");
        }
    }
    else
    {
        ui->launch_hlth->setPalette(palettered);
        ui->launch_hlth->setText("NOT OK");
    }
    DLZ_valid= mslp_res_data[1] & 0x0002;
    if(DLZ_valid == 0x0002)
    {
        ui->DLZ_valid->setPalette(palettegreen);
        ui->DLZ_valid->setText("OK");
    }
    else
    {
        ui->DLZ_valid->setPalette(palettered);
        ui->DLZ_valid->setText("NOT OK");
    }
    astra_hlth= mslp_res_data[1] & 0x4000;
    if(astra_hlth == 0x4000)
    {
        ui->astra_hlth->setPalette(palettegreen);
        ui->astra_hlth->setText("OK");
    }
    else
    {
        ui->astra_hlth->setPalette(palettered);
        ui->astra_hlth->setText("NOT OK");
    }
    int dl_stat= mslp_res_data[1] & 0x0c00;
    if(dl_stat == 0x0800) ///****DATALINK STATUS*****/
    {
        ui->datalink_Ldt->setPalette(palettegreen);
        ui->datalink_Ldt->setText("OK");
        ui->datalnk_GrpBox->setStyleSheet("background-color: rgb(0, 170, 127);");//GREEN
    }else if(dl_stat == 0x0400)
    {
        ui->datalink_Ldt->setPalette(paletteyellow);
        ui->datalink_Ldt->setText("In Progress");
        ui->datalnk_GrpBox->setStyleSheet("background-color: rgb(255, 250, 0);");//yellow
    }
    else if(dl_stat == 0x0000)
    {
        ui->datalink_Ldt->setPalette(palettered);
        ui->datalink_Ldt->setText("NOT OK");
        ui->datalnk_GrpBox->setStyleSheet("background-color: rgb(255, 0, 0);");//RED
    }

    int dlt_hp_req = mslp_res_data[1] & 0x0200;
    if (dlt_hp_req == 0x0200) ///****DLTx HP MODEREQUIRED STATUS*****/
    {
        ui->dlpmode_Req_Ldt->setPalette(palettegreen);
        ui->dlpmode_Req_Ldt->setText("YES");
    }
    else
    {
        ui->dlpmode_Req_Ldt->setPalette(palettered);
        ui->dlpmode_Req_Ldt->setText("NOT REQ");

    }
    if((mslp_res_data[1] & 0x0020) == 0x0020) ///****DLT Switchover STATUS*****/
    {
        ui->dltswtchover_Ldt->setPalette(palettegreen);
        ui->dltswtchover_Ldt->setText("OK");
    }else
    {
        ui->dltswtchover_Ldt->setPalette(palettered);
        ui->dltswtchover_Ldt->setText("NOT OK");
    }


    filament27= mslp_res_data[16] & 0x8000;
    if(filament27 == 0x8000)
    {
        ui->filament27->setPalette(palettered);
        ui->filament27->setText("OFF");
    }
    else
    {
        ui->filament27->setPalette(palettegreen);
        ui->filament27->setText("ON");
        //filament_flag=1;
    }


    boost_fire= mslp_res_data[16] & 0x4000;
    if(boost_fire == 0x4000)
    {
      //  qDebug()<< "TriggerIF : "<<boost_fire;
        ui->boost_fire->setPalette(palettered);
        ui->boost_fire->setText("OFF");
    }
    else
    {
   //    qDebug()<< "TriggerELSE : "<<boost_fire;
        ui->boost_fire->setPalette(palettegreen);
        ui->boost_fire->setText("BSTON");
        //Boosterflag=1;
    }
    ltb_fire= mslp_res_data[16] & 0x2000;
    if(ltb_fire == 0x2000)
    {
        ui->ltb_fire->setPalette(palettered);
        ui->ltb_fire->setText("OFF");
    }
    else
    {
       // Ltbflag=1;
        ui->ltb_fire->setPalette(palettegreen);
        ui->ltb_fire->setText("ON");

    }
    unguid_lanuch= mslp_res_data[16] & 0x1000;
    if(unguid_lanuch == 0x1000)
    {
        ui->unguid_lanuch->setPalette(palettered);
        ui->unguid_lanuch->setText("NOT issued");
    }
    else
    {
        ui->unguid_lanuch->setPalette(palettegreen);
        ui->unguid_lanuch->setText("Issued ");
    }
    lanuch2_sts= mslp_res_data[16] & 0x0800;
    if(lanuch2_sts == 0x0800)
    {
        ui->lanuch2_sts->setPalette(palettered);
        ui->lanuch2_sts->setText("NOT issued");
    }
    else
    {
        ui->lanuch2_sts->setPalette(palettegreen);
        ui->lanuch2_sts->setText("Issued ");
    }
    lanuch1_sts= mslp_res_data[16] & 0x0400;
    if(lanuch1_sts == 0x0400)
    {
        ui->lanuch1_sts->setPalette(palettered);
        ui->lanuch1_sts->setText("NOT issued");
    }
    else
    {
        ui->lanuch1_sts->setPalette(palettegreen);
        ui->lanuch1_sts->setText("Issued ");
        //L1flag=1;
    }
    umbilical_sts= mslp_res_data[16] & 0x0200;
    if(umbilical_sts == 0x0200)
    {
        ui->umbilical_sts->setPalette(palettered);
        ui->umbilical_sts->setText("Unmated");
    }
    else
    {
        ui->umbilical_sts->setPalette(palettegreen);
        ui->umbilical_sts->setText("Mated");
    }
    SAM_sts= mslp_res_data[16] & 0x0100;
    if(SAM_sts == 0x0100)
    {
        ui->SAM_sts->setPalette(palettered);
        ui->SAM_sts->setText("OFF");
    }
    else
    {
        ui->SAM_sts->setPalette(palettegreen);
        ui->SAM_sts->setText("ON");
        //samflag=2;
    }
    ready_sts=mslp_res_data[16] & 0x0080;
    if(ready_sts == 0x0080)
    {
        ui->ready_sts->setPalette(palettered);
        ui->ready_sts->setText("OFF");
    }
    else
    {
        ui->ready_sts->setPalette(palettegreen);
        ui->ready_sts->setText("ON");
    }
    tel_sts= (mslp_res_data[16]>>2) & 0x0010;
    if(tel_sts == 0x0010)
    {
        ui->tel_sts->setPalette(palettered);
        ui->tel_sts->setText("OFF");
    }
    else
    {
        ui->tel_sts->setPalette(palettegreen);
        ui->tel_sts->setText("ON");
    }
    scu_sts= (mslp_res_data[16]>>1) & 0x0010;
    if(scu_sts == 0x0010)
    {
        ui->scu_sts->setPalette(palettered);
        ui->scu_sts->setText("OFF");
    }
    else
    {
        ui->scu_sts->setPalette(palettegreen);
        ui->scu_sts->setText("ON");
    }
    DLTxsup_sts=mslp_res_data[16] & 0x0010;
    if(DLTxsup_sts == 0x0010)
    {
        //DLTxflag=0;
        ui->DLTxsup_sts->setPalette(palettered);
        ui->DLTxsup_sts->setText("OFF");
    }
    else
    {

        ui->DLTxsup_sts->setPalette(palettegreen);
        ui->DLTxsup_sts->setText("ON");
         //DLTxflag=1;

    }


    elec_subsys_sts= (mslp_res_data[16]>>3) & 0x0001;
    if(elec_subsys_sts == 0x0001)
    {
        ui->elec_subsys_sts->setPalette(palettered);
        ui->elec_subsys_sts->setText("OFF");
    }
    else
    {
        ui->elec_subsys_sts->setPalette(palettegreen);
        ui->elec_subsys_sts->setText("ON");
    }
    seekr_htr_sts= (mslp_res_data[16]>>2) & 0x0001;
    if(seekr_htr_sts == 0x0001)
    {
        ui->seekr_htr_sts->setPalette(palettered);
        ui->seekr_htr_sts->setText("OFF");
    }
    else
    {
        ui->seekr_htr_sts->setPalette(palettegreen);
        ui->seekr_htr_sts->setText("ON");
    }
    seekr_elec_sts= (mslp_res_data[16]>>1) & 0x0001;
    if(seekr_elec_sts == 0x0001)
    {
        ui->seekr_elec_sts->setPalette(palettered);
        ui->seekr_elec_sts->setText("OFF");
    }
    else
    {
        ui->seekr_elec_sts->setPalette(palettegreen);
        ui->seekr_elec_sts->setText("ON");
    }
    seekr_tx_sts= mslp_res_data[16] & 0x0001;
    if(seekr_tx_sts == 0x0001)
    {
        ui->seekr_tx_sts->setPalette(palettered);
        ui->seekr_tx_sts->setText("OFF");
    }
    else
    {
        ui->seekr_tx_sts->setPalette(palettegreen);
        ui->seekr_tx_sts->setText("ON");
    }

    validity= mslp_res_data[0] & 0x8000;
    //    if(validity == 0x8000)
    //    {
    flm_sts= mslp_res_data[17] & 0x0020;
    if(flm_sts == 0x0020)
    {
        ui->flm_sts->setText("SAFE");
    }
    else
    {
        ui->flm_sts->setText("ON");
    }
    LTB_a_sts= mslp_res_data[17] & 0x0010;
    if(LTB_a_sts == 0x0010)
    {
        ui->LTB_a_sts->setText("SAFE");
    }
    else
    {
        ui->LTB_a_sts->setText("ON");
    }
    boost2_sts= (mslp_res_data[17]>> 3) & 0x0001;
    if(boost2_sts == 0x0001)
    {
        ui->boost2_sts->setText("SAFE");
    }
    else
    {
        ui->boost2_sts->setText("ON");
    }
    boost1_sts= (mslp_res_data[17]>> 2) & 0x0001;
    if(boost1_sts == 0x0001)
    {
        ui->boost1_sts->setText("SAFE");
    }
    else
    {
        ui->boost1_sts->setText("ON");
    }
    LTB_se_sts= (mslp_res_data[17]>> 1) & 0x0001;
    if(LTB_se_sts == 0x0001)
    {
        ui->LTB_se_sts->setText("SAFE");
    }
    else
    {
        ui->LTB_se_sts->setText("ON");
    }
    LTB_t_sts= mslp_res_data[17] & 0x0001;
    if(LTB_t_sts == 0x0001)
    {
        ui->LTB_t_sts->setText("SAFE");
    }
    else
    {
        ui->LTB_t_sts->setText("ON");
    }
    mlpobc_comm= mslp_res_data[18] & 0x2000;
    if(mlpobc_comm == 0x2000)
    {
        ui->mlpobc_comm->setPalette(palettegreen);
        ui->mlpobc_comm->setText("OK");
    }
    else
    {
        ui->mlpobc_comm->setPalette(palettered);
        ui->mlpobc_comm->setText("NOT OK");
    }
    /*  video_record= mslp_res_data[18]  & 0x1000;
    if(video_record == 0x1000)
    {
        ui->video_record->setPalette(palettegreen);
        ui->video_record->setText("ON");
    }
    else
    {
        ui->video_record->setPalette(palettered);
        ui->video_record->setText("OFF");
    }*/
    mis_mate= mslp_res_data[18] & 0x0800;
    if(mis_mate == 0x0800)
    {
        ui->mis_mate->setPalette(palettegreen);
        ui->mis_mate->setText("ON");
    }
    else
    {
        ui->mis_mate->setPalette(palettered);
        ui->mis_mate->setText("OFF");
    }
    fin_lock= mslp_res_data[18] & 0x0400;
    if(fin_lock == 0x0400)
    {
        ui->fin_lock->setPalette(palettegreen);
        ui->fin_lock->setText("OK");
    }
    else
    {
        ui->fin_lock->setPalette(palettered);
        ui->fin_lock->setText("NOT OK");
    }
    act_null= mslp_res_data[18] & 0x0200;
    if(act_null == 0x0200)
    {
        ui->act_null->setPalette(palettegreen);
        ui->act_null->setText("OK");
    }
    else
    {
        ui->act_null->setPalette(palettered);
        ui->act_null->setText("NOT OK");
    }
    DLRx_init_hlth= mslp_res_data[18] & 0x0100;
    if(DLRx_init_hlth == 0x0100)
    {
        ui->DLRx_init_hlth->setPalette(palettegreen);
        ui->DLRx_init_hlth->setText("OK");
    }
    else
    {
        ui->DLRx_init_hlth->setPalette(palettered);
        ui->DLRx_init_hlth->setText("NOT OK");
    }

    unsigned short int DLRx_hlth;
    DLRx_hlth= mslp_res_data[18] & 0x0080;
    if(DLRx_hlth == 0x0080)
    {
        ui->DLR_Hlth->setPalette(palettegreen);
        ui->DLR_Hlth->setText("OK");
    }
    else
    {
        ui->DLR_Hlth->setPalette(palettered);
        ui->DLR_Hlth->setText("NOT OK");
    }
    ins_cbit= mslp_res_data[18]  & 0x0040;
    if(ins_cbit == 0x0040)
    {
        ui->ins_cbit->setPalette(palettegreen);
        ui->ins_cbit->setText("OK");
    }
    else
    {
        ui->ins_cbit->setPalette(palettered);
        ui->ins_cbit->setText("NOT OK");
    }
    rpf_hlth= mslp_res_data[18] & 0x0020;
    if(rpf_hlth == 0x0020)
    {
        ui->rpf_hlth->setPalette(palettegreen);
        ui->rpf_hlth->setText("OK");
    }
    else
    {
        ui->rpf_hlth->setPalette(palettered);
        ui->rpf_hlth->setText("NOT OK");
    }
    sam_hlth= mslp_res_data[18] & 0x0010;
    if(sam_hlth == 0x0010)
    {
        ui->sam_hlth->setPalette(palettegreen);
        ui->sam_hlth->setText("OK");
    }
    else
    {
        ui->sam_hlth->setPalette(palettered);
        ui->sam_hlth->setText("NOT OK");
    }
    seekr_elec_hlth= mslp_res_data[18] & 0x0008;
    if(seekr_elec_hlth == 0x0008)
    {
        ui->seekr_elec_hlth->setPalette(palettegreen);
        ui->seekr_elec_hlth->setText("OK");
    }
    else
    {
        ui->seekr_elec_hlth->setPalette(palettered);
        ui->seekr_elec_hlth->setText("NOT OK");
    }
    obc_comm= mslp_res_data[18]  & 0x0004;
    if(obc_comm == 0x0004)
    {
        ui->obc_comm->setPalette(palettegreen);
        ui->obc_comm->setText("OK");
    }
    else
    {
        ui->obc_comm->setPalette(palettered);
        ui->obc_comm->setText("NOT OK");
    }
    /*
    DLRx_mask= mslp_res_data[18]  & 0x0002;
    if(DLRx_mask == 0x0002)
    {
        ui->DLRx_mask->setPalette(palettegreen);
        ui->DLRx_mask->setText("OK");
    }
    else
    {
        ui->DLRx_mask->setPalette(palettered);
        ui->DLRx_mask->setText("NOT ok");
    }
    */
    DLTx_mask= (mslp_res_data[18]) & 0x0001;
    if(DLTx_mask == 0x0001)
    {
        ui->DLTx_mask->setText("HP");
    }
    else
    {
        ui->DLTx_mask->setText("LP");

        //fprintf(Autolaunch_file,"DLTx Health:LP");
    }


    Dmax1 = mslp_res_data[3] & 0x00FF;
    itoa(Dmax1,s,10);
    str=s;
    ui-> Dmax_1->clear ();
    ui-> Dmax_1->setText(str);

    Dmax2 =mslp_res_data[2] & 0x00FF;
    itoa(Dmax2,s,10);
    str=s;
    ui-> Dmax_2->clear ();
    ui-> Dmax_2->setText(str);


    Dmin =mslp_res_data[4] & 0x00FF;
    itoa(Dmin,s,10);
    str=s;
    ui-> Dmin->clear ();
    ui-> Dmin->setText(str);


    IRT_range=mslp_res_data[5] * 0.0078125;
    str = QString ( "%1" ).arg( IRT_range, 0, 'f', 1 );
    ui-> irt->clear ();
    ui-> irt->setText(str);

    tla = mslp_res_data[7]   & 0x0FFF;
    str = QString ( "%1" ).arg( tla, 0, 10 );
    ui->tla->clear ();
    ui->tla->insert (str) ;




  //  if((mslp_res_data[0]&0x00002)==0x0002)
  //  {
        tlt= mslp_res_data[8]  & 0x00FF;
        str = QString ( "%1" ).arg(tlt, 0, 10 );
        ui->tlt->clear ();
        ui->tlt->setText(str);
       // fprintf(,"Time to target: %5.3f",str);


        tln = mslp_res_data[9]  & 0x00FF;
        str = QString ( "%1" ).arg(tln, 0, 10 );
        ui->tln->clear ();
        ui->tln->setText(str);
        //fprintf(Autolaunch_file,"Time to peel off: %5.3f",str);

 //   }
//Autolaunch_file
   // else
//    {
//        ui->tlt->setText("0");
//        ui->tln->setText("0");
//    }


     itoa(mslp_res_data[10],s,10);
  //  int setx = (((mslp_res_data[10] - 32767)*60)/65535);
    //  itoa(mslp_res_data[10],s,10);
    str = s ;//QString ( "%1" ).arg( setx, 0, 10 );
    ui->setx->clear ();
    ui->setx->setText(str);

    itoa(mslp_res_data[11],s,10);
    str=s;
    ui->seel->clear ();
    ui->seel->setText(str);

    itoa(mslp_res_data[12],s,10);
    str=s;
    ui->elmon->clear ();
    ui->elmon->setText(str);

    itoa(mslp_res_data[13],s,10);
    str=s;
    ui->dltmon->clear ();
    ui->dltmon->setText(str);


   // int actmon = (((mslp_res_data[14] - 32767)*60)/65535);
    itoa(mslp_res_data[14],s,10);
    str =s; // QString ( "%1" ).arg( actmon, 0, 10 );
    ui->actmon->clear ();
    ui->actmon->setText(str);


    // to display NOGO ID
int abc;
    str = QString ( "%1" ).arg(mslp_res_data[15], 0, 10 );
    ui->le_nogo_id->clear ();
    ui->le_nogo_id->setText(str);
    ui->lineEdit_6->clear ();
    abc = str.toInt();
    switch(abc)                                                    // IMPLEMENTED ON 03-12-2020 ANIL
    {
    case  1:
          ui->lineEdit_6->setText("AMLP PBIT NOT OK");
          break;
    case  2:
          ui->lineEdit_6->setText("WCS DIP FAIL");
          break;

    case  3:
          ui->lineEdit_6->setText("OBC PBIT FAIL");
          break;
    case  4:
          ui->lineEdit_6->setText("DLTx INIT/Health FAIL");
          break;
    case  5:
          ui->lineEdit_6->setText("DLRx INIT/Health FAIL");
          break;
    case  6:
          ui->lineEdit_6->setText("DL LOOPCHECK FAIL");
          break;

    case  7:
          ui->lineEdit_6->setText("MSL HEALTH FAIL");
          break;

    case  8:
          ui->lineEdit_6->setText("NO MINS DATA ");
          break;

    case  9:
          ui->lineEdit_6->setText("TA RESPONSE FAIL");
          break;


    case  10:
          ui->lineEdit_6->setText("NOMINS TO INS(3Sec) FAIL");
          break;


    case  11:
          ui->lineEdit_6->setText("OBC TIME FROZEN");
          break;

    case  12:
          ui->lineEdit_6->setText("MISSILE SUBSYSTEM FAIL AFTER PBIT");
          break;

    case  13:
          ui->lineEdit_6->setText("MLP- OBC Communication Fail");
          break;

    case  14:
          ui->lineEdit_6->setText("No valid MINS data available to AMLP");
          break;

    case  15:
          ui->lineEdit_6->setText("AMLP-NO MODE");
          break;
    case  16:
          ui->lineEdit_6->setText("Air");
          break;

    case  101:
          ui->lineEdit_6->setText("RLT Status NOT OK");
          break;

    case  102:
          ui->lineEdit_6->setText("Actuator Null Status NOT OK");
          break;

    case  103:
          ui->lineEdit_6->setText("NAV Status NOT OK");
          break;

    case  104:
          ui->lineEdit_6->setText("MSL HLT NOT OK after External OFF");
          break;

    case  105:
          ui->lineEdit_6->setText("ACTUATOR NOT OK after External OFF");
          break;

    case  108:
          ui->lineEdit_6->setText("DLTx Hp Health NOT OK");
          break;

   default:
          ui->lineEdit_6->setText("0");
          break;

    }




    missile_test= mslp_res_data[21] & 0x0030;
    if(missile_test == 0x0000)
    {
        ui->missile_test->setPalette(palettered);
        ui->missile_test->clear ();
        ui->missile_test->setText("NA");
    }
    if(missile_test == 0x0010)
    {
        ui->missile_test->setPalette(palettegreen);
        ui->missile_test->clear ();
        ui->missile_test->setText("Astra MK-I");
    }
    if(missile_test == 0x0020)
    {
         ui->missile_test->setPalette(palettegreen);
         ui->missile_test->clear ();
         ui->missile_test->setText("Astra MK-II");
    }
    if(missile_test == 0x0030)
    {
        ui->missile_test->setPalette(palettered);
        ui->missile_test->clear ();
        ui->missile_test->setText("NA");
    }

    launcher_test= mslp_res_data[21] & 0x00C0;
    if(launcher_test == 0x0000)
    {
       ui->launcher_test->setPalette(palettered);
       ui->launcher_test->clear ();
       ui->launcher_test->setText("NA1");
    }
    if(launcher_test == 0x0040)
    {
      ui->launcher_test->setPalette(palettegreen);
      ui->launcher_test->clear ();
      ui->launcher_test->setText("Rail Launcher");
    }
         if(launcher_test == 0x0080)
    {
        ui->launcher_test->setPalette(palettegreen);
        ui->launcher_test->clear ();
        ui->launcher_test->setText("EJ Launcher");
    }
    if(launcher_test == 0x00C0)
    {
        ui->launcher_test->setPalette(palettered);
        ui->launcher_test->setText("NA ");
    }


    modetype = mslp_res_data[22] & 0x01C0;
        if(modetype == 0x0000)
        {
            ui->modetype->setPalette(palettered);
            ui->modetype->setText("NO MODE");
            modeflag=1;
        }

        if(modetype == 0x0040)
        {
            //AMLP_LIVE_MISSILE_MODE = 1,
            ui->modetype->setPalette(palettegreen);
            ui->modetype->setText("LIVE MODE");
            modeflag=2;
        }
        if(modetype == 0x0100)
        {
            // AMLP_MISSILE_SIMULATOR_MODE = 3
            ui->modetype->setPalette(palettegreen);
            ui->modetype->setText("MSL SM MODE");
            modeflag=3;
        }
        if(modetype == 0x0180)
        {
           // AMLP_STORE_SIMULATOR_MODE_MK1 = 2,
            ui->modetype->setPalette(palettegreen);
            ui->modetype->setText("STORE MODE MK1");
            modeflag=4;
        }
        if(modetype == 0x0080)
        {
            //AMLP_STORE_SIMULATOR_MODE_MK2 = 4
            ui->modetype->setPalette(palettegreen);
            ui->modetype->setText("STORE MODE MK1I");
            modeflag=5;
        }
        if(modetype == 0x01C0)
        {
            //AMLP_LAUNCHER_OR_ACS_TRNG_MODE = 0

            ui->modetype->setPalette(palettegreen);
            ui->modetype->setText(" LH/ACS Mode");
            modeflag=6;
        }

    QString str1 = QString("%1").arg(freq_res_stn7[0], 0, 16);
    ui->le_freq_res_stn7->clear ();
    ui->le_freq_res_stn7->setText(str1);

    QString str2 = QString("%1").arg(freq_res_stn8[0], 0, 16);
    ui->le_freq_res_stn8->clear ();
    ui->le_freq_res_stn8->setText(str2);

    QString str3 = QString("%1").arg(freq_res_stn9[0], 0, 16);
    ui->le_freq_res_stn9->clear ();
    ui->le_freq_res_stn9->setText(str3);

    QString str4 = QString("%1").arg(freq_res_stn10[0], 0, 16);
    ui->le_freq_res_stn10->clear ();
    ui->le_freq_res_stn10->setText(str4);

    // code for displaying seeker freq in stn7

    if((freq_res_stn7[0]&0x0080)==0x0080)
    {
        U16BIT temp= freq_res_stn7[0]&0x003F;

        QString str5 = QString("%1").arg(temp, 0, 10);
        //  ui->le_seek_freq_res_stn7->clear ();
        ui->le_seek_freq_res_stn7->setText(str5);
    }
    else
        ui->le_seek_freq_res_stn7->setText("INVALID");

    // code for displaying DL freq in stn7
    if((freq_res_stn7[0]&0x8000)==0x8000)
    {
        U16BIT temp= freq_res_stn7[0]&0x3F00;
        temp=temp>>8;
        QString str6 = QString("%1").arg(temp, 0, 10);
        //  ui->le_DL_freq_res_stn7->clear ();
        ui->le_DL_freq_res_stn7->setText(str6);
    }
    else

        ui->le_DL_freq_res_stn7->setText("INVALID");


    // code for displaying seeker freq in stn8
    if((freq_res_stn8[0]&0x0080)==0x0080)
    {
        U16BIT temp= freq_res_stn8[0]&0x003F;

        QString str7 = QString("%1").arg(temp, 0, 10);
        // ui->le_seek_freq_res_stn8->clear ();
        ui->le_seek_freq_res_stn8->setText(str7);
    }
    else
        ui->le_seek_freq_res_stn8->setText("INVALID");

    // code for displaying DL freq in stn8
    if((freq_res_stn8[0]&0x8000)==0x8000)
    {
        U16BIT temp= freq_res_stn8[0]&0x3F00;
        temp=temp>>8;
        QString str8 = QString("%1").arg(temp, 0, 10);
        //   ui->le_DL_freq_res_stn8->clear ();
        ui->le_DL_freq_res_stn8->setText(str8);
    }
    else
        ui->le_DL_freq_res_stn8->setText("INVALID");



    // code for displaying seeker freq in stn9
    if((freq_res_stn9[0]&0x0080)==0x0080)
    {
        U16BIT temp= freq_res_stn9[0]&0x003F;

        QString str9 = QString("%1").arg(temp, 0, 10);
        // ui->le_seek_freq_res_stn9->clear ();
        ui->le_seek_freq_res_stn9->setText(str9);
    }
    else
        ui->le_seek_freq_res_stn9->setText("INVALID");

    // code for displaying DL freq in stn9
    if((freq_res_stn9[0]&0x8000)==0x8000)
    {
        U16BIT temp= freq_res_stn9[0]&0x3F00;
        temp=temp>>8;
        QString str10 = QString("%1").arg(temp, 0, 10);
        // ui->le_DL_freq_res_stn9->clear ();
        ui->le_DL_freq_res_stn9->setText(str10);
    }
    else
        ui->le_DL_freq_res_stn9->setText("INVALID");



    // code for displaying seeker freq in stn10
    if((freq_res_stn10[0]&0x0080)==0x0080)
    {
        U16BIT temp= freq_res_stn10[0]&0x003F;

        QString str11 = QString("%1").arg(temp, 0, 10);
        // ui->le_seek_freq_res_stn10->clear ();
        ui->le_seek_freq_res_stn10->setText(str11);
    }
    else
        ui->le_seek_freq_res_stn10->setText("INVALID");


    // code for displaying DL freq in stn10
    if((freq_res_stn10[0]&0x8000)==0x8000)
    {
        U16BIT temp= freq_res_stn10[0]&0x3F00;
        temp=temp>>8;
        QString str12 = QString("%1").arg(temp, 0, 10);
        // ui->le_DL_freq_res_stn10->clear ();
        ui->le_DL_freq_res_stn10->setText(str12);
    }
    else
        ui->le_DL_freq_res_stn10->setText("INVALID");

    // Code for displaying DLT code1 and code2

    // stn 7

    str = QString("%1").arg(freq_res_stn7[1], 0, 10);
    ui->le_DL_ch1_code_res_stn7->setText(str);

    str = QString("%1").arg(freq_res_stn7[2], 0, 10);
    ui->le_DL_ch2_code_res_stn7->setText(str);

    // stn8

    str = QString("%1").arg(freq_res_stn8[1], 0, 10);
    ui->le_DL_ch1_code_res_stn8->setText(str);

    str = QString("%1").arg(freq_res_stn8[2], 0, 10);
    ui->le_DL_ch2_code_res_stn8->setText(str);

    //stn9

    str = QString("%1").arg(freq_res_stn9[1], 0, 10);
    ui->le_DL_ch1_code_res_stn9->setText(str);

    str = QString("%1").arg(freq_res_stn9[2], 0, 10);
    ui->le_DL_ch2_code_res_stn9->setText(str);

    //stn10

    str = QString("%1").arg(freq_res_stn10[1], 0, 10);
    ui->le_DL_ch1_code_res_stn10->setText(str);

    str = QString("%1").arg(freq_res_stn10[2], 0, 10);
    ui->le_DL_ch2_code_res_stn10->setText(str);


    union time
    {
        int time_total;
        unsigned short int time_data[2];
    };
    union time mlp_time;

    mlp_time.time_data[0] = mslp_res_data[20];
    mlp_time.time_data[1] = mslp_res_data[19];

    //printf ("\n time is %lf \n",mlp_time.time_total);


    //qDebug()<<"mlp_timer"<<mlp_time.time_total;
qDebug("%4x",mlp_time.time_total);
    float mlp_time1 = mlp_time.time_total/1000;
    str = QString ( "%1" )
            .arg(mlp_time1, 0, 'f',3 );
    // ui->amlp_timer->clear();
    ui->amlp_timer->setText(str);

    /* Missile Target Data Message     *///--------------------------------------------------------------------------------

    //freq response update from AMLP
    // QString str = freq_res_stn7[0].toString();

    ////////////////////////////////// SBTS//////////////////////////////
    int stn7_TA = ((mslp_res_data1[0]) ) & 0x01C0;
    if(stn7_TA==0x0000) {
        ui->lE_cI7->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
    }else if(stn7_TA==0x0040) {
        ui->lE_cI7->setStyleSheet("background-color: rgb(255, 250, 0);"); //yellow
    } else if(stn7_TA==0x00C0) {
        ui->lE_cI7->setStyleSheet("background-color: rgb(0, 170, 127);"); //green
    }

    int stn8_TA = ((mslp_res_data2[0]) ) & 0x01C0;
    if(stn8_TA==0x0000) {
        ui->lE_cI8->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
    } else if(stn8_TA==0x0040) {
        ui->lE_cI8->setStyleSheet("background-color: rgb(255, 250, 0);"); //yellow
    } else if(stn8_TA==0x00C0){
        ui->lE_cI8->setStyleSheet("background-color: rgb(0, 170, 127);"); //green
    }

    int stn9_TA  = ((mslp_res_data3[0]) ) & 0x01C0;
    if(stn9_TA==0x0000){
        ui->lE_cI9->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
    }else if(stn9_TA==0x0040){
        ui->lE_cI9->setStyleSheet("background-color: rgb(255, 250, 0);"); //yellow
    } else if(stn9_TA == 0x00C0){
        ui->lE_cI9->setStyleSheet("background-color: rgb(0, 170, 127);"); //green
    }

    int stn10_TA = ((mslp_res_data4[0]) ) & 0x01C0;
    if(stn10_TA == 0x0000){
        ui->lE_cI10->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
    }else if(stn10_TA==0x0040){
        ui->lE_cI10->setStyleSheet("background-color: rgb(255, 250, 0);"); //yellow
    }else if(stn10_TA==0x00C0) {
        ui->lE_cI10->setStyleSheet("background-color: rgb(0, 170, 127);"); //green
    }


    int stn7_dl= mslp_res_data1[1] & 0x0c00;
    if(stn7_dl == 0x0800) ///****DATALINK STATUS*****/
    {
        ui->lE_cO7->setStyleSheet("background-color: rgb(0, 170, 127);");//GREEN
    }else if(stn7_dl == 0x0400)
    {
        ui->lE_cO7->setStyleSheet("background-color: rgb(255, 250, 0);");//yellow
    }
    else if(stn7_dl == 0x0000)
    {
        ui->lE_cO7->setStyleSheet("background-color: rgb(255, 0, 0);");//RED
    }


    int stn8_dl= mslp_res_data2[1] & 0x0c00;
    if(stn8_dl == 0x0800) ///****DATALINK STATUS*****/
    {
        ui->lE_cO8->setStyleSheet("background-color: rgb(0, 170, 127);");//GREEN
    }else if(stn8_dl == 0x0400)
    {
        ui->lE_cO8->setStyleSheet("background-color: rgb(255, 250, 0);");//yellow
    }
    else if(stn8_dl == 0x0000)
    {
        ui->lE_cO8->setStyleSheet("background-color: rgb(255, 0, 0);");//RED
    }

    int stn9_dl= mslp_res_data3[1] & 0x0c00;
    if(stn9_dl == 0x0800) ///****DATALINK STATUS*****/
    {
        ui->lE_cO9->setStyleSheet("background-color: rgb(0, 170, 127);");//GREEN
    }else if(stn9_dl == 0x0400)
    {
        ui->lE_cO9->setStyleSheet("background-color: rgb(255, 250, 0);");//yellow
    }
    else if(stn9_dl == 0x0000)
    {
        ui->lE_cO9->setStyleSheet("background-color: rgb(255, 0, 0);");//RED
    }

    int stn10_dl= mslp_res_data4[1] & 0x0c00;
    if(stn10_dl == 0x0800) ///****DATALINK STATUS*****/
    {
        ui->lE_cO10->setStyleSheet("background-color: rgb(0, 170, 127);");//GREEN
    }else if(stn10_dl == 0x0400)
    {
        ui->lE_cO10->setStyleSheet("background-color: rgb(255, 250, 0);");//yellow
    }
    else if(stn10_dl == 0x0000)
    {
        ui->lE_cO10->setStyleSheet("background-color: rgb(255, 0, 0);");//RED
    }
    int missile_avil_7 = mslp_res_data1[0] & 0x0020;
    if(missile_avil_7 == 0x0020){
        ui->lB_aSTRA7->setHidden(false);
        ui->lb_launch_stn7->setHidden(false);
        ui->lE_cI7->setHidden(false);
        ui->lE_cO7->setHidden(false);

    }
    else
    {
        ui->lB_aSTRA7->setHidden(true);
        //ui->lb_launch_stn7->setHidden(true);
        ui->lE_cI7->setHidden(true);
        ui->lE_cO7->setHidden(true);

    }


    int missile_avil_8 = mslp_res_data2[0] & 0x0020;
    if(missile_avil_8 == 0x0020){
        ui->lB_aSTRA8->setHidden(false);
        ui->lb_launch_stn8->setHidden(false);
        ui->lE_cI8->setHidden(false);
        ui->lE_cO8->setHidden(false);
    }
    else{
        ui->lB_aSTRA8->setHidden(true);
        //ui->lb_launch_stn8->setHidden(true);
        ui->lE_cI8->setHidden(true);
        ui->lE_cO8->setHidden(true);

    }

    int missile_avil_9 = mslp_res_data3[0] & 0x0020;
    if(missile_avil_9 == 0x0020){
        ui->lB_aSTRA9->setHidden(false);
        ui->lb_launch_stn9->setHidden(false);
        ui->lE_cI9->setHidden(false);
        ui->lE_cO9->setHidden(false);


    }
    else{
        ui->lB_aSTRA9->setHidden(true);
        //ui->lb_launch_stn9->setHidden(true);
        ui->lE_cI9->setHidden(true);
        ui->lE_cO9->setHidden(true);


    }

    int missile_avil_10 = mslp_res_data4[0] & 0x0020;
    if(missile_avil_10 == 0x0020){
        ui->lB_aSTRA10->setHidden(false);
        ui->lb_launch_stn10->setHidden(false);
        ui->lE_cI10->setHidden(false);
        ui->lE_cO10->setHidden(false);


    }
    else{
        ui->lB_aSTRA10->setHidden(true);
        //ui->lb_launch_stn10->setHidden(true);
        ui->lE_cI10->setHidden(true);
        ui->lE_cO10->setHidden(true);

    }

//
    updategui();
    filewriting();


    ////////////////////////////////END SBTS ///////////////////////////////////

}
void MainWindow::on_start_sim_Pbt_clicked()  // qsimulator start
{



    QString L=ui->La_No->text();
           //string Lno=L.toStdString();
          QByteArray Lno=L.toLatin1();
          const char *c_str=Lno.data();
          if(ui->La_No->text().isEmpty())
          {
              QMessageBox::warning(this,"Title","Please Enter Launcher Number");

          }
          QString M=ui->Msl_No->text();
           //string Lno=L.toStdString();
          QByteArray Mno=M.toLatin1();
          const char *c_str_m=Mno.data();
          if(ui->Msl_No->text().isEmpty())
          {
              QMessageBox::warning(this,"Title","Please Enter Missile Number");

          }
          QString O=ui->le_obj->text();
           //string Lno=L.toStdString();
          QByteArray Obj=O.toLatin1();
          const char *c_str_o=Obj.data();
          if(ui->le_obj->text().isEmpty())
          {
              QMessageBox::warning(this,"Title","Please Enter Objective");

          }
          time_t timeval;
          (void) time (&timeval);


          QDir dir("");

          if(dir.exists())
              qDebug()<<"Dir Exist";
          else
              dir.mkpath("D:/Autolaunch");

          QDir dir1("");
          wchar_t hpn = L'\u002D';
           //QString hpn_1=hpn.toString("-");
        //  qDebug()<<"hpn: "<<hpn;
          if(dir1.exists())
              qDebug()<<"Dir1 Exist";
          else
              dir1.mkpath("D://Autolaunch//"+L+hpn+M);


       QString d=(QDate::currentDate().toString("dd-MM-yyyy "));

       QDir dir3("D:/Autolaunch/"+L+hpn+M+"/"+d);

       if(dir3.exists())
           qDebug()<<"Dir3 Exist";
       else
           dir3.mkpath("D:/Autolaunch/"+L+hpn+M+"/"+d);

      QString path="D:/Autolaunch/"+L+hpn+M+"/"+d+"/AutoLaunch_file.txt";

      string filepath=path.toStdString();

      qDebug()<<"path "<<filepath.c_str();

      Autolaunch_file=fopen(filepath.c_str(),"a");


     fprintf(Autolaunch_file,"\n\t******************* Mission Run ********************************************** \n");
     fprintf(Autolaunch_file,"\n\t Conducted on : %s",ctime(&timeval));
     fprintf(Autolaunch_file,"\n\t Launcher No: %s",c_str );
     fprintf(Autolaunch_file,"\t\t\t Missile No: %s",c_str_m);
     fprintf(Autolaunch_file,"\n\n\t Objective: %s",c_str_o);
     fprintf(Autolaunch_file,"\n\n\t ***************************************************************** \n");
   //  DLZ_file=fopen("DLZ.txt","a");
//     fprintf(DLZ_file,"\n\t***************************************************************** \n");
//     fprintf(DLZ_file,"\n\t Conducted on : %s",ctime(&timeval));
//     fprintf(DLZ_file,"\n\t Launcher No: %s",c_str );
//     fprintf(DLZ_file,"\t\t\t Missile No: %s",c_str_m);
//     fprintf(DLZ_file,"\n\n\t Objective: %s",c_str_o);
//     fprintf(DLZ_file,"\n\n\t ***************************************************************** \n");
//     fprintf(DLZ_file,"\n\t\tDmax1\t Dmax2\t Dmin\t IRT\t tlt \t tat \t tla \t tln\n");
//     fprintf(DLZ_file ,"\t ---------------------------------------------------------\n\n");





    if((ui->rc_chk_Box->isChecked())&& (ui->mc_chck_Box->isChecked()))
    {
        // qDebug()<<"rc--mc ";
        startRc();
        startMc();
        ui->mc_chck_Box->setStyleSheet("background-color: rgb(0, 170, 127);"); //green
        ui->rc_chk_Box->setStyleSheet("background-color: rgb(0, 170, 127);"); //green

    }
    else if(ui->rc_chk_Box->isChecked())
    {
        //   qDebug()<<"rc";
        startRc();

        ui->rc_chk_Box->setStyleSheet("background-color: rgb(0, 170, 127);"); //green

    }else if(ui->mc_chck_Box->isChecked())
    {
        qDebug()<<"mc ";
        startMc();
        ui->mc_chck_Box->setStyleSheet("background-color: rgb(0, 170, 127);"); //green

    }
    else
    {
        errorPopup->information(this,"Information","SelectSimulator");
    }

}

void MainWindow::startRc()  //Initializes Card and Creates Message
{

    rcFilePath = ui->rc_file_Ldt->text();
    qDebug()<<rcFilePath;

    if(rcFilePath == "")
    {
        errorPopup->information(this,"Information","SelectFile");
    }
    else
    {

        //first line of file need to be skipped
        file_RC = fopen(rcFilePath.toUtf8(), "r");
        qDebug()<<"rcfile path ::"<<rcFilePath;
        fgets(szDummy,512, file_RC);
        if ((ui->devnum->currentText()) == "0")
        {
            DevNum=0x0000;
        }
        if ((ui->devnum->currentText()) == "1")
        {
            DevNum=0x0001;
        }
        if ((ui->devnum->currentText()) == "2")
        {
            DevNum=0x0002;
        }
        if ((ui->devnum->currentText()) == "3")
        {
            DevNum=0x0003;
        }
        rc_initialize();   // card initialization and message creation

        /* mThread->start();*/
        aceBCStart(DevNum,MJR,-1);

        timer->start(18);

        //qDebug()<<"mthread  running status::"<<mThread->isRunning();
        //qDebug()<<"mthread status:"<<mThread->isRunning();
        icount=0;
        this->timer_t->start(20);
        // qDebug()<<"timer status:"<<timer_t->isActive();
    }
}

void MainWindow::Ondisplay()
{

    qDebug()<<"inside ondisplay";
    aceBCStart(DevNum,MJR,-1);
    icount=0;

    //this->timer->start(18);

}

void MainWindow::acestop()
{
    aceFree(DevNum);
    aceBCStop(DevNum);

}

void MainWindow::stopRc()
{

    mThread->quit();
    //   wBuffer[32]= 0 ;
//    fclose(pFile);
//    fclose(rFile);
//    fclose(sFile);
//    fclose(tFile);
//    fclose(uFile);
  //  fclose(fp); ////22082023
    acestop();
    this->timer->stop();
    this->timer_t->stop();
    fclose(Autolaunch_file);
  //  fclose(HMDSFile);
  //  fclose(DLZ_file);
}
void MainWindow::on_stop_sim_Pbt_clicked()
{

    if(ui->rc_chk_Box->isChecked()&& ui->mc_chck_Box->isChecked())
    {
        //  qDebug()<<"rc--mc stop";
        stopMc();
        stopRc();
        ui->mc_chck_Box->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
        ui->rc_chk_Box->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
    }
    else if(ui->rc_chk_Box->isChecked())
    {
        //   qDebug()<<"rc stop";
        stopRc();
        ui->rc_chk_Box->setStyleSheet("background-color: rgb(255, 0, 0);"); //red

    }else if(ui->mc_chck_Box->isChecked())
    {
        //   qDebug()<<"mc stop ";
        stopMc();
        ui->mc_chck_Box->setStyleSheet("background-color: rgb(255, 0, 0);"); //red
    }
    else
    {
        errorPopup->information(this,"Information","SelectSimulator..");
    }
}

void MainWindow::message()//RT-BC  data reception and extraction
{

    i++;
    icount++;
    ui_Count++; // ui counter variable

    // qDebug()<<"inside messgae count";

    //printf("MSLP Data reading.......\n");
    //   while(1)


    //-----------pFile-MSLP data


    {

        // newly added on 25th May 2016 for receiving MSLP from all four stations in four arrays
        //      aceBCDataBlkRead(DevNum,MSG6,*pBuffer, U16BIT wBufferSize,U16BIT wOffset);
        // aceBCFrmToHBuf(DevNum);





        for(k=0;k<32;k++)
        {
            mslp_res_data1[k]=0x0000;
            //fprintf(Tgt7File,"%04", mslp_res_data1[k]);
            // qDebug()<<"mslp1 array::"<<mslp_res_data1[k];
        }
        wResult = aceBCDataBlkRead(DevNum,MSG6,mslp_res_data1,32,0);
//        for(int i =10000; i=0; i--)
//        {
//        };
        // wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG6,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
                unsigned short int time_data[2];
            };
            union time mlp_time;
         //   fprintf(pFile,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];


            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;

        //    fprintf(rFile,"%f   ",mlp_time1);

//            for(j=0;j<32;j++)
//            {

//           //     fprintf(pFile, "%04x ",mslp_res_data1[j]);
//                fprintf(rFile, "%04x ",mslp_res_data1[j]);
//            }

        //    fprintf(rFile,"\n");
           }

        //  aceBCFrmToHBuf(DevNum);

        for(k=0;k<32;k++)
        {
            mslp_res_data2[k]=0x0000;
           // fprintf(Tgt8File,"%04", mslp_res_data2[k]);

            // qDebug()<<"mslp2 array::"<<mslp_res_data2[k];
        }
        wResult = aceBCDataBlkRead(DevNum,MSG7,mslp_res_data2,32,0);

        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG7,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
                unsigned short int time_data[2];
            };
            union time mlp_time;
          //  fprintf(pFile,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];


            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
//            fprintf(sFile,"%f   ",mlp_time1);

//            for(j=0;j<32;j++)
//            {
//            //    fprintf(pFile, "%04x ",mslp_res_data2[j]);
//                fprintf(sFile, "%04x ",mslp_res_data2[j]);
//            }

         //  fprintf(sFile,"\n");

            }



        // aceBCFrmToHBuf(DevNum);
        for(k=0;k<32;k++)
        {
            mslp_res_data3[k]=0x0000;
            //fprintf(Tgt9File,"%04", mslp_res_data3[k]);

            //      qDebug()<<"mslp3 array::"<<mslp_res_data3[k];
        }
        wResult = aceBCDataBlkRead(DevNum,MSG8,mslp_res_data3,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        // wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG8,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
                unsigned short int time_data[2];
            };
            union time mlp_time;
        //    fprintf(pFile,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];


            float mlp_time1 = float (mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
            qDebug()<<mlp_time.time_total;
          //  fprintf(tFile,"%f   ",mlp_time1);


//            for(j=0;j<32;j++)
//            {
//              //  fprintf(pFile, "%04x ",mslp_res_data3[j]);
//                fprintf(tFile, "%04x ",mslp_res_data3[j]);
//            }

       //    fprintf(tFile,"\n");
            }


        // aceBCFrmToHBuf(DevNum);
        for(k=0;k<32;k++)
        {
            mslp_res_data4[k]=0x0000;
            //fprintf(Tgt10File,"%04", mslp_res_data[k]);

            //   qDebug()<<"mslp4 array::"<<mslp_res_data4[k];
        }
        wResult = aceBCDataBlkRead(DevNum,MSG9,mslp_res_data4,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {

            union time
            {
                int time_total;
               unsigned short int time_data[2];
            };

           union time mlp_time;

         //  fprintf(pFile,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];

            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
            qDebug()<<mlp_time.time_total;
            //qDebug()<<(mslp_res_data4[19]*65536);
//            fprintf(uFile,"%f   ",mlp_time1);

//            for(j=0;j<32;j++)
//            {
//             //   fprintf(pFile, "%04x ",mslp_res_data4[j]);
//                fprintf(uFile, "%04x ",mslp_res_data4[j]);
//            }
//                fprintf(uFile,"\n");
            }

   //----------------Surveillance------------------------------------------------------


        //for(k=0;k<33;k++)
       // {
           // sur_data_1[k]=0x0000;

       // }




        wResult = aceBCDataBlkRead(DevNum,MSG23,sur_data_1,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
               unsigned short int time_data[2];
            };

           union time mlp_time;

           //fprintf(Surv7File,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];

            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
            qDebug()<<mlp_time.time_total;
            //qDebug()<<(mslp_res_data4[19]*65536);
//            fprintf(Surv7File,"%f   ",mlp_time1);


//        for(j=0;j<32;j++)
//        {
//            fprintf(Surv7File, "%04x ",sur_data_1[j]);
//            //fprintf(uFile, "%04x ",mslp_res_data4[j]);
//        }
//            fprintf(Surv7File,"\n");
        }



        //for(k=0;k<33;k++)
        //{
           // sur_data_2[k]=0x0000;

        //}
        wResult = aceBCDataBlkRead(DevNum,MSG24,sur_data_2,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
               unsigned short int time_data[2];
            };

           union time mlp_time;

           //fprintf(Surv7File,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];

            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
            qDebug()<<mlp_time.time_total;
            //qDebug()<<(mslp_res_data4[19]*65536);
//            fprintf(Surv8File,"%f   ",mlp_time1);


//        for(j=0;j<32;j++)
//        {

//            //fprintf(Surv8File, "%04x ",sur_data_1[j]);
//            fprintf(Surv8File, "%04x ",sur_data_2[j]);
//        }
//            fprintf(Surv8File,"\n");
        }




        //for(k=0;k<33;k++)
        //{
          //  sur_data_3[k]=0x0000;

       // }
        wResult = aceBCDataBlkRead(DevNum,MSG25,sur_data_3,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
               unsigned short int time_data[2];
            };

           union time mlp_time;

           //fprintf(Surv7File,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];

            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
            qDebug()<<mlp_time.time_total;
            //qDebug()<<(mslp_res_data4[19]*65536);
//            fprintf(Surv9File,"%f   ",mlp_time1);


//        for(j=0;j<32;j++)
//        {

//            //fprintf(Surv9File, "%04x ",sur_data_1[j]);
//            fprintf(Surv9File, "%04x ",sur_data_3[j]);
//        }
//            fprintf(Surv9File,"\n");
        }



        //for(k=0;k<33;k++)
        //{
          //  sur_data_4[k]=0x0000;

        //}
        wResult = aceBCDataBlkRead(DevNum,MSG26,sur_data_4,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time
            {
                int time_total;
               unsigned short int time_data[2];
            };

           union time mlp_time;

           //fprintf(Surv7File,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];

            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
            qDebug()<<mlp_time.time_total;
            //qDebug()<<(mslp_res_data4[19]*65536);
//            fprintf(Surv10File,"%f   ",mlp_time1);


//        for(j=0;j<32;j++)
//        {

//            //fprintf(Surv10File, "%04x ",sur_data_1[j]);
//            fprintf(Surv10File, "%04x ",sur_data_4[j]);
//        }
//            fprintf(Surv10File,"\n");
        }



//---------------------------DL tgt data--------------------------------------------------------------------





        for(k=0;k<32;k++)
        {
            stn7_tagt_data[k]=0x0000;

        }
        wResult = aceBCDataBlkRead(DevNum,MSG10,stn7_tagt_data,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {

        union time1
        {
            int time_total1;
            unsigned short int time_data1[2];
        };
        union time1 mlp_time1;
        mlp_time1.time_data1[0]=stn_tagt_data[1];
        mlp_time1.time_data1[1]=stn_tagt_data[0];

        float mlp_time2=float(mlp_time1.time_total1);
        mlp_time2=mlp_time2/1000;
//        fprintf(Tgt7File,"%f",mlp_time2);

//        for(j=0;j<32;j++)
//        {
//            fprintf(Tgt7File, "%04x ",stn7_tagt_data[j]);
//        }
//            fprintf(Tgt7File,"\n");

        }



        for(k=0;k<32;k++)
        {
            stn8_tagt_data[k]=0x0000;

        }
        wResult = aceBCDataBlkRead(DevNum,MSG11,stn8_tagt_data,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            union time1
            {
                int time_total1;
                unsigned short int time_data1[2];
            };
            union time1 mlp_time1;
            mlp_time1.time_data1[0]=stn_tagt_data[1];
            mlp_time1.time_data1[1]=stn_tagt_data[0];

            float mlp_time2=float(mlp_time1.time_total1);
            mlp_time2=mlp_time2/1000;
//            fprintf(Tgt8File,"%f",mlp_time2);
//        for(j=0;j<32;j++)
//        {
//            fprintf(Tgt8File, "%04x ",stn8_tagt_data[j]);
//        }
//            fprintf(Tgt8File,"\n");

        }


        for(k=0;k<32;k++)
        {
            stn9_tagt_data[k]=0x0000;

        }
        wResult = aceBCDataBlkRead(DevNum,MSG12,stn9_tagt_data,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {

            union time1
            {
                int time_total1;
                unsigned short int time_data1[2];
            };
            union time1 mlp_time1;
            mlp_time1.time_data1[0]=stn_tagt_data[1];
            mlp_time1.time_data1[1]=stn_tagt_data[0];

            float mlp_time2=float(mlp_time1.time_total1);
            mlp_time2=mlp_time2/1000;
//            fprintf(Tgt9File,"%f",mlp_time2);

//        for(j=0;j<32;j++)

//        {
//            fprintf(Tgt9File, "%04x ",stn9_tagt_data[j]);
//        }
//            fprintf(Tgt9File,"\n");

        }



        for(k=0;k<32;k++)
        {
            stn10_tagt_data[k]=0x0000;

        }
        wResult = aceBCDataBlkRead(DevNum,MSG13,stn10_tagt_data,32,0);
        //        for (i =10000; i =0; i--)
        //        {
        //        };
        //  wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG9,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {

            union time1
            {
                int time_total1;
                unsigned short int time_data1[2];
            };
            union time1 mlp_time1;
            mlp_time1.time_data1[0]=stn_tagt_data[1];
            mlp_time1.time_data1[1]=stn_tagt_data[0];

            float mlp_time2=float(mlp_time1.time_total1);
            mlp_time2=mlp_time2/1000;
//            fprintf(Tgt10File,"%f",mlp_time2);
//            for(j=0;j<32;j++)
//        {
//            fprintf(Tgt10File, "%04x ",stn10_tagt_data[j]);
//        }
//            fprintf(Tgt10File,"\n");

        }
    }

//----------------------------------Station selection------------------------------------------------------------------------------------
    //NKS

        if(mslp_res_data1[16] != 0x0000)       
        gb_umbilical_sts7 = ((mslp_res_data1[16] & 0x0200) ==  0x0200 ) ? 0 : 1 ;

        if(ui->station_select1->currentText()=="Station 7")
        {
            for(j=0;j<32;j++)
             mslp_res_data[j]=mslp_res_data1[j];

         }

        //NKS
        if(mslp_res_data2[16] != 0x0000)
            gb_umbilical_sts8 = ((mslp_res_data2[16] & 0x0200) ==  0x0200 ) ? 0 : 1 ;

        if(ui->station_select1->currentText()=="Station 8")
        {

            for(j=0;j<32;j++)
            mslp_res_data[j]=mslp_res_data2[j];


        }


        if(mslp_res_data3[16] != 0x0000)
            gb_umbilical_sts9 = ((mslp_res_data3[16] & 0x0200) ==  0x0200 ) ? 0 : 1 ;

        if(ui->station_select1->currentText()=="Station 9")
        {

            for(j=0;j<32;j++)

            mslp_res_data[j]=mslp_res_data3[j];

         }


        if(mslp_res_data4[16] != 0x0000)
            gb_umbilical_sts10 = ((mslp_res_data4[16] & 0x0200) ==  0x0200 ) ? 0 : 1 ;

        if(ui->station_select1->currentText()=="Station 10")
        {

            for(j=0;j<32;j++)

            mslp_res_data[j]=mslp_res_data4[j];

         }


//----------------------------------Frequency response---------------------------------------------------------------
        // for freq resp message T /////

        // aceBCFrmToHBuf(DevNum);
        wResult = aceBCDataBlkRead(DevNum,MSG19,freq_res_stn7,3,0);
        //        for (i =1000; i =0; i--)
        //        {
        //        };
        // wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG19,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            for(j=0;j<2;j++)
            {
                //  freq_res_stn7[j]=sMsg.aDataWrds[j];
                // frequency data change
                // printf("freq_data[%d] is %04x\n",j, freq_res_stn7[j]);
           //     fprintf(fp, "%04x ",freq_res_stn7[j]); //22082023
            }
           // fprintf(fp,"\n");//22082023
        }

        // aceBCFrmToHBuf(DevNum);
        wResult = aceBCDataBlkRead(DevNum,MSG20,freq_res_stn8,3,0);
        //        for (i =1000; i =0; i--)
        //        {
        //        };
        // wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG20,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            for(j=0;j<2;j++)
            {
                //        freq_res_stn8[j]=sMsg.aDataWrds[j];

                // frequency data change
                // printf("freq_data[%d] is %04x\n",j, freq_res_stn8[j]);
           //     fprintf(fp, "%04x ",freq_res_stn8[j]); //22082023
            }
          //  fprintf(fp,"\n");//22082023
        }
        // aceBCFrmToHBuf(DevNum);
        wResult = aceBCDataBlkRead(DevNum,MSG21,freq_res_stn9,3,0);
        //        for (i =1000; i =0; i--)
        //        {
        //        };
        // wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG21,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            for(j=0;j<2;j++)
            {
                //      freq_res_stn9[j]=sMsg.aDataWrds[j];
                // frequency data change
                // printf("freq_data[%d] is %04x\n",j, freq_res_stn9[j]);
              //  fprintf(fp, "%04x ",freq_res_stn9[j]); //22082023
            }
          //  fprintf(fp,"\n");//22082023
        }

        //  aceBCFrmToHBuf(DevNum);
        wResult = aceBCDataBlkRead(DevNum,MSG22,freq_res_stn10,3,0);
        //        for (i =1000; i =0; i--)
        //        {
        //        };
        // wResult =  aceBCGetMsgFromIDDecoded(DevNum,MSG22,&sMsg,TRUE);
        if(wResult < 0)
        {
            PrintOutError(wResult);
        }
        else
        {
            for(j=0;j<2;j++)
            {
                //
                freq_res_stn10[j]=sMsg.aDataWrds[j];
                // frequency data change
                // printf("freq_data[%d] is %04x\n",j, freq_res_stn10[j]);
              //  fprintf(fp, "%04x ",freq_res_stn10[j]);//22082023
            }
          //  fprintf(fp,"\n");//22082023
        }
        /****GUI UPDATE FUNCTION ******/
        ui_Count++;


        if(ui_Count==100) // 2sec update of GUI (emitting the signal for thread)
        {
            // qDebug()<<"gui update signal sent";
            // thread signal emit..
            //            sendupdate();
            ui_Count = 0;

        }
    }



void _DECL funcExternalISR(S16BIT DevNum, U32BIT Status)
{

    msgcnt++;
    //  printf("msgcnt is %d\n",msgcnt);
    //  prevmsgcnt=msgcnt;
    wResult = aceBCDataBlkWrite(DevNum, DBLK1, dstd1, 32, 0);
    if(wResult)
    {
        printf("BC DataDlk1Write Failed\n");
    }
    wResult = aceBCDataBlkWrite(DevNum, DBLK2, dstd2, 32, 0);
    if(wResult)
    {
        printf("BC DataDlk2Write Failed\n");
    }
    wResult = aceBCDataBlkWrite(DevNum, DBLK3, dstd3, 32, 0);
    if(wResult)
    {
        printf("BC DataDlk3Write Failed\n");
    }
    wResult = aceBCDataBlkWrite(DevNum, DBLK4, dstd4, 32, 0);
    if(wResult)
    {
        printf("BC DataDlk4Write Failed\n");
    }
    wResult = aceBCDataBlkWrite(DevNum, DBLK5, lotd, 32, 0);
    if(wResult)
    {
        printf("BC DataDlk5Write Failed\n");
    }
#if 0   //22082023
    for(j=0;j<32;j++)
       {
           fprintf(testFile, "%04x ",hmds1[j]);
       }
        fprintf(testFile,"\n");
#endif
    //   qDebug()<<"\n\n before sending \nhmds 3 and 4 ::"<< hmds1[3] << hmds1[4] ;
    //    qDebug()<<"hmds 7 and  8 ::"<< hmds1[7]  <<   hmds1[8] ;
    //    qDebug()<<"hmds 11 12"<< hmds1[11]   <<   hmds1[12] ;
    //    qDebug()<<"hmds 13 18 "<< hmds1[17]   <<   hmds1[18] ;

    wResult = aceBCDataBlkWrite(DevNum, DBLK14, hmds1, 32, 0);
    if(wResult)
    {
        printf("BC DataDlk14Write Failed\n");
    }

    wResult = aceBCDataBlkWrite(DevNum, DBLK15, freq_cmd_stn7, 5, 0);
    if(wResult)
    {
        printf("BC DataDlk15Write Failed\n");
    }
    //////T///
    wResult = aceBCDataBlkWrite(DevNum, DBLK16, freq_cmd_stn8, 5, 0);
    if(wResult)
    {
        printf("BC DataDlk16Write Failed\n");
    }
    wResult = aceBCDataBlkWrite(DevNum, DBLK17, freq_cmd_stn9, 5, 0);
    if(wResult)
    {
        printf("BC DataDlk17Write Failed\n");
    }
    wResult = aceBCDataBlkWrite(DevNum, DBLK18, freq_cmd_stn10, 5, 0);
    if(wResult)
    {
        printf("BC DataDlk18rite Failed\n");
    }
    //    printf("hello");

}

//static void PrintOutError(S16BIT nResult)
//{
//    aceErrorStr(nResult,buf,80);
//    printf("RTL Function Failure-> %s.\n",buf);
//    MessageBoxW(NULL,L"RTL Function Failure",L"",0);
//}

void MainWindow::Onmesgcount()// updation of data block sent
{
    U16BIT str,str1,str2;


    recievecount++;
    icount++;
    //float fkamTime;
    //    printf("RC File read thread started\n");
    //  printf("prev is %d\n",prevmsgcnt);
    // prevmsgcnt++;
    //   static int i=0;
    QPalette palettered,palettegreen,paletteyellow;
    palettered.setColor(QPalette::Text,Qt::red);
    palettegreen.setColor(QPalette::Text,Qt::green);
    paletteyellow.setColor(QPalette::Text,Qt::yellow);

    if(ui->cb_radar->isChecked())
    {
        if(msgcnt > prevmsgcnt)
        {
            prevmsgcnt=msgcnt;
            //printf("prev is %d\n",prevmsgcnt);
            ///Change by unical on 070119/////
            if(stn1 == true)
            {
                sg1->generationscenario();
                //               memcpy( dstd1,sg1->Word_RC,32);


                for(int i=0;i<32;i++)
                {


                    dstd1[i]=sg1->Word_RC[i];
                }


                    //                    fprintf(file_rcw1,"%5d\t",sg1->Word_RC[i]);


                dstd1[0]=1;

                //                fprintf(file_rcw1,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw1,"%5d\t",sg1->Word_MC[i]);
                //                }
                //                fprintf(file_mcw1,"\n");
            }else
                memset(dstd1,0,32);


            if(stn2 == true)
            {
                sg2->generationscenario();



                for(int i=0;i<32;i++)
                {
                    dstd2[i]=sg2->Word_RC[i];
                }


                    //                    fprintf(file_rcw2,"%5d\t",sg2->Word_RC[i]);

                dstd2[0]=2;
                //                fprintf(file_rcw2,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw2,"%5d\t",sg2->Word_MC[i]);
                //                }
                //                fprintf(file_mcw2,"\n");
            }else
                memset(dstd2,0,32);


            if(stn3 == true)
            {
                sg3->generationscenario();


                for(int i=0;i<32;i++)
                {
                    dstd3[i]=sg3->Word_RC[i];
                }


           //                    fprintf(file_rcw3,"%5d\t",sg3->Word_RC[i]);

                dstd3[0]=3;
                //                fprintf(file_rcw3,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw3,"%5d\t",sg3->Word_MC[i]);
                //                }
                //                fprintf(file_mcw3,"\n");
            }else
                memset(dstd3,0,32);


            if(stn4 == true){
                sg4->generationscenario();



                for(int i=0;i<32;i++)
                {
                    dstd4[i]=sg4->Word_RC[i];

                    //                    fprintf(file_rcw4,"%5d\t",sg4->Word_RC[i]);
                }


                dstd4[0]=4;
                //                fprintf(file_rcw4,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw4,"%5d\t",sg4->Word_MC[i]);
                //                }
                //                fprintf(file_mcw4,"\n");
            }else
                memset(dstd4,0,32);
            ///Change by unical on 070119/////


            if(ui->cB_lOTD->currentText() == "Target-1"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg1->Word_LOTD[i];
                lotd[0]=1;
               lotdflag=1;
            }
            else if(ui->cB_lOTD->currentText() == "Target-2"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg2->Word_LOTD[i];
                lotd[0]=2;
                lotdflag=2;
            }
            else if(ui->cB_lOTD->currentText() == "Target-3"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg3->Word_LOTD[i];
                lotd[0]=3;
                lotdflag=3;
            }
            else if(ui->cB_lOTD->currentText() == "Target-4"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg4->Word_LOTD[i];
                lotd[0]=4;
               lotdflag=4;
            }
            else
                memset(lotd,0,32);
            lotd[19]=recievecount;
#if 0
            if(!feof(file_RC))
            {
                fscanf(file_RC, "%f", &fkamTime);
                for (j=0; j<32; j++)
                    fscanf(file_RC, "%d", &data1[j]);
                fscanf(file_RC,"\n" );
                for(j=0;j<32;j++)
                {
                    dstd1[j]=data1[j];
                    dstd2[j]=data1[j];
                    dstd3[j]=data1[j];
                    dstd4[j]=data1[j];
                    lotd[j]=data1[j];
                }
                for(j=0;j<32;j++)
                {
                    //printf("\tRCfileData:%d",lotd[j]);
                }
                printf("\n");

                //                for(j=1;j<33;j++)
                //                    dstd1[j-1]=data1[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd1[j]);
                //                }
                //                printf("\n");

                //                for(j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data2[j]);
                //                for(j=1;j<33;j++)
                //                    dstd2[j-1]=data2[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd2[j]);
                //                }
                //                printf("\n");

                //                for (j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data3[j]);
                //                for(j=1;j<33;j++)
                //                    dstd3[j-1]=data3[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd3[j]);
                //                }
                //                printf("\n");

                //                for (j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data4[j]);
                //                for(j=1;j<33;j++)
                //                    dstd4[j-1]=data4[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd4[j]);
                //                }
                //                printf("\n");

                //                for (j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data5[j]);
                //                for(j=1;j<33;j++)
                //                    lotd[j-1]=data5[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",lotd[j]);
                //                }
                //                printf("\n");
            }
            if(feof(file_RC))
            {
                //                qDebug()<<"in rewind slot\n";
                //                printf("end of rc file\n");
                //                rewind(file_RC);
                fclose(file_RC);
                // usleep(10000);
                file_RC = fopen(rcFilePath.toUtf8(), "r");
                qDebug()<<"rcfile path ::"<<rcFilePath;
                fgets(szDummy,512, file_RC);
            }
#endif
            dstd1[27]= 0x0000;
            dstd1[28]= 0x0000;
            dstd2[27]= 0x0000;
            dstd2[28]= 0x0000;
            dstd3[27]= 0x0000;
            dstd3[28]= 0x0000;
            dstd4[27]= 0x0000;
            dstd4[28]= 0x0000;
            lotd[27]=0x0000;
            lotd[28]=0x0000;
            // test case for invalid target
            //lotd[0]=0x0000;

//--------------------------------------------- HMDS data block update-------------------------------------------------------------------------

            //  qDebug()<<"mslp_res_data1 ::"<<mslp_res_data1[0] << mslp_res_data1[1] <<"mslp_res_data2 ::"<<mslp_res_data2[0] << mslp_res_data2[1] ;
            // qDebug()<<"mslp_res_data3 ::"<<mslp_res_data3[0] << mslp_res_data3[1] <<"mslp_res_data4 ::"<<mslp_res_data4[0] << mslp_res_data4[1] ;

            union time
            {
                int time_total;
                unsigned short int time_data[2];
            };
            union time mlp_time;
            //fprintf(pFile,"\n");

            mlp_time.time_data[0] = mslp_res_data[20];
            mlp_time.time_data[1] = mslp_res_data[19];


            float mlp_time1 = float(mlp_time.time_total);
            mlp_time1=mlp_time1/1000;
       #if 0
            fprintf(HMDSFile,"%f   ",mlp_time1);
                        for(j=0;j<32;j++)
                        {
                           fprintf(HMDSFile, "%04x ", hmds1[j]);
                            hmds1[j] = 0x0000;
                         //  qDebug()<<"hmds array::"<<hmds1[j];
             }
                        fprintf(HMDSFile,"\n");
       #endif
            //            qDebug()<<"mslp_res_data1[0] ::"<<mslp_res_data1[0];
            //            qDebug()<<"mslp_res_data1[1] ::"<<mslp_res_data1[1];
            //            qDebug()<<"hmds[3] :"<<hmds1[3];
            //            qDebug()<<"hmds[4] :"<<hmds1[4];
            //            qDebug()<<"mslp_res_data1[1] ::"<<mslp_res_data1[1];

            hmds1[3]=mslp_res_data1[0];
            hmds1[4]=mslp_res_data1[1];

            hmds1[7]=mslp_res_data2[0];
            hmds1[8]=mslp_res_data2[1];
            //            qDebug()<<"mslp_res_data3[0] ::"<<mslp_res_data3[0];
            //            qDebug()<<"mslp_res_data3[1] ::"<<mslp_res_data3[1];
            //            qDebug()<<"hmds[11] :"<<hmds1[11];
            //            qDebug()<<"hmds[12] :"<<hmds1[12];

            hmds1[11]=mslp_res_data3[0];
            hmds1[12]=mslp_res_data3[1];

            hmds1[15]=mslp_res_data4[0];
            hmds1[16]=mslp_res_data4[1];

            //            qDebug()<<"\n\n hmds 3 and 4 ::"<< hmds1[3] << hmds1[4] ;
            //            qDebug()<<"hmds 7 and  8 ::"<< hmds1[7]  <<   hmds1[8] ;
            //            qDebug()<<"hmds 11 12"<< hmds1[11]   <<   hmds1[12] ;
            //            qDebug()<<"hmds 13 18 "<< hmds1[17]   <<   hmds1[18] ;

            // added on 29-06-16 as per new ICD
            // for Astra Data 1
            // weight on wheels bit 0
            if (ui->weight_on_wheel->isChecked())
                hmds1[0]= hmds1[0] | 0x8000;
            else
                hmds1[0]= hmds1[0] & 0x7FFF;
            // Apart mode bit 1

            if (ui->cb_apart_mode->isChecked())
                hmds1[0]= hmds1[0] | 0x4000;
            else
                hmds1[0]= hmds1[0] & 0xBFFF;
            //   Engine state bit 2


            if (ui->cb_engine_on->isChecked())
                hmds1[0]= hmds1[0] | 0x2000;
            else
                hmds1[0]= hmds1[0] & 0xDFFF;

            if (ui->man_range_on->isChecked())
                hmds1[0]= hmds1[0] | 0x1000;
            else
                hmds1[0]= hmds1[0]& 0xEFFF;

            if(ui->imm_on->isChecked())
                hmds1[0]= hmds1[0] | 0x0800;
            else
                hmds1[0]= hmds1[0] & 0xF7FF;

            // for Air Attack mode

            //DLZ bit 11
            if(ui->cb_dlz->isChecked())
                hmds1[2]= hmds1[2] | 0x0010;
            else
                hmds1[2]= hmds1[2] & 0xFFEF;


            // Astra selection bits 8-10 001

         /*   if ((ui->cb_astra_rvvae->currentText())=="ASTRA")

                hmds1[2]= hmds1[2]|0x0020;
            else
                hmds1[2]= hmds1[2] & 0xFFDF;

                */



            if ((ui->cb_astra_rvvae->currentText())=="RVVAE") //RVVAE Missile with Catapult launcher
               hmds1[2]= 0x0000;
            else if((ui->cb_astra_rvvae->currentText())=="ASRM1") //Astra MK-I with Rail Launcher
                hmds1[2]= 0x0020;
            else if((ui->cb_astra_rvvae->currentText())=="ASRM2") //Astra MK-II with Rail Launcher
                hmds1[2]= 0x0040;
            else if((ui->cb_astra_rvvae->currentText())=="ASEM1") //Astra MK-I with Ejection Launcher
                hmds1[2]= 0x0060;
            else if((ui->cb_astra_rvvae->currentText())=="ASEM2") //Astra MK-II with Ejection Launcher
                hmds1[2]= 0x0080;

            //todo
            //   for pair launch bit 7
            if(ui->checkbox_pair_launch->isChecked())
                hmds1[2]=hmds1[2]| 0x0100;
            else
                hmds1[2]= hmds1[2] &0xFEFF;



  /*          // added on 14th July 2016 for simulation  of other station missile release

            //  DLT HP required,( bit 6 of LHW)

            // for stn 7 HP req
          //  int dlt_hp_req7=mslp_res_data1[1] & 0x0200;
            if (ui->cb_stn7_hp_req->isChecked())
            {
                hmds1[4]= hmds1[4]|0x0200;
qDebug()<< "in if";
                qDebug("%4x:",hmds1[4]);
            }
            else
            {
                hmds1[4]= hmds1[4]|0x0000;
                qDebug()<< "in else";
            }
            // for stn 8 HP req
           // int dlt_hp_req8=mslp_res_data2[1] & 0x0200;
            if (ui->cb_stn8_hp_req->isChecked())

                hmds1[8]= hmds1[8]|0x0200;
            else
                hmds1[8]=  hmds1[8]|0x0000;

            // for stn 9 HP req
         //   int dlt_hp_req9=mslp_res_data3[1]& 0x0200;
            if (ui->cb_stn9_hp_req->isChecked())
                hmds1[12]= hmds1[12]|0x0200;
            else
                hmds1[12]= hmds1[12]|0x0000;

            // for stn 10 HP req
           //int dlt_hp_req10=mslp_res_data4[1]& 0x0200;
            if (ui->cb_stn10_hp_req->isChecked())

                hmds1[16]= hmds1[16]|0x0200;
            else
                hmds1[16]= hmds1[16]|0x0000;

*/

            if(ui->EL_Launch->isChecked())

                hmds1[24]=hmds1[24]|0x8000;
            else
                 hmds1[24]= 0x0000;

            if(ui->TID->isChecked()) // For target lock break
            {
                hmds1[24]=hmds1[24]|0x0800;
                hmds1[25]=1;
                hmds1[26]=5;
                dstd1[0]=5;
            }
            else
            {
              hmds1[24]=hmds1[24]|0x0000;
             //   dstd1[0]=5;
            }

            modetype = mslp_res_data[22] & 0x01C0;
                if(modetype == 0x0000)
                {
                    ui->modetype->setPalette(palettered);
                    ui->modetype->setText("NO MODE");
                }

                if(modetype == 0x0040)
                {
                    //AMLP_LIVE_MISSILE_MODE = 1,
                    ui->modetype->setPalette(palettegreen);
                    ui->modetype->setText("LIVE MODE");
                }
                if(modetype == 0x0100)
                {
                    // AMLP_MISSILE_SIMULATOR_MODE = 3
                    ui->modetype->setPalette(palettegreen);
                    ui->modetype->setText("MSL SM MODE");
                }
                if(modetype == 0x0180)
                {
                   // AMLP_STORE_SIMULATOR_MODE_MK1 = 2,
                    ui->modetype->setPalette(palettegreen);
                    ui->modetype->setText("STORE MODE MKI");
                }
                if(modetype == 0x0080)
                {
                    //AMLP_STORE_SIMULATOR_MODE_MK2 = 4
                    ui->modetype->setPalette(palettegreen);
                    ui->modetype->setText("STORE MODE MKII");
                }
                if(modetype == 0x01C0)
                {
                    //AMLP_LAUNCHER_OR_ACS_TRNG_MODE = 0

                    ui->modetype->setPalette(palettegreen);
                    ui->modetype->setText(" LH/ACS Mode");
                }
            //

                IMM_state = mslp_res_data[24] & 0x0040;
                if(IMM_state == 0x0040)
                {
                    ui->IMM_status->setPalette(palettegreen);
                    ui->IMM_status->setText("IMM ON");
                }
                else
                {
                    ui->IMM_status->setPalette(palettered);
                    ui->IMM_status->setText("IMM OFF");
                }

                Tgt_status = mslp_res_data[24] & 0x0010;
                if(Tgt_status == 0x0010)
                {
                    ui->Tgt_status->setPalette(palettegreen);
                    ui->Tgt_status->setText("Target IN Range");
                }
                else
                {
                    ui->Tgt_status->setText("");
                }
            //else if()
            //{
              //  hmds1[25]= 0x0001;
           // }
            //         }
            //       else
            //           hmds1[16]= hmds1[16]&0xFDFF;

            // simulation of dlt switch over

            //NKS
           // if(mis_state==0x2000)  // removed on 14th may 2020
           // {
                //DLT HEALTH FAIL BIT-10
                // for stn 7
                //int dlt_hp_req7 = mslp_res_data1[1] & 0xFFDF;
                if(ui->cb_stn7_health_fail->isChecked() )
                    hmds1[4]= hmds1[4] & 0x0FFDF;
               // else
                   // hmds1[4]= hmds1[4] | 0x0020;

                // for stn 8
                //int dlt_hp_req8 = mslp_res_data2[1] & 0xFFDF;
                if(ui->cb_stn8_health_fail->isChecked() )
                    hmds1[8]= hmds1[8] & 0xFFDF;
                //else
                    //hmds1[8]= hmds1[8] | 0x0020;

                //int dlt_hp_req9 = mslp_res_data3[1] & 0xFFDF;
                // for stn 9
                if(ui->cb_stn9_health_fail->isChecked() )
                    hmds1[12]= hmds1[12] & 0xFFDF;
                //else
                   // hmds1[12]= hmds1[12] | 0x0020;

                // for stn 10
                //int dlt_hp_req10 = mslp_res_data4[1] & 0xFFDF;
                if(ui->cb_stn10_health_fail->isChecked() )
                    hmds1[16]= hmds1[16] & 0xFFDF;
               // else
                   // hmds1[16]= hmds1[16] | 0x0020;
         //   }

                // DLT HP Req(BIT-6)

                if(ui->cb_stn7_hp_req->isChecked())
                    hmds1[4]= hmds1[4]|0x0200;
                else
                    hmds1[4]= hmds1[4]|0x0000;

                if(ui->cb_stn8_hp_req->isChecked())
                    hmds1[8]= hmds1[8]|0x0200;
                else
                    hmds1[8]= hmds1[8]|0x0000;

                if(ui->cb_stn9_hp_req->isChecked())
                    hmds1[12]= hmds1[12]|0x0200;
                else
                    hmds1[12]= hmds1[12]|0x0000;

                if(ui->cb_stn10_hp_req->isChecked())
                    hmds1[16]= hmds1[16] | 0x0200;
                else
                    hmds1[16]= hmds1[16]|0x0000;
            // DLT HP Status(BIT-7)

            if(ui->cb_stn7_hp_status->isChecked())
                hmds1[4]= hmds1[4]|0x0100;
            else
                hmds1[4]= hmds1[4]|0x0000;

            if(ui->cb_stn8_hp_status->isChecked())
                hmds1[8]= hmds1[8]|0x0100;
            else
                hmds1[8]= hmds1[8]|0x0000;

            if(ui->cb_stn9_hp_status->isChecked())
                hmds1[12]= hmds1[12]|0x0100;
            else
                hmds1[12]= hmds1[12]|0x0000;

            if(ui->cb_stn10_hp_status->isChecked())
                hmds1[16]= hmds1[16] | 0x0100;
            else
                hmds1[16]= hmds1[16]|0x0000;


            // for simulating msl availability
/*
            if(ui->cb_stn7_available->isChecked())
                hmds1[3]= hmds1[3]|0x0020;
            else
                hmds1[3]= hmds1[3]&0xFFDF;

            if(ui->cb_stn8_available->isChecked())
                hmds1[7]= hmds1[7]|0x0020;
            else
                hmds1[7]= hmds1[7]&0xFFDF;

            if(ui->cb_stn9_available->isChecked())
                hmds1[11]= hmds1[11]|0x0020;
            else
                hmds1[11]= hmds1[11]&0xFFDF;

            if(ui->cb_stn10_available->isChecked())
                hmds1[15]= hmds1[15] | 0x0020;
            else
                hmds1[15]= hmds1[15]&0xFFDF;
                */
            //for IBIT command
            //   added on26th may 2016
            //     if ((mslp_res_data1[1]&0xE000)==0x0000)
            //         freq_cmd_stn7[4]=0x8000;

            //       if ((mslp_res_data2[1]&0xE000)==0x0000)
            //           freq_cmd_stn8[4]=0x8000;
            //       if ((mslp_res_data3[1]&0xE000)==0x0000)
            //           freq_cmd_stn9[4]=0x8000;

            //       if ((mslp_res_data4[1]&0xE000)==0x0000)
            //           freq_cmd_stn10[4]=0x8000;
            //       // for removing IBIT aftr AMLP acknowledgement
            //       if ((mslp_res_data1[21]&0x0080)==0x0080)
            //         freq_cmd_stn7[4]=0x00000;

            //       if ((mslp_res_data2[21]&0x0080)==0x0080)
            //         freq_cmd_stn8[4]=0x00000;

            //       if ((mslp_res_data3[21]&0x0080)==0x0080)
            //         freq_cmd_stn9[4]=0x00000;

            //       if ((mslp_res_data4[21]&0x0080)==0x0080)
            //         freq_cmd_stn10[4]=0x00000;

            /////////DLL Frequency code selection T ///////


            //           if ((ui->freqcombo->currentText()) == "STATION-7")
            {

                if(ui-> le_freq->text()!="0")

                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    //printf("\n stn7 frq is %x",str1);
                    str2=str1<<8;
                    freq_cmd_stn7[0]=freq_cmd_stn7[0]&0x0000;
                    freq_cmd_stn7[0]=freq_cmd_stn7[0]|str1;
                    freq_cmd_stn7[0]=freq_cmd_stn7[0]|str2;

                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn7[0]=freq_cmd_stn7[0]|0x8080; // for seeker and datalink validity
                    // ui->le_freq->setEnabled("FALSE");
                    seekrdl_flag=1;
                 //   printf ("\tfreq cmd is %4X \n", freq_cmd_stn7[0]);
                }
            }

            //            if ((ui->freqcombo->currentText()) == "STATION-8")
            {
                if(ui-> le_freq->text()!="0")
                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    str2=str1<<8;
                    freq_cmd_stn8[0]=freq_cmd_stn8[0]&0x0000;
                    freq_cmd_stn8[0]=freq_cmd_stn8[0]| str1;
                    freq_cmd_stn8[0]=freq_cmd_stn8[0]| str2;
                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn8[0]=freq_cmd_stn8[0]|0x8080;
                    //    ui->le_freq->setEnabled("FALSE");
                    seekrdl_flag=2;
               //     printf ("\n    freq cmd is %4X", freq_cmd_stn8[0]);
                }
            }

            //            if ((ui->freqcombo->currentText()) == "STATION-9")
            {
                if(ui-> le_freq->text()!="0")
                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    str2=str1<<8;
                    freq_cmd_stn9[0]=freq_cmd_stn9[0]&0x0000;
                    freq_cmd_stn9[0]=freq_cmd_stn9[0]| str1;
                    freq_cmd_stn9[0]=freq_cmd_stn9[0]| str2;
                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn9[0]=freq_cmd_stn9[0]|0x8080;
                    seekrdl_flag=3;
                    ui->le_freq->setEnabled("FALSE");
                //    printf ("\n    freq cmd is %4X", freq_cmd_stn9[0]);
                }
            }
            //            if ((ui->freqcombo->currentText()) == "STATION-10")
            {
                if(ui-> le_freq->text()!="0")
                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    str2=str1<<8;
                    freq_cmd_stn10[0]=freq_cmd_stn10[0]&0x0000;
                    freq_cmd_stn10[0]=freq_cmd_stn10[0]|str1;
                    freq_cmd_stn10[0]=freq_cmd_stn10[0]|str2;
                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn10[0]=freq_cmd_stn10[0]|0x8080;
                    seekrdl_flag=4;
                    ui->le_freq->setEnabled("FALSE");
               //     printf ("\n    freq cmd is %4X", freq_cmd_stn10[0]);
                }
            }

 //--------------------------------------DL CODES -------------------------------------------------------//

            //            if ((ui->dl_code_combo->currentText()) == "STATION-7")
            {
                if(ui-> le_DL_ch1_code->text()!= "0")
                {
                    U16BIT str= ui->le_DL_ch1_code->text ().toInt(0, 10);
                    freq_cmd_stn7[1]=str;
                }
                if(ui-> le_DL_ch2_code->text()!= "0")
                {
                    str= ui->le_DL_ch2_code->text ().toInt(0, 10);
                    freq_cmd_stn7[2]=str;
                }
            }
        }
        //        if ((ui->dl_code_combo->currentText()) == "STATION-8")
        {
            if(ui-> le_DL_ch1_code->text()!= "0")
            {
                U16BIT str= ui->le_DL_ch1_code->text ().toInt(0, 10);
                freq_cmd_stn8[1]=str;
            }
            if(ui-> le_DL_ch2_code->text()!= "0")
            {
                str= ui->le_DL_ch2_code->text ().toInt(0, 10);
                freq_cmd_stn8[2]=str;
            }
        }
    }

   if(ui->cb_sdr->isChecked())
    {
        if(msgcnt > prevmsgcnt)
        {
            prevmsgcnt=msgcnt;
            //printf("prev is %d\n",prevmsgcnt);
            ///Change by unical on 070119/////
            if(stn1 == true)
            {
                sg1->generationscenario();
                //               memcpy( dstd1,sg1->Word_RC,32);

                for(int i=0;i<32;i++)
                {
                    dstd1[i]=sg1->Word_RC[i];
                    //                    fprintf(file_rcw1,"%5d\t",sg1->Word_RC[i]);
                }

                //dstd1[0]=1001;
                dstd1[0]=1001;//ui->cb_tgt1->text().toInt();


                //                fprintf(file_rcw1,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw1,"%5d\t",sg1->Word_MC[i]);
                //                }
                //                fprintf(file_mcw1,"\n");
            }else
                memset(dstd1,0,32);


            if(stn2 == true){
                sg2->generationscenario();
                for(int i=0;i<32;i++)
                {
                    dstd2[i]=sg2->Word_RC[i];
                    //                    fprintf(file_rcw2,"%5d\t",sg2->Word_RC[i]);
                }
                //dstd2[0]=2;
                dstd2[0]=1004;//ui->cb_tgt2->text().toInt();
                //                fprintf(file_rcw2,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw2,"%5d\t",sg2->Word_MC[i]);
                //                }
                //                fprintf(file_mcw2,"\n");
            }else
                memset(dstd2,0,32);


            if(stn3 == true){
                sg3->generationscenario();
                for(int i=0;i<32;i++)
                {
                    dstd3[i]=sg3->Word_RC[i];
                    //                    fprintf(file_rcw3,"%5d\t",sg3->Word_RC[i]);
                }
                //dstd3[0]=1003;
                dstd3[0]=1006;//ui->cb_tgt3->text().toInt();
                //                fprintf(file_rcw3,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw3,"%5d\t",sg3->Word_MC[i]);
                //                }
                //                fprintf(file_mcw3,"\n");
            }else
                memset(dstd3,0,32);


            if(stn4 == true){
                sg4->generationscenario();
                for(int i=0;i<32;i++)
                {
                    dstd4[i]=sg4->Word_RC[i];
                    //                    fprintf(file_rcw4,"%5d\t",sg4->Word_RC[i]);
                }
                //dstd4[0]=1004;
                dstd4[0]=1010;//ui->cb_tgt1->text().toInt();
                //                fprintf(file_rcw4,"\n");
                //                for(int i=0;i<18;i++)
                //                {
                //                    fprintf(file_mcw4,"%5d\t",sg4->Word_MC[i]);
                //                }
                //                fprintf(file_mcw4,"\n");
            }else
                memset(dstd4,0,32);
            ///Change by unical on 070119/////


            if(ui->cB_lOTD->currentText() == "Target-1"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg1->Word_LOTD[i];
                //lotd[0]=1;
                lotd[0]=1001;//ui->cb_tgt1->text().toInt();
            }
            else if(ui->cB_lOTD->currentText() == "Target-2"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg2->Word_LOTD[i];
                //lotd[0]=2;
                lotd[0]=1004;//ui->cb_tgt2->text().toInt();
            }
            else if(ui->cB_lOTD->currentText() == "Target-3"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg3->Word_LOTD[i];
                //lotd[0]=3;
                lotd[0]=1006;//ui->cb_tgt3->text().toInt();
            }
            else if(ui->cB_lOTD->currentText() == "Target-4"){
                for(int i=0;i<32;i++)
                    lotd[i]=sg4->Word_LOTD[i];
               // lotd[0]=4;
                lotd[0]=1010;//ui->cb_tgt4->text().toInt();
            }
            else
                memset(lotd,0,32);
            lotd[19]=recievecount;
#if 0
            if(!feof(file_RC))
            {
                fscanf(file_RC, "%f", &fkamTime);
                for (j=0; j<32; j++)
                    fscanf(file_RC, "%d", &data1[j]);
                fscanf(file_RC,"\n" );
                for(j=0;j<32;j++)
                {
                    dstd1[j]=data1[j];
                    dstd2[j]=data1[j];
                    dstd3[j]=data1[j];
                    dstd4[j]=data1[j];
                    lotd[j]=data1[j];
                }
                for(j=0;j<32;j++)
                {
                    //printf("\tRCfileData:%d",lotd[j]);
                }
                printf("\n");

                //                for(j=1;j<33;j++)
                //                    dstd1[j-1]=data1[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd1[j]);
                //                }
                //                printf("\n");

                //                for(j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data2[j]);
                //                for(j=1;j<33;j++)
                //                    dstd2[j-1]=data2[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd2[j]);
                //                }
                //                printf("\n");

                //                for (j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data3[j]);
                //                for(j=1;j<33;j++)
                //                    dstd3[j-1]=data3[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd3[j]);
                //                }
                //                printf("\n");

                //                for (j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data4[j]);
                //                for(j=1;j<33;j++)
                //                    dstd4[j-1]=data4[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",dstd4[j]);
                //                }
                //                printf("\n");

                //                for (j=0; j<33; j++)
                //                    fscanf(file_RC, "%x\n", &data5[j]);
                //                for(j=1;j<33;j++)
                //                    lotd[j-1]=data5[j];
                //                for(j=0;j<33;j++)
                //                {
                //                    printf("%x",lotd[j]);
                //                }
                //                printf("\n");
            }
            if(feof(file_RC))
            {
                //                qDebug()<<"in rewind slot\n";
                //                printf("end of rc file\n");
                //                rewind(file_RC);
                fclose(file_RC);
                // usleep(10000);
                file_RC = fopen(rcFilePath.toUtf8(), "r");
                qDebug()<<"rcfile path ::"<<rcFilePath;
                fgets(szDummy,512, file_RC);
            }
#endif
            dstd1[27]= 0x0000;
            dstd1[28]= 0x0000;
            dstd2[27]= 0x0000;
            dstd2[28]= 0x0000;
            dstd3[27]= 0x0000;
            dstd3[28]= 0x0000;
            dstd4[27]= 0x0000;
            dstd4[28]= 0x0000;
            lotd[27]=0x0000;
            lotd[28]=0x0000;
            // test case for invalid target
            //lotd[0]=0x0000;

// HMDS data block update-------------------------------------------------------------------------------------------------------

            //  qDebug()<<"mslp_res_data1 ::"<<mslp_res_data1[0] << mslp_res_data1[1] <<"mslp_res_data2 ::"<<mslp_res_data2[0] << mslp_res_data2[1] ;
            // qDebug()<<"mslp_res_data3 ::"<<mslp_res_data3[0] << mslp_res_data3[1] <<"mslp_res_data4 ::"<<mslp_res_data4[0] << mslp_res_data4[1] ;


            //HMDSFile=fopen("HMDS.txt","a");

//                        for(j=0;j<32;j++)
//                        {
//                            qDebug()<<"hmds"<<hmds1[j];
//                            hmds1[j] = 0x0000;
//                            fprintf(HMDSFile, "%04x ",hmds1[j]);


//                          //  qDebug()<<"hmds array::"<<hmds1[j];
//                        }

//                        for(j=0;j<32;j++)
//                        {
//                            qDebug()<<"hmds"<<hmds1[j];
//                            fprintf(HMDS8File, "%04x ",hmds2[j]);

//                            hmds1[j] = 0x0000;
//                          //  qDebug()<<"hmds array::"<<hmds1[j];
//                        }

//                        for(j=0;j<32;j++)
//                        {
//                            qDebug()<<"hmds"<<hmds1[j];
//                            fprintf(HMDS9File, "%04x ",hmds3[j]);

//                            hmds1[j] = 0x0000;
//                          //  qDebug()<<"hmds array::"<<hmds1[j];
//                        }


//                        for(j=0;j<32;j++)
//                        {
//                            qDebug()<<"hmds"<<hmds1[j];
//                            fprintf(HMDS10File, "%04x ",hmds4[j]);

//                            hmds1[j] = 0x0000;
//                          //  qDebug()<<"hmds array::"<<hmds1[j];
//                        }
            //            qDebug()<<"mslp_res_data1[0] ::"<<mslp_res_data1[0];
            //            qDebug()<<"mslp_res_data1[1] ::"<<mslp_res_data1[1];
            //            qDebug()<<"hmds[3] :"<<hmds1[3];
            //            qDebug()<<"hmds[4] :"<<hmds1[4];
            //            qDebug()<<"mslp_res_data1[1] ::"<<mslp_res_data1[1];

            hmds1[3]=mslp_res_data1[0];
            hmds1[4]=mslp_res_data1[1];

            hmds1[7]=mslp_res_data2[0];
            hmds1[8]=mslp_res_data2[1];
            //            qDebug()<<"mslp_res_data3[0] ::"<<mslp_res_data3[0];
            //            qDebug()<<"mslp_res_data3[1] ::"<<mslp_res_data3[1];
            //            qDebug()<<"hmds[11] :"<<hmds1[11];
            //            qDebug()<<"hmds[12] :"<<hmds1[12];

            hmds1[11]=mslp_res_data3[0];
            hmds1[12]=mslp_res_data3[1];

            hmds1[15]=mslp_res_data4[0];
            hmds1[16]=mslp_res_data4[1];

            //            qDebug()<<"\n\n hmds 3 and 4 ::"<< hmds1[3] << hmds1[4] ;
            //            qDebug()<<"hmds 7 and  8 ::"<< hmds1[7]  <<   hmds1[8] ;
            //            qDebug()<<"hmds 11 12"<< hmds1[11]   <<   hmds1[12] ;
            //            qDebug()<<"hmds 13 18 "<< hmds1[17]   <<   hmds1[18] ;

            // added on 29-06-16 as per new ICD
            // for Astra Data 1
            // weight on wheels bit 0
            if (ui->weight_on_wheel->isChecked())
                hmds1[0]= hmds1[0] | 0x8000;
            else
                hmds1[0]= hmds1[0] & 0x7FFF;
            // Apart mode bit 1

            if (ui->cb_apart_mode->isChecked())
                hmds1[0]= hmds1[0] | 0x4000;
            else
                hmds1[0]= hmds1[0] & 0xBFFF;
            //   Engine state bit 2


            if (ui->cb_engine_on->isChecked())
                hmds1[0]= hmds1[0] | 0x2000;
            else
                hmds1[0]= hmds1[0] & 0xDFFF;

            if (ui->man_range_on->isChecked())
                hmds1[0]= hmds1[0] | 0x1000;
            else
                hmds1[0]= hmds1[0]& 0xEFFF;

            if(ui->imm_on->isChecked())
                hmds1[0]= hmds1[0] | 0x0800;
            else
                hmds1[0]= hmds1[0] & 0xF7FF;

            // for Air Attack mode

            //DLZ bit 11
            if(ui->cb_dlz->isChecked())
                hmds1[2]= hmds1[2] | 0x0010;
            else
                hmds1[2]= hmds1[2] & 0xFFEF;

            // Astra selection bits 8-10 001

         /*   if ((ui->cb_astra_rvvae->currentText())=="ASTRA")

                hmds1[2]= hmds1[2]|0x0020;
            else
                hmds1[2]= hmds1[2] & 0xFFDF;

                */



            if ((ui->cb_astra_rvvae->currentText())=="RVVAE") //RVVAE Missile with Catapult launcher
               hmds1[2]= 0x0000;
            else if((ui->cb_astra_rvvae->currentText())=="ASRM1") //Astra MK-I with Rail Launcher
                hmds1[2]= 0x0020;
            else if((ui->cb_astra_rvvae->currentText())=="ASRM2") //Astra MK-II with Rail Launcher
                hmds1[2]= 0x0040;
            else if((ui->cb_astra_rvvae->currentText())=="ASEM1") //Astra MK-I with Ejection Launcher
                hmds1[2]= 0x0060;
            else if((ui->cb_astra_rvvae->currentText())=="ASEM2") //Astra MK-II with Ejection Launcher
                hmds1[2]= 0x0080;

            //todo
            //   for pair launch bit 7
            if(ui->checkbox_pair_launch->isChecked())
                hmds1[2]=hmds1[2]| 0x0100;
            else
                hmds1[2]= hmds1[2] &0xFEFF;



  /*          // added on 14th July 2016 for simulation  of other station missile release

            //  DLT HP required,( bit 6 of LHW)

            // for stn 7 HP req
          //  int dlt_hp_req7=mslp_res_data1[1] & 0x0200;
            if (ui->cb_stn7_hp_req->isChecked())
            {
                hmds1[4]= hmds1[4]|0x0200;
qDebug()<< "in if";
                qDebug("%4x:",hmds1[4]);
            }
            else
            {
                hmds1[4]= hmds1[4]|0x0000;
                qDebug()<< "in else";
            }
            // for stn 8 HP req
           // int dlt_hp_req8=mslp_res_data2[1] & 0x0200;
            if (ui->cb_stn8_hp_req->isChecked())

                hmds1[8]= hmds1[8]|0x0200;
            else
                hmds1[8]=  hmds1[8]|0x0000;

            // for stn 9 HP req
         //   int dlt_hp_req9=mslp_res_data3[1]& 0x0200;
            if (ui->cb_stn9_hp_req->isChecked())
                hmds1[12]= hmds1[12]|0x0200;
            else
                hmds1[12]= hmds1[12]|0x0000;

            // for stn 10 HP req
           //int dlt_hp_req10=mslp_res_data4[1]& 0x0200;
            if (ui->cb_stn10_hp_req->isChecked())

                hmds1[16]= hmds1[16]|0x0200;
            else
                hmds1[16]= hmds1[16]|0x0000;

*/

            if(ui->EL_Launch->isChecked())

                hmds1[24]=hmds1[24]|0x8000;
            else
                 hmds1[24]= 0x0000;

            if(ui->TID->isChecked()) // For target lock break
            {
                hmds1[24]=hmds1[24]|0x0800;
                hmds1[25]=1;
                hmds1[26]=5;
                dstd1[0]=5;
            }
            else
            {
              hmds1[24]=hmds1[24]|0x0000;
                dstd1[0]=5;
            }
/*
            modetype = mslp_res_data[22] & 0x01C0;
                if(modetype == 0x0000)
                {
                    ui->modetype->setText("NO MODE");
                }

                if(modetype == 0x0040)
                {
                    //AMLP_LIVE_MISSILE_MODE = 1,
                    ui->modetype->setText("LIVE MODE");
                }
                if(modetype == 0x0100)
                {
                    // AMLP_MISSILE_SIMULATOR_MODE = 3
                    ui->modetype->setText("MSL SM MODE");
                }
                if(modetype == 0x0180)
                {
                   // AMLP_STORE_SIMULATOR_MODE_MK1 = 2,
                    ui->modetype->setText("STORE MODE MK1");
                }
                if(modetype == 0x0080)
                {
                    //AMLP_STORE_SIMULATOR_MODE_MK2 = 4
                    ui->modetype->setText("STORE MODE MK1I");
                }
                if(modetype == 0x01C0)
                {
                    //AMLP_LAUNCHER_OR_ACS_TRNG_MODE = 0

                    ui->modetype->setText(" LH/ACS Mode");
                }
            //
*/

            //else if()
            //{
              //  hmds1[25]= 0x0001;
           // }
            //         }
            //       else
            //           hmds1[16]= hmds1[16]&0xFDFF;

            // simulation of dlt switch over

            //NKS
           // if(mis_state==0x2000)  // removed on 14th may 2020
           // {
                //DLT HEALTH FAIL BIT-10
                // for stn 7
                //int dlt_hp_req7 = mslp_res_data1[1] & 0xFFDF;
                //togglingcount=0;
                if(ui->toggle->isChecked() )
                {
                    togglingcount++;


                if(togglingcount==1)


                        hmds1[4]= hmds1[4]|0x0200;
                    else
                        hmds1[4]= hmds1[4]|0x0000;

                 if(togglingcount==2)

                     hmds1[4]= hmds1[4]|0x0200;
                 else
                     hmds1[4]= hmds1[4]|0x0000;
                      togglingcount=0;
                  }

                if(ui->cb_stn7_health_fail->isChecked() )
                    hmds1[4]= hmds1[4] & 0x0FFDF;
               // else
                   // hmds1[4]= hmds1[4] | 0x0020;

                // for stn 8
                //int dlt_hp_req8 = mslp_res_data2[1] & 0xFFDF;
                if(ui->cb_stn8_health_fail->isChecked() )
                    hmds1[8]= hmds1[8] & 0xFFDF;
                //else
                    //hmds1[8]= hmds1[8] | 0x0020;

                //int dlt_hp_req9 = mslp_res_data3[1] & 0xFFDF;
                // for stn 9
                if(ui->cb_stn9_health_fail->isChecked() )
                    hmds1[12]= hmds1[12] & 0xFFDF;
                //else
                   // hmds1[12]= hmds1[12] | 0x0020;

                // for stn 10
                //int dlt_hp_req10 = mslp_res_data4[1] & 0xFFDF;
                if(ui->cb_stn10_health_fail->isChecked() )
                    hmds1[16]= hmds1[16] & 0xFFDF;
               // else
                   // hmds1[16]= hmds1[16] | 0x0020;
         //   }

                // DLT HP Req(BIT-6)

                if(ui->cb_stn7_hp_req->isChecked())
                    hmds1[4]= hmds1[4]|0x0200;
                else
                    hmds1[4]= hmds1[4]|0x0000;

                if(ui->cb_stn8_hp_req->isChecked())
                    hmds1[8]= hmds1[8]|0x0200;
                else
                    hmds1[8]= hmds1[8]|0x0000;

                if(ui->cb_stn9_hp_req->isChecked())
                    hmds1[12]= hmds1[12]|0x0200;
                else
                    hmds1[12]= hmds1[12]|0x0000;

                if(ui->cb_stn10_hp_req->isChecked())
                    hmds1[16]= hmds1[16] | 0x0200;
                else
                    hmds1[16]= hmds1[16]|0x0000;
            // DLT HP Status(BIT-7)

            if(ui->cb_stn7_hp_status->isChecked())
                hmds1[4]= hmds1[4]|0x0100;
            else
                hmds1[4]= hmds1[4]|0x0000;

            if(ui->cb_stn8_hp_status->isChecked())
                hmds1[8]= hmds1[8]|0x0100;
            else
                hmds1[8]= hmds1[8]|0x0000;

            if(ui->cb_stn9_hp_status->isChecked())
                hmds1[12]= hmds1[12]|0x0100;
            else
                hmds1[12]= hmds1[12]|0x0000;

            if(ui->cb_stn10_hp_status->isChecked())
                hmds1[16]= hmds1[16] | 0x0100;
            else
                hmds1[16]= hmds1[16]|0x0000;


            // for simulating msl availability
/*
            if(ui->cb_stn7_available->isChecked())
                hmds1[3]= hmds1[3]|0x0020;
            else
                hmds1[3]= hmds1[3]&0xFFDF;

            if(ui->cb_stn8_available->isChecked())
                hmds1[7]= hmds1[7]|0x0020;
            else
                hmds1[7]= hmds1[7]&0xFFDF;

            if(ui->cb_stn9_available->isChecked())
                hmds1[11]= hmds1[11]|0x0020;
            else
                hmds1[11]= hmds1[11]&0xFFDF;

            if(ui->cb_stn10_available->isChecked())
                hmds1[15]= hmds1[15] | 0x0020;
            else
                hmds1[15]= hmds1[15]&0xFFDF;
                */
            //for IBIT command
            //   added on26th may 2016
            //     if ((mslp_res_data1[1]&0xE000)==0x0000)
            //         freq_cmd_stn7[4]=0x8000;

            //       if ((mslp_res_data2[1]&0xE000)==0x0000)
            //           freq_cmd_stn8[4]=0x8000;
            //       if ((mslp_res_data3[1]&0xE000)==0x0000)
            //           freq_cmd_stn9[4]=0x8000;

            //       if ((mslp_res_data4[1]&0xE000)==0x0000)
            //           freq_cmd_stn10[4]=0x8000;
            //       // for removing IBIT aftr AMLP acknowledgement
            //       if ((mslp_res_data1[21]&0x0080)==0x0080)
            //         freq_cmd_stn7[4]=0x00000;

            //       if ((mslp_res_data2[21]&0x0080)==0x0080)
            //         freq_cmd_stn8[4]=0x00000;

            //       if ((mslp_res_data3[21]&0x0080)==0x0080)
            //         freq_cmd_stn9[4]=0x00000;

            //       if ((mslp_res_data4[21]&0x0080)==0x0080)
            //         freq_cmd_stn10[4]=0x00000;

            /////////DLL Frequency code selection T ///////


            //           if ((ui->freqcombo->currentText()) == "STATION-7")
            {

                if(ui-> le_freq->text()!="0")

                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    //printf("\n stn7 frq is %x",str1);
                    str2=str1<<8;
                    freq_cmd_stn7[0]=freq_cmd_stn7[0]&0x0000;
                    freq_cmd_stn7[0]=freq_cmd_stn7[0]|str1;
                    freq_cmd_stn7[0]=freq_cmd_stn7[0]|str2;

                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn7[0]=freq_cmd_stn7[0]|0x8080; // for seeker and datalink validity
                    // ui->le_freq->setEnabled("FALSE");
                    printf ("\tfreq cmd is %4X \n", freq_cmd_stn7[0]);
                }
            }

            //            if ((ui->freqcombo->currentText()) == "STATION-8")
            {
                if(ui-> le_freq->text()!="0")
                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    str2=str1<<8;
                    freq_cmd_stn8[0]=freq_cmd_stn8[0]&0x0000;
                    freq_cmd_stn8[0]=freq_cmd_stn8[0]| str1;
                    freq_cmd_stn8[0]=freq_cmd_stn8[0]| str2;
                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn8[0]=freq_cmd_stn8[0]|0x8080;
                    //    ui->le_freq->setEnabled("FALSE");
                    printf ("\n    freq cmd is %4X", freq_cmd_stn8[0]);
                }
            }

            //            if ((ui->freqcombo->currentText()) == "STATION-9")
            {
                if(ui-> le_freq->text()!="0")
                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    str2=str1<<8;
                    freq_cmd_stn9[0]=freq_cmd_stn9[0]&0x0000;
                    freq_cmd_stn9[0]=freq_cmd_stn9[0]| str1;
                    freq_cmd_stn9[0]=freq_cmd_stn9[0]| str2;
                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn9[0]=freq_cmd_stn9[0]|0x8080;
                    ui->le_freq->setEnabled("FALSE");
                    printf ("\n    freq cmd is %4X", freq_cmd_stn9[0]);
                }
            }
            //            if ((ui->freqcombo->currentText()) == "STATION-10")
            {
                if(ui-> le_freq->text()!="0")
                {
                    str1= ui->le_freq->text ().toInt(0, 10);
                    str2=str1<<8;
                    freq_cmd_stn10[0]=freq_cmd_stn10[0]&0x0000;
                    freq_cmd_stn10[0]=freq_cmd_stn10[0]|str1;
                    freq_cmd_stn10[0]=freq_cmd_stn10[0]|str2;
                    if(ui->cb_validity->currentText()=="1-VALID")
                        freq_cmd_stn10[0]=freq_cmd_stn10[0]|0x8080;
                    ui->le_freq->setEnabled("FALSE");
                    printf ("\n    freq cmd is %4X", freq_cmd_stn10[0]);
                }
            }

            //////DL CODES  ///////
            //            if ((ui->dl_code_combo->currentText()) == "STATION-7")
            {
                if(ui-> le_DL_ch1_code->text()!= "0")
                {
                    U16BIT str= ui->le_DL_ch1_code->text ().toInt(0, 10);
                    freq_cmd_stn7[1]=str;
                }
                if(ui-> le_DL_ch2_code->text()!= "0")
                {
                    str= ui->le_DL_ch2_code->text ().toInt(0, 10);
                    freq_cmd_stn7[2]=str;
                }
            }
        }
        //        if ((ui->dl_code_combo->currentText()) == "STATION-8")
        {
            if(ui-> le_DL_ch1_code->text()!= "0")
            {
                U16BIT str= ui->le_DL_ch1_code->text ().toInt(0, 10);
                freq_cmd_stn8[1]=str;
            }
            if(ui-> le_DL_ch2_code->text()!= "0")
            {
                str= ui->le_DL_ch2_code->text ().toInt(0, 10);
                freq_cmd_stn8[2]=str;
            }
        }
    }
    //    if ((ui->dl_code_combo->currentText()) == "STATION-9")
    {
        if(ui-> le_DL_ch1_code->text()!= "0")
        {
            U16BIT  str= ui->le_DL_ch1_code->text ().toInt(0, 10);
            freq_cmd_stn9[1]=str;
        }
        if(ui-> le_DL_ch2_code->text()!= "0")
        {
            str= ui->le_DL_ch2_code->text ().toInt(0, 10);
            freq_cmd_stn9[2]=str;
        }
    }
    //    if ((ui->dl_code_combo->currentText()) == "STATION-10")
    {
        if(ui-> le_DL_ch1_code->text()!= "0")
        {
            U16BIT  str= ui->le_DL_ch1_code->text ().toInt(0, 10);
            freq_cmd_stn10[1]=str;
        }
        if(ui-> le_DL_ch2_code->text()!= "0")
        {
            str= ui->le_DL_ch2_code->text ().toInt(0, 10);
            freq_cmd_stn10[2]=str;
        }
    }

    /*** WCS Station Status -Word 3 -- STATION 7 --******/

    // //Modified on 17th August 2016 since Word 3 LSB and MSB are interchanged
    //******** station selection- BIT 15 *******/

    if(ui->cb_stn7_selection->isChecked())
   {
        freq_cmd_stn7[3]= freq_cmd_stn7[3]|0x0001;
        stnflag=1;
    }
    else
        freq_cmd_stn7[3]= freq_cmd_stn7[3]&0xFFFE;

    // Launch-BIT 13
    if(ui->cb_stn7_launch->isChecked())
        freq_cmd_stn7[3]= freq_cmd_stn7[3]|0x0004;
    else
        freq_cmd_stn7[3]= freq_cmd_stn7[3]&0xFFFB;

    // released -BIT 11

    if(ui->cb_stn7_release->isChecked())
    {
        freq_cmd_stn7[3]= freq_cmd_stn7[3]|0x0010;
        ui->lb_launch_stn7->setHidden(true);
 }

    else
    {
        freq_cmd_stn7[3]= freq_cmd_stn7[3]&0xFFEF;
       // ui->lb_launch_stn7->setHidden(false);
 }
    // Hang fire-BIT 5
    if(ui->cb_stn7_hang_fire->isChecked())
        freq_cmd_stn7[3]= freq_cmd_stn7[3]|0x0400;
    else
        freq_cmd_stn7[3]= freq_cmd_stn7[3]&0xFBFF;

    // CAP-BIT 3
    if(ui->cb_stn7_cap->isChecked())
        freq_cmd_stn7[3]= freq_cmd_stn7[3]|0x1000;
    else
        freq_cmd_stn7[3]= freq_cmd_stn7[3]&0xEFFF;

    //   WORD 4
    //IBIT command-BIT 0
    if(ui->cb_stn7_ibit->isChecked())
        freq_cmd_stn7[4]= freq_cmd_stn7[4]|0x8000;
    else
        freq_cmd_stn7[4]= freq_cmd_stn7[4]&0x7FFF;

    // O-Level test-BIT 1
    if(ui->cb_stn7_o_level->isChecked())
        freq_cmd_stn7[4]= freq_cmd_stn7[4]|0x4000;
    else
        freq_cmd_stn7[4]= freq_cmd_stn7[4]&0xBFFF;



    /*////////////////Station Data and Command(WORD4)//////////////////////*/



   /*...............STATION-7......................*/

            // Training Mode STN7
           if(ui->acs_stn7->currentText() == "ACS CMD")
               freq_cmd_stn7[4] = 0x1000;// Traning Mode ON
           else if(ui->acs_stn7->currentText() == "OFF CMD")
               freq_cmd_stn7[4] = 0x2000;// Traning Mode OFF
           else if(ui->acs_stn7->currentText() == "NO CMD")
               freq_cmd_stn7[4] = 0x0000;// NO cmd
           else
               qDebug()<<"test"<<freq_cmd_stn7[4];


       //FB1

       if(ui->fb1_stn7->isChecked())
          freq_cmd_stn7[4] |= 0x0200;// FB1 ON
       else
          freq_cmd_stn7[4] &= (~0x0200);// FB1 OFF



       //FB2
       if(ui->fb2_stn7->isChecked())
          freq_cmd_stn7[4] |= 0x0100;// FB2 ON
       else
          freq_cmd_stn7[4] &= (~0x0100);// FB2 OFF

       //IMM
        if(ui->imm_stn7->isChecked())
           freq_cmd_stn7[4] |= 0x0400;// IMM ON
        else
           freq_cmd_stn7[4] &= (~0x0400);// IMM OFF

       //HEM
       if(ui->hem_stn7->isChecked())
          freq_cmd_stn7[4] |= 0x0080;// HEM ON
       else
          freq_cmd_stn7[4] &= (~0x0080);// HEM OFF

       /*...............STATION-8......................*/

                // Training Mode STN8
               if(ui->acs_stn8->currentText() == "ACS CMD")
                   freq_cmd_stn8[4] = 0x1000;// Traning Mode ON
               else if(ui->acs_stn8->currentText() == "OFF CMD")
                   freq_cmd_stn8[4] = 0x2000;// Traning Mode OFF
               else if(ui->acs_stn8->currentText() == "NO CMD")
                   freq_cmd_stn8[4] = 0x0000;// NO cmd
               else
                   qDebug()<<"test"<<freq_cmd_stn8[4];


           //FB1

           if(ui->fb1_stn8->isChecked())
              freq_cmd_stn8[4] |= 0x0200;// FB1 ON
           else
              freq_cmd_stn8[4] &= (~0x0200);// FB1 OFF



           //FB2
           if(ui->fb2_stn8->isChecked())
              freq_cmd_stn8[4] |= 0x0100;// FB2 ON
           else
              freq_cmd_stn8[4] &= (~0x0100);// FB2 OFF


           //IMM
            if(ui->imm_stn8->isChecked())
               freq_cmd_stn8[4] |= 0x0400;// IMM ON
            else
               freq_cmd_stn8[4] &= (~0x0400);// IMM OFF

           //HEM
           if(ui->hem_stn8->isChecked())
              freq_cmd_stn8[4] |= 0x0080;// HEM ON
           else
              freq_cmd_stn8[4] &= (~0x0080);// HEM OFF


           /*...............STATION-9......................*/

                    // Training Mode STN9
                   if(ui->acs_stn9->currentText() == "ACS CMD")
                       freq_cmd_stn9[4] = 0x1000;// Traning Mode ON
                   else if(ui->acs_stn9->currentText() == "OFF CMD")
                       freq_cmd_stn9[4] = 0x2000;// Traning Mode OFF
                   else if(ui->acs_stn9->currentText() == "NO CMD")
                       freq_cmd_stn9[4] = 0x0000;// NO cmd
                   else
                       qDebug()<<"test"<<freq_cmd_stn9[4];


               //FB1

               if(ui->fb1_stn9->isChecked())
                  freq_cmd_stn9[4] |= 0x0200;// FB1 ON
               else
                  freq_cmd_stn9[4] &= (~0x0200);// FB1 OFF



               //FB2
               if(ui->fb2_stn9->isChecked())
                  freq_cmd_stn9[4] |= 0x0100;// FB2 ON
               else
                  freq_cmd_stn9[4] &= (~0x0100);// FB2 OFF

               //IMM
                if(ui->imm_stn9->isChecked())
                   freq_cmd_stn9[4] |= 0x0400;// IMM ON
                else
                   freq_cmd_stn9[4] &= (~0x0400);// IMM OFF


               //HEM
               if(ui->hem_stn9->isChecked())
                  freq_cmd_stn9[4] |= 0x0080;// HEM ON
               else
                  freq_cmd_stn9[4] &= (~0x0080);// HEM OFF



               /*...............STATION-10......................*/

                        // Training Mode STN10
                       if(ui->acs_stn10->currentText() == "ACS CMD")
                           freq_cmd_stn10[4] = 0x1000;// Traning Mode ON
                       else if(ui->acs_stn10->currentText() == "OFF CMD")
                           freq_cmd_stn10[4] = 0x2000;// Traning Mode OFF
                       else if(ui->acs_stn10->currentText() == "NO CMD")
                           freq_cmd_stn10[4] = 0x0000;// NO cmd
                       else
                           qDebug()<<"test"<<freq_cmd_stn10[4];


                   //FB1

                   if(ui->fb1_stn10->isChecked())
                      freq_cmd_stn10[4] |= 0x0200;// FB1 ON
                   else
                      freq_cmd_stn10[4] &= (~0x0200);// FB1 OFF



                   //FB2
                   if(ui->fb2_stn10->isChecked())
                      freq_cmd_stn10[4] |= 0x0100;// FB2 ON
                   else
                      freq_cmd_stn10[4] &= (~0x0100);// FB2 OFF


                   //IMM
                    if(ui->imm_stn10->isChecked())
                       freq_cmd_stn10[4] |= 0x0400;// IMM ON
                    else
                       freq_cmd_stn10[4] &= (~0x0400);// IMM OFF


                   //HEM
                   if(ui->hem_stn10->isChecked())
                      freq_cmd_stn10[4] |= 0x0080;// HEM ON
                   else
                      freq_cmd_stn10[4] &= (~0x0080);// HEM OFF





       //......................................................................//




    // WCS Station Status -Word 3 --    // STATION 8

    // station selection- BIT 15
    if(ui->cb_stn8_selection->isChecked())
                   {
        freq_cmd_stn8[3]= freq_cmd_stn8[3]|0x0001;
        stnflag=2;
    }
    else
        freq_cmd_stn8[3]= freq_cmd_stn8[3]&0xFFFE;

    // Launch-BIT 13
    if(ui->cb_stn8_launch->isChecked())
        freq_cmd_stn8[3]= freq_cmd_stn8[3]|0x0004;
    else
        freq_cmd_stn8[3]= freq_cmd_stn8[3]&0xFFFB;


    // released -BIT 11

    if(ui->cb_stn8_release->isChecked())
    {
        freq_cmd_stn8[3]= freq_cmd_stn8[3]|0x0010;
       ui->lb_launch_stn8->setHidden(true);
}
    else
    {
        freq_cmd_stn8[3]= freq_cmd_stn8[3]&0xFFEF;
        //ui->lb_launch_stn8->setHidden(false);
}



    // Hang fire-BIT 5
    if(ui->cb_stn8_hang_fire->isChecked())
        freq_cmd_stn8[3]= freq_cmd_stn8[3]|0x0400;
    else
        freq_cmd_stn8[3]= freq_cmd_stn8[3]&0xFBFF;

    // CAP-BIT 3
    if(ui->cb_stn8_cap->isChecked())
        freq_cmd_stn8[3]= freq_cmd_stn8[3]|0x1000;
    else
        freq_cmd_stn8[3]= freq_cmd_stn8[3]&0xEFFF;

    //   WORD 4

    //IBIT command-BIT 0
    if(ui->cb_stn8_ibit->isChecked())
        freq_cmd_stn8[4]= freq_cmd_stn8[4]|0x8000;
    else
        freq_cmd_stn8[4]= freq_cmd_stn8[4]&0x7FFF;


    // O-Level test-BIT 1
    if(ui->cb_stn8_o_level->isChecked())
        freq_cmd_stn8[4]= freq_cmd_stn8[4]|0x4000;
    else
        freq_cmd_stn8[4]= freq_cmd_stn8[4]&0xBFFF;


    // WCS Station Status -Word 3--  STATION 9 //

    // station selection- BIT 15
    if(ui->cb_stn9_selection->isChecked())
    {
        stnflag=3;
        freq_cmd_stn9[3]= freq_cmd_stn9[3]|0x0001;
    }
    else
        freq_cmd_stn9[3]= freq_cmd_stn9[3]&0xFFFE;


    // Launch-BIT 13
    if(ui->cb_stn9_launch->isChecked())
        freq_cmd_stn9[3]= freq_cmd_stn9[3]|0x0004;
    else
        freq_cmd_stn9[3]= freq_cmd_stn9[3]&0xFFFB;

    // released -BIT 11

    if(ui->cb_stn9_release->isChecked())
    {
        freq_cmd_stn9[3]= freq_cmd_stn9[3]|0x0010;
    ui->lb_launch_stn9->setHidden(true);
}
    else
    {
        freq_cmd_stn9[3]= freq_cmd_stn9[3]&0xFFEF;
    //ui->lb_launch_stn9->setHidden(false);
}


    // Hang fire-BIT 5
    if(ui->cb_stn9_hang_fire->isChecked())
        freq_cmd_stn9[3]= freq_cmd_stn9[3]|0x0400;
    else
        freq_cmd_stn9[3]= freq_cmd_stn9[3]&0xFBFF;


    // CAP-BIT 3
    if(ui->cb_stn9_cap->isChecked())
        freq_cmd_stn9[3]= freq_cmd_stn9[3]|0x1000;
    else
        freq_cmd_stn9[3]= freq_cmd_stn9[3]&0xEFFF;

    //   WORD 4

    //IBIT command-BIT 0
    if(ui->cb_stn9_ibit->isChecked())
        freq_cmd_stn9[4]= freq_cmd_stn9[4]|0x8000;
    else
        freq_cmd_stn9[4]= freq_cmd_stn9[4]&0x7FFF;

    // O-Level test-BIT 1
    if(ui->cb_stn9_o_level->isChecked())
        freq_cmd_stn9[4]= freq_cmd_stn9[4]|0x4000;
    else
        freq_cmd_stn9[4]= freq_cmd_stn9[4]&0xBFFF;

    // WCS Station Status -Word 3
    // STATION 10

    // station selection- BIT 15
    if(ui->cb_stn10_selection->isChecked())
    {
        stnflag=4;
        freq_cmd_stn10[3]= freq_cmd_stn10[3]|0x0001;
    }
    else
        freq_cmd_stn10[3]= freq_cmd_stn10[3]&0xFFFE;


    // Launch-BIT 13
    if(ui->cb_stn10_launch->isChecked())
        freq_cmd_stn10[3]= freq_cmd_stn10[3]|0x0004;
    else
        freq_cmd_stn10[3]= freq_cmd_stn10[3]&0xFFFB;

    // released -BIT 11

    if(ui->cb_stn10_release->isChecked())
    {
        freq_cmd_stn10[3]= freq_cmd_stn10[3]|0x0010;
        ui->lb_launch_stn10->setHidden(true);
}
    else
    {
        freq_cmd_stn10[3]= freq_cmd_stn10[3]&0xFFEF;
   // ui->lb_launch_stn10->setHidden(false);

}
    // Hang fire-BIT 5
    if(ui->cb_stn10_hang_fire->isChecked())
        freq_cmd_stn10[3]= freq_cmd_stn10[3]|0x0400;
    else
        freq_cmd_stn10[3]= freq_cmd_stn10[3]&0xFBFF;


    // CAP-BIT 3
    if(ui->cb_stn10_cap->isChecked())
        freq_cmd_stn10[3]= freq_cmd_stn10[3]|0x1000;
    else
        freq_cmd_stn10[3]= freq_cmd_stn10[3]&0xEFFF;

    //   WORD 4

    //IBIT command-BIT 0
    if(ui->cb_stn10_ibit->isChecked())
        freq_cmd_stn10[4]= freq_cmd_stn10[4]|0x8000;
    else
        freq_cmd_stn10[4]= freq_cmd_stn10[4]&0x7FFF;

    // O-Level test-BIT 1
    if(ui->cb_stn10_o_level->isChecked())
        freq_cmd_stn10[4]= freq_cmd_stn10[4]|0x4000;
    else
        freq_cmd_stn10[4]= freq_cmd_stn10[4]&0xBFFF;
    // for OLEVEL AND IBIT CMD


}




void MainWindow::updategui()
{
    /////change by unical on 28 jan///////////////////
    //Discrete Target Data DSTD1 Message
    ui->lE_tGTID->setText     (QString::number(dstd1[0]));
    ui->lE_eG->setText        (QString::number(proc_1553_15sgnf(dstd1[1],  0.0054931640625)));
    ui->lE_eV->setText        (QString::number(proc_1553_15sgnf(dstd1[2],  0.0054931640625)));
    ui->lE_dI->setText        (QString::number(proc_1553_15sgnf(dstd1[4],  0.0078125)));
    ui->lE_d->setText         (QString::number(proc_1553_15sgnf(dstd1[5],  0.015625)));
    ui->lE_dT->setText        (QString::number(proc_1553_15sgnf(dstd1[6],  0.000244140625)));
    ui->lE_hE->setText        (QString::number(proc_1553_15sgnf(dstd1[7],  0.0078125)));
    ui->lE_vC->setText        (QString::number(proc_1553_15sgnf(dstd1[15], 0.000244140625)));
    ui->lE_qG->setText        (QString::number(proc_1553_15sgnf(dstd1[19], 0.0054931640625)));
    ui->lE_vXA->setText       (QString::number(proc_1553_15sgnf(dstd1[21], 0.000244140625)));
    ui->lE_vYA->setText       (QString::number(proc_1553_15sgnf(dstd1[22], 0.000244140625)));
    ui->lE_vZA->setText       (QString::number(proc_1553_15sgnf(dstd1[23], 0.000244140625)));

    //Discrete Target Data DSTD2 Message
    ui->lE_tGTID_2->setText   (QString::number(dstd2[0]));
    ui->lE_eG_2->setText      (QString::number(proc_1553_15sgnf(dstd2[1],  0.0054931640625)));
    ui->lE_eV_2->setText      (QString::number(proc_1553_15sgnf(dstd2[2],  0.0054931640625)));
    ui->lE_dI_2->setText      (QString::number(proc_1553_15sgnf(dstd2[4],  0.0078125)));
    ui->lE_d_2->setText       (QString::number(proc_1553_15sgnf(dstd2[5],  0.015625)));
    ui->lE_dT_2->setText      (QString::number(proc_1553_15sgnf(dstd2[6],  0.000244140625)));
    ui->lE_hE_2->setText      (QString::number(proc_1553_15sgnf(dstd2[7],  0.0078125)));
    ui->lE_vC_2->setText      (QString::number(proc_1553_15sgnf(dstd2[15], 0.000244140625)));
    ui->lE_qG_2->setText      (QString::number(proc_1553_15sgnf(dstd2[19], 0.0054931640625)));
    ui->lE_vXA_2->setText     (QString::number(proc_1553_15sgnf(dstd2[21], 0.000244140625)));
    ui->lE_vYA_2->setText     (QString::number(proc_1553_15sgnf(dstd2[22], 0.000244140625)));
    ui->lE_vZA_2->setText     (QString::number(proc_1553_15sgnf(dstd2[23], 0.000244140625)));
    //Discrete Target Data DSTD3 Message
    ui->lE_tGTID_3->setText   (QString::number(dstd3[0]));
    ui->lE_eG_3->setText      (QString::number(proc_1553_15sgnf(dstd3[1],  0.0054931640625)));
    ui->lE_eV_3->setText      (QString::number(proc_1553_15sgnf(dstd3[2],  0.0054931640625)));
    ui->lE_dI_3->setText      (QString::number(proc_1553_15sgnf(dstd3[4],  0.0078125)));
    ui->lE_d_3->setText       (QString::number(proc_1553_15sgnf(dstd3[5],  0.015625)));
    ui->lE_dT_3->setText      (QString::number(proc_1553_15sgnf(dstd3[6],  0.000244140625)));
    ui->lE_hE_3->setText      (QString::number(proc_1553_15sgnf(dstd3[7],  0.0078125)));
    ui->lE_vC_3->setText      (QString::number(proc_1553_15sgnf(dstd3[15], 0.000244140625)));
    ui->lE_qG_3->setText      (QString::number(proc_1553_15sgnf(dstd3[19], 0.0054931640625)));
    ui->lE_vXA_3->setText     (QString::number(proc_1553_15sgnf(dstd3[21], 0.000244140625)));
    ui->lE_vYA_3->setText     (QString::number(proc_1553_15sgnf(dstd3[22], 0.000244140625)));
    ui->lE_vZA_3->setText     (QString::number(proc_1553_15sgnf(dstd3[23], 0.000244140625)));
    //Discrete Target Data DSTD4 Message
    ui->lE_tGTID_4->setText   (QString::number(dstd4[0]));
    ui->lE_eG_4->setText      (QString::number(proc_1553_15sgnf(dstd4[1],  0.0054931640625)));
    ui->lE_eV_4->setText      (QString::number(proc_1553_15sgnf(dstd4[2],  0.0054931640625)));
    ui->lE_dI_4->setText      (QString::number(proc_1553_15sgnf(dstd4[4],  0.0078125)));
    ui->lE_d_4->setText       (QString::number(proc_1553_15sgnf(dstd4[5],  0.015625)));
    ui->lE_dT_4->setText      (QString::number(proc_1553_15sgnf(dstd4[6],  0.000244140625)));
    ui->lE_hE_4->setText      (QString::number(proc_1553_15sgnf(dstd4[7],  0.0078125)));
    ui->lE_vC_4->setText      (QString::number(proc_1553_15sgnf(dstd4[15], 0.000244140625)));
    ui->lE_qG_4->setText      (QString::number(proc_1553_15sgnf(dstd4[19], 0.0054931640625)));
    ui->lE_vXA_4->setText     (QString::number(proc_1553_15sgnf(dstd4[21], 0.000244140625)));
    ui->lE_vYA_4->setText     (QString::number(proc_1553_15sgnf(dstd4[22], 0.000244140625)));
    ui->lE_vZA_4->setText     (QString::number(proc_1553_15sgnf(dstd4[23], 0.000244140625)));
    //Lock On Target Message(LOTD)

    ui->lE_tGTID_LOTD->setText(QString::number(lotd[0]));
    ui->lE_eG_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[1],  0.0054931640625)));
    ui->lE_eV_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[2],  0.0054931640625)));
    ui->lE_dI_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[4],  0.0078125)));
    ui->lE_d_LOTD->setText    (QString::number(proc_1553_15sgnf(lotd[5],  0.0078125)));
    ui->lE_dT_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[6],  0.000244140625)));
    ui->lE_vC_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[13], 0.000244140625)));
    ui->lE_qG_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[17], 0.0054931640625)));
    ui->lE_Tteks_LOTD->setText(QString::number(lotd[19]));
    ui->lE_vZA_LOTD->setText  (QString::number(proc_1553_15sgnf(lotd[20], 0.000244140625)));
    ui->lE_He_LOTD->setText   (QString::number(proc_1553_15sgnf(lotd[25], 0.0078125)));
    ui->lE_vXA_LOTD->setText  (QString::number(proc_1553_15sgnf(lotd[30], 0.000244140625)));
    ui->lE_vYA_LOTD->setText  (QString::number(proc_1553_15sgnf(lotd[31], 0.000244140625)));

    /////change by unical on 28 jan///////////////////

    //NKS
    //ui->cb_stn7_available->setChecked(gb_umbilical_sts7);
    //ui->cb_stn8_available->setChecked(gb_umbilical_sts8);
    //ui->cb_stn9_available->setChecked(gb_umbilical_sts9);
    //ui->cb_stn10_available->setChecked(gb_umbilical_sts10);
 // changed on 14/5/2020

//    ui->cb_stn7_hp_req->setChecked(mslp_res_data1[1] & 0x0200);
//    ui->cb_stn8_hp_req->setChecked(mslp_res_data2[1] & 0x0200);
//    ui->cb_stn9_hp_req->setChecked(mslp_res_data3[1] & 0x0200);
//    ui->cb_stn10_hp_req->setChecked(mslp_res_data4[1] & 0x0200);
}
// **** two comp functions ...***//

unsigned int comp(unsigned short var)
{
    unsigned int twocomp;
    twocomp= ((~var) + 1);
    //   printf("two comp is %x\n",twocomp);
    return twocomp;
}

unsigned short convertodec(unsigned short value )
{
    //  printf("decimal val is %d\n",value);
    return value;
}
/***************Qt_MC FUNCTIONS***************/
void MainWindow::openMCfile()
{

    char mcDummy[512];
    //mc file firstline skipped
    fpIn10msData = fopen(mcFilePath.toUtf8(), "r");

    qDebug()<<mcFilePath;


    fgets(mcDummy,512, fpIn10msData);
}
void MainWindow::startMc()
{

    mcFilePath = ui->mc_file_Ldt->text();
//    qDebug()<<"mc selected file path::"<<mcFilePath;

    if(mcFilePath == "")
    {
        errorPopup->information(this,"Information","Select File");
    }
    else
    {

        openMCfile();
        fileclosecount = 1;
        if(mcFilePath== "")
        {
            errorPopup->information(this,"Information","Select File");
        }
        else
        {
            if(ui->devnum_bc->currentText()=="0")
            {
                DevNumBC =0x0000;
            }
            if(ui->devnum_bc->currentText()=="1")
            {
                DevNumBC =0x0001;
            }
            if(ui->devnum_bc->currentText()=="2")
            {
                DevNumBC =0x0002;
            }
            if(ui->devnum_bc->currentText()=="3")
            {
                DevNumBC =0x0003;
            }
            if(ui->devnum_rt->currentText()=="0")
            {
                DevNumRT =0x0000;
            }
            if(ui->devnum_rt->currentText()=="1")
            {
                DevNumRT =0x0001;
            }
            if(ui->devnum_rt->currentText()=="2")
            {
                DevNumRT =0x0002;
            }
            if(ui->devnum_rt->currentText()=="3")
            {
                DevNumRT =0x0003;
            }

            mc_rtConfig();
            mc_BcConfig();

            if(mc_timer->isActive())
            {
                qDebug()<<"Running Timer..";
            }
            else
            {
                mc_rtthread->start();
                mc_bcthread->start();
                mcCount=0;
                this->mc_timer->start(10);
            }
        }
    }
}
void MainWindow::mc_Timer_Message()
{


    lineCount++;
    if(ui->checkBox->isChecked())
    {
        if(lineCount == ui->line_chk->text().toInt())
        {
            lineCount--;
        }
        else
        {
        //    qDebug()<<"inside getmins";
            getMinsData(fpIn10msData);
        }
    }
    else
    {
        getMinsData(fpIn10msData);
        //qDebug()<<"inside getmins else";
    }
    //  aceBCGetHBufMsgDecoded(DevNumBC,&sMsg,&dwMsgCount,&dwHBufLost,ACE_BC_MSGLOC_NEXT_PURGE);
    aceRTGetHBufMsgDecoded(DevNumRT,&sMsg,&dwMsgCount,&dwMsgLostStk,&dwHBufLost,ACE_RT_MSGLOC_NEXT_PURGE);

        /////sending sync msg every 1 sec


        if(mcCount==100)
        {


         wResult=aceBCAsyncMsgCreateMode(DevNumBC,MSG27,DBLK50,wRTAddress,ACE_TX_CMD,1,0,ACE_BCCTRL_CHL_A, wBuffer); //sync

     //    qDebug()<<"create async msg "<<wResult;

        }




     //   qDebug()<<"mc count"<<mcCount;
            if((mcCount%100)==0)
            {

                qDebug()<<"sync sent";
               wResult= aceBCSendAsyncMsgHP(DevNumBC,MSG27,0);
              //  qDebug()<<"send async"<<wResult;
            }

            ///////






   if(mcCount)
    {
        ScheduleINU_01RtMsg(wBuffer,&sMsg);
        modifyguinu01(wBuffer);
        aceRTDataBlkWrite(DevNumRT,DBLK4,wBuffer,27,0);	// updates RT data Buffer   10ms
        aceBCDataBlkRead(DevNumBC,DBLK1,wBuffer,27,0);
        updateinu01(wBuffer);
    }
    if((mcCount % 2)==0)
    {
        ScheduleINU_02RtMsg(wBuffer);
        modifyguinu02(wBuffer);
        aceRTDataBlkWrite(DevNumRT,DBLK5,wBuffer,20,0);	// updates RT data Buffer   20ms
        aceBCDataBlkRead(DevNumBC,DBLK2,wBuffer,20,0);
        updateinu02(wBuffer);
    }
    if((mcCount % 8)==0)  // updates RT data Buffer  80ms
    {
        if(ui->cb_ta_bias_cmd->isChecked())
        {
            ta_bias=1;
          //  printf ("\n ta_bias in mw.cpp is %d", ta_bias);
        }

        else
            ta_bias=0;
        VN=10;
        /////change by unical on 070119////////
        if(stn1 ==  true)
            for(int i=0; i<=17;i++)
                wBuffer[i]=sg1->Word_MC[i];
        else if(stn2 ==  true)
            for(int i=0; i<=17;i++)
                wBuffer[i]=sg2->Word_MC[i];
        else if(stn3 ==  true)
            for(int i=0; i<=17;i++)
                wBuffer[i]=sg3->Word_MC[i];
        else if(stn4 ==  true)
            for(int i=0; i<=17;i++)
                wBuffer[i]=sg4->Word_MC[i];
        else
            ScheduleINU_03RtMsg(wBuffer,&sMsg);



        wBuffer[0]=time_tag%31245  ;
        time_tag+=1250;

        if((Maneuverb==true)&&(mNrQ==true))

        {
            if((0<=MnurCnt) &&(63>MnurCnt))
                pITCH=pITCH+0.14;
            else if((62<MnurCnt) &&(138>MnurCnt))
                pITCH=pITCH;
            else if((137<MnurCnt) &&(201>MnurCnt))
                pITCH=pITCH-0.14;
            else if((200<MnurCnt) &&(276>MnurCnt))
                pITCH=pITCH;
            else if((275<MnurCnt) &&(339>MnurCnt))
                pITCH=pITCH-0.14;
            else   if((338<MnurCnt) &&(414>MnurCnt))
                pITCH=pITCH;
            else   if((413<MnurCnt) &&(477>MnurCnt))
                pITCH=pITCH+0.14;
            else{
                pITCH=0;
                Maneuverb=false;
            }
            wBuffer[4]=DoubletoBC1(pITCH,0.011, 14);
            wBuffer[5]=DoubletoBC1(pITCH,0.0055, 15);
            MnurCnt++;
        }else{
            ui->cB_mANEUVER->setChecked(false);
            MnurCnt=0;
        }
//                for(int i=0;i<=19;i++)     //22082023
//                        fprintf(file_man,"%5d\t",wBuffer[i]); //22082023
//                fprintf(file_man,"\n");                //22082023
        /////change by unical on 070119////////
        modifyguinu03(wBuffer);
        updateinu03(wBuffer);

        aceRTDataBlkWrite(DevNumRT,DBLK6,wBuffer,20,0);
        // updates RT data Buffer   80ms
        aceBCDataBlkRead(DevNumBC,DBLK3,wBuffer,20,0);
        //        updateinu03(wBuffer);
    }
    mcCount++;
    if((mcCount % 100) == 0 )
    {
        //        qDebug()<<"Time in Sec ::"<<mcCount/100 <<"\n";
        // qDebug()<<"dblk::" <<DBLK6  << wBuffer;
    }
    if(feof(fpIn10msData))
    {
        //        // rewind(fpIn10msData);
        fclose(fpIn10msData);
        openMCfile();
        //  qDebug()<<"MC File Ends .."<<"MCFILE Rewind Count::" << fileclosecount;
        fileclosecount++;
    }

}

void MainWindow::Onbcconfig()
{


    printf("BC Thread started\n");
    wResult = aceInitialize(DevNumBC,ACE_ACCESS_CARD,ACE_MODE_BC,0,0,0);
    if(wResult)
    {
        printf("Initialize ");
        PrintOutError(wResult);
    }
    wResult = aceBCConfigure(DevNumBC,ACE_BC_ASYNC_HMODE);
    if(wResult)
    {
        PrintOutError(wResult);
    }
    // Create 4 data blocks
    aceBCDataBlkCreate(DevNumBC,DBLK1,32,wBuffer,27);
    aceBCDataBlkCreate(DevNumBC,DBLK2,32,wBuffer,20);
    aceBCDataBlkCreate(DevNumBC,DBLK3,32,wBuffer,18);
    // Create message block
    aceBCMsgCreateRTtoBC(
                DevNumBC,              	// Device number
                MSG1,                	// Message ID to create
                DBLK1,               	// Message will use this data block
                wRTAddress,             // RT address
                1,                   	// RT subaddress
                27,            		// Word count
                0,                   	// Default message timer
                ACE_BCCTRL_CHL_A);   	// use chl A options

    aceBCMsgCreateRTtoBC(DevNumBC,MSG2,DBLK2,wRTAddress,2,20,0,ACE_BCCTRL_CHL_A);
    aceBCMsgCreateRTtoBC(DevNumBC,MSG3,DBLK3,wRTAddress,3,18,0,ACE_BCCTRL_CHL_A);

    // Create XEQ opcode that will use msg block
    aceBCOpCodeCreate(DevNumBC,OP_MSG1,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG1,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MSG2,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG2,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MSG3,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG3,0,0);

    // Create CAL opcode that will call mnr frame from major
    aceBCOpCodeCreate(DevNumBC,OP_MNR1,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR1,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR2,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR2,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR3,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR3,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR4,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR4,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR5,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR5,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR6,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR6,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR7,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR7,0,0);
    aceBCOpCodeCreate(DevNumBC,OP_MNR8,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR8,0,0);

    // Create Minor Frame
    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG3;
    aceBCFrameCreate(DevNumBC,MNR1,ACE_FRAME_MINOR,aOpCodes,2,0,0); // mnr frm 1 = msg1, msg3

    // Create Minor Frame
    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR2,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 2 = msg1, msg4

    // Create Minor Frame
    aOpCodes[0] = OP_MSG1;
    aceBCFrameCreate(DevNumBC,MNR3,ACE_FRAME_MINOR,aOpCodes,1,0,0); //mnr frm 3 = msg1,

    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR4,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 3 = msg1,msg4

    aOpCodes[0] = OP_MSG1;
    aceBCFrameCreate(DevNumBC,MNR5,ACE_FRAME_MINOR,aOpCodes,1,0,0); //mnr frm 3 = msg1

    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR6,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 3 = msg1,msg4

    aOpCodes[0] = OP_MSG1;
    aceBCFrameCreate(DevNumBC,MNR7,ACE_FRAME_MINOR,aOpCodes,1,0,0); //mnr frm 3 = msg1

    aOpCodes[0] = OP_MSG1;
    aOpCodes[1] = OP_MSG2;
    aceBCFrameCreate(DevNumBC,MNR8,ACE_FRAME_MINOR,aOpCodes,2,0,0); //mnr frm 3 = msg1,msg4

    // Create Major Frame
    aOpCodes[0] = OP_MNR1;		//msg 1,3
    aOpCodes[1] = OP_MNR2;		//msg 1,4
    aOpCodes[2] = OP_MNR3;		//msg 1
    aOpCodes[3] = OP_MNR4;		//msg 1,4
    aOpCodes[4] = OP_MNR5;		//msg 1
    aOpCodes[5] = OP_MNR6;		//msg 1,4
    aOpCodes[6] = OP_MNR7;		//msg 1
    aOpCodes[7] = OP_MNR8;                //msg 1,4
    aceBCFrameCreate(DevNumBC,MJR,ACE_FRAME_MAJOR,aOpCodes,8,100 ,0);

    aceBCInstallHBuf(DevNumBC,(512*ACE_MSGSIZE_BC)*4 *3);   // Create Host Buffer
    //   aceBCInstallHBuf(DevNumBC,32*1024);
    //  nResult = aceSetTimeTagRes (DevNumBC,ACE_TT_64US);

    aceBCStart(DevNumBC,MJR,-1);	// Start BC
}

void MainWindow::Onrtconfig()
{

    printf("RT Thread started\n");
    nResult = aceInitialize(DevNumRT,ACE_ACCESS_CARD,ACE_MODE_RT,0,0,0);
    if(nResult)
    {
        printf("Initialize ");
        PrintOutError(nResult);
    }
    // Legalize msgs received by the RT own address and mode code 17 (Synchronize with Data)
    aceRTMsgLegalityEnable(0,ACE_RT_MODIFY_ALL,ACE_RT_MODIFY_ALL,ACE_RT_MODIFY_ALL, ACE_RT_SA5);
    // Create DBLK3 for RT
    aceRTDataBlkCreate(DevNumRT, DBLK4, ACE_RT_DBLK_SINGLE, wBuffer, 27);
    aceRTDataBlkCreate(DevNumRT, DBLK5, ACE_RT_DBLK_SINGLE, wBuffer, 20);
    aceRTDataBlkCreate(DevNumRT, DBLK6, ACE_RT_DBLK_SINGLE, wBuffer, 18);

    aceRTSetAddress(DevNumRT,wRTAddress); //Set RT [or latch (BU-65565 only)] address

    aceRTDataBlkMapToSA(DevNumRT, DBLK4, 1, ACE_RT_MSGTYPE_TX, 0, TRUE);	// Map data block to given sub-address
    aceRTDataBlkMapToSA(DevNumRT, DBLK5, 2, ACE_RT_MSGTYPE_TX, 0, TRUE);
    aceRTDataBlkMapToSA(DevNumRT, DBLK6, 3, ACE_RT_MSGTYPE_TX, 0, TRUE);

    aceSetTimeTagRes(DevNumRT,ACE_TT_64US);  // sets time tag res
    if(nResult < 0)
    {
        printf("Error in aceSetTimeTagRes() function \n");
        PrintOutError(nResult);
        return;
    }
    aceRTInstallHBuf(DevNumRT,(512*ACE_MSGSIZE_BC)*4 *3); // Create Host Buffer

    // Poll for messages
    aceRTStart(DevNumRT);   // Start RT Device

}

void MainWindow::mc_acestop()
{
    aceFree(DevNumBC);
    aceFree(DevNumRT);
    aceBCStop(DevNumBC);
    aceRTStop(DevNumRT);

}

static void PrintOutError(S16BIT nResult)
{
    aceErrorStr(nResult,buf,80);
    printf("RTL Function Failure-> %s.\n",buf);
    MessageBoxW(NULL,L"RTL Function Failure",L"",0);
}

U16BIT decodeMsg(U32BIT nMsgNum,MSGSTRUCT *pMsg,U16BIT rBuf[])
{
  //  fprintf(TxFile,"\n ");
   // fprintf(TxFile,"\n CmdWrd  %lf\t %04X  \t  %04X \n",pMsg->wTimeTag*64.0,pMsg->wCmdWrd1,pMsg->wCmdWrd2);

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1,&wRT,&wTR1,&wSA,&wWC);
    if(pMsg->wCmdWrd2Flg) 	aceCmdWordParse(pMsg->wCmdWrd2,&wRT,&wTR2,&wSA,&wWC);

    /* Display transmit status words  */
    if((wTR1==1) || (pMsg->wBCCtrlWrd&ACE_BCCTRL_RT_TO_RT))
    {
        //TRANSMIT
        if(pMsg->wStsWrd1Flg)
   //         fprintf(TxFile,"\n            STA1 %04X",pMsg->wStsWrd1);
        for(i=0; i<pMsg->wWordCount; i++)
        {
            if(i==0)
   //             fprintf(TxFile,"\n            DATA ");
            rBuf[i] = pMsg->aDataWrds[i];

    //        fprintf(TxFile,"%04X  ",pMsg->aDataWrds[i]);

            if((i%8)==7)
            {

            }
    //            fprintf(TxFile,"\n                 ");
        }
        retValue = pMsg->wWordCount;

    }

    else if((wTR1==0)  && !(pMsg->wBCCtrlWrd&ACE_BCCTRL_RT_TO_RT))/* Display receive status words */
    {
        //RECEIVE

        if(pMsg->wStsWrd1Flg)
        //    fprintf(RxFile,"\n            STA1 %04X",pMsg->wStsWrd1);

        for(i=0; i<pMsg->wWordCount; i++)
        {
            if(i==0)
       //    fprintf(RxFile,"\n            DATA ");

     //       fprintf(RxFile,"%04X  ",pMsg->aDataWrds[i]);

            if((i%8)==7)
            {}
                //fprintf(RxFile,"\n                 ");
        }
        retValue = 0;
    }
    return retValue;
}

void MainWindow::modifyguinu01(unsigned short dataBuff[])
{
    if(ui->checkBox_navsts1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->nav_sts1->currentText()=="Alignment Mode")
            dataBuff[1]= dataBuff[1] | 0x8000;

        if(ui->nav_sts1->currentText()=="Navigation Mode")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_algsts1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->align_sts1->currentText()=="Not Ready")
            dataBuff[1]= dataBuff[1] | 0x0000;

        if(ui->align_sts1->currentText()=="Ready after stored Heading")
            dataBuff[1]= dataBuff[1] | 0x1000;

        if(ui->align_sts1->currentText()=="Ready after Inserted Heading")
            dataBuff[1]= dataBuff[1] | 0x2000;

        if(ui->align_sts1->currentText()=="Interruptible Gyrocompass")
            dataBuff[1]= dataBuff[1] | 0x3000;

        if(ui->align_sts1->currentText()=="Ready after Gyrocompass")
            dataBuff[1]= dataBuff[1] | 0x4000;

        if(ui->align_sts1->currentText()=="Ready after In-flight restart")
            dataBuff[1]= dataBuff[1] | 0x5000;

        if(ui->align_sts1->currentText()=="Invalid Alignment coord.")
            dataBuff[1]= dataBuff[1] | 0x6000;
    }
    if(ui->checkBox_teststs1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->test_sts1->currentText()=="Test Mode")
            dataBuff[1]= dataBuff[1] | 0x0800;

        if(ui->test_sts1->currentText()=="Normal Mode")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_selectsat1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->select_sat1->currentText()=="Satellite Hybridization Prohibit")
            dataBuff[1]= dataBuff[1] | 0x0000;

        if(ui->select_sat1->currentText()=="GPS Only")
            dataBuff[1]= dataBuff[1] | 0x0200;

        if(ui->select_sat1->currentText()=="GLONASS Only")
            dataBuff[1]= dataBuff[1] | 0x0400;

        if(ui->select_sat1->currentText()=="GPS and GLONASS")
            dataBuff[1]= dataBuff[1] | 0x0600;
    }
    if(ui->checkBox_satsts1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_sts1->currentText()=="Searching")
            dataBuff[1]= dataBuff[1] | 0x0100;

        if(ui->sat_sts1->currentText()=="Satellite Data Available")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_runsys1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->run_sat_sys1->currentText()=="Satellite Hybridization Disable")
            dataBuff[1]= dataBuff[1] | 0x0000;

        if(ui->run_sat_sys1->currentText()=="GPS only")
            dataBuff[1]= dataBuff[1] | 0x0040;

        if(ui->run_sat_sys1->currentText()=="GLONASS only")
            dataBuff[1]= dataBuff[1] | 0x0080;

        if(ui->run_sat_sys1->currentText()=="GPS and GLONASS")
            dataBuff[1]= dataBuff[1] | 0x00c0;
    }
    if(ui->checkBox_sigma1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sigma1->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0020;

        if(ui->sigma1->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_iner_blk1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->inertial_blk1->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0010;

        if(ui->inertial_blk1->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_gps_glonass1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->gps_glonass1->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0008;

        if(ui->gps_glonass1->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_analog_discrete1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->analog_discrete_op1->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0004;

        if(ui->analog_discrete_op1->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_gost_op1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->gost_op1->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0002;

        if(ui->gost_op1->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_computer1->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->computer1->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0001;

        if(ui->computer1->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_acc->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->acceleration->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x8000;

        if(ui->acceleration->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_alt_rate->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->alt_body_rate->currentText()=="Valid")
            dataBuff[22]= 65;//4dataBuff[2] | 0x4000;

        if(ui->alt_body_rate->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_pitch_rol->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->pitch_roll->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x2000;

        if(ui->pitch_roll->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_true_head->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->true_head->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x1000;

        if(ui->true_head->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_mag_head->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->Magnetic_head->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0800;

        if(ui->Magnetic_head->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_mag_dev->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->magnetic_dev->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0400;

        if(ui->magnetic_dev->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_inertial_speed->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->inertial_speed->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0200;

        if(ui->inertial_speed->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_inertial_horz->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->inertial_horz_coord->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0100;

        if(ui->inertial_horz_coord->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_baro_alt->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->baro_inertial_alt->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0080;

        if(ui->baro_inertial_alt->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_pwr_ontme->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->pwr_on_time->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0040;

        if(ui->pwr_on_time->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_instalchk->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->instal_chksum->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0020;

        if(ui->instal_chksum->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_tt->isChecked())
    {
        dataBuff[0]=0x0000;
        ttag = ui->time_tag1->text().toDouble();
        dataBuff[0]=DoubletoBNR1(ttag,0.064);
    }
    if(ui->checkBox_gamax->isChecked())
    {
        dataBuff[3]=0x0000;
        GAMAX= ui->gamax->text().toDouble();
        dataBuff[3]=DoubletoBC1(GAMAX, 0.0039, 15);
    }
    if(ui->checkBox_gamaz->isChecked())
    {
        dataBuff[4]=0x0000;
        GAMAZ= ui->gamaz->text().toDouble();
        dataBuff[4]=DoubletoBC1(GAMAZ, 0.0039, 15);
    }
    if(ui->checkBox_gamay->isChecked())
    {
        dataBuff[5]=0x0000;
        GAMAY= ui->gamay->text().toDouble();
        dataBuff[5]=DoubletoBC1(GAMAY, 0.0039, 15);
    }
    if(ui->checkBox_omegax->isChecked())
    {
        dataBuff[6]=0x0000;
        OMEGAX= ui->omegax->text().toDouble();
        dataBuff[6] = DoubletoBC1(OMEGAX, 0.01562, 15);
    }
    if(ui->checkBox_omegaz->isChecked())
    {
        dataBuff[7]=0x0000;
        OMEGAZ= ui->omegaz->text().toDouble();
        dataBuff[7] = DoubletoBC1(OMEGAZ, 0.01562, 15);
    }
    if(ui->checkBox_omegay->isChecked())
    {
        dataBuff[8]=0x0000;
        OMEGAY= ui->omegay->text().toDouble();
        dataBuff[8] = DoubletoBC1(OMEGAY, 0.01562, 15);
    }
    if(ui->checkBox_rol_ins->isChecked())
    {
        dataBuff[9]=0x0000;
        ROLL_INS= ui->roll_ins->text().toDouble();
        dataBuff[9] = DoubletoBC1(ROLL_INS, 0.011, 14);
    }
    if(ui->checkBox_pitch_ins->isChecked())
    {
        dataBuff[10]=0x0000;
        PITCH_INS= ui->pitch_ins->text().toDouble();
        dataBuff[10] = DoubletoBC1(PITCH_INS, 0.011, 14);
    }
    if(ui->checkBox_thead_ins->isChecked())
    {
        dataBuff[11]=0x0000;
        THEAD_INS= ui->thead_ins->text().toDouble();
        dataBuff[11] = DoubletoBC1(THEAD_INS, 0.055, 15);
    }
    if(ui->checkBox_vn_ins->isChecked())
    {
        dataBuff[12]=0x0000;
        dataBuff[13]=0x0000;
        VN_INS= ui->vn_ins->text().toDouble();
        bc2VnIns = DoubletoBC2(VN_INS, 0.0032, 19);
        dataBuff[12] = (bc2VnIns >> 16) & 0x0000FFFF;
        dataBuff[13] = bc2VnIns & 0x0000FFFF;
    }
    if(ui->checkBox_ve_ins->isChecked())
    {
        dataBuff[14]=0x0000;
        dataBuff[15]=0x0000;
        VE_INS= ui->ve_ins->text().toDouble();
        bc2VeIns = DoubletoBC2(VE_INS, 0.0032, 19);
        dataBuff[14] = (bc2VeIns >> 16) & 0x0000FFFF;
        dataBuff[15] = bc2VeIns & 0x0000FFFF;
    }
    if(ui->checkBox_vup_ins->isChecked())
    {
        dataBuff[16]=0x0000;
        dataBuff[17]=0x0000;
        Vup_INS= ui->vup_ins->text().toDouble();
        bc2VupIns = DoubletoBC2(Vup_INS, 0.0032, 19);
        dataBuff[16] = (bc2VupIns >> 16) & 0x0000FFFF;
        dataBuff[17] = bc2VupIns & 0x0000FFFF;
    }
    if(ui->checkBox_lat_ins->isChecked())
    {
        dataBuff[18]=0x0000;
        dataBuff[19]=0x0000;
        LAT_INS= ui->lat_ins->text().toDouble();
        bc2LatIns = DoubletoBC2(LAT_INS, 90/pow(2.0,27), 28);
        dataBuff[18] = (bc2LatIns >> 16) & 0x0000FFFF;
        dataBuff[19] = bc2LatIns & 0x0000FFFF;
    }
    if(ui->checkBox_lon_ins->isChecked())
    {
        dataBuff[20]=0x0000;
        dataBuff[21]=0x0000;
        LON_INS= ui->lon_ins->text().toDouble();
        bc2LonIns = DoubletoBC2(LON_INS, 90/pow(2.0,27), 28);
        dataBuff[20] = (bc2LonIns >> 16) & 0x0000FFFF;
        dataBuff[21] = bc2LonIns & 0x0000FFFF;
    }
    if(ui->checkBox_zbi->isChecked())
    {
        dataBuff[22]=0x0000;
        ZBI= ui->zbi->text().toDouble();
        dataBuff[22] = DoubletoBC1(ZBI, 1.0, 15);
    }

    /********ZB CHECK 30  *******/
    if(ui->lat_time_chkl->isChecked())
    {
        dataBuff[22]=0x0000;
        ZBI= 30;
        dataBuff[22] = DoubletoBC1(ZBI, 1.0, 15);
    }
    if(ui->checkBox_mhead_ins->isChecked())
    {
        dataBuff[23]=0x0000;
        MHEAD_INS= ui->mhead_ins->text().toDouble();
        dataBuff[23] = DoubletoBC1(MHEAD_INS, 0.0055, 15);
    }
    if(ui->checkBox_magn_dev->isChecked())
    {
        dataBuff[24]=0x0000;
        MAGN_DEV = ui->magn_dev->text().toDouble();
        dataBuff[24] = DoubletoBC1(MAGN_DEV, 0.0055, 15);
    }
    if(ui->checkBox_pwr_time->isChecked())
    {
        dataBuff[25]=0x0000;
        PWR_TIME = ui->pwr_time->text().toDouble();
        dataBuff[25] = DoubletoBNR1(PWR_TIME, 1.0);
    }
    if(ui->checkBox_chk_instal->isChecked())
    {
        dataBuff[26]=0x0000;
        CHK_INSTAL = ui->chk_install->text().toUInt();
        dataBuff[26] = CHK_INSTAL;
    }
}

void MainWindow::updateinu01(unsigned short dataBuff[32])
{
    TIME_TAG=BNR1toDouble(dataBuff[0], 0.064);
    mc_str = QString ( "%1" ).arg(TIME_TAG, 0, 'f',4 );
    ui->time_tag1->setText(mc_str);

    nav_sts1= ((dataBuff[1]) ) & 0x8000;
    if(nav_sts1==0x8000)
    {
        ui->nav_sts_1->clear();
        ui->nav_sts_1->setText("Alignment Mode");
    }
    else
    {
        ui->nav_sts_1->clear();
        ui->nav_sts_1->setText("Navigation Mode");
    }

    align_sts1=(dataBuff[1] & 0x7000);
    if(align_sts1==0x0000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Not Ready");
    }
    if(align_sts1==0x1000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Ready after stored Heading");
    }
    if(align_sts1==0x2000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Ready after Inserted Heading");
    }
    if(align_sts1==0x3000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Interruptible Gyrocompass");
    }
    if(align_sts1==0x4000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Ready after Gyrocompass");
    }
    if(align_sts1==0x5000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Ready after In-flight restart");
    }
    if(align_sts1==0x6000)
    {
        ui->align_sts_1->clear();
        ui->align_sts_1->setText("Invalid Alignment coord.");
    }

    test_sts1= (dataBuff[1] & 0x0800);
    if(test_sts1==0x0800)
    {
        ui->test_sts_1->clear();
        ui->test_sts_1->setText("Test Mode");
    }
    else
    {
        ui->test_sts_1->clear();
        ui->test_sts_1->setText("Normal Mode");
    }

    select_sat1=(dataBuff[1] & 0x0600);
    if(select_sat1==0x0000)
    {
        ui->select_sat_1->clear();
        ui->select_sat_1->setText("Satellite Hybridization Prohibit");
    }
    if(select_sat1==0x0200)
    {
        ui->select_sat_1->clear();
        ui->select_sat_1->setText("GPS Only");
    }
    if(select_sat1==0x0400)
    {
        ui->select_sat_1->clear();
        ui->select_sat_1->setText("GLONASS Only");
    }
    if(select_sat1==0x0600)
    {
        ui->select_sat_1->clear();
        ui->select_sat_1->setText("GPS and GLONASS");
    }

    sat_sts1=(dataBuff[1] & 0x0100);
    if(sat_sts1==0x0100)
    {
        ui->sat_sts_1->clear();
        ui->sat_sts_1->setText("Searching");
    }
    else
    {
        ui->sat_sts_1->clear();
        ui->sat_sts_1->setText("Satellite Data Available");
    }

    run_sat_sys1=(dataBuff[1] & 0x00c0);
    if(run_sat_sys1==0x0000)
    {
        ui->run_sat_sys_1->clear();
        ui->run_sat_sys_1->setText("Satellite Hybridization Disable");
    }
    if(run_sat_sys1==0x0040)
    {
        ui->run_sat_sys_1->clear();
        ui->run_sat_sys_1->setText("GPS only");
    }
    if(run_sat_sys1==0x0080)
    {
        ui->run_sat_sys_1->clear();
        ui->run_sat_sys_1->setText("GLONASS only");
    }
    if(run_sat_sys1==0x00c0)
    {
        ui->run_sat_sys_1->clear();
        ui->run_sat_sys_1->setText("GPS and GLONASS");
    }

    sigma1=(dataBuff[1] & 0x0020);
    if(sigma1==0x0020)
    {
        ui->sigma_1->clear();
        ui->sigma_1->setText("FAIL");
    }
    else
    {
        ui->sigma_1->clear();
        ui->sigma_1->setText("PASS");
    }

    inertial_blk1=(dataBuff[1] & 0x0010);
    if(inertial_blk1==0x0010)
    {
        ui->inertial_blk_1->clear();
        ui->inertial_blk_1->setText("FAIL");
    }
    else
    {
        ui->inertial_blk_1->clear();
        ui->inertial_blk_1->setText("PASS");
    }

    gps_glonass1=(dataBuff[1] & 0x0008);
    if(gps_glonass1==0x0008)
    {
        ui->gps_glonass_1->clear();
        ui->gps_glonass_1->setText("FAIL");
    }
    else
    {
        ui->gps_glonass_1->clear();
        ui->gps_glonass_1->setText("PASS");
    }

    analog_discrete1=(dataBuff[1] & 0x0004);
    if(analog_discrete1==0x0004)
    {
        ui->analog_discrete_op_1->clear();
        ui->analog_discrete_op_1->setText("FAIL");
    }
    else
    {
        ui->analog_discrete_op_1->clear();
        ui->analog_discrete_op_1->setText("PASS");
    }

    gost_op1=(dataBuff[1] & 0x0002);
    if(gost_op1==0x0002)
    {
        ui->gost_op_1->clear();
        ui->gost_op_1->setText("FAIL");
    }
    else
    {
        ui->gost_op_1->clear();
        ui->gost_op_1->setText("PASS");
    }

    computer1=(dataBuff[1] & 0x0001);
    if(computer1==0x0001)
    {
        ui->computer_1->clear();
        ui->computer_1->setText("FAIL");
    }
    else
    {
        ui->computer_1->clear();
        ui->computer_1->setText("PASS");
    }

    acceleration_1=(dataBuff[2] & 0x8000);
    if(acceleration_1==0x8000)
    {
        ui->acceleration1->clear();
        ui->acceleration1->setText("Valid");
    }
    else
    {
        ui->acceleration1->clear();
        ui->acceleration1->setText("Invalid");
    }

    alt_body_rate1=(dataBuff[2] & 0x4000);
    if(alt_body_rate1==0x4000)
    {
        ui->alt_body_rate1->clear();
        ui->alt_body_rate1->setText("Valid");
    }
    else
    {
        ui->alt_body_rate1->clear();
        ui->alt_body_rate1->setText("Invalid");
    }

    pitch_roll1=(dataBuff[2] & 0x2000);
    if(pitch_roll1==0x2000)
    {
        ui->pitch_roll1->clear();
        ui->pitch_roll1->setText("Valid");
    }
    else
    {
        ui->pitch_roll1->clear();
        ui->pitch_roll1->setText("Invalid");
    }

    true_head1=(dataBuff[2] & 0x1000);
    if(true_head1==0x1000)
    {
        ui->true_head1->clear();
        ui->true_head1->setText("Valid");
    }
    else
    {
        ui->true_head1->clear();
        ui->true_head1->setText("Invalid");
    }

    magnetic_head1=(dataBuff[2] & 0x0800);
    if(magnetic_head1==0x0800)
    {
        ui->magnetic_head1->clear();
        ui->magnetic_head1->setText("Valid");
    }
    else
    {
        ui->magnetic_head1->clear();
        ui->magnetic_head1->setText("Invalid");
    }

    magnetic_dev1=(dataBuff[2] & 0x0400);
    if(magnetic_dev1==0x0400)
    {
        ui->magnetic_dev1->clear();
        ui->magnetic_dev1->setText("Valid");
    }
    else
    {
        ui->magnetic_dev1->clear();
        ui->magnetic_dev1->setText("Invalid");
    }

    inertial_speed1=(dataBuff[2] & 0x0200);
    if(inertial_speed1==0x0200)
    {
        ui->inertial_speed1->clear();
        ui->inertial_speed1->setText("Valid");
    }
    else
    {
        ui->inertial_speed1->clear();
        ui->inertial_speed1->setText("Invalid");
    }

    inertial_horiz_coord1=(dataBuff[2] & 0x0100);
    if(inertial_horiz_coord1==0x0100)
    {
        ui->inertial_horiz_coord1->clear();
        ui->inertial_horiz_coord1->setText("Valid");
    }
    else
    {
        ui->inertial_horiz_coord1->clear();
        ui->inertial_horiz_coord1->setText("Invalid");
    }

    baro_inertial_alt1=(dataBuff[2] & 0x0080);
    if(baro_inertial_alt1==0x0080)
    {
        ui->baro_inertial_alt1->clear();
        ui->baro_inertial_alt1->setText("Valid");
    }
    else
    {
        ui->baro_inertial_alt1->clear();
        ui->baro_inertial_alt1->setText("Invalid");
    }

    pwr_on_time1=(dataBuff[2] & 0x0040);
    if(pwr_on_time1==0x0040)
    {
        ui->pwr_on_time1->clear();
        ui->pwr_on_time1->setText("Valid");
    }
    else
    {
        ui->pwr_on_time1->clear();
        ui->pwr_on_time1->setText("Invalid");
    }

    instal_chksum1=(dataBuff[2] & 0x0020);
    if(instal_chksum1==0x0020)
    {
        ui->instal_chksum1->clear();
        ui->instal_chksum1->setText("Valid");
    }
    else
    {
        ui->instal_chksum1->clear();
        ui->instal_chksum1->setText("Invalid");
    }

    GAMAX=BC1toDouble(dataBuff[3], 0.0039, 15);;
    mc_str = QString ( "%1" ).arg(GAMAX, 0, 'f',4 );
    ui->gamax->setText(mc_str);

    GAMAY=BC1toDouble(dataBuff[5], 0.0039, 15);
    mc_str = QString ( "%1" ).arg(GAMAY, 0, 'f',4 );
    ui->gamay->setText(mc_str);

    GAMAZ=BC1toDouble(dataBuff[4], 0.0039, 15);
    mc_str = QString ( "%1" ).arg(GAMAZ, 0, 'f',4 );
    ui->gamaz->setText(mc_str);

    OMEGAX=BC1toDouble(dataBuff[6], 0.01562, 15);
    mc_str = QString ( "%1" ).arg(OMEGAX, 0, 'f',4 );
    ui->omegax->setText(str);

    OMEGAY=BC1toDouble(dataBuff[8], 0.01562, 15);
    str = QString ( "%1" ).arg(OMEGAY, 0, 'f',4 );
    ui->omegay->setText(mc_str);

    OMEGAZ=BC1toDouble(dataBuff[7], 0.01562, 15);
    mc_str = QString ( "%1" ).arg(OMEGAZ, 0, 'f',4 );
    ui->omegaz->setText(mc_str);

    ROLL_INS=BC1toDouble(dataBuff[9], 0.011, 14);
    mc_str = QString ( "%1" ).arg(ROLL_INS, 0, 'f',4 );
    ui->roll_ins->setText(mc_str);

    PITCH_INS=BC1toDouble(dataBuff[10], 0.011, 14);
    mc_str = QString ( "%1" ).arg(PITCH_INS, 0, 'f',4 );
    ui->pitch_ins->setText(mc_str);

    CHK_INSTAL=dataBuff[26];
    itoa(CHK_INSTAL,s,16);
    mc_str=s;
    ui->chk_install->setText(mc_str);

    PWR_TIME=BNR1toDouble(dataBuff[25], 1.0);
    mc_str = QString ( "%1" ).arg(PWR_TIME, 0, 'f',4 );
    ui->pwr_time->setText(mc_str);

    THEAD_INS=BC1toDouble(dataBuff[11], 0.055, 15);
    mc_str = QString ( "%1" ).arg(THEAD_INS, 0, 'f',4 );
    ui->thead_ins->setText(mc_str);

    MAGN_DEV=BC1toDouble(dataBuff[24], 0.0055, 15);
    mc_str = QString ( "%1" ).arg(MAGN_DEV, 0, 'f',4 );
    ui->magn_dev->setText(mc_str);

    bc2Vn = dataBuff[12];
    bc2Vn = ((bc2Vn & 0x0000FFFF) << 16) | dataBuff[13];
    VN_INS=BC2toDouble(bc2Vn,0.0032, 19);
    mc_str = QString ( "%1" ).arg(VN_INS, 0, 'f',4 );
    ui->vn_ins->setText(mc_str);

    bc2Ve = dataBuff[14];
    bc2Ve = ((bc2Ve & 0x0000FFFF) << 16) | dataBuff[15];
    VE_INS=BC2toDouble(bc2Ve,0.0032, 19);
    mc_str = QString ( "%1" ).arg(VE_INS, 0, 'f',4 );
    ui->ve_ins->setText(mc_str);

    bc2Vup = dataBuff[16];
    bc2Vup = ((bc2Vup & 0x0000FFFF) << 16) | dataBuff[17];
    Vup_INS=BC2toDouble(bc2Vup,0.0032, 19);
    mc_str = QString ( "%1" ).arg(Vup_INS, 0, 'f',4 );
    ui->vup_ins->setText(mc_str);

    bc2Lat = dataBuff[18];
    bc2Lat = ((bc2Lat & 0x0000FFFF) << 16) | dataBuff[19];
    LAT_INS= BC2toDouble(bc2Lat, 90/pow(2.0,27), 28);
    mc_str = QString ( "%1" ).arg(LAT_INS, 0, 'f',4 );
    ui->lat_ins->setText(mc_str);

    bc2Lon = dataBuff[20];
    bc2Lon = ((bc2Lon & 0x0000FFFF) << 16) | dataBuff[21];
    LON_INS=BC2toDouble(bc2Lon, 90/pow(2.0,27), 28);
    str = QString ( "%1" ).arg(LON_INS, 0, 'f',4 );
    ui->lon_ins->setText(str);

    ZBI=BC1toDouble(dataBuff[22], 1.0, 15);
    mc_str = QString ( "%1" ).arg(ZBI, 0, 'f',4 );
    ui->zbi->setText(mc_str);

    MHEAD_INS=BC1toDouble(dataBuff[23],0.0055, 15);
    mc_str = QString ( "%1" ).arg(MHEAD_INS, 0, 'f',4 );
    ui->mhead_ins->setText(mc_str);
}

void MainWindow::modifyguinu02(unsigned short dataBuff[])
{
    if(ui->checkBox_navsts2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->nav_sts1_2->currentText()=="Alignment Mode")
            dataBuff[0]= dataBuff[0] | 0x8000;

        if(ui->nav_sts1_2->currentText()=="Navigation Mode")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_algsts2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->align_sts1_2->currentText()=="Not Ready")
            dataBuff[0]= dataBuff[0] | 0x0000;

        if(ui->align_sts1_2->currentText()=="Ready after stored Heading")
            dataBuff[0]= dataBuff[0] | 0x1000;

        if(ui->align_sts1_2->currentText()=="Ready after Inserted Heading")
            dataBuff[0]= dataBuff[0] | 0x2000;

        if(ui->align_sts1_2->currentText()=="Interruptible Gyrocompass")
            dataBuff[0]= dataBuff[0] | 0x3000;

        if(ui->align_sts1_2->currentText()=="Ready after Gyrocompass")
            dataBuff[0]= dataBuff[0] | 0x4000;

        if(ui->align_sts1_2->currentText()=="Ready after In-flight restart")
            dataBuff[0]= dataBuff[0] | 0x5000;

        if(ui->align_sts1_2->currentText()=="Invalid Alignment coord.")
            dataBuff[0]= dataBuff[0] | 0x6000;
    }
    if(ui->checkBox_teststs2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->test_sts1_2->currentText()=="Test Mode")
            dataBuff[0]= dataBuff[0] | 0x0800;

        if(ui->test_sts1_2->currentText()=="Normal Mode")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_selectsys2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->select_sat1_2->currentText()=="Satellite Hybridization Prohibit")
            dataBuff[0]= dataBuff[0] | 0x0000;

        if(ui->select_sat1_2->currentText()=="GPS Only")
            dataBuff[0]= dataBuff[0] | 0x0200;

        if(ui->select_sat1_2->currentText()=="GLONASS Only")
            dataBuff[0]= dataBuff[0] | 0x0400;

        if(ui->select_sat1_2->currentText()=="GPS and GLONASS")
            dataBuff[0]= dataBuff[0] | 0x0600;
    }
    if(ui->checkBox_satsts2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->sat_sts1_2->currentText()=="Searching")
            dataBuff[0]= dataBuff[0] | 0x0100;

        if(ui->sat_sts1_2->currentText()=="Satellite Data Available")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_runsys2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->run_sat_sys1_2->currentText()=="Satellite Hybridization Disable")
            dataBuff[0]= dataBuff[0] | 0x0000;

        if(ui->run_sat_sys1_2->currentText()=="GPS only")
            dataBuff[0]= dataBuff[0] | 0x0040;

        if(ui->run_sat_sys1_2->currentText()=="GLONASS only")
            dataBuff[0]= dataBuff[0] | 0x0080;

        if(ui->run_sat_sys1_2->currentText()=="GPS and GLONASS")
            dataBuff[0]= dataBuff[0] | 0x00c0;
    }
    if(ui->checkBox_sigma2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->sigma1_2->currentText()=="FAIL")
            dataBuff[0]= dataBuff[0] | 0x0020;

        if(ui->sigma1_2->currentText()=="PASS")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_ineblk2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->inertial_blk1_2->currentText()=="FAIL")
            dataBuff[0]= dataBuff[0] | 0x0010;

        if(ui->inertial_blk1_2->currentText()=="PASS")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_gps_glonass2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->gps_glonass1_2->currentText()=="FAIL")
            dataBuff[0]= dataBuff[0] | 0x0008;

        if(ui->gps_glonass1_2->currentText()=="PASS")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_analog_discrete2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->analog_discrete_op1_2->currentText()=="FAIL")
            dataBuff[0]= dataBuff[0] | 0x0004;

        if(ui->analog_discrete_op1_2->currentText()=="PASS")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_gostop2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->gost_op1_2->currentText()=="FAIL")
            dataBuff[0]= dataBuff[0] | 0x0002;

        if(ui->gost_op1_2->currentText()=="PASS")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_computer2->isChecked())
    {
        dataBuff[0]=0x0000;
        if(ui->computer1_2->currentText()=="FAIL")
            dataBuff[0]= dataBuff[0] | 0x0001;

        if(ui->computer1_2->currentText()=="PASS")
            dataBuff[0]= dataBuff[0] | 0x0000;
    }
    if(ui->checkBox_satspeed->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_speed->currentText()=="Valid")
            dataBuff[1]= dataBuff[1] | 0x8000;

        if(ui->sat_speed->currentText()=="Invalid")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_sathoriz->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_horiz_coord->currentText()=="Valid")
            dataBuff[1]= dataBuff[1] | 0x4000;

        if(ui->sat_horiz_coord->currentText()=="Invalid")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_satalt->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_alt->currentText()=="Valid")
            dataBuff[1]= dataBuff[1] | 0x2000;

        if(ui->sat_alt->currentText()=="Invalid")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_sattime->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_time->currentText()=="Valid")
            dataBuff[1]= dataBuff[1] | 0x1000;

        if(ui->sat_time->currentText()=="Invalid")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_satdate->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_date->currentText()=="Valid")
            dataBuff[1]= dataBuff[1] | 0x0800;

        if(ui->sat_date->currentText()=="Invalid")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_satsts->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_sts->currentText()=="Valid")
            dataBuff[1]= dataBuff[1] | 0x0400;

        if(ui->sat_sts->currentText()=="Invalid")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
}

void MainWindow::updateinu02(unsigned short dataBuff[32])
{
    nav_sts2= ((dataBuff[1]) ) & 0x8000;
    if(nav_sts2==0x8000)
    {
        ui->nav_sts_2->clear();
        ui->nav_sts_2->setText("Alignment Mode");
    }
    else
    {
        ui->nav_sts_2->clear();
        ui->nav_sts_2->setText("Navigation Mode");
    }

    align_sts2=(dataBuff[1] & 0x7000);
    if(align_sts2==0x0000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Not Ready");
    }
    if(align_sts2==0x1000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Ready after stored Heading");
    }
    if(align_sts2==0x2000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Ready after Inserted Heading");
    }
    if(align_sts2==0x3000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Interruptible Gyrocompass");
    }
    if(align_sts2==0x4000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Ready after Gyrocompass");
    }
    if(align_sts2==0x5000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Ready after In-flight restart");
    }
    if(align_sts2==0x6000)
    {
        ui->align_sts_2->clear();
        ui->align_sts_2->setText("Invalid Alignment coord.");
    }

    test_sts2= (dataBuff[1] & 0x0800);
    if(test_sts2==0x0800)
    {
        ui->test_sts_2->clear();
        ui->test_sts_2->setText("Test Mode");
    }
    else
    {
        ui->test_sts_2->clear();
        ui->test_sts_2->setText("Normal Mode");
    }

    select_sat2=(dataBuff[1] & 0x0600);
    if(select_sat2==0x0000)
    {
        ui->select_sat_2->clear();
        ui->select_sat_2->setText("Satellite Hybridization Prohibit");
    }
    if(select_sat2==0x0200)
    {
        ui->select_sat_2->clear();
        ui->select_sat_2->setText("GPS Only");
    }
    if(select_sat2==0x0400)
    {
        ui->select_sat_2->clear();
        ui->select_sat_2->setText("GLONASS Only");
    }
    if(select_sat2==0x0600)
    {
        ui->select_sat_2->clear();
        ui->select_sat_2->setText("GPS and GLONASS");
    }

    sat_sts2=(dataBuff[1] & 0x0100);
    if(sat_sts2==0x0100)
    {
        ui->sat_sts_2->clear();
        ui->sat_sts_2->setText("Searching");
    }
    else
    {
        ui->sat_sts_2->clear();
        ui->sat_sts_2->setText("Satellite Data Available");
    }

    run_sat_sys2=(dataBuff[1] & 0x00c0);
    if(run_sat_sys2==0x0000)
    {
        ui->run_sat_sys_2->clear();
        ui->run_sat_sys_2->setText("Satellite Hybridization Disable");
    }
    if(run_sat_sys2==0x0040)
    {
        ui->run_sat_sys_2->clear();
        ui->run_sat_sys_2->setText("GPS only");
    }
    if(run_sat_sys2==0x0080)
    {
        ui->run_sat_sys_2->clear();
        ui->run_sat_sys_2->setText("GLONASS only");
    }
    if(run_sat_sys2==0x00c0)
    {
        ui->run_sat_sys_2->clear();
        ui->run_sat_sys_2->setText("GPS and GLONASS");
    }

    sigma2=(dataBuff[1] & 0x0020);
    if(sigma2==0x0100)
    {
        ui->sigma_2->clear();
        ui->sigma_2->setText("FAIL");
    }
    else
    {
        ui->sigma_2->clear();
        ui->sigma_2->setText("PASS");
    }

    inertial_blk2=(dataBuff[1] & 0x0010);
    if(inertial_blk2==0x0100)
    {
        ui->inertial_blk_2->clear();
        ui->inertial_blk_2->setText("FAIL");
    }
    else
    {
        ui->inertial_blk_2->clear();
        ui->inertial_blk_2->setText("PASS");
    }

    gps_glonass2=(dataBuff[1] & 0x0008);
    if(gps_glonass2==0x0100)
    {
        ui->gps_glonass_2->clear();
        ui->gps_glonass_2->setText("FAIL");
    }
    else
    {
        ui->gps_glonass_2->clear();
        ui->gps_glonass_2->setText("PASS");
    }

    analog_discrete2=(dataBuff[1] & 0x0004);
    if(analog_discrete2==0x0100)
    {
        ui->analog_discrete_op_2->clear();
        ui->analog_discrete_op_2->setText("FAIL");
    }
    else
    {
        ui->analog_discrete_op_2->clear();
        ui->analog_discrete_op_2->setText("PASS");
    }

    gost_op2=(dataBuff[1] & 0x0002);
    if(gost_op2==0x0100)
    {
        ui->gost_op_2->clear();
        ui->gost_op_2->setText("FAIL");
    }
    else
    {

        ui->gost_op_2->clear();
        ui->gost_op_2->setText("PASS");
    }

    computer2=(dataBuff[1] & 0x0001);
    if(computer2==0x0100)
    {
        ui->computer_2->clear();
        ui->computer_2->setText("FAIL");
    }
    else
    {
        ui->computer_2->clear();
        ui->computer_2->setText("PASS");
    }

    sat_speed_2=(dataBuff[2] & 0x8000);
    if(sat_speed_2==0x8000)
    {
        ui->sat_speed_2->clear();
        ui->sat_speed_2->setText("Valid");
    }
    else
    {
        ui->sat_speed_2->clear();
        ui->sat_speed_2->setText("Invalid");
    }

    sat_horiz_coord_2=(dataBuff[2] & 0x4000);
    if(sat_horiz_coord_2==0x4000)
    {
        ui->sat_horiz_coord_2->clear();
        ui->sat_horiz_coord_2->setText("Valid");
    }
    else
    {
        ui->sat_horiz_coord_2->clear();
        ui->sat_horiz_coord_2->setText("Invalid");
    }

    sat_alt_2=(dataBuff[2] & 0x2000);
    if(sat_alt_2==0x2000)
    {
        ui->sat_alt_2->clear();
        ui->sat_alt_2->setText("Valid");
    }
    else
    {
        ui->sat_alt_2->clear();
        ui->sat_alt_2->setText("Invalid");
    }

    sat_time_2=(dataBuff[2] & 0x1000);
    if(sat_time_2==0x1000)
    {
        ui->sat_time_2->clear();
        ui->sat_time_2->setText("Valid");
    }
    else
    {
        ui->sat_time_2->clear();
        ui->sat_time_2->setText("Invalid");
    }

    sat_date_2=(dataBuff[2] & 0x0800);
    if(sat_date_2==0x0800)
    {
        ui->sat_date_2->clear();
        ui->sat_date_2->setText("Valid");
    }
    else
    {
        ui->sat_date_2->clear();
        ui->sat_date_2->setText("Invalid");
    }

    sat_sts_2=(dataBuff[2] & 0x0400);
    if(sat_sts_2==0x0400)
    {
        ui->sat_sts2->clear();
        ui->sat_sts2->setText("Valid");
    }
    else
    {
        ui->sat_sts2->clear();
        ui->sat_sts2->setText("Invalid");
    }

    bc2VnSat = dataBuff[2];
    bc2VnSat = ((bc2VnSat & 0x0000FFFF) << 16) | dataBuff[3];
    VN_SAT= BC2toDouble(bc2VnSat,842.865/pow(2.0,18), 19);
    itoa(VN_SAT,s,10);
    mc_str=s;
    ui->vn_sat->setText(mc_str);

    bc2VeSat = dataBuff[4];
    bc2VeSat = ((bc2VeSat & 0x0000FFFF) << 16) | dataBuff[5];
    VE_SAT=BC2toDouble(bc2VeSat,842.865/pow(2.0,18), 19);
    itoa(VE_SAT,s,10);
    mc_str=s;
    ui->ve_sat->setText(mc_str);

    bc2VupSat = dataBuff[6];
    bc2VupSat = ((bc2VupSat & 0x0000FFFF) << 16) | dataBuff[7];
    Vup_SAT= BC2toDouble(bc2VupSat,842.865/pow(2.0,18), 19);
    itoa(Vup_SAT,s,10);
    mc_str=s;
    ui->vup_sat->setText(mc_str);

    bc2LatSat = dataBuff[8];
    bc2LatSat = ((bc2LatSat & 0x0000FFFF) << 16) | dataBuff[9];
    LAT_SAT=BC2toDouble(bc2LatSat,90/pow(2.0,27), 28);
    itoa(LAT_SAT,s,10);
    mc_str=s;
    ui->lat_sat->setText(mc_str);

    bc2LonSat = dataBuff[10];
    bc2LonSat = ((bc2LonSat & 0x0000FFFF) << 16) | dataBuff[11];
    LON_SAT=BC2toDouble(bc2LonSat,90/pow(2.0,27), 28);
    itoa(LON_SAT,s,10);
    mc_str=s;
    ui->lon_sat->setText(mc_str);

    ALT_SAT=BNR1toDouble(dataBuff[12], 1.0);
    itoa(ALT_SAT,s,10);
    mc_str=s;
    ui->alt_sat->setText(mc_str);

    PDOP= BNR1toDouble(dataBuff[18], 0.1);
    itoa(PDOP,s,10);
    mc_str=s;
    ui->pdop->setText(mc_str);

    glonass_sat=(dataBuff[19]>>8) & 0x00ff;
    itoa(glonass_sat,s,10);
    mc_str=s;
    ui->glonass_sat->setText(mc_str);

    gps_sat=dataBuff[19];
    itoa(gps_sat,s,10);
    mc_str=s;
    ui->gps_sat->setText(mc_str);

    TIME_SAT = dataBuff[13];
    TIME_SAT = ((TIME_SAT & 0x0000FFFF) << 16) | dataBuff[14];
    secs = (TIME_SAT >> 10) & 0x003F;
    mins = (TIME_SAT >> 21) & 0X003F;
    hrs = (TIME_SAT >> 27) & 0X001F;

    bc2TimeSat = dataBuff[15];
    bc2TimeSat = ((bc2TimeSat & 0x0000FFFF) << 16) | dataBuff[16];
    TIME_SAT_SEC = BC2toDouble(bc2TimeSat,9.54e-7, 31);
    itoa(TIME_SAT_SEC,s,10);
    mc_str=s;
    ui->time_sat->setText(mc_str);

    //    time_sat=dataBuff[14] & 0xf800;
    //    itoa(time_sat,s,16);
    //    str=s;
    //    ui->time_sat->setText(str);

    //    time_sat1=dataBuff[14] & 0x07e0;
    //    itoa(time_sat1,s,16);
    //    str=s;
    //    ui->time_sat1->setText(str);

    //    time_sat2=dataBuff[15]& 0xfc00;
    //    itoa(time_sat2,s,16);
    //    str=s;
    //    ui->time_sat2->setText(str);

    //    time_sat2=(dataBuff[16]>>16)& 0x00ff;
    //    itoa(time_sat2,s,16);
    //    str=s;
    //    ui->time_sat2->setText(str);

    //    time_sat2=dataBuff[17]& 0xf000;
    //    itoa(time_sat2,s,16);
    //    str=s;
    //    ui->time_sat2->setText(str);

    DATE_SAT = dataBuff[17];
    day = DATE_SAT & 0x001F;
    month = (DATE_SAT >> 5) & 0x000F;
    year = (DATE_SAT >> 9) & 0x007F;
    itoa(day,s,16);
    mc_str=s;
    ui->day->setText(mc_str);
    itoa(month,s,16);
    mc_str=s;
    ui->month->setText(mc_str);
    itoa(year,s,16);
    mc_str=s;
    ui->year->setText(mc_str);
}

void MainWindow::modifyguinu03(unsigned short dataBuff[])
{

    if(ui->checkBox_navsts3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->nav_sts1_3->currentText()=="Alignment Mode")
            dataBuff[1]= dataBuff[1] | 0x8000;

        if(ui->nav_sts1_3->currentText()=="Navigation Mode")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_algsts3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->align_sts1_3->currentText()=="Not Ready")
            dataBuff[1]= dataBuff[1] | 0x0000;

        if(ui->align_sts1_3->currentText()=="Ready after stored Heading")
            dataBuff[1]= dataBuff[1] | 0x1000;

        if(ui->align_sts1_3->currentText()=="Ready after Inserted Heading")
            dataBuff[1]= dataBuff[1] | 0x2000;

        if(ui->align_sts1_3->currentText()=="Interruptible Gyrocompass")
            dataBuff[1]= dataBuff[1] | 0x3000;

        if(ui->align_sts1_3->currentText()=="Ready after Gyrocompass")
            dataBuff[1]= dataBuff[1] | 0x4000;

        if(ui->align_sts1_3->currentText()=="Ready after In-flight restart")
            dataBuff[1]= dataBuff[1] | 0x5000;

        if(ui->align_sts1_3->currentText()=="Invalid Alignment coord.")
            dataBuff[1]= dataBuff[1] | 0x6000;
    }
    if(ui->checkBox_teststs3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->test_sts1_3->currentText()=="Test Mode")
            dataBuff[1]= dataBuff[1] | 0x0800;

        if(ui->test_sts1_3->currentText()=="Normal Mode")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_selectsys3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->select_sat1_3->currentText()=="Satellite Hybridization Prohibit")
            dataBuff[1]= dataBuff[1] | 0x0000;

        if(ui->select_sat1_3->currentText()=="GPS Only")
            dataBuff[1]= dataBuff[1] | 0x0200;

        if(ui->select_sat1_3->currentText()=="GLONASS Only")
            dataBuff[1]= dataBuff[1] | 0x0400;

        if(ui->select_sat1_3->currentText()=="GPS and GLONASS")
            dataBuff[1]= dataBuff[1] | 0x0600;
    }
    if(ui->checkBox_satsts3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sat_sts1_3->currentText()=="Searching")
            dataBuff[1]= dataBuff[1] | 0x0100;

        if(ui->sat_sts1_3->currentText()=="Satellite Data Available")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_runsys3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->run_sat_sys1_3->currentText()=="Satellite Hybridization Disable")
            dataBuff[1]= dataBuff[1] | 0x0000;

        if(ui->run_sat_sys1_3->currentText()=="GPS only")
            dataBuff[1]= dataBuff[1] | 0x0040;

        if(ui->run_sat_sys1_3->currentText()=="GLONASS only")
            dataBuff[1]= dataBuff[1] | 0x0080;

        if(ui->run_sat_sys1_3->currentText()=="GPS and GLONASS")
            dataBuff[1]= dataBuff[1] | 0x00c0;
    }
    if(ui->checkBox_sigma3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->sigma1_3->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0020;

        if(ui->sigma1_3->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_inerblk3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->inertial_blk1_3->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0010;

        if(ui->inertial_blk1_3->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_gps_glonass3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->gps_glonass1_3->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0008;

        if(ui->gps_glonass1_3->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_analog_discrete3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->analog_discrete_op1_3->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0004;

        if(ui->analog_discrete_op1_3->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_gostop3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->gost_op1_3->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0002;

        if(ui->gost_op1_3->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_computer3->isChecked())
    {
        dataBuff[1]=0x0000;
        if(ui->computer1_3->currentText()=="FAIL")
            dataBuff[1]= dataBuff[1] | 0x0001;

        if(ui->computer1_3->currentText()=="PASS")
            dataBuff[1]= dataBuff[1] | 0x0000;
    }
    if(ui->checkBox_pitch_rol3->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->pitch_roll_3->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x8000;

        if(ui->pitch_roll_3->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }

    if(ui->checkBox_true_head3->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->true_head_3->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x4000;

        if(ui->true_head_3->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_mag_head3->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->magnetic_head_3->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x2000;

        if(ui->magnetic_head_3->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_hybrid_speed->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->hybrid_speed->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x1000;

        if(ui->hybrid_speed->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_hybridhoriz->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->hybrid_horiz_coord->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0800;

        if(ui->hybrid_horiz_coord->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_hybrid_alt->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->hybrid_alt->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0400;

        if(ui->hybrid_alt->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_hybrid_poserr->isChecked())
    {
        dataBuff[2]=0x0000;
        if(ui->hybrid_pos_err->currentText()=="Valid")
            dataBuff[2]= dataBuff[2] | 0x0200;

        if(ui->hybrid_pos_err->currentText()=="Invalid")
            dataBuff[2]= dataBuff[2] | 0x0000;
    }
    if(ui->checkBox_tt3->isChecked())
    {
        dataBuff[0]=0x0000;
        ttag3 = ui->time_tag3->text().toDouble();
        dataBuff[0] = DoubletoBNR1(ttag3,0.064);
    }
    if(ui->checkBox_roll->isChecked())
    {
        dataBuff[3]=0x0000;
        ROLL = ui->roll->text().toDouble();
        dataBuff[3] = DoubletoBC1(ROLL,0.011, 14);
        //t  dataBuff[3] = 4;
    }
    if(ui->checkBox_pitch->isChecked())
    {
        dataBuff[4]=0x0000;
        PITCH = ui->pitch->text().toDouble();
        dataBuff[4] = DoubletoBC1(PITCH, 0.011, 14);
    }
    if(ui->checkBox_thead->isChecked())
    {
        dataBuff[5]=0x0000;
        THEAD = ui->thead->text().toDouble();
        dataBuff[5] = DoubletoBC1(THEAD, 0.0055, 15);
    }
    if(ui->checkBox_mhead->isChecked())
    {
        dataBuff[6]=0x0000;
        MHEAD = ui->mhead->text().toDouble();
        dataBuff[6] = DoubletoBC1(MHEAD,0.0055, 15);
    }
    if(ui->checkBox_vn->isChecked())
    {
        dataBuff[7]=0x0000;
        dataBuff[8]=0x0000;
        VN= ui->vn->text().toDouble();
        bc2Vn = DoubletoBC2(VN, 0.0032, 19);
        dataBuff[7] = (bc2Vn >> 16) & 0x0000FFFF;
        dataBuff[8] = bc2Vn & 0x0000FFFF;
    }
    if(ui->checkBox_ve->isChecked())
    {
        dataBuff[9]=0x0000;
        dataBuff[10]=0x0000;
        VE= ui->ve->text().toDouble();
        bc2Ve = DoubletoBC2(VE, 0.0032, 19);
        dataBuff[9] = (bc2Ve >> 16) & 0x0000FFFF;
        dataBuff[10] = bc2Ve & 0x0000FFFF;
    }
    if(ui->checkBox_vup->isChecked())
    {
        dataBuff[11]=0x0000;
        Vup = ui->vup->text().toDouble();
        dataBuff[11] = DoubletoBC1(Vup, 0.0514, 15);
    }
    if(ui->checkBox_lat->isChecked())
    {
        dataBuff[12]=0x0000;
        dataBuff[13]=0x0000;
        LAT= ui->lat->text().toDouble();
        bc2Lat = DoubletoBC2(LAT, 90/pow(2.0,27), 28);
        dataBuff[12] = (bc2Lat >> 16) & 0x0000FFFF;
        dataBuff[13] = bc2Lat & 0x0000FFFF;
    }
    if(ui->checkBox_lon->isChecked())
    {
        dataBuff[14]=0x0000;
        dataBuff[15]=0x0000;
        LON= ui->lon->text().toDouble();
        bc2Lon = DoubletoBC2(LON, 90/pow(2.0,27), 28);
        dataBuff[14] = (bc2Lon >> 16) & 0x0000FFFF;
        dataBuff[15] = bc2Lon & 0x0000FFFF;
    }
    if(ui->checkBox_alt->isChecked())
    {
        dataBuff[16]=0x0000;
        ALT= ui->alt->text().toDouble();
        dataBuff[16] = DoubletoBC1(ALT, 1.0, 15);
    }
    if(ui->checkBox_poserr->isChecked())
    {
        dataBuff[17]=0x0000;
        POS_ERR= ui->pos_err->text().toDouble();
        dataBuff[17] = DoubletoBNR1(POS_ERR, 1.0);
    }
}

void MainWindow::updateinu03(unsigned short dataBuff[32])
{
    TIME_TAG3=BNR1toDouble(dataBuff[0], 0.064);
    mc_str = QString ( "%1" ).arg(TIME_TAG3, 0, 'f',4 );
    ui->time_tag3->setText(mc_str);

    nav_sts3= ((dataBuff[1]) ) & 0x8000;
    if(nav_sts3==0x8000)
    {
        ui->nav_sts_3->clear();
        ui->nav_sts_3->setText("Alignment Mode");
    }
    else
    {
        ui->nav_sts_3->clear();
        ui->nav_sts_3->setText("Navigation Mode");
    }

    align_sts3=(dataBuff[1] & 0x7000);
    if(align_sts3==0x0000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Not Ready");
    }
    if(align_sts3==0x1000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Ready after stored Heading");
    }
    if(align_sts3==0x2000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Ready after Inserted Heading");
    }
    if(align_sts3==0x3000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Interruptible Gyrocompass");
    }
    if(align_sts3==0x4000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Ready after Gyrocompass");
    }
    if(align_sts3==0x5000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Ready after In-flight restart");
    }
    if(align_sts3==0x6000)
    {
        ui->align_sts_3->clear();
        ui->align_sts_3->setText("Invalid Alignment coord.");
    }

    test_sts3= (dataBuff[1] & 0x0800);
    if(test_sts3==0x0800)
    {
        ui->test_sts_3->clear();
        ui->test_sts_3->setText("Test Mode");
    }
    else
    {
        ui->test_sts_3->clear();
        ui->test_sts_3->setText("Normal Mode");
    }

    select_sat3=(dataBuff[1] & 0x0600);
    if(select_sat3==0x0000)
    {
        ui->select_sat_3->clear();
        ui->select_sat_3->setText("Satellite Hybridization Prohibit");
    }
    if(select_sat3==0x0200)
    {
        ui->select_sat_3->clear();
        ui->select_sat_3->setText("GPS Only");
    }
    if(select_sat3==0x0400)
    {
        ui->select_sat_3->clear();
        ui->select_sat_3->setText("GLONASS Only");
    }
    if(select_sat3==0x0600)
    {
        ui->select_sat_3->clear();
        ui->select_sat_3->setText("GPS and GLONASS");
    }

    sat_sts3=(dataBuff[1] & 0x0100);
    if(sat_sts3==0x0100)
    {
        ui->sat_sts_3->clear();
        ui->sat_sts_3->setText("Searching");
    }
    else
    {
        ui->sat_sts_3->clear();
        ui->sat_sts_3->setText("Satellite Data Available");
    }

    run_sat_sys3=(dataBuff[1] & 0x00c0);
    if(run_sat_sys3==0x0000)
    {
        ui->run_sat_sys_3->clear();
        ui->run_sat_sys_3->setText("Satellite Hybridization Disable");
    }
    if(run_sat_sys3==0x0040)
    {
        ui->run_sat_sys_3->clear();
        ui->run_sat_sys_3->setText("GPS only");
    }
    if(run_sat_sys3==0x0080)
    {
        ui->run_sat_sys_3->clear();
        ui->run_sat_sys_3->setText("GLONASS only");
    }
    if(run_sat_sys3==0x00c0)
    {
        ui->run_sat_sys_3->clear();
        ui->run_sat_sys_3->setText("GPS and GLONASS");
    }

    sigma3=(dataBuff[1] & 0x0020);
    if(sigma3==0x0020)
    {
        ui->sigma_3->clear();
        ui->sigma_3->setText("FAIL");
    }
    else
    {
        ui->sigma_3->clear();
        ui->sigma_3->setText("PASS");
    }

    inertial_blk3=(dataBuff[1] & 0x0010);
    if(inertial_blk3==0x0010)
    {
        ui->inertial_blk_3->clear();
        ui->inertial_blk_3->setText("FAIL");
    }
    else
    {
        ui->inertial_blk_3->clear();
        ui->inertial_blk_3->setText("PASS");
    }

    gps_glonass3=(dataBuff[1] & 0x0008);
    if(gps_glonass3==0x0008)
    {
        ui->gps_glonass_3->clear();
        ui->gps_glonass_3->setText("FAIL");
    }
    else
    {
        ui->gps_glonass_3->clear();
        ui->gps_glonass_3->setText("PASS");
    }

    analog_discrete3=(dataBuff[1] & 0x0004);
    if(analog_discrete3==0x0004)
    {
        ui->analog_discrete_op_3->clear();
        ui->analog_discrete_op_3->setText("FAIL");
    }
    else
    {
        ui->analog_discrete_op_3->clear();
        ui->analog_discrete_op_3->setText("PASS");
    }

    gost_op3=(dataBuff[1] & 0x0002);
    if(gost_op3==0x0002)
    {
        ui->gost_op_3->clear();
        ui->gost_op_3->setText("FAIL");
    }
    else
    {
        ui->gost_op_3->clear();
        ui->gost_op_3->setText("PASS");
    }

    computer3=(dataBuff[1] & 0x0001);
    if(computer3==0x0001)
    {

        ui->computer_3->clear();
        ui->computer_3->setText("FAIL");
    }
    else
    {
        ui->computer_3->clear();
        ui->computer_3->setText("PASS");
    }

    pitch_roll3=(dataBuff[2] & 0x8000);
    if(pitch_roll3==0x8000)
    {
        ui->pitch_roll3->clear();
        ui->pitch_roll3->setText("Valid");
    }
    else
    {
        ui->pitch_roll3->clear();
        ui->pitch_roll3->setText("Invalid");
    }

    true_head3=(dataBuff[2] & 0x4000);
    if(true_head3==0x4000)
    {
        ui->true_head3->clear();
        ui->true_head3->setText("Valid");
    }
    else
    {
        ui->true_head3->clear();
        ui->true_head3->setText("Invalid");
    }

    magnetic_head3=(dataBuff[2] & 0x2000);
    if(magnetic_head3==0x2000)
    {
        ui->magnetic_head3->clear();
        ui->magnetic_head3->setText("Valid");
    }
    else
    {
        ui->magnetic_head3->clear();
        ui->magnetic_head3->setText("Invalid");
    }

    hybrid_speed_3=(dataBuff[2] & 0x1000);
    if(hybrid_speed_3==0x1000)
    {
        ui->hybrid_speed_3->clear();
        ui->hybrid_speed_3->setText("Valid");
    }
    else
    {
        ui->hybrid_speed_3->clear();
        ui->hybrid_speed_3->setText("Invalid");
    }

    hybrid_horiz_coord_3=(dataBuff[2] & 0x0800);
    if(hybrid_horiz_coord_3==0x0800)
    {
        ui->hybrid_horiz_coord_3->clear();

        ui->hybrid_horiz_coord_3->setText("Valid");
    }
    else

    {
        ui->hybrid_horiz_coord_3->clear();
        ui->hybrid_horiz_coord_3->setText("Invalid");
    }

    hybrid_alt_3=(dataBuff[2] & 0x0400);
    if(hybrid_alt_3==0x0400)
    {
        ui->hybrid_alt_3->clear();
        ui->hybrid_alt_3->setText("Valid");
    }
    else
    {
        ui->hybrid_alt_3->clear();
        ui->hybrid_alt_3->setText("Invalid");
    }

    hybrid_pos_err_3=(dataBuff[2] & 0x0200);
    if(hybrid_pos_err_3==0x0200)
    {
        ui->hybrid_pos_err_3->clear();
        ui->hybrid_pos_err_3->setText("Valid");
    }
    else
    {
        ui->hybrid_pos_err_3->clear();
        ui->hybrid_pos_err_3->setText("Invalid");
    }

    ROLL= dataBuff[3] & 0x00FF;
    //ROLL= ((ROLL & 0x00FF) << 8);
    ROLL= BC1toDouble(ROLL, 0.011, 14);
    mc_str = QString ( "%1" ).arg(ROLL, 0, 'f',4 );
    ui->roll->clear ();
    ui->roll->setText(mc_str);


    // ROLL= BC1toDouble(dataBuff[3], 0.011, 14);
    // mc_str = QString ( "%1" ).arg(ROLL, 0, 'f',4 );
    // ui->roll->setText(mc_str);

    /*  tlt= mslp_res_data[8]  & 0x00FF;
    mc_str = QString ( "%1" ).arg(tlt, 0, 10 );
    ui->tlt->clear ();
    ui->tlt->setText(mc_str);


*/
    PITCH=BC1toDouble(dataBuff[4], 0.011, 14);
    mc_str = QString ( "%1" ).arg(pITCH, 0, 'f',4 );
    ui->pitch->setText(mc_str);

    THEAD=BC1toDouble(dataBuff[5],  0.0055, 15);
    mc_str = QString ( "%1" ).arg(pITCH, 0, 'f',4 );
    ui->thead->setText(mc_str);

    MHEAD=BC1toDouble(dataBuff[6],  0.0055, 15);
    mc_str = QString ( "%1" ).arg(MHEAD, 0, 'f',4 );
    ui->mhead->setText(mc_str);

    bc2Vn = dataBuff[7];
    bc2Vn = ((bc2Vn & 0x0000FFFF) << 16) | dataBuff[8];
    VN= BC2toDouble(bc2Vn, 0.0032, 19);
    mc_str = QString ( "%1" ).arg(VN, 0, 'f',4 );
    ui->vn->setText(mc_str);

    bc2Ve = dataBuff[9];
    bc2Ve = ((bc2Ve & 0x0000FFFF) << 16) | dataBuff[10];
    VE=BC2toDouble(bc2Ve, 0.0032, 19);
    mc_str = QString ( "%1" ).arg(VE, 0, 'f',4 );
    ui->ve->setText(mc_str);

    Vup=BC1toDouble(dataBuff[11], 0.0514, 15);
    mc_str = QString ( "%1" ).arg(Vup, 0, 'f',4 );
    ui->vup->setText(mc_str);


    // Vup = dataBuff[11]*0xFFFF;
    //  Vup = (Vup & 0xFFFF);
    //  Vup=BC1toDouble(Vup, 0.0514, 15);
    //  mc_str = QString ( "%1" ).arg(Vup, 0, 'f',4 );
    //   ui->vup->setText(mc_str);


    bc2Lat = dataBuff[12];
    bc2Lat = ((bc2Lat & 0x0000FFFF) << 16) | dataBuff[13];
    LAT=BC2toDouble(bc2Lat,90/pow(2.0,27), 28);
    mc_str = QString ( "%1" ).arg(LAT, 0, 'f',4 );
    ui->lat->setText(mc_str);

    bc2Lon = dataBuff[14];
    bc2Lon = ((bc2Lon & 0x0000FFFF) << 16) | dataBuff[15];
    LON=BC2toDouble(bc2Lon,90/pow(2.0,27), 28);
    mc_str = QString ( "%1" ).arg(LON, 0, 'f',4 );
    ui->lon->setText(mc_str);

    ALT=BC1toDouble(dataBuff[16], 1.0, 15);
    mc_str = QString ( "%1" ).arg(ALT, 0, 'f',4 );
    ui->alt->setText(mc_str);
    //  printf("alt is %lf\n",ALT);
    //    if((ALT-61.0000)>20.0000)
    //    {
    //        ui->ta->setText("Ta cmd");
    //        ALT=BC1toDouble(dataBuff[16], 1.0, 15);
    //        itoa(ALT,s,10);
    //        mc_str=s;
    //        ui->alt_2->setText(mc_str);
    //    }


    POS_ERR=BNR1toDouble(dataBuff[17], 1.0);
    mc_str = QString ( "%1" ).arg(POS_ERR, 0, 'f',4 );
    ui->pos_err->setText(mc_str);
}

/**************QT_MC CODE ENDS***********/
void MainWindow::stopMc()
{

    mc_acestop(); // mc_acestopfunction
    this->mc_timer->stop();
}

void MainWindow::on_mc_File_Brwse_Pbt_clicked()
{

    mcFilePath = QFileDialog::getOpenFileName(this,"Select File","");
    //QStringList list = mcFilePath.split("/");
    ui->mc_file_Ldt->setText(mcFilePath);
}

void MainWindow::on_mc_file_Chk_clicked(bool checked)
{
    if(checked == true)
    {
        ui->mc_File_Brwse_Pbt->setFocus();
        ui->mc_file_Ldt->clear();
    }
    else
    {
        ui->mc_file_Ldt->setText("FILE10.DAT");
    }
}

void MainWindow::on_rc_file_Pbt_clicked()
{

    rcFilePath = QFileDialog::getOpenFileName(this,"SelectFile");
    QStringList list = rcFilePath.split("/");
    ui->rc_file_Ldt->setText(list.at(list.size()-1));

}

void MainWindow::on_rc_select_Chk_clicked(bool checked)
{
    if(checked == true)
    {
        ui->rc_file_Pbt->setFocus();
        ui->rc_file_Ldt->clear();
    }
    else
    {
        ui->rc_file_Ldt->setText("MIL_RC_LOT_TEST.txt");
    }
}
void MainWindow::onSIM()
{
    if(cb1== true)
    {
        ui->cB_lOTD->addItem("Target-1");

    sg1 = new sgeneration();
    sg1->Hs=ui->lE_sHeight_2->text().toDouble();
    sg1->Ht=ui->lE_tHeight->text().toDouble();
    sg1->Vs=ui->lE_sVelocity_3->text().toDouble();
    sg1->Vt=ui->lE_Velocity->text().toDouble();
    sg1->TAA=ui->lE_tGT_AA->text().toDouble();
    sg1->R=ui->lE_rTGT->text().toDouble();
    //sgnflag=1;
    memset(sg1->Word_MC,0,32*4);
    memset(sg1->Word_RC,0,32*4);
    sg1->iNputSgeneration();
    cb1= false;
//        ui->cB_simulation->setDisabled(true);

    stn1 = true;

}
else
    stn1= false;
}
/*
void MainWindow::on_cB_simulation_clicked(bool checked)
{
    if(checked == true)
    {
        if(cb1== true)
            ui->cB_lOTD->addItem("Target-1");

        sg1 = new sgeneration();
        sg1->Hs=ui->lE_sHeight_2->text().toDouble();
        sg1->Ht=ui->lE_tHeight->text().toDouble();
        sg1->Vs=ui->lE_sVelocity_3->text().toDouble();
        sg1->Vt=ui->lE_Velocity->text().toDouble();
        sg1->TAA=ui->lE_tGT_AA->text().toDouble();
        sg1->R=ui->lE_rTGT->text().toDouble();
        //sgnflag=1;
        memset(sg1->Word_MC,0,32*4);
        memset(sg1->Word_RC,0,32*4);
        sg1->iNputSgeneration();
        cb1= false;
//        ui->cB_simulation->setDisabled(true);

        stn1 = true;

    }
    else
        stn1= false;
}
*/

void MainWindow::on_cB_simulation_2_clicked(bool checked)
{
    if(checked == true){
        if(cb2==true)
            ui->cB_lOTD->addItem("Target-2");
        sg2 = new sgeneration();
        sg2->Hs=ui->lE_sHeight_2->text().toDouble();
        sg2->Ht=ui->lE_tHeight_2->text().toDouble();
        sg2->Vs=ui->lE_sVelocity_3->text().toDouble();
        sg2->Vt=ui->lE_Velocity_2->text().toDouble();
        sg2->TAA=ui->lE_tGT_AA_2->text().toDouble();
        sg2->R=ui->lE_rTGT_2->text().toDouble();
        //sgnflag=2;
        memset(sg2->Word_MC,0,32*4);
        memset(sg2->Word_RC,0,32*4);
        sg2->iNputSgeneration();
        cb2= false;
//        ui->cB_simulation_2->setDisabled(true);

        stn2 =true;

    }else
        stn2=false;


}




void MainWindow::on_cB_simulation_3_clicked(bool checked)
{
    if(checked == true)
    {
        if(cb3==true)
            ui->cB_lOTD->addItem("Target-3");
        sg3 = new sgeneration();
        sg3->Hs=ui->lE_sHeight_2->text().toDouble();
        sg3->Ht=ui->lE_tHeight_3->text().toDouble();
        sg3->Vs=ui->lE_sVelocity_3->text().toDouble();
        sg3->Vt=ui->lE_Velocity_3->text().toDouble();
        sg3->TAA=ui->lE_tGT_AA_3->text().toDouble();
        sg3->R=ui->lE_rTGT_3->text().toDouble();
        //sgnflag=3;

        memset(sg3->Word_MC,0,32*4);
        memset(sg3->Word_RC,0,32*4);
        sg3->iNputSgeneration();
        stn3= true;
        cb3=false;
//        ui->cB_simulation_3->setDisabled(true);

    }else
        stn3 =false;

}

void MainWindow::on_cB_simulation_4_clicked(bool checked)
{
    if(checked == true){
        if(cb4== true)
            ui->cB_lOTD->addItem("Target-4");
        sg4 = new sgeneration();
        sg4->Hs=ui->lE_sHeight_2->text().toDouble();
        sg4->Ht=ui->lE_tHeight_4->text().toDouble();
        sg4->Vs=ui->lE_sVelocity_3->text().toDouble();
        sg4->Vt=ui->lE_Velocity_4->text().toDouble();
        sg4->TAA=ui->lE_tGT_AA_4->text().toDouble();
        sg4->R=ui->lE_rTGT_4->text().toDouble();
       // sgnflag=4;

        memset(sg4->Word_MC,0,32*4);
        memset(sg4->Word_RC,0,32*4);
        cb4=false;
        sg4->iNputSgeneration();
//        ui->cB_simulation_4->setDisabled(true);

        stn4 =true;
    }else
        stn4 =false;

}



void MainWindow::on_cB_mANEUVER_clicked(bool checked)
{

    Maneuverb  =  checked;
}

void MainWindow::filewriting()
{




    union time
    {
        int time_total;
       unsigned short int time_data[2];
    };

   union time mlp_time;

   //fprintf(Surv7File,"\n");

    mlp_time.time_data[0] = mslp_res_data[20];
    mlp_time.time_data[1] = mslp_res_data[19];

    float mlp_time1 = float(mlp_time.time_total);
    mlp_time1=mlp_time1/1000;
  //  qDebug()<<mlp_time.time_total;
    //qDebug()<<(mslp_res_data4[19]*65536);
    //fprintf(Surv9File,"%f   ",mlp_time1);

//for(mlp_time1=0;mlp_time1<=10;mlp_time1++)

   // {

    if((mlp_time1 >= 160.0) && (ui->mis_state->text()=="Ready after PBIT") && (Pbitflag==0) )
    {
       Pbitflag=1;
       onSIM();
    }


    if((mlp_time1>=6) & (ui->DLTxsup_sts->text()=="ON") & (DLTxflag==0))
           {
           QString dlt_sts=ui->DLTxsup_sts->text();
         //  qDebug()<<"dlt_sts"<<dlt_sts;
           //qDebug()<<"DLTxflag"<<DLTxflag;
           DLTxflag=1;
           //qDebug()<<"DLTxflag1"<<DLTxflag;
           fprintf(Autolaunch_file,"\nMLP Time\t\t\t\t\t\tEvents\n");
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tDLT:ON");


       }
       //}
       //    if((ui->umbilical_sts->text()=="Mated") & umblicalflag==0)
       //    {
       //      QString umbilical=ui->umbilical_sts->text();
       //      qDebug()<<"umbilical"<<umbilical;
       //      qDebug()<<"umbilical flag"<<umblicalflag;
       //      umblicalflag=1;
       //      qDebug()<<"umbilical flag"<<umblicalflag;
       //      //fprintf(Autolaunch_file,"Umbilical:Mated");

       //    }

       //----------------------Missile available------------------------------------


               if((mlp_time1>=6) & (ui->mis_avail->text()=="Mated")  & (mis_avail_flag==0))
               {
                   mis_avail_flag=1;
                   fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
                   fprintf(Autolaunch_file,"\t\t\t\t\t\t\tMissile Availability:Available");

               }


       if((mlp_time1>=6) & (ui->umbilical_sts->text()=="Mated")  & (umblicalflag==0))
       {
           umblicalflag=1;
          fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tUmbilical:Mated");

       }

       //    if((ui->SAM_sts->text()=="ON") & (samflag==0))
       //    {
               //samflag=1;
       //       // fprintf(Autolaunch_file,"SAM:ON");//
       //    }
       if((mlp_time1>=5) & (ui->SAM_sts->text()=="ON") &(samflag==0) )
       {
          samflag=1;
          fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
          fprintf(Autolaunch_file,"\t\t\t\t\t\t\tSAM:ON");

       }
       //-----------------------------Luncher health----------------------

       if( (ui->amlp_hlth->text()=="OK") &(mlpflag==0) )
       {
          mlpflag=1;
          fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
          fprintf(Autolaunch_file,"\t\t\t\t\t\t\tAMLP Health:OK");

       }




       //---------------------------AMLP MODE-----------------------------

       //    if ((ui->modetype->text()=="NO MODE") & (modeflag==0))
       //    {
       //        modeflag=1;
       //        fprintf(Autolaunch_file,"\n\tAMLP MODE:No Mode");
       //    }
       if((mlp_time1>=6) & (ui->modetype->text()=="NO MODE") & (modeflag==0))
       {
           modeflag=1;
           fprintf(Autolaunch_file,"\n\tAMLP MODE:No Mode");
       }

       //    if ((ui->modetype->text()=="LIVE MODE") & (modeflag==0))
       //    {
       //        modeflag=1;
       //        fprintf(Autolaunch_file,"\n\tAMLP MODE:Live Mode");
       //    }
     //  qDebug()<<"mlp time_h"<<mlp_time1;
       QString modetype=ui->modetype->text();
    //   qDebug()<<"modetype"<<modetype;
       if((mlp_time1>=5) & (ui->modetype->text()=="LIVE MODE") & (modeflag==0))
       {
         //  qDebug()<<"modeflag0="<<modeflag;

           modeflag=1;
         //  qDebug()<<"modeflag1="<<modeflag;

           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tAMLP MODE:Live Mode");


       }


       //    if((ui->modetype->text()=="MSL SM MODE") &(modeflag==0))
       //    {
       //        modeflag=1;
       //        fprintf(Autolaunch_file,"\n\tAMLP MODE:Msl Sim Mode");
       //    }

       if((mlp_time1>=5) & (ui->modetype->text()=="MSL SM MODE") & (modeflag==0))
       {
           QString Mode=ui->modetype->text();
              //   qDebug()<<"Mode"<<Mode;
              //   qDebug()<<"mode flag"<<umblicalflag;
                 modeflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tAMLP MODE:Msl Sim Mode");

       }


       //    if ((ui->modetype->text()=="STORE MODE MKI") & (modeflag==0))
       //    {
       //        modeflag=1;
       //        fprintf(Autolaunch_file,"\n\tAMLP MODE:Store Mode-MKI");
       //    }
       if((mlp_time1>=5) &(ui->modetype->text()=="STORE MODE MK1") &(modeflag==0))
       {QString Mode=ui->modetype->text();
         //  qDebug()<<"store Mode"<<Mode;
        //   qDebug()<<"store flag"<<modeflag;
           modeflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tAMLP MODE:Store Mode-MKI");

       }

       //    if ((ui->modetype->text()=="STORE MODE MKII") &(modeflag==0))
       //    {
       //        modeflag=1;
       //        fprintf(Autolaunch_file,"\n\tAMLP MODE:Store Mode-MKII");
       //    }
       if((mlp_time1>=5) & (ui->modetype->text()=="STORE MODE MK1I") &(modeflag==0) )
       {
           modeflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tAMLP MODE:Store Mode-MKII");

       }


           if((ui->modetype->text()==" LH/ACS Mode") &(modeflag==0))
           {
               modeflag=1;
               fprintf(Autolaunch_file,"\n\tAMLP MODE:LA/ACS Mode");
               //fprintf(Autolaunch_file,"\t\t\t\tMLP Time:%5.3f",mlp_time1);

           }
       //----------------------Launcher type---------------------------------------


       if ((ui->launcher_test->text()=="R Launcher")  & (ltypeflag==0))

            {
           ltypeflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tLauncher Type:Rail Launcher");
           }
       if ((ui->launcher_test->text()=="EJ Launcher")  & (ltypeflag==0))

            {
           ltypeflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tLauncher Type:Rail Launcher");


            }

       //-----------------------------------------------------------------------

       //if( (mlp_time1==24)&(ui->filament27->text()=="ON") & (filamentflag==0))
           if (  (mlp_time1>=24) &    (ui->filament27->text()=="ON") & (filament_flag==0))

       {
           filament_flag=1;
           QString filament27=(ui->filament27->text());
           qDebug()<<"filament27"<<filament27;

           //qDebug()<<"filament_flag"<<filament_flag;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tFilament:ON");
           //qDebug()<<"filament_flag"<<filament_flag;

       }



       //if (ui->mis_hlth->text()=="OK") //& (nogoflag=0))
       //{QString abc=ui->amlp_timer->text();
       //    QByteArray mlptime=abc.toLatin1();
       //    const char *c_str1=mlptime.data();
       //    fprintf(Autolaunch_file,"\n\t MLP time : ",c_str1);
       //    fprintf(Autolaunch_file,"Missile Subsytem Health :Pass");}

       //----------------- OBC post-------------------------------------------

       if((ui->mlpobc_comm->text()=="OK") & (Obcflag==0))
       {
           Obcflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tMLP-OBC Communication:OK");

           //fprintf(Autolaunch_file,"MLP time:",mlp_time1);


       }

       if((ui->missile_test->text()=="Astra MK-I") & (msl_type_flag==0))
       {
           msl_type_flag=1;
          // qDebug()<<"msl_type_flag"<<msl_type_flag;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tMissile Type:Astra MK-I");

           //fprintf(Autolaunch_file,"MLP time:",mlp_time1);
       }

       if((ui->missile_test->text()=="Astra MK-II") & (msl_type_flag==0))
       {
           msl_type_flag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tMissile Type:Astra MK-II");

           //fprintf(Autolaunch_file,"MLP time:",mlp_time1);


       }

//--------------------APSU VOLTAGES------------------------------

   if((mlp_time1>70.0) && (Apsuflag==0))
   {
       Apsuflag = 1;
       /*itoa(mslp_res_data[10],s,10);
    //  int setx = (((mslp_res_data[10] - 32767)*60)/65535);
      //  itoa(mslp_res_data[10],s,10);
      str = s ;//QString ( "%1" ).arg( setx, 0, 10 );
      ui->setx->clear ();
      ui->setx->setText(str); */

      fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
      fprintf(Autolaunch_file,"\t\t\t\t\t\t\tSeekerTx : %d",mslp_res_data[10]);

     /* itoa(mslp_res_data[11],s,10);
      str=s;
      ui->seel->clear ();
      ui->seel->setText(str); */
      fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
      fprintf(Autolaunch_file,"\t\t\t\t\t\t\tSeeker Electronics : %d",mslp_res_data[11]);

      /*itoa(mslp_res_data[12],s,10);
      str=s;
      ui->elmon->clear ();
      ui->elmon->setText(str);*/
      fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
      fprintf(Autolaunch_file,"\t\t\t\t\t\t\tElectronics : %d",mslp_res_data[12]);

      /*itoa(mslp_res_data[13],s,10);
      str=s;
      ui->dltmon->clear ();
      ui->dltmon->setText(str);*/
      fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
      fprintf(Autolaunch_file,"\t\t\t\t\t\t\tDLTx : %d",mslp_res_data[13]);


     // int actmon = (((mslp_res_data[14] - 32767)*60)/65535);
     /* itoa(mslp_res_data[14],s,10);
      str =s; // QString ( "%1" ).arg( actmon, 0, 10 );
      ui->actmon->clear ();
      ui->actmon->setText(str);*/
      fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
      fprintf(Autolaunch_file,"\t\t\t\t\t\t\tActuator : %d\n",mslp_res_data[14]);

 }


       //------------------Msl Pbit------------------------------------

       if ((ui->mis_mate->text()=="ON") & (lflag==0))
       {
           lflag=1;
               //fprintf(Autolaunch_file,"\n\t\tLift Off:ON");
               //fprintf(Autolaunch_file,"MLP time:",mlp_time1);

       }

       if((ui->fin_lock->text()=="OK") & (finflag==0))
       {
           finflag=1;
           //fprintf(Autolaunch_file,"\n\t\tActualtor Coil Current:OK");
       }

       if((ui->act_null->text()=="OK") & (actflag==0))
       {
           actflag=1;
           //fprintf(Autolaunch_file,"\n\t\tActualtor Null:OK");
       }

       if((ui->DLRx_init_hlth->text()=="OK") & (DLRflag==0))
       {
           //DLRflag=1;
           //fprintf(Autolaunch_file,"\n\t\tDLR init Health:OK");
       }
       if((ui->ins_cbit->text()=="OK") & (insflag==0))
       {
           insflag=1;
           //fprintf(Autolaunch_file,"\n\t\tINS Pbit:OK");
       }
       if((ui->rpf_hlth->text()=="OK") & (rpfflag==0))
       {
           rpfflag=1;
           //fprintf(Autolaunch_file,"\n\t\tRPF Health:OK");

       }

       if((ui->sam_hlth->text()=="OK") & (samflag==0))
       {
           samflag=1;
           //fprintf(Autolaunch_file,"\n\t\tSAM Health:OK");

       }
       if((ui->seekr_elec_hlth->text()=="OK") & (seekrflag==0))
       {
           seekrflag=1;
           //fprintf(Autolaunch_file,"\n\t\tSeeker Elec. Health:OK");

       }
       if((ui->obc_comm->text()=="OK") & (obcflag==0))
       {
        obcflag=1;
        //fprintf(Autolaunch_file,"\n\t\tOBC Communication:OK");

       }
       if((ui->DLR_Hlth->text()=="OK") & (DLRflag==1))
       {
           //DLRflag=2;
           //fprintf(Autolaunch_file,"\n\t\tDLR Health:OK");
           //fprintf(Autolaunch_file,"\n\tMLP Time:%5.3f",mlp_time1);
           //fprintf(Autolaunch_file,"\tMissile PBIT Completed\n");
           //fprintf(Autolaunch_file,"\t\t\tMLP Time:%5.3f",mlp_time1);

       }


       //---------------Msl subsystem health NOGO7-----------------------

       if ((ui->mis_hlth->text()=="NOT OK") & (nogoflag==7))
       {
           fprintf(Autolaunch_file,"\t\tNOGO : 7");
           fprintf(Autolaunch_file,"\t\tMissile Subsystem Health : Fail\n");

           if((ui->fin_lock->text()=="NOT OK") & (finflag==0))
           {
               finflag=1;
               fprintf(Autolaunch_file,"\t\tActualtor Coil Current: NOT OK\n");
           }
           if((ui->act_null->text()=="NOT OK") & (actflag==0))
           {
               actflag=1;
               fprintf(Autolaunch_file,"\n\t\tActualtor Null: NOT OK");
           }

           if((ui->DLRx_init_hlth->text()=="NOT OK") & (DLRflag==0))
           {
               //DLRflag=1;
               //fprintf(Autolaunch_file,"\n\t\tDLR init Health: NOT OK");
           }
           if((ui->ins_cbit->text()=="NOT OK") & (insflag==0))
           {
               insflag=1;
               fprintf(Autolaunch_file,"\n\t\tINS Pbit:OK");
           }
           if((ui->rpf_hlth->text()=="NOT 0K") & (rpfflag==0))
           {
               rpfflag=1;
               fprintf(Autolaunch_file,"\n\t\tRPF Health:NOT OK");

           }

           if((ui->sam_hlth->text()=="NOT OK") & (samflag==0))
           {
               samflag=1;
               fprintf(Autolaunch_file,"\n\t\tSAM Health: NOT OK");

           }
           if((ui->seekr_elec_hlth->text()=="NOT OK") & (seekrflag==0))
           {
               seekrflag=1;
               fprintf(Autolaunch_file,"\n\t\tSeeker Elec. Health:OK");

           }
           if((ui->obc_comm->text()=="NOT OK") & (obcflag==0))
           {
            obcflag=1;
            fprintf(Autolaunch_file,"\n\t\tOBC Communication:NOT OK");

           }
           if((ui->DLR_Hlth->text()=="NOT OK") & (DLRflag==0))
           {
               //DLRflag=1;
               //fprintf(Autolaunch_file,"\n\t\tDLR Health:NOT OK");

           }
       }



       //-------------------TA Manuever---------------------------------

       if((ui->manever->text()=="Required")& ( Maneverflag==0))
       {
           Maneverflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tTA Manuever :Required");

           //fprintf(Autolaunch_file,"\n\t\t            : Manuever Received");
       }

       if((ui->manever->text()=="Not Required")& ( Maneverflag==1))
       {
           Maneverflag=2;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tTA Manuever :Not Required");

       }
       //if(Maneuverb=bool(true) & ( Maneverflag==0))
       //{
       //  Maneverflag=1;
       //  fprintf(Autolaunch_file,"\n\t\t Manuever Bit:Set to 1");
       //}
       //if(Maneuverb=bool(false) & ( Maneverflag==0))
       //{
       // Maneverflag=2;
       //  fprintf(Autolaunch_file,"\n\t\t Manuever Bit:Set to 0 ");
       //}

       //------------------------DLT PBIT-----------------------------



       //QString DLTx_init=ui->DLTx_init->text();
       //qDebug()<<"DLTx_init"<<DLTx_init;
       if((ui->DLTx_init->text()=="OK") & (DLTxflag==1))
       {
           QString DLTx_init=ui->DLTx_init->text();
           qDebug()<<"DLTx_init"<<DLTx_init;
           DLTxflag=2;
         //  qDebug()<<"DLTxflag"<<DLTxflag;

           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tDatalink Init: OK ");


       }
       //else
       //     fprintf(Autolaunch_file,"\n\t\t Datalink Init: Not OK ");


       if((ui->DLTx_sts->text()=="OK") & (DLTxflag==2))
       {
           DLTxflag=3;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tDatalink Health status: OK ");

       }
       //else
       //     fprintf(Autolaunch_file,"\n\t\t Datalink Init: Not OK ");


       if((ui->DLRx_init_hlth->text()=="OK") & (DLRflag==0))
       {
           QString DLRx_init_hlth=ui->DLRx_init_hlth->text();
         //  qDebug()<<"DLRx_init_hlth"<<DLRx_init_hlth;
           DLRflag=1;
           //fprintf(Autolaunch_file,"\t\t\t\t\t\t\tDLR init Health: OK ");
           //fprintf(Autolaunch_file,"\nMLP Time:%5.3f",mlp_time1);


       }
       //QString DLR_Hlth=ui->DLR_Hlth->text();
       //qDebug()<<"DLR_Hlth"<<DLR_Hlth;


       if((ui->DLR_Hlth->text()=="OK") & (DLRflag==1))

       {
           QString DLR_Hlth=ui->DLR_Hlth->text();
          // qDebug()<<"DLR_Hlth"<<DLR_Hlth;
           DLRflag=2;
           //fprintf(Autolaunch_file,"\n\t\tDLR_Hlth: OK ");
           //fprintf(Autolaunch_file,"\t\t\t\t\t\tMLP Time:%5.3f",mlp_time1);


       }



       //}



       if ((ui->mis_state->text()=="Ready after PBIT") & (Pbitcmpflag==0) )
       {
           Pbitcmpflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tPBIT Completed");

       }

       //else
       //     fprintf(Autolaunch_file,"\n\t\t PBIT: Not OK ");

       //------------------------------Prelaunch--------------------------------------------------


       if((ui->ta_sts->text()=="Converged") & (TAflag==0))
       {
           TAflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\t Transfer Alignment:Converged");

       }


       //------------------------------------------------------------------------------------------


       //if((stnflag==1) &  (ui->cb_validity->currentText()=="1-VALID") & (ui->cb_astra_rvvae->currentText()=="ASRM1")||(ui->cb_astra_rvvae->currentText()=="ASRM2") )
       //{
       //    //stnflag==1;
       //    fprintf(Autolaunch_file,"\n\t\t Station 7 -Missile Ready after seeker-DL freq cmd");
       //}
       //if((stnflag==2) & (ui->cb_validity->currentText()=="1-VALID") & (ui->cb_astra_rvvae->currentText()=="ASRM")||(ui->cb_astra_rvvae->currentText()=="ASRM2") )
       //{
       //    //stnflag==2;
       //    fprintf(Autolaunch_file,"\n\t\t Station 8 -Missile Ready after seeker-DL freq cmd");
       //}
       //if((stnflag==3) & (ui->cb_validity->currentText()=="1-VALID") & (ui->cb_astra_rvvae->currentText()=="ASRM1")||(ui->cb_astra_rvvae->currentText()=="ASRM2") )
       //{
       //   // stnflag==3;
       //    fprintf(Autolaunch_file,"\n\t\t Station 9 -Missile Ready after seeker-DL freq cmd");
       //}

       //if((stnflag==4) & (ui->cb_validity->currentText()=="1-VALID") & (ui->cb_astra_rvvae->currentText()=="ASRM1")||(ui->cb_astra_rvvae->currentText()=="ASRM2") )
       //{
       //    //stnflag==4;
       //    fprintf(Autolaunch_file,"\n\t\t Station 10 -Missile Ready after seeker-DL freq cmd");
       //}

       //----------------Re init part-------------------------------------------------
       for(reinit_flag=10;reinit_flag<=200;reinit_flag++)
       {
          // qDebug()<<"reinit_flag"<<reinit_flag;

           if((ui->cb_validity->currentText()=="1-VALID")& (ui->le_freq->text()==" ") & (ui->skr_6->currentText()=="AUTO") & (ui->dl_4->currentText()=="AUTO") )//&(reinit_flag==0))
           {
               reinit_flag=1;
            //   qDebug()<<"reinit_flag1"<<reinit_flag;
               fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
               fprintf(Autolaunch_file,"\t\t\t\t\t\t\tDLT re-init status: OK");

           }
       }











       //-------------------Target selection part-------------------------------------


       if((sgnflag==0)  & (ui->cB_lOTD->currentText()=="Target-1"))
       {
       sgnflag=1;
       //lotdflag=1;

       fprintf(Autolaunch_file,"\n\t  --------PRELAUNCH--------- ");
       fprintf(Autolaunch_file,"\n\n\t  --------Scenario Parameters--------- ");
       fprintf(Autolaunch_file,"\n\n%5.3f",mlp_time1);
       fprintf(Autolaunch_file,"\t Target-1 Selected\n");



           double Hs=ui->lE_sHeight_2->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\t Shooter Height :          %5.3f",Hs);

           double Ht=ui->lE_tHeight->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\t Target Height :           %5.3f",Ht);

           double Vs=ui->lE_sVelocity_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\t Shooter Velocity :        %5.3f",Vs);

           double Vt=ui->lE_Velocity->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\t Target Velocity :         %5.3f",Vt);

           double TAA=ui->lE_tGT_AA->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\t Target Aspect Angle :     %5.3f",TAA);

           double R=ui->lE_rTGT->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\t Range of Target :         %5.3f",R);


       }


       if((sgnflag==0) & (ui->cB_lOTD->currentText()=="Target-2"))
       {
       sgnflag=2;
       fprintf(Autolaunch_file,"\nMLP Time:%5.3f",mlp_time1);
       fprintf(Autolaunch_file,"\tTarget-2 Selected");

           double Hs=ui->lE_sHeight_2->text().toDouble();
           fprintf(Autolaunch_file,"\nShooter Height: %5.3f",Hs);

           double Ht=ui->lE_sHeight_2->text().toDouble();
           fprintf(Autolaunch_file,"\nTarget Height: %5.3f",Ht);

           double Vs=ui->lE_sVelocity_3->text().toDouble();
           fprintf(Autolaunch_file,"\nShooter Velocity: %5.3f",Vs);

           double Vt=ui->lE_Velocity_2->text().toDouble();
           fprintf(Autolaunch_file,"\nTarget Velocity: %5.3f",Vt);

           double TAA=ui->lE_tGT_AA_2->text().toDouble();
           fprintf(Autolaunch_file,"\nTarget Aspect Angle: %5.3f",TAA);

           double R=ui->lE_rTGT_2->text().toDouble();
           fprintf(Autolaunch_file,"\nRange of Target: %5.3f",R);


       }


       if((sgnflag==0) & (ui->cB_lOTD->currentText()=="Target-3"))
       {
       sgnflag=3;

       fprintf(Autolaunch_file,"\nMLP Time:%5.3f",mlp_time1);
       fprintf(Autolaunch_file,"\t\t\t\t\t\t\tTarget-3 Selected");

           double Hs=ui->lE_sHeight_2->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tShooter Height: %5.3f",Hs);

           double Ht=ui->lE_tHeight_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tTarget Height: %5.3f",Ht);

           double Vs=ui->lE_sVelocity_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tShooter Velocity: %5.3f",Vs);

           double Vt=ui->lE_Velocity_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tTarget Velocity: %5.3f",Vt);

           double TAA=ui->lE_tGT_AA_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tTarget Aspect Angle: %5.3f",TAA);

           double R=ui->lE_rTGT_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tRange of Target: %5.3f",R);


       }


       if((sgnflag==0) & (ui->cB_lOTD->currentText()=="Target-4"))
       {
       sgnflag=4;

       fprintf(Autolaunch_file,"\nMLP Time:%5.3f",mlp_time1);
       fprintf(Autolaunch_file,"\t\t\t\t\t\t\tTarget-4 Selected");

           double Hs=ui->lE_sHeight_2->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tShooter Height: %5.3f",Hs);

           double Ht=ui->lE_tHeight_4->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tTarget Height: %5.3f",Ht);

           double Vs=ui->lE_sVelocity_3->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tShooter Velocity: %5.3f",Vs);

           double Vt=ui->lE_Velocity_4->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tTarget Velocity: %5.3f",Vt);

           double TAA=ui->lE_tGT_AA_4->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tTarget Aspect Angle: %5.3f",TAA);

           double R=ui->lE_rTGT_4->text().toDouble();
           fprintf(Autolaunch_file,"\n\t\tRange of Target: %5.3f",R);


       }



       if((lotdflag==1) ||(lotdflag==2) ||(lotdflag==3) ||(lotdflag==4))
       //   ((ui->cb_astra_rvvae->currentText()=="ASRM1")||(ui->cb_astra_rvvae->currentText()=="ASRM2")||(ui->cb_astra_rvvae->currentText()=="ASEM1")||(ui->cb_astra_rvvae->currentText()=="ASEM2")) )

       {

       //    if((ui->cb_astra_rvvae->currentText()=="ASRM1"))

       //    fprintf(Autolaunch_file,"\n\tAstra: MKI(With Rail Launcher)");

       //    if((ui->cb_astra_rvvae->currentText()=="ASRM2"))

       //    fprintf(Autolaunch_file,"\n\tAstra: MKII(With Rail Launcher)");

       //}
           union time
           {
               int time_total;
              unsigned short int time_data[2];
           };

          union time mlp_time;

          //fprintf(Surv7File,"\n");

           mlp_time.time_data[0] = mslp_res_data[20];
           mlp_time.time_data[1] = mslp_res_data[19];

           float mlp_time1 = float(mlp_time.time_total);
           mlp_time1=mlp_time1/1000;
//           fprintf(DLZ_file,"%f   ",mlp_time1);
//           fprintf(DLZ_file ,"\t%u \t%u \t%u \t%5.3f \t%u \t%u \t%u",Dmax1,Dmax2,Dmin,IRT_range,tlt,tla,tln);
//           //fprintf(Autolaunch_file,"\n\tMLP Time:%5.3f",mlp_time1);

        //   fprintf(DLZ_file,"\n");

       }

       if((mlp_time1>175) && (ui->mis_rdy->text()=="OK") && (Readyflag==0))
       {
           Readyflag=1;

           fprintf(Autolaunch_file,"\n\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t\t\t\t\t\tASTRA Ready for Launch: YES ");

               fprintf(Autolaunch_file,"\n\t  --------DLZ Parameters--------- ");
               fprintf(Autolaunch_file,"\n\t\t Dmax1:%u",Dmax1);
               fprintf(Autolaunch_file,"\n\t\t Dmax2:%u",Dmax2);
               fprintf(Autolaunch_file,"\n\t\t Dmin:%u",Dmin);
               fprintf(Autolaunch_file,"\n\t\t IRT: %5.3f",IRT_range);
               fprintf(Autolaunch_file,"\n\t\t tlt:%u",tlt);
              // fprintf(Autolaunch_file,"\n\t\t tat:%u",tat);
               fprintf(Autolaunch_file,"\n\t\t tla:%u",tla);
               fprintf(Autolaunch_file,"\n\t\t tln:%u",tln);
               fprintf(Autolaunch_file,"\n\t  ------------------------------ ");

       }

//       if((mlp_time1 >= 250) && (mlp_time1 <= 500))
//       {
//           qDebug()<<"Mlptime: "<<mlp_time1<<"boost_fire 1:"<<boost_fire;
//       }


       //QString lanuch1_sts=ui->lanuch1_sts->text();
       //qDebug()<<"lanuch1_sts"<<lanuch1_sts;

       //for (L1flag=0;L1flag<=5;L1flag++)
       //{
       if((mlp_time1>160) &( ui->lanuch1_sts->text()=="Issued ") & (L1flag==0))
       {
           QString lanuch1_sts=ui->lanuch1_sts->text();
         //  qDebug()<<"lanuch1_sts1"<<lanuch1_sts;
           L1flag=1;
           qDebug()<<"L1flag"<<L1flag;

           fprintf(Autolaunch_file,"\n  --------AUTOLAUNCH--------- ");
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  Launch 1 : ON ");

       }

       //}

       //launch1= mslp_res_data[16] & 0x0400;
       //if((launch1==0x0400) & (L1flag==0))
       //{
       //     qDebug()<<"launch1"<<L1flag;
       //    L1flag=1;
       //    qDebug()<<"L1flag"<<L1flag;
       //    //fprintf(Autolaunch_file,"\n\t\t  Launch 1 : ON ");
       //}
       //for(L2flag=3;L2flag<=5;L2flag++)
       //{
       if((mlp_time1>160)&( ui->lanuch2_sts->text()=="Issued ") & (L2flag==0) )//&(ui->->text()=="  HP")& (L2flag==0))
       {
           QString lanuch2_sts=ui->lanuch2_sts->text();
           qDebug()<<"lanuch2_sts"<<lanuch2_sts;
           L2flag=1;
         //qDebug()<<"L2flag"<<L2flag;
           //L2flag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  Launch 2 : ON ");


       }

       if((mlp_time1>200) & ( ui->ready_sts->text()=="ON") & (Readyrelay==0))
       {
            Readyrelay=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  Ready relay : ON ");

       }

       //}

   //    if( (mlp_time1>160)&( ui->unguid_lanuch->text()=="Issued ") &  (unguided_Lflag==0) )
   //    {
   //        QString unguid_lanuch=ui->unguid_lanuch->text();
   //        qDebug()<<"lanuch2_sts"<<unguid_lanuch;
   //        unguided_Lflag=1;
   //      //qDebug()<<"L2flag"<<L2flag;
   //        //L2flag=1;
   //        fprintf(Autolaunch_file,"\nMLP Time:%5.3f\n",mlp_time1);
   //        fprintf(Autolaunch_file,"\t\tUnguided launch : Issued ");


   //    }
     //   qDebug()<<"Mlptime: "<<mlp_time1<<"boost_fire2:"<<boost_fire;

       if((mlp_time1>270) & (ui->boost_fire->text()=="BSTON") & (Boosterflag==0))
       {
         // QString boost_fire=ui->boost_fire->text();
        //  qDebug()<<"Mlptime: "<<mlp_time1<<"boost_fire2:"<<boost_fire;
           Boosterflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  Booster : ON");

       }
       /*
        else
        {
          if(mlp_time1>265)
          {
           // QString boost_fire1=ui->boost_fire->text();
          //  Boosterflag=1;
            fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
            fprintf(Autolaunch_file,"\t\t  Booster : OFF : %d",boost_fire);
          }

        }
        */
       if((mlp_time1>200) &( ui->ltb_fire->text()=="ON") & (Ltbflag==0))
       {
         //  QString ltb_fire1=ui->ltb_fire->text();
          // qDebug()<<"Mlptime: "<<mlp_time1<<"LTB: "<<ltb_fire;
           Ltbflag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  LTB : ON ");
      }


       if(( ui->tel_sts->text()=="ON") & (rpfflag==0))
       {
           rpfflag=1;
           //fprintf(Autolaunch_file,"\n\t\t  RPF relay : ON ");

       }

       if(( ui->scu_sts->text()=="ON") & (actflag==0))
       {
           actflag=1;
           //fprintf(Autolaunch_file,"\n\t\t  Actuator relay : ON ");

       }

       if(( ui->elec_subsys_sts->text()=="ON") & (eleflag==0))
       {
           eleflag=1;
           //fprintf(Autolaunch_file,"\n\t\t  Actuator relay : ON ");

       }

       if(( ui->seekr_htr_sts->text()=="ON") & (seekhtflag==0))
       {
           seekhtflag=1;
           //fprintf(Autolaunch_file,"\n\t\t  Seeker Heater relay : ON ");

       }

       if((ui->seekr_elec_sts->text()=="ON") & (seekeleflag==0))

       {
           seekeleflag=1;
           //fprintf(Autolaunch_file,"\n\t\t  Seeker Elec. relay : ON ");

       }

       if((ui->seekr_tx_sts->text()=="ON") & (seekTxflag==0))
       {
           seekTxflag=1;
           //fprintf(Autolaunch_file,"\n\t\t  Seeker Tx relay : ON ");

       }

       if ((ui->DLTx_mask->text()=="HP") & (ui->dlpmode_Req_Ldt->text()=="YES")& (HP_flag==0) )
       {
           HP_flag=1;
           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  DLT HighPower");

       }
       //for(mlp_time1=0;mlp_time1<=181;mlp_time1++)
       //{
       if ((ui->DLTx_mask->text()=="LP") & (ui->mis_rel->text()=="Released") &(LP_flag==0) )
       {
           LP_flag=1;

           fprintf(Autolaunch_file,"\n%5.3f",mlp_time1);
           fprintf(Autolaunch_file,"\t\t  DLT in LP after 180 sec");

       }

       //---------------------------------NOGO--------------------------------------------


       //if(nogoflag>0)
       //{
       if((ui->lineEdit_6->text()=="AMLP PBIT NOT OK") &(nogoflag==0))
       {   nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO1: AMLP PBIT NOT OK ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="WCS DIP FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO2: AMLP PBIT NOT OK ");
           fprintf(Autolaunch_file,"\n\t***************************END**********************************");
       }

       if((ui->lineEdit_6->text()=="OBC PBIT FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO3: WCS Initial DIP Status(FB1,FB2&HEM)are not in expected state ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="DLTx INIT/Health FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO4: OBC PBIT Failure ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="DLRx INIT/Health FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO5: DLTx initialization/Health failure ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }



       if((ui->lineEdit_6->text()=="DL LOOPCHECK FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO6: DLR loop check failure ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="MSL HEALTH FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO7: Missile Subsystem Health failure ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="NO MINS DATA ") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO8: No MINS data available to AMLP till PBIT completion ");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="TA RESPONSE FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO9: TA Response failure(5 secs after TA command issued)");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="NOMINS TO INS(3Sec) FAIL") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO10: MINS data not recieved for 3 secs after TA command issued )");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="OBC TIME FROZEN") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO11: OBC time frozen for 5 samples consecutively(time out for 3 sec)");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="MISSILE SUBSYSTEM FAIL AFTER PBIT") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO12: Missile subsystem failure in prelaunch");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="MLP- OBC Communication Fail") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO13: MLP OBC communication fail(Timeout 2 sec)");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="No valid MINS data available to AMLP") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO14: No valid MINS data available to AMLP");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="AMLP-NO MODE") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO15: AMLP-NO MODE");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="RLT Status NOT OK") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO101: RLT status NOT OK");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

       if((ui->lineEdit_6->text()=="Actuator Null Status NOT OK") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO102: Actuator NULL Status NOT OK");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }
       if((ui->lineEdit_6->text()=="NAV Status NOT OK") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO103: NAV Status NOT OK");
           fprintf(Autolaunch_file,"\n\n\t***************************END***********************************");
       }
       if((ui->lineEdit_6->text()=="MSL HLT NOT OK after External OFF") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO104: Missle Health NOT OK after external OFF");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }
       if((ui->lineEdit_6->text()=="ACTUATOR NOT OK after External OFF") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\tNOGO105: Actuator voltages NOT OK after external OFF");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }
       if((ui->lineEdit_6->text()=="DLTx Hp Health NOT OK") &(nogoflag==0))
       {
           nogoflag=1;
           fprintf(Autolaunch_file,"\n\n\t\t  NOGO108: Actuator voltages NOT OK after external OFF");
           fprintf(Autolaunch_file,"\n\t***************************END***********************************");
       }

     }




