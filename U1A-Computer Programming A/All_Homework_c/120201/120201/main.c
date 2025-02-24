//
//  main.c
//  120301
//
//  Created by 李佩哲 on 2021/9/30.
//

#include <stdio.h>

int main() {
    printf("小写：");
    char a=getchar();
    char b;
    b = a-32;
    printf("大写：%c\n",b);
    return 0;
}
