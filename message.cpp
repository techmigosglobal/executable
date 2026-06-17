/********************************************************************
        Created		:	November 2014
        File Name	:	message.cpp
        Author		:	DNEC, RCI, Hyderabad - 500069

        Purpose		:

*********************************************************************/

#include <stdio.h>
#include <math.h>
#include "message.h"
#include "ta_bias.h"
#include<QDebug>
int ta_bias=0;
unsigned short int gwMcRawData[32];

/*****  1553 Data Format Encoding Conversion Functions  *****/
int DoubletoBC1(double number, double lsb, int numBits)
{
    dNumber = number/lsb;
    fractionalPart = modf(dNumber,&integerPart);
    absFraction = fabs(fractionalPart);

    if(integerPart>0.0 && absFraction>=0.5)
        bc1Number = (int)ceil(dNumber);
    else if(integerPart>0.0 && absFraction<0.5)
        bc1Number = (int)floor(dNumber);
    else if(integerPart<0.0 && absFraction<0.5)
        bc1Number = (int)ceil(dNumber);
    else
        bc1Number = (int)floor(dNumber);

    bc1Number = bc1Number << (15 - numBits);
    return bc1Number;
}

long DoubletoBC2(double number, double lsb, int numBits)
{
    dNumber = number/lsb;
    fractionalPart = modf(dNumber,&integerPart);
    absFraction = fabs(fractionalPart);

    if(integerPart>0.0 && absFraction>=0.5)
        bc2Number = (long)ceil(dNumber);
    else if(integerPart>0.0 && absFraction<0.5)
        bc2Number = (long)floor(dNumber);
    else if(integerPart<0.0 && absFraction<0.5)
        bc2Number = (long)ceil(dNumber);
    else
        bc2Number = (long)floor(dNumber);

    bc2Number = bc2Number << (31 - numBits);
    return bc2Number;
}

unsigned int DoubletoBNR1(double number, double lsb)
{
    dNumber = number/lsb;
    fractionalPart = modf(dNumber,&integerPart);

    if(fractionalPart >= 0.5)
        bnr1Number = (unsigned int)ceil(dNumber);
    else
        bnr1Number = (unsigned int)floor(dNumber);

    return bnr1Number;
}

double BC1toDouble(int bc1Number, double lsb, int numBits)
{
    bc1Number = bc1Number >> (15 - numBits);
    number = (double)(bc1Number * lsb);

    return number;
}

double BC2toDouble(long bc2Number, double lsb, int numBits)
{
    bc2Number = bc2Number >> (31 - numBits);
    number = (double)(bc2Number * lsb);

    return number;
}

double BNR1toDouble(unsigned int bnr1number, double lsb)
{
    number = (double)(bnr1number * lsb);

    return number;
}
double proc_1553_16sgnf(unsigned int bnr1number, double lsb){
    number=double(bnr1number);
    number=number*lsb;
return number;
}
double proc_1553_15sgnf(unsigned int bnr1number, double lsb){
    int temp;
    if((bnr1number&0x8000)== 0x8000)
       temp  =bnr1number-65536;
    else
        temp=bnr1number;
    number=temp*lsb;
return number;
}

void getMinsData(FILE *fpIn10msData)
{
    //t  fscanf(fpIn10msData, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&kam_time,&time_tag, &status_word, &validity_word,&ROLL_INS,&PITCH_INS,&THEAD_INS,&MHEAD_INS, &VN_INS,&VE_INS, &Vup_INS,&LAT_INS,&LON_INS, &ZBI,&pos_err);
#ifdef MC_ENG_DATA

    fscanf(fpIn10msData, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &time_tag ,&LAT_INS , &LON_INS, &ZBI, &VN_INS, &VE_INS, &Vup_INS,&ROLL_INS,&PITCH_INS,&THEAD_INS);
    //&ROLL_INS, &PITCH_INS, &THEAD_INS);
    //%  time(sec) , latitude (deg) , longitude (deg), altitude(m), vnshooter(m/s), veshooter(m/s), vushooter(m/s)
    LAT_INS = LAT_INS / cdr;  //To Degrees
    LON_INS = LON_INS / cdr;
    Vup_INS = Vup_INS;

    //Vup_INS = -Vup_INS;

    //  VWINU1 = 0x07FF;
    //  SWINU3 = 0x36c0;
    //t  SWINU3=status_word;
    //t SWINU1=status_word;
    //t SWINU2=status_word;
    //  VWINU3 = 0xFE00;
    //t  VWINU3= validity_word;
    //t VWINU1= validity_word;
    //t VWINU4 = 0x000F;

    //  if(THEAD_INS>180.0)
    //   THEAD_INS= THEAD_INS-360.0;

    //  MHEAD_INS = THEAD_INS;

    //t MHEAD=MHEAD_INS;
    ROLL_INS = ROLL_INS;
    PITCH_INS = PITCH_INS;

    ROLL = ROLL_INS;
    PITCH = PITCH_INS;

    THEAD = THEAD_INS;
    if(ta_bias==1)
    {
VN=10;
VE=10;
Vup=10;
    }
    else
    {
    VN = VN_INS;
    VE = VE_INS;
    Vup = Vup_INS;
    }
    LAT = LAT_INS;
    LON = LON_INS;
    ALT = ZBI;
    // POS_ERR=pos_err;


    // printf(" file reading %lf LAT:%lf LONG:%lf ZBI: %lf  %lf %lf %lf %lf %lf %lf\n",dData, LAT_INS, LON_INS, ZBI, VN_INS,VE_INS, Vup_INS,ROLL_INS, PITCH_INS, THEAD_INS);
    printf(" file reading %lf LAT:%lf LONG:%lf ZBI: %lf VN: %lf VE:%lf Vup: %lf ROLL:%lf PITCH: %lf THEAD:%lf\n",time_tag ,LAT_INS ,LON_INS, ZBI,VN_INS,VE_INS, Vup_INS,ROLL_INS,PITCH_INS,THEAD_INS);
#else

#endif /**/
    float fkamTime;
    fscanf(fpIn10msData, "%f", &fkamTime);

    for (int j=0; j<18; j++)
        fscanf(fpIn10msData,"%d\n", &gwMcRawData[j]);
    //printf("file data: \t %f %04x %04x %04x \n",fkamTime,gwMcRawData[0],gwMcRawData[1],gwMcRawData[2]);

//    if(feof(fpIn10msData))
//    {
//        printf("end of MC Data file\n");
//        qDebug()<<"mc file ends";
//        rewind(fpIn10msData);
//    }
}

void ScheduleINU_01RtMsg(unsigned short dataBuff[32],MSGSTRUCT *pMsg)
{


    //  dataBuff[0] = DoubletoBNR1(pMsg->wTimeTag,0.064);
    dataBuff[0]=  DoubletoBNR1(time_tag,0.064);
    dataBuff[1] = SWINU1;
    dataBuff[2] = VWINU1;
    dataBuff[3] = DoubletoBC1(GAMAX, 0.0039, 15);
    dataBuff[4] = DoubletoBC1(GAMAZ, 0.0039, 15);
    dataBuff[5] = DoubletoBC1(GAMAY, 0.0039, 15);
    dataBuff[6] = DoubletoBC1(OMEGAX, 0.01562, 15);
    dataBuff[7] = DoubletoBC1(OMEGAZ, 0.01562, 15);
    dataBuff[8] = DoubletoBC1(OMEGAY, 0.01562, 15);
    dataBuff[9] = DoubletoBC1(ROLL_INS, 0.011, 14);
    dataBuff[10] = DoubletoBC1(PITCH_INS, 0.011, 14);
    dataBuff[11] = DoubletoBC1(THEAD_INS, 0.055, 15);

    bc2VnIns = DoubletoBC2(VN_INS, 0.0032, 19);
    bc2VeIns = DoubletoBC2(VE_INS, 0.0032, 19);
    bc2VupIns = DoubletoBC2(Vup_INS, 0.0032, 19);
    dataBuff[12] = (bc2VnIns >> 16) & 0x0000FFFF;
    dataBuff[13] = bc2VnIns & 0x0000FFFF;
    dataBuff[14] = (bc2VeIns >> 16) & 0x0000FFFF;
    dataBuff[15] = bc2VeIns & 0x0000FFFF;
    dataBuff[16] = (bc2VupIns >> 16) & 0x0000FFFF;
    dataBuff[17] = bc2VupIns & 0x0000FFFF;

    bc2LatIns = DoubletoBC2(LAT_INS, 90/pow(2.0,27), 28);
    bc2LonIns = DoubletoBC2(LON_INS, 90/pow(2.0,27), 28);
    dataBuff[18] = (bc2LatIns >> 16) & 0x0000FFFF;
    dataBuff[19] = bc2LatIns & 0x0000FFFF;
    dataBuff[20] = (bc2LonIns >> 16) & 0x0000FFFF;
    dataBuff[21] = bc2LonIns & 0x0000FFFF;

    dataBuff[22] = DoubletoBC1(ZBI, 1.0, 15);
    dataBuff[23] = DoubletoBC1(MHEAD_INS, 0.0055, 15);
    dataBuff[24] = DoubletoBC1(MAGN_DEV, 0.0055, 15);
    dataBuff[25] = DoubletoBNR1(PWR_TIME, 1.0);

    for (int i=0, CHK_INSTAL = 0x0000; i<26; i++)
        CHK_INSTAL += dataBuff[i];

    dataBuff[26] = CHK_INSTAL;
    for (int i=27; i<32; i++)
        dataBuff[i] = 0x0000;

 memcpy(dataBuff, gwMcRawData, 36);

}

void ScheduleINU_02RtMsg(unsigned short dataBuff[32])
{
    for (int i=0; i<32; i++)
        dataBuff[i] = 0x0000;
}

void ScheduleINU_03RtMsg(unsigned short dataBuff[32],MSGSTRUCT *pMsg)
{
    //  dataBuff[0] = DoubletoBNR1(pMsg->wTimeTag,0.064);
    dataBuff[0]=DoubletoBNR1(time_tag,0.064);
    dataBuff[1] = SWINU3;
    dataBuff[2] = VWINU3;
    dataBuff[3] = DoubletoBC1(ROLL,0.011, 14);
    dataBuff[4] = DoubletoBC1(PITCH, 0.011, 14);
    dataBuff[5] = DoubletoBC1(THEAD, 0.0055, 15);
    dataBuff[6] = DoubletoBC1(MHEAD,0.0055, 15);

    bc2Vn = DoubletoBC2(VN, 0.0032, 19);
    bc2Ve = DoubletoBC2(VE, 0.0032, 19);
    dataBuff[7] = (bc2Vn >> 16) & 0x0000FFFF;
    dataBuff[8] = bc2Vn & 0x0000FFFF;
    dataBuff[9] = (bc2Ve >> 16) & 0x0000FFFF;
    dataBuff[10] = bc2Ve & 0x0000FFFF;
    dataBuff[11] = DoubletoBC1(Vup, 0.0514, 15);

    bc2Lat = DoubletoBC2(LAT, 90/pow(2.0,27), 28);
    bc2Lon = DoubletoBC2(LON, 90/pow(2.0,27), 28);
    dataBuff[12] = (bc2Lat >> 16) & 0x0000FFFF;
    dataBuff[13] = bc2Lat & 0x0000FFFF;
    dataBuff[14] = (bc2Lon >> 16) & 0x0000FFFF;
    dataBuff[15] = bc2Lon & 0x0000FFFF;
    dataBuff[16] = DoubletoBC1(ALT, 1.0, 15);
    dataBuff[17] = DoubletoBNR1(POS_ERR, 1.0);
    for (int i=18; i<32; i++)
        dataBuff[i] = 0x0000;

    memcpy(dataBuff, gwMcRawData, 36);
}

void GetINU_01Parameters(unsigned short dataBuff[32])
{
    ttag = BNR1toDouble(dataBuff[0], 0.064);
    SWINU1 = dataBuff[1];
    VWINU1 = dataBuff[2];
    GAMAX = BC1toDouble(dataBuff[3], 0.0039, 15);
    GAMAZ = BC1toDouble(dataBuff[4], 0.0039, 15);
    GAMAY = BC1toDouble(dataBuff[5], 0.0039, 15);
    OMEGAX = BC1toDouble(dataBuff[6], 0.01562, 15);
    OMEGAZ = BC1toDouble(dataBuff[7], 0.01562, 15);
    OMEGAY = BC1toDouble(dataBuff[8], 0.01562, 15);
    ROLL_INS = BC1toDouble(dataBuff[9], 0.011, 14);
    PITCH_INS = BC1toDouble(dataBuff[10], 0.011, 14);
    THEAD_INS = BC1toDouble(dataBuff[11], 0.055, 15);

    bc2Vn = dataBuff[12];
    bc2Vn = ((bc2Vn & 0x0000FFFF) << 16) | dataBuff[13];
    VN_INS = BC2toDouble(bc2Vn,0.0032, 19); //0.0032);
    bc2Ve = dataBuff[14];
    bc2Ve = ((bc2Ve & 0x0000FFFF) << 16) | dataBuff[15];
    VE_INS = BC2toDouble(bc2Ve,0.0032, 19); //0.0032);
    bc2Vup = dataBuff[16];
    bc2Vup = ((bc2Vup & 0x0000FFFF) << 16) | dataBuff[17];
    Vup_INS = BC2toDouble(bc2Vup,0.0032, 19); //0.0032);

    bc2Lat = dataBuff[18];
    bc2Lat = ((bc2Lat & 0x0000FFFF) << 16) | dataBuff[19];
    LAT_INS = BC2toDouble(bc2Lat, 90/pow(2.0,27), 28);
    bc2Lon = dataBuff[20];
    bc2Lon = ((bc2Lon & 0x0000FFFF) << 16) | dataBuff[21];
    LON_INS = BC2toDouble(bc2Lon, 90/pow(2.0,27), 28);
    ZBI = BC1toDouble(dataBuff[22], 1.0, 15);
    MHEAD_INS = BC1toDouble(dataBuff[23], 0.0055, 15);
    MAGN_DEV = BC1toDouble(dataBuff[24], 0.0055, 15);
    PWR_TIME = BNR1toDouble(dataBuff[25], 1.0);
    CHK_INSTAL = dataBuff[26];

//    fprintf(inu01Fp,"%.0f\t0x%x\t0x%x\t%e\t%e\t%e\t",ttag, SWINU1, VWINU1, GAMAX, GAMAZ, GAMAY);
//    fprintf(inu01Fp,"%e\t%e\t%e\t%e\t%e\t%e\t",OMEGAX, OMEGAZ, OMEGAY, ROLL_INS, PITCH_INS, THEAD_INS);
//    fprintf(inu01Fp,"%e\t%e\t%e\t%e\t%e\t%e\t",VN_INS, VE_INS, Vup_INS, LAT_INS, LON_INS, ZBI);
//    fprintf(inu01Fp,"%e\t%e\t%e\t0x%x\n",MHEAD_INS, MAGN_DEV, PWR_TIME, CHK_INSTAL);
}

void GetINU_02Parameters(unsigned int dataBuff[32])
{
    SWINU2 = dataBuff[0];
    VWINU2 = dataBuff[1];

    bc2VnSat = dataBuff[2];
    bc2VnSat = ((bc2VnSat & 0x0000FFFF) << 16) | dataBuff[3];
    VN_SAT = BC2toDouble(bc2VnSat,842.865/pow(2.0,18), 19);

    bc2VeSat = dataBuff[4];
    bc2VeSat = ((bc2VeSat & 0x0000FFFF) << 16) | dataBuff[5];
    VE_SAT = BC2toDouble(bc2VeSat,842.865/pow(2.0,18), 19);

    bc2VupSat = dataBuff[6];
    bc2VupSat = ((bc2VupSat & 0x0000FFFF) << 16) | dataBuff[7];
    Vup_SAT = BC2toDouble(bc2VupSat,842.865/pow(2.0,18), 19);

    bc2LatSat = dataBuff[8];
    bc2LatSat = ((bc2LatSat & 0x0000FFFF) << 16) | dataBuff[9];
    LAT_SAT = BC2toDouble(bc2LatSat,90/pow(2.0,27), 28);

    bc2LonSat = dataBuff[10];
    bc2LonSat = ((bc2LonSat & 0x0000FFFF) << 16) | dataBuff[11];
    LON_SAT = BC2toDouble(bc2LonSat,90/pow(2.0,27), 28);

    ALT_SAT = BNR1toDouble(dataBuff[12], 1.0);
    TIME_SAT = dataBuff[13];
    TIME_SAT = ((TIME_SAT & 0x0000FFFF) << 16) | dataBuff[14];
    secs = (TIME_SAT >> 10) & 0x003F;
    mins = (TIME_SAT >> 21) & 0X003F;
    hrs = (TIME_SAT >> 27) & 0X001F;

    bc2TimeSat = dataBuff[15];
    bc2TimeSat = ((bc2TimeSat & 0x0000FFFF) << 16) | dataBuff[16];
    TIME_SAT_SEC = BC2toDouble(bc2TimeSat,9.54e-7, 31);

    DATE_SAT = dataBuff[17];
    day = DATE_SAT & 0x001F;
    month = (DATE_SAT >> 5) & 0x000F;
    year = (DATE_SAT >> 9) & 0x007F;

    PDOP = BNR1toDouble(dataBuff[18], 0.1);

    NB_SAT = dataBuff[19];

//    fprintf(inu02Fp,"0x%x\t0x%x\t%e\t%e\t%e\t", SWINU2, VWINU2, VN_SAT, VE_SAT, Vup_SAT);
//    fprintf(inu02Fp,"%e\t%e\t%e\t%d:%d:%d\t", LAT_SAT, LON_SAT, ALT_SAT, hrs, mins, secs);
//    fprintf(inu02Fp,"%f\t%d/%d/%d\t%.1f\t%d\t%d\n", TIME_SAT_SEC, day, month, year, PDOP, (NB_SAT>>8)&0x00FF, NB_SAT&0x00FF);
}

void GetINU_03Parameters(unsigned short dataBuff[32])
{
#ifdef MC_ENGG
    ttag = BNR1toDouble(dataBuff[0], 0.064);
    SWINU3 = dataBuff[1];
    VWINU3 = dataBuff[2];
    ROLL = BC1toDouble(dataBuff[3], 0.011, 14);
    PITCH = BC1toDouble(dataBuff[4], 0.011, 14);
    THEAD = BC1toDouble(dataBuff[5],  0.0055, 15);
    MHEAD = BC1toDouble(dataBuff[6],  0.0055, 15);

    bc2Vn = dataBuff[7];
    bc2Vn = ((bc2Vn & 0x0000FFFF) << 16) | dataBuff[8];
    VN = BC2toDouble(bc2Vn, 0.0032, 19);
    bc2Ve = dataBuff[9];
    bc2Ve = ((bc2Ve & 0x0000FFFF) << 16) | dataBuff[10];
    VE = BC2toDouble(bc2Ve, 0.0032, 19);
    Vup = BC1toDouble(dataBuff[11], 0.0514, 15);

    bc2Lat = dataBuff[12];
    bc2Lat = ((bc2Lat & 0x0000FFFF) << 16) | dataBuff[13];
    LAT = BC2toDouble(bc2Lat,90/pow(2.0,27), 28);
    bc2Lon = dataBuff[14];
    bc2Lon = ((bc2Lon & 0x0000FFFF) << 16) | dataBuff[15];
    LON = BC2toDouble(bc2Lon,90/pow(2.0,27), 28);
    ALT = BC1toDouble(dataBuff[16], 1.0, 15);
    POS_ERR = BNR1toDouble(dataBuff[17], 1.0);

    fprintf(inu03Fp, "%f\t%x\t%x\t%e\t%e\t%e\t", ttag, SWINU3, VWINU3, ROLL, PITCH, THEAD);
    fprintf(inu03Fp, "%e\t%e\t%e\t%e\t", MHEAD, VN, VE, Vup);
    fprintf(inu03Fp,"%e\t%e\t%.1f\t%.1f\n", LAT, LON, ALT, POS_ERR);
#else

    memcpy(dataBuff, gwMcRawData, 36);

#endif
}
