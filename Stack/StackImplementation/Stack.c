#include<stdio.h>
#include<stdlib.h>

struct stack{

    int top;
    int size;
    int a[50];

};

void push(struct stack *s,int val){

    printf("%d\n",s->top);
    if(s->top ==s->size-1){
        printf("Stack OverFlow !!\n");
        return;
    }

    s->a[++s->top]=val;
}

int pop(struct stack *s){

    if(s->top<0){
        printf("Stack UnderFlow !!\n");
        return -1;
    }

    return s->a[s->top--];
}

int peek(struct stack *s){

    if(s->top<0){
        printf("Stack UnderFlow !!\n");
        return -1;  
    }

    return s->a[s->top];
}

void display(struct stack *s){

    for(int i=s->top;i>=0;i--){
        printf("%d ",s->a[i]);
    }
    printf("\n");
}

int main(){

int n;
struct stack *s=(struct stack *)malloc(sizeof(struct stack));
printf("ENTER THE SIZE OF THE STACK REQIURED :\n");
scanf("%d",&s->size);
printf("%d\n",s->size);
s->top=-1;
do{
printf("-----------------------------------------\n");
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.PEEK\n");
printf("4.DISPLAY\n");
printf("5.EXIT\n");
printf("-----------------------------------------\n");
printf("ENTER THE CHOICE :\n");
scanf("%d",&n);

switch(n){

    case 1:
    printf("ENTER THE ELEMENT TO PUSH :\n");
    scanf("%d",&n);
    push(s,n);
    break;

    case 2 :
    printf("POPED ELEMENT IS : %d\n",pop(s));
    break;

    case 3 :
    printf("TOP ELEMENT OF THE STACK IS : %d\n",peek(s));
    break;

    case 4 :
    display(s);
    break;

    case 5 :
    exit(0);

    default :
    printf("INVALID OPTION !! TRY AGAIN..\n");
    break;
}

    
}while(1);

}