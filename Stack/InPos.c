#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max 10

char infix[max],postfix[max],stack[max];
int opStack[max];
int top=-1;
int topNew=-1;

void intopos();
void push(char q);
int ISP(char p);
int ICP(char p);
char pop();
int isEmpty();
void print();
int evaluate();
void pushInt(int s);
int popToEvaluate();

void main(){

    printf("Enter infix expression: ");
    gets(infix);
    intopos();
    print();
    printf("Value is %d",evaluate());
    

}
void intopos(){
    char next,symbol;
    int i,j=0;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        
        case ')':
            while((next=pop())!='(')
                postfix[j++]=next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!isEmpty() && ISP(stack[top])>=ICP(symbol))
                postfix[j++]=pop();
            push(symbol);
            break;

        default:
            postfix[j++]=symbol;
            break;
        }
    }
    while (!isEmpty()){
        postfix[j++]=pop();
        postfix[j]='\0';
    }
    
}

int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push(char q){
    if(top>=max-1){
        printf("Full stack");
    }else{
        top+=1;
        stack[top]=q;
    }
}

char pop(){
    char op;
    if(top<0){
        printf("Empty stack");
        return(0);
    }else{
        op = stack[top];
        top--;
        return op;
    }
}

int ISP(char p){
    switch (p)
    {
    case '+':
    case '-':
        return 2;
    case '/':
    case '*':
        return 4;   
    case '^':
        return 5;
    default:
        return 0;
    }
}

int ICP(char p){
    switch (p)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 3;   
    case '^':
        return 6;
    case '(':
        return 10;
    default:
        return 0;
    }
}


void print(){
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while (postfix[i]){
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int evaluate(){
    int i,x,y,res,sp;
    char symbol;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            pushInt(postfix[i]-'0');
        }
        else{
            x=popToEvaluate();
            y=popToEvaluate();
            switch (postfix[i]){
            case '+':
                pushInt(x+y);
                break;
            case '-':
                pushInt(y-x);
                break;
            case '*':
                pushInt(x*y);
                break;
            case '/':
                pushInt(x/y);
                break;
            case '^':
                pushInt(pow(x,y));
                break;
    
            }
        }
    }return popToEvaluate();
}

void pushInt(int s){
    if(topNew>=max-1){
        printf("Full stack");
    }else{
        topNew+=1;
        opStack[topNew]=s;
    }
}

int popToEvaluate(){
    if(topNew<0){
        printf("Empty");
        return 0;
    }else{
        int value = opStack[topNew];
        topNew-=1;
        return value;
    }
}

