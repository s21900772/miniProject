typedef struct{
	char date[64];
	int income;
	char kind[128];
} Budget;

int LoadFile(Budget* b);
void selectMenu();
void addIcome(Budget* b, int price);
void addOutgo(Budget* b, int price);
void readBudget(Budget* b, int count);
void updateBudget(Budget* b, int count);
void deleteBudget(Budget* b, int count);
void searchByDate(Budget* b, int count);
void searcgBykind(Budget* b, int count);
void saveFile(Budget* b, int count);