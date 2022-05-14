#include <stdio.h>
#include "budget.h"

int main(){
    
    Budget slist[100];
    int curcount=0;
    int count = 0, menu;
    
    //count = loadData(slist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf(" 데이터가 없습니다!\n");
			    continue;
			}
		}

        if(menu == 1) {
            readBudget(slist,curcount); 
        }

        else if (menu == 2) {
            count+=createBudget(&slist[curcount++]); 
        }

        else if (menu == 3) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            updateBudget(&slist[no-1]);
        }

        else if (menu == 4) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteBudget(&slist[no-1])) count --;       
           	 } 
        }

        else if (menu == 6) {
            searchByDate(slist, count);
        }

        else if (menu == 7) {
            searchByCategory(slist, count);
        }

        else if (menu == 8) {
            searchByMoney(slist, count);
        }
	}

	printf("\n종료됨!\n");
   	return 0;
}
