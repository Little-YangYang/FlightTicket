#include "nav.h"

void showNav() {
    int nav;
    printf("\n\n\n\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t��������������������������������������\n");
    printf("\t\t\t\t��    ��ӭʹ�ý��ź��ն�Ʊϵͳ��    ��\n");
    printf("\t\t\t\t��������������������������������������\n");
    printf("\t\t\t\t��      ��ѡ������Ҫ�ķ�������      ��\n");
    printf("\t\t\t\t��������������������������������������\n");
    printf("\t\t\t\t**************************************\n");
    printf("\n\n\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��1.������ѯϵͳ                ��\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��2.Ʊ��ϵͳ                    ��\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��3.�˳�ϵͳ                    ��\n");
    printf("\t\t\t\t  ����������������������������������\n\n\n");
    printf("\t\t\t\t  ����ѡ��                      ��");
    printf("\r\t\t\t\t  ����ѡ��");
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
        printf("\t\t\t\t  ����ѡ��                      ��");
        printf("\r����������������룡\t\t  ����ѡ��");
        return;
    }
}


void infoNav() {
    system("cls");
    int nav;
    printf("\n\n\n\n");
    printf("\t\t\t\t**************************************\n");
    printf("\t\t\t\t��������������������������������������\n");
    printf("\t\t\t\t��    ��ӭʹ�ý��ź��ղ�ѯϵͳ��    ��\n");
    printf("\t\t\t\t��������������������������������������\n");
    printf("\t\t\t\t��      ��ѡ������Ҫ�ķ�������      ��\n");
    printf("\t\t\t\t��������������������������������������\n");
    printf("\t\t\t\t**************************************\n");
    printf("\n\n\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��1.�ͻ���Ϣ��ѯ                ��\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��2.������Ϣ��ѯ                ��\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��3.�������˵�                  ��\n");
    printf("\t\t\t\t  ����������������������������������\n");
    printf("\t\t\t\t  ��4.�˳�ϵͳ                    ��\n");
    printf("\t\t\t\t  ����������������������������������\n\n\n");
    printf("\t\t\t\t  ����ѡ��                      ��");
    printf("\r\t\t\t\t  ����ѡ��");
    while (true) {
        scanf("%d", &nav);
        switch (nav) {
        case 1:
            userSearch();
            return;
        case 2:
        case 3:
            return;
        case 4:
            exit(1);
        default:
            printf("\t\t\t\t  ����ѡ��                      ��");
            printf("\r����������������룡\t\t  ����ѡ��");
            break;
        }
    }
}

void ticketNav() {

}