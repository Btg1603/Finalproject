#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"

int main() {
    Category categories[MAX_CATEGORIES];
    int categoryCount = 0;
    int choice;

    do {
    system("cls"); 
    displayCategoryMenu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
    showCategories(categories, categoryCount);
    break;
    case 2:
    addCategory(categories, &categoryCount);
    break;
    case 3:
    changeCategory(categories, categoryCount);	
	break; 
    case 0:
    printf("Exiting...\n");
    break;
    default:
    printf("Invalid choice! Try again.\n");
    }
    } while (choice != 0);

    return 0;
}
