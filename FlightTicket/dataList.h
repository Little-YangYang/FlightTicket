/*
* dataList.h
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 声明相关链式存储结构
*/

#pragma once
#include "stdafx.h"

/*
* flightLineInfo
*航线信息相关存储链表
********************************
* @pragma lineCode 航线编码
* @pragma startCode 起点机场编码
* @pragma endCode 终点机场编码
* @pragma kilometer 航班公里数
* @pragma min 飞行时间(min)
*/
typedef struct {
    int lineCode;
    int startCode;
    int endCode;
    int kilometer;
    int min;
}flightLineData;

typedef struct flightLineInfoNode {
    flightLineData data;
    struct flightLineInfoNode *next;
}flightLineInfoNode, *flightLineInfo;

/*
* flightInfo
*航班信息相关存储链表
********************************
* @pragma flightCode 航班编码
* @pragma lineCode 航线编码
* @pragma time[2] 起飞时间[小时][分钟]
* @pragma price 票价
* @pragma amount 可售机票总数
* @pragma status 当前状态
*/
typedef struct {
    int flightCode;
    int lineCode;
    int time[2];
    int price;
    int amount;
    int status;
}flightData;

typedef struct flightInfoNode {
    flightData data;
    struct flightInfoNode *next;
}flightInfoNode, *flightInfo;

/*
* ticketInfo
*售票信息相关存储链表
********************************
* @pragma flightCode 航班编码
* @pragma uuid 顾客ID
* @pragma username[10] 姓名
* @pragma ticketTime[5] 购票时间[年/月/日/小时/分钟]
*/
typedef struct {
    int flightCode;
    int uuid;
    char userName[10];
    int ticketTime[5];
}ticketData;

typedef struct ticketInfoNode {
    ticketData data;
    struct ticketInfoNode *next;
}ticketInfoNode, *ticketInfo;
