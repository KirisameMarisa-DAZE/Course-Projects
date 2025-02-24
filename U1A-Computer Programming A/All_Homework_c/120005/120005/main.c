//
//  main.c
//  120005
//
//  Created by 李佩哲 on 2021/11/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int m1=1,n1=1,m2=1,n2=1,choice=0,typeOfGet;
//m1,n1,m2,n2为两个矩阵的大小，一直都要调用，故设为全局变量并赋初值，实际值在getInput_mn()中赋给；
//choice为选择的功能的序号，在初期判断是用哪个函数时有多个函数要调用，故设为全局变量
//typeOfGet为选择的功能所需要输入的矩阵的数量，在获取输入时有多个函数要调用，故设为全局变量

void choose(void){
//    选择要进行的功能,得到选择功能的序号
    printf("请选择：1.加减；2.数乘；3.转置；4.相乘；5.伴随；6.求逆；7.行列式；0.退出\n");
    goto LOOP1;
LOOP2:
    getchar();//用于间断程序
LOOP1:
    printf(">>>");
    if (!scanf("%d",&choice)) {//判断是否输入整数
        printf("\n键入不是整数！请检查您的输入，并重新键入符合规范的数字！\n");
        goto LOOP2;
    }
    switch (choice) {
        case 1://加减
            typeOfGet = 2;
            break;
        case 2://数乘
            typeOfGet = 1;
            break;
        case 3://转置
            typeOfGet = 1;
            break;
        case 4://相乘
            typeOfGet = 2;
            break;
        case 5://伴随
            typeOfGet = 1;
            break;
        case 6://求逆
            typeOfGet = 1;
            break;
        case 7://行列式
            typeOfGet = 1;
            break;
        case 0://退出
            exit(0);
            break;
        default:
            choice = 0;
            printf("\n键入不在范围内！请输入正确的数值！\n");
            goto LOOP2;
            break;
    }
}

void getInput_mn(void){
//    获取输入的矩阵规格
    m1=n1=m2=n2=1;
    choose();
    goto LOOP1;
LOOP2:
    getchar();//用于间断程序
LOOP1:
    switch (typeOfGet) {
        case 1://如果只涉及一个矩阵，就只输入一个，另外一个令为零矩阵
            printf("请输入m×n...\nm n=");
            if (!scanf("%d%d",&m1,&n1)) {//判断是否输入整数
                printf("\n键入不是整数！请检查您的输入，并重新键入符合规范的数字！\n");
                goto LOOP2;
            }
            break;
        case 2://如果涉及了两个矩阵，就输入两个
            printf("请输入m1×n1...\nm1 n1=");
            if (!scanf("%d%d",&m1,&n1)) {//判断是否输入整数
                printf("\n键入不是整数！请检查您的输入，并重新键入符合规范的数字！\n");
                goto LOOP2;
            }
        LOOP3:
            printf("请输入m2×n2...\nm2 n2=");
            if (!scanf("%d%d",&m2,&n2)) {//判断是否输入整数
                printf("\n键入不是整数！请检查您的输入，并重新键入符合规范的数字！\n");
                getchar();//用于间断程序
                goto LOOP3;
            }
            break;
        default:
            printf("请输入正确的数值！\n>>>");
            goto  LOOP2;
            break;
    }
    switch (choice) {//判断行列数是否合规
        case 1://加减
            if(!(m1==m2&&n1==n2)||(!(m1>0&&n1>0&&m2>0&&n2>0))){
                printf("\n键入矩阵行列数不合规范！请检查您的输入，并重新键入符合规范的行数与列数！\n");
                goto LOOP2;
            }
            break;
        case 2 ... 3:
            if (!(m1>0&&n1>0&&m2>0&&n2>0)) {
                printf("\n键入矩阵行列数不合规范！请检查您的输入，并重新键入符合规范的行数与列数！\n");
                goto LOOP2;
            }
            break;
        case 4://相乘
            if ((n1!=m2)||(!(m1>0&&n1>0&&m2>0&&n2>0))) {
                printf("\n键入矩阵行列数不合规范！请检查您的输入，并重新键入符合规范的行数与列数！\n");
                goto LOOP2;
            }
            break;
        case 5 ... 7://伴随、求逆、行列式都要求为方阵
            if ((n1!=m1)||(!(m1>0&&n1>0&&m2>0&&n2>0))) {
                printf("\n键入矩阵行列数不合规范！请检查您的输入，并重新键入符合规范的行数与列数！\n");
                goto LOOP2;
            }
            break;
        case 0://退出
            exit(0);
            break;
        default:
            choice = 0;
            printf("\n请输入正确的数值！\n>>>");
            goto LOOP2;
            break;
    }
}

void getInput(double A[m1][n1], double B[m2][n2]){
//    获取矩阵输入
LOOP1:
    printf("请输入A：\n");
    for(int i=0;i<m1;i++){//输入A
        printf("第%d行：\n>>>",i+1);
        for(int j=0;j<n1;j++)
            if (!scanf("%lf",&A[i][j])) {//判断是否输入整数
                printf("\n键入不是整数！请检查您的输入，并重新键入符合规范的数字！\n");
                getchar();//用于间断程序
                goto LOOP1;
            }
    }
    printf("输入A=\n");
    for(int i=0;i<m1;i++){//输出A
        for(int j=0;j<n1;j++)
            printf("%lf ",A[i][j]);
        printf("\n");
    }//如果只涉及一个矩阵，就只输入一个，另外一个令为零矩阵
    if (typeOfGet == 2) {//如果涉及了两个矩阵，就输入两个
    LOOP2:
        printf("请输入B：\n");
        for(int i=0;i<m2;i++){//输入B
            printf("第%d行：\n>>>",i+1);
            for(int j=0;j<n2;j++)
                if (!scanf("%lf",&B[i][j])) {//判断是否输入整数
                    printf("\n键入不是整数！请检查您的输入，并重新键入符合规范的数字！\n");
                    getchar();//用于间断程序
                    goto LOOP2;
                }
        }
        printf("输入B=\n");
        for(int i=0;i<m2;i++){//输出B
            for(int j=0;j<n2;j++)
                printf("%lf ",B[i][j]);
            printf("\n");
        }
    }
}

int plus(double A[m1][n1],double B[m2][n2]){
//    加法
    double C[m1][n1];
    if(!(m1==m2 && n1==n2)){
        printf("A，B行列数不一致！\n");
        return 0;//返回不能加
    }
    printf("A+B=\n");
    for (int i=0; i<m1; i++) {//做加法并同时输出结果
        for (int j=0; j<n1; j++) {
            C[i][j]=A[i][j]+B[i][j];
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }
    return 1;//返回能加
}

void lambda(double A[m1][n1]){
//    数乘
    double l;
    printf("λ=");
    scanf("%lf",&l);
    double C[m1][n1];
    printf("λA=\n");
    for (int i=0; i<m1; i++) {//做数乘并同时输出结果
        for (int j=0; j<n1; j++) {
            C[i][j]=l*A[i][j];
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }
}

void T(double A[m1][n1]){
//    转置
    double C[n1][m1];
    printf("A^T=\n");
    for (int i=0; i<m1; i++)
        for (int j=0; j<n1; j++)//做转置
            C[j][i]=A[i][j];
    for (int i=0; i<n1; i++){
        for (int j=0; j<m1; j++)//做转置
            printf("%lf ",C[i][j]);
        printf("\n");
    }
}

int Times(double A[m1][n1],double B[m2][n2]){
//    乘法
    if(n1!=m2){
        printf("A列数，B行数不一致！\n");
        return 0;//返回不能乘
    }
    double C[m1][n2];
    for(int i=0;i<m1;i++)
        for(int j=0;j<n2;j++)
            C[i][j]=0;
    printf("A×B=\n");
    for (int i=0; i<m1; i++) {//做乘法并同时输出结果
        for (int j=0; j<n2; j++) {
            for (int r=0; r<n1; r++)
                C[i][j]+=A[i][r]*B[r][j];
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }
    return 1;//返回能乘
}

//Line244～Line272:以下为求方阵的行列式
double MIJ(double A[m1][n1],int i,int j, int n){//A是传入的方阵，i，j是去掉的元素所在的第i行第j列，n为A的阶数//Line244
    //这里设置阶数的目的是：因为根据函数定义，只能传入一个固定大小的数组，而剥洋葱的算法会让方阵一层层缩小，于是将方阵置于原方阵的左上角，使用阶数n来避免调用多余的量，这样也就有了Line179每次都要让M[][]归零的操作
//    求余子式
    double det(double A[m1][n1], int n);//下面那个求行列式的函数的函数声明
    double M[m1][n1];//定义余子式矩阵
    for(int r=0;r<m1;r++)//先让Mij为零矩阵，防止出错//Line249
        for(int s=0;s<n1;s++)
            M[s][r]=0;
    for(int a=0;a<n-1;a++)//获得余子式Mij
        for(int b=0;b<n-1;b++){
            if(a<i && b<j)M[a][b]=A[a][b];//获得i行j列元素的左上角区域
            else if (a<i && b>=j)M[a][b]=A[a][b+1];//获得i行j列元素的右上角区域
            else if (a>=i && b<j)M[a][b]=A[a+1][b];//获得i行j列元素的左下角区域
            else M[a][b]=A[a+1][b+1];//获得i行j列元素的右下角区域
        }
    return det(M,n-1);//获得余子式的行列式，然后无限套娃剥洋葱直至返回一个1x1行列式得到最终值，在逐层向上传递结果，得到最终答案
}

double det(double A[m1][n1], int n){//A是传入的方阵，n为A的阶数；
//这里设置阶数的目的是：因为根据函数定义，只能传入一个固定大小的数组，而剥洋葱的算法会让方阵一层层缩小，于是将方阵置于原方阵的左上角，使用阶数n来避免调用多余的量
//    求行列式
    double detA=0;//令行列式的初值为零，方便后面的加法运算
    //在这里令detA=0而不是在全局变量里令的原因是，每次解行列式，MIJ()都是在反复调用本函数，也就是说，会产生局部里的局部变量、局部里局部里的局部变量……以此类推，会出现detA套娃的现象，而最后的结果是要求detA一层一层向上返回值，所以如果它是全局变量，就会出现问题
    if(n==1)return A[0][0];//如果得到的是一个1x1的方阵，就返回其值，这也是上面求余子式函数的出口，最终返回值是这个，然后再一层一层向上返回，直到得出第n-1阶余子式行列式的值
    else if (n>1)//其他情况就继续往下剥洋葱算
        for (int i=0; i<n; i++)//按第一行展开
            detA+=pow(-1,i+2)*A[0][i]*MIJ(A, 0, i, n);//这里detA加上了一个代数余子式，而余子式是要调用上面一个函数来剥洋葱算的，最终的返回值在这里被使用
    return detA;//最后的最后，返回行列式的值
}//Line272
//以上为求方阵的行列式

double company(double A[m1][n1]){
//    伴随矩阵
    if(m1!=n1){
        printf("输入不是方阵！\n");
        return 0;
    }
    double C[m1][n1];
    printf("A*=\n");
    for (int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            C[i][j]=pow(-1,i+j+2)*MIJ(A, j, i, m1);
            if(C[i][j]==-0)C[i][j]=0;
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int contrast(double A[m1][n1]){
//    逆矩阵
    if(m1!=n1){
        printf("输入不是方阵！\n");
        return 0;
    }
    if(det(A, m1)==0){
        printf("不可逆！\n");
        return 0;
    }
    double C[m1][n1];
    printf("A^(-1)=\n");
    for (int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            C[i][j]=(pow(-1,i+j+2)*MIJ(A, j, i, m1))/det(A, m1);
            if(C[i][j]==-0)C[i][j]=0;
            printf("%lf ",C[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int main() {
LOOP:
    getInput_mn();//获得mxn
    double A[m1][n1],B[m2][n2];
    getInput(A,B);//获取A，B
    switch (choice) {
        case 1://加法
            if(!plus(A,B))goto LOOP;
            break;
        case 2://数乘
            lambda(A);
            break;
        case 3://转置
            T(A);
            break;
        case 4://乘法
            if(!Times(A,B))goto LOOP;
            break;
        case 5://伴随
            if(!company(A))goto LOOP;
            break;
        case 6://求逆
            if(!contrast(A))goto LOOP;
            break;
        case 7://行列式
            if(m1!=n1){
                printf("输入不是方阵！\n");
                goto LOOP;
            }
            printf("det(A)=%lf\n",det(A,m1));
            break;
        case 0://退出
            exit(0);
            break;
        default:
            break;
    }
    return 0;
}
