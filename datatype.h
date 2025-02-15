// noi khai bao cac thu vien, import cac struct
#include <stdio.h>
#include <string.h>
#ifndef CATEGORY_H
#define CATEGORY_H

#define MAX_CATEGORIES 100
#define MAX_PRODUCTS 100 
typedef struct {
    char CategoryId[10];
    char CategoryName[10];
} Category;

typedef struct {
	char productId[10];
	char categoryId[10];
	char productName[10];
	int quantity;
	int price; 
} Product; 
#endif 
