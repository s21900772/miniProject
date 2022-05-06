typedef struct{
	int income;
	char date[64];
	char category[10];
	char expression[128];
} Budget;

int LoadFile(Budget* b);
int selectMenu();
int createBudget(Budget* b);
void readBudget(Budget* b, int count);
void updateBudget(Budget* b);
int deleteBudget(Budget* b);
void searchByDate(Budget* b, int count);
void searchBykind(Budget* b, int count);
void searchMoney(Budget* b, int count);
void saveFile(Budget* b, int count);
int selectDataNo(Budget* b, int count);
