//
//  main.c
//  121202
//
//  Created by 李佩哲 on 2021/12/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct music{
    int Hz;
    int time;
    struct music *next;
} MUSIC;

void play(MUSIC*head){
    for (MUSIC*p=head; p!=NULL; p=p->next) {
        Beep(p->Hz,p->time);
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/page/Documents/-文稿/1-学习/1-理学/5-计算机科学/2-C/Homework/All_Homework_c/121202/MUSIC.txt", "r", stdin);
    MUSIC *head, *node, *end;
    head=(MUSIC*)malloc(sizeof(MUSIC));
    end=head;
    for (MUSIC*p=(MUSIC*)malloc(sizeof(MUSIC)); (scanf("%d%d",&p->Hz,&p->time)!=EOF); end=node) {
        node=(MUSIC*)malloc(sizeof(MUSIC));
        node->Hz=p->Hz;
        node->time=p->time;
        end->next=node;
    }
    end->next=NULL;
    play(head);
    return 0;
}
