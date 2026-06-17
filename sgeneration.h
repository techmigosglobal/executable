#ifndef SGENERATION_H
#define SGENERATION_H

#include<math.h>
#include<QDebug>
#define deg2rad  (M_PI/180.0)
#define rad2deg  57.29577951308232
#define cosd(x) cos(x*M_PI/180.0)
#define sind(x) sin(fmod(x,360)*M_PI/180.0)
//#define cosd(x) cos(x*57.29577951308232)
//#define sind(x) sin(x*57.29577951308232)
#define eps  2.22*pow(10,-16)
#define SamplesNum = 20000;
#define hypot(x,y) sqrt((x*x)+(y*y))
#define bitshift(x,y) (x<<y)
#define bitad(x,y) x&y
#define npi2pi(x) ((x<=0)? x :(x<=180)? x:(x-360))

class sgeneration
{
public:
    sgeneration();
    ~sgeneration();
    int Hs,Vs,Vt,TAA,R,SAA,SCA,TargetSim,Target;
    double  Ri, Azti,Elti,Vnti,Vupti,Vedi,Veti,Vti,Hti,TAAi,Vci,Latsi,Longsi,Hsi,Vnsi,Vesi,Vupsi,Vsi,sigmai,Ht;
    double delt,Res,Rns,Rups,Rnt,Ret,Rupt,XS_ECEFi,YS_ECEFi,ZS_ECEFi,Rni,Rei,Rupi,Vndi,Vupdi,Ri2;
    double  deles,delns,delups;
    unsigned short inc;
    FILE *file_rcw,*file_mcw;

    typedef struct A33
    {
        double ARRY33[3][3];
    }arry33;
    arry33 CENU2ECEF;
    unsigned int  Word_MC[32];
    unsigned int  Word_RC[32];
    unsigned int  Word_LOTD[32];

    typedef struct A31
    {
        double ARRY31[3][1];
    }arry31;
    arry31 ECEF;
    typedef struct Poisition
    {
        double lat;
        double lon;
        double alt;
    }position;
    position psn;


    typedef struct values2
    {
        int value1;
         int  value2;
    }values2;
    values2 r2value;
    arry33 DCMENU2ECEF(double,double);
    arry31 Geodetic2ECEF(double,double,double);
    position ECEFtoLatLongAlt(double,double,double);
    values2 proc_19sgnf(double, double);
    values2 proc_28sgnf(double,double);
    unsigned short   proc_15sgnf(double,double);
    void iNputSgeneration();
    void generationscenario();
//    double npi2pi(double);
};

#endif // SGENERATION_H

/*
%Input Data:
%Hs - Shooter height
%Vs - Shooter velocity
%Ht - Target height
%Vt - Target velocity
%TAA - Target Aspect Angle
%R - Range to Target
%SAA - Shooter Aspect Angle
%SCA - Shooter Climb Angle
*/

