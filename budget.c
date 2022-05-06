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
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}
