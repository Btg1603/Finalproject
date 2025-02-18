// noi trien khai cac ham
#include "datatype.h"
#include <stdlib.h> 

int checkLogin(const char* username, const char* password) {
    FILE* file = fopen("admin.txt", "r");
    if (!file) {
        printf("Loi: Khong tim thay file admin.txt!\n");
        return 0;
    }
    
    char storedUser[MAX_LEN], storedPass[MAX_LEN];
    fscanf(file, "%s %s", storedUser, storedPass);
    fclose(file);
    
    return (strcmp(username, storedUser) == 0 && strcmp(password, storedPass) == 0);
}

void getPassword(char* password) {
    int index = 0;
    char ch;
    while ((ch = _getch()) != 13) { // 13 = Enter key
        if (ch == 8 && index > 0) { // 8 = Backspace
            printf("\b \b");
            index--;
            password[index] = '\0';
        } else if (ch != 8) {
            printf("*");
            password[index++] = ch;
        }
    }
    password[index] = '\0';
    printf("\n");
}




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
    do {
    system("cls"); 
    printf("\t=== ADD CATEGORY ===\n");
        
        
    if (*count >= MAX_CATEGORIES) {
    printf("Category list is full!\n");
    return;
    }

    Category newCategory;
    int isValid;
    do {
    isValid = 1;

  
    do {
    printf("Enter Category ID (max 9 chars): ");
    fflush(stdin);
    fgets(newCategory.CategoryId, sizeof(newCategory.CategoryId), stdin);
    newCategory.CategoryId[strcspn(newCategory.CategoryId, "\n")] = '\0';

    if (strlen(newCategory.CategoryId) == 0) {
    printf("Error: Category ID cannot be empty! Please enter again.\n");
    } else if (strlen(newCategory.CategoryId) >= sizeof(newCategory.CategoryId) - 1) {
    printf("Error: Category ID is too long (Max 9 chars). Please enter again.\n");
    } else {
    int duplicate = 0;
   
    for (int i = 0; i < *count; i++) {
    if (strcmp(categories[i].CategoryId, newCategory.CategoryId) == 0) {
    printf("Error: Category ID already exists! Please enter again.\n");
    duplicate = 1;
    break;
    }
    }
    if (!duplicate) break;
    }
    } while (1);

    
    do {
    printf("Enter Category Name (max 9 chars): ");
    fflush(stdin);
    fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
    newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = '\0';

    if (strlen(newCategory.CategoryName) == 0) {
    printf("Error: Category Name cannot be empty! Please enter again.\n");
    } else if (strlen(newCategory.CategoryName) >= sizeof(newCategory.CategoryName) - 1) {
    printf("Error: Category Name is too long (Max 9 chars). Please enter again.\n");
    } else {
    int duplicate = 0;
    
    for (int i = 0; i < *count; i++) {
    if (strcmp(categories[i].CategoryName, newCategory.CategoryName) == 0) {
    printf("Error: Category Name already exists! Please enter again.\n");
    duplicate = 1;
    break;
    }
    }
    if (!duplicate) break;
    }
    } while (1);

    } while (!isValid);

   // Add new category to the list
    categories[*count] = newCategory;
    (*count)++;
    printf("Category added successfully!\n");

    // Option to go back to Category Management
    printf("\nPress [0] back to (===CATEGORY MANAGEMENT===).\n");
    printf("Enter your choice: ");
    scanf("%d", &back);
    } while (back != 0);
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







#include "datatype.h"
#include <stdlib.h>


// noi trien khai cac ham

void displayProductMenu() { 
    printf("\n*** STORE MANAGER ***\n");
    printf("===PRODUCT MANAGEMENT===\n"); 
    printf("[1] Show Products\n");
    printf("[2] Add Products\n");
    printf("[3] Change Product\n");
    printf("[4] Delete Product\n");
    printf("[5] Sort Products\n");
    printf("[6] Search Product\n");
    printf("[0] Exit\n");
}

void showProducts(Product products[], int count) {
	int back;
	system("cls");
    printf("\t=== PRODUCT LIST ===\n");
    if (count == 0) {
    printf("No products available.\n"); 
    } else {
    printf("+------------+------------+---------------------+------------+-----------+\n");
    printf("| productId  | categoryId |productName          | quantity   | price     |\n");
    printf("+------------+------------+---------------------+------------+-----------+\n");
    
    for (int i = 0; i < count; i++) {
    printf("| %-10s | %-10s | %-19s | %-10d |%-10d |\n", products[i].productId, 
	products[i].categoryId,products[i].productName,products[i].quantity,products[i].price);
    printf("+------------+------------+---------------------+------------+-----------+\n");
    }
    printf("\nPress [0] to go back to (=== CATEGORY MANAGEMENT ===).\n");
    printf("Enter your choice: ");
	}
    while (scanf("%d", &back) != 1 || back != 0) {
    while (getchar() != '\n'); // Xoa bo nho dem 
    }
}


void addProduct(Product products[], int *count, Category categories[], int categoryCount) {
    int back;
    system("cls");
    printf("\t=== ADD PRODUCT ===\n");

    if (*count >= MAX_PRODUCTS) {
    printf("Products list is full!\n");
    return;
    }

    Product newProduct;
    int isValid;
    
    do {
    isValid = 1;  // Reset isValid

    printf("Enter Product ID (max 9 chars): ");
    fflush(stdin);
    fgets(newProduct.productId, sizeof(newProduct.productId), stdin);
    newProduct.productId[strcspn(newProduct.productId, "\n")] = '\0';

    if (strlen(newProduct.productId) == 0) {
    printf("? Error: Product ID cannot be empty! Please enter again.\n");
    isValid = 0;
    } else if (strlen(newProduct.productId) >= sizeof(newProduct.productId) - 1) {  // Ki?m tra vý?t quá 9 k? t?
    printf("? Error: Product ID is too long (Max 9 chars). Please enter again.\n");
    isValid = 0;
    } else {
    // Ki?m tra trùng Product ID
    for (int i = 0; i < *count; i++) {
    if (strcmp(products[i].productId, newProduct.productId) == 0) {
    printf("? Error: Product ID already exists! Please enter again.\n");
    isValid = 0;
    break;
    }
    }
    }
} while (!isValid);


    // Nhap Category ID
    int found;
    do {
    found = 0;
    printf("Enter Category ID (max 9 chars): ");
    fflush(stdin);
    fgets(newProduct.categoryId, sizeof(newProduct.categoryId), stdin);
    newProduct.categoryId[strcspn(newProduct.categoryId, "\n")] = '\0'; 

    for (int i = 0; i < categoryCount; i++) {
    if (strcmp(newProduct.categoryId, categories[i].CategoryId) == 0) {
    found = 1;
    break;
    }
    }
    if (!found) {
    printf("Error: Category ID is not available! Please enter again.\n");
    }
    } while (!found);

    // Nh?p Product Name
    printf("Enter Product Name (max 19 chars): ");
    fflush(stdin);
    fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
    newProduct.productName[strcspn(newProduct.productName, "\n")] = '\0';

    // Nh?p Quantity
    do {
    printf("Enter Quantity: ");
    if (scanf("%d", &newProduct.quantity) != 1 || newProduct.quantity < 0) {
    printf("Invalid quantity! Please enter a valid number.\n");
    while (getchar() != '\n');
    } else {
    break;
    }
    } while (1);

    // Nhap Price
    do {
    printf("Enter Price: ");
    if (scanf("%d", &newProduct.price) != 1 || newProduct.price < 0) {
    printf("Invalid price! Please enter a valid number.\n");
    while (getchar() != '\n');
    } else {
    break;
    }
    } while (1);

    // Kiem tra trung Product Name
    for (int i = 0; i < *count; i++) {
    if (strcmp(products[i].productName, newProduct.productName) == 0) {
    printf("Error: Product Name already exists!\n");
    return;
    }
    }

    
    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");

   
    printf("\nPress [0] back to (===PRODUCT MANAGEMENT===).\n");
    scanf("%d", &back);
    getchar();  // Xóa k? t? xu?ng d?ng c?n l?i
}



void changeProduct(Product products[], int count) {
    int back = 1;
    do {
    printf("\t=== CHANGE PRODUCT ===\n");
    char changeID[10];
    printf("Enter the ID product: ");
    scanf("%9s", changeID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < count; i++) {
    if (strcmp(products[i].productId, changeID) == 0) {
    found = 1;
               
    printf("+------------+------------+---------------------+------------+-----------+\n");
    printf("| productId  | categoryId |productName          | quantity   | price     |\n");
    printf("+------------+------------+---------------------+------------+-----------+\n");
    printf("| %-10s | %-10s | %-10s | %-10d |%-10d |\n", products[i].productId, 
    products[i].categoryId, products[i].productName, products[i].quantity, products[i].price);
    printf("+------------+------------+---------------------+------------+-----------+\n");

                
    printf("Enter the new product name: ");
    fgets(products[i].productName, sizeof(products[i].productName), stdin);
    products[i].productName[strcspn(products[i].productName, "\n")] = '\0';  // Xóa newline

    
    printf("Enter the new quantity: ");
    if (scanf("%d", &products[i].quantity) != 1 || products[i].quantity < 0) {
    printf("Invalid quantity! Please enter a valid number.\n");
    while (getchar() != '\n'); // Xóa b? ð?m
    }

    
    printf("Enter the new price: ");
    if (scanf("%d", &products[i].price) != 1 || products[i].price < 0) {
    while (getchar() != '\n'); // Xóa b? ð?m
    }

    printf("Product changed successfully!\n");

    // H?i ngý?i dùng có mu?n thay ð?i s?n ph?m khác không
    char choice;
    printf("Do you want to change another product ? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'n' || choice == 'N') {
    back = 0;
    }
    break;
        }
	}

    if (!found) {
    printf("ID is not available!\n");
    }
    } while (back != 0);
}

void deleteProduct(Product products[], int *count) {
    char deleteID[10];
    printf("Enter Product ID to delete: ");
    scanf("%s", deleteID);

    int found = 0;
    for (int i = 0; i < *count; i++) {
    if (strcmp(products[i].productId, deleteID) == 0) {
    found = 1;
    // Confirmation to delete
    char confirm;
    printf("Are you sure you want to delete this product? (y/n): ");
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
    // Delete product
    for (int j = i; j < *count - 1; j++) {
    products[j] = products[j + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
	} else {
    printf("Product deletion canceled.\n");
    }
    break;
    }
    }
    if (!found) {
        printf("Product ID does not exist!\n");
    }
}


void searchProduct(Product products[], int count) {
    char searchName[10];
    printf("Enter product name to search: ");
    getchar(); // Clear newline
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    int found = 0;
    printf("+------------+------------+------------+------------+-----------+\n");
    printf("| productId  | productName | categoryId | quantity   | price     |\n");
    printf("+------------+------------+------------+------------+-----------+\n");
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].productName, searchName)) {
            printf("| %-10s | %-10s | %-10s | %-10d | %-10d |\n", 
                    products[i].productId, products[i].productName, 
                    products[i].categoryId, products[i].quantity, products[i].price);
            found = 1;
        }
    }
    printf("+------------+------------+------------+------------+-----------+\n");
    if (!found) {
        printf("No products found!\n");
    }
}


void sortProductsByPrice(Product products[], int *count) {
    int choice;
    printf("Select sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < *count - 1; i++) {
        for (int j = i + 1; j < *count; j++) {
            if ((choice == 1 && products[i].price > products[j].price) || 
                (choice == 2 && products[i].price < products[j].price)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    printf("Product sorted\n");
}

void saveToFile(Product products[], int count) {
    FILE *file = fopen("product.bin", "wb");
    if (file == NULL) {
    printf("Cannot save data!\n");
    return;
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(products, sizeof(Product), count, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile(Product products[], int *count) {
    FILE *file = fopen("product.bin", "rb");
    if (file == NULL) {
    printf("Cannot load data!\n");
    *count=0;
    return;
    }
    fread(count, sizeof(int), 1, file);
    fread(products, sizeof(Product),*count, file);
    fclose(file);
    printf("Data loaded successfully!\n");
}




 
