/*
* nav.cpp
* (c)copyright 李沐阳 刘颖民 2016-2017 gench.edu.cn all right reserved.
****************************
* 导航菜单程序
*/
#include "nav.h"

void showNav() {
    int nav;
    printf("\n\n\n\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t┌─────────────────┐\n");
    printf("\t\t\t\t├    欢迎使用建桥航空订票系统！    ┤\n");
    printf("\t\t\t\t├─────────────────┤\n");
    printf("\t\t\t\t├      请选择您需要的服务内容      ┤\n");
    printf("\t\t\t\t└─────────────────┘\n");
    printf("\t\t\t\t**************************************\n");
    printf("\n\n\n");
    printf("\t\t\t\t  ┌───────────────┐\n");
    printf("\t\t\t\t  ├1.自助查询系统                ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├2.票务系统                    ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├3.退出系统                    ┤\n");
    printf("\t\t\t\t  └───────────────┘\n\n\n");
    printf("\t\t\t\t  ├请选择：                      ┤");
    printf("\r\t\t\t\t  ├请选择：");
    scanf("%d", &nav);
    switch (nav) {
    case 1: {
        infoNav();
        return;
    }
    case 2: {
        ticketNav();
        return;
    }
    case 3:
        exit(1);
    default:
        printf("\t\t\t\t  ├请选择：                      ┤");
        printf("\r输入错误，请重新输入！\t\t  ├请选择：");
        return;
    }
}


void infoNav() {
    system("cls");
    int nav;
    printf("\n\n\n\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t┌─────────────────┐\n");
    printf("\t\t\t\t├    欢迎使用建桥航空查询系统！    ┤\n");
    printf("\t\t\t\t├─────────────────┤\n");
    printf("\t\t\t\t├      请选择您需要的服务内容      ┤\n");
    printf("\t\t\t\t└─────────────────┘\n");
    printf("\t\t\t\t**************************************\n");
    printf("\n\n\n");
    printf("\t\t\t\t  ┌───────────────┐\n");
    printf("\t\t\t\t  ├1.客户信息查询                ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├2.航班信息查询                ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├3.返回主菜单                  ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├4.退出系统                    ┤\n");
    printf("\t\t\t\t  └───────────────┘\n\n\n");
    printf("\t\t\t\t  ├请选择：                      ┤");
    printf("\r\t\t\t\t  ├请选择：");
    while (true) {
        scanf("%d", &nav);
        switch (nav) {
        case 1:
            userSearch();
            return;
        case 2:
            int id;
            printf("\t\t\t\t  ├请输入航班编号：              ┤");
            printf("\r\t\t\t\t  ├请输入航班编号：");
            scanf("%d", &id);
            if (id) {
                flightSearch(id);
            }
            else {
                printf("\t\t\t\t  ├请输入航班编号：              ┤");
                printf("\r\t\t\t\t  ├请输入航班编号：");
            }
            return;
        case 3:
            return;
        case 4:
            exit(1);
        default:
            printf("\t\t\t\t  ├请选择：                      ┤");
            printf("\r输入错误，请重新输入！\t\t  ├请选择：");
            break;
        }
    }
}

void ticketNav() {
    system("cls");
    int nav;
    printf("\n\n\n\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t┌─────────────────┐\n");
    printf("\t\t\t\t├    欢迎使用建桥航空订票系统！    ┤\n");
    printf("\t\t\t\t├─────────────────┤\n");
    printf("\t\t\t\t├      请选择您需要的服务内容      ┤\n");
    printf("\t\t\t\t└─────────────────┘\n");
    printf("\t\t\t\t**************************************\n");
    printf("\n\n\n");
    printf("\t\t\t\t  ┌───────────────┐\n");
    printf("\t\t\t\t  ├1.使用航班编号查询            ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├2.使用航线信息查询            ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├3.返回主菜单                  ┤\n");
    printf("\t\t\t\t  ├───────────────┤\n");
    printf("\t\t\t\t  ├4.退出系统                    ┤\n");
    printf("\t\t\t\t  └───────────────┘\n\n\n");
    printf("\t\t\t\t  ├请选择：                      ┤");
    printf("\r\t\t\t\t  ├请选择：");
    while (true) {
        scanf("%d", &nav);
        switch (nav) {
        case 1:
            int id;
            printf("\t\t\t\t  ├请输入航班编号：              ┤");
            printf("\r\t\t\t\t  ├请输入航班编号：");
            scanf("%d", &id);
            if (id) {
                flightSearch(id);
            }
            else {
                printf("\t\t\t\t  ├请输入航班编号：                ┤");
                printf("\r\t\t\t\t  ├请输入航班编号：");
            }
            return;
        case 2:
            int line, timehMin, timehMax, timemMin, timemMax;
            printf("\t\t\t\t  ├请输入航线编号：                ┤");
            printf("\r\t\t\t\t  ├请输入航线编号：");
            scanf("%d", &line);
            printf("\t\t\t\t  ├请输入最早时间：           h:m  ┤");
            printf("\r\t\t\t\t  ├请输入最早时间：");
            scanf("%d:%d", &timehMin, &timemMin);
            printf("\t\t\t\t  ├请输入最晚时间：           h:m  ┤");
            printf("\r\t\t\t\t  ├请输入最晚时间：");
            scanf("%d:%d", &timehMax, &timemMax);

            flightLineSearch(line, timehMin, timemMin, timehMax, timemMax);
            return;
        case 3:
            return;
        case 4:
            exit(1);
        default:
            printf("\t\t\t\t  ├请选择：                      ┤");
            printf("\r输入错误，请重新输入！\t\t  ├请选择：");
            break;
        }
    }
}