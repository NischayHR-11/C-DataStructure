#include<stdio.h>
#include<stdlib.h>

struct student{

    char name[20];
    int RollNo;
    float m1,m2,m3;
    float avg;

};

void read(struct student *p,int n){

for(int i=0;i<n;i++){

    printf("ENTER THE DETAILS OF STUDENT %d\n",i+1);
    printf("ENTER THE NAME : \n");
    scanf("%s",(p+i)->name);
    printf("ENTER THE ROLL NUMBER : \n");
    scanf("%d",&(p+i)->RollNo);
    printf("ENTER THE MARKS OF THREE SUBJECT : \n");
    scanf("%f%f%f",&(p+i)->m1,&(p+i)->m2,&(p+i)->m3);
    (p+i)->avg=((p+i)->m1+(p+i)->m2+(p+i)->m3)/3;

}

}

float Avg2(struct student *p ){

    float a=(p->m1);
    float b=(p->m2);
    float c=(p->m3);
    float avg;

    if(a>=c && a>=b){

        avg= (a + ((b>c)?b:c))/2;

    }else if(b>=a && b>=c){

        avg= (b + ((a>c)?a:c))/2; 
        
    }else{

        avg= (c + ((b>a)?b:a))/2;
    }

return avg;
}

void display(struct student *p,int n){

for(int i=0;i<n;i++){

    printf("DETAILS OF STUDENT %d\n\n",i+1);
    printf("NAME : %s\n",(p+i)->name);
    printf("ROLL NUMBER : %d\n",(p+i)->RollNo);
    printf("MARKS OF THREE SUBJECT ARE : %.2f  %.2f%  .2f\n",(p+i)->m1,(p+i)->m2,(p+i)->m3);
    printf("AVERAGE OF ALL THREE SUBJECT : %.2f\n",(p+i)->avg);
    printf("AVERAGE OF BEST 2 MARKS : %.2f\n\n",Avg2((p+i)));

}

}

int main(){

    int n;
    printf("ENTER THE NUMBER OF STUDENTS :\n");
    scanf("%d",&n);

    struct student *p =(struct student *)malloc(n*sizeof(struct student));

    read(p,n);
    display(p,n);

    return 0;
}


