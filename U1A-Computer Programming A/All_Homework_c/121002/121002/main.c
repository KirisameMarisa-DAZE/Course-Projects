//
//  main.c
//  121002
//
//  Created by 李佩哲 on 2021/12/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    float val[100]={0},s=0,x=0;//val各个数值，s为方差，x为平均值
    for(int i=1;i<argc;i++)//argv转换为val
        val[i]=atof(argv[i]);
    for (int i=1;i<argc;i++)//求平均值
        x+=val[i]/(argc-1);
    for (int i=1; i<argc; i++)//求方差
        s+=powf(val[i]-x, 2)/(argc-1);
    printf("\ns^2=%f\n",s);
    return 0;
}
