#include "budget.h"
#include <stdio.h>

int selectMenu() {
    int menu;
    printf("\n*** ����� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int createBudget(Budget* b) {
    printf("�ݾ��Է� (����: - /����: +) : ");
    scanf("%d", &b->income);
    printf("��¥�Է�: ");
    scanf("%s", b->date);
    printf("ī�װ��Է�");
    printf(" (�Ļ�, �Ƿ�/�ǰ�, ī��/����, ��/����, �Ƿ�/�̿�, ����, �ְ�/���, ��Ȱ, ��ȭ/����, ����/����, ����, ��Ÿ) : ");
    scanf("%s", b->category);
    printf("�󼼳��� : ");
    scanf("%s", b->expression);

    return 1;
}

void readBudget(Budget* b, int count) {
    printf("��¥   �ݾ�   ī�װ�   �󼼳���\n");
    printf("=================================\n");
    for(int i =0; i<count; i++) {
        if(b[i].income == -1) continue;
        printf("%s %d %s %s\n", b[i].date, b[i].income, b[i].category, b[i].expression);
    }
}

void updateBudget(Budget* b) {

}
int deleteBudget(Budget* b) {
    return 0;
}

int selectDataNo(Budget* b, int count){
    int no;
    readBudget(b,count);
    printf("��ȣ�� (���:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}
