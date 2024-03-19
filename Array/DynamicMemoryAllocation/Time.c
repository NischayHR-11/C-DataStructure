#include<stdio.h>
#include<stdlib.h>

struct Time {

    int hour;
    int min;
    int sec;
};

void read(struct Time *t,int hour,int min,int sec){

    t->hour=t->hour;
    t->min=t->min;
    t->sec=t->sec;

}

void update(struct Time *t){

    t->sec++;

    if(t->sec >= 60){

        t->sec=0;
        t->min++;

        if(t->min >= 60){
            t->min=0;
            t->hour++;

            if(t->hour >=24){

                t->hour=0;
            }
        }
    }
}

void AddTime(struct Time *t,struct Time *t1,struct Time *t2){

    t->hour=t1->hour+t2->hour;
    if(t->hour>=24)
    t->hour=t->hour-24;

    t->min=t1->min+t2->min;
    if(t->min>=60)
    t->min=t->min-60;

    t->sec=t1->sec+t2->sec;
    if(t->sec>=60)
    t->sec=t->sec-60;

}

void display(struct Time *t){

    printf("TIME :\t\t %d : %d : %d\n",t->hour,t->min,t->sec);

}

int main(){

    struct Time *t=(struct Time *)malloc(sizeof(struct Time));
    struct Time *t1=(struct Time *)malloc(sizeof(struct Time));
    struct Time *t2=(struct Time *)malloc(sizeof(struct Time));

    int n;
    do{
    printf("----------------------------------------------\n");
    printf("1.READ\n");
    printf("2.UPDATE\n");
    printf("3.ADD TWO TIMINGS\n");
    printf("4.DISPLAY\n");
    printf("----------------------------------------------\n");
    printf("ENTER THE CHOICE\n");
    scanf("%d",&n);

    switch(n){

        case 1 :
        printf("ENTER HOUR,MIN & SEC : \n");
        scanf("%d %d %d",&(t->hour),&(t->min),&(t->sec));
        read(t,t->hour,t->min,t->sec);
        break;

        case 2:
        update(t);
        printf("TIME UPDATED SUCCESSFULLY...\n");
        break;

        case 3:
        printf("ENTER THE FIRST TIME TO ADD : \n");
        printf("ENTER HOUR,MIN & SEC : \n");
        scanf("%d %d %d",&(t1->hour),&(t1->min),&(t1->sec));
        read(t1,t1->hour,t1->min,t1->sec);
        printf("ENTER THE SECOND TIME TO ADD : \n");
        printf("ENTER HOUR,MIN & SEC : \n");
        scanf("%d %d %d",&(t2->hour),&(t2->min),&(t2->sec));
        read(t2,t2->hour,t2->min,t2->sec);
        AddTime(t,t1,t2);
        break;

        case 4:
        display(t);
        break;

        default :

        printf("INVALID OPTION TRY AGAIN !!\n");
        break;

    }
    }while(1);

}