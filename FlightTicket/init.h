/*
* init.h
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 入口初始化功能程序
*/
#pragma once

#include "stdafx.h"
#include "dataListInit.h"
#include "dataList.h"
#include "dataInit.h"

void init();
void initDisplay();
void displayProgress(int progress, char *status);
void error(char *s);