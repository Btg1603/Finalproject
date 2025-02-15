#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"
#include "functionproduct.h" 
int main() {
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
                changeCategory(categories, categoryCount);
                saveCategoriesToBinaryFile(categories, categoryCount );
                break;
                case 4:
                deleteCategory(categories, &categoryCount);
                saveCategoriesToBinaryFile(categories, categoryCount );
                break;
                case 5:
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
                showProducts(products,productCount);            
                break;
                case 2:
                addProduct(products,&productCount);           
                break;
                case 3:
                           
                break;
                case 4:
                            
                break;
                case 5:
                            
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

 
