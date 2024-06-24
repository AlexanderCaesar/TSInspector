//author Yangang Cai  caiyangang@bupt.edu.cn

#include <stdio.h>
#include <stdlib.h>
#include "tsfile.h"
#include "ts.h"

/* 打印help信息 */
static void showHelp()
{
#define H0 printf
	H0("\n-h Print parameter configuration information and exit\n");
	H0("\n-i Configure input files, eg.-i brazil-bq.ts\n");
	H0("\n-t Configure output logs, eg.-t brazil-bq.log\n");
	H0("\n-v Configure output video, eg.-v brazil-bq.264\n");
	H0("\n-a Configure output audio, eg.-a brazil-bq.aac\n");
	H0("\n-o Configure output TS, eg.-o brazil-new.ts\n\n");
}
/* 设置ts的默认参数 */
void ts_param_default(ts_param *param)
{
	param->b_ts    = 1;
	param->b_video = 0;
	param->b_audio = 0;    
	param->b_nts   = 0;
}

/* 解析配置参数 */
bool parse(ts_param *param,int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("No configuration parameters\n");
		return false;
	}

	for(int i = 1; i < argc; i += 2)
	{
		if(argv[i][0] != '-')
		{
			printf("Parameter configuration error:%s\n",argv[i]);
			return false;
		}
		switch(argv[i][1])
		{
		case 'h':showHelp();system("pause\n");exit(0);          break;
		case 'i':ts_file_name = argv[i+1];                     break;
		case 't':ts_ts_name = argv[i+1];  param->b_ts     = 1; break;
		case 'v':ts_video_name = argv[i+1];param->b_video = 1; break;
		case 'a':ts_audio_name = argv[i+1];param->b_audio = 1; break;
		case 'o':ts_out_name = argv[i+1];  param->b_nts   = 1; break;
		default:printf("Parameter configuration error:%s\n",argv[i]); return false;
		}
	}
	return true;
}
