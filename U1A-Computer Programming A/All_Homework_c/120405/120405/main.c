//
//  main.c
//  120405
//
//  Created by 李佩哲 on 2021/10/21.
//

#include <stdio.h>

float sum(int n){
    float res=0.0,i1=2.0, i2=1.0;
    float i3;
    for (int i=1; i<=n; i++) {
        res+=i1/i2;
        i3=i1+i2;
        i2=i1;
        i1=i3;
    }
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%.2f\n",sum(n));
    return 0;
}
