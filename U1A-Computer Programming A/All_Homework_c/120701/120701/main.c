//
//  main.c
//  120701
//
//  Created by 李佩哲 on 2021/11/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int goodbrackets(char x[]);
    char str[65535];
    gets(str);
    if(goodbrackets(str)  == 1) printf("true\n");
    else printf("false\n");
    return 0;
}

int goodbrackets(char x[]) {
    int boolean = 0, l = 0;
    unsigned long n = strlen(x);
    int num[n + 1];
    for(int i = 0; i < n; i++) num[i] = x[i];
    for (unsigned long i = 0; i < n; i++) {
        if (x[i] == 40) l++;
        else if (x[i] == 41) l--;
        if(l<0)break;
    }
    if(l == 0) boolean = 1;
    return boolean;
}
