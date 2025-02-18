#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "function.h"
#include "datatype.h"
 
int main() {
	
char username[MAX_LEN], password[MAX_LEN];

    printf("===== ADMIN LOGIN =====\n");
    while (1) {
    printf("Username: ");
    scanf("%s", username);
        
    printf("Password: ");
    getPassword(password);
        
    if (checkLogin(username, password)) {
    printf("\nLogin successful!\n");
    break;
    } else {
    printf("\nInvalid username or password! Please try again.\n");
    }
    }

	
	
	system("cls");
    Category categories[MAX_CATEGORIES];
    int categoryCount = 0;   
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
    system("cls");
    displayStoreManager();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: { 
                int categoryChoice;
                do {
                system("cls");
                displayCategoryMenu();
                printf("Enter your choice: ");
                scanf("%d", &categoryChoice);

                switch (categoryChoice) {
                case 1:
                loadCategoriesFromBinaryFile(categories, &categoryCount);
                showCategories(categories, categoryCount);
                break;
                case 2:
                addCategory(categories, &categoryCount);
                saveCategoriesToBinaryFile(categories, categoryCount );
                break;
                case 3:
                loadCategoriesFromBinaryFile(categories, &categoryCount);
                changeCategory(categories, categoryCount);
                saveCategoriesToBinaryFile(categories, categoryCount );
                break;
                case 4:
                loadCategoriesFromBinaryFile(categories, &categoryCount);
                deleteCategory(categories, &categoryCount);
                saveCategoriesToBinaryFile(categories, categoryCount );
                break;
                case 5:
                loadCategoriesFromBinaryFile(categories, &categoryCount);
                sortCategories(categories, categoryCount);
                saveCategoriesToBinaryFile(categories, categoryCount );
                break;
                case 6:
                loadCategoriesFromBinaryFile(categories, &categoryCount);
                searchCategory(categories, categoryCount);	
				break; 
                case 0:
                printf("Returning to Store Manager...\n");
                break;
                default:
                printf("Invalid choice! Try again.\n");
                }
                } while (categoryChoice != 0);
                break;
            	}
            
    case 2: {
                int productChoice;
                do {
                system("cls");
                displayProductMenu();
                printf("Enter your choice: ");
                scanf("%d", &productChoice);

                switch (productChoice) {
                case 1:
                loadFromFile(products,&productCount);
                showProducts(products,productCount);            
                break;
                case 2:
                loadCategoriesFromBinaryFile(categories, &categoryCount);
            	addProduct(products,&productCount,categories,categoryCount);
				saveToFile(products,productCount);           
                break;
                case 3:
                system("cls");
                loadFromFile(products,&productCount);
                changeProduct(products,productCount);
				saveToFile(products,productCount);          
                break;
                case 4:
                loadFromFile(products,&productCount);
                deleteProduct(products,&productCount); 
				saveToFile(products,productCount);          
                break;
                case 5:
                loadFromFile(products,&productCount);
                searchProduct(products,productCount);            
                break;
                case 6:
                loadFromFile(products,&productCount);
                sortProductsByPrice(products,&productCount);
                saveToFile(products,productCount);
				break; 
                case 0:
                printf("Returning to Store Manager...\n");
                break;
                default:
                printf("Invalid choice! Try again.\n");
                }
                } while (productChoice != 0);
                break;
            	}

    case 0:
			    printf("Exiting Store Manager...\n");
			    break;

			    default:
			    printf("Invalid choice! Try again.\n");
			    }
    } while (choice != 0);
    return 0;
}

 
