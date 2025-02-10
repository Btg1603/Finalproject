#include <stdio.h>
#include <string.h>
#include "category.h"

void displayCategoryMenu() { 
    printf("\n*** STORE MANAGER ***\n");
    printf("===CATEGORY MANAGEMENT==="); 
    printf("[1] Show Categories\n");
    printf("[2] Add Category\n");
    printf("[0] Exit\n");
    printf("Enter your choice: ");
}

void showCategories(Category categories[], int count) {
    printf("\n=== CATEGORY LIST ===\n");
    if (count == 0) {
        printf("No categories available.\n");
    } else {
        printf("+------------+------------+\n");
        printf("| CategoryID | Name       |\n");
        printf("+------------+------------+\n");
        for (int i = 0; i < count; i++) {
            printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
        }
        printf("+------------+------------+\n");
    }
}

void addCategory(Category categories[], int *count) {
    if (*count >= MAX_CATEGORIES) {
        printf("Category list is full!\n");
        return;
    }

    Category newCategory;
    printf("\n=== ADD A NEW CATEGORY ===\n");

    printf("Enter Category ID (max 9 chars): ");
    scanf("%9s", newCategory.CategoryId);

    printf("Enter Category Name (max 9 chars): ");
    scanf("%9s", newCategory.CategoryName);

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
}

