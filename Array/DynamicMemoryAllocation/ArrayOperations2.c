#include<stdio.h>
#include<stdlib.h>

void InsertByOrder(int *a,int CAPACITY,int *size,int val){

    if(*size>CAPACITY){
        printf("ARRAY IS FULL !!\n");
        return;
    }

    int i=*size-1;

    for(;a[i]>val && i>=0;i--){
    
    a[i+1]=a[i];

    }

    a[i+1]=val;
    *size=*size+1;

}

void DeleteByPosition(int *a,int *size,int pos){

    if(pos>*size-1){
        printf("INVALID POSITION !!\n");
        return;
    }

    for(int i=pos;i<*size;i++){

        a[i]=a[i+1];
    }

    *size=*size-1;
    printf("ELEMENT DELETED SUCCESSFULLY ...\n");

}

int SearchByKey(int *a,int *size,int key){

    for(int i=0;i<*size;i++){

        if(a[i]==key)
        return i;

    }
    printf("ELEMENT NOT FOUND !!\n");
    return -1;

}

void DeleteByKey(int *a,int *size,int val){

    int index=SearchByKey(a,size,val);
    if(index==-1){
        printf("ELEMENT NOT FOUND !! CANNOT DELETE ..\n");
        return;
    }
    DeleteByPosition(a,size,index);

}


void Reverse(int *a,int *size){

    for(int i=0;i<*size/2;i++){

        int temp=a[i];
        a[i]=a[*size-i-1];
        a[*size-i-1]=temp;
    }
}

void display(int *a,int *size){

    for(int i=0;i<*size;i++){

        printf("%d ",a[i]);

    }
    printf("\n");
}

int main(){

    int n,c;int n1,n2;
    printf("ENTER THE CAPACITY and SIZE OF THE ARRAY :\n");
    scanf("%d%d",&c,&n);
    int *a=(int *)malloc(c*sizeof(int));
    printf("ENTER THE ELEMENTS :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("ENTERED ELEMENTS IS :\n");
    display(a,&n);
    do{
    printf("-----------------------------------------------------------\n");
    printf("1.INSERT BY ORDER \n");
    printf("2.SEARCH BY KEY \n");
    printf("3.REVERSE THE ARRAY \n");
    printf("4.DELETE BY KEY \n");
    printf("5.DELETE BY POSITON \n");
    printf("6.DISPALY \n");
    printf("7.EXIT\n");
    printf("-----------------------------------------------------------\n");
    printf("ENTER THE CHOICE :\n");
    scanf("%d",&n1);

    switch(n1){

        case 1 :
        printf("ENTER THE ELEMENT TO INSERT :\n");
        scanf("%d",&n1);
        InsertByOrder(a,c,&n,n1);
        break;

        case 2 :

        printf("ENTER THE VALUE TO SEARCH : \n");
        scanf("%d",&n1);
        printf("ELEMENT IS FOUND AT INDEX  : %d\n",SearchByKey(a,&n,n1));
        break;

        case 3:

        Reverse(a,&n);
        printf("ARRAY IS REVERSED SUCCESSFULLY...\n");
        break;

        case 4 :
        printf("ENTER THE ELEMENT TO DELETE :\n");
        scanf("%d",&n1);
        DeleteByKey(a,&n,n1);
        break;

        case 5:
        printf("ENTER THE POSITION OF ELEMENT TO DELETE :\n");
        scanf("%d",&n1);
        DeleteByPosition(a,&n,n1);
        break;

        case 6:
        display(a,&n);
        break;

        case 7:
        printf("EXITING....\n");
        exit(0);

        default:
        printf("EXITING....\n");
        exit(0);
    }

    display(a,&n);

    }while(1);


    return 0;
}