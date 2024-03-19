#include<stdio.h>
void main(){
    printf("------------------ PRIME NO IN RANGE ------------------\n");
    int a,b,n,p;
    printf("ENTER THE RANGE:\n");
    scanf("%d %d",&a,&b);
    printf("PRIME NUMBERS FROM %d to %d is:\n",a,b);
    for(int i=a;i<=b;i++){
        n=i;
        int flag=1;
        if(n==1){
        flag=0;}
        for(int j=2;j<=(n/2);j++){
            if(n%j==0){
                flag=0;
                break;
            }
        }
        if(flag==1)
        printf("%d\t",i);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");
}