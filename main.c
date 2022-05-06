#include <stdio.h>
#include <string.h>
#include "budget.h"

int main(void){
    
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
                printf(" �����Ͱ� �����ϴ�!\n");
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
                printf("=>��ҵ�!");
                continue;
            }
            updateBudget(&slist[no-1]);
        }

        else if (menu == 4) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>��ҵ�!");
                continue;
            }
            int deleteok;
            printf("������ �����Ͻðڽ��ϱ�?(����:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteBudget(&slist[no-1])) count --;       
           	 } 
        }
	}

	printf("\n�����!\n");
   	return 0;
}