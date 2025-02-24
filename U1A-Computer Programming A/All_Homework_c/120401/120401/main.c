//
//  main.c
//  120401
//
//  Created by 李佩哲 on 2021/10/20.
//

#include <stdio.h>
int main(){
    int n;
    int i = 1;
    int r = 1;
    int m = 0;
    printf("n=");
    scanf("%d", &n );
    if (n < 2) {
        printf("Error");
    }
    else {
        while(i<=n){
            while (m <= i) {
                printf("%d ", r );
                r++;
                m++;
                if (m == i) {
                    m = 0;
                    printf("\n");
                    break;
                }
            }
            i++;
        }
    }
    return 0;
}
