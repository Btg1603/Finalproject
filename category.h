#ifndef CATEGORY_H
#define CATEGORY_H

#define MAX_CATEGORIES 100

typedef struct {
    char CategoryId[10];
    char CategoryName[10];
} Category;

void displayCategoryMenu();
void showCategories(Category categories[], int count);
void addCategory(Category categories[], int *count);

#endif

