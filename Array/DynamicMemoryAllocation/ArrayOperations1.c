#include<stdio.h>
#include<stdlib.h>

void InsertByPosition(int *a,int *size,int pos,int val){

    if(pos>*size-1){
        printf("INVALID POSITION !!\n");
        return;
    }

    for(int i=*size-1;i>=pos;i--){

        a[i+1]=a[i];
    }

    *size=*size+1;
    a[pos]=val;
}

int SearchByPosition(int *a,int *size,int pos){

    if(pos > *size-1){
        printf("INVALID POSITION !!\n");
    }

    return a[pos];

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
    printf("1.INSERT BY POSITION \n");
    printf("2.SEARCH BY POSITION \n");
    printf("3.REVERSE THE ARRAY \n");
    printf("4.DISPALY \n");
    printf("5.EXIT\n");
    printf("-----------------------------------------------------------\n");
    printf("ENTER THE CHOICE :\n");
    scanf("%d",&n1);

    switch(n1){

        case 1 :
        printf("ENTER THE ELEMENT AND POSITION TO INSERT :\n");
        scanf("%d%d",&n1,&n2);
        InsertByPosition(a,&n,n2,n1);
        break;

        case 2 :

        printf("ENTER THE POSITION TO SEARCH : \n");
        scanf("%d",&n1);
        printf("VALUE OF ELEMENT IS  : %d\n",SearchByPosition(a,&n,n1));
        break;

        case 3:

        Reverse(a,&n);
        printf("ARRAY IS REVERSED SUCCESSFULLY...\n");
        break;

        case 4 :

        display(a,&n);
        break;

        case 5:
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