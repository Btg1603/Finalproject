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
    printf("+------------+------------+------------+------------+------------+\n");
    printf("| productId  | categoryId |productName | quantity   | price      |\n");
    printf("+------------+------------+------------+------------+------------+\n");
    
    for (int i = 0; i < count; i++) {
    printf("| %-10s | %-10s | %-10s | %-10s |%-10s |\n", products[i].productId, 
	products[i].categoryId,products[i].productName,products[i].quantity,products[i].price);
    printf("+------------+------------+------------+------------+------------+\n");
    }
    printf("\nPress [0] to go back to (=== CATEGORY MANAGEMENT ===).\n");
    printf("Enter your choice: ");
	}
    while (scanf("%d", &back) != 1 || back != 0) {
    while (getchar() != '\n'); // Xoa bo nho dem 
    }
}


void addProduct(Product products[], int *count, Category categories[], int categoryCount) {
    int back,found;
    do {
    system("cls");
    printf("\t=== ADD PRODUCT ===\n");
    if (*count >= MAX_PRODUCTS) {
        printf("Products list is full!\n");
        return;
    }

    Product newProduct;
    int isValid;
    do {
    isValid = 1;

	
	do{
    printf("Enter Product ID (max 9 chars): ");
    fflush(stdin);
    fgets(newProduct.productId, sizeof(newProduct.productId), stdin);
    newProduct.productId[strcspn(newProduct.productId, "\n")] = '\0';
    
    if (strlen(newProduct.productId)==0){
    printf("Error: Product ID cannot be empty! Please enter again.\n"); 
	}else if(strlen(newProduct.productId)>=sizeof(newProduct.productId)-1){
	printf("Error: Product ID is too long (Max 9 chars). Please enter again.\n");
	} 
	} while (newProduct.productId == 0 || strlen(newProduct.productId) >= sizeof(newProduct.productId) - 1);
    
    
//	do{
//    printf("Enter Category ID (max 9 chars): ");
//    fflush(stdin);
//    fgets(newProduct.categoryId, sizeof(newProduct.categoryId), stdin);
//    newProduct.categoryId[strcspn(newProduct.categoryId, "\n")] = '\0';
//    
//    if (strlen(newProduct.categoryId) == 0) {
//    printf("Error: Category ID cannot be empty! Please enter again.\n");
//    } else for(int i=0;i<count;i++){
//	if (newProduct.categoryId!=categories[i].CategoryId){
//    printf("Error: Category ID is not available!\n");	
//	}
//	}
//	
//    } while (newProduct.categoryId==categories[i].CategoryId||newProduct.CategoryId == 0||strlen(newProduct.productId) >= sizeof(newProduct.productId) - 1);

 
do {
    int found = 0 ; // kiem tra xem category id co ton tai khong 
    
    printf("Enter Category ID (max 9 chars): ");
    fflush(stdin);
    fgets(newProduct.categoryId, sizeof(newProduct.categoryId), stdin);
    newProduct.categoryId[strcspn(newProduct.categoryId, "\n")] = '\0'; // Lo?i b? k? t? xu?ng d?ng

    if (strlen(newProduct.categoryId) == 0) {
    printf("Error: Category ID cannot be empty! Please enter again.\n");
    continue; //quay lai nhap lai 
    }

    for (int i = 0; i < count; i++) {
    if (strcmp(newProduct.categoryId, categories[i].CategoryId) == 0) {
    found = 1; // id ton tai 
    break;
    }
    }

    if (!found) {
    printf("Error: Category ID is not available! Please enter again.\n");
    }

} while (!found);
 
 
 
 
 
    
	// Nh?p Product Name
    printf("Enter Product Name (max 9 chars): ");
    fflush(stdin);
    fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
    newProduct.productName[strcspn(newProduct.productName, "\n")] = '\0';


    // Nh?p Quantity
    printf("Enter Quantity: ");
    if (scanf("%d", &newProduct.quantity) != 1 || newProduct.quantity < 0) {
    printf("Invalid quantity! Please enter a valid number.\n");
    isValid = 0;
    while (getchar() != '\n'); // Xóa b? nh? ð?m
    continue;
    }
    // Nh?p Price
    printf("Enter Price: ");
    if (scanf("%d", &newProduct.price) != 1 || newProduct.price < 0) {
    printf("Invalid price! Please enter a valid number.\n");
    isValid = 0;
    while (getchar() != '\n');
    continue;
    }


    // Ki?m tra Product ID và Product Name có b? trùng không
    for (int i = 0; i < *count; i++) {
    if (strcmp(products[i].productId, newProduct.productId) == 0) {
    printf("Error: Product ID already exists!\n");
    isValid = 0;
    }
    if (strcmp(products[i].productName, newProduct.productName) == 0) {
    printf("Error: Product Name already exists!\n");
    isValid = 0;
    }
    }


    // Ki?m tra Category ID có t?n t?i không
    int categoryExists = 0;
    for (int i = 0; i < categoryCount; i++) {
    if (strcmp(categories[i].CategoryId, newProduct.categoryId) == 0) {
    categoryExists = 1;
    break;
    }
    }
    if (!categoryExists) {
    printf("Error: Category ID does not exist!\n");
    isValid = 0;
    }

	if (!isValid) {
	printf("Please enter product information again!\n\n");
    }
    } while (!isValid);


    // Thêm s?n ph?m vào danh sách
    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");

    printf("\nPress [0] back to (===PRODUCT MANAGEMENT===).\n");
    printf("Enter your choice: ");
    scanf("%d", &back);
    } while (back != 0);
}





