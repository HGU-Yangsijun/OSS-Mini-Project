#ifndef __PRODUCT_H__
#define __PRODUCT_H__

typedef struct Product {
    char name[256];    // 제품명
    char info[1024];   // 제품설명
    char weight[32];   // 중량
    int price;         // 판매가격
    int deliveryType;  // 배송법법
} Product;

enum Menu {
    QUIT,
    LIST,
    CREATE,
    SEARCH,
    LOAD,
    SAVE
};

#endif  // __PRODUCT_H__

int listProduct(Product *p[], int count);
void searchProduct(Product *p[], int count);
void searchProductName(Product *p[], int count);
void searchProductInfo(Product *p[], int count);
void searchProductPrice(Product *p[], int count);
int loadFromFile(char *filename, Product *p[], int *count);
int saveAsFile(char *filename, Product *p[], int count);

