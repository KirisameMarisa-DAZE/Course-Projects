//
//  main.c
//  121102
//
//  Created by 李佩哲 on 2021/12/8.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int stunum;          //学号
    char name[20];    //姓名
    float examscore;    //考试成绩
    float labscore;    //实验成绩
    float totalmark;    //总评成绩
    struct student * next;  //下一个结点
} STU;

STU *create(int n){
    STU *head, *node, *end;
    head=(STU*)malloc(sizeof(STU));
    end=head;
    for (int i=0; i<n; i++) {
        node=(STU*)malloc(sizeof(STU));
        scanf("%d%s%f%f",&node->stunum,node->name,&node->examscore,&node->labscore);
        node->totalmark=0.6*node->examscore+0.4*node->labscore;
        end->next=node;
        end=node;
    }
    end->next=NULL;
    for(int i=0;i<n;i++)
        for (STU *q=head; (q!=NULL)&&(q->next!=NULL)&&(q->next->next!=NULL); q=q->next) {
            if ((q==head)&&(q->totalmark<=q->next->totalmark)) {
                STU *p=q->next->next;
                head=q->next;
                q->next->next=q;
                q->next=p;
            }
            else if (q->next->totalmark<=q->next->next->totalmark) {
                    if (q->next->next==end) {
                        end=q->next;
                        q->next=q->next->next;
                        q->next->next=end;
                        end->next=NULL;
                    }
                    else{
                        STU *p1=q->next,*p2=q->next->next->next;
                        q->next=q->next->next;
                        q->next->next=p1;
                        q->next->next->next=p2;
                    }
                }
        }
    return head;
}

STU *delete(STU *head,int stunum){
    STU *p=head;
    STU *q=p;
    for(;(p->stunum!=stunum)&&(p!=NULL)&&(p->next!=NULL);p=p->next)
        q=p;
    if(p->stunum==stunum){
        q->next=p->next;
        free(p);
    }
    else printf("NULL Person\n");
    return head;
}

STU *insert(STU *head){
    STU *node, *end=head;
    for(;end->next!=NULL;end=end->next);
    node=(STU*)malloc(sizeof(STU));
    scanf("%d%s%f%f",&node->stunum,node->name,&node->examscore,&node->labscore);
    node->totalmark=0.6*node->examscore+0.4*node->labscore;
    end->next=node;
    end=node;
    end->next=NULL;
    for(int i=0;i<10;i++)
        for (STU *q=head; (q!=NULL)&&(q->next!=NULL)&&(q->next->next!=NULL); q=q->next) {
            if ((q==head)&&(q->totalmark<=q->next->totalmark)) {
                STU *p=q->next->next;
                head=q->next;
                q->next->next=q;
                q->next=p;
            }
            else if (q->next->totalmark<=q->next->next->totalmark) {
                    if (q->next->next==end) {
                        end=q->next;
                        q->next=q->next->next;
                        q->next->next=end;
                        end->next=NULL;
                    }
                    else{
                        STU *p1=q->next,*p2=q->next->next->next;
                        q->next=q->next->next;
                        q->next->next=p1;
                        q->next->next->next=p2;
                    }
                }
        }
    return head;
}

int main(int argc, const char * argv[]) {
    int stunum;
    STU *p=create(10);
    printf("Sorted:\n");
    for (STU *q=p; q!=NULL; q=q->next)
        if(q->stunum!=0)
            printf("%d %s:%f\n",q->stunum,q->name,q->totalmark);
    printf("Delete:");
    scanf("%d",&stunum);
    p=delete(p, stunum);
    printf("Deleted:\n");
    for (STU *q=p->next; q!=NULL; q=q->next)
        if(q->stunum!=0)
            printf("%d %s:%f\n",q->stunum,q->name,q->totalmark);
    printf("Insert:");
    p=insert(p);
    printf("Inserted:\n");
    for (STU *q=p->next; q!=NULL; q=q->next)
        if(q->stunum!=0)
            printf("%d %s:%f\n",q->stunum,q->name,q->totalmark);
    return 0;
}
/*
71250李霞    95    82
69753李友友   88    86
12254东方亮   87    88
61256张男    73    85
30258孙杰    25    88
11260柯以乐   82    76
33262谢涛    91    85
29263叶林    80    75
22483陈翔    80    76
71525王子    71    88
*/
