/*
* ticket.h
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 订票系统程序相关声明
*/
#pragma once
#include "stdafx.h"
#include "dataList.h"

void flightSearch(int id);
void flightLineSearch(int id, int hour_min, int min_min, int hour_max, int min_max);
int book(int flightCode, int uuid, char name[10]);
void refund(int uuid,int id);
void saveAll();