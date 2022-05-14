#include "budget.h"
#include <stdio.h>

int selectMenu() {
    int menu;
    printf("\n*** 가계부 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createBudget(Budget* b) {
    printf("금액입력 (지출: - /수입: +) : ");
    scanf("%d", &b->income);
    total += b->income;
    printf("날짜입력: ");
    scanf("%s", b->date);
    printf("카테고리입력");
    printf(" (식사, 의료/건강, 카페/간식, 술/유흥, 의류/미용, 교통, 주거/통신, 생활, 문화/여가, 여행/숙박, 교육, 기타) : ");
    scanf("%s", b->category);
    printf("상세내역 : ");
    scanf("%s", b->expression);

    return 1;
}

void readBudget(Budget* b, int count) {
    printf("날짜   금액   카테고리   상세내역\n");
    printf("=================================\n");
    for(int i =0; i<count; i++) {
        if(b[i].income == -1) continue;
        printf("%d %s %d %s %s\n", i+1, b[i].date, b[i].income, b[i].category, b[i].expression);
    }
    printf("total : %d\n",total);
}

void updateBudget(Budget* b){

    printf("금액입력 (지출: - /수입: +) : ");
    scanf("%d", &b->income);
    printf("날짜입력: ");
    scanf("%s", b->date);
    printf("카테고리입력");
    printf(" (식사, 의료/건강, 카페/간식, 술/유흥, 의류/미용, 교통, 주거/통신, 생활, 문화/여가, 여행/숙박, 교육, 기타) : ");
    scanf("%s", b->category);
    printf("상세내역 : ");
    scanf("%s", b->expression);
    printf("==> 수정됨!\n");
}

int deleteBudget(Budget* b){
    b->income=-1;
    printf("==> 삭제됨!\n");
    return 0;
}

int selectDataNo(Budget* b, int count){
    int no;
    readBudget(b,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

void searchByDate(Budget* b, int count) {
    char search[20];
    int num = 0;
    printf("검색할 날짜는? ");
    scanf("%s", search);
    printf("===========================\n");
    for(int i=0; i<count; i++) {
        if(b[i].income == -1) continue;
        if(strstr(b[i].date, search)) {
            printf("%d %s %d %s %s\n", i+1, b[i].date, b[i].income, b[i].category, b[i].expression);;
            num++;
        }
    }
    if(num == 0) {
        printf("=> 검색된 데이터 없음\n");
    }
}

void searchByCategory(Budget* b, int count) {
    char search[20];
    int num = 0;
    printf("검색할 카테고리는? ");
    scanf("%s", search);
    printf("===========================\n");
    for(int i=0; i<count; i++) {
        if(b[i].income == -1) continue;
        if(strstr(b[i].category, search)) {
            printf("%d %s %d %s %s\n", i+1, b[i].date, b[i].income, b[i].category, b[i].expression);;
            num++;
        }
    }
    if(num == 0) {
        printf("=> 검색된 데이터 없음\n");
    }
}

void searchByMoney(Budget* b, int count) {
    int search;
    int num = 0;
    printf("검색할 지출 금액은 (만원단위입력)? ");
    scanf("%d", &search);
    printf("===========================\n");
    for(int i=0; i<count; i++) {
        if(b[i].income == -1) continue;
        if(b[i].income >= -search-9999 && b[i].income <= -search) {
            printf("%d %s %d %s %s\n", i+1, b[i].date, b[i].income, b[i].category, b[i].expression);;
            num++;
        }
    }
    if(num == 0) {
        printf("=> 검색된 데이터 없음\n");
    }
}
