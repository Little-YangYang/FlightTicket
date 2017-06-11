/*
* user.cpp
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 用户查询系统相关程序
*/
#include "user.h"

extern ticketInfo ticket;
void userSearch() {
    int uuid, count = 0;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t┌─────────────────┐\n");
    printf("\t\t\t\t├    欢迎使用航空用户查询系统！    ┤\n");
    printf("\t\t\t\t└─────────────────┘\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t├请输入用户ID：                      ┤");
    printf("\r\t\t\t\t├请输入用户ID：");
    scanf("%d", &uuid);
    ticketInfo p;
    p = ticket->next;
    printf("\n\n\n");
    printf("\t\t\t\t┌───────────────────────┐\n");
    printf("\t\t\t\t├  航班号\t姓名\t订票日期\t\t┤\n");
    while (p) {
        if (p->data.uuid == uuid) {
            printf("\t\t\t\t├───────────────────────┤\n");
            printf("\t\t\t\t├%d\t\t%s\t%d年%d月%d日%d点%d分\t┤\n", p->data.flightCode, p->data.userName, p->data.ticketTime[0], p->data.ticketTime[1], p->data.ticketTime[2], p->data.ticketTime[3], p->data.ticketTime[4]);
            count += 1;
        }
        p = p->next;
    }
    printf("\t\t\t\t└───────────────────────┘\n");
    if (count == 0) {
        printf("\n\t\t\t\tUUID错误或无购票信息，请核对后再次查询！");
        system("pause");
        userSearch();
    }
    system("pause");
}