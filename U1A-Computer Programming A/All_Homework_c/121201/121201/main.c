//
//  main.c
//  121201
//
//  Created by 李佩哲 on 2021/12/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str{
    char s;
    struct str *next;
} STR;

STR *secret(STR *head){
    for (STR*p=head; p!=NULL; p=p->next) {
        if((p->s<='s'&&p->s>='a')||(p->s<='S'&&p->s>='A'))p->s+=7;
        else if (p->s>'s'&&p->s<='z')p->s+='a'+6-'z';
        else if (p->s>'S'&&p->s<='Z')p->s+='A'+6-'Z';
        else continue;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    STR *head, *node, *end;
    head=(STR*)malloc(sizeof(STR));
    end=head;
    FILE *fp=freopen("/Users/page/Documents/-文稿/1-学习/1-理学/5-计算机科学/2-C/Homework/All_Homework_c/121201/secrect.txt", "r", stdin);
    for (STR*p=(STR*)malloc(sizeof(STR)); (scanf("%c",&p->s)!=EOF); ) {
        node=(STR*)malloc(sizeof(STR));
        node->s=p->s;
        end->next=node;
        end=node;
    }
    end->next=NULL;
    head=secret(head);
    fclose(fp);
    FILE *fp1=freopen("/Users/page/Documents/-文稿/1-学习/1-理学/5-计算机科学/2-C/Homework/All_Homework_c/121201/secrect.txt", "w", stdin);
    for (STR*p=head; p!=NULL; p=p->next) {
        fprintf(fp1,"%c",p->s);
    }
    fclose(fp1);
    return 0;
}
