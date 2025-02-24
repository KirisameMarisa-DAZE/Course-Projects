//
//  main.c
//  120202
//
//  Created by 李佩哲 on 2021/9/30.
//

#include <stdio.h>

int judgement(float a, float b){
    int bolean;
    if (a<=1 && a>=-1 && b<=1&&b>=-1)
    {
        bolean = 1;
    }
    
    else{
        bolean = 0;
    }
    
    return bolean;
}

int main() {
    float x,y;
    int c;
    printf("Input:");
    scanf("%f%f",&x,&y);
    c = judgement(x,y);
    if(c == 1){
        printf("Yes.\n");
    }
    else{
        printf("No.\n");
    }
    return 0;
}
