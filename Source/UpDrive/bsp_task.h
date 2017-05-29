#ifndef  __TASK__H__
#define  __TASK__H__
#include "bsp_tpc.h"
#pragma anon_unions             //使用匿名结构体

/********************************************************************************************************
* 宏定义
********************************************************************************************************/
#define KEY_KEY 	PAin(4) //PA4,KEY扫描按键
#define KEY_PWR		PCout(13) //PC13,PWR控制按键

typedef union
{
	uint8_t msg[8];
	struct
	{
		uint8_t head; //包头
		uint8_t devID; //设备id
		uint8_t Heartdata; //心率值
		uint8_t HrtPowerdata; //心率带电量
		uint8_t BatPowerdata; //电池电量
		uint8_t tail; //包尾
	};
} SLVMSG_T; //从机信息结构体


/********************************************************************************************************
* 变量定义
********************************************************************************************************/
extern TPC_TASK TaskComps[];

/********************************************************************************************************
* 内部函数
********************************************************************************************************/
static void Task_RecvfromUart(void);  // 广播任务
static void Task_LEDDisplay(void);  //LED闪烁任务
static void Task_SendToMaster(void); //发送数据至PC机
static void Task_RecvfromLora(void); //从Lora（SX1278）所连接的串口2读取数据任务
static void Task_KeyScan(void); //扫描一键开机键的任务
static void Task_PowerCtl(void); //控制关机任务
static void Task_ADCProcess(void); //ADC采集串联分压电阻获得电量程序
/********************************************************************************************************
* 全局函数
********************************************************************************************************/
extern void TaskInit(void); // 初始化
extern void bsp_KeyScan(void);
/*******************************************************************************************************/
#endif

