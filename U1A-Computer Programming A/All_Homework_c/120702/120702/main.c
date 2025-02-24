//
//  main.c
//  120702
//
//  Created by 李佩哲 on 2021/11/10.
//

#include <stdio.h>
#include <stdlib.h>

int tpmatrix[5][5];

int main(){
    void transpose(int pmatrix[5][5]);
    int pmatrix[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };
    transpose(pmatrix);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            printf("%d ", tpmatrix[i][j]);
        printf("\n");
    }
    return 0;
}

void transpose(int pmatrix[5][5]) {
    for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
    tpmatrix[i][j] = pmatrix[j][i];
}
