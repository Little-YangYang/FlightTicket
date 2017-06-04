/*
* init.cpp
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 入口初始化功能程序
*/
#include "init.h"

flightLineInfo flightLine;
flightInfo flight;
ticketInfo ticket;

void init() {
    initDisplay();
    displayProgress(10, "正在加载航线模块.");
    Sleep(500);
    flightLine = initFlightLine();
    displayProgress(40, "正在加载航班模块");
    Sleep(400);
    flight = initFlight();
    displayProgress(70, "正在加载票务模块");
    Sleep(500);
    ticket = initTicket();
    displayProgress(100, "模块加载完毕！");
    Sleep(500);
    displayProgress(1, "正在加载航线数据");
    createLineList(flightLine);
    Sleep(500);
    displayProgress(34, "正在加载航班数据");
    createFlightList(flight);
    Sleep(500);
    displayProgress(67, "正在加载票务数据");
    createTicketList(ticket);
    Sleep(500);
    displayProgress(100, "数据加载完毕！");
    Sleep(500);
    for (int i = 1; i <= 100; i++) {
        displayProgress(i, "正在加载导航系统:");
        Sleep(20);
    }
    system("cls");
}

//initDisplay 初始化程序欢迎界面
void initDisplay() {

    for (int i = 0; i < 10; i++) {
        printf("\n");
    }
    printf("\t\t\t\t欢迎使用航空公司订票系统！\n");
    printf("\n\n");
    printf("\t\t\t\t\t\tCopyright (c) 李沐阳/刘颖民 2016-2017 ALL right reserved.\n");
    printf("\n\n\n\n\n");
    printf("正在初始化系统模块，请稍后.....\n");
    Sleep(2000);
}

//进度条显示函数
void displayProgress(int progress,char *status) {
    int len = 50, pro = progress / 2;
    char bar[50];
    for (int i = 0; i < len; i++) {
        bar[i] = '-';
    }
    printf("\r%s  \t当前进度:%d %% \t[",status,progress);
    for (int i = 0; i < pro; i++) {
        printf(">");
    }
    for (int i = pro; i < len; i++) {
        printf("-");
    }
    printf("]");
    if (progress == 100) {
        printf("\n");
    }
    fflush(stdout);
}
//错误函数
void error(char *s) {
    printf("\n%s", s);
    system("pause");
    exit(1);
}