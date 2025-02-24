//
//  main.c
//  120902
//
//  Created by 李佩哲 on 2021/11/24.
//

// Code file created by C Code Develop

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char **argv) {
    char countries[10][40],*list1[10],*list2[10];
    
    //getsInput
    for(int i=0;i<10;i++)
        for(int j=0;j<40;j++)
            countries[i][j]='\0';
    for(int i=0;i<10;i++)
        gets(countries[i]);
    
    /*
     Saint Vincent and the Grenadines
     El Salvador
     Papua New Guinea
     Niue
     Norfolk Island
     United Arab Emirates
     United Kingdom
     United States
     Slovenia
     Solomon Islands
     */
    
    //list 1
    unsigned long l[10] = {0};
    for(int i = 0; i < 10; i++)//每个国家名的长度
        l[i] = strlen(countries[i]) ;
    for(int r = 0; r < 10; r++) {
        int min = 0;
        for(int i = 0; i < 10; i++)
            if (l[min] >= l[i])min = i;
        list1[r] = &countries[min][0];
        l[min] = 40;
    }
    
    //List 2
    int s[10];
    for(int i=0;i<10;i++)
        s[i]=countries[i][0];
    for(int r = 0; r < 10; r++) {
        int min = 0;
        for(int i = 0; i < 10; i++)
            if (s[min] >= s[i])min = i;
        list2[r] = &countries[min][0];
        s[min] = 200;
    }
    
    //print
    printf("List 1:\n");
    for(int i = 0; i < 10; i++) {
        for(int j=0; j<40 ;j++)
            printf("%c", *(list1[i]+j));
        printf("\n");
    }
    printf("\nList 2:\n");
    for(int i = 0; i < 10; i++) {
        for(int j=0; j<40 ;j++)
            printf("%c", *(list2[i]+j));
        printf("\n");
    }
    return 0;
}
;
