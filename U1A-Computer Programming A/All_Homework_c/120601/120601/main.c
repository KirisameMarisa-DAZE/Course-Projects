//
//  main.c
//  120601
//
//  Created by 李佩哲 on 2021/11/2.
//

#include <stdio.h>

float change(float x){
    x*=100;
    int i = (int)x;
    if((i%10)>=5){
        i+=10;
    }
    return i/10;
}

int main() {
    float x;
    int money[8]={1000,500,200,100,50,10,5,1};
    int charge[8]={0,0,0,0,0,0,0,0};
    for(;;){
        printf("x=");
        scanf("%f",&x);
        if (x<0.0||x>100.0){
            printf("请输入正确的x！\n");
            continue;
        }
        int t=change(100-x);
        printf("共找零%.1f元:\n",100-x);
        for (int i=0; i<8; i++) {
            charge[i]=(int)(t/money[i]);
            t-=charge[i]*money[i];
            if(i<6&&charge[i]!=0)printf("%d张%d元\n",charge[i],money[i]/10);
            else {if (charge[i]!=0)printf("%d张%d角\n",charge[i],money[i]);}
        }
        break;
    }
    return 0;
}
