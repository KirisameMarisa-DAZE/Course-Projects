//
//  main.c
//  120802
//
//  Created by 李佩哲 on 2021/11/17.
//

#include <stdio.h>
#include <string.h>

int n=12,array[65535]={0};// 11 188 768 1377 12 228 902 740 1326 1987 41 1478
int answer[65535]={0};
int l;

int main() {
    void selection_sort(int array[],int n);
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&array[i]);
    l=n;
    selection_sort(array, n);
    for(int i=0;i<l;i++)printf("%d\n",answer[i]);
    return 0;
}

void selection_sort(int array[],int n){
    int m=0;
    int j=0;
    for(int i=0;i<l;i++)
        if(m<array[i]){
            m=array[i];
            j=i;
        }
    answer[n-1]=array[j];
    array[j]=0;
    if(n>0)selection_sort(array, n-1);
}
