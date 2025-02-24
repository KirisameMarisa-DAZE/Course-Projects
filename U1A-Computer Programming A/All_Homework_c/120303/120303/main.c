//
//  main.c
//  120303
//
//  Created by 李佩哲 on 2021/10/14.
//

#include <stdio.h>

int main() {
    int score;
    scanf("%d",&score);
    if (score<=100 && score>=0){
        switch (score) {
            case 0 ... 59:
                printf("F; GPA==0\n");
                break;
                
            case 60:
                printf("D-; GPA==1.0\n");
                break;
            
            case 61 ... 63:
                printf("D; GPA==1.3\n");
                break;
                
            case 64:
                printf("D+; GPA==1.5\n");
                break;
                
            case 65 ... 67:
                printf("C-; GPA==1.7\n");
                break;
                
            case 68 ... 71:
                printf("C; GPA==2.0\n");
                break;
                
            case 72 ... 74:
                printf("C+; GPA==2.3\n");
                break;
                
            case 75 ... 77:
                printf("B-; GPA==2.7\n");
                break;
                
            case 78 ... 81:
                printf("B; GPA==3.0\n");
                break;
                
            case 82 ... 84:
                printf("B+; GPA==3.3\n");
                break;
                
            case 85 ... 89:
                printf("A-; GPA==3.7\n");
                break;
                
            case 90 ... 94:
                printf("A; GPA==4.0\n");
                break;
                
            case 95 ... 100:
                printf("A+; GPA==4.3\n");
                break;
                
            default:
                break;
        }
    }
    
    else{
        printf("ERROR\n");
    }
    return 0;
}
