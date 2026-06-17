#ifndef SENARIOGENERATION_H
#define SENARIOGENERATION_H

class senariogeneration
{
public:
    senariogeneration();
float HS,VS,HT,VT,R,Ri,Azti,Elti,Vnti,Vupti,Veti,Vti,Hti,TAAi,Vci,Latsi,Longsi,Hsi,Vnsi,Vesi,Vupsi,Vsi;
float delt,Res,Rns,Rups;
unsigned short  TAA,SAA,SCA ;


int proc_15sgnf(int,int,int);
};

#endif // SENARIOGENERATION_H
