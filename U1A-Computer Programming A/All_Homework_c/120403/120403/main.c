//
//  main.c
//  120403
//
//  Created by 李佩哲 on 2021/10/20.
//

#include <stdio.h>

unsigned long long ro(unsigned long long i){
    unsigned long long n = 1, s = 1;
    while (n < i) {
        n++;
        s*= n;
    }
    return s;
}

int main() {
    unsigned long long t;
    unsigned long long r = 1;
    unsigned long long re = 0;
    printf("n=");
    scanf("%llu", &t );
    while (r <= t) {
        re += ro(r);
        r++;
    }
    printf("result=%llu\n", re ) ;
    return 0;
}
