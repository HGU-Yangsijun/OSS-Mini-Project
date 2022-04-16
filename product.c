#include "product.h"

#include <stdio.h>
#include <string.h>

void printMenu() {
    printf("\n");
    printf("[메뉴]\n");
    printf("1. 제품 목록\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 검색\n");
    printf("4. 제품 목록 불러오기\n");
    printf("5. 제품 목록 저장\n");
    printf("0. 종료\n");
}

int chooseMenu() {
    int menu;
    for (;;) {
        printMenu();
        printf("-----------------\n");
        printf("메뉴를 입력하시오: ");
        scanf("%d", &menu);

        if (menu >= 0 && menu <= 5)
            return menu;
        else
            printf("잘못된 입력!\n");
    }
#ifdef DEBUG
    printf("메뉴 선택!\nmenu: %d\n", menu);
#endif
}

int createProduct(Product *p) {  // 제품을 추가하는 함수
    while (getchar() != '\n')
        ;
    printf("제품명: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strlen(p->name) - 1] = '\0';

    printf("제품 설명: ");
    fgets(p->info, sizeof(p->info), stdin);
    p->info[strlen(p->info) - 1] = '\0';

    printf("중량: ");
    fgets(p->weight, sizeof(p->weight), stdin);
    p->weight[strlen(p->weight) - 1] = '\0';

    printf("판매가격: ");
    scanf(" %d", &p->price);

    printf("배송방법 (1: 새벽배송 / 2: 택배배송): ");
    scanf(" %d", &p->deliveryType);

    return 1;  // 정상적으로 생성됨
}

int readProduct(Product p) {  // 하나의 제품 출력 함수
    printf("%s\t%s\t%s\t%d\t%d\n", p.name, p.info, p.weight, p.price,
           p.deliveryType);

    return 1;  // 정상적으로 출력됨
}
