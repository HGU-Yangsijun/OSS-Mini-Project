#include "manager.h"

#include <stdio.h>
#include <string.h>

#include "product.h"

int listProduct(Product *p[], int count) {  // 전체 등록된 제품 리스트 출력
    printf("제품명\t설명\t중량\t판매가격\t배송방법\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        readProduct(*p[i]);
    }

    return 1;  // 정상적으로 출력됨
}

void searchProduct(Product *p[], int count) {  // 제품 검색
    int searchMode = 0;
    for (;;) {
        printf(
            "검색 기준을 입력하세요 (1: 제품명 / 2: 설명 / 3: 판매가격 / 0: "
            "취소): ");
        scanf("%d", &searchMode);

        switch (searchMode) {
            case 1:
                searchProductName(p, count);
                return;
            case 2:
                searchProductInfo(p, count);
                return;
            case 3:
                searchProductPrice(p, count);
                return;
            case 0:
                printf("취소됐습니다!\n");
                return;
            default:
                break;
        }
    }
}

void searchProductName(Product *p[], int count) {
    char searchName[256];
    printf("검색할 제품명을 입력하세요: ");
    while (getchar() != '\n')
        ;
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strlen(searchName) - 1] = '\0';

    int scnt = 0;
    for (int i = 0; i <= count; i++) {
        if (strstr(p[i]->name, searchName)) {
            if (scnt == 0) {
                printf("제품명\t설명\t중량\t판매가격\t배송방법\n");
                printf(
                    "-----------------------------------------------------\n");
            }
            readProduct(*p[i]);
            scnt++;
        }
    }
    if (scnt == 0) {
        printf("검색 결과가 없습니다!\n");
    }
}

void searchProductInfo(Product *p[], int count) {
    char searchInfo[1024];
    printf("검색할 설명을 입력하세요: ");
    while (getchar() != '\n')
        ;
    fgets(searchInfo, sizeof(searchInfo), stdin);
    searchInfo[strlen(searchInfo) - 1] = '\0';

    int scnt = 0;
    for (int i = 0; i <= count; i++) {
        if (strstr(p[i]->info, searchInfo)) {
            if (scnt == 0) {
                printf("제품명\t설명\t중량\t판매가격\t배송방법\n");
                printf(
                    "-----------------------------------------------------\n");
            }
            readProduct(*p[i]);
            scnt++;
        }
    }
    if (scnt == 0) {
        printf("검색 결과가 없습니다!\n");
    }
}

void searchProductPrice(Product *p[], int count) {
    char searchPrice[1024];
    printf("검색할 제품의 가격을 입력하세요: ");
    while (getchar() != '\n')
        ;
    fgets(searchPrice, sizeof(searchPrice), stdin);
    searchPrice[strlen(searchPrice) - 1] = '\0';

    int scnt = 0;
    char productPrice[16];
    for (int i = 0; i <= count; i++) {
        sprintf(productPrice, "%d", p[i]->price);
        if (strstr(productPrice, searchPrice)) {
            if (scnt == 0) {
                printf("제품명\t설명\t중량\t판매가격\t배송방법\n");
                printf(
                    "-----------------------------------------------------\n");
            }
            readProduct(*p[i]);
            scnt++;
        }
    }
    if (scnt == 0) {
        printf("검색 결과가 없습니다!\n");
    }
}

int loadFromFile(char *filename, Product *p[], int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("파일 불러오기에 실패했습니다.\n");
        return -1;
    }

    for (;;) {
        fgets(p[*count]->name, sizeof(p[*count]->name), fp);
        p[*count]->name[strlen(p[*count]->name) - 1] = '\0';
        fgets(p[*count]->info, sizeof(p[*count]->info), fp);
        p[*count]->info[strlen(p[*count]->info) - 1] = '\0';
        fgets(p[*count]->weight, sizeof(p[*count]->weight), fp);
        p[*count]->weight[strlen(p[*count]->weight) - 1] = '\0';
        fscanf(fp, "%d", &p[*count]->price);
        fscanf(fp, "%d", &p[*count]->deliveryType);
        if (feof(fp))
            break;
        (*count)++;
    }

    fclose(fp);

    return *count;
}

int saveAsFile(char *filename, Product *p[], int count) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("파일 저장에 실패했습니다.\n");
        return -1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", p[i]->name, p[i]->info,
                p[i]->weight, p[i]->price, p[i]->deliveryType);
    }
    fclose(fp);
#ifdef DEBUG
    printf("정상적으로 저장됨\n");
#endif
    return 1;  // 정상적으로 파일 저장됨
}
