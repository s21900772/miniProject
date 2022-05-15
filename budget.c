#include "budget.h"
#include <stdio.h>
#include <string.h>

int selectMenu()
{
    int menu;
    printf("\n*** ����� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ����\n");
    printf("6. ��¥�� �˻�\n");
    printf("7. ī�װ��� �˻�\n");
    printf("8. �ݾ����� �˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int createBudget(Budget *b)
{
    printf("�ݾ��Է� (����: - /����: +) : ");
    scanf("%d", &b->income);
    total += b->income;
    getchar();
    printf("��¥�Է�: ");
    scanf("%[^\n]", b->date);
    getchar();
    printf("ī�װ��Է�");
    printf(" (�Ļ�, �Ƿ�/�ǰ�, ī��/����, ��/����, �Ƿ�/�̿�, ����, �ְ�/���, ��Ȱ, ��ȭ/����, ����/����, ����, ��Ÿ) : ");
    scanf("%[^\n]", b->category);
    getchar();
    printf("�󼼳��� : ");
    scanf("%[^\n]", b->expression);
    printf("==> ��ϵ�!\n");

    return 1;
}

void readBudget(Budget *b, int count)
{
    printf("count: %d\n",count);
    printf("��¥   �ݾ�   ī�װ�   �󼼳���\n");
    printf("=================================\n");
    for (int i = 0; i < count; i++)
    {
        if (b[i].income == -1)
            continue;
        printf("%d %s %d %s %s\n", i + 1, b[i].date, b[i].income, b[i].category, b[i].expression);
    }
    printf("total : %d\n", total);
}

void updateBudget(Budget *b)
{

    printf("�ݾ��Է� (����: - /����: +) : ");
    scanf("%d", &b->income);
    getchar();
    printf("��¥�Է�: ");
    scanf("%[^\n]", b->date);
    getchar();
    printf("ī�װ��Է�");
    printf(" (�Ļ�, �Ƿ�/�ǰ�, ī��/����, ��/����, �Ƿ�/�̿�, ����, �ְ�/���, ��Ȱ, ��ȭ/����, ����/����, ����, ��Ÿ) : ");
    scanf("%[^\n]", b->category);
    getchar();
    printf("�󼼳��� : ");
    scanf("%[^\n]", b->expression);
    printf("==> ������!\n");
}

int deleteBudget(Budget *b)
{
    b->income = -1;
    printf("==> ������!\n");
    return 0;
}

int selectDataNo(Budget *b, int count)
{
    int no;
    readBudget(b, count);
    printf("��ȣ�� (���:0)?");
    scanf("%d", &no);
    getchar();
    return no;
}

void searchByDate(Budget *b, int count)
{
    char search[20];
    int num = 0;
    getchar();
    printf("�˻��� ��¥��? ");
    scanf("%[^\n]", search);
    printf("===========================\n");
    for (int i = 0; i < count; i++)
    {
        if (b[i].income == -1)
            continue;
        if (strstr(b[i].date, search))
        {
            printf("%d %s %d %s %s\n", i + 1, b[i].date, b[i].income, b[i].category, b[i].expression);
            num++;
        }
    }
    if (num == 0)
    {
        printf("=> �˻��� ������ ����\n");
    }
}

void searchByCategory(Budget *b, int count)
{
    char search[20];
    int num = 0;
    getchar();
    printf("�˻��� ī�װ���? ");
    scanf("%[^\n]", search);
    printf("===========================\n");
    for (int i = 0; i < count; i++)
    {
        if (b[i].income == -1)
            continue;
        if (strstr(b[i].category, search))
        {
            printf("%d %s %d %s %s\n", i + 1, b[i].date, b[i].income, b[i].category, b[i].expression);
            num++;
        }
    }
    if (num == 0)
    {
        printf("=> �˻��� ������ ����\n");
    }
}

void searchByMoney(Budget *b, int count)
{
    int search;
    int num = 0;
    printf("�˻��� ���� �ݾ��� (���������Է�)? ");
    scanf("%d", &search);
    printf("===========================\n");
    for (int i = 0; i < count; i++)
    {
        if (b[i].income == -1)
            continue;
        if (b[i].income >= -search - 9999 && b[i].income <= -search)
        {
            printf("%d %s %d %s %s\n", i + 1, b[i].date, b[i].income, b[i].category, b[i].expression);
            num++;
        }
    }
    if (num == 0)
    {
        printf("=> �˻��� ������ ����\n");
    }
}

void saveFile(Budget* b, int count)
{
    FILE *fp;

    fp = fopen("budget.txt", "wt");
    for (int i = 0; i < count; i++)
    {
        if (b[i].income == -1)
        {
            continue;
        }

        fprintf(fp, "%s, %d, %s, %s\n", b[i].date, b[i].income, b[i].category, b[i].expression);
    }

    fclose(fp);
    printf("�����!\n");
}

int LoadFile(Budget *b)
{
    int count = 0;
    FILE *fp;

    if ((fp = fopen("budget.txt", "r")) == NULL)
    {
        printf("=> ���� ����\n");
        return count;
    }

    else
    {
        while (1)
        {
            if (fscanf(fp, "%[^,], %d, %[^,], %[^\n]\n", b[count].date, &b[count].income, b[count].category, b[count].expression) != -1)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }

    total = 0;
    for(int i = 0; i<count; i++) {
        total += b[i].income;
    }
    printf("=> �ε� ����!\n");
    return count;
}
