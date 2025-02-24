//
//  main.c
//  120704
//
//  Created by 李佩哲 on 2021/11/11.
//

/*数字的移动
 Time：1000ms    Memory：65536kb

 题目描述

 有n个整数（n<=20），使前面各数顺序向后移m个位置，最后的m个数则循环移动到前面变成前面m个数。写一函数：实现以上功能，在主函数中输入n个整数、输出调整后的n个整数（数字之间用一个空格分隔）。

 输入

 3行： 第一行输入数据的个数n 第二行输入 n个整数 第三行输入要移动的位置m

 输出

 1行： 移动后的n个数

 样例输入

 10
 1 2 3 4 5 6 7 8 9 10
 2
 样例输出

 9 10 1 2 3 4 5 6 7 8*/

#include <stdio.h>

int main() {
    int n,m;
    scanf("%d",&n);
    int num[n],ans[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&num[i]);
    }
    scanf("%d",&m);
    for (int i=0; i<n; i++) ans[(i+m)%n]=num[i];
    for (int i=0; i<n; i++){
        printf("%d",ans[i]);
        if(i<n-1)printf(" ");
        else printf("\n");
    }
    return 0;
}
