//
//  main.c
//  120302
//
//  Created by 李佩哲 on 2021/10/14.
//

#include <stdio.h>

int main() {
    int x,y;
    scanf("%d%d",&x,&y);
    if (x<=2 && y<=2 && x>=-2 && y>=-2){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
