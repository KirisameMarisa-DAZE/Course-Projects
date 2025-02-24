//
//  main.c
//  120803
//
//  Created by 李佩哲 on 2021/11/17.
//

#include <stdio.h>
#define swap(a,b) {int i;i=a;a=b;b=i;}


int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    swap(a,b);
    printf("%d %d\n",a,b);
    printf("line:%d\nfile:%s\nfunc:%s\n",__LINE__,__FILE__,__func__);
    
    #ifdef  _WIN32
    printf("WIN32");
    #else
    printf("NO\n");
    #endif

    #ifdef _WIN64
    printf("WIN64");
    #else
    printf("NO\n");
    #endif

    #ifdef __CYGWIN__
    printf("CYGWIN");
    #else
    printf("NO\n");
    #endif

    #ifdef __gnu_linux__
    printf("gnu linux");
    #else
    printf("NO\n");
    #endif

    #ifdef __MINGW32__
    printf("MING32");
    #else
    printf("NO\n");
    #endif

    return 0;
}
