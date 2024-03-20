#include<stdio.h>
#include<stdlib.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

};

int count=0;

struct node *createnode(int val){

    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->right=NULL;
    newnode->left=NULL;

    return newnode;
}


struct node *Insert(struct node *root,int val){

    if(root==NULL){
    struct node *newnode=createnode(val);
    printf("%d is Successfully Inserted ..\n",newnode->data);
    return newnode;
    }

    if(val>root->data){

        root->right=Insert(root->right,val);
    }else{

        root->left=Insert(root->left,val);
    }

    return root;

}


void Search(struct node *root,int val){

    struct node *parent=NULL;
    struct node *cur=root;

    while(cur!=NULL){

        if(cur->data==val){
            printf("ELEMENT FOUND IN TREE ...\n");
            printf("PARENT IS %d\n",parent->data);
            return;
        }

        if(val>cur->data){
            parent=cur;
            cur=cur->right;
        }else{
            parent=cur;
            cur=cur->left;
        }
    }

    printf("ELEMENT NOT FOUND IN THE TREE !!!\n");

}

struct node *Minimum(struct node *node){

    if(node->left==NULL){
        return node;
    }
    
    Minimum(node->left);
}


struct node *delete(struct node *root,int val){

    if(root==NULL){
        printf("ELEMENT NOT EXISIT IN THE TREE !!\n");
        return root;
    }

    if(val>root->data){
    root->right= delete(root->right,val);
    }else if(val<root->data){
        root->left=delete(root->left,val);
    }else{

        if(root->left!=NULL && root->right!=NULL){

            struct node *min=Minimum(root->right);
            root->data=min->data;
            root->right=delete(root->right,min->data);

        }else if(root->left!=NULL){

            root=root->left;
        }else{

            root=root->right;
        }
    }

 return root;

}


void MaximumElement(struct node *root){

    struct node *parent=NULL;
    struct node *cur=root;

    while(cur->right!=NULL){
        parent=cur;
        cur=cur->right;
    }

    printf("MAXIMUM ELEMENT IS : %d\n",cur->data);
    printf("PARENT OF MAXIMUM ELEMENT IS : %d\n",parent->data);

}


void preOrderdisplay(struct node *root){

    if(root==NULL){
        return;
    }

    printf("%d ",root->data);
    preOrderdisplay(root->left);
    preOrderdisplay(root->right);
}


void postOrderdisplay(struct node *root){

    if(root==NULL){
        return;
    }

    postOrderdisplay(root->left);
    postOrderdisplay(root->right);
    printf("%d ",root->data);

}


void InOrderdisplay(struct node *root){

    if(root==NULL){
        return;
    }

    InOrderdisplay(root->left);
    printf("%d ",root->data);
    count++;
    InOrderdisplay(root->right);

}


void LevelOrderdisplay(struct node *root){

    struct node *q[50], *cur;
    int front=0;int rear=-1;

    q[++rear]=root;

    while(front<=rear){

        cur=q[front++];

        printf("%d ",cur->data);

        if(cur->left !=NULL){
            q[++rear]=cur->left;
        }
        if(cur->right !=NULL){
            q[++rear]=cur->right;
        }

    }

    printf("\n");

}



int main(){

    struct node *root=NULL;

    root=Insert(root,1);
    Insert(root,3);
    Insert(root,4);
    Insert(root,2);
    Insert(root,5);
    LevelOrderdisplay(root);
    InOrderdisplay(root);
    printf("\n");
    Search(root,6);
    MaximumElement(root);
    printf("NUMBER OF NODES : %d\n",count);
    delete(root,3);
    InOrderdisplay(root);


}