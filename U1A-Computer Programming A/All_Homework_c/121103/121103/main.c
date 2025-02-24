//
//  main.c
//  121103
//
//  Created by 李佩哲 on 2021/12/8.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList{
    double coefficient;
    int exponent;
    struct LinkList *next;
    struct LinkList *prior;
} SUM;

SUM *define(int n){
    SUM *head, *node, *end;
    head=(SUM*)malloc(sizeof(SUM));
    head->prior=NULL;
    end=head;
    for(int i=1;i<=n;i++){
        node=(SUM*)malloc(sizeof(SUM));
        scanf("%lf%d",&node->coefficient,&node->exponent);
        if(node->coefficient==0)i--;
        node->prior=end;
        end->next=node;
        end=node;
    }
    end->next=NULL;
    return head;
}

SUM *sort(SUM *head,SUM *head2){
    void print(SUM *head);
    SUM *p1=head, *p2=head2;
    for(;p1->next!=NULL;p1=p1->next);
    for (; ; p2=p2->next) {
        p1->next=p2;
        p1=p2;
        if(p2->next==NULL)break;
    }
    p1->next=NULL;
    for(int i=0;i<10;i++)
        for (SUM *q=head; (q!=NULL)&&(q->next!=NULL)&&(q->next->next!=NULL); q=q->next) {
            if ((q==head)&&(q->exponent<=q->next->exponent)) {
                SUM *p=q->next->next;
                head=q->next;
                q->next->next=q;
                q->next=p;
            }
            else if (q->next->exponent<=q->next->next->exponent) {
                    if (q->next->next==p1) {
                        p1=q->next;
                        q->next=q->next->next;
                        q->next->next=p1;
                        p1->next=NULL;
                    }
                    else{
                        SUM *p1=q->next,*p2=q->next->next->next;
                        q->next=q->next->next;
                        q->next->next=p1;
                        q->next->next->next=p2;
                    }
                }
        }
    for (p1=head; (p1!=NULL)&&(p1->next!=NULL); ) {
        if (p1->exponent==p1->next->exponent) {
            p1->coefficient=p1->coefficient+p1->next->coefficient;
            SUM *temp=p1->next;
            p1->next=p1->next->next;
            free(temp);
        }
        else p1=p1->next;
        if(p1->next==NULL)
            break;
    }
    return head;
}

void print(SUM *head){
    int i=0,r=0;
    for (SUM *p=head; (p!=NULL); p=p->next) {
        if((p!=NULL)&&((int)(p->coefficient)!=0)){
            if((p->coefficient>0)&&(i!=0))printf("+");
            if(p->exponent==0)printf("%.0lf",p->coefficient);
            else if(p->exponent==1)printf("%.0lfx",p->coefficient);
            else printf("%.0lfx^%d",p->coefficient,p->exponent);
            r=1;
        }
        i++;
    }
    if(r==0)printf("0");
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int n1,n2;
    scanf("%d",&n1);
    SUM *p1=define(n1);
    scanf("%d",&n2);
    SUM *p2=define(n2);
    SUM *p=sort(p1,p2);
    print(p);
    return 0;
}
