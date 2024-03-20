#include<stdio.h>
#include<stdlib.h>

struct queue{

    int front,rear;
    int size;
    int *a;
};

void InserAtFront(struct queue *q,int val){

    if(q->front>0 && q->front < q->rear){
        q->a[--q->front]=val;
        return;
    }
    
    if(q->front==-1){
        q->front=0;
        q->a=(int *)malloc(q->size*sizeof(struct queue));
        q->a[++q->rear]=val;
        return;
    }

    printf("INSERT AT FRONT NOT POSSIBLE !!\n");
}

void InserAtRear(struct queue *q,int val){

    if(q->rear==q->size-1){
        printf("INSERT AT REAR NOT POSSIBLE !! QUEUE IS FULL \n");
        return ;
    }

    if(q->front==-1){
    q->front=0;
    q->a=(int *)malloc(q->size*sizeof(struct queue));
    }

    q->a[++q->rear]=val;

}

int DeleteAtFront(struct queue *q){

    if(q->front==-1 && q->rear==-1){
        printf("DELETE AT FRONT NOT POSSIBLE !!\n");
        return -1;
    }

    int n=q->a[q->front];

    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
    q->front++;
    }

    return n;

}

int DeleteAtRear(struct queue *q){

    if(q->front==-1 && q->rear==-1){
        printf("DELETE AT REAR NOT POSSIBLE !!\n");
        return -1;
    }

    int n=q->a[q->rear];

    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
    q->rear--;
    }

    return n;
}

void display(struct queue *q){

    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->a[i]);
    }

    printf("\n");
}


int main(){

    struct queue *s=(struct queue *)malloc(sizeof(struct queue));
    printf("ENTER THE SIZE OF THE QUEUE REQUIRED :\n");
    scanf("%d",&s->size);
    s->front=s->rear=-1;
    int n;

 do{
        printf("-----------------------------------------\n");
        printf("1.INSERT AT FRNT \n");
        printf("2.INSERT AT REAR\n");
        printf("3.DELETE AT FRONT\n");
        printf("4.DELETE AT REAR\n");
        printf("5.DISPLAY\n");
        printf("6.EXIT\n");
        printf("-----------------------------------------\n");
        printf("ENTER THE CHOICE :\n");
        scanf("%d",&n);

        switch(n){

        case 1:
        printf("ENTER THE ELEMENT TO ENQUEUE :\n");
        scanf("%d",&n);
        InserAtFront(s,n);
        break;

        case 2 :
        printf("ENTER THE ELEMENT TO ENQUEUE :\n");
        scanf("%d",&n);
        InserAtRear(s,n);
        break;

        case 3 :
        printf("DEQUEUED ELEMENT IS : %d\n",DeleteAtFront(s));
        break;

        case 4 :
        printf("DEQUEUED ELEMENT IS : %d\n",DeleteAtRear(s));
        break;

        case 5 :
        display(s);
        break;

        case 6 :
        exit(0);

        default :
        printf("INVALID OPTION !! TRY AGAIN..\n");
        break;
    }

    
}while(1);



}