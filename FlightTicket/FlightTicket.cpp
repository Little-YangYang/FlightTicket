// homework19.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "init.h"
#include "dataList.h"
#include "nav.h"

extern flightLineInfo flightLine;
extern flightInfo flight;
extern ticketInfo ticket;
int main() {
    init();
    while (1) {
        showNav();
        system("cls");
    }
    system("pause");
    return 0;
}

