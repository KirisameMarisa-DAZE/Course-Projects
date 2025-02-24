//
//  main.c
//  120502
//
//  Created by 李佩哲 on 2021/10/27.
//

#include <stdio.h>

int main() {
    int a[20] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[] = {1, 43, 72, 23, 9, 87, 54, 3, 55, 0};
    for(int i = 0; i < 10; i++) {
        a[10 + i] = b[i];
    }
    int c;
    for(int j = 0; j < 19; j++) {
        for(int i = 0; i < 19 - j; i++) {
            if(a[i] > a[i + 1]) {
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
            else
                continue;
        }
    }
    for(int i = 0; i < 20; i++) {
        printf("%d", a[i]) ;
        if(i < 19)
            printf(",");
        else
            printf("\n");
    }
    return 0;
}
