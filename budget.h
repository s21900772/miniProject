typedef struct{
	int income;
	char date[64];
	char category[10];
	char expression[128];
} Budget;

int LoadFile(Budget* b);
void selectMenu();
void createBudget(Budget* b, int price);
void readBudget(Budget* b, int count);
void updateBudget(Budget* b, int count);
void deleteBudget(Budget* b, int count);
void searchByDate(Budget* b, int count);
void searchBykind(Budget* b, int count);
void searchMoney(Budget* b, int count);
void saveFile(Budget* b, int count);
