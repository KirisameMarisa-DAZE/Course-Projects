//
//  main.c
//  120503
//
//  Created by 李佩哲 on 2021/10/27.


#include <stdio.h>

int main() {
    int n, m;
    printf("n,m=");
    scanf("%d%d", &n, &m );
    int soldiers[100];
    for(int i = 0; i < n; i++) {
        soldiers[i] = 1;//设置总人数
    }
    for (int i=n; i<100; i++) {
        soldiers[i]=0;
    }
    int t = 0;
    for(int i = (m - 1)%n; t < n - 1 ; t++) {//激动人心的连环杀人环节
        soldiers[i] = 0;//杀人
        printf("kill i=%d\n",i+1);
        if(i > n - 1) {//判断超范围了没，超了就从头再来
            i = i % n;//回到开头
        }
        int r=0;
        while (r < m) {//找下一个人的编号
            i=(i+1)%n;
            LOOP:switch (soldiers[i]) {
                case 0:
                    i=(i+1)%n;
                    goto LOOP;
                    break;
                    
                case 1:
                    r++;
                    break;
                    
                default:
                    break;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {//输出活着的人
        if(soldiers[i] != 0) {
            printf("%d survives.\n", i + 1);
        }
    }
    return 0;
}
