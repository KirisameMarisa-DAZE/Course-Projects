//
//  main.c
//  120901
//
//  Created by 李佩哲 on 2021/11/24.
//

// Code file created by C Code Develop

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int t=0;
char *p[101];//指向最长单词的指针构成的指针数组

int judge(int r){//判断是否为字母
    int boolean = 0;
    if((r > 64&&r < 91) ||(r > 96&&r < 123))boolean = 1;
    return boolean;
}

void find(char str[]) {//找到最长的单词，并返回指向其首字母的指针们
    unsigned long l=strlen(str);
    char str0[l+1];
    int sum[101]={0};
    str0[0]=(char)(0);
    for (int i = 0; i < l; i++)str0[i + 1] = str[i];
    int r = 0;
    for(int i=0;i < l;i++)//在最前面加一个非字母字符，以判断第一个是否为一个单词
        if ((!judge(str0[i])) && judge(str0[i + 1])) {
            for (int t = i; t < l+1; t++) {
                if (judge(str0[t]))sum[r]+=1;
                if (judge(str0[t]) && (!judge(str0[t + 1])))break;
            }
            r++;
        }
    int max[101],s=0;//max为最长单词是第几个
    max[s]=0;
    for (int i=0; i<101; i++)max[i]=-1;
    for (int i = 0; i < l+1; i++) {
        if(!sum[i])break;
        if(sum[max[s]]<=sum[i])max[s]=i;
    }
    for (int i = 0; i < l+1; i++) {
        if(!sum[i]){
            t=i-1;
            break;
        }
        if(sum[i]==sum[max[0]] && i!=max[0]){
            s++;
            max[s]=i;
        }
    }
    for(int j = 0; j < t; j++)//冒泡排序
        for(int i = 0; i < t - j; i++)
            if(max[i]!=-1&&max[i+1]!=-1)//表示“NONE”的-1不参加排序
                if(max[i] > max[i + 1]) {
                    int c = max[i];
                    max[i] = max[i + 1];
                    max[i + 1] = c;
                }
    int q=0;
    for (int i=0; i<l+1; i++) {//找到最长单词的首字母对应的地址并赋给指针
        int w=0;
        if(!sum[i])break;
        if(max[i]!=-1){
            int j=0;
            for (; j<l+1; j++) {
                if (w==max[i]+1)break;
                if ((!judge(str0[j])) && judge(str0[j + 1]))w++;
            }
            if(j==0)p[q] = &str[j];
            else p[q] = &str[j]-1;
            q++;
        }
    }
}

int main(int argc, char **argv) {
    char str[200];//字符串
    gets(str);
    find(str);
    for(int w=0;w<101;w++){//输出答案
        for (int i = 0; i < 200; i++){
            if(judge(*(p[w]+i)))
                printf("%c", *(p[w] + i));//打印第i个字符
            if(!judge(*(p[w]+i+1)))break;
        }
        if(!p[w+1])break;
        printf(" ");
    }
    printf("\n");
    return 0;
}
