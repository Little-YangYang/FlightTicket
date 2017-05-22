/*
* dataListInit.cpp
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 初始化相关链式存储结构
* 声明数据初始化函数
*/

#include "dataListInit.h"

// 初始化航线数据空链表
flightLineInfo initFlightLine(){
    flightLineInfo info;
    info = (flightLineInfo)malloc(sizeof(flightInfoNode));
    info->next = NULL;
    return info;
}


//初始化航班数据空链表
flightInfo initFlight() {
    flightInfo info;
    info = (flightInfo)malloc(sizeof(flightInfoNode));
    info->next = NULL;
    return info;
}


//初始化票务数据空链表
ticketInfo initTicket() {
    ticketInfo info;
    info = (ticketInfo)malloc(sizeof(ticketInfoNode));
    info->next = NULL;
    return info;
}