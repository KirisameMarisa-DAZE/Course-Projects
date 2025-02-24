//
//  main.c
//  121101
//
//  Created by 李佩哲 on 2021/12/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student{
    int stunum;       //学号
    char name[20];    //姓名
    float examscore;  //考试成绩
    float labscore;   //实验成绩
    float totalmark;  //总评成绩
}STU;

int main(int argc, const char * argv[]) {
    STU stutable[10];
    for (int i=0; i<10; i++) {
        scanf("%d%s%f%f",&stutable[i].stunum,stutable[i].name,&stutable[i].examscore,&stutable[i].labscore);
        stutable[i].totalmark=stutable[i].examscore*0.6+stutable[i].labscore*0.4;
    }
    STU *parray[10];
    for(int i=0;i<10;i++)
        parray[i]=&stutable[i];
    for(int j=0;j<9;j++)
        for(int i=0;i<9-j;i++)
            if(parray[i]->totalmark<=parray[i+1]->totalmark){
                STU *temp=parray[i];
                parray[i]=parray[i+1];
                parray[i+1]=temp;
            }
    for(int i=0;i<10;i++)
        printf("%d %s:%f\n",parray[i]->stunum,parray[i]->name,parray[i]->totalmark);
    return 0;
}
/*
71250李霞    95    82
69753李友友   88    86
12254东方亮   87    88
61256张男    73    85
30258孙杰    25    88
11260柯以乐   82    76
33262谢涛    91    85
29263叶林    80    75
22483陈翔    80    76
71525王子    71    88
*/
