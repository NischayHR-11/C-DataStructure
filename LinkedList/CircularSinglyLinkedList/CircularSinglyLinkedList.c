#include<stdlib.h>
#include<stdio.h>

struct node{

    int val;
    struct node *next;

};

struct list{

    struct node *head;
    struct node *tail;
    int size;

};

struct node *createnode(int val){

    struct node *newnode =(struct node *)calloc(1,sizeof(struct node));
    newnode->next=NULL;
    newnode->val=val;

    return newnode;
}

void createlist(struct list *l,int val){

    struct node *newnode=createnode(val);
    newnode->next=newnode;
    l->head=newnode;
    l->tail=newnode;
    l->size=1;
}

void InsertATFront(struct list *l,int val){
if(l->head==NULL){
    createlist(l,val);
    return;
}
struct node *newnode=createnode(val);
newnode->next=l->head;
l->head=newnode;
l->tail->next=l->head;
l->size++;
}

void InsertAtPosition(struct list *l,int pos,int val){
if(l->head==NULL){
    createlist(l,val);
    return;
}
struct node *newnode=createnode(val);

struct node *cur=l->head;
if(pos<=0){
InsertATFront(l,val);
return;
}

if(pos>l->size){
    InsertAtRear(l,val);
    return;
}

int i=0;
while(i<pos-1){

    cur=cur->next;
    i++;

}

newnode->next=cur->next;
cur->next=newnode;
l->size++;
}

void InsertAtRear(struct list *l,int val){

    if(l->head==NULL){
        createlist(l,val);
        return;
    }

    struct node *newnode=createnode(val);
    newnode->next=l->head;
    l->tail->next=newnode;
    l->tail=newnode;
    l->size++;
}

int SearchByKey(struct list *l,int val){

    struct node *cur=l->head;int i=0;
    while(cur->next != l->head){
        if(cur->val==val)
        return i;

        cur=cur->next;
        i++;
    }

    return -1;
}

int SearchByPosition(struct list *l,int pos){

if(l->head==NULL && pos<0){
    return -1;
}

struct node *cur=l->head;int i=0;

while(cur->next !=l->head && i<pos){
cur=cur->next;
i++;
}

if(cur->next == l->head){
    printf("INVALID POSITION !!\n");
    return -1;
}

return cur->val;

}

void DeleteByPosition(struct list *l,int pos){

    if(pos>l->size-1 || pos<0){
        printf("INVALID POSITION !!\n");
        return;
    }

    struct node *cur=l->head;
    int i=0;

    if(pos==0){
        int *p=l->head;
        l->head=l->head->next;
        l->tail->next=l->head;
        free(p);
        return;
    }

    while(cur->next!=l->head && i<pos-1){
    cur=cur->next;
    i++;
    }
    int *p=cur->next;
    cur->next=cur->next->next;
    free(p);
    l->size--;
}

void DeleteByKey(struct list *l,int val){

    int pos=SearchByKey(l,val);
    DeleteByPosition(l,pos);

}

void InsertByOrder(struct list *l,int val){

    if(l->head==NULL){
        createlist(l,val);
        return;
    }

    if(val<l->head->val){
        InsertATFront(l,val);
        return;
    }

    struct node *newnode= createnode(val);
    struct node *cur=l->head;

    while(cur->next != l->head && cur->next->val < val){

        cur=cur->next;
    }

    if(cur->next ==l->head){
        InsertAtRear(l,val);
        return;
    }

    newnode->next=cur->next;
    cur->next=newnode;
}

void display(struct list *l){

    struct node *cur =l->head;

    

    while(cur->next!=l->head){
        printf("%d->",cur->val);
        cur=cur->next;
    }
    printf("%d\n",cur->val);

}

void main(){

    struct list *l=(struct list *)calloc(1,sizeof(struct list));
    createlist(l,1);
    InsertAtRear(l,2);
    InsertAtRear(l,3);
    InsertAtRear(l,4);
    InsertAtRear(l,5);
    InsertATFront(l,0);
    InsertAtPosition(l,1,1);
    InsertAtPosition(l,2,8);
    InsertAtPosition(l,10,8);
    printf("%d\n",SearchByKey(l,3));
    printf("%d\n",SearchByPosition(l,3));
    display(l);
    DeleteByPosition(l,-1);
    display(l);
    DeleteByKey(l,8);
    display(l);
    DeleteByPosition(l,7);
    display(l);
}
