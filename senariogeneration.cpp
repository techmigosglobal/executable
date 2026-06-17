#include "senariogeneration.h"
#include<QDebug>
#define  deg2rad = (pi/180.0);
#define rad2deg = 57.29577951308232;
#define SamplesNum = 20000;

senariogeneration::senariogeneration()
{


    SAA = 0;          //  %in Deg
    SCA = 0;          //  %in Deg

    Ri   = 0.0;
    Azti = 0.0;
    Elti = 0.0;
    Vnti = 0.0;
    Vupti = 0.0;
    Veti = 0.0;
    Vti = 0.0;
    Hti = 0.0;
    TAAi = 0.0;
    Vci = 0.0;
    Latsi  = 18.5856136680;    // %Pune Latitude
    Longsi = 73.9182666689;    // %Pune Longitude
    Hsi = 0.0;
    Vnsi = 0.0;
    Vesi = 0.0;
    Vupsi = 0.0;
    Vsi = 0.0;



    if(Hs<0.0 || Hs>20.0)
    {
        qDebug()<<'Shooter Height is out of specified range of 0 to 20 km';
        return;
    }


    if(Ht<0.0 || Ht>20.0){
        qDebug()<<'Target Height is out of specified range of 0 to 20 km';
        return;
    }

    if(Vs<50.0 || Vs>650.0){
      qDebug()<<'Shooter Velocity is out of specified range of 0 to 650 m/s';
        return;
    }

    if(Vt<50.0 || Vt>650.0){
       qDebug()<<'Target Velocity is out of specified range of 0 to 650 m/s';
        return;
    }

    if(TAA<-180.0 || TAA>180.0){
        qDebug()<<'Target Aspect Angle is out of specified range of -180 to 180 Deg';
        return;
    }

    if(R<2.0 || R>200.0){
        qDebug()<<'Simulation start range is out of specified range of 2 to 200 km';
        return;
    }


    delt = 0.02;                //Simulation time interval, Delta_t = 20ms

    Res = 0.0;
    Rns = 0.0;
    Rups = 0.0;

    Vnti = -Vt*cosd(TAA)*0.001;

    Veti = -Vt*sind(TAA)*0.001;
    Vupti = 0.0;

    Vti = sqrt(Vnti*Vnti+Veti*Veti+Vupti*Vupti);

    Vnsi = Vs*0.001;
    Vesi = 0.0;
    Vupsi = 0.0;

    Vsi = sqrt(Vnsi*Vnsi+Vesi*Vesi+Vupsi*Vupsi);

    Hsi = Hs;
    Hti = Ht;
    Ri = R;

    TAAi = TAA;

    if (abs(Ri) < eps)
        Ri = eps;


    Elti = asin((Hti-Hsi)/Ri)*rad2deg; // %Snap-up Elevation angle is +ve

    Rnt  = Ri * cosd(Elti) * cosd(Azti);
    Ret  = Ri * cosd(Elti) * sind(Azti);
    Rupt = Ri * sind(Elti);

    TargetSim = 1;
    Target = 1;


    CENU2ECEF = DCMENU2ECEF(Latsi,Longsi);
    [XS_ECEFi,YS_ECEFi,ZS_ECEFi] = Geodetic2ECEF(Latsi,Longsi,Hsi);

    fid  = fopen('Scenario.txt','w');
    fid2 = fopen('Debug.txt','w');
    fprintf(fid,'%%time\t Range_t\t Azimuth_t\t Elevation_t\t Vn_t\t Ve_t\t Vup_t\t V_t\t H_t\t TAA\t Vc_t\t Latitude_s\t Longitude_s\t Alt_s\t Vn_s\t Ve_s\t Vup_s\t V_s\t Target_t\n');
    fprintf(fid2,'%%time\t\t\t Rei_t\t\t\t Rni_t\t\t\t Rupi_t\t\t\t Vedi\t\t\t Vndi\t\t\t Vupdi\t\t\t Vci\t\t\t Ri\t\t\t Res\t\t\t Rns\t\t\t Rups\t\t\t Ret\t\t\t Rnt\t\t\t Rupt\t\t\t Ri2\t\t\t Azti\t
            \t\t Elti\t\t\t sigmai\t\t\t TTAi\t\t\t deles\t\t\t delns\t\t\t delups\t\t\n');

            for (int i = 1; i< SamplesNum;i++)
    {
        time = i*delt;

        if(TargetSim == 1){
            if(abs(Elti)>70.0 || abs(Azti)>70.0){
                TargetSim = 0;
                Target = 0;
            }
        }

        switch TargetSim

                case 1,

                Rni  = Ri * cosd(Elti) * cosd(Azti);
        Rei  = Ri * cosd(Elti) * sind(Azti);
        Rupi = Ri * sind(Elti);

        Vedi  = -Vesi+Veti;
        Vndi  = -Vnsi+Vnti;
        Vupdi = -Vupsi+Vupti;

        Vci = (Rei*Vedi+Rni*Vndi+Rupi*Vupdi)/Ri;

        fprintf(fid,'%10.6f\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %12.8f\t\t %12.8f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t
                \t %10.6f\t\t %10.6f\t %5d\n',...
                time,Ri,Azti,Elti,Vnti,Veti,Vupti,Vti,Hti,TAAi,Vci,Latsi,Longsi,Hsi,Vnsi,Vesi,Vupsi,Vsi,Target);

        Ri = Ri+Vci*delt;

        Res  = Res+Vesi*delt;
        Rns  = Rns+Vnsi*delt;
        Rups = Rups+Vupsi*delt;

        Ret  = Ret+Veti*delt;
        Rnt  = Rnt+Vnti*delt;
        Rupt = Rupt+Vupti*delt;

        Ri2 = sqrt((Ret-Res)*(Ret-Res)+(Rnt-Rns)*(Rnt-Rns)+(Rups-Rupt)*(Rups-Rupt));

        if (abs(Ri) < eps)
            Ri = eps;


        Azti = atan2((Ret-Res),(Rnt-Rns))*rad2deg;
        Elti = asin((Hti-Hsi)/Ri)*rad2deg;

        sigmai = atan2(Veti,Vnti)*rad2deg;
        TAAi   = npi2pi((180-Azti)+sigmai);

        deles  = Vesi*delt*1000;
        delns  = Vnsi*delt*1000;
        delups = Vupsi*delt*1000;

        CENU2ECEF = DCMENU2ECEF(Latsi,Longsi);

        XS_ECEFi = CENU2ECEF(1,:) * [deles; delns; delups] + XS_ECEFi;
        YS_ECEFi = CENU2ECEF(2,:) * [deles; delns; delups] + YS_ECEFi;
        ZS_ECEFi = CENU2ECEF(3,:) * [deles; delns; delups] + ZS_ECEFi;

        //        % %             llai = ecef2lla([XS_ECEFi YS_ECEFi ZS_ECEFi]);
        //        % %
        //        % %             Latsi  = llai(1);
        //        % %             Longsi = llai(2);
        //        % %             Hsi    = llai(3);

        [Latsi,Longsi,Hsi] = ECEFtoLatLongAlt(XS_ECEFi,YS_ECEFi,ZS_ECEFi);

        fprintf(fid2,'%10.6f\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f
                \t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\n',...
                time,Rei,Rni,Rupi,Vedi,Vndi,Vupdi,Vci,Ri,Res,Rns,Rups,Ret,Rnt,Rupt,Ri2,Azti,Elti,sigmai,TAAi,deles,delns,delups);

        otherwise,

                deles  = Vesi*delt*1000;
        delns  = Vnsi*delt*1000;
        delups = Vupsi*delt*1000;

        CENU2ECEF = DCMENU2ECEF(Latsi,Longsi);

        XS_ECEFi = CENU2ECEF(1,:) * [deles; delns; delups] + XS_ECEFi;
        YS_ECEFi = CENU2ECEF(2,:) * [deles; delns; delups] + YS_ECEFi;
        ZS_ECEFi = CENU2ECEF(3,:) * [deles; delns; delups] + ZS_ECEFi;

        //        % %             llai = ecef2lla([XS_ECEFi YS_ECEFi ZS_ECEFi]);
        //        % %
        //        % %             Latsi  = llai(1);
        //        % %             Longsi = llai(2);
        //        % %             Hsi    = llai(3);

        [Latsi,Longsi,Hsi] = ECEFtoLatLongAlt(XS_ECEFi,YS_ECEFi,ZS_ECEFi);


        Ri    = 0.0;
        Azti  = 0.0;
        Elti  = 0.0;
        Vnti  = 0.0;
        Vupti = 0.0;
        Veti  = 0.0;
        Vti   = 0.0;
        Hti   = 0.0;
        TAAi  = 0.0;
        Vci   = 0.0;

        fprintf(fid,'%10.6f\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t\t %12.8f\t\t %12.8f\t\t %10.6f\t\t %10.6f\t\t %10.6f\t
                \t %10.6f\t\t %10.6f\t %5d\n',...
                time,Ri,Azti,Elti,Vnti,Veti,Vupti,Vti,Hti,TAAi,Vci,Latsi,Longsi,Hsi,Vnsi,Vesi,Vupsi,Vsi,Target);

        end

    }
    Dbg = load('Debug.txt');

    time   = Dbg(:,1);
    Rei    = Dbg(:,2);
    Rni    = Dbg(:,3);
    Rupi   = Dbg(:,4);
    Vedi   = Dbg(:,5);
    Vndi   = Dbg(:,6);
    Vupdi  = Dbg(:,7);
    Vci    = Dbg(:,8);
    Ri     = Dbg(:,9);
    Res    = Dbg(:,10);
    Rns    = Dbg(:,11);
    Rups   = Dbg(:,12);
    Ret    = Dbg(:,13);
    Rnt    = Dbg(:,14);
    Rupt   = Dbg(:,15);
    Ri2    = Dbg(:,16);
    Azti   = Dbg(:,17);
    Elti   = Dbg(:,18);
    sigmai = Dbg(:,19);
    TAAi   = Dbg(:,20);
    deles  = Dbg(:,21);
    delns  = Dbg(:,22);
    delups = Dbg(:,23);

    Rcalc = sqrt((Ret.*Ret)+(Rnt.*Rnt)+(Rupt.*Rupt));
    Rmax = round(max(Rcalc))+10;

//    figure('Name','Shooter-Target Profile');
//    subplot(1,2,1);plot(Res,Rns,'b*-',Ret,Rnt,'ro-');grid on;xlabel('East [km]');ylabel('North [km]');legend('Shooter','Target');xlim([-Rmax Rmax]);ylim([-Rmax Rmax]);axis('square');
//    subplot(1,2,2);plot(Rns,Rups,'b*-',Rnt,Rupt,'ro-');grid on;xlabel('North [km]');ylabel('Up [km]');legend('Shooter','Target');xlim([-Rmax Rmax]);ylim([0 25]);axis('square');

//    figure('Name','Range to Go Components');
//    plot(time,Rei,time,Rni,time,Rupi);grid on;xlabel('Time [s]');ylabel('Range [km]');legend('Re','Rn','Rup');

//    figure('Name','Range Info - Target');
//    plot(time,Ret,time,Rnt,time,Rupt);grid on;xlabel('Time [s]');ylabel('Shooter Displacement [km]');legend('Re','Rn','Rup');

//    figure('Name','Range Info - Shooter');
//    plot(time,Res,time,Rns,time,Rups);grid on;xlabel('Time [s]');ylabel('Shooter Displacement [km]');legend('Re','Rn','Rup');

//    figure('Name','Delta Velocity Info - Target');
//    plot(time,Vedi,time,Vndi,time,Vupdi);grid on;xlabel('Time [s]');ylabel('Velocity [km/s]');legend('Ves-Vet','Vns-Vnt','Vups-Vupt');

//    figure('Name','Closing Velocity');
//    plot(time,Vci,'b*-');grid on;xlabel('Time [s]');ylabel('Closing Velocity [km/s]');

//    figure('Name','Range to Go');
//    plot(time,Ri,'b*-',time,Ri2,'ro-');grid on;xlabel('Time [s]');ylabel('Range to Go [km]');legend('Computed using Vc','Computed using Range');

//    figure('Name','Polar Angles');
//    plot(time,Azti,'b*-',time,Elti,'ro-');grid on;xlabel('Time [s]');ylabel('Angles [Deg]');legend('Azimuth','Elevation');

//    figure('Name','Aspect Angle');
//    plot(time,TAAi,'b*-');grid on;xlabel('Time [s]');ylabel('Target Aspect Angle [Deg]');

//    %--------------------------------------------------------------------------
//    % MIL_MC_HYBRID.txt
//            %--------------------------------------------------------------------------
//            % KAM time	 TimeTag	 StatusWd	 ValWd	 RollAngle	 PitchAngle	 TrueHdg
//            %    1          2           3           4       5           6           7
//            % MHdg      Vn     Ve	 Vup	 Latitude	 Longitude	 Altitude	 PosErr
//            %   8       9      10     11        12          13          14          15
//            %--------------------------------------------------------------------------
//            % ICD Word definition
//            %--------------------------------------------------------------------------
//            % Word0       Word1     Word2     Word3         Word4     Word5     Word6
//            % TimeTag	 StatusWd	ValWd	 RollAngle	 PitchAngle	 TrueHdg	 MHdg
//            % Word7       Word8     Word9     Word10       Word11     Word12     Word13
//            % VnH           VnL     VeH         VeL         Vup         LatH	 LatL
//            % Word14       Word15    Word16     Word17
//            % LongH        LongL	Altitude	PosErr
//            %--------------------------------------------------------------------------
            engg = load('Scenario.txt');
    Time = engg(:,1);
    Vn  = engg(:,15)*1000;      % To convert to m/s from km/s
            Ve  = engg(:,16)*1000;      % To convert to m/s from km/s
            Vup = engg(:,17)*1000;      % To convert to m/s from km/s
            Latitude = engg(:,12);
    Longitude = engg(:,13);
    Altitude = engg(:,14)*1000; % To convert to m from km
//            %--------------------------------------------------------------------------
            flength = length(engg);
//    %--------------------------------------------------------------------------
    TimeTag(1:flength) = 0.0;
    StsWd(1:flength) = 18112;
    ValWd(1:flength) = 65024;
    RollAngle(1:flength) = 0.0;
    PitchAngle(1:flength) = 0.0;
    %This following six lines added on 10th Aug 2017 for maneuver simulation
            PitchAngle(10000:10600) = 0.0:0.01:6.0;
    PitchAngle(10601:11201) = 6.0;
    PitchAngle(11202:11802) = 6.0:-0.01:0.0;
    PitchAngle(12400:13000) = 0.0:0.01:6.0;
    PitchAngle(13001:13601) = 6.0;
    PitchAngle(13602:14202) = 6.0:-0.01:0.0;
    TrueHdg(1:flength) = 0.0;
    %This following six lines added on 10th Aug 2017 for maneuver simulation
            TrueHdg(14800:15400) = 0.0:0.01:6.0;
    TrueHdg(15401:16001) = 6.0;
    TrueHdg(16002:16602) = 6.0:-0.01:0.0;
    TrueHdg(17200:17800) = 0.0:0.01:6.0;
    TrueHdg(17801:18401) = 6.0;
    TrueHdg(18402:19002) = 6.0:-0.01:0.0;
    MHdg(1:flength) = 0.0;
    PosErr(1:flength) = 20.0;
//    %--------------------------------------------------------------------------
    Word0 = round(TimeTag/0.064);
    Word1 = StsWd;
    Word2 = ValWd;
    Word3 = RollAngle;
    Word4 = proc_15sgnf(PitchAngle,flength,0.005493164062500);
    Word5 = proc_15sgnf(TrueHdg,flength,0.005493164062500);
    Word6 = MHdg;
    [Word7,Word8]  = proc_19sgnf(Vn,flength,0.003215274811);
    [Word9,Word10] = proc_19sgnf(Ve,flength,0.003215274811);
    Word11 = proc_15sgnf(Vup,flength,0.05144439697265625);
    [Word12,Word13]  = proc_28sgnf(Latitude,flength,6.705522537231445*10^-7);
    [Word14,Word15] = proc_28sgnf(Longitude,flength,6.705522537231445*10^-7);
    Word16 = proc_15sgnf(Altitude,flength,1);
    Word17 = PosErr;
//    %--------------------------------------------------------------------------
    fid = fopen('MIL_MC_HYBRID_RAW.txt','w');
//    % % fid2 = fopen('MIL_MC_HYBRID_RAW_HEX.txt','w');
    fprintf(fid,'%%Time\t Word0\t Word1\t Word2\t Word3\t Word4\t Word5\t Word6\t Word7\t Word8\t Word9\t Word10\t Word11\t Word12\t Word13\t Word14\t Word15\t Word16\t Word17\n');
//    % % fprintf(fid2,'%%Word0\t Word1\t Word2\t Word3\t Word4\t Word5\t Word6\t Word7\t Word8\t Word9\t Word10\t Word11\t Word12\t Word13\t Word14\t Word15\t Word16\t Word17\n');
    for i=1:flength
            fprintf(fid,'%6.4f\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\n',Time(i),Word0(i),Word1(i),Word2(i),Word3(i),Word4(i),Word5
                    (i),Word6(i),Word7(i),Word8(i),Word9(i),Word10(i),Word11(i),Word12(i),Word13(i),Word14(i),Word15(i),Word16(i),Word17(i));
//    % % fprintf(fid2,'%5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\n',Word0(i),Word1(i),Word2(i),Word3(i),Word4(i),Word5(i),Word6(i),Word7
//                (i),Word8(i),Word9(i),Word10(i),Word11(i),Word12(i),Word13(i),Word14(i),Word15(i),Word16(i),Word17(i));
    end
            fclose(fid);
//    % % fclose(fid2);

//    %--------------------------------------------------------------------------
//    % ICD Word definition
//            %--------------------------------------------------------------------------
//            % Word0
//            % Target Noumber/Station ID/BVR/CCM/DLZrequired or not
//            % Word1      Word2     Word3       Word4       Word5           Word6
//            % AbsAz     AbsEl    Discrete1   RangeMeas   RangeCalc       ClosingSpd
//            % Word7       Word8             Word9          Word10       Word11
//            % HorzVel  HorzAngleOfVt    SmthAltRate       Discrete2    Discrete3
//            % Word12    Word13   Word14             Word15        Word16       Word17
//            % Discrete4  Vt      VertAngleOfVt  AngularVtHorz  AngularVtVert  TAAHorz
//            % Word18    Word19    Word20    Word21      Word22   Word23  Word24  Word25
//            % Discrete5 RC1Timer  VtzAnt   Discrete6  Discrete7   VtAz    VtEl    Ht
//            % Word26    Word27    Word28    Word29     Word30    Word31
//            % VtxAxis   VtyAxis   VtzAxis  QtyOfTrack  VtxAnt    VtyAnt
//            %--------------------------------------------------------------------------
            flength = length(engg);
//    %--------------------------------------------------------------------------
    Time = engg(:,1);
    TgtNo = engg(:,19);
    AbsAz = engg(:,3);
    AbsEl = engg(:,4);
    Discrete1(1:flength) = 0.0;
    RangeMeas = engg(:,2);
    RangeCalc = engg(:,2);
    ClosingSpd = engg(:,11);
    HorzVel(1:flength) = 0.0;
    HorzAngleOfVt(1:flength) = 0.0;
    SmthAltRate(1:flength) = 0.0;
    Discrete2(1:flength) = 0.0;
    Discrete3(1:flength) = 0.0;
    Discrete4(1:flength) = 0.0;
    Vt = engg(:,8);
    VertAngleOfVt(1:flength) = 0.0;
    AngularVtHorz(1:flength) = 0.0;
    AngularVtVert(1:flength) = 0.0;
    TAAHorz = engg(:,10);
    Discrete5(1:flength) = 0.0;
    RC1Timer(1:flength) = 0.0;
    VtzAnt = engg(:,6);
    Discrete6(1:flength) = 0.0;
    Discrete7(1:flength) = 0.0;
    VtAz(1:flength) = 0.0;
    VtEl(1:flength) = 0.0;
    Ht = engg(:,9);
    VtxAxis = engg(:,5);
    VtyAxis = engg(:,7);
    VtzAxis = engg(:,6);
    QtyOfTrack(1:flength) = 1;
    VtxAnt = engg(:,5);
    VtyAnt = engg(:,7);
    %--------------------------------------------------------------------------
    Word0 = TgtNo;
    Word1 = proc_15sgnf(AbsAz,flength,0.0054931640625);
    Word2 = proc_15sgnf(AbsEl,flength,0.0054931640625);
    Word3 = Discrete1;
    Word4 = proc_15sgnf(RangeMeas,flength,0.0078125);
    Word5 = proc_15sgnf(RangeCalc,flength,0.0078125);
    Word6 = proc_15sgnf(ClosingSpd,flength,0.000244140625);
    Word7 = proc_15sgnf(HorzVel,flength,0.000244140625);

    Word8 = proc_15sgnf(HorzAngleOfVt,flength,0.0054931640625);
    Word9 = proc_15sgnf(SmthAltRate,flength,0.000244140625);
    Word10 = Discrete2;
    Word11 = Discrete3;
    Word12 = Discrete4;
    Word13 = proc_15sgnf(Vt,flength,0.000244140625);
    Word14 = proc_15sgnf(VertAngleOfVt,flength,0.0054931640625);
    Word15 = proc_15sgnf(AngularVtHorz,flength,0.0054931640625);
    Word16 = proc_15sgnf(AngularVtVert,flength,0.0054931640625);
    Word17 = proc_15sgnf(TAAHorz,flength,0.0054931640625);
    Word18 = Discrete5;
    Word19 = 1:1:flength;
    Word20 = proc_15sgnf(VtzAnt,flength,0.000244140625);
    Word21 = Discrete6;
    Word22 = Discrete7;
    Word23 = proc_15sgnf(VtAz,flength,0.0054931640625);
    Word24 = proc_15sgnf(VtEl,flength,0.0054931640625);
    Word25 = proc_15sgnf(Ht,flength,0.0078125);
    Word26 = proc_15sgnf(VtxAxis,flength,0.000244140625);
    Word27 = proc_15sgnf(VtyAxis,flength,0.000244140625);
    Word28 = proc_15sgnf(VtzAxis,flength,0.000244140625);
    Word29 = QtyOfTrack*16384;
    Word30 = proc_15sgnf(VtxAnt,flength,0.000244140625);
    Word31 = proc_15sgnf(VtyAnt,flength,0.000244140625);
    %--------------------------------------------------------------------------
    fid = fopen('MIL_RC_LOT_RAW.txt','w');
    % % fid2 = fopen('MIL_RC_LOT_RAW_HEX.txt','w');
    fprintf(fid,'%%Time\t Word0\t Word1\t Word2\t Word3\t Word4\t Word5\t Word6\t Word7\t Word8\t Word9\t Word10\t Word11\t Word12\t Word13\t Word14\t Word15\t Word16\t Word17\t Word18\t Word19\t
            Word20\t Word21\t Word22\t Word23\t Word24\t Word25\t Word26\t Word27\t Word28\t Word29\t Word30\t Word31\n');
            % % fprintf(fid2,'%%Word0\t Word1\t Word2\t Word3\t Word4\t Word5\t Word6\t Word7\t Word8\t Word9\t Word10\t Word11\t Word12\t Word13\t Word14\t Word15\t Word16\t Word17\t Word18\t Word19\t
                        Word20\t Word21\t Word22\t Word23\t Word24\t Word25\t Word26\t Word27\t Word28\t Word29\t Word30\t Word31\n');
                        for i=1:flength
            fprintf(fid,'%6.4f\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t %5d\t
                    %5d\t %5d\t %5d\n',Time(i),Word0(i),Word1(i),Word2(i),Word3(i),Word4(i),Word5(i),Word6(i),Word7(i),Word8(i),Word9(i),Word10(i),Word11(i),Word12(i),Word13(i),Word14(i),Word15(i),Word16(i),Word17
                    (i),Word18(i),Word19(i),Word20(i),Word21(i),Word22(i),Word23(i),Word24(i),Word25(i),Word26(i),Word27(i),Word28(i),Word29(i),Word30(i),Word31(i));
            % % fprintf(fid2,'%5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t %5X\t
                        %5X\t %5X\n',Word0(i),Word1(i),Word2(i),Word3(i),Word4(i),Word5(i),Word6(i),Word7(i),Word8(i),Word9(i),Word10(i),Word11(i),Word12(i),Word13(i),Word14(i),Word15(i),Word16(i),Word17(i),Word18
                        (i),Word19(i),Word20(i),Word21(i),Word22(i),Word23(i),Word24(i),Word25(i),Word26(i),Word27(i),Word28(i),Word29(i),Word30(i),Word31(i));
            end
            fclose(fid);
    % % fclose(fid2);
    %--------------------------------------------------------------------------
    //dcmenu2ecef.m
    function [c] = DCMENU2ECEF(Phi,Lamda)
            %--------------------------------------------------------------------
            % Function to generate DCM to transform from ENU to ECEF coordinate system.
            % inputs are geodedtic latitude and longitude in deg
            cph = cosd(Phi);
    sph = sind(Phi);

    cla = cosd(Lamda);
    sla = sind(Lamda);
    %--------------------------------------------------------------------
    c(1,1) = -sla;
    c(1,2) = -cla*sph;
    c(1,3) = cla*cph;

    c(2,1) = cla;
    c(2,2) = -sla*sph;
    c(2,3) = sla*cph;

    c(3,1) = 0;
    c(3,2) = cph;
    c(3,3) = sph;
    %--------------------------------------------------------------------
    end

            //////////////////////////
            //ecefto latlongalt//
            function [lat,lon,alt] = ECEFtoLatLongAlt(XECEF,YECEF,ZECEF)
            %ECEFtoLatLongAlt function converts ECEF values to Latitude, Longitude
            %and Altitude data
            a = 6378137.0;
    b = 6356752.3142;
    f = 1/298.257223563;
    esq = 0.00669437999014;
    epsq = esq / (1 - esq);
    rtod = 180/pi; % Degree to radian conversion factor

            % Longitude
            lon = atan2(YECEF,XECEF)*rtod;

    % Distance from Z-axis
            rho = hypot(XECEF,YECEF);

    beta = atan2(ZECEF, (1 - f) * rho);

    % Latitude
            phi = atan2(ZECEF   + b * epsq * sin(beta).^3,...
                        rho - a * esq  * cos(beta).^3);

    % Fixed-point iteration with Bowring's formula
            % (typically converges within two or three iterations)
            betaNew = atan2((1 - f)*sin(phi), cos(phi));
    count = 0;
    while any(beta(:) ~= betaNew(:)) && count < 5
            beta = betaNew;
    phi = atan2(ZECEF   + b * epsq * sin(beta).^3,...
                rho - a * esq  * cos(beta).^3);
    betaNew = atan2((1 - f)*sin(phi), cos(phi));
    count = count + 1;
    end

            % Calculate ellipsoidal height from the final value for latitude
            sinphi = sin(phi);
    N = a ./ sqrt(1 - esq * sinphi.^2);
    alt = rho .* cos(phi) + (ZECEF + esq * N .* sinphi) .* sinphi - N;
    lat = phi*rtod;
    end

            ///////////////
            ///geodetic2ecefc
            function [XECEF,YECEF,ZECEF] = Geodetic2ECEF(Lat,Lon,h)
            %--------------------------------------------------------------------
            % function to compute ECEF coordinates of a given geodetic position.
            % Lat is the geodetic latitude in deg
            % Lon is the geodetic longitude in deg
            % h is the altitude above MSL in meters
            %--------------------------------------------------------------------
            esq = 0.00669437999014;
    a = 6378137.0;
    dr = 1.0 - esq * sind(Lat)^2;
    N = a/sqrt(dr);
    %--------------------------------------------------------------------
    XECEF = (N + h) * cosd(Lat) * cosd(Lon);
    YECEF = (N + h) * cosd(Lat) * sind(Lon);
    ZECEF = (N * (1-esq) + h) * sind(Lat);
    %--------------------------------------------------------------------
    end
            ////////////////
     function [val1,val2] = proc_19sgnf(X,flength,SF)

            Y = round(X/SF);

    Z = bitshift(Y,12);

    for i = 1:flength
            if (Z(i)<0)
            Z(i) = Z(i) +  4294967296;
    end
            end

            val1 = bitshift(bitand(Z,4294901760),-16);
    val2 = bitand(Z,65535);
    ///////////
    function [val1,val2] = proc_28sgnf(X,flength,SF)

            Y = round(X/SF);

    Z = bitshift(Y,3);

    for i = 1:flength
            if (Z(i)<0)
            Z(i) = Z(i) +  4294967296;
    end
            end

            val1 = bitshift(bitand(Z,4294901760),-16);
    val2 = bitand(Z,65535);
    ///////
    }

int senariogeneration::proc_15sgnf(int, int)
{
    Y = round(X/SF);

    for (int i = 1;i<= flength;i++ ){
        if (Y(i)<0)
            Y(i) = Y(i) + 65536;

    }
    val = Y
            return val ;
}
