/**
 ** @file:	   head.h
 ** @author:	   浓咖啡
 ** @date:	   2016.11.1
 ** @brief:      定义相关结构体
 */

#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define random(x) (rand()%x)

typedef struct sockaddr SA;

typedef struct {
	uint8_t head[3];	 //标识位st:
	uint8_t type;		 //数据类型
	uint8_t snum;		 //仓库编号
	uint8_t temp[2];	 //温度	
	uint8_t hum[2];		 //湿度
	uint8_t x;			 //三轴信息
	uint8_t y;			 
	uint8_t z;			 
	uint32_t ill;		 //光照
	uint32_t bet;		 //电池电量
	uint32_t adc; 		 //电位器信息
}MSG;	

#endif
