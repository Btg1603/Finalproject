


#include "datatype.h"

void getPassword(char* password);
int checkLogin(const char* username, const char* password);



void displayStoreManager();
 
void displayCategoryMenu();
void showCategories(Category categories[], int count);
void addCategory(Category categories[], int *count);
void changeCategory(Category categories[], int count);
void deleteCategory(Category categories[], int *count);
void sortCategories(Category categories[],int count);
void searchCategory(Category categories[],int count);
void saveCategoriesToBinaryFile(Category categories[], int count);
void loadCategoriesFromBinaryFile(Category categories[], int *count);


void displayProductMenu();
void showProducts(Product products[], int count);
void addProduct(Product products[], int *count, Category categories[], int categoryCount);
void changeProduct(Product products[], int count);
void deleteProduct(Product products[], int *count);
void searchProduct(Product products[], int count);
void sortProductsByPrice(Product products[], int *count);
void saveToFile(Product products[], int count);
void loadFromFile(Product products[], int *count);
 
