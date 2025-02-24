//
//  main.c
//  120804
//
//  Created by 李佩哲 on 2021/11/18.
//

/*
 题目描述

 设n是一任意自然数。若将n的各位数字反向排列所得自然数n1与n相等，则称n为一回文数。
 例如，若n=1234321，则称n为一回文数。
 请设计一个程序，接收两个自然数a和b，(假设a<b, b<=99999) 按序输出不小于a且不大于b的所有回文数。
 建议用函数实现判断一个数是否为回文数。

 输入

 输入区间下限和区间上限

 输出

 输出区间内所有回文数（以空格分割不同回文数，最后一个回文数后也有一个空格）

 样例输入

 10 55
 样例输出

 11 22 33 44 55
 */

#include <stdio.h>

int result[100000]={0};

int charge(int x){
    if(x==0)return 1;
    int boolean=0,m=x;
    double y=0;
    for (double i=1; x>=1; i++) {
        y=y*10+(x%10);
        x/=10;
    }
    if(m==y)boolean=1;
    return boolean;
}

void backword(int m,int n){
    int r=0;
    for (int i=m; i<=n; i++){
        if(charge(i)==1){
            result[r]=i;
            r++;
        }
    }
}

int main() {
    
    int a,b;
    for (;;) {
        scanf("%d%d",&a,&b);
        if((a<b&&b<=99999 && a>=0 ))break;
        printf("a<b & b<=99999");
    }
    
    backword(a,b);
    int i=0;
    if(result[i]==0){
        printf("%d ",result[i]);
        i++;
    }
    for(;result[i]!=0;i++)printf("%d ",result[i]);
    
    return 0;
}
