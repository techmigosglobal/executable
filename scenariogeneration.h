#ifndef SCENARIOGENERATION_H
#define SCENARIOGENERATION_H

#endif // SCENARIOGENERATION_H
double HS,VS,HT,VT,R,Ri,Azti,Elti,Vnti,Vupti,Veti,Vti,Hti,TAAi,Vci,Latsi,Longsi,Hsi,Vnsi,Vesi,Vupsi,Vsi;
double delt,Res,Rns,Rups;
unsigned short  TAA,SAA,SCA,TargetSim, Target;
double XS_ECEFi,YS_ECEFi,ZS_ECEFi;
void senariogeneration();
int proc_15sgnf(int, int,int);
void Geodetic2ECEF(double,double,double);
