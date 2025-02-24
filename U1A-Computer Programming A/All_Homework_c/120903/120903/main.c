//
//  main.c
//  120903
//
//  Created by 李佩哲 on 2021/11/25.
//

#include <stdio.h>
#include <math.h>

double integration(char fx[],double a,double b){
    double sum=0,delta = fabs(b-a)/100000000,x=a;
    for (int i=0; i<100000000; i++) {
        if(fx[0]=='s'&&fx[1]=='i'&&fx[2]=='n')
            sum+=sin(x+i*delta)*delta;
        else if (fx[0]=='c'&&fx[1]=='o'&&fx[2]=='s')
            sum+=cos(x+i*delta)*delta;
        else if (fx[0]=='e'&&fx[1]=='^'&&fx[2]=='x')
            sum+=exp(x+i*delta)*delta;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    char fx[100];
    double a,b;
    gets(fx);
    scanf("%lf%lf",&a,&b);
    double (*p)(char *,double, double)=integration;
    double result=p(fx,a,b);
    printf("%lf\n",result);
    return 0;
}
