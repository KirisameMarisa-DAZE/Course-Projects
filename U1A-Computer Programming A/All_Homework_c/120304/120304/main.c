//
//  main.c
//  120304
//
//  Created by 李佩哲 on 2021/10/14.
//

#include <stdio.h>
#include<math.h>

int main() {
    double a, b, c, p,S;
    scanf("%lf%lf%lf",&a,&b,&c);
    if (a+b>c && b+c>a && c+a>b){
        p = .5*(a+b+c);
        S = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.2f\n",S);
    }
    else{
        printf("0.00\n");
    }
    return 0;
}
