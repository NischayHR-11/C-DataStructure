#include<stdio.h>
void rmatrix(int r,int c,int a[r][c]);
void pmatrix(int r,int c,int a[r][c]);
void tmatrix(int r,int c,int a[r][c],int b[c][r]);
void main(){
printf("----------------- TRANSPOSE MATRIX-----------------\n\n");
int r,c;
printf("ENTER ROW AND COULMN\n");
scanf("%d %d",&r,&c);
int a[r][c],t[c][r];
printf("ENTER THE MATRIX:\n");
rmatrix(r,c,a);
printf("THE ENTERED MATRIX IS :\n");
pmatrix(r,c,a);
printf("\n");
printf("TRANSPOSE OF THIS MATRIX IS :\n");
tmatrix(r,c,a,t);
pmatrix(c,r,t);
printf("\n");
printf("******* THANK YOU *******\n");
printf("-----------------------------------------------------\n\n");

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
void tmatrix(int r,int c,int a[r][c],int b[c][r]){
     for(int i=0;i<c;i++){
        for(int j=0;j<r;j++)
        b[i][j]=a[j][i];
    }
}