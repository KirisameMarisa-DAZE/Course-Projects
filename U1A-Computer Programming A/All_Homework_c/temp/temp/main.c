//
//  main.c
//  temp
//
//  Created by 李佩哲 on 2021/12/27.
//

#include <stdio.h>
#define M printf("HelloWorld!");

int main(int argc, const char * argv[]) {
    int i=2;
    float g=2.5;
    printf("%lf\n",g/i++);
    i=2;
    printf("%lf\n",g/++i);
    return 0;
}
