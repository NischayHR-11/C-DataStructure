#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

struct linkedlist{
    struct node*head;
    struct node*tail;
    int size;
};

struct node *createnode(int val){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->next=NULL;
return newnode;
}

void creatlist(struct linkedlist *l,int val){
    struct node *newnode=createnode(val);
    l->tail=newnode;l->head=newnode;
    l->size=1;
}

void insertion(struct linkedlist *l,int val,int pos){
    struct node *newnode=createnode(val);
    if(l->head==NULL){
        creatlist(l,val);
        return;
    }else if(pos==0){
        newnode->next=l->head;
        l->head=newnode;
    }else if(pos>=l->size){
        l->tail->next=newnode;
        newnode->next=NULL;
        l->tail=newnode;
    }else{
        int i=0;struct node *cur=l->head;
        while(i<pos-1){
            cur=cur->next;
            i++;
        }
        newnode->next=cur->next;
        cur->next=newnode;
    }
    l->size++;
}

void  orderedinsertion(struct linkedlist *l1,int val){
    struct node *cur=l1->head;struct node *newnode=createnode(val);
    if(l1->head->data>val){
        newnode->next=l1->head;
        l1->head=newnode;
        return;
    }
    while(cur->next!=NULL&& cur->next->data<val){
        cur=cur->next;
    }
    newnode->next=cur->next;
    cur->next=newnode;
    l1->size++;
}

void delete(struct linkedlist *l,int n){
    if(n==0){
        struct node *p=l->head;
        l->head=l->head->next;
        free(p);
        l->size--;
        return;
    }
        struct node *cur=l->head;int i=0;
        while(i<n-1){
            cur=cur->next;
            i++;
        }
        if(n==l->size-1)
        l->tail=cur;
        struct node *p=cur->next;
        cur->next=cur->next->next;
        free(p);
        l->size--;
}

void deleteAll(struct linkedlist *l){
    if(l->head==NULL){
        printf("NO LIST PRESENT!!");
    }
    struct node *cur=l->head;struct node *next;
    while(cur!=NULL){
        next=cur->next;
        free(cur); 
        cur=next;
    }
    l->head=NULL;
}

int search(struct linkedlist *l,int n){
    struct node *cur=l->head;int i=0;
    while(cur->next!=NULL){
        if(cur->data==n)
        return i;
        cur=cur->next;i++;
    }
    return-1;
}

int getElement(struct linkedlist *l,int n){
    int i=0;struct node *cur=l->head;
    while(i<n){
        cur=cur->next;
        i++;
    }
    return cur->data;
}

void reverse(struct linkedlist*l){
    struct node*next=NULL;
    struct node*prev=NULL;
    while(l->head!=NULL){
        next=l->head->next;
        l->head->next=prev;
        prev=l->head;
        l->head=next;
    }
    l->head=prev;
    printf("LIST REVERSED SUCESSFULLY...\n");
}

void display(struct linkedlist *l){
        if(l->head==NULL){
        printf("NO LIST PRESENT!!\n");
        return;
    }
    struct node *cur=l->head;
    while(cur->next!=NULL){
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("%d\n",cur->data);
}
int main(){
int n,k,k1;
struct linkedlist *l=(struct linkedlist*)calloc(1,sizeof(struct linkedlist));
struct linkedlist *l1=(struct linkedlist*)calloc(1,sizeof(struct linkedlist));
 do{
           printf("------------------------------------- MENU -----------------------------------\n");
           printf("1.CREATE SINGLY LINKED LIST\n");
           printf("2.INSERT ELEMENT AT BEGINING\n");
           printf("3.INSERT ELEMENT AT END\n");
           printf("4.INSERT ELEMENT AT PARTICULAR INDEX\n");
           printf("5.DELETE ELEMENT\n");
           printf("6.DELETE ENTIRE LIST\n");
           printf("7.SEARCH ELMENT\n");
           printf("8.GET ELEMENT AT PARTICULAR INDEX\n");
           printf("9.DISPLAY LIST\n");
           printf("10.REVRSE LIST\n");
           printf("11.CREATE AN ORDERED LIST\n");
           printf("12.INSERTION AT ORDERED LINKED LIST\n");
           printf("13.DISPLAY ORDERED LIST\n");
           printf("14.EXIT\n");
           printf("--------------------------------------------------------------------------------\n");
           printf("ENTER THE CHOICE :\n");
            scanf("%d",&n);
            switch (n) {
                    case 1:
                    printf("ENTER THE VALUE OF FIRST ELEMENT :\n");
                    scanf("%d",&k);
                    creatlist(l,k);
                    break;
                    case 2:                    
                    printf("ENTER THE VALUE OF ELEMENT TO INSERT :\n");
                    scanf("%d",&k);
                    insertion(l,k,0);
                    break;
                    case 3:
                    printf("ENTER THE VALUE OF ELEMENT TO INSERT :\n");
                    scanf("%d",&k);
                    insertion(l,k,l->size+2);
                    break;
                    case 4:                    
                    printf("ENTER THE VALUE AND POSITION OF ELEMENT TO INSERT :\n");
                    scanf("%d %d",&k,&k1);
                    insertion(l,k,k1);
                    break;
                    case 5:
                    printf("ENTER THE INDEX OF ELEMENT TO DELETE :\n");
                    scanf("%d",&k);
                    delete(l,k);
                    break;
                    case 6:
                    printf("LIST DELETED SUCCESSFULLY.......\n");
                    deleteAll(l);
                    break;
                    case 7:                    
                    printf("ENTER THE ELEMENT TO SEARCH :\n");
                    scanf("%d",&k);
                    if(search(l,k)==-1)
                    printf("NO SUCH ELEMENT PRESENT IN LIST!!\n");
                    printf("INDEX : %d\n",search(l,k));
                    break;
                    case 8:
                    printf("ENTER THE INDEX :\n");
                    scanf("%d",&k);
                    printf("ELEMENT :  %d\n",getElement(l,k));
                    break;
                    case 9:
                    display(l);
                    break;
                    case 10:
                    reverse(l);
                    break;
                    case 11:
                    printf("ENTER THE VALUE OF FIRST ELEMENT :\n");
                    scanf("%d",&k);
                    creatlist(l1,k);
                    break;
                    case 12: 
                    printf("ENTER THE VALUE OF ELEMENT TO INSERT :\n");
                    scanf("%d",&k);
                    orderedinsertion(l1,k);
                    break;
                    case 13 :
                    display(l1);
                    break;
                    case 14:
                    exit(0);
                    break;
            
                   default:
                   exit(0);
            }
        }while(1);
return 0;
}

