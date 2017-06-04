/*
* dataInit.cpp
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 初始化数据
* 读取数据到链表中
*/
#include "dataInit.h"

//读取航线数据
void createLineList(flightLineInfo info) {
    FILE *fp;
    int lineCode, kilometer, min;
    char start[10], end[10];
    flightLineInfo p;
    if ((fp = fopen("dataFlightLine.txt", "r")) == NULL) {
        printf("\nError:C404 无法找到航线数据文件!\n");
        system("pause");
        exit(1);
        return;
    }
    while (!feof(fp)) {
        fscanf(fp, "%d %s %s %d %d\n", &lineCode, &start, &end, &kilometer, &min);
        p = (flightLineInfo)malloc(sizeof(flightLineInfoNode));
        p->data.lineCode = lineCode;
        strcpy(p->data.start, start);
        strcpy(p->data.end, end);
        p->data.kilometer = kilometer;
        p->data.min = min;
        p->next = info->next;
        info->next = p;
    }
    fclose(fp);
}
//读取航班数据
void createFlightList(flightInfo info) {
    FILE *fp;
    int flightCode,lineCode,time[2],price,amount,status;
    flightInfo p;
    if ((fp = fopen("dataFlight.txt", "r")) == NULL) {
        printf("\nError:C404 无法找到航班数据文件!\n");
        system("pause");
        exit(1);
        return;
    }
    while (!feof(fp)) {
        fscanf(fp, "%d %d %d %d %d %d %d\n", &flightCode, &lineCode, &time[0], &time[1], &price, &amount, &status);
        p = (flightInfo)malloc(sizeof(flightInfoNode));
        p->data.flightCode = flightCode;
        p->data.lineCode = lineCode;
        p->data.time[0] = time[0];
        p->data.time[1] = time[1];
        p->data.price = price;
        p->data.amount = amount;
        p->data.status = status;
        p->next = info->next;
        info->next = p;
    }
    fclose(fp);
}

//读取票务数据
void createTicketList(ticketInfo info){
    FILE *fp;
    int flightCode,uuid,ticketTime[5];
    char userName[10];
    ticketInfo p;
    if ((fp = fopen("dataTicket.txt", "r")) == NULL) {
        printf("\nError:C404 无法找到票务数据文件!\n");
        system("pause");
        exit(1);
        return;
    }
    while (!feof(fp)) {
        fscanf(fp, "%d %d %d %d %d %d %d %s\n",
            &flightCode, &uuid, &ticketTime[0], &ticketTime[1], &ticketTime[2], &ticketTime[3], &ticketTime[4], &userName);
        p = (ticketInfo)malloc(sizeof(ticketInfoNode));
        p->data.flightCode = flightCode;
        p->data.uuid = uuid;
        p->data.ticketTime[0] = ticketTime[0];
        p->data.ticketTime[1] = ticketTime[1];
        p->data.ticketTime[2] = ticketTime[2];
        p->data.ticketTime[3] = ticketTime[3];
        p->data.ticketTime[4] = ticketTime[4];
        //p->data.ticketTime[5] = ticketTime[5];
        strcpy(p->data.userName, userName);
        p->next = info->next;
        info->next = p;
    }
    fclose(fp);
}