#include<stdio.h>
#include<stdlib.h>

struct queue{

    int front,rear;
    int size;
    int *a;

};

void enqueue(struct queue *q,int val){

    if(q->rear==q->size-1){
        printf("ENQUEUE NOT POSSIBLE !! QUEUE IS FULL \n");
        return;
    }

    if(q->front==-1){
        q->front=0;
        q->a=(int *)malloc(q->size*sizeof(int));
        q->a[++q->rear]=val;
        return;
    }

    int i;
    for( i=q->rear;i>=0 && val< q->a[i] ;i--){
        q->a[i+1]=q->a[i];
    }

    q->a[i+1]=val;
    q->rear++;
}

int dequeue(struct queue *q){

    if(q->front==-1 && q->rear==-1){
        printf("DEQUEUE NOT POSSIBLE !! QUEUE IS EMPTY\n");
        return -1;
    }

    int n=q->a[q->front];

    if(q->front==q->rear){
        q->rear=q->front=-1;
    }else{
        q->front++;
    }

    return n;
}

int peek(struct queue *q){

    if(q->front==-1 && q->rear==-1){
        printf("QUEUE IS EMPTY\n");
        return -1;
    }

    return q->a[q->front];

}

void display(struct queue *q){

    for(int i=q->front;i<=q->rear;i++){

        printf("%d ",q->a[i]);
    }

    printf("\n");
}

int main(){

int n;
struct queue *s=(struct queue *)malloc(sizeof(struct queue));
printf("ENTER THE SIZE OF THE QUEUE REQIURED :\n");
scanf("%d",&s->size);
printf("%d\n",s->size);
s->front=s->rear=-1;
do{
printf("-----------------------------------------\n");
printf("1.ENQUEUE\n");
printf("2.DEQUEUE\n");
printf("3.PEEK\n");
printf("4.DISPLAY\n");
printf("5.EXIT\n");
printf("-----------------------------------------\n");
printf("ENTER THE CHOICE :\n");
scanf("%d",&n);

switch(n){

    case 1:
    printf("ENTER THE ELEMENT TO ENQUEUE :\n");
    scanf("%d",&n);
    enqueue(s,n);
    break;

    case 2 :
    printf("DEQUEUED ELEMENT IS : %d\n",dequeue(s));
    break;

    case 3 :
    printf("FRONT ELEMENT OF THE QUEUE IS : %d\n",peek(s));
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