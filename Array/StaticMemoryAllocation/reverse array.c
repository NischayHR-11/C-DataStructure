#include<stdio.h>
void array(int arr[],int n);
int main(){
    int arr[]={1,2,3,4,5};
   printf("REVERSED ARRAY VALUES ARE:\t");
   array(arr,5);

    
return 0;
}
void array(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}