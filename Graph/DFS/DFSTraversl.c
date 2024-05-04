#include<stdio.h>
#include<stdlib.h>

int visited[8]={0,0,0,0,0,0,0,0}; 

void DFS(int i,int size,int matrix[][8]){

    int s[50]; int top=-1;

    s[++top]=i;
    visited[i]=1;

    while(top>=0){

        int cur=s[top--];

        printf("%d ",cur);

        for(int i=0;i<size;i++){

           if( matrix[cur][i]==1 && visited[i]==0 ){

            s[++top]=i;
            visited[i]=1;

           }
        }

    }
}


int main(){

    int matrix[5][5]={{0,1,1,1,0},{1,0,0,0,1},{1,0,0,1,0},{1,0,1,0,1},{0,1,0,1,0}};
    DFS(0,5,matrix);
}