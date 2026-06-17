#ifndef VARIABLES_H
#define VARIABLES_H
#include "stdemace.h"

S16BIT aOpCodes[30] =  {0x0000};

MSGSTRUCT sMsg;
QString str;
char s[32], buf[80];
S16BIT	nResult = 0,wResult = 0;
S16BIT DevNum ;
U16BIT wBuffer[32]={0} ;
U16BIT mlp_data_1[32]={0}, mlp_data_2[32]={0}, mlp_data_3[32]={0},mlp_data_4[32]={0}, mslp_res_stn7[32]={0}, mslp_res_stn8[32]={0},mslp_res_stn9[32]={0}, mslp_res_stn10[32]={0}, mslp_res_data[32]={0}, mslp_res_data1[32]={0}, mslp_res_data2[32]={0}, mslp_res_data3[32]={0}, mslp_res_data4[32]={0},target_data[32]={0},missile_tgt_data[32]={0}, freq_res_stn7[3]={0},freq_res_stn8[3]={0}, freq_res_stn9[3]={0}, freq_res_stn10[3]={0};
U16BIT sekr_on_off,soft_opt,lau_val,hold_num,apole_valid,msl_val,A_L_Status,val_hold,temp_value,init_test,DLTtx_sts,sekr_ack,seeker_sts,launcher_test,missile_test,validity,mlpobc_comm,video_record,mis_mate,fin_lock,act_null,DLRx_init_hlth,ins_cbit,rpf_hlth,sam_hlth,seekr_elec_hlth,obc_comm,DLRx_mask,DLTx_mask,filament27,setx,seel,actmon,dcmon,elmon,dltmon,irt,tlt,tat,tla,tln,Dmin,Dmax1,Dmax2,umbilical_sts,flm_sts,boost1_sts,boost2_sts,LTB_a_sts,LTB_se_sts,LTB_t_sts,boost_fire,ltb_fire,unguid_lanuch,lanuch1_sts,lanuch2_sts,SAM_sts,ready_sts,seekr_elec_sts,seekr_htr_sts,seekr_tx_sts,tel_sts,scu_sts,DLTxsup_sts,elec_subsys_sts,astra_hlth,launch_hlth,DLZ_valid,Mis_Avail,Transfer_align,Maneuver,mis_rdy,mis_rel,mis_hlth,mis_state,amlp_hlth,apru_sts,apsu_sts,DLTx_init,DLTx_sts,mins_data,modetype,launch1,Astra_state ,IMM_state,Tgt_status;
U16BIT sur_data_1[32]={0},sur_data_2[32]={0},sur_data_3[32]={0},sur_data_4[32]={0},sur_data[32]={0};
U16BIT stn7_tagt_data[32]={0},stn8_tagt_data[32]={0},stn9_tagt_data[32]={0},stn10_tagt_data[32]={0},stn_tagt_data[32]={0};
U16BIT amlp_time;
U32BIT dwHBufLost       = 0x0000;
U32BIT dwMsgLostStk = 0x0000;
S16BIT dwCurCount       = 0x0000;
U32BIT dwMsgCount;
int msgcnt=0;
int prevmsgcnt=0;
int stn7_counter=0,stn8_counter=0, stn9_counter=0, stn10_counter=0;
int i=0,j;
U16BIT value,deci,twocomp,data,a,dstd1[32]={0},dstd2[32]={0},dstd3[32]={0},dstd4[32]={0},lotd[32]={0},data1[33]={0},data2[33]={0},data3[33]={0},data4[33]={0},data5[33]={0},hmds1[32]={0},hmds2[3]={0}, hmds3[3]={0}, hmds4[3]={0}, freq_cmd_stn7[5]={0},freq_cmd_stn8[5]={0},freq_cmd_stn9[5]={0},freq_cmd_stn10[5]={0};



//FILE *  testFile = fopen("Mslp_test.txt","w");
//FILE *fp =fopen("Target Data.txt","a");
void _DECL funcExternalISR(S16BIT DevNum, U32BIT Status);
unsigned int comp(U16BIT );
static void PrintOutError(S16BIT nResult);
U16BIT convertodec(U16BIT );
HWVERSIONINFO structHWVersionInfo;
int k;
#endif // VARIABLES_H
