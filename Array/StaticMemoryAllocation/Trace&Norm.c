#include<stdio.h>
#include<math.h>
int trace(int p[10][10],int a);
float norm(int p[10][10],int a);
void rmatrix(int p[10][10],int a);
void pmatrix(int p[10][10],int a);
void main(){
    printf("-------------------TRACE AND NORM OF MATRIX----------------\n");
    int q[10][10],a,b;
    printf("enter the size of array:\n");
    scanf("%d %d",&a,&b);
    if(a==b){
        printf("ENTER THE ELEMENTS:\n");
        rmatrix(q,a);
        printf("the given matrix is :\n");
        pmatrix(q,a);
        printf("TRACE OF MATRIX IS: %d\n",trace(q,a));
        printf("NORM OF MATRIX IS :%f\n",norm(q,a));
        printf("-----------------------------------------------------------\n");
    } else{
        printf("invalid array to find trace and form\n");
    }
}
void rmatrix(int p[10][10],int a){
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)
        scanf("%d",&p[i][j]);
    }
}
void pmatrix(int p[10][10],int a){
       for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)
        printf("%d\t",p[i][j]);
        printf("\n");
    }
}
int trace(int p[10][10],int a){
    int sum=0;
    for(int i=0;i<a;i++){
      sum=sum+p[i][i];
    }
    return sum;
}
 float norm(int p[10][10],int a){
    int sum=0;
    float t;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            sum=sum+p[i][j]*p[i][j];

        }

    }
    t=sqrt(sum);
    return t;

}