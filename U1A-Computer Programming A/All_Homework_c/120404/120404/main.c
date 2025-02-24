//
//  main.c
//  120404
//
//  Created by 李佩哲 on 2021/10/20.
//

#include <stdio.h>
#include "math.h"

int judge(double r){
    int boolean=0;
    if ((int)r%2 == 0) {
        boolean = 0;
    }
    else{
        for (int i=3; i<=sqrt(r); i+=2) {
            if ((int)r%i!=0) {
                boolean = 1;
            }
            else{
                boolean = 0;
                break;
            }
        }
    }
    return boolean;
}

int main() {
    double num = 500.0;
    int result = 0;
    printf("500以内最大的十个质数：\n");
    int m = 0;
    for (;m >= 0 && m <= 10; num-=2) {
        if (m<0) {
            printf("很抱歉，500以内没有十个质数！");
            break;
        }
        else{
            if (judge(num) == 0) {
                continue;
            }
            else{
                m++;
                printf("%d",(int)num);
                result += num;
            }

            if (m == 10) {
                printf("=%d\n",result);
                break;
            }
            else{
                printf("+");
            }
        }
    }
    return 0;
}
