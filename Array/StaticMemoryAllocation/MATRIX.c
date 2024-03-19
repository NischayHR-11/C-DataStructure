#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void rmatrix(int r,int c,int a[r][c]);
void pmatrix(int r,int c,int a[r][c]);
void addmatrix(int r,int c,int a[r][c],int b[r][c],int sum[r][c]);
void submatrix(int r,int c,int a[r][c],int b[r][c],int sum[r][c]);
int trace(int r,int c,int p[r][c]);
float norm(int r,int c,int p[r][c]);
void main(){
    printf("------------------------------------- MATRIX ---------------------------------------\n\n");
    int r1,c;
    printf("ENTER THE SIZE OF ARRAY REQUIRED FOR BOTH A and B MATRIX:\n");
    scanf("%d %d",&r1,&c);
    int p[r1][c],q[r1][c],r[r1][c],n,a,b;
    printf("ENTER THE MATRIX A:\n");
    rmatrix(r1,c,p);
    printf("ENTER THE MATRIX B:\n");
    rmatrix(r1,c,q);
    printf("THE GIVEN MATRIX A is:\n");
    pmatrix(r1,c,p);
    printf("\n");
    printf("THE GIVEN MATRIX B is:\n");
    pmatrix(r1,c,q);
     do{
     printf("\n");
     printf("ENTER THE CHOICE:\n");
     printf("1:addition\n");
     printf("2:subtraction\n");
     printf("3.Trace\n");
     printf("4.Norm\n");
     printf("5:EXIT\n");
     scanf("%d",&n);
     switch(n){
     case 1:
     printf("-----------------------------------------\n");
     printf("addition of A and B is:\n");
     addmatrix(r1,c,p,q,r);
     pmatrix(r1,c,r);
     printf("-----------------------------------------\n");
     break;
     case 2:
     printf("-----------------------------------------\n");
     printf("subtraction of A and B is:\n");
     submatrix(r1,c,p,q,r);
     pmatrix(r1,c,r);
     printf("-----------------------------------------\n");
     break;
     case 3:
     if(r1==c){
     printf("ENTER THE CHOICE:\n");
     printf("1:TRACE OF A\n");
     printf("2:TRACE OF B\n");
     printf("3.TRACE OF BOTH A and B\n");
     scanf("%d",&a);
     printf("-----------------------------------------\n");
     if(a==1){
     printf("Trace of A is:%d\n",trace(r1,c,p));
     }else if(a==2){
     printf("Trace of B is:%d\n",trace(r1,c,q));
     }else{
     printf("Trace of A is:%d\n",trace(r1,c,p));
     printf("Trace of B is:%d\n",trace(r1,c,q));
     }
     printf("-----------------------------------------\n");
     }else{
        printf("-----------------------------------------\n");
        printf("NOT COMPATIBLE\n");
        printf("-----------------------------------------\n");
     }
     break;
     case 4:
     printf("ENTER THE CHOICE:\n");
     printf("1:NORM OF A\n");
     printf("2:NORM OF B\n");
     printf("3.NORM OF BOTH A and B\n");
     scanf("%d",&b);
     printf("-----------------------------------------\n");
     if(b==1){
     printf("NORM of A is:%f\n",norm(r1,c,p));
     }else if(b==2){
     printf("NORM of B is:%f\n",norm(r1,c,q));
     }else{
     printf("NORM of A is:%f\n",norm(r1,c,p));
     printf("NORM of B is:%f\n",norm(r1,c,q));
     }
     printf("-----------------------------------------\n");
     break;
     case 5:
     printf("******************** THANK YOU *******************\n");
     printf("--------------------------------------------------------------------------------\n\n");
     exit(0);
     default:
     printf("invalid entry:\n");

     }
    }while(1);


}
void rmatrix(int r,int c,int a[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }
}

void pmatrix(int r,int c,int a[r][c]){
       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    
}
void addmatrix(int r,int c,int a[r][c],int b[r][c],int sum[r][c]){
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        sum[i][j]=a[i][j]+b[i][j];
      }
    
}
void submatrix(int r,int c,int a[r][c],int b[r][c],int sum[r][c]){
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        sum[i][j]=a[i][j]-b[i][j];
      }

}
int trace(int r,int c,int p[r][c]){
    int sum=0;
    for(int i=0;i<r;i++){
      sum=sum+p[i][i];
    }
    return sum;
}
 float norm(int r,int c,int p[r][c]){
    int sum=0;
    float t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum=sum+p[i][j]*p[i][j];

        }

    }
    t=sqrt(sum);
    return t;

}