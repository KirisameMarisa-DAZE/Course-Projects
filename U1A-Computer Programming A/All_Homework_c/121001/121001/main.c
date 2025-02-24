//
//  main.c
//  121001
//
//  Created by 李佩哲 on 2021/11/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int compar(const void *a,const void *b)
    {return *(double*)a-*(double*)b;}

double **change(double pm[][100], int n){
    
    double matrix[n*n];
    double pmatrix[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            pmatrix[i][j]=pm[i][j];
    int r=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            matrix[r]=pmatrix[i][j];
            r++;
        }
    qsort(matrix, n*n, sizeof(double), compar);
    pmatrix[0][0]=*matrix;
    pmatrix[0][n-1]=*(matrix+1);
    pmatrix[n-1][0]=*(matrix+2);
    pmatrix[n-1][n-1]=*(matrix+3);
    r=4;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (!((i==0 || i==n-1) && (j==0 || j== n-1))){
                pmatrix[i][j]=*(matrix+r);
                r++;
            }
    
    double **p =(double **)malloc(n*sizeof(double *));//先申请M个指针型字节的空间
    for (int i=0;i<n;i++)
        p[i]=(double *)malloc(n*sizeof(double));//然后依次按一维申请
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            *((double *)p+n*i+j) = *((double *)pmatrix+n*i+j) + 1;//找地址，如同数据结构中矩阵找地址相同，首地址+（次数行数-1）*总列数+次数列数-1,i，j都是从0开始，可以不用减1
    return p;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    double pmatrix[100][100]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&pmatrix[i][j]);
    double **p=change(pmatrix,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%lf ",*((double *)p+n*i+j)-1);
        printf("\n");
    }
    return 0;
}
