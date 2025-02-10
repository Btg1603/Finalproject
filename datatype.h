// noi khai bao cac thu vien, import cac struct
#include <stdio.h>
#include <string.h>
#ifndef CATEGORY_H
#define CATEGORY_H

#define MAX_CATEGORIES 100

typedef struct {
    char CategoryId[10];
    char CategoryName[10];
} Category;

#endif 
