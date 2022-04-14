#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "manager.h"

int main() {

#ifdef DEBUG
    printf("=> DEBUGMODE\n");
#endif

    Product **p = (Product **)malloc(100 * sizeof(Product *));
    for (int i = 0; i < 100; i++) {
        p[i] = (Product *)malloc(sizeof(Product));
    }

    int cnt = 0;
    int stop = 0;
    while (!stop) {
        int menu = chooseMenu();
        switch (menu) {
            case LIST:
                listProduct(p, cnt);
                break;
            case CREATE:
                createProduct(p[cnt]);
                cnt++;
#ifdef DEBUG
                printf("cnt 증가!\ncnt: %d\n", cnt);
#endif
                break;
            case SEARCH:
                searchProduct(p, cnt);
                break;
            case SAVE:
                saveAsFile("a.txt", p, cnt);
                break;
            case QUIT:
                stop = 1;
#ifdef DEBUG
                printf("stop 변경\nstop: %d\n", stop);
#endif
                break;
        }
    }

#ifdef DEBUG
    printf("정상 종료\n");
#endif

    return 0;
}
