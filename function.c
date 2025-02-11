// noi trien khai cac ham
#include "datatype.h"
 
void displayCategoryMenu() { 
    printf("\n*** STORE MANAGER ***\n");
    printf("===CATEGORY MANAGEMENT===\n"); 
    printf("[1] Show Categories\n");
    printf("[2] Add Category\n");
    printf("[3] Change Category\n");
    printf("[0] Exit\n");
    printf("Enter your choice: ");
}

void showCategories(Category categories[], int count) {
	int back;
	do{
	system("cls");
    printf("\t=== CATEGORY LIST ===\n");
    if (count == 0) {
    printf("No categories available.\n");
    } else {
    printf("+------------+------------+\n");
    printf("| CategoryID | Name       |\n");
    printf("+------------+------------+\n");
    for (int i = 0; i < count; i++) {
    printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
    printf("+------------+------------+\n");
    }
     
    printf("\n[0] Back to (===CATEGORY MANAGEMENT===).\n");
    printf("Enter your choice: ");
	scanf("%d",&back); 
    }
}while(back!=0);
}

void addCategory(Category categories[], int *count) {
	int back;
	do{
	system("cls"); 
    printf("\t=== ADD CATEGORY ===\n");
	if (*count >= MAX_CATEGORIES) {
    printf("Category list is full!\n");
    return;
    }

    Category newCategory;
    printf("Enter Category ID (max 9 chars): ");
    scanf("%9s", newCategory.CategoryId);

    printf("Enter Category Name (max 9 chars): ");
    getchar(); // xoa bo dem
    fgets(newCategory.CategoryName , sizeof(newCategory.CategoryName),stdin);
    // xoa ki tu xuong dong 
    newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")]  = '\0';

    // Kiem tra ID va ten danh muc co bi trung khong
    for (int i = 0; i < *count; i++) {
        if (strcmp(categories[i].CategoryId, newCategory.CategoryId) == 0 || 
            strcmp(categories[i].CategoryName, newCategory.CategoryName) == 0) {
            printf("Error: Category ID or Name already exists!\n");
            return;
        }
    }

    categories[*count] = newCategory;
    (*count)++;
    printf("Category added successfully!\n");
    printf("\n[0] Back to (===CATEGORY MANAGEMENT===).\n");
    printf("Enter your choice: ");
	scanf("%d",&back);
}while(back!=0); 
}


void changeCategory(Category categories[], int count) {
	int back; 
	do{
	system("cls"); 
    printf("\t=== CHANGE CATEGORY ===\n");
	char changeID[10];
    printf("Enter the ID of the Category you want to edit: ");
    scanf("%9s", changeID);
    getchar(); //loai bo ki tu newline 

    // Tim kiem danh muc voi id tuong ung 
    int found = 0;
    for (int i = 0; i < count; i++) {
    if (strcmp(categories[i].CategoryId, changeID) == 0) {
    found = 1;
    printf("Enter the new Category Name (max 9 chars): ");
    fgets(categories[i].CategoryName, sizeof(categories[i].CategoryName), stdin);
    // xoa ki tu newline 
    categories[i].CategoryName[strcspn(categories[i].CategoryName, "\n")] = '\0';
    printf("Category changed successfully!\n");
    break;
    }
    }

    if (!found) {
    printf("The ID you entered does not exist!\n");
    }
}while(back!=0); 
}





 
