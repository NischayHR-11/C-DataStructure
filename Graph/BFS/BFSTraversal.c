#include<stdio.h>
#include<stdlib.h>

int visited[5]={0,0,0,0,0}; 

void BFS(int i,int size,int matrix[5][5]){

    int q[50]; int front=0;int rear=-1;

    q[++rear]=i;
    visited[i]=1;

    while(front<=rear){

        int cur=q[front++];

        printf("%d ",cur);

        for(int i=0;i<size;i++){

           if( matrix[cur][i]==1 && visited[i]==0 ){

            q[++rear]=i;
            visited[i]=1;

           }
        }

    }
}


int main(){

    int matrix[5][5]={{0,1,1,1,0},{1,0,0,0,1},{1,0,0,1,0},{1,0,1,0,1},{0,1,0,1,0}};
    BFS(0,5,matrix);
}