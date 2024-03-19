#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char post[50];

struct stack{

    int top;
    int size;
    char a[50];

};

void push(struct stack *s,char val){

    if(s->top ==s->size-1){
        printf("Stack OverFlow !!\n");
        return;
    }

    s->a[++s->top]=val;
}

char pop(struct stack *s){

    if(s->top<0){
        printf("Stack UnderFlow !!\n");
        return ' ';
    }

    return s->a[s->top--];
}

char peek(struct stack *s){

    if(s->top<0){
        printf("Stack UnderFlow !!\n");
        return ' ';  
    }

    return s->a[s->top];
}

int precedence(char s){

    if(s=='^'||s=='$')
    return 3;
    if(s=='/'||s=='%'||s=='*')
    return 2;
    if(s=='+'||s=='-')
    return 1;

    return 0;
}

char Associativity(char s){

    if(s=='^')
    return 'R';
    else
    return 'L';
}

void InfixToPostfix(struct stack *s, char infix[]){

s->top=-1;     
s->size=30;      int index=0;

for(int i=0;i<strlen(infix);i++){
    
    if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9')){

        post[index++]=infix[i];
    }else if(infix[i]=='('){
        push(s,infix[i]);
    }else if (infix[i]==')'){

        while(s->top>=0 && peek(s)!='('){
            post[index++]=pop(s);
        }
        s->top--;

    }else{

        while(s->top>=0 && precedence(infix[i])<=precedence(peek(s)) && Associativity(infix[i])=='L'){

            post[index++]=pop(s);
        }

        push(s,infix[i]);
    }
}

while(s->top>=0){
    post[index++]=pop(s);
}

post[index]='\0';

printf("POSTFIX EXPRESSION IS : %s\n",post);

}

int Evaluation(struct stack *s,char postfix[]){

    s->top=-1;s->size=30;int res=0;

    for(int i=0;i<strlen(postfix);i++){

        if(isdigit(postfix[i])){
            push(s,postfix[i]-'0');
        }else{

            int opr2=pop(s);
            int opr1=pop(s);

            switch(postfix[i]){

                case '^':
                res=opr1^opr2;
                push(s,res);
                break;

                case '%':
                res=opr1%opr2;
                push(s,res);
                break;

                case '/':
                res=opr1/opr2;
                push(s,res);
                break;

                case '*':
                res=opr1*opr2;
                push(s,res);
                break;

                case '+':
                res=opr1+opr2;
                push(s,res);
                break;

                case '-':
                res=opr1-opr2;
                push(s,res);
                break;

            }

        }
    }

    return pop(s);
}

int main(){

    struct stack *s =(struct stack *)malloc(sizeof(struct stack));
    struct stack *s1 =(struct stack *)malloc(sizeof(struct stack));
    char exp[50];
    printf("ENTER THE INFIX EXPRESSION :\n");
    scanf("%s",exp);
    printf("INFIX EXPRESSION IS : %s\n",exp);
    InfixToPostfix(s,exp);
    printf("EVALUTION : %d",Evaluation(s1,post));
}