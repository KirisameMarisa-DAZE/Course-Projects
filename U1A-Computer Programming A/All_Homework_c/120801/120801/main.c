//
//  main.c
//  120801
//
//  Created by 李佩哲 on 2021/11/17.
//

#include <stdio.h>
#include <math.h>

float x1[10]={0};
float x2[5]={0};

int main() {
    void ave_stu(float a[10][5]);
    void ave_sub(float a[10][5]);
    void max(float a[10][5]);
    void sigma();
    
    float grades[10][5]={
        {87,    86,    70,    86,    80},
        {67,    78,    72,    80,    92},
        {88,    85,    60,    69,    69},
        {68,    85,    80,    86,    90},
        {79,    95,    69,    82,    78},
        {33,    87,    78,    76,    93},
        {76,    82,    75,    76,    83},
        {90,    89,    96,    79,    88},
        {80,    41,    87,    79,    85},
        {56,    73,    21,    50,    63}
    };
    
    ave_stu(grades);
    ave_sub(grades);
    max(grades);
    sigma();
    
    return 0;
}

void ave_stu(float a[10][5]){
    printf("Average of Students:\n");
    for (int i=0; i<10; i++)
        for (int j=0; j<5; j++) {
            x1[i]+=(a[i][j]/5);
        }
    for(int i=0;i<10;i++)printf("Student%d  ==  %.1f\n",i+1,x1[i]);
}

void ave_sub(float a[10][5]){
    printf("\n\nAverage of Subjects:\n");
    for(int i=0;i<5;i++)
        for(int j=0;j<10;j++)
            x2[i]+=(a[j][i]/10);
    for(int i=0;i<5;i++)printf("Subject%d  ==  %.1f\n",i+1,x2[i]);
}

void max(float a[10][5]){
    printf("\n\nThe First Student & The MaxSubject:\n");
    int m=0,i0=0,j0=0;
    for(int i=0;i<10;i++)
        for(int j=0;j<5;j++)
            if(m<a[i][j]){
                m=a[i][j];
                i0=i+=1;
                j0=j+=1;
            }
    printf("Student%d, Subject%d. \nIt's %d.\n",i0,j0,m);
}

void sigma(){
    printf("\n\nσ of Students:\n");
    float s=0, sigma_x_sqrt=0, sigma_x=0;
    for(int i=0;i<10;i++){
        sigma_x+=x1[i];
        sigma_x_sqrt+=sqrtf(x1[i]);
    }
    s=sigma_x_sqrt/10-sqrtf(sigma_x/10);
    printf("σ == %f\n",s);
}
