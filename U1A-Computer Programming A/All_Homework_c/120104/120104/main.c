//
//  main.c
//  temp4
//
//  Created by 李佩哲 on 2021/9/25.
//

#include <stdio.h>
float change(float y){
    float x;
    x=5./9.*(y-32);
    return x;
}

int main() {
    printf("题目：\n\n以下是答案：\n");

    float c,f;
    
    printf("please input ℉:");
    scanf("%f",&f);
    
    c=change(f);
    
    printf("%f ℉≈%f ℃\n",f, c);
    return 0;
}
