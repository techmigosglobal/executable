#ifndef MCVARIABLES
#define MCVARIABLES
#include "stdio.h"
#include "stdemace.h"


U16BIT retValue =0;

char szBuffer[100];
U16BIT wRT,wTR1,wTR2,wSA,wWC;

/***********MC-RC Parameters

char s[32] ,buf[80];
extern U16BIT i;
S16BIT aOpCodes[10]     = { 0x0000 };
U32BIT dwHBufLost       = 0x0000;
U32BIT dwMsgLostStk = 0x0000;
S16BIT dwCurCount       = 0x0000;
MSGSTRUCT   sMsg;
S16BIT	nResult = 0,wResult = 0;
U16BIT rBuffer[32],wBuffer[32];
U32BIT dwMsgCount;
HWVERSIONINFO structHWVersionInfo;
********/
S16BIT  DevNumBC ,DevNumRT;
extern double GAMAX, GAMAY, GAMAZ, OMEGAX, OMEGAY, OMEGAZ;
extern double ROLL_INS, PITCH_INS, THEAD_INS, VN_INS, VE_INS, Vup_INS,time_tag;
extern double PWR_TIME, LAT_INS, LON_INS, ZBI, MHEAD_INS, MAGN_DEV;
extern long bc2VnIns, bc2VeIns, bc2VupIns, bc2LatIns, bc2LonIns,bc2Vup;
extern double VN_SAT, VE_SAT, Vup_SAT, LAT_SAT, LON_SAT, ALT_SAT, TIME_SAT_SEC, PDOP;
extern long bc2VnSat, bc2VeSat, bc2VupSat, bc2LatSat, bc2LonSat, bc2TimeSat;
extern int secs, hrs, mins, day, month, year;
unsigned int CHK_INSTAL,TIME_TAG,TIME_TAG3;
extern double POS_ERR, ROLL, PITCH, THEAD, MHEAD, VN, VE, Vup, LAT, LON, ALT;
extern long bc2Vn, bc2Ve, bc2Lat, bc2Lon;
extern double ttag;
double ttag3;
unsigned int pitch_roll3,true_head3,magnetic_head3,hybrid_speed_3,hybrid_horiz_coord_3,hybrid_alt_3,gost_op3,computer3,nav_sts3,align_sts3,test_sts3,select_sat3,sat_sts3,run_sat_sys3,sigma3,inertial_blk3,gps_glonass3,analog_discrete3,hybrid_pos_err_3;
unsigned int TIME_SAT,DATE_SAT,time_sat,time_sat1,time_sat2,time_sat3,glonass_sat,gps_sat;
unsigned int sat_alt_2,sat_time_2,sat_date_2,sat_sts_2,sat_horiz_coord_2,sat_speed_2,gost_op2,computer2,nav_sts2,align_sts2,test_sts2,select_sat2,sat_sts2,run_sat_sys2,sigma2,inertial_blk2,gps_glonass2,analog_discrete2;
unsigned short instal_chksum1,pwr_on_time1,baro_inertial_alt1,inertial_horiz_coord1,inertial_speed1,alt_body_rate1,acceleration_1,pitch_roll1,true_head1,magnetic_head1,magnetic_dev1,gost_op1,computer1,nav_sts1,align_sts1,test_sts1,select_sat1,sat_sts1,run_sat_sys1,sigma1,inertial_blk1,gps_glonass1,analog_discrete1;

/*****  1553 Data Format Encoding Conversion Functions  *****/
int DoubletoBC1(double, double, int);
long DoubletoBC2(double, double, int);
unsigned int DoubletoBNR1(double, double);
double BC1toDouble(int, double, int);
double BC2toDouble(long, double, int);
double BNR1toDouble(unsigned int, double);
double proc_1553_16sgnf(unsigned int, double);
double proc_1553_15sgnf(unsigned int, double);

void ScheduleINU_01RtMsg(unsigned short dataBuff[32],MSGSTRUCT *pMsg);
void ScheduleINU_02RtMsg(unsigned short dataBuff[32]);
void ScheduleINU_03RtMsg(unsigned short dataBuff[32],MSGSTRUCT *pMsg);
void getMinsData(FILE *);
void GetINU_01Parameters(unsigned short[]);
void GetINU_02Parameters(unsigned int[]);
void GetINU_03Parameters(unsigned short[]);
static void PrintOutError(S16BIT nResult);

U16BIT decodeMsg(U32BIT nMsgNum,MSGSTRUCT *pMsg,U16BIT rBuf[]);
//FILE *fpIn10msData = fopen("AUTOLAUNCH_MC_HYBRID.txt", "r");
//FILE *fpIn10msData = fopen("FILE10.DAT", "r");

//MIL_MC_HYBRID_1

//FILE *TxFile = fopen("outTxData.txt","a");
//FILE *inu01Fp = fopen("inu01.txt","w+");
//FILE *inu02Fp = fopen("inu02.txt","w+");
//FILE *inu03Fp = fopen("inu03.txt","w+");
//FILE *inu04Fp = fopen("inu04.txt","w+");
//FILE *RxFile = fopen("outRxData.txt","a");


#endif // MCVARIABLES

