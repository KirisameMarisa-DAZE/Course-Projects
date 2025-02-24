//
//  main.c
//  120703
//
//  Created by 李佩哲 on 2021/11/10.
//

// Code file created by C Code Develop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int wordcounter(char str[]);
    char str[65535];
    gets(str);
    int i = wordcounter(str);
    printf("%d\n", i);
    return 0;
}

int wordcounter(char str[]) {
    int i = 0;
    unsigned long r = 0;
    r = strlen(str);
    int num[r+2];
    for (int t = 0; t < r; t++) num[t+1] = str[t];//给第一个单词留下判定点，因为下面的判断是：前一个字符不是字母而后一个是才算一个单词
    for (int t = 0; t < r; t++)
    if(
        !(
            (num[t] > 64&&num[t] < 91)
            ||
            (num[t] > 96&&num[t] < 123)//前一个字符不是字母
        )
        &&                                     //且
        (
            (num[t + 1] > 64&&num[t + 1] < 91)
            ||
            (num[t + 1] > 96&&num[t + 1] < 123)//后一个字符是字母
        )
    ) i++;
    return i;
}
