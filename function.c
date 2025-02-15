// noi trien khai cac ham
#include "datatype.h"
#include <stdlib.h> 
void displayCategoryMenu() { 
    printf("\n*** STORE MANAGER ***\n");
    printf("===CATEGORY MANAGEMENT===\n"); 
    printf("[1] Show Categories\n");
    printf("[2] Add Category\n");
    printf("[3] Change Category\n");
    printf("[4] Delete Category\n");
    printf("[5] Sort Category\n");
    printf("[6] Search Category\n");
    printf("[0] Exit\n");
}

void displayStoreManager() { 
    printf("\n*** STORE MANAGER ***\n"); 
    printf("[1] Category Managerment\n");
    printf("[2] Product Managerment\n");
    printf("[0] Exit\n");
}


void showCategories(Category categories[], int count) {
    int back; 
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
    }

    
    printf("\nPress [0] to go back to (=== CATEGORY MANAGEMENT ===).\n");
    printf("Enter your choice: ");

    while (scanf("%d", &back) != 1 || back != 0) {
    while (getchar() != '\n'); // Xoa bo nho dem 
    }
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
    int isValid=0;
	do{
	isValid=1;

    do {
    printf("Enter Category ID (max 9 chars): ");
    // xoa bo dem truoc khi nhap 
    fflush(stdin);
    fgets(newCategory.CategoryId, sizeof(newCategory.CategoryId), stdin);
    newCategory.CategoryId[strcspn(newCategory.CategoryId, "\n")] = '\0';
	  
    if (strlen(newCategory.CategoryId) == 0) {
    printf("Error: Category ID cannot be empty! Please enter again.\n");
    } else if (strlen(newCategory.CategoryId) >= sizeof(newCategory.CategoryId) - 1) {
    printf("Error: Category ID is too long (Max 9 chars). Please enter again.\n");
    }
    } while (strlen(newCategory.CategoryId) == 0 || strlen(newCategory.CategoryId) >= sizeof(newCategory.CategoryId) - 1);
	
	do{
    printf("Enter Category Name (max 9 chars): ");
    // xoa bo dem truoc khi nhap 
    fflush(stdin);
    fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
    newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = '\0';
		
	if (strlen(newCategory.CategoryName) == 0) {
    printf("Error: Category Name cannot be empty! Please enter again.\n");
    } else if (strlen(newCategory.CategoryName) >= sizeof(newCategory.CategoryName)-1) {
    printf("Error: Category Name is too long (Max 9 chars). Please enter again.\n");
    }
    } while (strlen(newCategory.CategoryName) == 0 || strlen(newCategory.CategoryName)>= sizeof(newCategory.CategoryName)-1 );

	 
	// Kiem tra ID va ten khong duoc de trong
	if (strlen(newCategory.CategoryId)==0||strlen(newCategory.CategoryName)==0){
		printf("Error: Category ID and Name cannot be empty!\n");
		isValid=0; 
	} 
    // Kiem tra ID va ten danh muc co bi trung khong
    for (int i = 0; i < *count; i++) {
        if (strcmp(categories[i].CategoryId, newCategory.CategoryId) == 0 || 
            strcmp(categories[i].CategoryName, newCategory.CategoryName) == 0) {
            printf("Error: Category ID or Name already exists!\n");
            isValid=0; 
        }
    }
    if (!isValid){
    	printf("Please enter valid Category information again!\n\n"); 
	} 
}while(!isValid);
 //neu hop le them vao danh sach 
    categories[*count] = newCategory;
    (*count)++;
    printf("Category added successfully!\n");
    
    printf("\nPress [0] back to (===CATEGORY MANAGEMENT===).\n");
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

void deleteCategory(Category categories[], int *count) {
    int back;
    do {
    system("cls");
    printf("\t=== DELETE CATEGORY ===\n");

    if (*count == 0) {
    printf("No categories available to delete!\n");
    } else {
    char deleteID[10];
    printf("Enter the Category ID to delete: ");
    scanf("%9s", deleteID);

    int found = -1;
    for (int i = 0; i < *count; i++) {
    if (strcmp(categories[i].CategoryId, deleteID) == 0) {
    found = i;
    break;
    }
    }

    if (found == -1) {
    printf("Category ID not found!\n");
    } else {
    char confirm;
    printf("Are you sure you want to delete ID:%s (y/n): ", deleteID);
    scanf(" %c", &confirm); // dau cach truoc %c tranh loi nhap 

    if (confirm == 'y' || confirm == 'Y') {
    // neu chi con 1 danh muc cho count=0 
    if (*count == 1) {
    *count = 0;
    } else {
    // Dich danh sach xuong de xoa phan tu 
    for (int i = found; i < *count - 1; i++) {
    categories[i] = categories[i + 1];
    }
    (*count)--;
    }
    printf("Category deleted successfully!\n");
    } else {
    printf("Delete operation canceled.\n");
    }
    }
    }

    printf("\nPress [0] to go back to (===CATEGORY MANAGEMENT===).\n");
    printf("Enter your choice: ");
    while (scanf("%d", &back) != 1 || back != 0) {
    while (getchar() != '\n');
    }

    }while (back != 0);
}


void sortCategories(Category categories[],int count){
if (count == 0){
	printf("No categories available to sort !\n");
	return; 
}
int choice;
printf("\nSelect sorting order: \n");
printf("[1] Ascending (A-Z)\n");
printf("[2] Descending (Z-A)\n");
printf("Enter choice: ");
scanf("%d",&choice);

for (int i=0;i<count-1;i++){
for (int j=i+1;j<count;j++){
if (choice==1&&strcmp(categories[i].CategoryName,categories[j].CategoryName)>0
||choice==2&&strcmp(categories[i].CategoryName,categories[j].CategoryName)<0){
	Category temp=categories[i];
	categories[i]=categories[j];
	categories[j]=temp;	
}	
}		
}
printf("\nCategories sorted successfully!\n");
showCategories(categories, count); 
}
void searchCategory(Category categories[],int count){
int back;
do{
system("cls");
printf("\t=== SEARCH CATEGORY ===\n");
if (count == 0) {
printf("No categories available.\n");	
}else{
char searchName[10];
printf("Enter category name to search: ");
getchar();
fgets(searchName,sizeof(searchName),stdin);
searchName[strcspn(searchName, "\n")]='\0';
int found=0;
printf("\nSearch Result:\n");
printf("+----------+----------+\n");
printf("|CategoryID| Name     |\n");
printf("+----------+----------+\n");

for (int i =0;i<count;i++){
	if(strstr(categories[i].CategoryName, searchName)!=NULL){
	printf("|%-10s|%-10s|\n",categories[i].CategoryId,categories[i].CategoryName);  
	printf("+----------+----------+\n");
	found=1; 
	} 
}
if(!found){
	printf("No matching categories found!\n"); 
} 
}
printf("\nPress [0] back to (===CATEGORY MANAGERMENT===).\n");
printf("Enter your choice");
scanf("%d",&back);	
}while(back!=0);
}

void saveCategoriesToBinaryFile(Category categories[], int count){
FILE *file=fopen("category.bin","wb");
if(file==NULL){
	printf("Error: Could not open file for saving categories!\n");
	return;	 
}
fwrite(&count,sizeof(int),1,file);
fwrite(categories,sizeof(Category),count,file);
fclose(file);
printf("Categories saved successfully! \n");	
}

void loadCategoriesFromBinaryFile(Category categories[],int *count){
FILE *file=fopen("category.bin","rb");
if(file == NULL){
	printf("Error: Could not open file for load categories!\n");
	*count=0; 
	return; 
}     
fread(count,sizeof(int),1,file);
fread(categories,sizeof(Category),*count,file);
fclose(file);
printf("Categories load from file successfully! \n"); 
} 






 
