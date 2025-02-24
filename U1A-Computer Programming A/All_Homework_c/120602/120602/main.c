//
//  main.c
//  120602
//
//  Created by 李佩哲 on 2021/11/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int a,num[500],key[10],s=0,b=0,p=0,q1=0,q2=0,u1=0,u2=0,n=1,m1,m2,m3,m4,c=0;
float x1,x2,x3,x4,x5,x6,_x1,_x2,_x3,_x4,_x5,_x6;
FILE *fp;

int main(int argc, const char * argv[]) {
    int Random(void);
    int getInput(void);
    float find_1(void);
    int order(void);
    float find_2(void);
    
    printf("请输入要循环的次数：");
    scanf("%d",&n);
    m1=m2=m3=m4=n;
    getInput();
    for (int i=0; i<n; i++) {
        Random();
        find_1();
        printf("test1-%d\n",i+1);
        _x1+=(x1/m1);
        _x2+=(x2/m2);
        _x3+=(x3/n);
        sleep(1);
    }
    printf("Test1 Over.\n");
    order();
    for (int i=0; i<n; i++) {
        Random();
        find_2();
        printf("test2-%d\n",i+1);
        _x4+=(x4/m3);
        _x5+=(x5/m4);
        _x6+=(x6/n);
        sleep(1);
    }
    printf("Test2 Over.\n\nResult:\n");
    printf("找到存在的key平均%f次/个\n找到不存在的key一定是%f次/个\n遍历10个key平均%f次/个\n找到存在的key平均%f次/个\n找到不存在的key平均%f次/个\n遍历10个key平均%f次/个\n",_x1,_x2,_x3,_x4,_x5,_x6);
    
    return 0;
}

int Random(void){
    time_t t;
    srand((unsigned) time(&t));
    for (int i=0; i<10; i++) {
        a=rand()%2000;
        key[i]=a;
    }
    return 0;
}

int getInput(void){
    fp=freopen("/Users/page/Documents/4-app/Homework/All_Homework_c/120602/120602/rand500.txt", "r", stdin);
    for(int i=0;(fscanf(fp,"%d",&num[i])!=EOF)&&i<500;i++){}
    return 0;
}

float find_1(void){
    s=0;//总次数
    b=0;//不存在的个数
    c=0;//存在的个数
    for (int r=0,i=0; r<10&&i<500; s++) {
        if(key[r]==num[i]){
            r++;
            i=0;
            c++;
        }
        else i++;
        if(i==500){
            i=0;
            r++;
            b++;
        }
    }
    if(c)x1=(float)(s-b*500)/(10-b);
    else m1--;
    if(b)x2=500;
    else m2--;
    x3=(float)s/10;
    return 0;
}

int order(void){
    int c;
    for(int j = 0; j < 499; j++)
        for(int i = 0; i < 499 - j; i++)
            if(num[i] > num[i + 1]) {
                c = num[i];
                num[i] = num[i + 1];
                num[i + 1] = c;
            }
    /*printf("排序后：\n");
    for(int i = 0; i < 500; i++) {
        printf("%d", num[i]) ;
        if(i < 499)printf(",");
        else printf("\n");
    }*///打印排序后的num[]
    return 0;
}

float find_2(void){
    p=0;//查找每个数经过的次数
    q1=0;//存在的数的总次数
    q2=0;//不存在的数的总次数
    u1=0;//存在的总个数
    u2=0;//不存在的总个数
    int max=499,min=0;
    for (int r=0,i=250; r<10; p++) {
        if(max<min){
            u2++;
            q2+=(p++);
            p=-1;
            r++;
            i=250;
            max=499;
            min=0;
            continue;
        }
        if (key[r]>num[i]){
            min=i+1;
            i=(max+min)/2;
        }
        else if (key[r]<num[i]){
            max=i-1;
            i=(max+min)/2;
        }
        else{
            u1++;
            q1+=(p++);
            p=-1;
            r++;
            i=250;
            max=499;
            min=0;
        }
    }
    if(u1)x4=(float)q1/u1;
    else m3--;
    if(u2)x5=(float)q2/u2;
    else m4--;
    x6=(float)(q1+q2)/10;
    return 0;
}
