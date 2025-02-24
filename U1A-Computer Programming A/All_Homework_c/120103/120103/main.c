//
//  main.c
//  temp3
//
//  Created by 李佩哲 on 2021/9/25.
//

#include <stdio.h>

float max(float x,float y,float z){
    float m;
    
    if (x>y){
        if (x>z){
            m=x;
        }
        else{
            m=z;
        }
    }
    else{
        if (y>z){
            m=y;
        }
        else{
            m=z;
        }
    }
    printf("%f\n",m);
    return m;
}

int main(){
    printf("题目：\n输入三个整数，输出较大的值。\n以下是答案：\n");

    float a,b,c,res;
    
    printf("plesse input a,b,c:");
    scanf("%f %f %f", &a,&b,&c);
    res=max(a, b, c);
    
    printf("Max=%f\n",res);
    return 0;
}

