#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
    struct node *prev;

};

struct list{

    struct node *head;
    int size;

};

struct node *createnode(int val){

    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;

    return newnode;

}

void createlist(struct list *l,int val){

    struct node *newnode=createnode(val);
    newnode->next=newnode;
    newnode->prev=newnode;
    l->head=newnode;
    l->size=1;
}

void InsertAtRear(struct list *l,int val){

    if(l->head==NULL){
        createlist(l,val);
        return;
    }

    struct node *newnode=createnode(val);
    newnode->next=l->head;
    newnode->prev=l->head->prev;
    l->head->prev->next=newnode;
    l->head->prev=newnode;
    l->size++;
}

void InsertATFront(struct list *l,int val){

    if(l->head==NULL){
        createlist(l,val);
        return;
    }

    struct node *newnode=createnode(val);
    newnode->next=l->head;
    newnode->prev=l->head->prev;
    l->head->prev->next=newnode;
    l->head->prev=newnode;
    l->head=newnode;
    l->size++;
}

void InsertAtPosition(struct list *l,int pos,int val){

    if(l->head==NULL){
        createlist(l,val);
        return;
    }

    if(pos<=0){
        InsertATFront(l,val);
        return;
    }

    if(pos>l->size){
        InsertAtRear(l,val);
        return;
    }

    struct node *newnode=createnode(val);

    struct node *cur=l->head;int i=0;

    while(cur->next !=l->head && i<pos-1){

        cur=cur->next;
        i++;

    }
    newnode->next=cur->next;
    newnode->prev=cur->next->prev;
    cur->next->prev=newnode;
    cur->next=newnode;
    l->size++;
}

int SearchByPosition(struct list *l,int pos){

    if(l->head==NULL || pos>=l->size || pos<0){

        return -1;
    }

    struct node *cur=l->head;int i=0;

    if(pos==l->size-1){
        return l->head->prev->data;
    }

    while(cur->next!=l->head && i<pos){
        cur=cur->next;
        i++;
    }

    if(cur->next==l->head){
        return -1;
    }

    return cur->data;
}

int SearchByKey(struct list *l ,int key){

    if(l->head==NULL){
        return -1;
    }

    struct node *cur=l->head;
    int i=0;

    while(cur->next!=l->head){

        if(cur->data == key){
            return i;
        }
        cur=cur->next;
        i++;
    }

    if(cur->data==key){
        return i;
    }else{
        return -1;
    }
}

void DeleteByPosition(struct list *l,int pos){

if(l->head==NULL || pos<0 || pos>l->size-1){

    printf("Invalid Position !!\n");
    return;
}

if(pos==0){
    struct node *p=l->head;
    l->head->prev->next=l->head->next;
    l->head->next->prev=l->head->prev;
    l->head=l->head->next;
    free(p);
    l->size--;
    return;
}

    struct node *cur=l->head;int i=0;

    while(cur->next != l->head && i<pos-1){
        cur=cur->next;
        i++;
    }

    struct node *p=cur->next;
    cur->next->next->prev=cur;
    cur->next=cur->next->next;
    free(p);
    l->size--;

}

void DeleteByKey(struct list *l,int key){

    int pos =SearchByKey(l,key);
    DeleteByPosition(l,pos);
}


void InsertByOrder(struct list *l,int val){

    if(l->head==NULL){
        createlist(l,val);
        return;
    }

    if(val<l->head->data){
        InsertATFront(l,val);
        return;
    }

    if(val>l->head->prev->data){
    InsertAtRear(l,val);
    return;
    }

    struct node *newnode=createnode(val);
    struct node *cur=l->head;

    while(cur->next !=l->head && cur->next->data<val){
        cur=cur->next;
    }

    newnode->next=cur->next;
    newnode->prev=cur->next->prev;
    cur->next->prev=newnode;
    cur->next=newnode;
    l->size++;
}

void display(struct list *l){

    struct node *cur=l->head;

    while(cur->next!=l->head){
        printf("%d <-> ",cur->data);
        cur=cur->next;
    }
    printf("%d\n",cur->data);
}

void displayReverse(struct list *l){

    struct node *cur=l->head->prev;

    while(cur->prev!=l->head->prev){
        printf("%d <-> ",cur->data);
        cur=cur->prev;
    }
    printf("%d\n",cur->data);
}

void main(){

    struct list *l=(struct list *)malloc(sizeof(struct list));

    createlist(l,1);
    InsertAtRear(l,2);
    InsertAtRear(l,3);
    InsertAtRear(l,4);
    InsertAtRear(l,5);
    InsertATFront(l,0);
    InsertAtPosition(l,10,6);
    printf("%d\n",SearchByPosition(l,6));
    printf("%d\n",SearchByKey(l,0));
    DeleteByKey(l,6);
    printf("%d\n",l->size);
    
    display(l);

}