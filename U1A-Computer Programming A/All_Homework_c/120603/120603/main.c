//
//  main.c
//  120603
//
//  Created by 李佩哲 on 2021/11/4.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[65535];
    gets(str);
    unsigned long n=strlen(str);
    int num[n+1];
    char answer[n+1];
    for (unsigned long i=0; i<n; i++) {
        if(((num[i]=str[i])<122&&(num[i]=str[i])>96)||((num[i]=str[i])>64&&(num[i]=str[i])<90)){
            num[i]=str[i];
            num[i]++;
            answer[i]=num[i];
        }
        else if (((num[i]=str[i])==122)||((num[i]=str[i])==90)){
            num[i]=str[i];
            num[i]-=25;
            answer[i]=num[i];
        }
        else answer[i]=str[i];
        printf("%c\n",answer[i]);
    }
    return 0;
}
