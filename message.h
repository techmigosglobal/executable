#ifndef MESSAGE_H
#define MESSAGE_H


class message
{
public:
    message();
};

#include "stdio.h"
#include "stdemace.h"
#define cdr 0.017453292519943295769236907684886

//unsigned int i;
double number;
unsigned int bnr1Number;
double dNumber,integerPart,fractionalPart;
long bc2Number;
double absFraction;
int bc1Number;
extern U16BIT wTTvalue;
// INU-01 message variables
extern unsigned int CHK_INSTAL, TIME_TAG;
unsigned int SWINU1, VWINU1;
double GAMAX, GAMAY, GAMAZ, OMEGAX, OMEGAY, OMEGAZ,time_tag;
double ROLL_INS, PITCH_INS, THEAD_INS, VN_INS, VE_INS, Vup_INS,status_word,validity_word;
double PWR_TIME, LAT_INS, LON_INS, ZBI, MHEAD_INS, MAGN_DEV;
long bc2VnIns, bc2VeIns, bc2VupIns, bc2LatIns, bc2LonIns,bc2Vup;

// INU-02 message variables
extern unsigned int TIME_SAT, DATE_SAT;
unsigned  int SWINU2, VWINU2,NB_SAT;
double VN_SAT, VE_SAT, Vup_SAT, LAT_SAT, LON_SAT, ALT_SAT, TIME_SAT_SEC, PDOP,kam_time;

long bc2VnSat, bc2VeSat, bc2VupSat, bc2LatSat, bc2LonSat, bc2TimeSat;
int secs, hrs, mins, day, month, year;

// INU-03 message variables

unsigned short int SWINU3, VWINU3;
double	POS_ERR, ROLL, PITCH, THEAD, MHEAD, VN, VE, Vup, LAT, LON, ALT,pos_err;
long bc2Vn, bc2Ve, bc2Lat, bc2Lon;
double ttag;

// INU-04 message variables
unsigned int SWINU4, VWINU4;
double POS_TIMETAG;
double dData;

//extern FILE *inu01Fp, *inu02Fp, *inu03Fp, *inu04Fp;
#endif // MESSAGE_H
