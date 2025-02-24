//
//  main.c
//  120504
//
//  Created by 李佩哲 on 2021/10/28.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[5][5]={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    int b[5][3]={
        {3,0,16},
        {17,-6,9},
        {0,23,-4},
        {9,7,0},
        {4,13,11}
    };
    unsigned long long c[5][3]={0};
    for (int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<5;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            printf("%llu,",c[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
