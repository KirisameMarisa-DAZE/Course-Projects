//
//  main.c
//  120402
//
//  Created by 李佩哲 on 2021/10/20.
//

#include <stdio.h>

int main(){
    int n;
    int r = 1;
    int m = 0;
    printf("n=");
    scanf("%d", &n );
    if (n < 2) {
        printf("Error\n");
    }
    else {
        while(n>=1){
            r = 1 + (n) *(n-1)/2;
            while (m <= n) {
                printf("%d ", r );
                r++;
                m++;
                if (m == n) {
                    m = 0;
                    
                    printf("\n");
                    break;
                }
            }
            n--;
        }
    }
    return 0;
}
