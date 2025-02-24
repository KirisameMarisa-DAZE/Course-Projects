//
//  main.c
//  121003
//
//  Created by 李佩哲 on 2021/12/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *right(char str[51],int n){
    char *p=(char *)malloc(50*sizeof(char));
    unsigned long l=strlen(str);
    char ans[l+1];
    for(unsigned long i=0;i<n;i++)
        ans[i]=str[i+(int)(l-(unsigned long)n)];
    for(int i=n;i<l;i++)
        ans[i]=str[i-n];
    p=&ans[0];
    return p;
}

int main(int argc, const char * argv[]) {
    char str0[51],str[51];
    gets(str0);
    for(int i=0;i<50;i++)
        str[i]=str0[i];
    str[50]='\0';
    int n;
    scanf("%d",&n);
    char *p=right(str, n);
    unsigned long l=strlen(str);
    for(int i=0;i<(int)l;i++)
        printf("%c",*(p+i));
    printf("\n");
    return 0;
}
