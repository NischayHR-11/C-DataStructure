#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char pre[50];

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

void InfixToPrefix(struct stack *s, char infix[]){

s->top=-1;     
s->size=30;      int index=0;

for(int i=0;i<strlen(infix)/2;i++){

    char temp=infix[i];
    infix[i]=infix[strlen(infix)-i-1];
    infix[strlen(infix)-i-1]=temp; 
}

for(int i=0;i<strlen(infix);i++){

    if(infix[i]=='(')
    infix[i]=')';
    else if(infix[i]==')')
    infix[i]='(';
}

printf("%s\n",infix);

for(int i=0;i<strlen(infix);i++){
    
    if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9')){

        pre[index++]=infix[i];

    }else if(infix[i]=='('){

        push(s,infix[i]);

    }else if (infix[i]==')'){

        while(s->top>=0 && peek(s)!='('){
            pre[index++]=pop(s);
        }
        s->top--;

    }else{

        while(s->top>=0 && precedence(infix[i])<precedence(peek(s))){

            pre[index++]=pop(s);
        }

        push(s,infix[i]);
    }
}

while(s->top>=0){
    pre[index++]=pop(s);
}

pre[index]='\0';

for(int i=0;i<strlen(pre)/2;i++){

    char temp=pre[i];
    pre[i]=pre[strlen(pre)-i-1];
    pre[strlen(pre)-i-1]=temp; 
}

printf("PREFIX EXPRESSION IS : %s\n",pre);

}

int Evaluation(struct stack *s,char pre[]){

    s->top=-1;s->size=30;int res=0;

    for(int i=strlen(pre);i>=0;i--){

        if(isdigit(pre[i])){
            push(s,pre[i]-'0');
        }else{

            int opr1=pop(s);
            int opr2=pop(s);

            switch(pre[i]){

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
    InfixToPrefix(s,exp);
    printf("EVALUTION : %d",Evaluation(s1,pre));
}