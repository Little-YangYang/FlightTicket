#include "ticket.h"

extern flightLineInfo flightLine;
extern flightInfo flight;
extern ticketInfo ticket;

void flightSearch(int id) {
    flightLineInfo flightline_s;
    flightInfo flight_s;
    int status = 1;
    
    flight_s = flight->next;
    flightline_s = flightLine->next;

    system("cls");
    printf("\t┌─────────────── 航班：%6d ─────────────────────┐\n", id);
    printf("\t├航线编号      起飞机场        到达机场        起飞时间        里程    票价    余票    ┤\n");
    printf("\t├───────────────────────────────────────────┤\n");
    while (flight_s) {
        //判断若航班编号一致则输出
        if (flight_s->data.flightCode == id) {
            while (flightline_s) {
                if (flightline_s->data.lineCode == flight_s->data.lineCode) {
                    printf("\t├%d\t\t%s\t\t%s\t\t%d\:%2d\t\t%d\t%d\t%d\t┤\n",
                        flight_s->data.lineCode,
                        flightline_s->data.start,
                        flightline_s->data.end,
                        flight_s->data.time[0],
                        flight_s->data.time[1],
                        flightline_s->data.kilometer,
                        flight_s->data.price,
                        flight_s->data.amount
                    );
                    break;
                }
            }
            if (flight_s->data.status == 0) {
                printf("\t├警告：本次航班机票不可用！                                                            ┤\n");
                status = 0;
                break;
            }
            if (flight_s->data.amount == 0) {
                printf("\t├警告：本次航班机票已经售空！                                                          ┤\n");
                status = 0;
            }
            printf("\t└───────────────────────────────────────────┘\n\n\n");
            if (status == 1) {
                int nav;
                printf("\n\n\n\t├是否订购本次航班的机票？(0/1)                                                         ┤");
                printf("\r\t├是否订购本次航班的机票？(0/1)");
                scanf("%d", &nav);
                if (nav == 1) {
                    int uuid;
                    char name[10];
                    printf("\t├请输入您的会员卡ID：                                                                  ┤");
                    printf("\r\t├请输入您的会员卡ID：");
                    scanf("%d", &uuid);
                    printf("\t├请输入您的姓名:                                                                       ┤");
                    printf("\r\t├请输入您的姓名:");
                    scanf("%s", name);
                    int succ;
                    succ = book(id, uuid, name);
                    system("pause");
                }
            }
            return;
        }
        flight_s = flight_s->next;
        flightline_s = flightline_s->next;
    }
    printf("\t├警告：无此航班，请检查！                                                              ┤\n");
    printf("\t└───────────────────────────────────────────┘\n");
    system("pause");
}

void flightLineSearch(int id, int hour_min, int min_min, int hour_max, int min_max) {
    flightLineInfo flightline_s;
    flightInfo flight_s;

    int count = 0;
    flight_s = flight->next;
    flightline_s = flightLine->next;

    system("cls");
    printf("\t┌───────────────────────────────────────────┐\n");
    printf("\t├航班编号      起飞机场        到达机场        起飞时间        里程    票价    余票    ┤\n");
    printf("\t├───────────────────────────────────────────┤\n");

    while (flight_s) {
        if (flight_s->data.lineCode == id &&
            flight_s->data.time[0] >= hour_min &&
            flight_s->data.time[0] <= hour_max &&
            flight_s->data.time[1] >= min_min &&
            flight_s->data.time[1] <= min_max) {
            count += 1;
            while (flightline_s) {
                if (flightline_s->data.lineCode == flight_s->data.lineCode) {
                    printf("\t├%d\t\t%s\t\t%s\t\t%d\:%2d\t\t%d\t%d\t%d\t┤\n",
                        flight_s->data.flightCode,
                        flightline_s->data.start,
                        flightline_s->data.end,
                        flight_s->data.time[0],
                        flight_s->data.time[1],
                        flightline_s->data.kilometer,
                        flight_s->data.price,
                        flight_s->data.amount
                    );
                    break;
                }
            }
            if (flight_s->data.status == 0) {
                printf("\t├警告：本次航班机票不可用！                                                            ┤\n");
                break;
            }
            if (flight_s->data.amount == 0) {
                printf("\t├警告：本次航班机票已经售空！                                                          ┤\n");
            }
            printf("\t└───────────────────────────────────────────┘\n\n\n");
        }

        flight_s = flight_s->next;
        flightline_s = flightline_s->next;
    }
    if (count == 0) {
        printf("\t├警告：无此航班，请检查！                                                              ┤\n");
        printf("\t└───────────────────────────────────────────┘\n");
        system("pause");
        return;
    }
    int nav;
    printf("\n\n\n\t├是否继续订购机票？(0/1)                                                               ┤");
    printf("\r\t├是否继续订购机票？(0/1)");
    scanf("%d", &nav);
    if (nav == 1) {
        int flightid;
        printf("\n\n\n\t├请问您需要订购哪一次航班的机票？                                                      ┤");
        printf("\r\t├请问您需要订购哪一次航班的机票？");
        scanf("%d", &flightid);
        printf("\n\n\n\t├正在为您跳转到航班查询界面！                                                          ┤");
        Sleep(200);
        flightSearch(flightid);
    }
}

int book(int flightCode, int uuid, char name[10]) {
    flightInfo flight_s;
    ticketInfo ticket_s;
    ticketInfo temp;

    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);

    int ticketTime[5];

    ticketTime[0] = 1900 + p->tm_year;
    ticketTime[1] = 1 + p->tm_mon;
    ticketTime[2] = p->tm_mday;
    ticketTime[3] = p->tm_hour;
    ticketTime[4] = p->tm_min;

    flight_s = flight->next;
    ticket_s = ticket->next;

    while (flight_s) {
        if (flight_s->data.flightCode == flightCode && flight_s->data.amount != 0) {
            flight_s->data.amount -= 1;
            temp = (ticketInfo)malloc(sizeof(ticketInfoNode));
            temp->next = NULL;
            temp->data.flightCode = flightCode;
            strcpy(temp->data.userName, name);
            temp->data.uuid = uuid;
            temp->data.ticketTime[0] = ticketTime[0];
            temp->data.ticketTime[1] = ticketTime[1];
            temp->data.ticketTime[2] = ticketTime[2];
            temp->data.ticketTime[3] = ticketTime[3];
            temp->data.ticketTime[4] = ticketTime[4];
            ticket_s->next = temp;
            return 0;
        }

        flight_s = flight->next;
        ticket_s = ticket->next;
    }
    return 1;
}