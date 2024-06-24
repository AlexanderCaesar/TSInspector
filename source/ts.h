#ifndef XIAOC_TS_H
#define XIAOC_TS_H
//author Yangang Cai  caiyangang@bupt.edu.cn

typedef struct ts_param
{
    /* configuration information 
    -i brazil-bq.ts
    -t brazil-bq.log
    -v brazil-bq.264
    -a brazil-bq.aac
    **/
    int  b_ts;    //Print detailed information for each TS  
    int  b_video; //Output video stream information        
    int  b_audio; //Output audio stream information         
    int  b_nts;   //Output a new ts file        

}ts_param;

/* Set default parameters for ts */
void ts_param_default(ts_param *param);

/* ½âÎöÅäÖÃ²ÎÊı */
bool parse(ts_param *param,int argc, char **argv);

#endif
